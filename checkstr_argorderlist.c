#include "includes/ft_printf.h"

int			check_str_argorderlist(const char *str, t_args *ptrargs, int *auxshift)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] == '$' && i > 0)
	{
		if (!(tmp = malloc(sizeof(char) * (i + 1))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str, i);
		tmp[i] = '\0';
		*auxshift = i;
		ptrargs->value = ft_atoi(tmp);
		
