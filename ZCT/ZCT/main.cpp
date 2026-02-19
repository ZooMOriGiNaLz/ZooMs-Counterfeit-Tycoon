#include "raylib.h"
#include "Game.h"

int main(void)
{
	Game* game = new Game();
    game->Start();
    while (!WindowShouldClose())
    {
        game->Update();
        BeginDrawing();
        ClearBackground(DARKGRAY);
        game->Render();
        EndDrawing();
    }
    CloseWindow();
    delete(game);
    return 0;
}