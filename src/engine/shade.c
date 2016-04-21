/*
** shade.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 15:22:45 2016 romain samuel
** Last update Tue Apr 19 12:51:58 2016 romain samuel
*/

#include "raytracer.h"

double		apply_light(t_rt *s, t_light *light, t_color *light_color)
{
  double	add;

  add = 0;
  add = diffuse_light(s, s->obj_hit->next);
  if (add > 0.000000001)
    {
      add = add * light->intensity * s->hit.kd;
      add += (specular_light(s, s->ray.vct) * light->intensity * s->hit.ks);
      *light_color = add_light_color(*light_color, light->color);
    }
  return (add);
}

double		get_soft_intensity(double tab[1])
{
  double	i;
  int		j;

  j = 0;
  i = 0;
  while (j < 1)
    {
      i += tab[j];
      j++;
    }
  i = i / 1;
  return (i);
}

void		get_final_color(t_rt *s, t_color light_color, double itab[1])
{
  double	i;

  i = get_soft_intensity(itab) + s->opt.ambient * s->hit.ka;
  if (i > 1)
    i = 1;
  s->final_color = apply_b(s->final_color, light_color, s->hit.brightness, i);
}

void		fill_itab(t_rt *s,
			  t_light *light,
			  t_color *light_color,
			  double itab[1])
{
  if (shadow(s) == 0)
    itab[s->shade.diff] += apply_light(s, light, light_color);
  else
    itab[s->shade.diff] += 0;
  s->shade.diff++;
}

int		shade(t_rt *s, t_acc *vct, t_acc eye)
{
  t_object	*it;
  t_light	*light;
  double	itab[1];
  t_color	light_color;

  it = s->obj;
  light_color.full = BLACK;
  init_itab(itab);
  while (it != NULL)
    {
      if (it->type == 5)
	{
	  s->shade.diff = 0;
	  light = (t_light *)it->datas;
	  while (s->shade.diff < 1)
	    {
	      /*init_soft_shadow(s);*/
	      init_lum(s, vct, eye, light);
	      fill_itab(s, light, &light_color, itab);
	    }
	}
      it = it->next;
    }
  get_final_color(s, light_color, itab);
  return (0);
}
