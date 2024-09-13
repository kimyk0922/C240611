#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape = 'P');
	virtual ~APlayer();

	virtual void Tick() override;

	bool Predict(int PredictX, int PredictY);
};

