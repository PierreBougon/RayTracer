/*
** live_engine.h for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 18 20:20:50 2016 romain samuel
** Last update Tue Apr 19 11:49:53 2016 romain samuel
*/

#ifndef LIVE_ENGINE_H_
# define LIVE_ENGINE_H_

#include "raytracer.h"

/*
** display.c
*/
t_color			live_display_objects(t_rt *s, t_acc *vct, t_acc eye, int rec);
int			live_display(t_rt *s);

/*
** live_shade.c
*/
int			live_shade(t_rt *s, t_acc *vct, t_acc eye);

#endif /* !LIVE_ENGINE_H_ */
