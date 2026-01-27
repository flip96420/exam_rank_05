#include "life.h"

void freeBoard(char **board)
{
	int i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}

int initGame(char **av, t_game *game)
{
	game->width = atoi(av[1]);
	game->height = atoi(av[2]);
	game->iterations = atoi(av[3]);
	game->x = 0;
	game->y = 0;
	game->alive = '0';
	game->dead = ' ';
	game->draw = 0;

	game->board = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!game->board)
		return (0);
	game->board[game->height] = NULL;

	for (int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc((game->width + 1) * sizeof(char));
		if (!game->board[i])
			return (0);
		game->board[i][game->width] = '\0';
		
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = game->dead;
	}
	return (1);
}

void fillBoard(t_game *game)
{
	char buffer;

	while(read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch(buffer)
		{
			case 'w':
				if (game->y > 0)
					game->y--;
				break;
			case 'a':
				if (game->x > 0)
					game->x--;
				break;
			case 's':
				if (game->y < game->height - 1)
					game->y++;
				break;
			case 'd':
				if (game->x < game->width - 1)
					game->x++;
				break;
			case 'x':
				game->draw = !(game->draw);
				break;
			default:
				return;
		}
		if (game->draw)
			game->board[game->y][game->x] = game->alive;
	}
}

int countNeighbours(int y, int x, t_game *game)
{
	int count = 0, ny = 0, nx = 0;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			
			ny = i + y;
			nx = j + x;

			if (ny >= 0 && ny < game->height && nx >= 0 && nx < game->width && game->board[ny][nx] == game->alive)
				count++;
		}
	}
	return (count);
}

int play(t_game *game)
{
	char **temp = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!temp)
		return (0);
	
	for (int y = 0; y < game->height; y++)
	{
		temp[y] = (char *)malloc((game->width + 1) * sizeof(char));
		if (!temp[y])
			return (0);

		temp[y][game->width] = '\0';
	}
	temp[game->height] = NULL;
		

	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			int n_num = countNeighbours(y, x, game);
			if (game->board[y][x] == game->alive)
			{
				if (n_num == 2 || n_num == 3)
					temp[y][x] = game->alive;
				else
					temp[y][x] = game->dead;
			}
			else
			{
				if (n_num == 3)
					temp[y][x] = game->alive;
				else
					temp[y][x] = game->dead;
			}
		}
	}
	freeBoard(game->board);
	game->board = temp;
	return (1);
}

void printBoard(t_game *game)
{
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			putchar(game->board[y][x]);
		}
		putchar('\n');
	}
}

int main(int ac, char **av)
{
	t_game game;
	if (ac != 4 || !initGame(av, &game))
		return (1);
	
	fillBoard(&game);
	for (int i = 0; i < game.iterations; i++)
	{
		if (!play(&game))
		{
			freeBoard(game.board);
			return (1);
		}
	}
	printBoard(&game);
	freeBoard(game.board);
	return (0);
}