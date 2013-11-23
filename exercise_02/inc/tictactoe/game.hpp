#ifndef _TICTACTOE_GAME_HPP
#define _TICTACTOE_GAME_HPP

#include <cstddef>
#include <exception>

namespace tictactoe
{

class SpaceAlreadyTaken: public std::exception
{
public:
  virtual const char* what() const noexcept {
    return "Space already taken!";
  }
};

class MarkOutsideGrid: public std::exception
{
public:
  virtual const char* what() const noexcept {
    return "Mark outside grid!";
  }
};

class Grid
{
public:
  Grid(): buffer_(9, ' ') {}
  void putX(std::size_t row, std::size_t col) { putMark('X', row, col); }
  void putO(std::size_t row, std::size_t col) { putMark('O', row, col); }
  bool isXWinner() const { return isPlayerWinner('X'); }
  bool isOWinner() const { return isPlayerWinner('O'); }
private:
  bool isPlayerWinner(char player) const {
    return hasWinningRow(player)
           || hasWinningColumn(player)
           || hasWinningDiagonal(player);
  }
  bool isTaken(std::size_t row, std::size_t col) const {
    return spaceInGrid(row, col) != ' ';
  }
  bool isOutsideGrid(std::size_t row, std::size_t col) const {
    return row >= 3 || col >= 3;
  }
  bool hasWinningRow(char player) const {
    return hasThreeMarksInRow(player, 0)
           || hasThreeMarksInRow(player, 1)
           || hasThreeMarksInRow(player, 2);
  }
  bool hasWinningColumn(char player) const {
    return hasThreeMarksInColumn(player, 0)
           || hasThreeMarksInColumn(player, 1)
           || hasThreeMarksInColumn(player, 2);
  }
  bool hasWinningDiagonal(char player) const {
    return player == spaceInGrid(1, 1)
           && ((player == spaceInGrid(0, 0) && player == spaceInGrid(2, 2))
               || (player == spaceInGrid(0, 2) && player == spaceInGrid(2, 0)));
  }
  bool hasThreeMarksInRow(char mark, std::size_t row) const {
    return mark == spaceInGrid(row, 0)
           && mark == spaceInGrid(row, 1)
           && mark == spaceInGrid(row, 2);
  }
  bool hasThreeMarksInColumn(char mark, std::size_t col) const {
    return mark == spaceInGrid(0, col)
           && mark == spaceInGrid(1, col)
           && mark == spaceInGrid(2, col);
  }

  void putMark(char player, std::size_t row, std::size_t col) {
    if (isOutsideGrid(row, col)) { throw MarkOutsideGrid(); }
    if (isTaken(row, col)) { throw SpaceAlreadyTaken(); }
    spaceInGrid(row, col) = player;
  }
  char spaceInGrid(std::size_t row, std::size_t col) const {
    return buffer_[row * 3 + col];
  }
  char& spaceInGrid(std::size_t row, std::size_t col) {
    return buffer_[row * 3 + col];
  }

  std::string buffer_;
};

}

#endif
