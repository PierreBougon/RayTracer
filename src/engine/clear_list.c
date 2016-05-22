/*
** clear_list.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr 12 21:54:13 2016 romain samuel
** Last update Sun May 22 16:27:10 2016 bougon_p
*/

#include "raytracer.h"

int		clear_list(t_object *root)
{
  t_object	*it;
  t_object	*tmp;

  if (root == NULL)
    return (0);
  it = root;
  while (it != NULL)
    {
      tmp = it;
      it = it->next;
      bunny_free(tmp);
    }
  return (0);
}

void	free_data(t_object *obj, t_ftab *ftabs)
{
  ftabs->fct_free[obj->type](obj);
  bunny_free(obj->name);
  bunny_free(obj->datas);
}

int		clear_full_list(t_object *root, t_ftab *ftabs)
{
  t_object	*it;
  t_object	*tmp;

  if (root == NULL)
    return (0);
  it = root;
  while (it != NULL)
    {
      tmp = it;
      it = it->next;
      free_data(tmp, ftabs);
      bunny_free(tmp);
    }
  return (0);
}
