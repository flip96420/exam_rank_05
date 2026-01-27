#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game
{
	int		width;
	int		height;
	int		iterations;
	int		x;
	int		y;
	char	alive;
	char	dead;
	int		draw;
	char	**board;
} t_game;