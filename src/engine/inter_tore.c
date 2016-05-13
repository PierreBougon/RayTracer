/*
** inter_complex.c for complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 26 13:36:09 2016 benjamin duhieu
** Last update Thu May 12 21:27:45 2016 benjamin duhieu
*/

#include "raytracer.h"


inline double		solv_tor_b(t_rt *s)
{
  return (2 * ((CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
		CARRE(s->ray.vct->z)) *
	       (1 + ((s->ray.new_eye.x * s->ray.vct->x) +
		     (s->ray.new_eye.y * s->ray.vct->y) +
		     (s->ray.new_eye.z * s->ray.vct->z)))));
}

inline double		solv_tor_c(t_rt *s, t_tore *tore)
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

inline double		solv_tor_d(t_rt *s, t_tore *tore)
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

inline double		solv_tor_e(t_rt *s, t_tore *tore)
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

void		inter_tore(t_rt *s, t_tore *tore)
{
  t_4order	solv;

  s->ray.new_eye.x = s->ray.eye.x - tore->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - tore->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - tore->pos.z;
  rotation(&s->rotation, s->ray.vct, &tore->rot);
  rotation(&s->rotation, &s->ray.new_eye, &tore->rot);
  solv.a = CARRE(CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
		 CARRE(s->ray.vct->z));
  solv.b = solv_tor_b(s);
  solv.c = solv_tor_c(s, tore);
  solv.d = solv_tor_d(s, tore);
  solv.e = solv_tor_e(s, tore);
  solv.root1 = -1;
  solv.root2 = -1;
  solv.root3 = -1;
  solv.root4 = -1;
  resolv_4_degres(&solv);
  attribute_root(s, &solv);
}
