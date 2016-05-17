/*
** quartic_order_solver.c for quartic
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 13:53:17 2016 benjamin duhieu
** Last update Tue May 17 17:33:14 2016 benjamin duhieu
*/

#include <stdio.h>
#include "raytracer.h"

/* double		minus_resolv3(double a, double b, double c, double d) */
/* { */
/*   t_3order	res; */
/*   int		chk; */

/*   res.a = a; */
/*   res.b = b; */
/*   res.c = c; */
/*   res.d = d; */
/*   if ((chk = cube_order_solver(&res)) == 1) */
/*     return (res.root1); */
/*   else if (chk == 3) */
/*     { */
/*       if (res.root1 >= res.root2 && res.root1 >= res.root3) */
/* 	return (res.root1); */
/*       else if (res.root2 >= res.root3) */
/* 	return (res.root2); */
/*       else */
/* 	return (res.root3); */
/*     } */
/*   return (0); */
/* } */

/* void		select4(double *step, t_4order *solv) */
/* { */
/*   t_2order	sec; */
/*   int		chk; */

/*   sec.a = 1; */
/*   sec.b = step[1]; */
/*   sec.c = step[0] + step[2]; */
/*   if (!(chk = second_order_solver(&sec))) */
/*     solv->root1 = sec.root1 - solv->b / 4.0; */
/*   else if (chk == 1) */
/*     { */
/*       solv->root1 = sec.root1 - solv->b / 4.0; */
/*       solv->root2 = sec.root2 - solv->b / 4.0; */
/*     } */
/*   printf("\n|||CHK = %d\n", chk); */
/*   sec.a = 1; */
/*   sec.b = -step[1]; */
/*   sec.c = step[0] - step[2]; */
/*   if (!(chk = second_order_solver(&sec))) */
/*     solv->root3 = sec.root1 - solv->b / 4.0; */
/*   else if (chk == 1) */
/*     { */
/*       solv->root3 = sec.root1 - solv->b / 4.0; */
/*       solv->root4 = sec.root2 - solv->b / 4.0; */
/*     } */
/*   printf("\n|||CHK2 = %d\n", chk); */
/* } */

/* void		resolv_4_degres(t_4order *solv) */
/* { */
/*   double	tmp[3]; */
/*   double	step[3]; */

/*   solv->b = solv->b / solv->a; */
/*   solv->c = solv->c / solv->a; */
/*   solv->d = solv->d / solv->a; */
/*   solv->e = solv->e / solv->a; */
/*   printf("\na : %f \nb : %f \nc: %f \n d: %f\n e: %f\n===========================================================================================================================", solv->a, solv->b, solv->c, solv->d, solv->e); */
/*   tmp[0] = -(3.0 / 8.0) * CARRE(solv->b) + solv->c; */
/*   tmp[1] = ((1.0 / 8.0) * CUBE(solv->b)) - */
/*     ((1.0 / 2.0) * solv->b * solv->c) + solv->d; */
/*   tmp[2] = (-(3.0 / 256.0) * QUARTIC(solv->b)) + */
/*     ((1.0 / 16.0) * CARRE(solv->b) * solv->c) - */
/*     ((1.0 / 4.0) * solv->b * solv->d) + solv->e; */
/*   printf("\ntmp0 : %f \n tmp1 : %f \n tmp2: %f\n======================================================================================================================", tmp[0], tmp[1], tmp[2]); */
/*   step[0] = minus_resolv3(1, -(tmp[0] / 2), -tmp[2], */
/* 			  (1.0 / 2.0) * tmp[0] * tmp[2]) - */
/*     ((1.0 / 8.0) * CARRE(tmp[1])); */
/*   if (CARRE(step[0]) - tmp[2] > 0) */
/*     { */
/*       step[2] = sqrt(CARRE(step[0]) - tmp[2]); */
/*       step[1] = tmp[1] / (-2 * step[2]); */
/*       select4(step, solv); */
/*     } */
/*   printf("\nstep0 : %f \n step1 : %f \n step2 (sqrt(%f - tmp[0]) :%f): %f\n======================================================================================================================", step[0], step[1], CARRE(step[0]), CARRE(step[0]) - tmp[2], step[2]); */
/*   printf("\nk1 : %f \n k2 : %f \n k3: %f \n k4= %f\n======================================================================================================================", solv->root1, solv->root2, solv->root3, solv->root4); */
/* } */

void		root(t_4order *solv, double S, double q, double p)
{
  solv->root1 = (-solv->b / (4 * solv->a)) - S -
    (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) + (q / S)));
  solv->root2 = (-solv->b / (4 * solv->a)) - S +
    (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) + (q / S)));
  solv->root3 = (-solv->b / (4 * solv->a)) + S -
    (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) - (q / S)));
  solv->root4 = (-solv->b / (4 * solv->a)) + S +
    (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) - (q / S)));
}

void		delta_pos(t_4order *solv, double delta0, double delta1)
{
  double	p;
  double	q;
  double	teta;
  double	S;

  p = ((8.0 * solv->a * solv->c) - (3.0 * CARRE(solv->b))) /
    (8.0 * CARRE(solv->a));
  q = ((CUBE(solv->b)) - (4.0 * solv->a * solv->b * solv->c) +
       (8.0 * CARRE(solv->a) * solv->d)) / (8.0 * CUBE(solv->a));
  teta = acos((delta1) / (2.0 * sqrt(CUBE(delta0))));
  S = 0.5 * sqrt(((-2.0 / 3.0) * p) +
		 ((2.0 / (3.0 * solv->a)) * sqrt(delta0) * cos(teta / 3.0)));
  root(solv, S, q, p);
}

void		delta_nul(t_4order *solv, double delta0, double delta1)
{
  double	p;
  double	q;
  double	S;
  double	Q;

  p = ((8.0 * solv->a * solv->c) - (3.0 * CARRE(solv->b))) /
    (8.0 * CARRE(solv->a));
  q = ((CUBE(solv->b)) - (4.0 * solv->a * solv->b * solv->c) +
       (8.0 * CARRE(solv->a) * solv->d)) / (8.0 * CUBE(solv->a));
  if ((solv->delta < -0.00001 || solv->delta > 0.00001) &&
      delta0 > -0.00001 && delta0 < 0.00001)
    Q = pow((delta1 + sqrt((CARRE(delta1)))) / 2.0, 1.0 / 3.0);
  else
    Q = pow((delta1 + sqrt((CARRE(delta1) -
			    (4.0 * CUBE(delta0))))) / 2.0, 1.0 / 3.0);
  S = 0.5 * sqrt(((-2.0 / 3.0) * p) +
		 ((1.0 / (3.0 * solv->a)) * (Q + (delta0 / Q))));
  root(solv, S, q, p);
}

int		resolv_4_degres(t_4order *solv)
{
  double	delta0;
  double	delta1;

  if (solv->a > -0.00001 && solv->a < 0.00001)
    return (0);
  delta0 = CARRE(solv->c) - (3.0 * solv->b * solv->d) +
    (12.0 * solv->a * solv->e);
  /* printf("SETP 1: %f, STEP 2: %f , STEP 3 : %f\n\n", CARRE(solv->c), (3.0 * solv->b * solv->d), (12.0 * solv->a * solv->e)); */
  delta1 = (2.0 * CUBE(solv->c)) - (9.0 * solv->b * solv->c * solv->d) +
    (27.0 * CARRE(solv->b) * solv->e) + (27.0 * solv->a * CARRE(solv->d)) -
    (72.0 * solv->a * solv->c * solv->e);
  /* printf("\ndelta0: %f && delta1 : %f\n", delta0, delta1); */
  solv->delta = (CARRE(delta1) - (4.0 * CUBE(delta0))) / (-27.0);
  /* printf("\nDelta = %f && delta1² : %f && 4delta0³ : %f\n", solv->delta, CARRE(delta1), 4.0 * CUBE(delta0)); */
  if (solv->delta > 0.00001)
    delta_pos(solv, delta0, delta1);
  else
    delta_nul(solv, delta0, delta1);
  return (0);
}
