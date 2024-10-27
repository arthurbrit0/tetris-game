#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {           // header que definira a classe dos blocos
    public:
        Block();        // assinando o metodo construtor,
        void Draw();    // o método Draw,
        int id;         // o atributo id do bloco
        std::map<int, std::vector<Position>> cells;     // o objeto (com chave inteira e valor de vetor de posicoes) que armazenara vetores de posicoes que dependem do estado de rotacao
    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;

};