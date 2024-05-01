// TickTackToeGame.cpp : Defines the entry point for the application.
//

#include "TickTackToeGame.h"
#include "Game.h"
#include <vector>

int main()
{
	std::cout << "Hello Ankur lets play Tick Tack Toe Game"<<std::endl;
	std::vector <Player*> players {};
	bool winner = false;
	bool draw = false;
	players.push_back(new HumanPlayer("SAKSHI",'o',0));
	players.push_back(new BotPlayer("ANKUR", 'x',1));
	Game* game = new Game(3, players, 0);
	game->SetState(GameState::IN_PROGRESS);
	
	while (game->getGameState() == GameState::IN_PROGRESS)
	{
		game->DisplayBoard();
		game->GetAndMakeMove();
		winner = game->CheckWinner();
		draw = game->CheckDraw();
		
		game->setCurretIndex(game->getCurretIndex() + 1);
	}
	
	if (winner)
	{
		std::cout << "congratulations you are winner";
	}
	if (draw)
	{
		std::cout<<"game is drawn";
	}
}
