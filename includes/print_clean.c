void		print_clean(fstr_t *ptrfstring)
{
	int i;

	i = 0;

	ptrfstring->counter = write(1, ptrfstring->buff, ptrfstring->buffi + 1);
	while (i < BUFF_SIZE)
	{
		ptrfstring->buff[i++] = '\0';
	}
	ptrfstring->buffi = 0;
}
