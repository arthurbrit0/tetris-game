#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    gameScore = 0;
};

Block Game::GetRandomBlock(){

    if(blocks.empty()){
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    return block;
};

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
};

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw(11, 11);
    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
    }
};

void Game::HandleInput(){
    int keyPressed = GetKeyPressed();

    if(gameOver && keyPressed != 0){
        gameOver = false;
        Reset();
    }

    switch(keyPressed){
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
    };
}

void Game::MoveBlockLeft(){
    if(!gameOver){
        currentBlock.Move(0,-1);
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.Move(0,1);
        }
    }
};

void Game::MoveBlockRight(){
    if(!gameOver){
        currentBlock.Move(0,1);
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.Move(0,-1);
        }
    }
};

void Game::MoveBlockDown(){
    if(!gameOver){
        currentBlock.Move(1,0);
        if(isBlockOutside() || BlockFits() == false){
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}
bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
};

void Game::RotateBlock(){
    currentBlock.Rotate();
    if(isBlockOutside()){
        currentBlock.UndoRotation();
    }
}
void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}
bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        if(grid.IsCellEmpty(item.row, item.column) == false ){ // verificando se as posicoes do grid que o bloco passa a ocupar estao livres ou nao
            return false;                                      // se alguma posicao ja estiver ocupada, quer dizer que o bloco não pode encaixar ali
        };
    }
    return true;
}
void Game::Reset() {
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameScore = 0;
}
void Game::UpdateScore(int linesCleared, int moveDownPoints) {
    switch(linesCleared){
        case 1:
            gameScore += 100;
            break;
        case 2:
            gameScore += 300;
            break;
        case 3:
            gameScore += 500;
            break;
        default:
            break;
    }

    gameScore += moveDownPoints;
};