/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:09:22 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 17:15:46 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h> /* remove when finished */
# include "../libft/libft.h"
# define FLAGS "#0- +'"
# define CONVERSORS "sSpdDioOuUxXcC"
# define FLAGS_N 6
# define LENGTHM_N 7
# define CONV_N 14

typedef struct fstr_s
{
	int					argorder;
	char				*argordervalue;
	char				*argordermixed;
	int					flags[FLAGS_N];
	//int					flgs_sharp;
	//int					flg_zero;
	//int					flg_neg;
	//int 					flg_space;
	//int					flg_plus;
	//int					flg_apos;
	int					separator; /* only 4 testing purposes */
	int					fwidth;
	char				*fwidthvalue;
	int					precision;
	char				*precisionvalue;
	int					lengthmdf[LENGTHM_N];
	//int					lm_hh;
	//int					lm_h;
	//int					lm_ll;
	//int					lm_l;
	//int					lm_j;
	//int					lm_t;
	//int					lm_z;
	char				convesp;
}						fstr_t;
void ft_printf(const char *str, ...);
void sconv(va_list ap);
void argorder(void);
int	checkstr(const char *str, fstr_t *ptrfstring, va_list ap);
int	checkstr_argorder(const char *str, fstr_t *ptrfstring);
int	checkstr_flags(const char *str, fstr_t *ptrfstring);
int checkstr_fwidth(const char *str, fstr_t *ptrfstring);
int checkstr_precision(const char *str, fstr_t *ptrfstring);
int checkstr_length_hh(const char *str, fstr_t *ptrfstring);
int checkstr_length_h(const char *str, fstr_t *ptrfstring);
int checkstr_length_ll(const char *str, fstr_t *ptrfstring);
int checkstr_length_l(const char *str, fstr_t *ptrfstring);
int checkstr_length_j(const char *str, fstr_t *ptrfstring);
int checkstr_length_t(const char *str, fstr_t *ptrfstring);
int checkstr_length_z(const char *str, fstr_t *ptrfstring);
int conversion_specifiers(const char *str, fstr_t *ptrfstring);
void initialize_struct(fstr_t *ptrfstring);
void print_initialize(fstr_t *ptrfstring);
//int main(void);
#endif
