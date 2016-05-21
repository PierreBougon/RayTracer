/*
** quartic_order_solver.c for quartic
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon May  2 13:53:17 2016 benjamin duhieu
** Last update Sat May 21 21:52:43 2016 benjamin duhieu
*/

#include <stdio.h>
#include "raytracer.h"

void		put_root(t_2order *x1, t_2order *x2,
			 t_4order *solv)
{
  if (x1->tab[0])
    solv->root1 = x1->root1 - (solv->b / (4.0 * solv->a));
  if (x1->tab[1])
    solv->root2 = x1->root2 - (solv->b / (4.0 * solv->a));
  if (x2->tab[0])
    solv->root1 = x2->root1 - (solv->b / (4.0 * solv->a));
  if (x2->tab[1])
    solv->root2 = x2->root2 - (solv->b / (4.0 * solv->a));
}

void		resolv_root(t_4order *solv, t_3order *res,
			    double p, double q)
{
  t_2order	x1;
  t_2order	x2;
  double	a0;
  double	b0;

  a0 = sqrt(-p + 2.0 * res->root1);
  b0 = -q / (2.0 * a0);
  x1.root1 = -1;
  x1.root2 = -1;
  x1.a = 1.0;
  x1.b = -a0;
  x1.c = res->root1 - b0;
  second_order_solver(&x1);
  x2.root1 = -1.0;
  x2.root2 = -1.0;
  x2.a = 1.0;
  x2.b = a0;
  x2.c = res->root1 + b0;
  second_order_solver(&x1);
  put_root(&x1, &x2, solv);
}

void		q_is_not_nul(t_4order *solv, double p,
			     double q, double r)
{
  t_3order	res;

  res.root1 = -1;
  res.root2 = -1;
  res.root3 = -1;
  res.a = 8.0;
  res.b = -4.0 * p;
  res.c = -8.0 * r;
  res.d = (4.0 * r * p) - CARRE(q);
  cube_order_solver(&res);
  resolv_root(solv, &res, p, q);
}

/* void		root(t_4order *solv, double S, double q, double p) */
/* { */
/*   printf("p  : %f\n", p); */
/*   printf("SOLVER ROOT1 In SQUARE : %f\n", (-4.0 * CARRE(S)) - (2.0 * p) + (q / S)); */
/*   solv->root1 = (-solv->b / (4 * solv->a)) - S - */
/*     (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) + (q / S))); */
/*   solv->root2 = (-solv->b / (4 * solv->a)) - S + */
/*     (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) + (q / S))); */
/*   printf("SOLVER ROOT2 In SQUARE : %f\n", (-4.0 * CARRE(S)) - (2.0 * p) - (q / S)); */
/*   solv->root3 = (-solv->b / (4 * solv->a)) + S - */
/*     (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) - (q / S))); */
/*   solv->root4 = (-solv->b / (4 * solv->a)) + S + */
/*     (0.5 * sqrt((-4.0 * CARRE(S)) - (2.0 * p) - (q / S))); */
/* } */

/* void		delta_pos(t_4order *solv, double delta0, double delta1) */
/* { */
/*   double	p; */
/*   double	q; */
/*   double	teta; */
/*   double	S; */

/*   p = ((8.0 * solv->a * solv->c) - (3.0 * CARRE(solv->b))) / */
/*     (8.0 * CARRE(solv->a)); */
/*   q = ((CUBE(solv->b)) - (4.0 * solv->a * solv->b * solv->c) + */
/*        (8.0 * CARRE(solv->a) * solv->d)) / (8.0 * CUBE(solv->a)); */
/*   teta = acos((delta1) / (2.0 * sqrt(CUBE(delta0)))); */
/*   S = 0.5 * sqrt((-2.0 / 3.0) * p + */
/* 		 ((2.0 / (3.0 * solv->a)) * */
/* 		  sqrt(delta0) * cos(teta / 3.0))); */
/*   root(solv, S, q, p); */
/* } */

/* void		delta_nul(t_4order *solv, double delta0, double delta1) */
/* { */
/*   double	p; */
/*   double	q; */
/*   double	S; */
/*   double	Q; */
/*   double	test; */

/*   p = ((8.0 * solv->a * solv->c) - (3.0 * CARRE(solv->b))) / */
/*     (8.0 * CARRE(solv->a)); */
/*   q = ((CUBE(solv->b)) - (4.0 * solv->a * solv->b * solv->c) + */
/*        (8.0 * CARRE(solv->a) * solv->d)) / (8.0 * CUBE(solv->a)); */
/*   printf("\nSTEP 1 q: %f\nSTEP 2 q : %f\nSTEP 3 q: %f\nSTEP4 q : %f\nFINAL STEP : %f\n\n", */
/* 	 CUBE(solv->b), */
/* 	 (4.0 * solv->a * solv->b * solv->c), */
/* 	 (8.0 * CARRE(solv->a) * solv->d), */
/* 	 CUBE(solv->b) - (4.0 * solv->a * solv->b * solv->c), */
/* 	 CUBE(solv->b) - (4.0 * solv->a * solv->b * solv->c) + (8.0 * CARRE(solv->a) * solv->d)); */
/*   printf("\nIn Q CUBEroot: %f\n\n", (delta1 + sqrt((CARRE(delta1) - (4.0 * CUBE(delta0)))) / 2.0)); */
/*   if ((solv->delta < -0.00001 || solv->delta > 0.00001) && */
/*       delta0 > -0.00001 && delta0 < 0.00001) */
/*     { */
/*       test = (delta1 + sqrt((CARRE(delta1))) / 2.0); */
/*       if (test < 0.00001) */
/* 	{ */
/* 	  test = -test; */
/* 	  Q = -pow(test, 1.0 / 3.0); */
/* 	} */
/*       else */
/* 	Q = pow(test, 1.0 / 3.0); */
/*     } */
/*   else */
/*     { */
/*       test = (delta1 + sqrt((CARRE(delta1) - (4.0 * CUBE(delta0))))) / 2.0; */
/*       printf("===test ; %f===\n", test); */
/*       if (test < 0.00001) */
/* 	{ */
/* 	  test = -test; */
/* 	  Q = -pow(test, 1.0 / 3.0); */
/* 	} */
/*       else */
/* 	Q = pow(test, 1.0 / 3.0); */
/*     } */
/*   printf("===Q  : %f===\n\n\n", Q); */
/*   printf("In SquareRoot : %f \nSTEP Q/DELTA : %f\nSTEP 1/3A : %f\n", ((-2.0 / 3.0) * p) + */
/*   	 ((1.0 / (3.0 * solv->a)) * (Q + (delta0 / Q))), (Q + (delta0 / Q)), (1.0 / (3.0 * solv->a))); */
/*   S = 0.5 * sqrt(((-2.0 / 3.0) * p) + */
/* 		 ((1.0 / (3.0 * solv->a)) * (Q + (delta0 / Q)))); */
/*   if (S < 0.00001 && S > -0.00001) */
/*     { */
/*       test = (delta1 + sqrt((CARRE(delta1)))) / 2.0; */
/*       printf("===test2222 ; %f===\n", test); */
/*       if (test < 0.00001) */
/* 	{ */
/* 	  test = -test; */
/* 	  Q = -pow(test, 1.0 / 3.0); */
/* 	} */
/*       else */
/* 	Q = pow(test, 1.0 / 3.0); */
/*       printf("===Q2222  : %f===\n\n\n", Q); */
/*       S = 0.5 * sqrt(((-2.0 / 3.0) * p) + */
/* 		     ((1.0 / (3.0 * solv->a)) * (Q + (delta0 / Q)))); */
/*     } */
/*   printf("===S : %f && q : %f===\n", S, q); */
/*   root(solv, S, q, p); */
/* } */

/* int		resolv_4_degres(t_4order *solv) */
/* { */
/*   double	delta0; */
/*   double	delta1; */

/*   if (solv->a > -0.00001 && solv->a < 0.00001) */
/*     return (0); */
/*   delta0 = CARRE(solv->c) - (3.0 * solv->b * solv->d) + */
/*     (12.0 * solv->a * solv->e); */
/*   delta1 = (2.0 * CUBE(solv->c)) - (9.0 * solv->b * solv->c * solv->d) + */
/*     (27.0 * CARRE(solv->b) * solv->e) + (27.0 * solv->a * CARRE(solv->d)) - */
/*     (72.0 * solv->a * solv->c * solv->e); */
/*   printf("\ndelta0: %f && delta1 : %f\n", delta0, delta1); */
/*   solv->delta = (CARRE(delta1) - (4.0 * CUBE(delta0))) / (-27.0); */
/*   printf("\nDelta = %f && delta1² : %f && 4delta0³ : %f\n", solv->delta, CARRE(delta1), 4.0 * CUBE(delta0)); */
/*   if (solv->delta > 0.00001) */
/*     delta_pos(solv, delta0, delta1); */
/*   else */
/*     delta_nul(solv, delta0, delta1); */
/*   return (0); */
/* } */
