/*
** get_norm_complex.c for get_norm_complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May 11 12:34:10 2016 benjamin duhieu
** Last update Sun May 22 14:16:36 2016 romain samuel
*/

#include <math.h>
#include "raytracer.h"

void	get_norm_hole_cube(t_rt *s, t_hole_cube *hole_cube)
{
  s->hit.norm1.x = (4 * CUBE(s->hit.simple_inter1.x)) -
    (10 * (s->hit.simple_inter1.x));
  s->hit.norm1.y = (4 * CUBE(s->hit.simple_inter1.y)) -
    (10 * (s->hit.simple_inter1.y));
  s->hit.norm1.z = (4 * CUBE(s->hit.simple_inter1.z)) -
    (10 * (s->hit.simple_inter1.z));
  end_rotation(&s->rotation, &s->hit.norm1, &hole_cube->rot);
}

void	get_norm_tore(t_rt *s, t_tore *tore)
{
  /* s->hit.norm.x = 4 * s->hit.simple_inter1.x * */
  /*   (CARRE(s->hit.simple_inter1.x) + CARRE(s->hit.simple_inter1.y) + */
  /*    CARRE(s->hit.simple_inter1.z) + CARRE(tore->dist) - CARRE(tore->rad)) - */
  /*   (8 * CARRE(tore->dist) * s->hit.simple_inter1.x); */
  /* s->hit.norm.y = 4 * s->hit.simple_inter1.y * */
  /*   (CARRE(s->hit.simple_inter1.x) + CARRE(s->hit.simple_inter1.y) + */
  /*    CARRE(s->hit.simple_inter1.z) + CARRE(tore->dist) - CARRE(tore->rad)); */
  /* s->hit.norm.z = 4 * s->hit.simple_inter1.z * */
  /*   (CARRE(s->hit.simple_inter1.x) + CARRE(s->hit.simple_inter1.y) + */
  /*    CARRE(s->hit.simple_inter1.z) + CARRE(tore->dist) - CARRE(tore->rad)) - */
  /*   (8 * CARRE(tore->dist) * s->hit.simple_inter1.z); */
  s->hit.norm1.x = cos(s->hit.simple_inter1.x) *
    cos(s->hit.simple_inter1.y);
  s->hit.norm1.y = sin(s->hit.simple_inter1.x) *
    cos(s->hit.simple_inter1.y);
  s->hit.norm1.z = sin(s->hit.simple_inter1.y);
  end_rotation(&s->rotation, &s->hit.norm1, &tore->rot);
}

void		get_coord_spher_parab(t_parab *parab, double *phi,
				      double *teta)
{
  double	col;

  col = sqrt((parab->simple_inter1.x * parab->simple_inter1.x)
	     + (parab->simple_inter1.y * parab->simple_inter1.y)
	     + (parab->simple_inter1.z * parab->simple_inter1.z));
  *phi = acos(parab->simple_inter1.y / col);
  if (parab->simple_inter1.x >= 0)
    *teta = acos(parab->simple_inter1.z
		 / sqrt(pow(parab->simple_inter1.z, 2)
			+ pow(parab->simple_inter1.x, 2)));
  else
    *teta = (2 * M_PI)
      - acos(parab->simple_inter1.z
	     / sqrt(pow(parab->simple_inter1.z, 2)
		    + pow(parab->simple_inter1.x, 2)));
}

void	get_norm_parab(t_rt *s, t_parab *parab)
{
  double	phi;
  double	teta;

  if (parab->form == 1)
    {
      phi = 0;
      teta = 0;
      get_coord_spher_parab(parab, &phi, &teta);
      s->hit.norm1.x = (-2 * phi) * cos(teta);
      s->hit.norm1.y = (-2 * phi) * sin(teta);
      s->hit.norm1.z = parab->a;
    }
  else if (parab->form == 2)
    {
      s->hit.norm1.x = (-2 * (s->hit.simple_inter1.x)) /
	CARRE(parab->a);
      s->hit.norm1.y = (2 * (s->hit.simple_inter1.y)) /
	CARRE(parab->b);
      s->hit.norm1.z = 1;
    }
  end_rotation(&s->rotation, &s->hit.norm1, &parab->rot);
}

void		get_coord_spher_hyper(t_hyper *hyper, double *phi,
				      double *teta)
{
  double	col;

  col = sqrt((hyper->simple_inter1.x * hyper->simple_inter1.x)
	     + (hyper->simple_inter1.y * hyper->simple_inter1.y)
	     + (hyper->simple_inter1.z * hyper->simple_inter1.z));
  *phi = acos(hyper->simple_inter1.y / col);
  if (hyper->simple_inter1.x >= 0)
    *teta = acos(hyper->simple_inter1.z
		 / sqrt(pow(hyper->simple_inter1.z, 2)
			+ pow(hyper->simple_inter1.x, 2)));
  else
    *teta = (2 * M_PI)
      - acos(hyper->simple_inter1.z
	     / sqrt(pow(hyper->simple_inter1.z, 2)
		    + pow(hyper->simple_inter1.x, 2)));
}

void		get_norm_hyper(t_rt *s, t_hyper *hyper)
{
  double	phi;
  double	teta;

  phi = 0;
  teta = 0;
  get_coord_spher_hyper(hyper, &phi, &teta);
  if (hyper->nappe == 1)
    {
      s->hit.norm1.x = -(/* hyper->b * */ hyper->c) *
	/* CARRE( */cosh(teta)/* ) */ *  cos(phi);
      s->hit.norm1.y = -(/* hyper->a * */ hyper->c) * /* CARRE( */cosh(teta)/* ) */
	* sin(phi);
      s->hit.norm1.z = (hyper->a /* * hyper->b */) * sinh(teta) /* * cosh(teta) */;
    }
  else if (hyper->nappe == 2)
    {
      s->hit.norm1.x = -(/* hyper->b *  */hyper->c) *
	sqrt(CARRE(phi) - 1) * cos(teta);
      s->hit.norm1.y = -(/* hyper->a *  */hyper->c) * sqrt(CARRE(phi) - 1) *
	sin(teta);
      s->hit.norm1.z = hyper->a /* * hyper->b  */ * phi;
    }
  end_rotation(&s->rotation, &s->hit.norm1, &hyper->rot);
}
