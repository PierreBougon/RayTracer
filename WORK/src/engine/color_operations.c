/*
** color_operations.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 12:50:14 2016 romain samuel
** Last update Sat Apr 23 18:48:57 2016 romain samuel
*/

#include "raytracer.h"

t_color			compute_colors(t_color color1,
				       t_color color2,
				       double coef)
{
  unsigned int		r;
  unsigned int		g;
  unsigned int		b;

  r = ((color1.full & 0xFF) * (1 - coef))
    + (((color2.full & 0xFF)) * coef);
  g = (((color1.full >> 8) & 0xFF) * (1 - coef))
    + ((((color2.full >> 8) & 0xFF)) * coef);
  b = (((color1.full >> 16) & 0xFF) * (1 - coef))
    + ((((color2.full >> 16) & 0xFF)) * coef);
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  color1.full = 0xFF000000 + (b << 16) + (g << 8) + r;
  return (color1);
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
