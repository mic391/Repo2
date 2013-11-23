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

class Game
{
public:
  Game(): grid_(9, ' ') {}
  void putX(std::size_t row, std::size_t col) { putMark('X', row, col); }
  void putY(std::size_t row, std::size_t col) { putMark('Y', row, col); }
  bool isTaken(std::size_t row, std::size_t col) {
    return spaceInGrid(row, col) != ' ';
  }
private:
  void putMark(char player, std::size_t row, std::size_t col) {
    if (isTaken(row, col)) { throw SpaceAlreadyTaken(); }
    spaceInGrid(row, col) = player;
  }
  char& spaceInGrid(std::size_t row, std::size_t col) {
    return grid_[row * 3 + col];
  }
  std::string grid_;
};

}

#endif
