#include "bsq.h"

int min3(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= c)
        return b;
    return c;
}

void free_map(t_map *map)
{
    if (map->grid)
    {
        for (int i = 0; i < map->height; i++)
            if (map->grid[i])
                free(map->grid[i]);
        free(map->grid);
        map->grid = NULL;
    }
}

int fail_read(char *line, t_map *map)
{
    free(line);
    free_map(map);
    return -1;
}

int read_map(FILE *f, t_map *map)
{
    char *line = NULL;
    size_t cap = 0;
    ssize_t n;
    map->grid = NULL;
    if (fscanf(f, "%d %c %c %c", &map->height, &map->empty, &map->obstacle, &map->full) != 4)
        return -1;
    if (map->height <= 0 || map->empty == map->obstacle || map->empty == map->full || map->obstacle == map->full)
        return -1;
    if (map->empty < ' ' || map->empty > '~' || map->obstacle < ' ' || map->obstacle > '~' || map->full < ' ' || map->full > '~')
        return -1;
    fscanf(f, "%*[^\n]");
    fscanf(f, "%*c");
    map->grid = (char **)calloc(map->height, sizeof(char *));
    if (!map->grid)
        return -1;
    for (int i = 0; i < map->height; i++)
    {
        n = getline(&line, &cap, f);
        if (n < 2 || line[n - 1] != '\n')
            return fail_read(line, map);
        if (i == 0)
            map->width = n - 1;
        if (map->width < 1 || n - 1 != map->width)
            return fail_read(line, map);
        map->grid[i] = (char *)malloc(map->width + 1);
        if (!map->grid[i])
            return fail_read(line, map);
        for (int j = 0; j < map->width; j++)
        {
            if (line[j] != map->empty && line[j] != map->obstacle)
                return fail_read(line, map);
            map->grid[i][j] = line[j];
        }
        map->grid[i][map->width] = '\0';
    }
    free(line);
    return 0;
}

void solve(t_map *map)
{
    int best = 0;
    int bx = 0;
    int by = 0;
    int *dp = (int *)calloc(map->width * map->height, sizeof(int));
    if (!dp)
        return;
    for (int y = 0; y < map->height; y++)
        for (int x = 0; x < map->width; x++)
        {
            if (map->grid[y][x] != map->empty)
                continue;
            if (x == 0 || y == 0)
                dp[y * map->width + x] = 1;
            else
                dp[y * map->width + x] = 1 + min3(dp[(y - 1) * map->width + x],
                    dp[y * map->width + x - 1], dp[(y - 1) * map->width + x - 1]);
            if (dp[y * map->width + x] > best)
            {
                best = dp[y * map->width + x];
                bx = x;
                by = y;
            }
        }
    for (int y = by - best + 1; y <= by; y++)
        for (int x = bx - best + 1; x <= bx; x++)
            map->grid[y][x] = map->full;
    free(dp);
}

void print_map(t_map *map)
{
    for (int i = 0; i < map->height; i++)
        fprintf(stdout, "%s\n", map->grid[i]);
}

int process_map(FILE *f)
{
    t_map map;
    if (read_map(f, &map) == -1)
        return -1;
    solve(&map);
    print_map(&map);
    free_map(&map);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        if (process_map(stdin) == -1)
            fprintf(stderr, "map error\n");
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        FILE *f = fopen(argv[i], "r");
        if (!f)
            fprintf(stderr, "map error\n");
        else
        {
            if (process_map(f) == -1)
                fprintf(stderr, "map error\n");
            fclose(f);
        }
        if (i < argc - 1)
            fprintf(stdout, "\n");
    }
    return 0;
}