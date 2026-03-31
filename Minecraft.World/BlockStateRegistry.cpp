#include "BlockStateRegistry.h"
#include "BlockState.h" 


std::vector<BlockState*> BlockStateRegistry::m_statesById;

void BlockStateRegistry::init()
{
   
    m_statesById.clear();
    m_statesById.reserve(8192); 
}

void BlockStateRegistry::registerState(BlockState* state)
{
    if (state == nullptr) return;

    
    unsigned short newId = (unsigned short)m_statesById.size();
    
    
    state->setStateId(newId); 
    
    
    m_statesById.push_back(state);
}

BlockState* BlockStateRegistry::getStateById(unsigned short id)
{
    
    if (id >= m_statesById.size() || m_statesById.empty()) {
        return m_statesById.empty() ? nullptr : m_statesById[0]; 
    }

    return m_statesById[id];
}