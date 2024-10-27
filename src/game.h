#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game();
        Grid grid;
        Block GetRandomBlock();
        void Draw();
        std::vector<Block> GetAllBlocks();

        void HandleInput();

        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

    private:
        bool isBlockOutside();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
};