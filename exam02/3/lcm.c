unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int x = 1;

	if ((a == 0) || (b == 0))
		return (0);

	while (1)
	{
		if((x % a == 0) && (x % b == 0))
			return (x);
		x++;
	}
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int n = lcm(atoi(argv[1]), atoi(argv[2]));
		printf("%d\n", n);
	}
	return (0);
}
