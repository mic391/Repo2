#include <gtest/gtest.h>
#include "tictactoe/game.hpp"

class TicTacToeTest : public testing::Test
{
};

TEST_F(TicTacToeTest, canCreateTicTacToeGame)
{
  tictactoe::Game game;
  (void)game;
}

TEST_F(TicTacToeTest, canPutXorY)
{
  tictactoe::Game game;
  game.putX(0, 0);
  game.putY(0, 0);
}

