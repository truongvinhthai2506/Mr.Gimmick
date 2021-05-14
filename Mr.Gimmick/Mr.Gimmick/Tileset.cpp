#include "Tileset.h"

Tileset::Tileset()
{
	this->numberOfTiles = 0;
	this->tiles = NULL;
	this->backgroundColor = NULL;
}

Tileset::Tileset(int numberOfTiles, LPCWSTR nameOfLevel, D3DCOLOR backgroundColor)
{
	this->backgroundColor = backgroundColor;
	this->numberOfTiles = numberOfTiles;
	this->tiles = new Tile*[numberOfTiles];

	LPCWSTR filePath = FOLDER_TILESET_PATH, filePath1 = L"/Tileset/Tileset_", filename;
	wstring ws = wstring(filePath) + nameOfLevel + filePath1;
	wstring* wss = new wstring[numberOfTiles];
	string index;
	int tileSize = TILE_SIZE;
	float scale = SCALE;
	Image* image;

	for (int i = 0; i < numberOfTiles; i++)
	{
		index = to_string(i);
		wss[i] = ws + wstring(index.begin(), index.end()) + L".jpg";
		filename = wss[i].c_str();

		if (CheckTile(i, 2, 140, 4, 14))
		{
			image = new Sprite(Dimension(tileSize, tileSize), filename, 1, 0, 1);
			this->tiles[i] = new ScrollBarTile(Point(i * tileSize, 0), (Sprite*)image);
		}
		else if (CheckTile(i, 8, 94, 4, 14) || CheckTile(i, 4, 205, 4, 14))
		{
			image = new Sprite(Dimension(tileSize, tileSize), filename, 1, 0, 1);
			this->tiles[i] = new WaterTile(Point(i * tileSize, 0), (Sprite*)image);
		}
		else
		{
			image = new Image(Dimension(tileSize * scale, tileSize * scale), filename);
			this->tiles[i] = new InanimatedTile(Point(i * tileSize * scale, 0), image);
		}
	}

	// ?
	//delete[] wss;
	// ?
}

void Tileset::Copy(const Tileset& tileset)
{
	this->numberOfTiles = tileset.numberOfTiles;
	this->backgroundColor = tileset.backgroundColor;
	this->tiles = new Tile*[tileset.numberOfTiles];

	for (int i = 0; i < tileset.numberOfTiles; i++)
	{
		this->tiles[i] = tileset.tiles[i]->Clone();
	}
}

Tileset::Tileset(const Tileset& tileset)
{
	Copy(tileset);
}

void Tileset::Clean()
{
	for (int i = 0; i < this->numberOfTiles; i++)
	{
		delete this->tiles[i];
	}

	delete[] this->tiles;
}

Tileset& Tileset::operator = (const Tileset& tileset)
{
	if (this != &tileset)
	{
		Clean();
		Copy(tileset);
	}

	return *this;
}

Tileset::~Tileset()
{
	Clean();
}

bool Tileset::CheckTile(int value, int numberOfRows, int firstTile, int numberOfTiles,
	int numberOfTilesInOneRow)
{
	int lastTile = firstTile + numberOfTiles - 1;
	int step;

	for (int i = 0; i < numberOfRows; i++)
	{
		step = numberOfTilesInOneRow * i;

		if (value >= firstTile + step && value <= lastTile + step)
		{
			return 1;
		}
	}

	return 0;
}

void Tileset::LoadTileset(DirectXGraphic directXGraphic)
{
	for (int i = 0; i < this->numberOfTiles; i++)
	{
		this->tiles[i]->Load(this->backgroundColor, directXGraphic);
	}
}

Tile** Tileset::GetTiles()
{
	return this->tiles;
}

Tile* Tileset::GetElement(int i)
{
	return this->tiles[i];
}