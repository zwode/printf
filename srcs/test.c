#include <stdio.h>
#include "../include/ft_printf.h"

int		main(void)
{
	printf("Or printf :%100d\n", 13534543321213);
	ft_printf("My printf :%100.d\n", 13534543321213);
	return(0);
}
