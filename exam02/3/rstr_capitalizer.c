#include <unistd.h>

int ft_isspace(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void r_capitalizer(char *s)
{
	int i = 0;
	while(s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if (s[i] >= 'a' && s[i] <= 'z' && ft_isspace(s[i+1]))
			s[i] -=32;
		ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc == 1)
		ft_putchar('\n');
	else
	{
		while (i < argc)
		{
			r_capitalizer(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
