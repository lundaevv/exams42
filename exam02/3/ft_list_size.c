#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int i = 0;

	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

#include <stdio.h>
int main(void)
{
    t_list *empty = NULL;
    printf("Empty list size = %d\n", ft_list_size(empty));

    t_list node1;
    node1.data = "first";
    node1.next = NULL;
    printf("One node list size = %d\n", ft_list_size(&node1));

    t_list node2, node3;

    node1.data = "first";
    node1.next = &node2;

    node2.data = "second";
    node2.next = &node3;

    node3.data = "third";
    node3.next = NULL;

    printf("Three node list size = %d\n", ft_list_size(&node1));

    return 0;
}
