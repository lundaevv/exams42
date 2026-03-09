#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res = res + str[i] - '0';
		i++;
	}
	return (res);
}

void puthex(int nbr)
{
	char *digits = "0123456789abcdef";

	if (nbr >= 16)
		puthex (nbr / 16);
	write(1, &digits[nbr % 16], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int num = ft_atoi(argv[1]);
		puthex(num);
	}
	write(1, "\n", 1);
	return (0);
}
