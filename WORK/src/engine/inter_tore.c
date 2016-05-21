/*
** inter_complex.c for complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 26 13:36:09 2016 benjamin duhieu
** Last update Mon May  2 13:57:25 2016 benjamin duhieu
*/

#include "raytracer.h"

double		solv_tor_a(t_rt *s, t_tore *tore)
{
  return (CARRE(CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
		CARRE(s->ray.vct->z)));
}

double		solv_tor_b(t_rt *s, t_tore *tore)
{
  return (2 * ((CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
		CARRE(s->ray.vct->z)) *
	       (1 + ((s->ray.new_eye.x * s->ray.vct->x) +
		     (s->ray.new_eye.y * s->ray.vct->y) +
		     (s->ray.new_eye.z * s->ray.vct->z)))));
}

double		solv_tor_c(t_rt *s, t_tore *tore)
{
  return (4 * (((s->ray.new_eye.x * s->ray.vct->x) +
		(s->ray.new_eye.y * s->ray.vct->y) +
		(s->ray.new_eye.z * s->ray.vct->z)) +
	       ((CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
		 CARRE(s->ray.vct->z)) *
		((2 * CARRE(s->ray.new_eye.x)) +
		 (2 * CARRE(s->ray.new_eye.y)) +
		 (2 * CARRE(s->ray.new_eye.z)) +
		 (2 * CARRE(tore->dist)) - (2 * CARRE(tore->rad))))));
}

double		solv_tor_d(t_rt *s, t_tore *tore)
{
  return ((-4 * CARRE(tore->dist)) *
	  (CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y)) +
	  ((s->ray.new_eye.x * s->ray.vct->x) +
	   (s->ray.new_eye.y * s->ray.vct->y) +
	   (s->ray.new_eye.z * s->ray.vct->z)) *
	  ((4 * CARRE(s->ray.new_eye.x)) + (4 * CARRE(s->ray.new_eye.y)) +
	   (4 * CARRE(s->ray.new_eye.z)) + (4 * CARRE(tore->dist)) -
	   (4 * CARRE(tore->rad))));
}

double		solv_tor_e(t_rt *s, t_tore *tore)
{
  return (CARRE((CARRE(s->ray.new_eye.x) + CARRE(s->ray.new_eye.y) +
		 CARRE(s->ray.new_eye.z) + CARRE(tore->dist) +
		 CARRE(tore->rad))) -
	  ((4 * CARRE(tore->dist)) *
	   (CARRE(s->ray.new_eye.x) +
	    CARRE(s->ray.new_eye.y) +
	    (2 * s->ray.new_eye.x * s->ray.vct->x) +
	    (2 * s->ray.new_eye.y * s->ray.vct->y))));
}

int		inter_tore(t_rt *s, t_tore *tore)
{
  t_solv	solv;

  s->ray.new_eye.x = s->ray.eye.x - tore->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - tore->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - tore->pos.z;
  rotation(&s->rotation, s->ray.vct, &tore->rot);
  rotation(&s->rotation, &s->ray.new_eye, &tore->rot);
  solv.a = solv_tor_a(s, tore);
  solv.b = solv_tor_b(s, tore);
  solv.c = solv_tor_c(s, tore);
  solv.d = solv_tor_d(s, tore);
  solv.e = solv_tor_e(s, tore);
  resolv_4_degres(s, tore, &solv);
}
