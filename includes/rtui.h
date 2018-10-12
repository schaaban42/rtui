/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtui.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:08:07 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/11 20:06:30 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTUI_H
# define RTUI_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <SDL.h>

# define WIDTH		500
# define HEIGHT		500

# define RT_PI		(double)3.14159265359

# if SDL_BYTEORDER == SDL_BIG_ENDIAN
#  define RT_SDL_RMASK			0x00ff0000
#  define RT_SDL_GMASK			0x0000ff00
#  define RT_SDL_BMASK			0x000000ff
#  define RT_SDL_AMASK			0xff000000
# else
#  define RT_SDL_RMASK			0x00ff0000
#  define RT_SDL_GMASK			0x0000ff00
#  define RT_SDL_BMASK			0x000000ff
#  define RT_SDL_AMASK			0xff000000
# endif

typedef struct		s_rt
{
	SDL_Event		event;
	SDL_Surface		*render;
	SDL_Window		*win;

	int				exit;
}					t_rt;

typedef struct		s_v3
{
	double		x;
	double		y;
	double		z;
}					t_v3;

typedef struct		s_aabb
{
	double		x;
	double		y;
	double		w;
	double		h;
}					t_aabb;

typedef struct		s_btn
{
	SDL_Surface		*tex;

	t_aabb			aabb;

	int				st_hover;
	int				st_pressing;
	
	void			(*action_call)(t_rt*);
}					t_btn;

typedef t_v3		t_v2;

void				button_pressed(t_rt *rt);

double				to_rad(double degrees);
double				to_deg(double radians);

void				v3_set(t_v3 *v, double newX, double newY, double newZ);
void				v3_reset(t_v3 *v);
t_v3				v3_cpy(t_v3 v);
int					v3_cmp(t_v3 v1, t_v3 v2);
void				v3_print(t_v3 v, int block);
t_v3				v3_sum(t_v3 v1, t_v3 v2);
t_v3				v3_sub(t_v3 v1, t_v3 v2);
double				v3_norm(t_v3 v);
t_v3				v3_mul(t_v3 v, double value);
t_v3				v3_div(t_v3 v, double value);
t_v3				v3_normalized(t_v3 v);
double				v3_dist(t_v3 v1, t_v3 v2);
t_v3				v3_rot_x(t_v3 v, double a);
t_v3				v3_rot_y(t_v3 v, double a);
t_v3				v3_rot_z(t_v3 v, double a);
t_v3				v3_rot(t_v3 v, double ax, double ay, double az);
double				v3_ang(t_v3 v1, t_v3 v2);

int					aabb_col_pt(t_aabb aabb, t_v2 pt);

t_btn				btn_new(char *filename, t_aabb aabb,
	void (*action_call)(t_rt*));
void				btn_update(t_rt *rt, t_btn *button);
void				btn_draw(t_rt *rt, t_btn btn);

void				sdl_loop(t_rt *rt);
void				sdl_event_manager(t_rt *rt);

void				ft_update(t_rt *rt);

SDL_Surface			*sdl_img_import(char *filename);
void				sdl_img_export(SDL_Surface *img, char *filename);
void				rt_export_screenshoot(t_rt *rt, char *filename);

void				ft_put_pixel(int x, int y, Uint32 c, t_rt *rt);
void				ft_clear_screen(Uint32 color, t_rt *rt);

#endif
