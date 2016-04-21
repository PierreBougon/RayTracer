/*
** color_operations.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 19 12:50:14 2016 romain samuel
** Last update Tue Apr 19 12:51:56 2016 romain samuel
*/

#include "raytracer.h"

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
