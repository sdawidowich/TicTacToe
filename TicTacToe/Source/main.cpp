#include <iostream>
#include <string>
#include <random>

void printGameBoard(std::string gameBoard[])
{
	for (int i = 0; i < 28; i++)
	{
		std::cout << gameBoard[i];
	}
	std::cout << std::endl;
}

void startGame()
{
	std::string bottomLine = "_____|_____|_____";
	std::string sideLine = "|";
	std::string xPlacement = "  X  ";
	std::string oPlacement = "  O  ";
	std::string blankPlacement = "     ";
	bool gameOver = false;
	std::cout << "Game started" << std::endl;
	std::string gameBoardOutput[] = {blankPlacement, sideLine, blankPlacement, sideLine, blankPlacement, "\n", bottomLine, "\n", blankPlacement, sideLine, blankPlacement, sideLine, blankPlacement, "\n", bottomLine, "\n", blankPlacement, sideLine, blankPlacement, sideLine, blankPlacement, "\n", blankPlacement, sideLine, blankPlacement, sideLine, blankPlacement, "\n"};
	std::string gameBoard[] = {
	"", "", "",
	"", "", "",
	"", "", ""};
	std::vector<char> v = { 'X', 'O' };
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_int_distribution<int> dist(0, v.size() - 1);
	
	printGameBoard(gameBoardOutput);
	char playerOptions[] = { 'X', 'O' };
	char player1 = v[dist(engine)];
	char player2;
	if (player1 == 'X')
	{
		player2 = 'O';
	}
	else
	{
		player2 = 'X';
	}
	std::cout << "You are " << player1 << "s" << std::endl;

	bool usersTurn = false;
	if (player1 == 'X')
	{
		usersTurn = true;
	}

	std::vector<std::string> playedMovesList = {};
	std::vector<std::string> possibleMoves = { "top left", "top middle", "top right", "middle left", "center", "middle right", "bottom left", "bottom middle", "bottom right" };
	int numPlayedMoves = 0;
	while (!gameOver)
	{
		char xOrO = 'X';
		std::string playerMove;
		bool takenSpace = false;
		
		if (usersTurn)
		{
			bool foundMove = true;
			bool possibleMove = false;
			xOrO = player1;
			while (foundMove)
			{
				std::cout << "Your move: ";
				getline(std::cin, playerMove);
				foundMove = std::find(playedMovesList.begin(), playedMovesList.end(), playerMove) != playedMovesList.end();
				possibleMove = std::find(possibleMoves.begin(), possibleMoves.end(), playerMove) != possibleMoves.end();
				if (!possibleMove)
				{
					std::cout << "Invalid Move." << std::endl;
					foundMove = true;
				}
				if (foundMove && possibleMove) {
					std::cout << "That space is already taken!" << std::endl;
				}
			}
			playedMovesList.push_back(playerMove);
			usersTurn = false;
		}
		else
		{
			std::vector<std::string> randomMove = { "top left", "top middle", "top right", "middle left", "center", "middle right", "bottom left", "bottom middle", "bottom right" };
			std::uniform_int_distribution<int> dist(0, randomMove.size() - 1);
			xOrO = player2;
			bool foundMove = true;
			while (foundMove)
			{
				playerMove = randomMove[dist(engine)];
				foundMove = std::find(playedMovesList.begin(), playedMovesList.end(), playerMove) != playedMovesList.end();
			}
			playedMovesList.push_back(playerMove);
			usersTurn = true;
		}
		if (playerMove == "top left" && xOrO == 'X' && gameBoard[0] == "")
		{
			gameBoardOutput[0] = xPlacement;
			gameBoard[0] = "X";
		}
		else if (playerMove == "top middle" && xOrO == 'X' && gameBoard[1] == "")
		{
			gameBoardOutput[2] = xPlacement;
			gameBoard[1] = "X";
		}
		else if (playerMove == "top right" && xOrO == 'X' && gameBoard[2] == "")
		{
			gameBoardOutput[4] = xPlacement;
			gameBoard[2] = "X";
		}
		else if (playerMove == "middle left" && xOrO == 'X' && gameBoard[3] == "")
		{
			gameBoardOutput[8] = xPlacement;
			gameBoard[3] = "X";
		}
		else if (playerMove == "center" && xOrO == 'X' && gameBoard[4] == "")
		{
			gameBoardOutput[10] = xPlacement;
			gameBoard[4] = "X";
		}
		else if (playerMove == "middle right" && xOrO == 'X' && gameBoard[5] == "")
		{
			gameBoardOutput[12] = xPlacement;
			gameBoard[5] = "X";
		}
		else if (playerMove == "bottom left" && xOrO == 'X' && gameBoard[6] == "")
		{
			gameBoardOutput[22] = xPlacement;
			gameBoard[6] = "X";
		}
		else if (playerMove == "bottom middle" && xOrO == 'X' && gameBoard[7] == "")
		{
			gameBoardOutput[24] = xPlacement;
			gameBoard[7] = "X";
		}
		else if (playerMove == "bottom right" && xOrO == 'X' && gameBoard[8] == "")
		{
			gameBoardOutput[26] = xPlacement;
			gameBoard[8] = "X";
		}
		else if (playerMove == "top left" && xOrO == 'O' && gameBoard[0] == "")
		{
			gameBoardOutput[0] = oPlacement;
			gameBoard[0] = "O";
		}
		else if (playerMove == "top middle" && xOrO == 'O' && gameBoard[1] == "")
		{
			gameBoardOutput[2] = oPlacement;
			gameBoard[1] = "O";
		}
		else if (playerMove == "top right" && xOrO == 'O' && gameBoard[2] == "")
		{
			gameBoardOutput[4] = oPlacement;
			gameBoard[2] = "O";
		}
		else if (playerMove == "middle left" && xOrO == 'O' && gameBoard[3] == "")
		{
			gameBoardOutput[8] = oPlacement;
			gameBoard[3] = "O";
		}
		else if (playerMove == "center" && xOrO == 'O' && gameBoard[4] == "")
		{
			gameBoardOutput[10] = oPlacement;
			gameBoard[4] = "O";
		}
		else if (playerMove == "middle right" && xOrO == 'O' && gameBoard[5] == "")
		{
			gameBoardOutput[12] = oPlacement;
			gameBoard[5] = "O";
		}
		else if (playerMove == "bottom left" && xOrO == 'O' && gameBoard[6] == "")
		{
			gameBoardOutput[22] = oPlacement;
			gameBoard[6] = "O";
		}
		else if (playerMove == "bottom middle" && xOrO == 'O' && gameBoard[7] == "")
		{
			gameBoardOutput[24] = oPlacement;
			gameBoard[7] = "O";
		}
		else if (playerMove == "bottom right" && xOrO == 'O' && gameBoard[8] == "")
		{
			gameBoardOutput[26] = oPlacement;
			gameBoard[8] = "O";
		}
		else
		{
			std::cout << "Invalid move" << std::endl;
		}
		printGameBoard(gameBoardOutput);
		numPlayedMoves++;
		std::string stringPlayer(1, player1);
		std::string stringOpponent(1, player2);
		if (gameBoard[0] != "" && gameBoard[0] == gameBoard[1] && gameBoard[0] == gameBoard[2])
		{
			if (gameBoard[0] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[0] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[3] != "" && gameBoard[3] == gameBoard[4] && gameBoard[3] == gameBoard[5])
		{
			if (gameBoard[3] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[3] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[6] != "" && gameBoard[6] == gameBoard[7] && gameBoard[6] == gameBoard[8])
		{
			if (gameBoard[6] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[6] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[0] != "" && gameBoard[0] == gameBoard[3] && gameBoard[0] == gameBoard[6])
		{
			if (gameBoard[0] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[0] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[1] != "" && gameBoard[1] == gameBoard[4] && gameBoard[1] == gameBoard[7])
		{
			if (gameBoard[1] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[1] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[2] != "" && gameBoard[2] == gameBoard[5] && gameBoard[2] == gameBoard[8])
		{
			if (gameBoard[2] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[2] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[0] != "" && gameBoard[0] == gameBoard[4] && gameBoard[0] == gameBoard[8])
		{
			if (gameBoard[0] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[0] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (gameBoard[2] != "" && gameBoard[2] == gameBoard[4] && gameBoard[2] == gameBoard[6])
		{
			if (gameBoard[2] == stringPlayer)
			{
				gameOver = true;
				std::cout << "You win!" << std::endl;
			}
			else if (gameBoard[2] == stringOpponent)
			{
				gameOver = true;
				std::cout << "You Lose!" << std::endl;
			}
		}
		else if (numPlayedMoves >= 9)
		{
			gameOver = true;
			std::cout << "It's a tie!" << std::endl;
		}
	}
	
}

std::string command()
{
	std::string userCommand;
	std::cout << "What would you like to do? ";
	getline(std::cin, userCommand);
	return userCommand;
}

int main()
{
	std::cout << "Welcome to tic-tac-toe! To start a game, type START. To quit, type QUIT." << std::endl;
	bool quit = false;
	while (!quit)
	{	
		std::string userCommand = command();
		if (userCommand == "START")
		{
			startGame();
		}
		else if (userCommand == "QUIT")
		{
			quit = true;
		}
		else
		{
			std::cout << "Invalid command. To start a game, type START. To quit, type QUIT." << std::endl;
		}
	}

	return 0;
}