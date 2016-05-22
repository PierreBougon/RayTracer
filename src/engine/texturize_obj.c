/*
** texturize_obj.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Sun Apr 24 15:39:17 2016 romain samuel
** Last update Sun May 22 16:40:43 2016 romain samuel
*/

#include "raytracer.h"
#include "perlin.h"

void		full_color(t_rt *s)
{
  s->final_color = s->hit.color1;
}

void		get_image_texel(t_rt *s)
{
  t_color	*color;

  color = s->hit.texture1->pixels;
  /* printf("x = %f, y = %f\n", s->hit.texels.x, s->hit.texels.y); */
  s->hit.texels.x = s->hit.texels.x
    * s->hit.texture1->clipable.clip_width;
  s->hit.texels.y = s->hit.texels.y
    * s->hit.texture1->clipable.clip_height;
  /* printf("new: x = %f, y = %f\n", s->hit.texels.x, s->hit.texels.y); */
  /* printf("width = %d, y = %d, x = %d\n", s->hit.texture1->clipable.clip_width, */
	 /* (int)s->hit.texels.y, (int)s->hit.texels.x); */
  s->final_color = color[s->hit.texture1->clipable.clip_width
			 * (int)s->hit.texels.y
			 + (int)s->hit.texels.x];
}

int	texturize_obj(t_rt *s)
{
  s->ftabs.tex_ftab[0] = &full_color;
  s->ftabs.tex_ftab[1] = &stripes;
  s->ftabs.tex_ftab[2] = &checkerboard_2d;
  s->ftabs.tex_ftab[3] = &planar_checkerboard;
  s->ftabs.tex_ftab[4] = &checkerboard_3d;
  s->ftabs.tex_ftab[5] = &smooth_noise;
  s->ftabs.tex_ftab[6] = &marble_noise;
  s->ftabs.tex_ftab[7] = &get_image_texel;
  if (s->hit.tex_type < 9)
    s->ftabs.tex_ftab[s->hit.tex_type - 1](s);
  else
    s->ftabs.tex_ftab[0](s);
  return (0);
}
