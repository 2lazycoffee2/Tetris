#pragma once
#include"grid.h"
#include"TypeBlocks.cpp"
class Game
{
public :
	Game();
	~Game();
	Block GetRandBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void Command();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void RotateBlock();
	Grid grid;
	bool GameOver;
	int score;

private :
	Sound GameStart;
	Sound GameIsOver;
	Sound RotateSound;
	Sound ClearSound;
	bool IsBlockoutSideGrid();
	void LockBlock();
	bool Blockfits();
	std::vector<Block> blocks;
	Block CurrentBlock;
	Block NextBlock;
	void reset();
	void UpdateScore(int LinesCleared, int MoveBlockPoints );
};

