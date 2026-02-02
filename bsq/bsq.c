#include "bsq.h"

// UTILS
void freeMap(char **grid)
{
	int i = 0;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int isPrintable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

char *ft_substr(char *src, int len)
{
	char *str = (char *)malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++) // <-- Change to len -1 if you want to exclude the newline character
		str[i] = src[i];
	str[len] = '\0';
	return (str);
}

int hasChar(char *line, char c1, char c2)
{
	int i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != c1 && line[i] != c2)
			return (0);
		i++;
	}
	return (1);
}


// PARSING
int loadNum(FILE *file, t_elements *elements)
{
	fscanf(file, "%d", &(elements->line_num));
	if (elements->line_num <= 0)
		return (0);
	return (1);
}

int loadElements(char *line, t_elements *elements)
{
	int i = 0;
	while (line[i] >= '0' && line[i] <= '9') // <-- Skip numbers in first line, because you already set it
		i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (!isPrintable(line[i]))
			return (0);
		if (!elements->empty)
			elements->empty = line[i];
		else
		{
			if (!elements->obstacle)
				elements->obstacle = line[i];
			else
			{
				if (!elements->full)
					elements->full = line[i];
			}
		}
		i++;
	}
	if (elements->empty == elements->obstacle || elements->empty == elements->full || elements->obstacle == elements->full)
		return (0);
	if (elements->line_num && elements->empty && elements->obstacle && elements->full)
		return (1);
	return (0);
}

int loadMap(FILE *file, t_map *map, t_elements *elements)
{
	size_t	size;
	char	*line;

	if (!getline(&line, &size, file) || !loadElements(line, elements))
		return (0);
	
	map->width = getline(&line, &size, file);
	map->height = elements->line_num;
	map->grid = (char **)malloc((map->height + 1) * sizeof(char *));
	map->grid[0] = ft_substr(line, map->width);
	
	for (int i = 1; i < map->height; i++)
	{
		int len = getline(&line, &size, file);
		if (len == -1 || len != map->width || !hasChar(line, elements->empty, elements->obstacle))
		{
			freeMap(map->grid);
			return (0);
		}
		map->grid[i] = ft_substr(line, map->width);
	}

	map->grid[map->height] = NULL;

	if (getline(&line, &size, file) != -1)
	{
		freeMap(map->grid);
		return (0);
	}
	return (1);
}


// FIND BIG SQUARE
int findMin(int n1, int n2, int n3)
{
	int min = n1;
	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return (min + 1);
}

void findBigSquare(t_map *map, t_elements *elements, t_square *square)
{
	int matrix[map->height][map->width];
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width - 1; j++) // <-- change to just map->width if excluded newline character in ft_substr
			matrix[i][j] = 0;
	}
	
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width - 1; j++) // <-- change to just map->width if excluded newline character in ft_substr
		{
			if (map->grid[i][j] == elements->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = findMin(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
			
			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - square->size + 1;
				square->j = j - square->size + 1;
			}
		}
	}
}


// PRINT
void printSquare(t_map *map, t_elements *elements, t_square *square)
{
	if (map->height == 1 && map->width == 2 && map->grid[0][0] == '0') {} // <-- Condition can be fully skipped if excluded newline character in ft_substr, probably xdd
	else
	{
		for (int i = square->i; i < square->i + square->size; i++)
		{
			for (int j = square->j; j < square->j + square->size; j++)
			{
				if (i < map->height && j < map->width)
					map->grid[i][j] = elements->full;
			}
		}
	}

	for (int i = 0; i < map->height; i++)
		fputs(map->grid[i], stdout); // <-- add a newline to the print, if excluded newline character in ft_substr
}


// RUN
int runBSQ(FILE *file)
{
	t_elements	elements;
	t_map		map;
	t_square	square;

	elements.line_num = 0; elements.empty = 0; elements.obstacle = 0; elements.full = 0;
	square.size = 0; square.i = 0; square.j = 0;
	if (!loadNum(file, &elements) || !loadMap(file, &map, &elements))
		return (0);
	
	findBigSquare(&map, &elements, &square);
	printSquare(&map, &elements, &square);
	return (1);
}

int readFile(char *filename)
{
	FILE *file = fopen(filename, "r");
	if (!file || !runBSQ(file))
		return (0);
	fclose(file);
	return (1);
}