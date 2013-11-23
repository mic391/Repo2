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

