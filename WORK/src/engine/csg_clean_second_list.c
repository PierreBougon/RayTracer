/*
** csg_cleanèsecond_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri May 20 13:02:06 2016 romain samuel
** Last update Fri May 20 23:00:44 2016 romain samuel
*/

#include "raytracer.h"

static int	is_exterior(t_inter *end, int count)
{
  if (end->exterior == 0)
    {
      if (count == 1)
	return (1);
      else
	return (0);
    }
  else
    {
      if (count == 0)
  	return (1);
      else
  	return (0);
    }
  return (0);
}

static int	count_exteriors(t_inter *start, t_inter *end)
{
  t_inter	*it;
  int		count;

  it = start;
  count = 0;
  while (it != end)
    {
      if (it->exterior == 0)
	count--;
      else
	count++;
      it = it->next;
    }
  return (is_exterior(end, count));
}

static int	csg_clean_doublons(t_inter *right)
{
  t_inter	*it;

  it = right->next;
  while (it != NULL && it->next != NULL)
    {
      if (it->k == it->next->k)
	delete_inter_elem(it->next);
      else
	it = it->next;
    }
  return (0);
}

int		csg_clean_second_list(t_inter *right)
{
  t_inter	*it;

  csg_clean_doublons(right);
  it = right->next;
  while (it->next != NULL)
    it = it->next;
  if (it == right->next || it == right)
    return (-1);
  while (it != NULL && it != right && it != right->next)
    {
      if (count_exteriors(right->next, it) == 0)
	{
	  if ((it = delete_inter_elem(it)) == NULL)
	    return (-1);
	}
      else
	it = it->prev;
    }
  return (0);
}
