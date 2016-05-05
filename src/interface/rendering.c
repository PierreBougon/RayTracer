/*
** rendering.c for RENDER in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 16 18:34:35 2016 bougon_p
** Last update Thu May  5 15:16:12 2016 bougon_p
*/

#include "raytracer.h"

/*
** Rendering function is actually a One Shot
** PreRendering is displayed in the calculus
** redered value is updated to the right state
*/
int	start_rendering(t_data *data)
{
  if (data->rt.img != NULL)
    {
      fill_pxlarray(data->rt.img, 0xFF262626);
      data->rt.nb_coef = 1;
      data->ld.nb_coef = 1;
      data->ld.curr_line = 0;
      data->rt.r_pos.y = 0;
      data->ld.save_width = data->ld.loading->clipable.clip_width;
      data->ld.loading->clipable.clip_width = 1;
      if ((data->rt.shade.itab =
	   malloc(sizeof(double) * data->rt.opt.nb_rays_ss)) == NULL)
	return (1);
      display(&data->rt, data);
    }
  return (0);
}
