#include "BlockState.h"
#include "Property.h" 
#include "Tile.h"

BlockState::BlockState(Tile* tile, const std::map<const Property*, int>& properties)
    : mTile(tile), mProperties(properties) 
{
}

Tile* BlockState::getTile() const 
{
    return mTile;
}

const std::map<const Property*, int>& BlockState::getProperties() const 
{
    return mProperties;
}

int BlockState::getValue(const Property* prop) const 
{
    auto it = mProperties.find(prop);
    if (it != mProperties.end()) {
        return it->second;
    }
    throw std::invalid_argument("Property does not exist");
}

BlockState* BlockState::setValue(const Property* prop, int newValue) const 
{
    
    auto propIt = mPropertyValueTable.find(prop);
    if (propIt != mPropertyValueTable.end()) {
        
        auto valueIt = propIt->second.find(newValue);
        if (valueIt != propIt->second.end()) {
            return valueIt->second; 
        }
    }
    throw std::invalid_argument("Property missing or value is not valid");
}

BlockState* BlockState::cycle(const Property* prop) const 
{
    
    int currentValue = getValue(prop);
    
   
    
    auto propIt = mPropertyValueTable.find(prop);
    if (propIt != mPropertyValueTable.end()) {
        const auto& valueMap = propIt->second;
        
        
        auto currentIt = valueMap.find(currentValue);
        if (currentIt != valueMap.end()) {
            auto nextIt = std::next(currentIt);
            
            
            if (nextIt == valueMap.end()) {
                nextIt = valueMap.begin();
            }
            
            return nextIt->second;
        }
    }
    
   
    return const_cast<BlockState*>(this);
}

void BlockState::buildPropertyValueTable(const std::map<const Property*, std::map<int, BlockState*>>& table) 
{
    mPropertyValueTable = table;
}