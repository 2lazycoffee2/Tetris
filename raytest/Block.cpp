#include "Block.h"

Block::Block()
{
	cellsize = 30;
	rotationstate = 0;
	colors = GetCellColors();
	RowOffset = 0;
	ColumnOffset = 0;
}

void Block::Draw(int OffsetX, int OffsetY)
{
	std::vector<Position> tiles = GetCellPosition();
	for (Position item : tiles) 
	{
		DrawRectangle(item.column * cellsize + OffsetX, item.row * cellsize + OffsetY, cellsize - 1, cellsize - 1, colors[id]);
	}
}

void Block::move(int rows, int columns) 
{

	RowOffset += rows;
	ColumnOffset += columns;

}

void Block::Rotation()
{
	rotationstate++;
	if (rotationstate == (int)cells.size())
	{
		rotationstate = 0;
	}
}

void Block::UndoRotation()
{
	rotationstate--;
		if (rotationstate == -1)
		{
			rotationstate = cells.size() - 1;
		}
}

std::vector<Position> Block::GetCellPosition()
{

	std::vector<Position> tiles = cells[rotationstate];
	std::vector<Position> MoveTiles;
	
	for(Position item : tiles)
	{

		Position NewPos = Position(item.row + RowOffset, item.column + ColumnOffset);
		MoveTiles.push_back(NewPos);
		
	}
	return MoveTiles;

}

