/*
** csg_operations.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu May 19 01:24:04 2016 romain samuel
** Last update Sat May 21 21:54:06 2016 romain samuel
*/

#include "raytracer.h"

t_inter		*csg_operations(t_csg *it,
				t_inter *left,
				t_inter *right)
{
  if (it->type == 1)
    {
      if (left)
	{
	  if (csg_union(left, right) == -1)
	    return (NULL);
	}
      else
	return (right);
    }
  else if (it->type == 2)
    {
      if (csg_substraction(left, right) == -1)
	return (NULL);
    }
  else
    {
      if (csg_intersection(left, right) == NULL)
	return (NULL);
    }
  return (left);
}
