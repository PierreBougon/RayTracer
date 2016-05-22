/*
** shade.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 15:22:45 2016 romain samuel
** Last update Sun May 22 21:42:46 2016 benjamin duhieu
*/

#include "raytracer.h"

double		apply_light(t_rt *s, t_light *light, t_color *light_color)
{
  double	add;

  add = 0;
  add = diffuse_light(s);
  if (add > 0.000000001)
    {
      add = add * light->intensity * s->hit.kd;
      add += (specular_light(s, s->ray.vct) * light->intensity *
	      s->hit.ks);
      *light_color = add_light_color(*light_color, light->color);
    }
  return (add);
}

void		get_final_color(t_rt *s, t_color light_color, double *itab)
{
  double	i;

  i = get_soft_intensity(s, itab) + s->opt.ambient * s->hit.ka;
  i = expose(i);
  s->final_color = apply_b(s->final_color, light_color, s->hit.brightness,
			   i);
  if (s->hit.reflection > 0.0)
    fresnel_computation(s);
}

void		fill_itab(t_rt *s,
			  t_light *light,
			  t_color *light_color,
			  double *itab)
{
  double	coef;

  shadow(s);
  if (s->shade.shadow.coef > 1.0)
    coef = 1.0;
  else
    coef = s->shade.shadow.coef;
  itab[s->shade.diff] = (apply_light(s, light, light_color) *
			 (1.0 - coef));
  s->shade.diff++;
}

int		shade(t_rt *s, t_acc *vct, t_acc eye)
{
  t_object	*it;
  t_light	*light;
  t_color	light_color;

  it = s->obj;
  light_color.full = BLACK;
  init_itab(s->shade.itab);
  while (it != NULL)
    {
      if (it->type == LIGHT)
	{
	  s->shade.diff = 0;
	  light = (t_light *)it->datas;
	  while (s->shade.diff < s->opt.nb_rays_ss)
	    {
	      init_soft_shadow(s);
	      init_lum(s, vct, eye, light);
	      fill_itab(s, light, &light_color, s->shade.itab);
	    }
	}
      it = it->next;
    }
  texturize_obj(s);
  get_final_color(s, light_color, s->shade.itab);
  return (0);
}
