#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	//AActor::AActor();
	X = 1;
	Y = 1;
	Shape = ' ';
	Layer = 4;
	IsCollision = true;
	R = 0;
	G = 255;
	B = 0;
}

APlayer::APlayer(int NewX, int NewY, char NewShape)
{
	//	AActor::AActor(NewX, NewY, NewShape);
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 4;
	IsCollision = true;

	R = 0;
	G = 255;
	B = 0;

	Filename = "data/Player.bmp";
	LoadTexture(Filename);

}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	switch (UEngine::KeyCode)
	{
	case 'W':
	case 'w':
		if (Predict(X, Y - 1))
		{
			Y--;
		}
		break;
	case 'S':
	case 's':
		if (Predict(X, Y + 1))
		{
			Y++;
		}
		break;
	case 'A':
	case 'a':
		if (Predict(X - 1, Y))
		{
			X--;
		}
		break;
	case 'D':
	case 'd':
		if (Predict(X + 1, Y))
		{
			X++;
		}
		break;
	}
}

bool APlayer::Predict(int PredictX, int PredictY)
{
	for (auto OtherActor : GEngine->Actors)
	{
		if (this == OtherActor)
		{
			continue;
		}

		if (OtherActor->IsCollision == false)
		{
			continue;
		}

		if (PredictX == OtherActor->X && PredictY == OtherActor->Y)
		{
			return false;
		}
	}


	return true;
}
