#pragma once

#include<vector>
#include"raylib.h"


class Grid
{
public : 
	Grid();
	bool iscellempty(int row, int column);
	bool iscelloutsidegrid(int row, int column) const;
	int GridValue[20][10];
	void Draw();
	void Display() const;
	void initialize();
	int ClearLine();

private :

	//std::vector<Color> GetCellColors();
	
	bool isrowfull(int row) const;
	void ClearRow(int row);
	void FallRow(int row, int column);
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> colors;
};

