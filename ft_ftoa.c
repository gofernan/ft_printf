#include "includes/ft_printf.h"

char		*ft_ftoa(va_list ap)
{
	intmax_t	intpart;
	intmax_t	floatpart;
	int			len;
	char		*tmp;
	char		*tmp2;
	double		n;

	n = va_arg(ap, double);
	intpart = (intmax_t)n;
	floatpart = (n - (float)intpart) * 1000000000000000000;
	if (!(tmp = ft_imaxtoa(intpart)))
		exit(EXIT_FAILURE);
	len = ft_strlen(tmp);
	if (!(tmp2 = ft_memalloc(sizeof(char) * (len + 20))))
		exit(EXIT_FAILURE);
	ft_strncpy(tmp2, tmp, len);
	tmp2[len] = '.';
	ft_strdel(&tmp);
	if (!(tmp = ft_imaxtoa(floatpart)))
		exit(EXIT_FAILURE);
	ft_strcpy(tmp2 + len + 1, tmp);
	ft_strdel(&tmp);
	return (tmp2);
}
