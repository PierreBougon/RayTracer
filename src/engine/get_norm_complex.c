/*
** get_norm_complex.c for get_norm_complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May 11 12:34:10 2016 benjamin duhieu
** Last update Thu May 19 10:48:07 2016 benjamin duhieu
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

void	get_norm_hyper(t_rt *s, t_hyper *hyper)
{
  if (hyper->nappe == 1)
    {
      s->hit.norm.x = -(hyper->b * hyper->c) *
	CARRE(cosh(s->hit.simple_inter1.x)) *
	cos(s->hit.simple_inter1.y);
      s->hit.norm.y = -(hyper->a * hyper->c) * cosh(s->hit.simple_inter1.x) *
	sin(s->hit.simple_inter1.y);
      s->hit.norm.z = (hyper->a * hyper->b) *
	sinh(s->hit.simple_inter1.x) * cosh(s->hit.simple_inter1.x);
    }
  else if (hyper->nappe == 2)
    {
      s->hit.norm.x = -(hyper->b * hyper->c) *
	sqrt(CARRE(s->hit.simple_inter1.x) - 1) *
	cos(s->hit.simple_inter1.y);
      s->hit.norm.y = -(hyper->a * hyper->c) *
	sqrt(CARRE(s->hit.simple_inter1.x) - 1) *
	sin(s->hit.simple_inter1.y);
      s->hit.norm.z = hyper->a * hyper->b * s->hit.simple_inter1.x;
    }
}
