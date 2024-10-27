#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

// usaremos a biblioteca raylib para os graficos

double lastUpdateTime = 0;

bool EventTriggered(double interval){           // função para setar o intervalo de 0.2 segundos para a função MoveBlockDown
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){   // caso não usassemos essa função, a função MoveBlockDown seria executada 60x/s (o framerate está definido como 60 fps)
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    InitWindow(500, 620, "Tetris");      // inicializando a janela com 300x600 e o titulo tetris
    SetTargetFPS(60);                    // setando o fps padrão da janela para 60

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);


    Game game = Game();
    
    while(WindowShouldClose() == false) { // loop para, enquanto esc não for pressionado ou o botão de fechar não for pressionado, a janela continuará funcionando
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();                   // função do raylib para começar o desenho
        ClearBackground(darkBlue);        // definindo o fundo como azul escuro

        DrawTextEx(font, "Pontos", {350, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Próximo", {345, 175}, 38, 2, WHITE);
        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {325, 450}, 26, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.gameScore);

        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.Draw();                      // método draw do game desenhará o grid e os blocos, tanto atual como o próximo

        EndDrawing();
    };

    // depois que WindowShouldClose for true, a janela será fechada
    CloseWindow();
}