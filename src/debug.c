/*
** debug.c for DEBUG in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 00:19:11 2016 bougon_p
** Last update Sun Apr 17 16:47:35 2016 bougon_p
*/

#include "raytracer.h"
#include <stdio.h>

void			debug_pos()
{
  const t_bunny_position	*pos;

  pos = bunny_get_mouse_position();
  dprintf(2, "\n___POSX = %d\n___POSY = %d\n\n======\n", pos->x, pos->y);
}

void	debug_tabbool(bool *tab)
{
  int	i;

  i = 0;
  while (i < 19)
    {
      if (tab[i])
	printf("#TRUE -> %d\n", i);
      else
	printf("#FALSE -> %d\n", i);
      i++;
    }
}
