#include"Block.h"
#include"Position.h"

//--------------------------------------------------------------------------------------------------

	//THE L BLOCK
class LBlocks : public Block{

public : 
	LBlocks() {
		id = 1;
		cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}

};

//--------------------------------------------------------------------------------------------------

	//THE J BLOCK
class JBlocks : public Block {

public:
	JBlocks() {
		id = 2;
		cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
		move(0, 3);
	}

};

//--------------------------------------------------------------------------------------------------

	//THE I BLOCK
class IBlocks : public Block {

public:
	IBlocks() {
		id = 3;
		cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
		cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
		move(-1, 3);
	}

};

//--------------------------------------------------------------------------------------------------

	//THE O BLOCK
class OBlocks : public Block {

public:
	OBlocks() {
		id = 4;
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		cells[2] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		move(0, 4);

	}
};
 //--------------------------------------------------------------------------------------------------

	//THE S BLOCK
class SBlocks : public Block {

public:
	SBlocks() {
		id = 5;
		cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
		cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}

};

//--------------------------------------------------------------------------------------------------

	//THE T BLOCK
class TBlocks : public Block {

public:
	TBlocks() {
		id = 6;
		cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
		move(0, 4);
	}

};

//--------------------------------------------------------------------------------------------------

	//THE Z BLOCK
 class ZBlocks : public Block {

public:
	ZBlocks() {
		id = 7;
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
		move(0, 3);
	}

};

//--------------------------------------------------------------------------------------------------