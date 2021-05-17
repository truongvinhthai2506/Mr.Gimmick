#pragma once

#include "DirectXGraphic.h"
#include "Tile.h"
#include "Sprite.h"
#include "TransformHandler.h"
#include "Tilemap.h"

class AnimatedTile : public Tile
{
protected:
    int numberOfDrawings, indexOfRowInSprite;
    Sprite* sprite;
    LPDIRECT3DTEXTURE9 texture;
public:
    AnimatedTile();
    AnimatedTile(Point point, Sprite* sprite, int indexOfRowInSprite = 1);
    AnimatedTile(const AnimatedTile& animatedTile);
    ~AnimatedTile();
    void Draw(GraphicDevice graphicDevice, Point cameraPoint, bool isRotate = 0, 
        LPDIRECT3DSURFACE9 backbuffer = NULL);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
    RECT* GetRectangleOfSprite();
    Sprite* GetSprite();
    void Animate();
    Tile* Clone();
    string GetType();
    int GetNumberOfDrawings();
    void SetNumberOfDrawings(int numberOfDrawings);
    int GetIndexOfNewImageOfTile(int value, int firstTile, int lastTile, string direction, int i, int j, 
        int tileSize);
};