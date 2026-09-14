#include "life.h"

int init_board(t_game *game, char *argv[])
{
    game->width = atoi(argv[1]);
    game->height = atoi(argv[2]);
    game->iterations = atoi(argv[3]);
    if (game->height <= 0 || game->width <= 0)
        return -1;
    game->alive = 'O';
    game->dead = ' ';
    game->i = 0;
    game->j = 0;
    game->draw = 0;
    game->board = (char **)calloc(game->height, sizeof(char *));
    if (!game->board)
        return -1;
    for (int i = 0; i < game->height; i++)
    {
        game->board[i] = (char *)malloc(game->width * sizeof(char));
        if (!game->board[i])
        {
            free_board(game);
            return -1;
        }
        for (int j = 0; j < game->width; j++)
            game->board[i][j] = game->dead;
    }
    return 0;
}

