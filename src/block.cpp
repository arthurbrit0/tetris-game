#include "block.h"

Block::Block(){                 // implementando o construtor da classe block
    cellSize = 30;              // definindo o tamanho da celula como 30
    rotationState = 0;          // o estado de rotacao vai ser definido como 0, inicialmente
    colors = GetCellColors();   // as cores virão do método GetCellColors
    rowOffset = 0;
    columnOffset = 0;
};

void Block::Draw(int offsetX, int offsetY){
    std::vector<Position> tiles = GetCellPositions();
    for(Position item: tiles) {                             // para cada pixel no vetor de posições atual,
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);     // desenharemos o bloco correspondente ao rotationState
    }
};

void Block::Move(int rows, int columns){    // implementando o método Move, que recebe como parâmetros o número de linhas e colunas que deverão ser movidas
    rowOffset += rows;                      // adicionando ao rowOffset o n de linhas que o bloco sera movido
    columnOffset += columns;                // adicionando ao columnOffset o n de colunas que o bloco sera movido
};

std::vector<Position> Block::GetCellPositions(){        // implementando o método GetCellPositions, que retornará um vetor do tipo Position
    std::vector<Position> tiles = cells[rotationState]; // definimos os pixels atuais, pegando o objeto cells e pegando o vetor de pixels correspndente ao rotationState atual
    std::vector<Position> movedTiles;                   // inicializamos o vetor movedTiles

    for(Position item : tiles){                         // para cada posicao no vetor de posicoes atual,
        Position newPosition = Position(item.row + rowOffset, item.column + columnOffset);  // criaremos uma nova posicao, pegando o valor atual da linha e somando com o offset (mesma coisa par a acoluna)
        movedTiles.push_back(newPosition);                                                  // adicionamos essa novaPosicao no vetor movedTiles  
    }

    return movedTiles;
};

void Block::Rotate() {
    rotationState++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
};

void Block::UndoRotation() {
    rotationState--;
    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }
};
