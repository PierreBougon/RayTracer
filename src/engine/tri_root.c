/*
** tri_root.c for tri_root in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May  4 13:40:57 2016 benjamin duhieu
** Last update Fri May 13 13:03:26 2016 benjamin duhieu
*/

#include "raytracer.h"

void		swap_value(double *first, double *second)
{
  double	tmp;

  tmp = *second;
  *second = *first;
  *first = tmp;
}

void		tri_inter(t_hit *inter)
{
  while (1)
    {
      if ((inter->k1 >= 0 && inter->k2 >= 0 &&
	   inter->k1 > inter->k2) ||
	  (inter->k1 < 0 && inter->k2 >= 0))
	{
	  swap_value(&inter->k1, &inter->k2);
	  continue;
	}
      if ((inter->k2 >= 0 && inter->k3 >= 0 &&
	   inter->k2 > inter->k3) ||
	  (inter->k2 < 0 && inter->k3 >= 0))
	{
	  swap_value(&inter->k2, &inter->k3);
	  continue;
	}
      if ((inter->k3 >= 0 && inter->k4 >= 0 &&
	   inter->k3 > inter->k4) ||
	  (inter->k4 < 0 && inter->k4 >= 0))
	{
	  swap_value(&inter->k3, &inter->k4);
	  continue;
	}
      break;
    }
}

void		attribute_root(t_rt *s, t_4order *solv)
{
  s->hit.k1 = solv->root1;
  s->hit.k2 = solv->root2;
  s->hit.k3 = solv->root3;
  s->hit.k4 = solv->root4;
  tri_inter(&s->hit);
}
