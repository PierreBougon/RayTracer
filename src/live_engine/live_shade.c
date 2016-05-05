/*
** live_shade.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 11:35:43 2016 romain samuel
** Last update Wed May  4 15:25:15 2016 romain samuel
*/

#include "raytracer.h"
#include "live_engine.h"

int		live_shade(t_rt *s, t_acc *vct, t_acc eye)
{
  t_object	*it;
  t_light	*light;
  double	i;
  t_color	light_color;

  it = s->obj;
  light_color.full = BLACK;
  i = 0;
  while (it != NULL)
    {
      if (it->type == 1)
	{
	  light = (t_light *)it->datas;
	  init_lum(s, vct, eye, light);
	  i += diffuse_light(s, s->obj_hit->next) * light->intensity * s->hit.kd;
	  /* i = 1; */
	}
      it = it->next;
    }
  i += s->opt.ambient * s->hit.ka;
  if (i > 1)
    i = 1;
  s->final_color = apply_b(s->final_color, light_color, s->hit.brightness, i);
  return (0);
}
