/*
** shade.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Mon Apr 11 15:22:45 2016 romain samuel
** Last update Mon Apr 18 16:06:43 2016 romain samuel
*/

#include "raytracer.h"

int		init_soft_shadow(t_rt *s)
{
  int		rd;

  /*s->shade.x_diff[0] = 0;
  s->shade.x_diff[1] = 500;
  s->shade.x_diff[2] = - 500;
  s->shade.x_diff[3] = 0;
  s->shade.x_diff[4] = 0;
  s->shade.x_diff[5] = 0;
  s->shade.x_diff[6] = 0;
  s->shade.y_diff[0] = 0;
  s->shade.y_diff[1] = 0;
  s->shade.y_diff[2] = 0;
  s->shade.y_diff[3] = 500;
  s->shade.y_diff[4] = - 500;
  s->shade.y_diff[5] = 0;
  s->shade.y_diff[6] = 0;
  s->shade.z_diff[0] = 0;
  s->shade.z_diff[1] = 0;
  s->shade.z_diff[2] = 0;
  s->shade.z_diff[3] = 0;
  s->shade.z_diff[4] = 0;
  s->shade.z_diff[5] = 500;
  s->shade.z_diff[6] = - 500;*/
  rd = rand() % 1000;
  s->shade.x_diff = rd - 500;
  rd = rand() % 1000;
  s->shade.y_diff = rd - 500;
  rd = rand() % 1000;
  s->shade.z_diff = rd - 500;
  return (0);
}

void		init_lum(t_rt *s, t_acc *vct, t_acc eye, t_light *light)
{
  s->shade.inter.x = eye.x + s->hit.k1 * vct->x;
  s->shade.inter.y = eye.y + s->hit.k1 * vct->y;
  s->shade.inter.z = eye.z + s->hit.k1 * vct->z;
  s->shade.light_pos.x = light->pos.x + s->shade.x_diff;
  s->shade.light_pos.y = light->pos.y + s->shade.y_diff;
  s->shade.light_pos.z = light->pos.z + s->shade.z_diff;
  s->shade.vct.x = s->shade.inter.x - (double)s->shade.light_pos.x;
  s->shade.vct.y = s->shade.inter.y - (double)s->shade.light_pos.y;
  s->shade.vct.z = s->shade.inter.z - (double)s->shade.light_pos.z;
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
  if (add > 0.000000001)
    {
      add = add * light->intensity * s->hit.kd;
      add += (specular_light(s, s->ray.vct) * light->intensity * s->hit.ks);
      *light_color = add_light_color(*light_color, light->color);
    }
  return (add);
}

double		get_soft_intensity(double tab[500])
{
  double	i;
  int		j;

  j = 0;
  while (j < 500)
    {
      i += tab[j];
      j++;
    }
  i = i / 500;
  return (i);
}

int		shade(t_rt *s, t_acc *vct, t_acc eye)
{
  t_object	*it;
  t_light	*light;
  double	i;
  double	itab[500];
  t_color	light_color;

  it = s->obj;
  light_color.full = BLACK;
  while (it != NULL)
    {
      if (it->type == 5)
	{
	  s->shade.diff = 0;
	  light = (t_light *)it->datas;
	  while (s->shade.diff < 500)
	    {
	      init_soft_shadow(s);
	      init_lum(s, vct, eye, light);
	      if (shadow(s) == 0)
		itab[s->shade.diff] = apply_light(s, light, &light_color);
	      else
		itab[s->shade.diff] = 0;
	      s->shade.diff++;
	    }
	}
      it = it->next;
    }
  i = get_soft_intensity(itab) + s->opt.ambient * s->hit.ka;
  if (i > 1)
    i = 1;
  s->final_color = apply_b(s->final_color, light_color, s->hit.brightness, i);
  return (0);
}
