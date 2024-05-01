#include "Game.h"
#include <iostream>
#include <cassert>
// Game class Contructor
Game::Game(int dimension, std::vector<Player*> players, int currentIndex) :dimension{ dimension }, players{ players }, currentIndex{ currentIndex }, 
board{std::vector<std::vector<int>>(dimension, std::vector<int> (dimension,-1)) }
{assert(board.size() == dimension); }
GameState Game::getGameState()  {
	return this->gstate;
}
void Game::SetState(GameState state) {
	gstate = state;
}
int Game::getCurretIndex() const {
	return this->currentIndex;
	
}
void Game::setCurretIndex(int index)  {
	this->currentIndex = index;

}
void Game::DisplayBoard() const {
	char currentPlayersymbol = ' ';

	
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getid() == currentIndex % players.size())
			currentPlayersymbol = players[i]->getSymbol();
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{

			if (board[i][j] == -1)
			{
				std::cout << "| " << " " << " |";
			}
			else 
			{
				int value = board[i][j];
				
				for (int i = 0; i < players.size(); i++)
				{
					if (value == players[i]->getid())
					{
						std::cout << "| " << players[i]->getSymbol() << " |";
					}
				}
				
				
			}
		}
		std::cout<< std::endl;

	}

}
void Game::GetAndMakeMove() {
	Player::PlayerType currentPlayertype = Player::PlayerType::HUMAN;
	Coordinates c = { 0,0 };


	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getid() == currentIndex % players.size())
		{
			currentPlayertype = players[i]->getType();
			if (currentPlayertype == Player::PlayerType::HUMAN)
			{
				c = players[i]->getMove(board);
			}
			else
			{
				c = players[i]->getMove(board);
			}
		}
	}
	board[c.x][c.y] = currentIndex % players.size();


}
bool Game::CheckWinner() {

	for (int i = 0; i < board.size(); i++)
	{
		std::map<int, int> countmap;
		for (int k = 0; k < players.size(); k++)
		{
			countmap.insert(std::pair < int, int>(players[k]->getid(), 0));
		}
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] != -1) {
				if (countmap.find(board[i][j]) != countmap.end())
				{
					int value = countmap.at(board[i][j]);
					value = value + 1;
					countmap[board[i][j]] = value;
					if (value == board.size())
					{
						SetState(GameState::WIN);
						return true;
					}
				}
				
			}
		}
	}
	for (int i = 0; i < board.size(); i++)
	{
		std::map<int, int> countmap2;
		for (int k = 0; k < players.size(); k++)
		{
			countmap2.insert(std::pair < int, int>(players[k]->getid(), 0));
		}
		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][i] != -1) {
				if (countmap2.find(board[i][j]) != countmap2.end())
				{
					int value = countmap2.at(board[j][i]);
					value = value + 1;
					countmap2[board[j][i]] = value;
					if (value == board.size())
					{
						SetState(GameState::WIN);
						return true;
					}
				}
			}
		}
	}
	//

	return false;
}
bool Game::CheckDraw() {
	if (getGameState() == GameState::WIN)
	{
		return false;
	}
	
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == -1)
			{
				return false;
			}
		}
	}
	SetState(GameState::DRAW);
}
//Human Class // Bot class all attributes
HumanPlayer::HumanPlayer(std::string name, char symbol, int id) : name{ name }, symbol{ symbol }, id{ id } {}
BotPlayer::BotPlayer(std::string name, char symbol, int id) : name{ name }, symbol{ symbol }, id{ id } {}
Player::PlayerType HumanPlayer::getType() const{
	return Player::PlayerType::HUMAN;
}
std::string HumanPlayer::getName() const {
	return this->name;
}
int HumanPlayer::getid() const {
	return this->id;
}
char HumanPlayer::getSymbol() const {
	return this->symbol;
}
Coordinates HumanPlayer::getMove(std::vector<std::vector<int>>const& board) const {
	// to get from std::cin
	std::cout << "Hello " << this->name << " its your turn, please input row number" << std::endl;
	int r;
	int c;
	std::cin >> r;
	std::cout << "please input column number" << std::endl;
	std::cin >> c;
	std::cout << " you made a move at " << r << " and " << c<< std::endl;
	return Coordinates{ r, c };
	
}
Coordinates BotPlayer::getMove(std::vector<std::vector<int>>const& board) const {

	//bot easy strategy

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == -1)
			{
				std::cout << " bot make a move at " << i << " and " << j << std::endl;
				return Coordinates{ i, j };
			}
		}
	}
	assert(false);

}
Player::PlayerType BotPlayer::getType() const {
	return Player::PlayerType::BOT;
}
std::string BotPlayer::getName() const {
	return this->name;
}
char BotPlayer::getSymbol() const {
	return this->symbol;
}
int BotPlayer::getid() const {
	return this->id;
}