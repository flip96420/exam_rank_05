#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_elements
{
	int		line_num;
	char 	empty;
	char 	obstacle;
	char 	full;
} t_elements;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
} t_map;

typedef struct s_square
{
	int size;
	int i;
	int j;
} t_square;

int runBSQ(FILE *file);
int readFile(char *filename);