#include <unistd.h>

int ft_atoi(char *s)
{
	int i = 0;
	int res = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res);
}

void ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	int number = nbr % 10 + '0';
	write (1, &number, 1);
}

void ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 1;
		int n = ft_atoi(argv[1]);

		while (i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(n);
			ft_putstr(" = ");
			ft_putnbr(i * n);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
