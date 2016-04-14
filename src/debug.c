/*
** debug.c for DEBUG in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 14 00:19:11 2016 bougon_p
** Last update Thu Apr 14 00:23:06 2016 bougon_p
*/

#include "raytracer.h"
#include <stdio.h>

void			debug_pos()
{
  const t_bunny_position	*pos;

  pos = bunny_get_mouse_position();
  dprintf(2, "\n___POSX = %d\n___POSY = %d\n\n======\n", pos->x, pos->y);
}
