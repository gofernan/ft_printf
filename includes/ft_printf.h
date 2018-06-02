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
# define CONVERSORS "sSpdDioOuUxXcCfFb"
# define FLAGS "#0- +\'"
# define FLAGS_N 6
# define LENGTHM_N 8
# define CONV_N 17
# define BUFF_SIZE 1000

typedef struct		s_args
{
	int				value;
	char			conv;
	int				mdf;
	int				validlen;
	char			*str;
	struct s_args	*next;
}					t_args;

typedef struct		s_fstr
{
	//int				argorderstr;
	int				argo;
	int				argov;
	int				flags[FLAGS_N];
	int				fwidth;
	int				fwidth_as;
	int				fwidth_asarg;
	int				fwidth_asargv;
	int				fwidthvalue;
	int				prec;
	int				prec_as;
	int				prec_asarg;
	int				prec_asargv;
	int				precvalue;
	int				lengthmdf[LENGTHM_N];
	char			conv;
	int				counter;
	int				converted;
	char			buff[BUFF_SIZE];
	//char			*buff;
	//int			buffsize;
	int				buffi;
	int				lnchars;
	t_args			*ptrlargs;
	int				precheck;
}					t_fstr;

int			ft_printf(const char *str, ...);
void		sconv(va_list ap, t_fstr *pfs);
//void		argo(void);
void		checkstr(const char *str, t_fstr *pfs, va_list ap);
int			checkstr_argorder(const char *str, t_fstr *pfs, int *auxshift);
int			checkstr_flags(const char *str, t_fstr *pfs);
int			checkstr_fwidth(const char *str, t_fstr *pfs, int *auxshift);
int			checkstr_prec(const char *str, t_fstr *pfs, int *auxshift);
int			checkstr_length_hh(const char *str, t_fstr *pfs);
int			checkstr_length_h(const char *str, t_fstr *pfs);
int			checkstr_length_ll(const char *str, t_fstr *pfs);
int			checkstr_length_l(const char *str, t_fstr *pfs);
int			checkstr_length_j(const char *str, t_fstr *pfs);
int			checkstr_length_t(const char *str, t_fstr *pfs);
int			checkstr_length_z(const char *str, t_fstr *pfs);
int			checkstr_length_q(const char *str, t_fstr *pfs);
int			convsp(const char *str, t_fstr *pfs);
char		*field_width(char *str, int *len, t_fstr *pfs);
char		*field_width_num(char *str, int *len, t_fstr *pfs);
void		initialize_struct(t_fstr *pfs);
char		*precf(char *str, int *len, t_fstr *pfs);
void		lsconv(va_list ap, t_fstr *pfs);
char		*utf8conv(unsigned int *wstr);
char		*onebyteconv(wchar_t *wstr, t_args *tmpargsl);
char		*precfw(char *str, int *len, t_fstr *pfs);
void		diconv(va_list ap, t_fstr *pfs);
char		*precdigits(char *str, int *len, int plusp, t_fstr *pfs);
char		*flag_space(char *str, int *len, t_fstr *pfs);
char		*flag_plus(char *str, int *len, t_fstr *pfs);
char		*flag_sharp(char *str, int *len, t_fstr *pfs);
void		uconv(va_list ap, t_fstr *pfs);
void		oconv(va_list ap, t_fstr *pfs);
void		xconv(va_list ap, t_fstr *pfs);
void		cconv(va_list ap, t_fstr *pfs);
void		lcconv(va_list ap, t_fstr *pfs);
void		percent(char a, t_fstr *pfs);
void		pconv(va_list ap, t_fstr *pfs);
void		fconv(va_list ap, t_fstr *pfs);
void		bconv(va_list ap, t_fstr *pfs);
void		store_write(t_fstr *pfs, const char *s, int *len);
void        checkstr_allargs(const char *str, t_fstr *pfs, va_list ap);
void        store_arglist(t_fstr *pfs);
int         checkstr_inside(const char *str, t_fstr *pfs, va_list ap, int *i);
void        retr_arglist(va_list ap, t_fstr *pfs);
t_args		*sel_arglist(t_fstr *pfs);
char		*check_locale_lsconv(va_list ap, t_args *tmpargsl);
char		*check_locale_lcconv(va_list ap, t_args *tmpargsl);
char		*cconva(va_list ap, t_fstr *pfs);
char		*xmdfs(va_list ap, t_args *tmpargsl);
char		*omdfs(va_list ap, t_args *tmpargsl);
char		*umdfs(va_list ap, t_args *tmpargsl);
char		*dimdfs(va_list ap, t_args *tmpargsl);
char		*ft_ftoa(va_list ap);
void		free_struct(t_fstr *pfs);
#endif
