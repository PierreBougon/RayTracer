/*
** live_shade.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 11:35:43 2016 romain samuel
** Last update Fri May 13 19:07:55 2016 bougon_p
*/

#include "raytracer.h"
#include "live_engine.h"

void		live_init_lum(t_rt *s, t_acc *vct, t_acc eye, t_light *light)
{
  s->shade.inter.x = eye.x + s->hit.k1 * vct->x;
  s->shade.inter.y = eye.y + s->hit.k1 * vct->y;
  s->shade.inter.z = eye.z + s->hit.k1 * vct->z;
  s->shade.light_pos.x = light->pos.x;
  s->shade.light_pos.y = light->pos.y;
  s->shade.light_pos.z = light->pos.z;
  s->shade.vct.x = s->shade.inter.x - (double)s->shade.light_pos.x;
  s->shade.vct.y = s->shade.inter.y - (double)s->shade.light_pos.y;
  s->shade.vct.z = s->shade.inter.z - (double)s->shade.light_pos.z;
}

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
      if (it->type == LIGHT)
	{
	  light = (t_light *)it->datas;

	  live_init_lum(s, vct, eye, light);
	  i += diffuse_light(s, s->obj_hit->next) * light->intensity * s->hit.kd;
	}
      it = it->next;
    }
  i += s->opt.ambient * s->hit.ka;
  if (i > 1)
    i = 1;
  s->final_color = apply_b(s->final_color, light_color, s->hit.brightness, i);
  return (0);
}
