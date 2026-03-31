#pragma once
#include <vector>


class BlockState; 

class BlockStateRegistry
{
private:
    
    static std::vector<BlockState*> m_statesById;

public:
    
    static void registerState(BlockState* state);

    
    static BlockState* getStateById(unsigned short id);

   
    static void init();
};