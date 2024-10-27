#include <raylib.h>
#include "game.h"

// usaremos a biblioteca raylib para os graficos

int main() {
    Color darkBlue = {44, 44, 127, 255}; // definindo a cor do plano de fundo da janela
    InitWindow(300, 600, "Tetris");      // inicializando a janela com 300x600 e o titulo tetris
    SetTargetFPS(60);                    // setando o fps padrão da janela para 60


    Game game = Game();
    
    while(WindowShouldClose() == false) { // loop para, enquanto esc não for pressionado ou o botão de fechar não for pressionado, a janela continuará funcionando
        game.HandleInput();
        BeginDrawing();                   // função do raylib para começar o desenho
        ClearBackground(darkBlue);        // definindo o fundo como azul escuro

        game.Draw();                      // método draw do game desenhará o grid e os blocos, tanto atual como o próximo

        EndDrawing();
    };

    // depois que WindowShouldClose for true, a janela será fechada
    CloseWindow();
}