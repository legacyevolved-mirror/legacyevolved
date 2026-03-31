#pragma once

#include <map>
#include <vector>
#include <stdexcept>


class Tile;
class Property;

class BlockState {
private:

    Tile* mTile;
    unsigned short m_stateId = 0;

    std::map<const Property*, int> mProperties;
    
   
    std::map<const Property*, std::map<int, BlockState*>> mPropertyValueTable;

public:
    // Costruttore
    BlockState(Tile* tile, const std::map<const Property*, int>& properties);


    Tile* getTile() const;

    const std::map<const Property*, int>& getProperties() const;

 
    int getValue(const Property* prop) const;


    BlockState* setValue(const Property* prop, int newValue) const;

  
    BlockState* cycle(const Property* prop) const;
    unsigned short getStateId() const { return m_stateId; }
    void setStateId(unsigned short id) { m_stateId = id; }
    
    void buildPropertyValueTable(const std::map<const Property*, std::map<int, BlockState*>>& table);
};