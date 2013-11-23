#include <memory>
#include <gtest/gtest.h>
#include "tictactoe/game.hpp"

class TicTacToeTest : public testing::Test
{
protected:
  virtual void SetUp() {
    game.reset(new tictactoe::Game());
  }
  std::unique_ptr<tictactoe::Game> game;
};

TEST_F(TicTacToeTest, cannotPutXorYInSameSpace)
{
  EXPECT_NO_THROW(game->putX(0, 0));
  EXPECT_THROW(game->putY(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_THROW(game->putX(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_NO_THROW(game->putY(1, 1));
}

TEST_F(TicTacToeTest, cannotPutXorYOutsideOfGrid)
{
  EXPECT_NO_THROW(game->putX(0, 0));
  EXPECT_NO_THROW(game->putY(0, 1));
  EXPECT_NO_THROW(game->putX(0, 2));
  EXPECT_NO_THROW(game->putY(1, 0));
  EXPECT_NO_THROW(game->putX(1, 1));
  EXPECT_NO_THROW(game->putY(1, 2));
  EXPECT_NO_THROW(game->putX(2, 0));
  EXPECT_NO_THROW(game->putY(2, 1));
  EXPECT_NO_THROW(game->putX(2, 2));
  EXPECT_THROW(game->putX(0, 3), tictactoe::MarkOutsideGrid);
  EXPECT_THROW(game->putY(3, 0), tictactoe::MarkOutsideGrid);
  EXPECT_THROW(game->putX(3, 3), tictactoe::MarkOutsideGrid);
}

TEST_F(TicTacToeTest, threeMarksInARowWins)
{
  EXPECT_FALSE(game->isXWinner());
  EXPECT_FALSE(game->isYWinner());
  game->putX(0, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putY(1, 0);
  EXPECT_FALSE(game->isYWinner());
  game->putX(0, 1);
  EXPECT_FALSE(game->isXWinner());
  game->putY(1, 1);
  EXPECT_FALSE(game->isYWinner());
  game->putX(0, 2);
  EXPECT_TRUE(game->isXWinner());
}

TEST_F(TicTacToeTest, threeMarksInAColumnWins)
{
  EXPECT_FALSE(game->isXWinner());
  EXPECT_FALSE(game->isYWinner());
  game->putX(0, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putY(0, 1);
  EXPECT_FALSE(game->isYWinner());
  game->putX(1, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putY(1, 1);
  EXPECT_FALSE(game->isYWinner());
  game->putX(2, 0);
  EXPECT_TRUE(game->isXWinner());
}
