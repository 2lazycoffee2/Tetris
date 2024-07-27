#include"raylib.h"
#include"Game.h"
#include"Colors.h"
#include<iostream>
#include"button.h"

double timeupdate = 0;
bool EventTrigger(double interval)
{
	double currentTime = GetTime();
	if (currentTime - timeupdate >= interval)
	{
		timeupdate = currentTime;
		return true;
	}
	else
		return false;
}

int rungame() {

	
	InitWindow(500, 620, "RayTris");
	SetTargetFPS(60);

	Font font = LoadFontEx("//raytest//TTFfont//monogram.ttf",64,0,0);				//->"C://Users//users//"

	Grid grid = Grid();
	grid.Display();

	//OBlocks O = OBlocks();
	//SBlocks S = SBlocks();
	//ZBlocks Z = ZBlocks();
	//IBlocks I = IBlocks();
	//JBlocks J = JBlocks();
	//LBlocks L = LBlocks();
	//T.move(4, 3);

	Game blockobj = Game();

	while (WindowShouldClose() == false)
	{	
		blockobj.Command();
		if (EventTrigger(0.2))
		{
			blockobj.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(DarkBlue);
		DrawTextEx(font, "SCORE", { 350, 15 }, 38, 1, WHITE);
		DrawTextEx(font, "NEXT", { 360, 125 }, 38, 1, WHITE);
		DrawTextEx(font, "BLOCK", { 350, 160 }, 38, 1, WHITE);
		DrawRectangleRounded({ 320, 55, 170, 60}, 0.5, 6, BLACK ); //afficher le score.
		DrawRectangleRounded({ 320, 210, 170, 180}, 0.5, 6, BLACK ); //afficher le block suivant.
		if (blockobj.GameOver) 
		{
			DrawTextEx(font, "GAME OVER", { 320, 410 }, 30, 2, WHITE);
		

		}

		char scoretext[20];
		sprintf_s(scoretext, sizeof(scoretext), "%d", blockobj.score);
		Vector2 TextSize = MeasureTextEx(font, scoretext, 38, 2);
		

		DrawTextEx(font, scoretext, { 320 + (170 - TextSize.x)/2, 65}, 38, 1, WHITE);
		blockobj.Draw();
		EndDrawing();
	};
	CloseWindow();
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	InitWindow(1024, 1024, "RayTrisMenu");
	SetTargetFPS(60);
	bool exit = false;
	Texture2D background = LoadTexture("raytest//MenuPNG//MyMenu.png"); //background du menu.		//->"C://Users//users//*"
	button startbutton{ "raytest//MenuPNG//StartButton.png",{340,300}, 0.6 };						//->"C://Users//users//*"
	button exitbutton{ "raytest//MenuPNG//ExitButton.png",{340,500}, 0.6 };							//->"C://Users//users//*"
	while (WindowShouldClose() == false && exit == false)
	{
		Vector2 MousePosition = GetMousePosition();
		bool MousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		if (startbutton.ispressed(MousePosition, MousePressed) == true)
		{
			
			exit = true;
			rungame();
			
			std::cout << "is pressed";
		}
		else if (exitbutton.ispressed(GetMousePosition(), MousePressed) == true)
		{
			exit = true;

		}
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		startbutton.Draw();
		exitbutton.Draw();
		EndDrawing();
	}
	CloseWindow();
}