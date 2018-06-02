#include "includes/ft_printf.h"

int check_exist(t_fstr *pfs, char *tmp)
{
	int			tmpvalue;
	t_args		*cpyptrlargs;

	tmpvalue = ft_atoi(tmp);
	if (!pfs->ptrlargs)
	{
		pfs->ptrlargs = (t_args *)malloc(sizeof(t_args));
		pfs->ptrlargs->value = tmpvalue;
		pfs->ptrlargs->conv = '\0';
		pfs->ptrlargs->mdf = NULL;
	while (pfs->ptrlargs)
	{
		if (pfs->ptrlargs->value == 0)
			pfs->ptrlargs->value = tmpvalue;
		else
		{
			if (!(pfs->ptrlargs->next))
				pfs->ptrlargs->next = (t_args *)malloc(sizeof(t_args))


int		argorder_store(const char *str, t_fstr *pfs, int auxshift)
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
		check_exist(pfs, tmp);
		ptrlargs->value = ft_atoi(tmp);
