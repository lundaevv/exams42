#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	unsigned int number;

	if (nbr < 0)
	{
		ft_putchar('-');
		number = -nbr;
	}
	else
		number = nbr;
	if (nbr >=10)
		ft_putnbr(number / 10);
	ft_putchar(number % 10 + '0');
}

int is_prime(int nbr)
{
	if (nbr < 2)
		return (0);
	int i = 2;
	while (i <= nbr / 2)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int ft_atoi (char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if  (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}

int main(int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	int n = ft_atoi(argv[1]);
	int sum = 0;
	while (n > 1)
	{
		if (is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	ft_putchar('\n');
}
