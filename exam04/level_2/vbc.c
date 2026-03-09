#include <stdio.h>
#include <stdlib.h> // changed: use stdlib.h for calloc/free instead of malloc.h
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n)); // changed: allocation line differs from given_code.c
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}
node	*parse_addition(char **s); // added: forward declaration
node	*parse_multiplication(char **s); // added: forward declaration
node	*parse_primary(char **s); // added: forward declaration

node	*parse_addition(char **s) // added: parse expressions with '+'
{
	node *left;
	node *right;
	node tmp;

	left = parse_multiplication(s);
	if (!left)
		return (NULL);
	while (**s == '+')
	{
		(*s)++;
		right = parse_multiplication(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		tmp.type = ADD;
		tmp.l = left;
		tmp.r = right;
		tmp.val = 0;
		left = new_node(tmp);
		if (!left)
		{
			destroy_tree(right);
			return (NULL);
		}
	}
	return (left);
}
node	*parse_multiplication(char **s) // added: parse expressions with '*'
{
	node *left;
	node *right;
	node tmp;

	left = parse_primary(s);
	if (!left)
		return (NULL);
	while (**s == '*')
	{
		(*s)++;
		right = parse_primary(s);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		tmp.type = MULTI;
		tmp.l = left;
		tmp.r = right;
		tmp.val = 0;
		left = new_node(tmp);
		if (!left)
		{
			destroy_tree(right);
			return (NULL);
		}
	}
	return (left);
}
node	*parse_primary(char **s) // added: parse a digit or parenthesized expression
{
	node tmp;
	node *res;

	if (**s == '(')
	{
		(*s)++;
		res = parse_addition(s);
		if (!res || **s != ')')
		{
			destroy_tree(res);
			unexpected(**s);
			return (NULL);
		}
		(*s)++;
		return (res);
	}
	if (isdigit((unsigned char)**s))
	{
		tmp.type = VAL;
		tmp.l = NULL;
		tmp.r = NULL;
		tmp.val = **s - '0';
		res = new_node(tmp);
		if (!res)
			return (NULL);
		(*s)++;
		return (res);
	}
	unexpected(**s);
	return (NULL);
}

node    *parse_expr(char *s)
{
    node *ret; // changed: actual parser result variable added in place of template stub

    ret = parse_addition(&s); // changed: start real parsing from the top-level grammar rule
    if (!ret)
	return (NULL); // changed: handle parse failure from added parser
    if (*s) 
    {
        destroy_tree(ret);
		unexpected(*s); // changed: report trailing unexpected token
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
    return (0); // changed: suppress missing-return warning for completeness
}


int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
	return (0); // changed: suppress missing-return warning for completeness
}
