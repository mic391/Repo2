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
  void putX(std::size_t row, std::size_t col) {
    if (grid_[row * 3 + col] == ' ') { grid_[row * 3 + col] = 'X'; }
    else { throw SpaceAlreadyTaken(); }
  }
  void putY(std::size_t row, std::size_t col) {
    if (grid_[row * 3 + col] == ' ') { grid_[row * 3 + col] = 'Y'; }
    else { throw SpaceAlreadyTaken(); }
  }
private:
  std::string grid_;
};

}

#endif
