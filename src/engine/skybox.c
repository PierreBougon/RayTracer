/*
** skybox.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri Apr 29 16:15:08 2016 romain samuel
** Last update Sun May 22 21:43:21 2016 benjamin duhieu
*/

#include "raytracer.h"

int		read_texture(t_rt *s, float u, float v,
			     t_bunny_pixelarray *img)
{
  t_color	*color;

  u = fabs(u);
  v = fabs(v);
  color = (t_color *)img->pixels;
  u = u * img->clipable.clip_width;
  v = v * img->clipable.clip_height;
  s->final_color = color[img->clipable.clip_width * (int)v + (int)u];
  return (0);
}

void	skybox_x(t_rt *s, t_acc *vct)
{
  if (vct->x > 0.0)
    {
      s->final_color.full = 0xFF0000FF;
      read_texture(s,
		   (vct->z / vct->x + 1.0) * 0.5,
		   1.0 - (vct->y / vct->x + 1.0) * 0.5,
		   s->opt.skybox_right);
    }
  else
    {
      s->final_color.full = 0xFF0000FF;
      read_texture(s,
		   (vct->z / vct->x + 1.0) * 0.5,
		   (vct->y / vct->x + 1.0) * 0.5,
		   s->opt.skybox_left);
    }
}

void	skybox_y(t_rt *s, t_acc *vct)
{
  if (vct->y > 0.0)
    read_texture(s,
		 1.0 - (vct->x / vct->y + 1.0) * 0.5,
		 (vct->z / vct->y + 1.0) * 0.5,
		 s->opt.skybox_up);
  else
    read_texture(s,
		 (vct->x / vct->y + 1.0) * 0.5,
		 1.0 - (vct->z / vct->y + 1.0) * 0.5,
		 s->opt.skybox_down);
}

void	skybox_z(t_rt *s, t_acc *vct)
{
  if (vct->z > 0.0)
    {
      read_texture(s,
		   1.0 - (vct->x / vct->z + 1.0) * 0.5,
		   1.0 - (vct->y / vct->z + 1.0) * 0.5,
		   s->opt.skybox_forward);
    }
  else
    {
      read_texture(s,
		   1.0 - (vct->x / vct->z + 1.0) * 0.5,
		   (vct->y / vct->z + 1.0) * 0.5,
		   s->opt.skybox_backward);
    }
}

int	skybox(t_rt *s, t_acc *vct)
{
  if (s->opt.skybox == 0)
    {
      s->final_color.full = BLACK;
      return (0);
    }
  if (fabs(vct->x) >= fabs(vct->y) && fabs(vct->x) >= fabs(vct->z))
    skybox_x(s, vct);
  else if (fabs(vct->y) >= fabs(vct->x) && fabs(vct->y) >= fabs(vct->z))
    skybox_y(s, vct);
  else
    skybox_z(s, vct);
  return (0);
}
