#include <raylib.h>
#include "grid.h"

// usaremos a biblioteca raylib para os graficos

int main() {
    Color darkBlue = {44, 44, 127, 255}; // definindo a cor do plano de fundo da janela
    InitWindow(300, 600, "Tetris");      // inicializando a janela com 300x600 e o titulo tetris
    SetTargetFPS(60);                    // setando o fps padrão da janela para 60

    Grid grid = Grid();                  // criando a grid criada no header Grid
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[18][19] = 7;
    grid.Print();

    while(WindowShouldClose() == false) { // loop para, enquanto esc não for pressionado ou o botão de fechar não for pressionado, a janela continuará funcionando
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();

        EndDrawing();
    };

    // depois que WindowShouldClose for true, a janela será fechada
    CloseWindow();
}