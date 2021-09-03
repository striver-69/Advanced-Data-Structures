#include <iostream>
#include <list>
#include <string>
using namespace std;

enum Color
{
  BLACK,
  WHITE
};
enum GameStatus
{
  ACTIVE,
  PAUSED,
  FORTFEIGHT,
  BLACK_WIN,
  WHITE_WIN
};

class Account
{
private:
  string username;
  string password;
  string name;
  string email;
  string phone;
};

class Time
{
private:
  int mins;
  int secs;
};

class Player
{
private:
  Account account;
  Color color;
  Time timeleft;
};

class CellPosition
{
private:
  char ch;
  int i;
};

class Piece
{
private:
  Color color;

public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition) ;
  bool validate(CellPosition fromPosition, CellPosition endPosition) ;
};

class Knight : public Piece
{
public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition);
  bool validate(CellPosition fromPosition, CellPosition endPosition);
};

class Bishop : public Piece
{
public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition);
  bool validate(CellPosition fromPosition, CellPosition endPosition);
};

class Rook : public Piece
{
public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition);
  bool validate(CellPosition fromPosition, CellPosition endPosition);
};

class King : public Piece
{
public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition);
  bool validate(CellPosition fromPosition, CellPosition endPosition);
};

class Queen : public Piece
{
public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition);
  bool validate(CellPosition fromPosition, CellPosition endPosition);
};

class Pawn : public Piece
{
public:
  bool move(CellPosition fromPosition, CellPosition toPosition);
  list<CellPosition> possibleMoves(CellPosition fromPosition);
  bool validate(CellPosition fromPosition, CellPosition endPosition);
};

class Cell
{
private:
  Color color;
  Piece piece;
  CellPosition position;
};

class Move
{
private:
  Player turn;
  Piece piece;
  Piece killedPiece;
  CellPosition startPosition;
  CellPosition endPosition;
};

class ChessBoard
{
private:
  list<list<Cell> > board;

public:
  void resetBoard(){};
  void updateBoard(Move move){};
};

class Chess
{
private:
  ChessBoard chessboard;
  Player player[];
  Player currentPlayer;
  list<Move> movesList;
  GameStatus gamestatus;

  void changeTurn(){};

public:
  bool playerMove(CellPosition fromPosition, CellPosition endPosition, Piece piece);
  bool endGame();
};

int main()
{

  return 0;
}