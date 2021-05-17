#include "Game.h"

Game::Game()
{
	this->uselessObjs = NULL;
	this->window = NULL;
	this->numberOfUselessObjs = this->indexOfScene = 0;
}

Game::Game(const Game& game)
{
	this->scene = game.scene;
	this->indexOfScene = game.indexOfScene;
	this->camera = game.camera;
	this->quadtree = game.quadtree;
	this->yumetaro = game.yumetaro;
	this->background = game.background;
	this->directX = game.directX;
	this->window = game.window;
	this->boss = game.boss;
	this->gameObjs = game.gameObjs;

	this->numberOfUselessObjs = game.numberOfUselessObjs;
	this->uselessObjs = new UselessObj*[game.numberOfUselessObjs];

	for (int i = 0; i < game.numberOfUselessObjs; i++)
	{
		this->uselessObjs[i] = game.uselessObjs[i]->Clone();
	}

	this->numberOfPassiveCreatures = game.numberOfPassiveCreatures;
	this->passiveCreatures = new PassiveCreatures[game.numberOfPassiveCreatures];

	for (int i = 0; i < game.numberOfPassiveCreatures; i++)
	{
		this->passiveCreatures[i] = game.passiveCreatures[i];
	}
}

bool Game::InitGame(HWND window)
{
	Dimension screenDimension = SCREEN_DIMENSION;

	this->camera = Camera(Point(TILE_SIZE, TILE_SIZE * 37), Dimension(SCREEN_WIDTH / SCALE,
		SCREEN_HEIGHT / SCALE));
	this->scene = TwoDimensionObj(Point(16, 16 * 13));
	this->scene.SetDimension(Dimension(16 * 64, 16 * 13));

	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, screenDimension, FULLSCREEN);

	this->yumetaro = Yumetaro(1);
	this->gameObjs[1] = &this->yumetaro;
	this->boss = Bosses(Point(16 * 70 - 4, 16 * 6 + 2), 2);
	this->gameObjs[3] = new Treasures(Point(16 * 5 + 3, 16 * 5 + 5), 3);

	this->background = Background(NUMBER_OF_ROWS_LEVEL_ONE, NUMBER_OF_COLUMNS_LEVEL_ONE,
		FILE_TILEMAP_PATH_LEVEL_ONE, NUMBER_OF_TILES_LEVEL_ONE, L"Level_1", BACKGROUND_COLOR_LEVEL_ONE);

	const int numberOfTypeOfUselessObjs = NUMBER_OF_TYPE_OF_USELESS_OBJS;
	int numberOfUselessObjs[numberOfTypeOfUselessObjs + 1];
	numberOfUselessObjs[0] = 0;
	numberOfUselessObjs[1] = numberOfUselessObjs[0] + NUMBER_OF_SCROLLBARS;
	numberOfUselessObjs[2] = numberOfUselessObjs[1] + NUMBER_OF_WATERFALLS;

	this->numberOfUselessObjs = numberOfUselessObjs[numberOfTypeOfUselessObjs];
	this->uselessObjs = new UselessObj * [this->numberOfUselessObjs];

	for (int i = 0; i < numberOfTypeOfUselessObjs; i++)
	{
		InitUselessObjs(i, numberOfUselessObjs);
	}

	InitEnemies();
	InitHazardsAndInteractables();
	InitItemsAndHUD();
	InitPassiveCreatures();

	this->gameObjs.insert(pair<int, GameObj*>(this->boss.GetID(), &this->boss));

	map<int, QuadtreeNode*> quadtreeNodes = this->quadtree.InitQuadtreeNodeFromFile(this->gameObjs);
	this->quadtree.LinkQuadtreeNode(quadtreeNodes);

	return flag;
}

void Game::InitUselessObjs(int key, int* numberOfUselessObjs)
{
	for (int i = numberOfUselessObjs[key]; i < numberOfUselessObjs[key + 1]; i++)
	{
		switch (key)
		{
			case 0:
			{
				this->uselessObjs[i] = new ScrollBar(Point(288, 288), 1, 20 + i - 
					numberOfUselessObjs[key]);
				break;
			}
			case 1:
			{
				this->uselessObjs[i] = new Waterfall(Point(1056, 16), 1, 24);
				break;
			}
		}

		this->gameObjs.insert(pair<int, GameObj*>(this->uselessObjs[i]->GetID(), this->uselessObjs[i]));
	}
}

void Game::InitEnemies()
{
	this->gameObjs[4] = new Enemies(Point(16 * 28, 16 * 22), 4);
	this->gameObjs[5] = new Enemies(Point(16 * 30, 16 * 22), 5);
	this->gameObjs[6] = new Enemies(Point(16 * 33, 16 * 21), 6);
	this->gameObjs[7] = new Enemies(Point(16 * 37, 16 * 22), 7);
	this->gameObjs[8] = new Enemies(Point(16 * 41, 16 * 21), 8);
	this->gameObjs[9] = new Enemies(Point(16 * 45, 16 * 22), 9);
	this->gameObjs[10] = new Enemies(Point(16 * 47, 16 * 22), 10);
	this->gameObjs[11] = new Enemies(Point(16 * 49, 16 * 22), 11);
	this->gameObjs[12] = new Enemies(Point(16 * 36, 16 * 31), 12);
	this->gameObjs[13] = new Enemies(Point(16 * 114, 16 * 28), 13);
	this->gameObjs[14] = new Enemies(Point(16 * 114, 16 * 19), 14);
	this->gameObjs[15] = new Enemies(Point(16 * 108, 16 * 7), 15);
	this->gameObjs[16] = new Enemies(Point(16 * 89, 16 * 10), 16);
	this->gameObjs[17] = new Enemies(Point(16 * 85, 16 * 10), 17);
	this->gameObjs[18] = new Enemies(Point(16 * 47, 16 * 40 - 3), 18, Dimension(26, 19.4), 17);
	this->gameObjs[19] = new Enemies(Point(16 * 117, 16 * 31 - 3), 19, Dimension(26, 19.4), 17);
}

void Game::InitHazardsAndInteractables()
{
	for (int i = 0; i < 2; i++)
	{
		this->gameObjs[25 + i] = new HazardsAndInteractables(Point(16 * (55 - i * 3), 16 * 27), 25 + i);
	}

	for (int i = 2; i < 6; i++)
	{
		this->gameObjs[25 + i] = new HazardsAndInteractables(Point(16 * (53 + (i - 2) * 2), 16 * 39), 
			25 + i);
	}

	for (int i = 6; i < 8; i++)
	{
		this->gameObjs[25 + i] = new HazardsAndInteractables(Point(16 * (64 + (i - 6) * 2), 16 * 39), 
			25 + i);
	}

	this->gameObjs[33] = new HazardsAndInteractables(Point(16 * 36, 16 * 28 - 2), 33, 6);
	this->gameObjs[34] = new HazardsAndInteractables(Point(16 * 74, 16 * 42 - 2), 34, 6);
	this->gameObjs[35] = new HazardsAndInteractables(Point(16 * 115 + 8, 16 * 41 + 1), 35, 1, 
		Dimension(53, 77), 3);
}

void Game::InitItemsAndHUD()
{
	this->gameObjs[42] = new ItemsAndHUD(Point(16 * 27, 16 * 19 + 1), 42, 2);
	this->gameObjs[43] = new ItemsAndHUD(Point(16 * 34, 16 * 43), 43, 3);
	this->gameObjs[44] = new ItemsAndHUD(Point(16 * 126, 16 * 22), 44, 2);
	this->gameObjs[45] = new ItemsAndHUD(Point(16 * 127 - 6, 16 * 4 + 1), 45, 4, Dimension(16.5, 16.5));
}

void Game::InitPassiveCreatures()
{
	this->numberOfPassiveCreatures = NUMBER_OF_PASSIVE_CREATURES;
	this->passiveCreatures = new PassiveCreatures[this->numberOfPassiveCreatures];
	this->passiveCreatures[0] = PassiveCreatures(Point(16 * 110, 16 * 41), 36, 1);
	this->passiveCreatures[1] = PassiveCreatures(Point(16 * 106, 16 * 41), 37, 2);
	this->passiveCreatures[2] = PassiveCreatures(Point(16 * 102, 16 * 48 - 8), 38, 2);
	this->passiveCreatures[3] = PassiveCreatures(Point(16 * 98, 16 * 47), 39, 3);
	this->passiveCreatures[4] = PassiveCreatures(Point(16 * 94, 16 * 42), 40, 3);
	this->passiveCreatures[5] = PassiveCreatures(Point(16 * 90, 16 * 39), 41, 3);

	for (int i = 0; i < this->numberOfPassiveCreatures; i++)
	{
		this->gameObjs.insert(pair<int, GameObj*>(this->passiveCreatures[i].GetID(), 
			&this->passiveCreatures[i]));
	}
}

TreeObj* Game::InitTreeObjs()
{
	TreeObj* treeObjs = new TreeObj[NUMBER_OF_GAME_OBJS];
	treeObjs[0] = TreeObj(&this->boss);
	treeObjs[1] = TreeObj(this->gameObjs[3]);
	int index = 2;

	for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		treeObjs[index + i] = TreeObj(this->gameObjs[i + 4]);
	}

	index += NUMBER_OF_ENEMIES;

	for (int i = 0; i < this->numberOfUselessObjs; i++)
	{
		treeObjs[index + i] = TreeObj(this->uselessObjs[i]);
	}

	index += this->numberOfUselessObjs;

	for (int i = 0; i < NUMBER_OF_HAZARDS_AND_INTERACTABLES; i++)
	{
		treeObjs[index + i] = TreeObj(this->gameObjs[i + 25]);
	}

	index += NUMBER_OF_HAZARDS_AND_INTERACTABLES;

	for (int i = 0; i < this->numberOfPassiveCreatures; i++)
	{
		treeObjs[index + i] = TreeObj(&this->passiveCreatures[i]);
	}

	index += numberOfPassiveCreatures;

	for (int i = 0; i < NUMBER_OF_ITEMS_AND_HUD; i++)
	{
		treeObjs[index + i] = TreeObj(this->gameObjs[i + 42]);
	}

	return treeObjs;
}

bool Game::LoadGame()
{
	DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();

	for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
	{
		this->gameObjs[i + 4]->Load(directXGraphic, ENEMIES_BACKGROUND_COLOR);
	}

	for (int i = 0; i < NUMBER_OF_HAZARDS_AND_INTERACTABLES; i++)
	{
		this->gameObjs[i + 25]->Load(directXGraphic, HAZARDS_AND_INTERACTABLES_BACKGROUND_COLOR);
	}

	for (int i = 0; i < NUMBER_OF_ITEMS_AND_HUD; i++)
	{
		this->gameObjs[i + 42]->Load(directXGraphic, ITEMS_AND_HUD_BACKGROUND_COLOR);
	}

	for (int i = 0; i < this->numberOfPassiveCreatures; i++)
	{
		this->passiveCreatures[i].Load(PASSIVE_CREATURES_BACKGROUND_COLOR, directXGraphic);
	}

	this->background.LoadBackground(directXGraphic);
	this->boss.Load(BOSSES_BACKGROUND_COLOR, directXGraphic);
	this->gameObjs[1]->Load(directXGraphic, YUMETARO_BACKGROUND_COLOR);
	this->gameObjs[3]->Load(directXGraphic, TREASURES_BACKGROUND_COLOR);

	this->background.LoadUselessObjs(this->uselessObjs);
	
	return 1;
}

void Game::RunGame(HWND window)
{
	// Đảm bảo Direct3D device đã có
	if (!this->directX.GetDirectXGraphic().GetGraphicDevice().CheckDevice())
	{
		return;
	}

	UpdateGame();
	Draw();

	// Kiểm tra phím escape (để kết thúc chương trình)
	if (KEY_DOWN(VK_ESCAPE))
	{
		PostMessage(window, WM_DESTROY, 0, 0);
	}
}

void Game::UpdateGame()
{
	int velocity = YUMETARO_VELOCITY_X, tileSize = TILE_SIZE;
	
	if (KEY_DOWN(0x56))
	{
		this->indexOfScene++;
		int tileSize = TILE_SIZE;
		int sceneHeight = tileSize * 12;

		switch (this->indexOfScene)
		{
			case 1:
			{
				this->scene.IncreaseSecondValueOfPoint(-sceneHeight);
				this->camera.SetPoint(Point(tileSize * 49, tileSize * 49));
				this->yumetaro.SetPoint(Point(tileSize * 57, 41 * tileSize + 4));
				break;
			}
			case 2:
			{
				this->scene.IncreaseSecondValueOfPoint(sceneHeight);
				this->camera.SetPoint(Point(tileSize * 49, tileSize * 49 - sceneHeight));
				this->yumetaro.SetPoint(Point(tileSize * 56, tileSize * 44 - sceneHeight + 4));
				break;
			}
			case 3:
			{
				this->scene.IncreaseFirstValueOfPoint(tileSize * 32);
				this->scene.IncreaseSecondValueOfPoint(sceneHeight);
				this->scene.SetFirstValueOfDimension(tileSize * 32);
				this->camera.SetPoint(Point(tileSize * 49, tileSize * 49 - sceneHeight * 2));
				this->yumetaro.SetPoint(Point(tileSize * 57, tileSize * 42 - sceneHeight * 2 + 4));
				break;
			}
			case 4:
			{
				this->scene.IncreaseSecondValueOfPoint(sceneHeight);
				this->scene.SetFirstValueOfDimension(tileSize * 49);
				this->camera.SetPoint(Point(tileSize * 33, tileSize * 49 - sceneHeight * 3));
				this->yumetaro.SetPoint(Point(tileSize * 38 - 8, tileSize * 40 - sceneHeight * 3 + 4));
				break;
			}
			case 5:
			{
				this->scene.IncreaseFirstValueOfPoint(tileSize * 48);
				this->scene.SetFirstValueOfDimension(tileSize * 32);
				this->camera.SetFirstValueOfPoint(tileSize * 81);
				this->yumetaro.SetFirstValueOfPoint(tileSize * 82 - 8);
				this->yumetaro.IncreaseSecondValueOfPoint(tileSize * 2);
				break;
			}
			case 6:
			{
				this->scene.IncreaseFirstValueOfPoint(tileSize * 32);
				this->scene.SetFirstValueOfDimension(tileSize * 16);
				this->camera.SetFirstValueOfPoint(tileSize * 113);
				this->yumetaro.SetFirstValueOfPoint(tileSize * 114 - 8);
				break;
			}
			case 7:
			{
				this->scene.IncreaseSecondValueOfPoint(-sceneHeight);
				this->camera.IncreaseSecondValueOfPoint(sceneHeight);
				this->yumetaro.IncreaseSecondValueOfPoint(sceneHeight);
				break;
			}
			case 8:
			{
				this->scene.IncreaseSecondValueOfPoint(-sceneHeight);
				this->camera.IncreaseSecondValueOfPoint(sceneHeight);
				this->yumetaro.IncreaseSecondValueOfPoint(sceneHeight);
				break;
			}
			case 9:
			{
				this->scene.IncreaseValueOfPoint(Pair(-tileSize * 32, -sceneHeight));
				this->camera.IncreaseSecondValueOfPoint(sceneHeight);
				this->yumetaro.IncreaseValueOfPoint(Pair(tileSize * 4, sceneHeight));
				this->scene.SetFirstValueOfDimension(tileSize * 48);
				break;
			}
			case 10:
			{
				this->scene.IncreaseFirstValueOfPoint(-tileSize * 16);
				this->camera.SetPoint(Point(tileSize * 65, tileSize * 49));
				this->yumetaro.SetPoint(Point(tileSize * 70, tileSize * 42 + 4));
				this->scene.SetFirstValueOfDimension(tileSize * 16);
				break;
			}
		}
	}

	// Di chuyển bằng bàn phím
	if (KEY_DOWN(VK_LEFT))
	{
		this->yumetaro.SetVelocity(Velocity(-velocity, 0));
		this->yumetaro.Move(Dimension(SCENE_MAX_WIDTH, SCREEN_HEIGHT));
		this->camera.Update(this->yumetaro, this->scene, tileSize);
		this->yumetaro.Animate();
	}

	if (KEY_DOWN(VK_RIGHT))
	{
		this->yumetaro.SetVelocity(Velocity(velocity, 0));
		this->yumetaro.Move(Dimension(SCENE_MAX_WIDTH, SCREEN_HEIGHT));
		this->yumetaro.Animate();
		this->camera.Update(this->yumetaro, this->scene, tileSize);
	}

	if (KEY_DOWN(VK_UP))
	{
		if (camera.GetPoint().GetFirstValue() == SCENE_MIN_WIDTH ||
			camera.GetPoint().GetFirstValue() == SCENE_MAX_WIDTH)
		{
			this->yumetaro.SetVelocity(Velocity(0, -velocity));
			this->yumetaro.Move(Dimension(SCENE_MAX_WIDTH, SCREEN_HEIGHT));
		}

		this->yumetaro.Animate();
		this->camera.Update(this->yumetaro, this->scene, tileSize);
	}

	if (KEY_DOWN(VK_DOWN))
	{
		if (camera.GetPoint().GetFirstValue() == SCENE_MIN_WIDTH ||
			camera.GetPoint().GetFirstValue() == SCENE_MAX_WIDTH)
		{
			this->yumetaro.SetVelocity(Velocity(0, velocity));
			this->yumetaro.Move(Dimension(SCENE_MAX_WIDTH, SCREEN_HEIGHT));
		}

		this->yumetaro.Animate();
		this->camera.Update(this->yumetaro, this->scene, tileSize);
	}

	for (int i = 0; i < this->numberOfUselessObjs; i++)
	{
		this->uselessObjs[i]->Synchronize();
	}

	this->background.UpdateBackground(this->directX.GetDirectXGraphic());
}

void Game::Draw()
{
	Sleep(1000 / FPS);

	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();
	Camera camera(Point(this->camera.GetPoint().GetFirstValue(), MAP_LEVEL_ONE_HEIGHT -
		this->camera.GetPoint().GetSecondValue()), this->camera.GetDimension());
	this->quadtree.ListObjInCamera(camera, this->quadtree.GetRoot());
	map<int, GameObj*> gameObjsInCamera = this->quadtree.GetGameObjsInCamera();
	map<int, GameObj*>::iterator it;

	// Bắt đầu render
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		this->background.DrawBackground(directXGraphic.GetGraphicDevice().GetBackbuffer(), 
			directXGraphic, this->camera);

		Point cameraPoint = this->camera.GetPoint();
		this->yumetaro.Draw(graphicDevice, cameraPoint);

		for (it = gameObjsInCamera.begin(); it != gameObjsInCamera.end(); it++)
		{
			it->second->Draw(graphicDevice, cameraPoint);
		}

		// Dừng render
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();
}

Game::~Game()
{
	delete[] this->uselessObjs;
}

void Game::EndGame(HWND window)
{
	this->directX.ReleaseDirectX();
}