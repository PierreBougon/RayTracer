/*
** csg_intersection.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri May 20 22:29:39 2016 romain samuel
** Last update Sun May 22 19:26:06 2016 marc brout
*/

#include "raytracer.h"

void		set_del_intersection(t_inter *left)
{
  t_inter	*i;
  int		ct1;
  int		ct2;

  ct1 = 0;
  ct2 = 0;
  i = left->next;
  while (i != NULL)
    {
      i->del = 1;
      if (i->sub == 0 && i->exterior == 1)
	ct1++;
      else if (i->sub == 0 && i->exterior == 0)
	ct1--;
      else if (i->sub == 1 && i->exterior == 1)
	ct2++;
      else
	ct2--;
      if ((i->sub == 0 && i->exterior == 1 && ct1 > 0 && ct2 > 0) ||
	  (i->sub == 0 && i->exterior == 0 && ct1 <= 0 && ct2 > 0) ||
	  (i->sub == 1 && i->exterior == 1 && ct2 > 0 && ct1 > 0) ||
	  (i->sub == 1 && i->exterior == 0 && ct2 <= 0 && ct1 > 0))
	i->del = 0;
      i = i->next;
    }
}

int		del_extern_inters(t_inter *left)
{
  t_inter	*it_left;

  it_left = left->next;
  while (it_left != NULL)
    {
      if (it_left->del == 1 && it_left != left)
	{
	  if ((it_left = delete_inter_elem(it_left)) == NULL)
	    return (1);
	}
      it_left = it_left->next;
    }
  return (0);
}

t_inter		*csg_intersection(t_inter *left, t_inter *right)
{
  t_inter	*it_right;
  t_inter	*it_left;

  if (right == NULL || right->next == NULL ||
      left == NULL || left->next == NULL)
    return (NULL);
  it_right = right->next;
  it_left = left->next;
  while (it_right)
    {
      it_right->sub = 1;
      it_right = it_right->next;
    }
  while (it_left)
    {
      it_left->sub = 0;
      it_left = it_left->next;
    }
  if (csg_merge_lists(left, right) == -1)
    return (NULL);
  set_del_intersection(left);
  del_extern_inters(left);
  return (left);
}
