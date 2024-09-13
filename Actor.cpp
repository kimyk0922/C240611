#include "Actor.h"
#include "SDL.h"
#include "Engine.h"

#include <iostream>
#include <windows.h>

AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 0;
	IsCollision = false;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;
}

AActor::AActor(int NewX, int NewY, char NewShape, int NewLayer)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = NewLayer;
	IsCollision = false;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	//text 
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape;

	//2D
	SDL_SetRenderDrawColor(GEngine->MyRenderer, R, G, B, 1);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, X, Y);
	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;

	//	SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);


	if (MyTexture)
	{

		SDL_RenderCopy(GEngine->MyRenderer, MyTexture, nullptr, &MyRect);
	
	}
	else
	{

		SDL_FillRect

	}

}

void AActor::LoadTexture(std::string TextureFilename)
{
	//	RAM Image (메모리에 이미지 생성)
	SDL_Surface* MySurface = SDL_LoadBMP(TextureFilename.c_str());

	//	Image의 배경색을 제거
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format, 255, 255, 255));

	//	RAM -> VRAM (메모리에서 V메모리로)
	SDL_Texture* MyTexture =  SDL_CreateTextureFromSurface(GEngine->MyRenderer, MySurface);

}
