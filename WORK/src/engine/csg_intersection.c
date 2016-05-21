/*
** csg_intersection.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri May 20 22:29:39 2016 romain samuel
** Last update Sat May 21 06:35:31 2016 romain samuel
*/

#include "raytracer.h"

void		set_del_intersection(t_inter *left)
{
  t_inter	*it_left;
  int		count1;
  int		count2;

  count1 = 0;
  count2 = 0;
  it_left = left->next;
  while (it_left != NULL)
    {
      it_left->del = 1;
      if (it_left->sub == 0 && it_left->exterior == 1)
	count1++;
      else if (it_left->sub == 0 && it_left->exterior == 0)
	count1--;
      else if (it_left->sub == 1 && it_left->exterior == 1)
	count2++;
      else
	count2--;
      if ((it_left->sub == 0 && it_left->exterior == 1 && count1 > 0 && count2 > 0) ||
	  (it_left->sub == 0 && it_left->exterior == 0 && count1 <= 0 && count2 > 0) ||
	  (it_left->sub == 1 && it_left->exterior == 1 && count2 > 0 && count1 > 0) ||
	  (it_left->sub == 1 && it_left->exterior == 0 && count2 <= 0 && count1 > 0))
	it_left->del = 0;
      it_left = it_left->next;
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
