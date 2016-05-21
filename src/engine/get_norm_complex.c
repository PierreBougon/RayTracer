/*
** get_norm_complex.c for get_norm_complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May 11 12:34:10 2016 benjamin duhieu
** Last update Fri May 20 23:12:01 2016 benjamin duhieu
*/

#include <math.h>
#include "raytracer.h"

void	get_norm_hole_cube(t_rt *s, t_hole_cube *hole_cube)
{
  s->hit.norm.x = (4 * CUBE(s->hit.simple_inter1.x)) -
    (10 * (s->hit.simple_inter1.x));
  s->hit.norm.y = (4 * CUBE(s->hit.simple_inter1.y)) -
    (10 * (s->hit.simple_inter1.y));
  s->hit.norm.z = (4 * CUBE(s->hit.simple_inter1.z)) -
    (10 * (s->hit.simple_inter1.z));
  end_rotation(&s->rotation, &s->hit.norm, &hole_cube->rot);
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
  s->hit.norm.x = cos(s->hit.simple_inter1.x) *
    cos(s->hit.simple_inter1.y);
  s->hit.norm.y = sin(s->hit.simple_inter1.x) *
    cos(s->hit.simple_inter1.y);
  s->hit.norm.z = sin(s->hit.simple_inter1.y);
  end_rotation(&s->rotation, &s->hit.norm, &tore->rot);
}

void	get_norm_parab(t_rt *s, t_parab *parab)
{
  if (parab->form == 1)
    {
      s->hit.norm.x = (-2 * s->hit.simple_inter1.x) *
	cos(s->hit.simple_inter1.y);
      s->hit.norm.y = (-2 * s->hit.simple_inter1.x) *
	sin(s->hit.simple_inter1.y);
      s->hit.norm.z = parab->a;
    }
  else if (parab->form == 2)
    {
      s->hit.norm.x = (-2 * (s->hit.simple_inter1.x)) /
	CARRE(parab->a);
      s->hit.norm.y = (2 * (s->hit.simple_inter1.y)) /
	CARRE(parab->b);
      s->hit.norm.z = 1;
    }
  end_rotation(&s->rotation, &s->hit.norm, &parab->rot);
}

void		get_norm_hyper(t_rt *s, t_hyper *hyper)
{
  double	col;
  double	phi;
  double	teta;

  col = sqrt((hyper->simple_inter1.x * hyper->simple_inter1.x)
	     + (hyper->simple_inter1.y * hyper->simple_inter1.y)
	     + (hyper->simple_inter1.z * hyper->simple_inter1.z));
  phi = acos(hyper->simple_inter1.y / col);
  if (hyper->simple_inter1.x >= 0)
    teta = acos(hyper->simple_inter1.z
		/ sqrt(pow(hyper->simple_inter1.z, 2)
		       + pow(hyper->simple_inter1.x, 2)));
  else
    teta = (2 * M_PI)
      - acos(hyper->simple_inter1.z
	     / sqrt(pow(hyper->simple_inter1.z, 2)
		    + pow(hyper->simple_inter1.x, 2)));
  if (hyper->nappe == 1)
    {
      s->hit.norm.x = -(/* hyper->b * */ hyper->c) *
	/* CARRE( */cosh(phi)/* ) */ *  cos(teta);
      s->hit.norm.y = -(/* hyper->a * */ hyper->c) * /* CARRE( */cosh(phi)/* ) */
	* sin(teta);
      s->hit.norm.z = (hyper->a /* * hyper->b */) * sinh(phi) /* * cosh(teta) */;
    }
  else if (hyper->nappe == 2)
    {
      s->hit.norm.x = -(/* hyper->b *  */hyper->c) *
	sqrt(CARRE(phi) - 1) * cos(teta);
      s->hit.norm.y = -(/* hyper->a *  */hyper->c) * sqrt(CARRE(phi) - 1) *
	sin(teta);
      s->hit.norm.z = hyper->a /* * hyper->b  */ * phi;
    }
  end_rotation(&s->rotation, &s->hit.norm, &hyper->rot);
}
