#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int space = 0;
		while (is_space(argv[1][i]))
			i++;
		while (argv[1][i])
		{
			if (is_space(argv[1][i]))
				space = 1;
			else
			{
				if (space)
					ft_putchar(' ');
				space = 0;
				ft_putchar(argv[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
