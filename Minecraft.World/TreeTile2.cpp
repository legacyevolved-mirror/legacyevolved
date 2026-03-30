#include "stdafx.h"
#include "TreeTile2.h"

const unsigned int TreeTile2::TREE_NAMES[TreeTile2::TREE_NAMES_LENGTH] = {
    IDS_TILE_LOG_ACACIA,
    IDS_TILE_LOG_DARK_OAK
};

TreeTile2::TreeTile2(int id) : TreeTile(id)
{
}

int TreeTile2::getWoodType(int data)
{
    return (data & MASK_TYPE) + 4;
}