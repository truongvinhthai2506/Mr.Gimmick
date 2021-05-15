#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"
#include "Background.h"
#include "LevelOne.h"
#include "ScrollBar.h"
#include "Waterfall.h"
#include "Enemies.h"
#include "HazardsAndInteractables.h"
#include "ItemsAndHUD.h"
#include "Bosses.h"
#include "Treasures.h"
#include "PassiveCreatures.h"
#include "Quadtree.h"

#pragma region Definition
#define APP_TITLE L"Mr.Gimmick"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

#define FULLSCREEN 0
#define SCREEN_WIDTH 16 * TILE_SIZE * SCALE
#define SCREEN_HEIGHT 12 * TILE_SIZE * SCALE
#define SCREEN_DIMENSION Dimension(SCREEN_WIDTH, SCREEN_HEIGHT);
#define SCENE_MIN_WIDTH TILE_SIZE
#define SCENE_MAX_WIDTH 67 * TILE_SIZE

#define FPS 30
#pragma endregion

class Game
{
private:
	#pragma region Attributes
	TwoDimensionObj scene;
	int indexOfScene;
	Camera camera;
	Yumetaro yumetaro;
	Bosses boss;
	UselessObj** uselessObjs;
	PassiveCreatures* passiveCreatures;
	int numberOfUselessObjs;
	int numberOfPassiveCreatures;
	DirectX directX;
	HWND window;
	Background background;
	Quadtree quadtree;
	map<int, GameObj*> gameObjs;
	#pragma endregion
public:
	#pragma region Operations
	#pragma region Init
	Game();
	Game(const Game& game);
	bool InitGame(HWND window);
	void InitUselessObjs(int key, int* numberOfUselessObjs);
	void InitEnemies();
	void InitHazardsAndInteractables();
	void InitItemsAndHUD();
	void InitPassiveCreatures();
	TreeObj* InitTreeObjs();
	#pragma endregion
	bool LoadGame();
	void RunGame(HWND window);
	void UpdateGame();
	void Render();
	~Game();
	void EndGame(HWND window);
	#pragma endregion
};