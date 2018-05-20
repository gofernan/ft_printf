/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:09:22 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 19:53:02 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <fcntl.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <sys/types.h>
# include <errno.h>// remove???
# include <stdio.h>// remove when finished
# include "../libft/libft.h"
# define CONVERSORS "sSpdDioOuUxXcC"
# define FLAGS "#0- +\'"
# define FLAGS_N 6
# define LENGTHM_N 8
# define CONV_N 14
# define BUFF_SIZE 1000

typedef struct		s_args
{
	int				value;
	char			convesp;
	int				mdf;
	struct s_args	*next;
}					t_args;

typedef struct		fstr_s
{
	int				argorderstr;
	int				argorder;
	int				argordervalue;
	char			*argordermixed;
	int				flags[FLAGS_N];
	int				separator; /* only 4 testing purposes */
	int				fwidth;
	int				fwidthvalue;
	int				precision;
	int				precisionvalue;
	int				lengthmdf[LENGTHM_N];
	char			convesp;
	int				counter;
	int				converted;
	char			buff[BUFF_SIZE];
	//char			*buff;
	//int			buffsize;
	int				buffi;
	int				lnchars;
	t_args			*ptrlargs;
	int				precheck;
}					fstr_t;

int			ft_printf(const char *str, ...);
void		sconv(va_list ap, fstr_t *ptrfstring);
//void		argorder(void);
void		checkstr(const char *str, fstr_t *ptrfstring, va_list ap);
int			checkstr_argorder(const char *str, fstr_t *ptrfstring, int *auxshift);
int			checkstr_flags(const char *str, fstr_t *ptrfstring);
int			checkstr_fwidth(const char *str, fstr_t *ptrfstring, int *auxshift);
int			checkstr_precision(const char *str, fstr_t *ptrfstring, int *auxshift);
int			checkstr_length_hh(const char *str, fstr_t *ptrfstring);
int			checkstr_length_h(const char *str, fstr_t *ptrfstring);
int			checkstr_length_ll(const char *str, fstr_t *ptrfstring);
int			checkstr_length_l(const char *str, fstr_t *ptrfstring);
int			checkstr_length_j(const char *str, fstr_t *ptrfstring);
int			checkstr_length_t(const char *str, fstr_t *ptrfstring);
int			checkstr_length_z(const char *str, fstr_t *ptrfstring);
int			checkstr_length_q(const char *str, fstr_t *ptrfstring);
int			conversion_specifiers(const char *str, fstr_t *ptrfstring);
char		*field_width(char *str, int *len, fstr_t *ptrfstring);
char		*field_width_num(char *str, int *len, fstr_t *ptrfstring);
void		initialize_struct(fstr_t *ptrfstring);
char		*precisionf(char *str, int *len, fstr_t *ptrfstring);
void		lsconv(va_list ap, fstr_t *ptrfstring);
char		*utf8conv(unsigned int *wstr);
char		*onebyteconv(wchar_t *wstr, fstr_t *ptrfstring);
char		*precisionfw(char *str, int *len, fstr_t *ptrfstring);
void		diconv(va_list ap, fstr_t *ptrfstring);
char		*precisiondigits(char *str, int *len, int plusp, fstr_t *ptrfstring);
char		*flag_space(char *str, int *len, fstr_t *ptrfstring);
char		*flag_plus(char *str, int *len, fstr_t *ptrfstring);
char		*flag_sharp(char *str, int *len, fstr_t *ptrfstring);
void		uconv(va_list ap, fstr_t *ptrfstring);
void		oconv(va_list ap, fstr_t *ptrfstring);
void		xconv(va_list ap, fstr_t *ptrfstring);
void		cconv(va_list ap, fstr_t *ptrfstring);
void		lcconv(va_list ap, fstr_t *ptrfstring);
void		percent(char a, fstr_t *ptrfstring);
void		pconv(va_list ap, fstr_t *ptrfstring);
void		store_write(fstr_t *ptrfstring, const char *s, int *len);
void        checkstr_allargs(const char *str, fstr_t *ptrfstring, va_list ap);
void        store_arglist(fstr_t *ptrfstring);
int         checkstr_inside(const char *str, fstr_t *ptrfstring, va_list ap, int *i);
#endif
