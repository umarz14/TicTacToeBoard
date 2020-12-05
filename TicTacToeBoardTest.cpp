/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

 //EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggleturnX)
{
	TicTacToeBoard t;
	ASSERT_TRUE(O == t.toggleTurn());
}

TEST(TicTacToeBoardTest, toggleturnO)
{
	TicTacToeBoard t;
	t.toggleTurn();
	ASSERT_TRUE(X == t.toggleTurn());
}

TEST(TicTacToeBoardTest, outofrangerow)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(4,1), Invalid);
}

TEST(TicTacToeBoardTest, outofrangecolumn)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(0,4), Invalid);
}

TEST(TicTacToeBoardTest, twooutofrange)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(4,4), Invalid);
}

TEST(TicTacToeBoardTest, outofrangenegative)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(-1,-2), Invalid);
}

TEST(TicTacToeBoardTest, placeX)
{
	TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1,3), X);
}

TEST(TicTacToeBoardTest, placeO)
{
	TicTacToeBoard board;
	board.toggleTurn();
	ASSERT_EQ(board.placePiece(2,1), O);
}

TEST(TicTacToeBoardTest, spottaken)
{
	TicTacToeBoard board;
	board.placePiece(1,2);
	ASSERT_EQ(board.placePiece(1,2), X);
}

TEST(TicTacToeBoardTest, getpiecex)
{
	TicTacToeBoard board;
	board.placePiece(1,2);
	ASSERT_EQ(board.getPiece(1,2), X);
}

TEST(TicTacToeBoardTest, getpiece_ofr)
{
	TicTacToeBoard board;
	board.placePiece(1,2);
	ASSERT_EQ(board.getPiece(8,2), Invalid);
}

TEST(TicTacToeBoardTest, diagwinner)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(1,1);
	board.placePiece(2,1);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, row_winner)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,1);
	board.placePiece(0,1);
	board.placePiece(2,1);
	board.placePiece(0,2);
	ASSERT_EQ(board.getWinner(), X);
}


TEST(TicTacToeBoardTest, col_winner)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,1);
	board.placePiece(1,0);
	board.placePiece(2,1);
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), X);
}

TEST(TicTacToeBoardTest, nowinner)
{
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(1,1);
	board.placePiece(2,1);
	board.placePiece(1,2);
	ASSERT_EQ(board.getWinner(), Invalid);
}