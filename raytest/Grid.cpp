#include "Grid.h"
#include<iostream>
#include"Colors.h"

Grid::Grid(){

	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	colors = GetCellColors();
	initialize();
}

bool Grid::iscellempty(int row, int column)
{
	if (GridValue[row][column] == 0)
	{
		return true;
	}
	else
		return false;
}

bool Grid::iscelloutsidegrid(int row, int column) const
{
	if (row >= 0 && row < NumRows && column >= 0 && column < NumCols) {
		return false;
	}
	else
		return true;
}

void Grid::initialize() {
	for (int row = 0; row < NumRows; row++) {
		for (int column = 0; column < NumCols; column++) {
			GridValue[row][column] = 0;
		}
	};

}

int Grid::ClearLine()
{
	int completed = 0;
	for (int row = NumRows - 1; row >= 0; row--)
	{
		if (isrowfull(row))
		{
			ClearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			FallRow(row, completed); 
		}
	}
	return completed;
}

bool Grid::isrowfull(int row) const
{
	for (int column = 0; column < NumCols; column++)
	{
		if (GridValue[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)
{
	for (int column0 = 0; column0 < NumCols; column0++)
	{
		GridValue[row][column0] = 0;
	}
}

/*void Grid::FallRow(int row, int column)							| 
{																	| attention column et row limité à 20 et 10
	for (int column = 0; column < NumCols; column++)				| <-ici si valeur de row = 10 et NumRows = 19,
	{																|   la somme est suppérieur à 20, donc pointeur 
		GridValue[row + NumRows][column] = GridValue[row][column];	|   sur le vide.
		GridValue[row][column] = 0;									|
	}																|
}*/																

void Grid::FallRow(int row, int completed)
{
	for (int r = row; r >= 0; r--)
	{
		for (int column = 0; column < NumCols; column++)
		{
			if (r + completed < NumRows)
			{
				GridValue[r + completed][column] = GridValue[r][column];
			}
			GridValue[r][column] = 0;
		}
	}
}


void Grid::Display() const {
	for (int row = 0; row < NumRows; row++) {
		for (int column = 0; column < NumCols; column++) {
			std::cout<<GridValue[row][column]<< " ";
		}
		std::cout << std::endl;
	};

}

/*std::vector<Color> Grid::GetCellColors() {
	
	Color DarkGrey = {26, 31, 40, 255};
	Color Green = {47, 230, 23, 255};
	Color Red = {232, 18, 18, 255 };
	Color Orange = {226, 116, 17, 255 };
	Color Yellow = {237, 234, 4, 255 };
	Color Purple = {166, 0, 247, 255 };
	Color Cyan = {21, 204,209, 255 };
	Color Blue = {13, 64, 216, 255 };

	return { DarkGrey, Green, Red, Orange, Yellow, Purple,Cyan, Blue   };
}*/

void Grid::Draw() {
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			int CellValue = GridValue[row][column];
			DrawRectangle(column * CellSize +11, row * CellSize +11 , CellSize -1, CellSize -1, colors[CellValue]);
		}
	}
}