/*
** solver.h for raytracer in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Apr 13 13:46:56 2016 marc brout
** Last update Wed Apr 13 13:56:23 2016 marc brout
*/

#ifndef SOLVER_H_
# define SOLVER_H_

typedef struct		s_2order
{
  double		a;
  double		b;
  double		c;
  double		delta;
  double		root1;
  double		root2;
}			t_2order;

#endif /* !SOLVER_H_ */
