/*
** get_norm_complex.c for get_norm_complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May 11 12:34:10 2016 benjamin duhieu
** Last update Sun May 22 16:45:04 2016 benjamin duhieu
*/

#include <math.h>
#include "raytracer.h"

static void		get_coord_spher_parab(t_parab *parab, double *phi,
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
    *teta = (2.0 * M_PI)
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
      s->hit.norm1.z = (-2.0 * phi) * cos(teta);
      s->hit.norm1.x = (-2.0 * phi) * sin(teta);
      s->hit.norm1.y = parab->a;
    }
  else if (parab->form == 2)
    {
      s->hit.norm1.z = (-2.0 * (s->hit.simple_inter1.x)) /
	CARRE(parab->a);
      s->hit.norm1.x = (2.0 * (s->hit.simple_inter1.y)) /
	CARRE(parab->b);
      s->hit.norm1.y = 1.0;
    }
  end_rotation(&s->rotation, &s->hit.norm1, &parab->rot);
}

static void		get_coord_spher_hyper(t_hyper *hyper, double *phi,
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
    *teta = (2.0 * M_PI)
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
      s->hit.norm1.z = -(hyper->c) * cosh(phi) *  cos(teta);
      s->hit.norm1.x = -(hyper->c) * cosh(phi) * sin(teta);
      s->hit.norm1.y = (hyper->a) * sinh(phi);
    }
  else if (hyper->nappe == 2)
    {
      s->hit.norm1.z = -(hyper->c) *
	sqrt(CARRE(phi) - 1.0) * cos(teta);
      s->hit.norm1.x = -(hyper->c) * sqrt(CARRE(phi) - 1.0) *
	sin(teta);
      s->hit.norm1.y = hyper->a * phi;
    }
  end_rotation(&s->rotation, &s->hit.norm1, &hyper->rot);
}
