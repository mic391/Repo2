#include <memory>
#include <gtest/gtest.h>
#include "tictactoe/game.hpp"

class TicTacToeTest : public testing::Test
{
protected:
  virtual void SetUp() {
    grid.reset(new tictactoe::Grid());
  }
  std::unique_ptr<tictactoe::Grid> grid;
};

TEST_F(TicTacToeTest, cannotPutXorOInSameSpace)
{
  EXPECT_NO_THROW(grid->putX(0, 0));
  EXPECT_THROW(grid->putO(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_THROW(grid->putX(0, 0), tictactoe::SpaceAlreadyTaken);
  EXPECT_NO_THROW(grid->putO(1, 1));
}

TEST_F(TicTacToeTest, cannotPutXorOOutsideOfGrid)
{
  EXPECT_NO_THROW(grid->putX(0, 0));
  EXPECT_NO_THROW(grid->putO(0, 1));
  EXPECT_NO_THROW(grid->putX(0, 2));
  EXPECT_NO_THROW(grid->putO(1, 0));
  EXPECT_NO_THROW(grid->putX(1, 1));
  EXPECT_NO_THROW(grid->putO(1, 2));
  EXPECT_NO_THROW(grid->putX(2, 0));
  EXPECT_NO_THROW(grid->putO(2, 1));
  EXPECT_NO_THROW(grid->putX(2, 2));
  EXPECT_THROW(grid->putX(0, 3), tictactoe::MarkOutsideGrid);
  EXPECT_THROW(grid->putO(3, 0), tictactoe::MarkOutsideGrid);
  EXPECT_THROW(grid->putX(3, 3), tictactoe::MarkOutsideGrid);
}

TEST_F(TicTacToeTest, threeMarksInARowWins)
{
  EXPECT_FALSE(grid->isXWinner());
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(0, 0);
  EXPECT_FALSE(grid->isXWinner());
  grid->putO(1, 0);
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(0, 1);
  EXPECT_FALSE(grid->isXWinner());
  grid->putO(1, 1);
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(0, 2);
  EXPECT_TRUE(grid->isXWinner());
}

TEST_F(TicTacToeTest, threeMarksInAColumnWins)
{
  EXPECT_FALSE(grid->isXWinner());
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(0, 0);
  EXPECT_FALSE(grid->isXWinner());
  grid->putO(0, 1);
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(1, 0);
  EXPECT_FALSE(grid->isXWinner());
  grid->putO(1, 1);
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(2, 0);
  EXPECT_TRUE(grid->isXWinner());
}

TEST_F(TicTacToeTest, threeMarksDiagonalWins)
{
  EXPECT_FALSE(grid->isXWinner());
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(0, 0);
  EXPECT_FALSE(grid->isXWinner());
  grid->putO(0, 1);
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(1, 1);
  EXPECT_FALSE(grid->isXWinner());
  grid->putO(1, 2);
  EXPECT_FALSE(grid->isOWinner());
  grid->putX(2, 2);
  EXPECT_TRUE(grid->isXWinner());
}
