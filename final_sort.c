/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:28:35 by ctardy            #+#    #+#             */
/*   Updated: 2022/06/06 17:11:27 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void all_in_b(t_prog *prog)
{
	t_list *stack_a;

	stack_a = prog->stack_a;
	while (stack_a && stack_a->stay != 1)
	{
		push_b(&prog->stack_a, &prog->stack_b);
		stack_a = stack_a->next;	
	}
	printf("valeur de size %d\n", prog->size);
	sort_triple(prog);
	print_list(prog);
}


// int distance_in_list(int tag, int size)
// {
// 	if (tag >= size / 2)
// 		tag -= size;
// 	return (tag);
// }

// void calcul_rotation(t_prog *prog, int max, int *rot_a, int *rot_b)
// {
// 	int distance;
// 	int place;
// 	int true_distance;
// 	int i;
	
// 	i = 0;
// 	prog->inter = prog->stack_b;
// 	while (prog->inter)
// 	{
// 		printf("\n--- distance_b %d\n" ,distance = distance_in_list(i++, (prog->total - prog->size)));	
// 		printf("*** insert %d\n", place = where_place(prog->stack_a, prog->inter->index, prog->size));
// 		printf("xxx dist_total %d\n\n", true_distance = nega(place) + nega(distance));
// 		if (place > 0 && distance > 0)
// 			true_distance -= compare_little(distance, place);
// 		if (place < 0 && distance < 0)
// 			true_distance += compare_big(distance, place);
// 		if (true_distance < max)
// 		{
// 			max = true_distance;
// 			*rot_a = place;
// 			*rot_b = distance;
// 	//		printf("pk ? %d\n", *rot_a);
//  		}
// 		prog->inter = prog->inter->next;
// 	//	printf("tour %d\n", j++);
// 	}	
// }

void double_rotate(t_prog *prog, int *rot_a, int *rot_b)
{
		while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_a)--;
		(*rot_b)--;
		rotate_both(prog, *rot_a, *rot_b);
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		(*rot_a)++;
		(*rot_b)++;
		reverse_rotate_both(prog, *rot_a, *rot_b);
	}
}

void keep_rotating (t_prog *prog, int rot_a, int rot_b)
{
	double_rotate(prog, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		rotate_a(&prog->stack_a);
	}
	while (rot_a < 0)
	{
		rot_a++;
		reverse_rotate_a(&prog->stack_a);
	}
	while (rot_b > 0)
	{
		rot_b--;
		rotate_b(&prog->stack_a);
	}
	while (rot_b < 0)
	{
		rot_b++;
		reverse_rotate_b(&prog->stack_a);
	}
}

// void *closest_in_chunk(t_prog *prog, int cur_group)
// {
// 	t_list *inter;
// 	t_list *closest;
// 	int max;
// 	int distance;
	
// 	max = INT_MAX;
// 	closest = NULL;
// 	inter = prog->stack_b;
// 	while (inter)
// 	{
// 		if (inter->index <= cur_group * prog->group_size)
// 			{
// 				distance = distance_to_top(prog, inter->index);
// 				if (nega(distance) < (nega(max)))
// 				{
// 					max = distance;
// 					closest = inter;
// 					if (max == 0)
// 						break;
// 				}
// 		}
// 		inter = inter->next;
// 	}
// 	return (closest);
// }

// int swap_tester(t_list *stack)
// {
// 	t_list inter;
// 	t_list inter2;
// 	int swap;
// 	int swap2;
	
// 	inter.next = &inter2;
// 	inter.index = stack->next->index;
// 	inter2.next = stack->next->next;
// 	inter2.index = stack->index;  
// 	swap = find_biggest_asc_order(stack, 0);
// 	swap2 = find_biggest_asc_order(&inter, 0);
// 	if (swap2 > swap)
// 		return (1);
// 	return (0);	
// }

// void set_up_before_sort(t_prog *prog)
// {
// 	int cur_group;
// 	int distance;
// 	int j = 0;

// 	cur_group = 1;
// 	while (prog->size >= prog->strike && cur_group <= (prog->group_count + 1))
// 	{
// 		printf("--------------- tour de j = %d\n", j);
// 		j++;
// 		prog->inter = closest_in_chunk(prog, cur_group);
// 		if (prog->inter == NULL && ++cur_group)
// 			continue ;
// 		distance = distance_to_top(prog, prog->inter->index);
// 		if (prog->stack_a && swap_tester(prog->stack_a))
// 		{
// 			swap_a(&prog->stack_a);
// 			prog->strike = find_biggest_asc_order(prog->stack_a, 1);
// 		}
// 		else if (prog->stack_a && !prog->stack_a->stay && distance == 0)
// 		{
// 			push_b(&prog->stack_a, &prog->stack_b);
// 			prog->size--;
// 		}
// 		else if (prog->group_count == 1)
// 			rotate_both(prog, 0, 0);
// 		else
// 			keep_rotating(prog, compare_little(1, compare_big(-1, distance)), 0);
// 	}
// 	write (1, "yo\n", 2);
// 	print_list(prog);
// }

// void final_sort(t_prog *prog)
// {
// 	int rot_a;
// 	int rot_b;
 //	set_up_before_sort(prog);
// //	all_in_b(prog);
// 	printf("caca\n");
// 	while (prog->stack_b)
// 	{
// 		calcul_rotation(prog, INT_MAX, &rot_a, &rot_b);
// 		keep_rotating(prog, rot_a, rot_b);
// 		push_a(&prog->stack_a, &prog->stack_b);
// 		prog->size++;
// 		print_list(prog);
// 	}
// //	printf("ici ca deconne avec rot_a %d\n", rot_a);
// 	keep_rotating(prog, distance_to_top(prog, 0), 0);
// }

// int	where_place(t_list *list, int t, int size)
// {
// 	t_list	*prec;
// 	t_list	*current;
// 	int		current_max[2];
// 	int		i;

// 	i = 0;
// 	prec = get_last(list);
// 	current = list;
// 	current_max[1] = INT_MAX;
// 	printf("index de c %d\n", current->index);
// 	printf("index de p %d\n", prec->index);
// 	while (current)
// 	{
// 		if ((prec->index > current->index && (t < current->index || t > prec->index))
// 			|| (t > prec->index && t < current->index))
// 		{
// 			current_max[0] = i;
// 			if (current_max[0] > size / 2)
// 				current_max[0] -= size;
// 			if (nega(current_max[0]) < current_max[1])
// 				current_max[1] = current_max[0];
// //			printf("Je rentre, current_max[1] %d\n", current_max[1]);
// 		}
// 		printf("Valeur de la place ou il doit aller %d\n", current_max[1]);
// 		prec = current;
// 		current = current->next;
// 		i++;
// 	}
// 	return (current_max[1]);
// }

int calcul_rotation(t_list *stack_a, t_list *stack_b, t_list *inter)
{
	int place;
	int place_max;
	int i;
	t_list *pre;
	t_list *cur;
	
	pre = get_last(stack_a);
	cur = stack_a;
	i = 0;
	place_max = INT_MAX;
	while (stack_b)
	{
		if ((!cur && inter->index > pre->index) || (inter->index > pre->index && inter->index < cur->index))
			place = i;
		i++;
		stack_b = stack_b->next;		
	}
	return (place);
}

void final_sort(t_prog *prog)
{
	t_list *stack_b;
//	int rot_a;
//	int rot_b;
	int i;

	i = 0;
	
	stack_b = prog->stack_b;
	all_in_b(prog);
	while (stack_b)
	{
		stack_b->rot_a = calcul_rotation(prog->stack_a, prog->stack_b, stack_b);
		stack_b->rot_b = i++;
		stack_b = stack_b->next;
	}
}