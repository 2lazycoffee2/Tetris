#include "Game.h"
#include"raylib.h"
#include<random>
#include<iostream>
Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	CurrentBlock = GetRandBlock();
	NextBlock = GetRandBlock();
	GameOver = false;
	score = 0;
	InitAudioDevice();
	RotateSound = LoadSound("C://Users//elzcf//source//repos//raytest//sounds//rotate.mp3");
	GameIsOver = LoadSound("C://Users//elzcf//source//repos//raytest//sounds//GameOver.mp3");
	GameStart = LoadSound("C://Users//elzcf//source//repos//raytest//sounds//GameStart.mp3");
	ClearSound = LoadSound("C://Users//elzcf//source//repos//raytest//sounds//ClearLines.mp3");
}

Game::~Game()
{	
	UnloadSound(RotateSound);
	UnloadSound(GameIsOver);
	UnloadSound(GameStart);
	UnloadSound(ClearSound);
	CloseAudioDevice();
	
}

Block Game::GetRandBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int randindex = rand() % blocks.size();
	Block block = blocks[randindex];
	blocks.erase(blocks.begin() + randindex);
	return block;
}
std::vector<Block> Game::GetAllBlocks() 
{
	return { LBlocks(), JBlocks(), IBlocks(), OBlocks(), SBlocks(), TBlocks(), ZBlocks() };

}

void Game::Draw() 
{
	grid.Draw();
	CurrentBlock.Draw(11,11);
	
	switch(NextBlock.id)
	{

	case 3 : 
		NextBlock.Draw(255, 290);
			break;
	case 4:
		NextBlock.Draw(255, 270);
		break;
	case 6 : 
		NextBlock.Draw(240, 270);
		break;
	default:
		NextBlock.Draw(270, 270);
		break;
	}
}

//---------------------------------------------------------------------------------------------------------------------------------

void Game::Command()
{
	int KeyPressed = GetKeyPressed();
	if (GameOver && KeyPressed != 0) {
		GameOver = false;
		reset();
	}
	switch (KeyPressed)
	{
	case KEY_LEFT: MoveBlockLeft();
		break;

	case KEY_RIGHT: MoveBlockRight();
		break;

	case KEY_DOWN: MoveBlockDown();
		UpdateScore(0, 1);
		break;
	
	case KEY_SPACE: RotateBlock();
		break;

	}
}

void Game::MoveBlockLeft()
{
	if (!GameOver)
	{
		CurrentBlock.move(0, -1);
		if (IsBlockoutSideGrid() || Blockfits() == false)
		{
			CurrentBlock.move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!GameOver)
	{
		CurrentBlock.move(0, 1);
		if (IsBlockoutSideGrid() || Blockfits() == false)
		{
			CurrentBlock.move(0, -1);
			
		}
	}
}

void Game::MoveBlockDown()
{
	if (!GameOver)
	{
		CurrentBlock.move(1, 0);
		if (IsBlockoutSideGrid() || Blockfits() == false)
		{
			CurrentBlock.move(-1, 0);
			LockBlock();
		}
	}
}

void Game::RotateBlock()
{
	if (!GameOver) 
	{
		CurrentBlock.Rotation();
		if (IsBlockoutSideGrid() || Blockfits() == false) {
			CurrentBlock.UndoRotation();
		}
		else
			PlaySound(RotateSound);

		
	}
}

//---------------------------------------------------------------------------------------------------------------------------------

bool Game::IsBlockoutSideGrid()
{
	std::vector<Position> tiles = CurrentBlock.GetCellPosition();
	for(Position item: tiles)
	{
		if(grid.iscelloutsidegrid(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::LockBlock()
{
	std::vector<Position> tiles = CurrentBlock.GetCellPosition();
	for(Position item : tiles)
	{
		grid.GridValue[item.row][item.column] = CurrentBlock.id;

	}
	CurrentBlock = NextBlock;
	if (Blockfits() == false)
	{
		PlaySound(GameIsOver);
		GameOver = true;

	}
	NextBlock = GetRandBlock();
	int RowsCleared = grid.ClearLine();
	if(RowsCleared > 0)
	{
		PlaySound(ClearSound);
		UpdateScore(RowsCleared, 0);

	}
} 

bool Game::Blockfits()
{
	std::vector<Position> tiles = CurrentBlock.GetCellPosition();
	for(Position item : tiles)
	{
		if (grid.iscellempty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::reset()
{
	PlaySound(GameStart);
	grid.initialize();
	blocks = GetAllBlocks();
	NextBlock = GetRandBlock();
	score = 0;
}

void Game::UpdateScore(int LinesCleared, int MoveDownPoints)
{
	switch (LinesCleared) {
	case 1 : 
		score += 100;
		break;
	
	case 2 : 
		score += 200;
		break;
	
	case 3 : 
		score += 500;
		break;

	default : 
		break;

	}
	score += MoveDownPoints;
}
