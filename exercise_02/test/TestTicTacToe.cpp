#include <gtest/gtest.h>
#include "tictactoe/game.hpp"

class TicTacToeTest : public testing::Test
{
protected:
  tictactoe::Game game;
};

TEST_F(TicTacToeTest, cannotPutXorYInSameSpace)
{
  EXPECT_NO_THROW(game.putX(0, 0));
  EXPECT_THROW(game.putY(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_THROW(game.putX(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_NO_THROW(game.putY(1, 1));
}

