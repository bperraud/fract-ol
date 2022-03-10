/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:36:44 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/01 20:36:44 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex add(t_complex c1, t_complex c2)
{
	t_complex c;
	c.imag = c1.imag + c2.imag;
	c.real = c1.real + c2.real;
	return (c);
}

t_complex mult(t_complex c1, t_complex c2)
{
	t_complex c;
	c.real = c1.real * c2.real - c1.imag * c2.imag;
	c.imag = c1.imag * c2.real + c1.real * c2.imag;
	return (c);
}

t_complex absolute(t_complex c)
{
	c.imag = fabs(c.imag);
	c.real = fabs(c.real);
	return (c);
}

float module(t_complex c)
{
	return (sqrt(c.real * c.real + c.imag * c.imag));
}

