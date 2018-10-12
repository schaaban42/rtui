/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:15:06 by schaaban          #+#    #+#             */
/*   Updated: 2018/10/10 15:15:27 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtui.h"

SDL_Surface			*sdl_img_import(char *filename)
{
	SDL_Surface		*img;
	if (!(img = SDL_LoadBMP(filename)))
		return (NULL); /* error */
	return (img);
}

void				sdl_img_export(SDL_Surface *img, char *filename)
{
	if ((SDL_SaveBMP(img, filename)) == -1)
		return ; /* error */
}

void				rt_export_screenshoot(t_rt *rt, char *filename)
{
	sdl_img_export(rt->render, filename);
}
