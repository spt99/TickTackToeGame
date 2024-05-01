#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
//class Player;
class Coordinates {
public:
	int x;
	int y;
};
class Player {
public:
	virtual Coordinates getMove(std::vector<std::vector<int>>const & board) const =0;
	enum class PlayerType { HUMAN, BOT };
	virtual std::string getName() const =0;
	virtual PlayerType getType() const=0;
	virtual char getSymbol() const=0;
	virtual int getid() const = 0;


};
class HumanPlayer : public Player
{
public:
	HumanPlayer(std::string name, char symbol, int id);
	PlayerType getType() const override;
	char getSymbol() const override;
	std::string getName() const override;
	Coordinates getMove(std::vector<std::vector<int>>const &  board) const override;
	int getid() const override;
private:
	std::string name;
	char symbol;
	int id;
};
class BotPlayer :public Player
{
public:
	BotPlayer(std::string name, char symbol, int id);
	PlayerType getType() const override;
	char getSymbol() const override;
	std::string getName() const override;
	Coordinates getMove(std::vector<std::vector<int>>const& board) const override;
	int getid() const override;
private:
	std::string name;
	char symbol;
	int id;
};
enum class GameState { IN_PROGRESS, WIN, DRAW };
class Game
{
public:
	Game(int dimension, std::vector<Player*> players, int startingIndex);
	
	int getCurretIndex() const;
	void setCurretIndex(int index);
	void DisplayBoard() const;
	void GetAndMakeMove(); //taking input // move play
	bool CheckWinner() ;
	bool CheckDraw() ;

	
	GameState getGameState();
	void SetState(GameState game);
	GameState gstate;
	// |_0-|_1-|-1|
	// |_2-|_0-|_1|
	// |-1-|-1-|-1|
	// 
	

private:
	int dimension;
	std::vector<Player*> players;
	int currentIndex;
	std::vector<std::vector<int>> board;
	
	

};
