#include "block.h"

Block::Block(){         // implementando o construtor da classe block
    cellSize = 30;      // definindo o tamanho da celula como 30
    rotationState = 0;  // o estado de rotacao vai ser definido como 0, inicialmente
    colors = GetCellColors();   // as cores virão do método GetCellColors
}

void Block::Draw(){
    std::vector<Position> tiles = cells[rotationState];     // a posição que será a atual dependerá do rotationState
    for(Position item: tiles) {                             // para cada pixel no vetor de posições atual,
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);     // desenharemos o bloco correspondente ao rotationState
    }
};