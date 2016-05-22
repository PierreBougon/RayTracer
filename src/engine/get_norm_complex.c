/*
** get_norm_complex.c for get_norm_complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May 11 12:34:10 2016 benjamin duhieu
** Last update Sun May 22 16:43:04 2016 romain samuel
*/

#include <math.h>
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

void		get_coord_spher_tore(t_tore *tore, double *phi,
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
    *teta = (2 * M_PI)
      - acos(tore->simple_inter1.z
	     / sqrt(pow(tore->simple_inter1.z, 2)
		    + pow(tore->simple_inter1.x, 2)));
}

void	get_norm_tore(t_rt *s, t_tore *tore)
{
  double	phi;
  double	teta;

  get_coord_spher_tore(tore, &phi, &teta);
  s->hit.norm1.x = cos(phi) * cos(teta);
  s->hit.norm1.y = sin(phi) * cos(teta);
  s->hit.norm1.z = sin(teta);
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
      s->hit.norm1.x = (-2.0 * phi) * cos(teta);
      s->hit.norm1.y = (-2.0 * phi) * sin(teta);
      s->hit.norm1.z = parab->a;
    }
  else if (parab->form == 2)
    {
      s->hit.norm1.x = (-2.0 * (s->hit.simple_inter1.x)) /
	CARRE(parab->a);
      s->hit.norm1.y = (2.0 * (s->hit.simple_inter1.y)) /
	CARRE(parab->b);
      s->hit.norm1.z = 1.0;
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
      s->hit.norm1.x = -(hyper->c) * cosh(phi) *  cos(teta);
      s->hit.norm1.y = -(hyper->c) * cosh(phi) * sin(teta);
      s->hit.norm1.z = (hyper->a) * sinh(phi);
    }
  else if (hyper->nappe == 2)
    {
      s->hit.norm1.x = -(hyper->c) *
	sqrt(CARRE(phi) - 1.0) * cos(teta);
      s->hit.norm1.y = -(hyper->c) * sqrt(CARRE(phi) - 1.0) *
	sin(teta);
      s->hit.norm1.z = hyper->a * phi;
    }
  end_rotation(&s->rotation, &s->hit.norm1, &hyper->rot);
}

void		get_coord_spher_ellip(t_ellip *ellip, double *phi,
				      double *teta)
{
  double	col;

  col = sqrt((ellip->simple_inter1.x * ellip->simple_inter1.x)
	     + (ellip->simple_inter1.y * ellip->simple_inter1.y)
	     + (ellip->simple_inter1.z * ellip->simple_inter1.z));
  *phi = acos(ellip->simple_inter1.y / col);
  /* printf("SIMPLE INTER X: %f && SIMPLE INTER Y: %f && SIMPLE INTER Z: %f\n\n", ellip->simple_inter1.x, ellip->simple_inter1.y, ellip->simple_inter1.z); */
  if (ellip->simple_inter1.x >= 0)
    *teta = acos(ellip->simple_inter1.z
		 / sqrt(pow(ellip->simple_inter1.z, 2)
			+ pow(ellip->simple_inter1.x, 2)));
  else
    *teta = (2 * M_PI)
      - acos(ellip->simple_inter1.z
	     / sqrt(pow(ellip->simple_inter1.z, 2)
		    + pow(ellip->simple_inter1.x, 2)));
  /* printf("\nphi : %f && teta : %f\n\n", *phi, *teta); */
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
  /* printf("NORMAL X : %f\n NORMAL Y : %f\n NORMAL Z : %f\n\n", s->hit.norm1.x, s->hit.norm1.y, s->hit.norm1.z); */
  end_rotation(&s->rotation, &s->hit.norm1, &ellip->rot);
}
