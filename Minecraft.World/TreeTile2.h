#pragma once

#include "TreeTile.h"

class TreeTile2 : public TreeTile
{
    friend class Tile;
public:
    static const int TREE_NAMES_LENGTH = 2;
    static const unsigned int TREE_NAMES[TREE_NAMES_LENGTH];

protected:
    TreeTile2(int id);

public:
    virtual int getWoodType(int data);
};