#include <stdlib.h>

int *ft_range(int start, int end)
{
	int len;
	int i = 0;
	int *range;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;

	range = (int *)malloc(sizeof(int) * len);
	if (!range)
		return (NULL);

	while (i < len)
	{
		if (start < end)
			range[i++] = start++;
		else
			range[i++] = start--;
	}
	return (range);
}

#include <stdio.h>
int main(void)
{
	int *arr;

	arr = ft_range(1, -1);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    free(arr);
    return 0;
}
	
