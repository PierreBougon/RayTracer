/*
** inter_complex.c for complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 26 13:36:09 2016 benjamin duhieu
** Last update Sun May 22 00:53:06 2016 benjamin duhieu
*/

#include "raytracer.h"


inline double		solv_tor_b(t_rt *s)
{
  return (4.0 *
	  (s->ray.vct->x * s->ray.vct->x +
	   s->ray.vct->y * s->ray.vct->y +
	   s->ray.vct->z * s->ray.vct->z) *
	  (s->ray.vct->x * s->ray.new_eye.x +
	   s->ray.vct->y * s->ray.new_eye.y +
	   s->ray.vct->z * s->ray.new_eye.z));
}

inline double		solv_tor_c(t_rt *s, t_tore *tore)
{
  return (2.0 *
	  (s->ray.vct->x * s->ray.vct->x +
	   s->ray.vct->y * s->ray.vct->y +
	   s->ray.vct->z * s->ray.vct->z) *
	  (s->ray.new_eye.x * s->ray.new_eye.x +
	   s->ray.new_eye.y * s->ray.new_eye.y +
	   s->ray.new_eye.z * s->ray.new_eye.z +
	   tore->dist * tore->dist -
	   tore->rad * tore->rad) +
	  4.0 * ((s->ray.vct->x * s->ray.new_eye.x) +
		 (s->ray.vct->y * s->ray.new_eye.y) +
		 (s->ray.vct->z * s->ray.new_eye.z)) *
	  ((s->ray.vct->x * s->ray.new_eye.x) +
	   (s->ray.vct->y * s->ray.new_eye.y) +
	   (s->ray.vct->z * s->ray.new_eye.z)) -
	  4.0 * tore->dist * tore->dist *
	  (s->ray.vct->x * s->ray.vct->x +
	   s->ray.vct->y * s->ray.vct->y));
}

inline double		solv_tor_d(t_rt *s, t_tore *tore)
{

  return (4.0 *
	  (s->ray.vct->x * s->ray.new_eye.x +
	   s->ray.vct->y * s->ray.new_eye.y +
	   s->ray.vct->z + s->ray.new_eye.z) *
	  (s->ray.new_eye.x * s->ray.new_eye.x +
	   s->ray.new_eye.y * s->ray.new_eye.y +
	   s->ray.new_eye.z * s->ray.new_eye.z +
	   tore->dist * tore->dist -
	   tore->rad * tore->rad) -
	  8.0 * tore->dist * tore->dist *
	  (s->ray.new_eye.x * s->ray.vct->x +
	   s->ray.new_eye.y * s->ray.vct->y));
}

inline double		solv_tor_e(t_rt *s, t_tore *tore)
{
  return ((s->ray.new_eye.x * s->ray.new_eye.x +
	   s->ray.new_eye.y * s->ray.new_eye.y +
	   s->ray.new_eye.z * s->ray.new_eye.z +
	   tore->dist * tore->dist -
	   tore->rad * tore->rad) *
	  (s->ray.new_eye.x * s->ray.new_eye.x +
	   s->ray.new_eye.y * s->ray.new_eye.y +
	   s->ray.new_eye.z * s->ray.new_eye.z +
	   tore->dist * tore->dist -
	   tore->rad * tore->rad) -
	  4.0 * tore->dist * tore->dist *
	  (s->ray.new_eye.x * s->ray.new_eye.x +
	   s->ray.new_eye.y * s->ray.new_eye.y));
}

void		inter_tore(t_rt *s, t_tore *tore)
{
  t_4order	solv;

  s->ray.new_eye.x = s->ray.eye.x - tore->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - tore->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - tore->pos.z;
  rotation(&s->rotation, s->ray.vct, &tore->rot);
  rotation(&s->rotation, &s->ray.new_eye, &tore->rot);
  /* printf("VECT X : %f && EYE X : %f\nVECT Y : %f && EYE Y : %f\n VECT Z : %f&& EYE Z: %f\n", s->ray.vct->x, s->ray.new_eye.x, s->ray.vct->y, s->ray.new_eye.y, s->ray.vct->z, s->ray.new_eye.z); */
  solv.a =
    (s->ray.vct->x * s->ray.vct->x +
     s->ray.vct->y * s->ray.vct->y +
     s->ray.vct->z * s->ray.vct->z) *
    (s->ray.vct->x * s->ray.vct->x +
     s->ray.vct->y * s->ray.vct->y +
     s->ray.vct->z * s->ray.vct->z);
  solv.b = solv_tor_b(s);
  solv.c = solv_tor_c(s, tore);
  solv.d = solv_tor_d(s, tore);
  solv.e = solv_tor_e(s, tore);
  /* printf("SOLVA : %f\nSOLV B : %f\nSOLV C : %f\n SOLV D : %f\n SOLV E : %f\n", solv.a, solv.b, solv.c, solv.d, solv.e); */
  solv.root1 = -1;
  solv.root2 = -1;
  solv.root3 = -1;
  solv.root4 = -1;
  solver_pqr(&solv);
  attribute_root(s, &solv);
  /* printf("ROOT1 : %f\nROOT2 : %f\n ROOT3 : %f\n ROOT4 : %f\n", s->hit.k1, s->hit.k2, s->hit.k3, s->hit.k4); */
}
