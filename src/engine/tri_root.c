/*
** tri_root.c for tri_root in /home/duhieu_b/infographie/gfx_raytracer2
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed May  4 13:40:57 2016 benjamin duhieu
** Last update Thu May 19 23:29:11 2016 benjamin duhieu
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
	  (inter->k3 < 0 && inter->k4 >= 0))
	{
	  swap_value(&inter->k3, &inter->k4);
	  continue;
	}
      break;
    }
}

void		attribute_root(t_rt *s, t_4order *solv)
{
  /* if (solv->root1 >= 0) */
    s->hit.k1 = solv->root1;
  /* else */
  /*   s->hit.k1 = -1; */
  /* if (solv->root2 >= 0) */
    s->hit.k2 = solv->root2;
  /* else */
  /*   s->hit.k2 = -1; */
  /* if (solv->root3 >= 0) */
   s->hit.k3 = solv->root3;
  /* else */
  /*   s->hit.k3 = -1; */
  /* if (solv->root4 >= 0) */
    s->hit.k4 = solv->root4;
  /* else */
  /*   s->hit.k4 = -1; */
  tri_inter(&s->hit);
}
