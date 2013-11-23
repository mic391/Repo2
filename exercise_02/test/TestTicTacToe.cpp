#include <gtest/gtest.h>
#include "tictactoe/game.hpp"

class TicTacToeTest : public testing::Test
{
protected:
  tictactoe::Game game;
};

TEST_F(TicTacToeTest, canPutXorY)
{
  game.putX(0, 0);
  game.putY(0, 0);
}

