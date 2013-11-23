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

class Game
{
public:
  Game(): grid_(9, ' ') {}
  void putX(std::size_t row, std::size_t col) { putMark('X', row, col); }
  void putY(std::size_t row, std::size_t col) { putMark('Y', row, col); }
private:
  bool isTaken(std::size_t row, std::size_t col) const {
    return spaceInGrid(row, col) != ' ';
  }
  bool isOutsideGrid(std::size_t row, std::size_t col) const {
    return row >= 3 || col >= 3;
  }
  void putMark(char player, std::size_t row, std::size_t col) {
    if (isOutsideGrid(row, col)) { throw MarkOutsideGrid(); }
    if (isTaken(row, col)) { throw SpaceAlreadyTaken(); }
    spaceInGrid(row, col) = player;
  }
  char spaceInGrid(std::size_t row, std::size_t col) const {
    return grid_[row * 3 + col];
  }
  char& spaceInGrid(std::size_t row, std::size_t col) {
    return grid_[row * 3 + col];
  }
  std::string grid_;
};

}

#endif
