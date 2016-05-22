/*
** csg_union.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Thu May 19 01:31:00 2016 romain samuel
** Last update Sat May 21 16:33:19 2016 romain samuel
*/

#include "raytracer.h"

int		csg_union(t_inter *left, t_inter *right)
{
  if (left == NULL)
    if ((left = create_inter_list()) == NULL)
      return (-1);
  if (csg_merge_lists(left, right) == -1)
    return (-1);
  return (0);
}
