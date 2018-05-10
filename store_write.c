#include "includes/ft_printf.h"

void		store_write(fstr_t *ptrfstring, const char *s, int *len)
{
	int i;

	i = 0;
	if (((ptrfstring->buffi) + *len) < BUFF_SIZE)
	{
		ft_strncpynp(&ptrfstring->buff[ptrfstring->buffi], s, *len);
		ptrfstring->buffi += *len;
	}
	else if (ptrfstring->buffi)
	{
		ptrfstring->counter += write(1, ptrfstring->buff, ptrfstring->buffi);
		while (i < ptrfstring->buffi)
			ptrfstring->buff[i++] = '\0';
		ptrfstring->buffi = 0;
		ft_strncpy(ptrfstring->buff, s, *len);
		ptrfstring->buffi = *len;
	}
	else
		ft_putstr("NO ENTRA");
}
