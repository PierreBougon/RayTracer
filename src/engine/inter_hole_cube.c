/*
** inter_hole_cube.c for hole_cube in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue May  3 13:42:58 2016 benjamin duhieu
** Last update Sat May 21 21:42:41 2016 benjamin duhieu
*/

#include "raytracer.h"

inline double		resolv_hole_b(t_rt *s)
{
  return (4 * ((CUBE(s->ray.vct->x) * s->ray.new_eye.x) +
	       (CUBE(s->ray.vct->y) * s->ray.new_eye.y) +
	       (CUBE(s->ray.vct->z) * s->ray.new_eye.z)));
}

inline double		resolv_hole_c(t_rt *s)
{
  return ((6 * ((CARRE(s->ray.vct->x) * CARRE(s->ray.new_eye.x)) +
		(CARRE(s->ray.vct->y) * CARRE(s->ray.new_eye.y)) +
		(CARRE(s->ray.vct->z) * CARRE(s->ray.new_eye.z)))) -
	  (5 * (CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
		CARRE(s->ray.vct->z))));
}

inline double		resolv_hole_d(t_rt *s)
{
  return ((4 * ((CUBE(s->ray.new_eye.x) * s->ray.vct->x) +
		(CUBE(s->ray.new_eye.y) * s->ray.vct->y) +
		(CUBE(s->ray.new_eye.z) * s->ray.vct->z))) -
	  (10 * ((s->ray.vct->x * s->ray.new_eye.x) +
		 (s->ray.vct->y * s->ray.new_eye.y) +
		 (s->ray.vct->z * s->ray.new_eye.z))));
}

inline double		resolv_hole_e(t_rt *s, t_hole_cube *cube)
{
  return (QUARTIC(s->ray.new_eye.x) + QUARTIC(s->ray.new_eye.y) +
	  QUARTIC(s->ray.new_eye.z) -
	  (5 * (CARRE(s->ray.new_eye.x) + CARRE(s->ray.new_eye.y) +
		CARRE(s->ray.new_eye.z))) + cube->rad);
}

void		inter_hole_cube(t_rt *s, t_hole_cube *cube)
{
  t_4order	solv;

  s->ray.new_eye.x = s->ray.eye.x - cube->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - cube->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - cube->pos.z;
  rotation(&s->rotation, s->ray.vct, &cube->rot);
  rotation(&s->rotation, &s->ray.new_eye, &cube->rot);
  /* printf("VECTOR : \nVCTX: %f && -POSx : %f \nVCTy : %f && -POSy : %f\nVCTz : %f && -POSz: %f\n\n", s->ray.vct->x, s->ray.new_eye.x, s->ray.vct->y, s->ray.new_eye.y, s->ray.vct->z, s->ray.new_eye.z); */
  solv.a = QUARTIC(s->ray.vct->x) + QUARTIC(s->ray.vct->y) +
    QUARTIC(s->ray.vct->z);
  solv.b = resolv_hole_b(s);
  solv.c = resolv_hole_c(s);
  solv.d = resolv_hole_d(s);
  solv.e = resolv_hole_e(s, cube);
  /* printf("TORE : \n-A : %f\n-B : %f\n-C : %f\n-D : %f\n-E : %f\n\n", */
  /* 	 solv.a, solv.b, solv.c, solv.d, solv.e); */
  solv.root1 = -1;
  solv.root2 = -1;
  solv.root3 = -1;
  solv.root4 = -1;
  solver_pqr(&solv);
  attribute_root(s, &solv);
  /* printf("RES: -R1 : %f\n    -R2 : %f\n     R3 : %f\n     -R4 : %f\n\n", s->hit.k1, s->hit.k2, s->hit.k3, s->hit.k4); */
}
