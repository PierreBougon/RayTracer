/*
** get_norm_4_degres.c for norm_4_degres
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun May 22 16:40:36 2016 benjamin duhieu
** Last update Sun May 22 17:00:18 2016 benjamin duhieu
*/

#include "raytracer.h"

void	get_norm_hole_cube(t_rt *s, t_hole_cube *hole_cube)
{
  s->hit.norm1.x = (4.0 * CUBE(s->hit.simple_inter1.x)) -
    (10.0 * (s->hit.simple_inter1.x));
  s->hit.norm1.y = (4.0 * CUBE(s->hit.simple_inter1.y)) -
    (10.0 * (s->hit.simple_inter1.y));
  s->hit.norm1.z = (4.0 * CUBE(s->hit.simple_inter1.z)) -
    (10.0 * (s->hit.simple_inter1.z));
  end_rotation(&s->rotation, &s->hit.norm1, &hole_cube->rot);
}

static void		get_coord_spher_tore(t_tore *tore, double *phi,
				      double *teta)
{
  double	col;

  col = sqrt((tore->simple_inter1.x * tore->simple_inter1.x)
	     + (tore->simple_inter1.y * tore->simple_inter1.y)
	     + (tore->simple_inter1.z * tore->simple_inter1.z));
  *phi = acos(tore->simple_inter1.y / col);
  if (tore->simple_inter1.x >= 0)
    *teta = acos(tore->simple_inter1.z
		 / sqrt(pow(tore->simple_inter1.z, 2)
			+ pow(tore->simple_inter1.x, 2)));
  else
    *teta = (2.0 * M_PI)
      - acos(tore->simple_inter1.z
	     / sqrt(pow(tore->simple_inter1.z, 2)
		    + pow(tore->simple_inter1.x, 2)));
}

void	get_norm_tore(t_rt *s, t_tore *tore)
{
  double	phi;
  double	teta;

  get_coord_spher_tore(tore, &phi, &teta);
  s->hit.norm1.z = cos(teta) * cos(phi);
  s->hit.norm1.x = sin(teta) * cos(phi);
  s->hit.norm1.y = sin(phi);
  end_rotation(&s->rotation, &s->hit.norm1, &tore->rot);
}

static void		get_coord_spher_ellip(t_ellip *ellip, double *phi,
				      double *teta)
{
  double	col;

  col = sqrt((ellip->simple_inter1.x * ellip->simple_inter1.x)
	     + (ellip->simple_inter1.y * ellip->simple_inter1.y)
	     + (ellip->simple_inter1.z * ellip->simple_inter1.z));
  *phi = acos(ellip->simple_inter1.y / col);
  if (ellip->simple_inter1.x >= 0)
    *teta = acos(ellip->simple_inter1.z
		 / sqrt(pow(ellip->simple_inter1.z, 2)
			+ pow(ellip->simple_inter1.x, 2)));
  else
    *teta = (2.0 * M_PI)
      - acos(ellip->simple_inter1.z
	     / sqrt(pow(ellip->simple_inter1.z, 2)
		    + pow(ellip->simple_inter1.x, 2)));
}

void		get_norm_ellip(t_rt *s, t_ellip *ellip)
{
  double	phi;
  double	teta;

  phi = 0;
  teta = 0;
  get_coord_spher_ellip(ellip, &phi, &teta);
  s->hit.norm1.z = ellip->b * ellip->c * sin(phi) * cos(teta);
  s->hit.norm1.x = ellip->a * ellip->c * sin(phi) * sin(teta);
  s->hit.norm1.y = ellip->a * ellip->b * cos(phi);
  end_rotation(&s->rotation, &s->hit.norm1, &ellip->rot);
}
