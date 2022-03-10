/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:49:40 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/11 00:14:48 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move_up(float move, t_range *range)
{
	range->immax += move;
}

void	move_down(float move, t_range *range)
{
	range->immax -= move;
}

void	move_left(float move, t_range *range)
{
	range->remin -= move;
	range->remax -= move;
}

void	move_right(float move, t_range *range)
{
	range->remin += move;
	range->remax += move;
}
