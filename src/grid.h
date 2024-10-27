#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
        Grid();                         // método construtor
        void Initialize();              // função para inicializar o grid, definindo os valores das celulas como 0
        void Print();                   // função para printar o grid no console
        void Draw();                    // função para desenhar o grid na tela
        int grid[20][10];               // definindo o array bidimensional de celulas do grid
        bool IsCellOutside(int row, int column); // metodo para saber se um bloco está saindo do grid
        bool IsCellEmpty(int row, int column);
    private:
        int numRows;                    // numero de linhas do grid
        int numCols;                    // numero de colunas do grid
        int cellSize;                   // tamanho da celula
        std::vector<Color> colors;      // vetor do tipo Color (tipo do raylib) de cores do grid
};