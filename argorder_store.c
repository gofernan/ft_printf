#include "includes/ft_printf.h"

int check_exist(fstr_t *ptrfstring, char *tmp)
{
	int			tmpvalue;
	t_args		*cpyptrlargs;

	tmpvalue = ft_atoi(tmp);
	if (!ptrfstring->ptrlargs)
	{
		ptrfstring->ptrlargs = (t_args *)malloc(sizeof(t_args));
		ptrfstring->ptrlargs->value = tmpvalue;
		ptrfstring->ptrlargs->convesp = '\0';
		ptrfstring->ptrlargs->mdf = NULL;
	while (ptrfstring->ptrlargs)
	{
		if (ptrfstring->ptrlargs->value == 0)
			ptrfstring->ptrlargs->value = tmpvalue;
		else
		{
			if (!(ptrfstring->ptrlargs->next))
				ptrfstring->ptrlargs->next = (t_args *)malloc(sizeof(t_args))


int		argorder_store(const char *str, fstr_t *ptrfstring, int auxshift)
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
		check_exist(ptrfstring, tmp);
		ptrlargs->value = ft_atoi(tmp);
