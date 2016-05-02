/*
** matrices.c for rt2 in ~/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Apr 22 15:10:59 2016 marc brout
** Last update Sat Apr 23 19:07:49 2016 marc brout
*/

#include <math.h>
#include "raytracer.h"

void		init_cos_sin(t_rotation *rot)
{
  int		i;

  i = 0;
  while (i < 360)
    {
      rot->cos[i] = cos(RAD((double)i));
      rot->sin[i] = sin(RAD((double)i));
      ++i;
    }
}

void		init_matrices(t_rotation *rot)
{
  int		i;
  int		j;

  j = 0;
  while (j < 3)
    {
      i = 0;
      while (i < 3)
	{
	  rot->rotx[j][i] = 0;
	  rot->roty[j][i] = 0;
	  rot->rotz[j][i] = 0;
	  ++i;
	}
      ++j;
    }
  rot->rotx[1][1] = 1;
  rot->roty[2][2] = 1;
  rot->rotz[0][0] = 1;
}

void		set_rotx(t_rotation *rot, int teta)
{
  rot->rotx[0][0] = rot->cos[teta];
  rot->rotx[0][2] = rot->sin[teta];
  rot->rotx[2][0] = -rot->sin[teta];
  rot->rotx[2][2] = rot->cos[teta];
}

void		set_roty(t_rotation *rot, int teta)
{
  rot->roty[0][0] = rot->cos[teta];
  rot->roty[0][1] = -rot->sin[teta];
  rot->roty[1][0] = rot->sin[teta];
  rot->roty[1][1] = rot->cos[teta];
}

void		set_rotz(t_rotation *rot, int teta)
{
  rot->rotz[1][1] = rot->cos[teta];
  rot->rotz[1][2] = -rot->sin[teta];
  rot->rotz[2][1] = rot->sin[teta];
  rot->rotz[2][2] = rot->cos[teta];
}
