/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:47:18 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/04 10:30:21 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_order_b_in_a(t_init *ps, t_target target_data)
// {
// 	//ft_printf("sentido A = %d ------------------sentido B = %d", target_data.a_direction, target_data.b_direction);

// 	if (target_data.a_direction == target_data.b_direction)
// 	{
// 		ft_rrr_rr(ps, target_data);
// 	}
// 	while (ps->stack_b->value != target_data.b_value)
// 	{
// 		if (target_data.b_direction == -1)
// 			ft_rotate_b(ps, 0);
// 		else if (target_data.b_direction == 1)
// 			ft_reverse_rotate_b(ps, 0);
// 	}
// 	while (ps->stack_a->value != target_data.a_value)
// 	{
// 		if (target_data.a_direction == -1)
// 			ft_rotate_a(ps, 0);
// 		else if (target_data.a_direction == 1)
// 			ft_reverse_rotate_a(ps, 0);
// 	}
// 	ft_push_a(ps);
// }

// void	ft_set_targets(t_helper *vars, t_target *dados, t_init *ps)
// {
// 	if (vars->stack_a + vars->stack_b < vars->best_target_b)
// 	{
// 		vars->best_target_b = vars->stack_a + vars->stack_b;
// 		dados->a_value = vars->value;
// 		dados->a_direction = vars->a_direction;
// 		dados->b_value = vars->arg;
// 		dados->b_direction = vars->b_direction;
// 	}
// 	if (ft_case_rrr_or_rr(vars->arg, ps, 1) < vars->best_target_b)
// 	{
// 		vars->best_target_b = ft_case_rrr_or_rr(vars->arg, ps, 1);
// 		dados->a_value = vars->value;
// 		dados->a_direction = 1;
// 		dados->b_value = vars->arg;
// 		dados->b_direction = 1;
// 	}
// 	if (ft_case_rrr_or_rr(vars->arg, ps, -1) < vars->best_target_b)
// 	{
// 		vars->best_target_b = ft_case_rrr_or_rr(vars->arg, ps, -1);
// 		dados->a_value = vars->value;
// 		dados->a_direction = -1;
// 		dados->b_value = vars->arg;
// 		dados->b_direction = -1;
// 	}
// }

// void	ft_rrr_rr(t_init *ps, t_target data_target)
// {
// 	while (((ps->stack_b->value != data_target.b_value)
// 			&& (ps->stack_a->value != data_target.a_value)))
// 	{
// 		if (data_target.b_direction == -1)
// 			ft_rotate_rotate(ps);
// 		else
// 			ft_reverse_rotate_rotate(ps);
// 	}
// }

// int	ft_case_rrr_or_rr(int value, t_init *ps, int direction)
// {
// 	int	target;
// 	int	n_opt;

// 	if (direction == -1)
// 	{
// 		target = ft_get_best_option(ps->stack_a, value);
// 		n_opt = ft_get_index(ps->stack_b, value);
// 		if (ft_get_index(ps->stack_a, target) > n_opt)
// 			n_opt = ft_get_index(ps->stack_a, target);
// 	}
// 	if (direction == 1)
// 	{
// 		target = ft_get_best_option(ps->stack_a, value);
// 		n_opt = ps->num_values_b - ft_get_index(ps->stack_b, value);
// 		if (ps->num_values_b - ft_get_index(ps->stack_a, target) > n_opt)
// 			n_opt = ps->num_values_a - ft_get_index(ps->stack_a, target);
// 	}
// 	return (n_opt + 1);
// }

t_target	ft_get_best_comb(t_init *ps)
{
	t_list	*current_b;
	t_target best_target;
	int		pos_b;
	int		pos_a;
	int		best_cost;
	int		current_cost;

	pos_b = 0;
	best_cost = INT_MAX;
	current_b = ps->stack_b;
	while (current_b != NULL)
	{
		pos_a = ft_find_best_position_in_a(ps, current_b->value);
		current_cost = ft_calculate_cost(ps, pos_a, pos_b);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_target.a_value = ps->stack_a->value;
			best_target.b_value = current_b->value;
			best_target.a_direction = ft_get_direction(ps->num_values_a, pos_a);
			best_target.b_direction = ft_get_direction(ps->num_values_b, pos_b);
		}
		pos_b++;
		current_b = current_b->next;
	}
	return (best_target);
}


void ft_put_min_top(t_init *ps, t_list *stack, int stack_size)
{
    int min_value = ft_get_min_value(stack);
    int index = ft_get_index(stack, min_value); // A função que retorna o índice do valor mínimo

    // Se o índice estiver na primeira metade da pilha, faça rotações normais.
    if (index <= stack_size / 2)
    {
        while (stack->value != min_value)
            ft_rotate_a(ps, 0); // Faz rotações até o menor valor estar no topo
    }
    // Caso contrário, faça rotações reversas.
    else
    {
        while (stack->value != min_value)
            ft_reverse_rotate_a(ps, 0); // Faz rotações reversas até o menor valor estar no topo
    }
}
void ft_order_b_in_a(t_init *ps, t_target target_data)
{
    // Realiza rotações em stack_a e stack_b de acordo com a melhor combinação
    while (target_data.a_direction == 1 && ps->stack_a->value != target_data.a_value)
        ft_rotate_a(ps, 1); // Roda a pilha A até atingir a posição correta

    while (target_data.b_direction == 1 && ps->stack_b->value != target_data.b_value)
        ft_rotate_b(ps, 1); // Roda a pilha B até atingir a posição correta

    // Depois que as pilhas estão alinhadas, empurra o valor de B para A.
    ft_push_a(ps);
}
int	ft_find_best_position_in_a(t_init *ps, int value_b)
{
	t_list	*current;
	int		pos;
	int		best_pos;
	int		best_diff;
	int		diff;

	current = ps->stack_a;
	pos = 0;
	best_pos = 0;
	best_diff = INT_MAX;
	while (current != NULL)
	{
		diff = current->value - value_b;
		if (diff > 0 && diff < best_diff)
		{
			best_diff = diff;
			best_pos = pos;
		}
		pos++;
		current = current->next;
	}
	// Se não encontrar um lugar melhor, insere no início
	if (best_diff == INT_MAX)
		best_pos = 0;
	return (best_pos);
}
int	ft_calculate_cost(t_init *ps, int pos_a, int pos_b)
{
	int cost_a;
	int cost_b;

	// Custo para mover para a posição correta na pilha A
	if (pos_a <= ps->num_values_a / 2)
		cost_a = pos_a;
	else
		cost_a = ps->num_values_a - pos_a;

	// Custo para mover para a posição correta na pilha B
	if (pos_b <= ps->num_values_b / 2)
		cost_b = pos_b;
	else
		cost_b = ps->num_values_b - pos_b;

	// O custo total é a soma dos custos das duas pilhas
	return (cost_a + cost_b);
}
int	ft_get_direction(int stack_size, int position)
{
	if (position <= stack_size / 2)
		return (0); // Rotacionar para cima
	else
		return (1); // Rotacionar para baixo
}
int ft_get_index(t_list *stack, int value)
{
    int index = 0;
    
    while (stack != NULL)
    {
        if (stack->value == value)
            return index;
        stack = stack->next;
        index++;
    }
    return -1; // Retorna -1 caso o valor não seja encontrado (não deveria acontecer no push_swap)
}
