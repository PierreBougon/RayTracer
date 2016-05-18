/*
** inter_complex.c for complex
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Apr 26 13:36:09 2016 benjamin duhieu
** Last update Wed May 18 16:40:16 2016 benjamin duhieu
*/

#include "raytracer.h"


inline double		solv_tor_b(t_rt *s)
{
  /* return ((4.0 * CUBE(s->ray.vct->x) * s->ray.new_eye.x) + */
  /* 	  (4.0 * CARRE(s->ray.vct->x) * s->ray.vct->y * s->ray.new_eye.y) + */
  /* 	  (4.0 * CARRE(s->ray.vct->x) * s->ray.vct->z * s->ray.new_eye.z) + */
  /* 	  (4.0 * s->ray.vct->x * CARRE(s->ray.vct->y) * s->ray.new_eye.x) + */
  /* 	  (4.0 * s->ray.vct->x * CARRE(s->ray.vct->z) * s->ray.new_eye.x) + */
  /* 	  (4.0 * CUBE(s->ray.vct->y) * s->ray.new_eye.y) + */
  /* 	  (4.0 * CARRE(s->ray.vct->y) * s->ray.vct->z * s->ray.new_eye.z) + */
  /* 	  (4.0 * s->ray.vct->y * CARRE(s->ray.vct->z) * s->ray.new_eye.y) + */
  /* 	  (4.0 * CUBE(s->ray.vct->z) * s->ray.new_eye.z)); */
  return (4.0*CUBE(s->ray.vct->x)*s->ray.new_eye.x
  	  + (4.0*CARRE(s->ray.vct->x)*s->ray.vct->y*s->ray.new_eye.y)
  	  + (4.0*CARRE(s->ray.vct->x)*s->ray.vct->z*s->ray.new_eye.z)
  	  + (4.0*s->ray.vct->x*CARRE(s->ray.vct->y)*s->ray.new_eye.x)
  	  + (4.0*s->ray.vct->x*CARRE(s->ray.vct->z)*s->ray.new_eye.x)
  	  + (4.0*CARRE(s->ray.vct->y)*s->ray.vct->z*s->ray.new_eye.z)
  	  + (4.0*CUBE(s->ray.vct->y)*s->ray.new_eye.y)
  	  + (4.0*s->ray.vct->y*CARRE(s->ray.vct->z)*s->ray.new_eye.y)
	  + (4.0*CUBE(s->ray.vct->z)*s->ray.new_eye.z));
}

inline double		solv_tor_c(t_rt *s, t_tore *tore)
{
  /* return ((2.0 * CARRE(tore->dist) * */
  /* 	   (-CARRE(s->ray.vct->x) - CARRE(s->ray.vct->y) + */
  /* 	    CARRE(s->ray.vct->z))) + */
  /* 	  (2.0 * CARRE(s->ray.vct->x) * */
  /* 	   (-CARRE(tore->rad) + (3.0 * CARRE(s->ray.new_eye.x)) + */
  /* 	    CARRE(s->ray.new_eye.y) + CARRE(s->ray.new_eye.z))) + */
  /* 	  (2.0 * CARRE(s->ray.vct->y) * */
  /* 	   (-CARRE(tore->rad) + CARRE(s->ray.new_eye.x) + */
  /* 	    (3.0 * CARRE(s->ray.new_eye.y)) + CARRE(s->ray.new_eye.z))) + */
  /* 	  (2.0 * CARRE(s->ray.vct->z) * */
  /* 	   (-CARRE(tore->rad) + CARRE(s->ray.new_eye.x) + */
  /* 	    CARRE(s->ray.new_eye.y) + (3.0 *CARRE(s->ray.new_eye.z)))) + */
  /* 	  (8.0 * ((s->ray.vct->x * s->ray.vct->y * s->ray.new_eye.x * */
  /* 		 s->ray.new_eye.y) + */
  /* 		(s->ray.vct->x * s->ray.vct->z * s->ray.new_eye.x * */
  /* 		 s->ray.new_eye.z) + */
  /* 		(s->ray.vct->y * s->ray.vct->z * */
  /* 		 CARRE(s->ray.new_eye.y))))); */
  /* return ((-2.0 * CARRE(tore->dist) * CARRE(s->ray.vct->x)) - (2.0 * CARRE(tore->dist) * CARRE(s->ray.vct->y)) + (2.0 * CARRE(tore->dist) * CARRE(s->ray.vct->z)) - (2.0 * CARRE(s->ray.vct->x) * CARRE(tore->rad)) + (6.0 * CARRE(s->ray.vct->x) * CARRE(s->ray.new_eye.x)) + (2.0 * CARRE(s->ray.vct->x) * CARRE(s->ray.new_eye.y)) + (2.0 * CARRE(s->ray.vct->x) * CARRE(s->ray.new_eye.z)) + (8.0 * s->ray.vct->x * s->ray.vct->y * s->ray.new_eye.x * s->ray.new_eye.y) + (8.0 * s->ray.vct->x * s->ray.vct->z * s->ray.new_eye.x * s->ray.new_eye.z) - (2.0 * CARRE(s->ray.vct->y) * CARRE(tore->rad)) + (2.0 * CARRE(s->ray.vct->y) * CARRE(s->ray.new_eye.x)) + (6.0 * CARRE(s->ray.vct->y) * CARRE(s->ray.new_eye.y)) + (2.0 * CARRE(s->ray.vct->y) * CARRE(s->ray.new_eye.z)) + (8.0 * s->ray.vct->y * s->ray.vct->z * s->ray.new_eye.y * s->ray.new_eye.z) - (2.0 * CARRE(s->ray.vct->z) * CARRE(tore->rad)) + (2.0 * CARRE(s->ray.vct->z) * CARRE(s->ray.new_eye.x)) + (2.0 * CARRE(s->ray.vct->z) * CARRE(s->ray.new_eye.y)) + (6.0 * CARRE(s->ray.vct->z) * CARRE(s->ray.new_eye.z))); */
  return (-2.0*CARRE(tore->dist)*CARRE(s->ray.vct->x)
  	  - (2.0*CARRE(tore->dist)*CARRE(s->ray.vct->y))
  	  + (2.0*CARRE(tore->dist)*CARRE(s->ray.vct->z))
  	  - (2.0*CARRE(s->ray.vct->x)*CARRE(tore->rad))
  	  + (6.0*CARRE(s->ray.vct->x)*CARRE(s->ray.new_eye.x))
  	  + (2.0*CARRE(s->ray.vct->x)*CARRE(s->ray.new_eye.y))
  	  + (2.0*CARRE(s->ray.vct->x)*CARRE(s->ray.new_eye.z))
  	  + (8.0*s->ray.vct->x*s->ray.vct->y*s->ray.new_eye.x*s->ray.new_eye.y)
  	  + (8.0*s->ray.vct->x*s->ray.vct->z*s->ray.new_eye.x*s->ray.new_eye.z)
  	  - (2.0*CARRE(s->ray.vct->y)*CARRE(tore->rad))
  	  + (2.0*CARRE(s->ray.vct->y)*CARRE(s->ray.new_eye.x))
  	  + (6.0*CARRE(s->ray.vct->y)*CARRE(s->ray.new_eye.y))
  	  + (2.0*CARRE(s->ray.vct->y)*CARRE(s->ray.new_eye.z))
  	  + (8.0*s->ray.vct->y*s->ray.vct->z*s->ray.new_eye.y*s->ray.new_eye.z)
  	  - (2.0*CARRE(s->ray.vct->z)*CARRE(tore->rad))
  	  + (2.0*CARRE(s->ray.vct->z)*CARRE(s->ray.new_eye.x))
  	  + (2.0*CARRE(s->ray.vct->z)*CARRE(s->ray.new_eye.y))
  	  + (6.0*CARRE(s->ray.vct->z)*CARRE(s->ray.new_eye.z)));
}

inline double		solv_tor_d(t_rt *s, t_tore *tore)
{
  /* return ((4.0 * CARRE(tore->dist) * ((-s->ray.vct->x * s->ray.new_eye.x) - */
  /* 				    (s->ray.vct->y * s->ray.new_eye.y) + */
  /* 				    (s->ray.vct->z * s->ray.new_eye.z))) + */
  /* 	  (4.0 * s->ray.vct->x * ((-CARRE(tore->rad) * s->ray.new_eye.x) + */
  /* 				CUBE(s->ray.new_eye.x) + */
  /* 				(s->ray.new_eye.x * */
  /* 				 CARRE(s->ray.new_eye.y)) + */
  /* 				(s->ray.new_eye.x * */
  /* 				 CARRE(s->ray.new_eye.z)))) + */
  /* 	  (4.0 * s->ray.vct->y * ((-CARRE(tore->rad) * s->ray.new_eye.y) + */
  /* 				CUBE(s->ray.new_eye.y) + */
  /* 				(s->ray.new_eye.y * */
  /* 				 CARRE(s->ray.new_eye.x)) + */
  /* 				(s->ray.new_eye.y * */
  /* 				 CARRE(s->ray.new_eye.z)))) + */
  /* 	  (4.0 * s->ray.vct->z * ((-CARRE(tore->rad) * */
  /* 				  s->ray.new_eye.z) + */
  /* 				CUBE(s->ray.new_eye.z) + */
  /* 				(s->ray.new_eye.z * */
  /* 				 CARRE(s->ray.new_eye.x)) + */
  /* 				(s->ray.new_eye.z * */
  /* 				 CARRE(s->ray.new_eye.y))))); */
  /* return ((-4.0 * CARRE(tore->dist) * s->ray.vct->x * s->ray.new_eye.x) - (4.0 * CARRE(tore->dist) * s->ray.vct->y * s->ray.new_eye.y) + (4.0 * CARRE(tore->dist) * s->ray.vct->z * s->ray.new_eye.z) - (4.0 * s->ray.vct->x * CARRE(tore->rad) * s->ray.new_eye.x) + (4.0 * s->ray.vct->x * CUBE(s->ray.new_eye.x)) + (4.0 * s->ray.vct->x * s->ray.new_eye.x * CARRE(s->ray.new_eye.y)) + (4.0 * s->ray.vct->x * s->ray.new_eye.x * CARRE(s->ray.new_eye.z)) - (4.0 * s->ray.vct->y * CARRE(tore->rad) * s->ray.new_eye.y) + (4.0 * s->ray.vct->y * CARRE(s->ray.new_eye.x) * s->ray.new_eye.y) + (4.0 * s->ray.vct->y * CUBE(s->ray.new_eye.y)) + (4.0 * s->ray.vct->y * s->ray.new_eye.y * CARRE(s->ray.new_eye.z)) - (4.0 * s->ray.vct->z * CARRE(tore->rad) * s->ray.new_eye.z) + (4.0 * s->ray.vct->z * CARRE(s->ray.new_eye.x) * s->ray.new_eye.z) + (4.0 * s->ray.vct->z * CARRE(s->ray.new_eye.y) * s->ray.new_eye.z) + (4.0 * s->ray.vct->z * CUBE(s->ray.new_eye.z))); */
  return (-4.0*CARRE(tore->dist)*s->ray.vct->x*s->ray.new_eye.x
  	  - (4.0*CARRE(tore->dist)*s->ray.vct->y*s->ray.new_eye.y)
  	  + (4.0*CARRE(tore->dist)*s->ray.vct->z*s->ray.new_eye.z)
  	  - (4.0*s->ray.vct->x*CARRE(tore->rad)*s->ray.new_eye.x)
  	  + (4.0*s->ray.vct->x*CUBE(s->ray.new_eye.x))
  	  + (4.0*s->ray.vct->x*s->ray.new_eye.x*CARRE(s->ray.new_eye.y))
  	  + (4.0*s->ray.vct->x*s->ray.new_eye.x*CARRE(s->ray.new_eye.z))
  	  - (4.0*s->ray.vct->y*CARRE(tore->rad)*s->ray.new_eye.y)
  	  + (4.0*s->ray.vct->y*CARRE(s->ray.new_eye.x)*s->ray.new_eye.y)
  	  + (4.0*s->ray.vct->y*CUBE(s->ray.new_eye.y))
  	  + (4.0*s->ray.vct->y*s->ray.new_eye.y*CARRE(s->ray.new_eye.z))
  	  - (4.0*s->ray.vct->z*CARRE(tore->rad)*s->ray.new_eye.z)
  	  + (4.0*s->ray.vct->z*CARRE(s->ray.new_eye.x)*s->ray.new_eye.z)
  	  + (4.0*s->ray.vct->z*CARRE(s->ray.new_eye.y)*s->ray.new_eye.z)
  	  + (4.0*s->ray.vct->z*CUBE(s->ray.new_eye.z)));
}

inline double		solv_tor_e(t_rt *s, t_tore *tore)
{
  /* return ((CARRE(tore->dist) * ((CARRE(tore->dist)) + */
  /* 				(-2.0 * (CARRE(tore->rad) + */
  /* 					 CARRE(s->ray.new_eye.x) + */
  /* 					 CARRE(s->ray.new_eye.y) - */
  /* 					 CARRE(s->ray.new_eye.z))))) + */
  /* 	  (CARRE(tore->rad) * ((CARRE(tore->rad)) + */
  /* 			       (-2.0 * (CARRE(s->ray.new_eye.x) + */
  /* 					CARRE(s->ray.new_eye.y) + */
  /* 					CARRE(s->ray.new_eye.z))))) + */
  /* 	  (CARRE(s->ray.new_eye.x) * ((CARRE(s->ray.new_eye.x)) + */
  /* 				      (2.0 * (CARRE(s->ray.new_eye.y) + */
  /* 					      CARRE(s->ray.new_eye.z))))) + */
  /* 	  (CARRE(s->ray.new_eye.y) * ((CARRE(s->ray.new_eye.y)) + */
  /* 				      2.0 * CARRE(s->ray.new_eye.z))) + */
  /* 	  QUARTIC(s->ray.new_eye.z)); */
  /* return (QUARTIC(tore->dist) - (2.0 * CARRE(tore->dist) * CARRE(tore->rad)) - (2.0 * CARRE(tore->dist) * CARRE(s->ray.new_eye.x)) - (2.0 * CARRE(tore->dist) * CARRE(s->ray.new_eye.y)) + (2.0 * CARRE(tore->dist) * CARRE(s->ray.new_eye.z)) + QUARTIC(tore->rad) - (2.0 * CARRE(tore->rad) * CARRE(s->ray.new_eye.x)) - (2.0 * CARRE(tore->rad) * CARRE(s->ray.new_eye.y)) - (2.0 * CARRE(tore->rad) * CARRE(s->ray.new_eye.z)) + QUARTIC(s->ray.new_eye.x) + (2.0 * CARRE(s->ray.new_eye.x) * CARRE(s->ray.new_eye.y)) + (2.0 * CARRE(s->ray.new_eye.x) * CARRE(s->ray.new_eye.z)) + QUARTIC(s->ray.new_eye.y) + (2.0 * CARRE(s->ray.new_eye.y) * CARRE(s->ray.new_eye.z)) + QUARTIC(s->ray.new_eye.z)); */
  return (QUARTIC(tore->dist)
  	  - (2.0*CARRE(tore->dist)*CARRE(tore->rad))
  	  - (2.0*CARRE(tore->dist)*CARRE(s->ray.new_eye.x))
  	  - (2.0*CARRE(tore->dist)*CARRE(s->ray.new_eye.y))
	  + (2.0*CARRE(tore->dist)*CARRE(s->ray.new_eye.z))
  	  + (QUARTIC(tore->rad))
  	  - (2.0*CARRE(tore->rad)*CARRE(s->ray.new_eye.x))
  	  - (2.0*CARRE(tore->rad)*CARRE(s->ray.new_eye.y))
  	  - (2.0*CARRE(tore->rad)*CARRE(s->ray.new_eye.z))
  	  + (QUARTIC(s->ray.new_eye.x))
  	  + (2.0*CARRE(s->ray.new_eye.x)*CARRE(s->ray.new_eye.y))
  	  + (2.0*CARRE(s->ray.new_eye.x)*CARRE(s->ray.new_eye.z))
	  + (QUARTIC(s->ray.new_eye.y))
	  + (2.0*CARRE(s->ray.new_eye.y)*CARRE(s->ray.new_eye.z))
	  + (QUARTIC(s->ray.new_eye.z)));
}

void		inter_tore(t_rt *s, t_tore *tore)
{
  t_4order	solv;

  s->ray.new_eye.x = s->ray.eye.x - tore->pos.x;
  s->ray.new_eye.y = s->ray.eye.y - tore->pos.y;
  s->ray.new_eye.z = s->ray.eye.z - tore->pos.z;
  rotation(&s->rotation, s->ray.vct, &tore->rot);
  rotation(&s->rotation, &s->ray.new_eye, &tore->rot);
  /* printf("VECTOR && Es->ray.new_eye.yE: \n-VCTx : %f && Es->ray.new_eye.yEx : %f\n-VCTy : %f && Es->ray.new_eye.yEy : %f\n-VCTz: %f && Es->ray.new_eye.yEz : %f\n\n", s->ray.vct->x, s->ray.new_eye.x, s->ray.vct->y, s->ray.new_eye.y, s->ray.vct->z, s->ray.new_eye.z); */
  solv.a = CARRE(CARRE(s->ray.vct->x) + CARRE(s->ray.vct->y) +
	   	 CARRE(s->ray.vct->z));
  /* solv.a = QUARTIC(s->ray.vct->x) + */
  /*   2.0*CARRE(s->ray.vct->x)*CARRE(s->ray.vct->y) + */
  /*   2.0*CARRE(s->ray.vct->x)*CARRE(s->ray.vct->z) + */
  /*   QUARTIC(s->ray.vct->y) + */
  /*   2.0*CARRE(s->ray.vct->y)*CARRE(s->ray.vct->z) + */
  /*   QUARTIC(s->ray.vct->z); */
  solv.b = solv_tor_b(s);
  solv.c = solv_tor_c(s, tore);
  solv.d = solv_tor_d(s, tore);
  solv.e = solv_tor_e(s, tore);
  /* printf("TORE : \n-A : %f\n-B : %f\n-C : %f\n-D : %f\n-E : %f\n\n", solv.a, solv.b, solv.c, solv.d, solv.e); */
  solv.root1 = -1;
  solv.root2 = -1;
  solv.root3 = -1;
  solv.root4 = -1;
  resolv_4_degres(&solv);
  attribute_root(s, &solv);
  /* printf("RES: -R1 : %f\n    -R2 : %f\n     R3 : %f\n     -R4 : %f\n\n", s->hit.k1, s->hit.k2, s->hit.k3, s->hit.k4); */
}
