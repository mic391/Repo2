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

TEST_F(TicTacToeTest, cannotPutXorOInSameSpace)
{
  EXPECT_NO_THROW(game->putX(0, 0));
  EXPECT_THROW(game->putO(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_THROW(game->putX(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_NO_THROW(game->putO(1, 1));
}

TEST_F(TicTacToeTest, cannotPutXorOOutsideOfGrid)
{
  EXPECT_NO_THROW(game->putX(0, 0));
  EXPECT_NO_THROW(game->putO(0, 1));
  EXPECT_NO_THROW(game->putX(0, 2));
  EXPECT_NO_THROW(game->putO(1, 0));
  EXPECT_NO_THROW(game->putX(1, 1));
  EXPECT_NO_THROW(game->putO(1, 2));
  EXPECT_NO_THROW(game->putX(2, 0));
  EXPECT_NO_THROW(game->putO(2, 1));
  EXPECT_NO_THROW(game->putX(2, 2));
  EXPECT_THROW(game->putX(0, 3), tictactoe::MarkOutsideGrid);
  EXPECT_THROW(game->putO(3, 0), tictactoe::MarkOutsideGrid);
  EXPECT_THROW(game->putX(3, 3), tictactoe::MarkOutsideGrid);
}

TEST_F(TicTacToeTest, threeMarksInARowWins)
{
  EXPECT_FALSE(game->isXWinner());
  EXPECT_FALSE(game->isOWinner());
  game->putX(0, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putO(1, 0);
  EXPECT_FALSE(game->isOWinner());
  game->putX(0, 1);
  EXPECT_FALSE(game->isXWinner());
  game->putO(1, 1);
  EXPECT_FALSE(game->isOWinner());
  game->putX(0, 2);
  EXPECT_TRUE(game->isXWinner());
}

TEST_F(TicTacToeTest, threeMarksInAColumnWins)
{
  EXPECT_FALSE(game->isXWinner());
  EXPECT_FALSE(game->isOWinner());
  game->putX(0, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putO(0, 1);
  EXPECT_FALSE(game->isOWinner());
  game->putX(1, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putO(1, 1);
  EXPECT_FALSE(game->isOWinner());
  game->putX(2, 0);
  EXPECT_TRUE(game->isXWinner());
}

TEST_F(TicTacToeTest, threeMarksDiagonalWins)
{
  EXPECT_FALSE(game->isXWinner());
  EXPECT_FALSE(game->isOWinner());
  game->putX(0, 0);
  EXPECT_FALSE(game->isXWinner());
  game->putO(0, 1);
  EXPECT_FALSE(game->isOWinner());
  game->putX(1, 1);
  EXPECT_FALSE(game->isXWinner());
  game->putO(1, 2);
  EXPECT_FALSE(game->isOWinner());
  game->putX(2, 2);
  EXPECT_TRUE(game->isXWinner());
}
