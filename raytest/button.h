#pragma once
#include"raylib.h"
class button
{

public:

	button(const char* imagepath, Vector2 imageposition, float scale);
	~button();
	void Draw();
	bool ispressed(Vector2 MousePos, bool MousePressed);

private:
	Texture2D texture;
	Vector2 position;

};