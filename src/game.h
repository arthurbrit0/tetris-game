#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game();
        void Draw();

        void HandleInput();

        bool gameOver;

        int gameScore;

    private:
        Grid grid;

        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        bool isBlockOutside();
        std::vector<Block> blocks;

        Block currentBlock;
        Block nextBlock;
        
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
};