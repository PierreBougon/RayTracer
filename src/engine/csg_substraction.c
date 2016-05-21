/*
** csg_substraction.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri May 20 12:09:22 2016 romain samuel
** Last update Sat May 21 20:47:51 2016 romain samuel
*/

#include "raytracer.h"

static int	check_sub_position(t_inter *start, t_inter *end)
{
  t_inter	*it;
  int		count;

  it = start->next;
  count = 0;
  while (it != end->next)
    {
      if (it->sub == 0)
	{
	  if (it->exterior == 0)
	    count--;
	  else
	    count++;
	}
      it = it->next;
    }
  if (count <= 0)
    return (0);
  else
    return (1);
}

int		set_del_subs(t_inter *left)
{
  t_inter	*it_left;

  it_left = left->next;
  while (it_left != NULL)
    {
      if (it_left->sub == 1)
	{
	  if (check_sub_position(left, it_left) == 0)
	    it_left->del = 1;
	  else
	    it_left->del = 0;
	}
      it_left = it_left->next;
    }
  return (0);
}

int
del_subs(t_inter *left)
{
  t_inter	*it_left;

  it_left = left->next;
  while (it_left != NULL)
    {
      if (it_left->del == 1)
	{
	  if ((it_left = delete_inter_elem(it_left)) == NULL)
	    return (1);
	}
      else if (it_left->sub == 1)
	{
	  if (it_left->exterior == 1)
	    it_left->exterior = 0;
	  else
	    it_left->exterior = 1;
	}
      it_left = it_left->next;
    }
  return (0);
}

int		set_del_inters(t_inter *left)
{
  t_inter	*it_left;
  int		a;

  it_left = left->next;
  a = 0;
  while (it_left != NULL)
    {
      it_left->del = 0;
      if (it_left->sub == 1 && a == 0)
	a = 1;
      else if (it_left->sub == 1 && a == 1)
	a = 0;
      if (a == 1 && it_left->sub == 0)
	it_left->del = 1;
      it_left = it_left->next;
    }
  return (0);
}

int		csg_substraction(t_inter *left, t_inter *right)
{
  t_inter	*it_right;
  t_inter	*it_left;

  if (left == NULL || left->next == NULL)
    return (-1);
  else if (right == NULL || right->next == NULL)
    return (0);
  it_right = right;
  it_left = left;
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
  if (csg_clean_second_list(right) == -1)
    return (-1);
  it_right = right->next;
  it_left = left;
  while (it_right)
    {
      printf("right_clean: k = %f, sub = %d, ext = %d, name = %s\n", it_right->k, it_right->sub, it_right->exterior, it_right->obj->name);
      it_right = it_right->next;
    }
  if (right->next == NULL)
    return (-1);
  if (csg_merge_lists(left, right) == -1)
    return (-1);
  it_left = left->next;
  while (it_left)
    {
      printf("left_merged: k = %f, sub = %d, ext = %d, name = %s\n", it_left->k, it_left->sub, it_left->exterior, it_left->obj->name);
      it_left = it_left->next;
    }
  if (set_del_inters(left) == -1)
    return (-1);
  it_left = left->next;
  while (it_left)
    {
      printf("left_del: k = %f, sub = %d, ext = %d, name = %s, del = %d\n", it_left->k, it_left->sub, it_left->exterior, it_left->obj->name, it_left->del);
      it_left = it_left->next;
    }
  if (set_del_subs(left) == -1)
    return (-1);
  /* it_left = left->next; */
  /* while (it_left) */
  /*   { */
  /*     printf("left_sub_del: k = %f, sub = %d, ext = %d, name = %s, del = %d\n", it_left->k, it_left->sub, it_left->exterior, it_left->obj->name, it_left->del); */
  /*     it_left = it_left->next; */
  /*   } */
  del_subs(left);
  return (0);
}
