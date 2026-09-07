#ifndef BSQ_H
#define BSQ_H

#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
    int width;
    int height;
    char empty;
    char obstacle;
    char full;
    char **grid;
} t_map;

int min3(int a, int b, int c);
void free_map(t_map *map);
int fail_read(char *line, t_map *map);
int read_map(FILE *f, t_map *map);
void solve(t_map *map);
void print_map(t_map *map);
int process_map(FILE *f);

#endif