#pragma once
#include"Position.h"
#include<map>
#include<vector>
#include"Colors.h"

class Block
{
public : 

	Block();
	int id;
	std::map<int, std::vector<Position>> cells;  // association de chaque cellule à un "état" à l'aide d'un map
	void Draw(int OffsetX, int OffsetY);
	void move(int rows, int columns);
	void Rotation();
	void UndoRotation();
	std::vector<Position> GetCellPosition();

private :
	int RowOffset;
	int ColumnOffset;
	int cellsize;
	int rotationstate;
	std::vector<Color> colors;

};

