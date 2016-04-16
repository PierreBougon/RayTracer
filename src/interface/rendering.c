/*
** rendering.c for RENDER in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 16 18:34:35 2016 bougon_p
** Last update Sat Apr 16 18:42:27 2016 bougon_p
*/

#include "raytracer.h"

void	start_rendering(t_data *data)
{
  if (data->rt.img != NULL)
    display(&data->rt);
  /*
  ** /!\
  **
  ** Tmp instruction -> Kick that when the rendering is not
  ** a OS anymore !
  */
  data->itfc.rendering = false;

  data->itfc.rendered = true;
}
