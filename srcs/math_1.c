/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:11:20 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/11 17:14:03 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

double				to_rad(double degrees)
{
	return (degrees * RT_PI / 180.0);
}

double				to_deg(double radians)
{
	return (radians * 180.0 / RT_PI);
}
