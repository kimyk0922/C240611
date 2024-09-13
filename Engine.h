#pragma once
#include <vector>
#include <string>

using namespace std;

#include "SDL.h"


#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class AActor;

//sigleton patern
class UEngine
{
protected:
	UEngine();

public:
	virtual ~UEngine();

	static UEngine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new UEngine();

			return Instance;
		}

		return Instance;
	}


	void Init();

	void Term();

	void SpawnActor(AActor* NewActor);

	void Run();

	void LoadLevel(std::string MapFilename);

	void Sort();

	vector<AActor*> Actors;

	static int KeyCode;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
	bool IsRunning;


	Uint64 GetWorldDeltaSeconds() { return DeltaSeconds; }


	Uint64 DeltaSeconds;
	Uint64 LastTime;

protected:
	void Input();
	void Tick();
	void Render();

	static UEngine* Instance;

};

#define GEngine UEngine::GetInstance()


