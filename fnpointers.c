/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnpointers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:11:16 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/15 18:32:55 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_prinft.h"

void		fnpointers(void)
{
	convstr[0] = nextargument;
	convstr[1] = alternateform;
	convstr[2] = zeropadding;
	convstr[3] = leftadjusted;
	convstr[4] = space;
	convstr[5] = plus;
	convstr[6] = apostrophe;
	convstr[7] = separator; // not used
	convstr[8] = fieldwidth;
	convstr[9] = lenghtmodifier;
	convstr[10] = conversiontype;
}
