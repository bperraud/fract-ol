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
	c.imag = c1.imag * c2.real + c1.real * c2.imag;;
	return (c);
}
