/*
** csg_operations.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu May 19 01:24:04 2016 romain samuel
** Last update Sat May 21 19:31:50 2016 romain samuel
*/

#include "raytracer.h"

t_inter		*csg_operations(t_csg *it,
				t_inter *left,
				t_inter *right)
{
  t_inter	*it_left;
  t_inter	*it_right;

  printf("BEFORE:\n");
  if (left != NULL)
    {
      it_left = left->next;
      while (it_left)
  	{
  	  printf("left: k = %f, name = %s\n", it_left->k, it_left->obj->name);
  	  it_left = it_left->next;
  	}
    }
  if (right != NULL)
    {
      it_right = right->next;
      while (it_right)
  	{
  	  printf("right: k = %f, name = %s\n", it_right->k, it_right->obj->name);
  	  it_right = it_right->next;
  	}
    }
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
  printf("AFTER:\n");
  if (left != NULL)
    {
      it_left = left->next;
      while (it_left)
  	{
  	  printf("left: k = %f, name = %s\n", it_left->k, it_left->obj->name);
  	  it_left = it_left->next;
  	}
    }
  return (left);
}
