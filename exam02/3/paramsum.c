#include <unistd.h>

void ft_putnbr(int input)
{
	if (input >= 10)
		ft_putnbr(input / 10);
	char c = input % 10 + '0';
	write (1, &c, 1);
}

int main(int argc, char **argv)
{
	ft_putnbr(argc - 1);
	write (1, "\n", 1);
	return (0);
}
