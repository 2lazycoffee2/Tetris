#include "button.h"

button::button(const char* imagepath, Vector2 imageposition, float scale)
{

	Image image = LoadImage(imagepath);
	int originalwidth = image.width;
	int originalheight = image.height;

	int newwidth = static_cast<int>(originalwidth * scale);
	int newheight = static_cast<int>(originalheight * scale);

	ImageResize(&image, newwidth, newheight);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	position = imageposition;


}

button::~button()
{

	UnloadTexture(texture);
}

void button::Draw()
{
	DrawTextureV(texture, position, WHITE);
}

bool button::ispressed(Vector2 MousePos, bool MousePressed)
{
	Rectangle rectbutton = { position.x, position.y, static_cast<float>(texture.width),static_cast<float>(texture.height) };

	if (CheckCollisionPointRec(MousePos, rectbutton) && MousePressed)
	{
		return true;
	}
	return false;
}
