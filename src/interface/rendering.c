/*
** rendering.c for RENDER in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 16 18:34:35 2016 bougon_p
** Last update Wed Apr 27 20:37:15 2016 bougon_p
*/

#include "raytracer.h"

/*
** Rendering function is actually a One Shot
** PreRendering is displaed in the calculus
** redered value is updated to the right state
*/
void	start_rendering(t_data *data)
{
  if (data->rt.img != NULL)
    {
      fill_pxlarray(data->rt.img, 0xFF262626);
      display(&data->rt, data);
    }
  data->itfc.rendering = false;
  data->itfc.rendered = true;
}
