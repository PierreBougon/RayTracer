/*
** shade.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 15:22:45 2016 romain samuel
** Last update Sat Apr 16 17:37:28 2016 romain samuel
*/

#include "raytracer.h"

void		init_lum(t_rt *s, t_acc *vct, t_acc eye, t_light *light)
{
  s->shade.inter.x = eye.x + s->hit.k1 * vct->x;
  s->shade.inter.y = eye.y + s->hit.k1 * vct->y;
  s->shade.inter.z = eye.z + s->hit.k1 * vct->z;
  /*printf("eye = %f %f %f\n", eye.x, eye.y, eye.z);
  printf("vct = %f %f %f\n", vct->x, vct->y, vct->z);
  printf("k = %f\n", s->hit.k1);
  printf("inter = %f %f %f\n", s->shade.inter.x, s->shade.inter.y, s->shade.inter.z);*/
  s->shade.vct.x = s->shade.inter.x - (double)light->pos.x;
  s->shade.vct.y = s->shade.inter.y - (double)light->pos.y;
  s->shade.vct.z = s->shade.inter.z - (double)light->pos.z;
  s->shade.light_pos.x = light->pos.x;
  s->shade.light_pos.y = light->pos.y;
  s->shade.light_pos.z = light->pos.z;
}

t_color			add_light_color(t_color color,
					t_color second_color)
{
  unsigned int		r;
  unsigned int		g;
  unsigned int		b;

  r = (color.full & 0xFF) + ((second_color.full & 0xFF));
  g = ((color.full >> 8) & 0xFF) + (((second_color.full >> 8) & 0xFF));
  b = ((color.full >> 16) & 0xFF) + (((second_color.full >> 16) & 0xFF));
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  color.full = 0xFF000000 + (b << 16) + (g << 8) + r;
  return (color);
}

t_color			apply_b(t_color color,
				t_color light_color,
				double brightness,
				double i)
{
  unsigned int		r;
  unsigned int		g;
  unsigned int		b;

  r = (((color.full & 0xFF) * i) * (1 - brightness))
    + (((light_color.full & 0xFF) * i) * brightness);
  g = ((((color.full >> 8) & 0xFF) * i) * (1 - brightness))
    + ((((light_color.full >> 8) & 0xFF) * i) * brightness);
  b = ((((color.full >> 16) & 0xFF) * i) * (1 - brightness))
    + ((((light_color.full >> 16) & 0xFF) * i) * brightness);
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  color.full = 0xFF000000 + (b << 16) + (g << 8) + r;
  return (color);
}

double		apply_light(t_rt *s, t_light *light, t_color *light_color)
{
  double	add;

  add = 0;
  add = diffuse_light(s, s->obj_hit->next);
  /*  printf("add = %f\n", add);*/
  if (add > 0.1)
    {
      /*printf("add = %f, int = %f, kd = %f\n", add, light->intensity, s->hit.kd);*/
      add = add * light->intensity * s->hit.kd;
      /*printf("add = %f\n", add);*/
      add += (specular_light(s, s->ray.vct) * light->intensity * s->hit.ks);
      *light_color = add_light_color(*light_color, light->color);
    }
  return (add);
}

int		shade(t_rt *s, t_acc *vct, t_acc eye)
{
  t_object	*it;

  t_light	*light;
  double	i;
  t_color	light_color;

  it = s->obj;
  i = 0;
  light_color.full = BLACK;
  while (it != NULL)
    {
      if (it->type == 5)
	{
	  light = (t_light *)it->datas;
	  init_lum(s, vct, eye, light);
	  if (shadow(s) == 0)
	    i += apply_light(s, light, &light_color);
	}
      it = it->next;
    }
  i += s->opt.ambient * s->hit.ka;
  if (i > 1)
    i = 1;
  s->final_color = apply_b(s->final_color, light_color, s->hit.brightness, i);
  return (0);
}
