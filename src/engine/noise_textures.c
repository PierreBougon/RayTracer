/*
** noise_textures.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu Apr 28 12:31:13 2016 romain samuel
** Last update Thu Apr 28 12:40:12 2016 romain samuel
*/

#include "raytracer.h"
#include "perlin.h"

void		smooth_noise(t_rt *s)
{
  double	noise;

  noise = PerlinNoise3D(s->hit.simple_inter1.x * 0.0005,
			s->hit.simple_inter1.y * 0.0005,
			s->hit.simple_inter1.z * 0.0005,
			2,
			2,
			4);
  if (noise < 0)
    noise *= -1;
  s->final_color = compute_colors(s->hit.color1, s->hit.color2, noise);
}

void		marble_noise(t_rt *s)
{
  double	noise;

  noise = PerlinNoise3D(s->hit.simple_inter1.x * 0.0005,
			s->hit.simple_inter1.y * 0.0005,
			s->hit.simple_inter1.z * 0.0005,
			2,
			2,
			4);
  noise = 0.5 * sin((s->hit.simple_inter1.x + s->hit.simple_inter1.y) * 0.001 + noise) + 0.5;
  if (noise < 0)
    noise *= -1;
  s->final_color = compute_colors(s->hit.color1, s->hit.color2, noise);
}
