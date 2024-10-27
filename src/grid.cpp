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
    for(int row = 0; row < numRows; row++) {                 // iterando sobre todos os pixels do grid
        for(int column = 0; column < numCols; column++) {
            int cellValue = grid[row][column];               // pegamos o valor presente na celula do grid e desenhamos um quadrado com a cor do seu id
            DrawRectangle(column*cellSize+11, row*cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
};

bool Grid::IsCellOutside(int row, int column){                              // função para verificar se alguma cell está fora do grid
    if(row >= 0 && row < numRows && column >=0 && column < numCols) {       
        return false;
    }
    return true;
};

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0){
        return true;
    };
    return false;
}
int Grid::ClearFullRows()
{
    int completed = 0;                                  // inicializamos a variavel completed como 0, pois, inicialmente, nao ha linhas totalmente preenchidas
    for(int row = numRows - 1; row >= 0; row--){        // vamos percorrendo as linhas, da ultima ate o topo
        if(isRowFull(row))                              // se a linha estiver preenchida,
        {
            ClearRow(row);                              // limpamos ela (definimos todos os valores como 0)
            completed++;                                // incrementamos o valor de completed em 1
        } else if(completed > 0){                       // se a linha não estiver cheia,
            MoveRowDown(row, completed);                // movemos essa linha para baixo de acordo com a quantidade de linhas ja completadas
        }
    };
    return completed;                                   // retornamos a quantidade de linhas completadas, que servirá como pontuação
};

bool Grid::isRowFull(int row)
{
    for(int column = 0; column < numCols; column++){
        if(grid[row][column] == 0){
            return false;
        }
    }
    return true;
};

void Grid::ClearRow(int row) {
    for(int column = 0; column < numCols; column++){
        grid[row][column] = 0;
    };
};

void Grid::MoveRowDown(int row, int numRows) {
    for(int column = 0; column < numCols; column++){
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    };
};