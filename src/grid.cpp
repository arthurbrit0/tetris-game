#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid(){                       // implementando método construtor de Grid
    numRows = 20;                   // implementando o valor de 20 linhas e 10 colunas
    numCols = 10;
    cellSize = 30;                  // definindo o tamanho da celula como 30
    Initialize();                   // definindo todos os valores do array bidimensional do grid como 0

    colors = GetCellColors();       // usando o método GetCellColors para criar um vetor com as cores do grid
};

void Grid::Initialize(){            // implementando o método initialize
    for(int row = 0; row < numRows; row++){     // para cada linha
        for(int column = 0; column < numCols; column++) {    // para acada coluna
            grid[row][column]=0;                             // definiremos o valor de cada celula como 0, inicialmente
        }
    }
};

void Grid::Print(){                                          // implementando o método print
    for(int row = 0; row < numRows; row++){                  // para cada linha
        for(int column = 0; column < numCols; column++){     // para cada coluna
            std::cout << grid[row][column] << " ";           // printaremos o valor atual de cada celula no console
        }
        std::cout << std::endl;
    }
};


void Grid::Draw(){
    for(int row = 0; row < numRows; row++) {
        for(int column = 0; column < numCols; column++) {
            int cellValue = grid[row][column];
            DrawRectangle(column*cellSize+1, row*cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
};