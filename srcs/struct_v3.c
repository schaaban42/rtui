/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:09:35 by schaaban          #+#    #+#             */
/*   Updated: 2018/12/11 14:31:29 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

void				v3_set(t_v3 *v, double new_x, double new_y, double new_z)
{
	v->x = new_x;
	v->y = new_y;
	v->z = new_z;
}

void				v3_reset(t_v3 *v)
{
	v->x = 0.0;
	v->y = 0.0;
	v->z = 0.0;
}

t_v3				v3_cpy(t_v3 v)
{
	return ((t_v3)
	{
		v.x,
		v.y,
		v.z
	});
}

int					v3_cmp(t_v3 v1, t_v3 v2)
{
	if (v1.x == v2.x
		&& v1.y == v2.y
		&& v1.z == v2.z)
		return (1);
	return (0);
}

void				v3_print(t_v3 v, int block)
{
	if (block)
	{
		printf("X : %f\nY : %f\nZ : %f\n", v.x, v.y, v.z);
	}
	else
	{
		printf("X : %f Y : %f Z : %f\n", v.x, v.y, v.z);
	}
}

t_v3				v3_sum(t_v3 v1, t_v3 v2)
{
	return ((t_v3)
	{
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	});
}

t_v3				v3_sub(t_v3 v1, t_v3 v2)
{
	return ((t_v3)
	{
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	});
}

double				v3_norm(t_v3 v)
{
	return (sqrt(
		(v.x * v.x)
		+ (v.y * v.y)
		+ (v.z * v.z)));
}

t_v3				v3_mul(t_v3 v, double value)
{
	return ((t_v3)
	{
		v.x * value,
		v.y * value,
		v.z * value
	});
}

t_v3				v3_div(t_v3 v, double value)
{
	return ((t_v3)
	{
		v.x / value,
		v.y / value,
		v.z / value
	});
}

t_v3				v3_normalized(t_v3 v)
{
	return (v3_div(v, v3_norm(v)));
}

double				v3_dist(t_v3 v1, t_v3 v2)
{
	return (v3_norm(v3_sub(v2, v1)));
}

t_v3				v3_rot_x(t_v3 v, double a)
{
	a = to_rad(a);
	return ((t_v3)
	{
		v.x,
		(v.y * cos(a)) + (v.z * -sin(a)),
		(v.y * sin(a)) + (v.z * cos(a))
	});
}

t_v3				v3_rot_y(t_v3 v, double a)
{
	a = to_rad(a);
	return ((t_v3)
	{
		(v.x * cos(a)) + (v.z * sin(a)),
		v.y,
		(v.z * cos(a)) + (v.x * -sin(a))
	});
}

t_v3				v3_rot_z(t_v3 v, double a)
{
	a = to_rad(a);
	return ((t_v3)
	{
		(v.x * cos(a)) - (v.y * sin(a)),
		(v.x * sin(a)) + (v.y * cos(a)),
		v.z
	});
}

t_v3				v3_rot(t_v3 v, double ax, double ay, double az)
{
	return (v3_rot_x(v3_rot_y(v3_rot_z(v, az), ay), ax));
}

double				v3_ang(t_v3 v1, t_v3 v2)
{
	double		cosa;

	v1 = v3_normalized(v1);
	v2 = v3_normalized(v2);
	cosa = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	return (cosa);
}
