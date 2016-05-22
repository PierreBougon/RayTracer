/*
** create_csg_tab.c for rt2 in /home/brout_m/RENDU/INFOGRAPHIE/gfx_raytracer2
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sun May 22 17:48:40 2016 marc brout
** Last update Sun May 22 17:50:25 2016 marc brout
*/

#include "raytracer.h"

t_csg		**create_csg_tab(int len)
{
  t_csg		**tab;
  int		i;

  if ((tab = bunny_malloc(sizeof(t_csg *))) == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      if ((tab[i] = bunny_malloc(sizeof(t_csg))) == NULL)
	return (NULL);
      tab[i]->id = i + 1;
      tab[i]->type = -1;
      tab[i]->up = NULL;
      tab[i]->right = NULL;
      tab[i]->left = NULL;
      tab[i]->obj = NULL;
      i++;
    }
  return (tab);
}
