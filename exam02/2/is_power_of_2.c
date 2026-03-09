int	    is_power_of_2(unsigned int n)
{
	int test = 1;

	while (test <= n)
	{
		if (test == n)
			return (1);
		test *= 2;
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i = atoi(argv[1]);

	printf("%d\n", is_power_of_2(i));
	return (0);
}
