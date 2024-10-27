#include "grid.h"
#include "blocks.cpp"
#include <raylib.h>

// usaremos a biblioteca raylib para os graficos

int main() {
    Color darkBlue = {44, 44, 127, 255}; // definindo a cor do plano de fundo da janela
    InitWindow(300, 600, "Tetris");      // inicializando a janela com 300x600 e o titulo tetris
    SetTargetFPS(60);                    // setando o fps padrão da janela para 60

    Grid grid = Grid();                  // criando a grid criada no header Grid
    grid.Print();                        // printando os valores numericos de cada celula do grid no console

    TBlock block = TBlock();
    while(WindowShouldClose() == false) { // loop para, enquanto esc não for pressionado ou o botão de fechar não for pressionado, a janela continuará funcionando
        BeginDrawing();                   // função do raylib para começar o desenho
        ClearBackground(darkBlue);        // definindo o fundo como azul escuro
        grid.Draw();                      // desenhando o grid
        block.Draw();                     // desenhando o bloco

        EndDrawing();
    };

    // depois que WindowShouldClose for true, a janela será fechada
    CloseWindow();
}