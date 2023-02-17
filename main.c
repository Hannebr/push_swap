#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;



t_list	*ft_newlst(int number)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		exit(0);
	new->number = number;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*tail;
	
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tail = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	new->prev = tail;
	tail->next = new;
}


int main(int argc, char **argv)
{
	int 	i;
	int 	num;
	t_list	**head;
	t_list	*new;
	t_list	*check;

	i = 1;
	head = (t_list **) malloc(sizeof(t_list *));
	if (!head)
		return (NULL);
	*head = NULL;
	while (i < argc)
	{
		num = atoi(argv[i]);
		new = ft_newlst(num);
		ft_lstadd_back(head, new);
		i++;
	}
	check = *head;
	while (i > 1)
	{
		printf("%i\n", check->number);
		check = check->next;
		i--;
	}
}
