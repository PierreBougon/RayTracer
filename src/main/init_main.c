/*
** init_main.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 23:20:17 2016 bougon_p
** Last update Tue Apr 19 12:18:11 2016 romain samuel
*/

#include "raytracer.h"
#include "live_engine.h"

int	init_main_data(t_data *data)
{
  if ((data->win = bunny_start_style(WIN_WIDTH, WIN_HEIGHT,
			      DEFAULT_WIN_STYLE, "RAYTRACER")) == NULL)
    return (my_puterr("Could not perform bunny_start"));
  return (0);
}

int	init_rt_data(t_rt *rt, int argc, char **argv)
{
  rt->width = INIT_WIDTH;
  rt->height = INIT_HEIGHT;
  rt->img = NULL;
  rt->live = true;
  if (argc == 2)
    {
      rt->live = false;
      if ((rt->img = bunny_new_pixelarray(rt->width, rt->height)) == NULL)
	return (my_puterr("Could not perform bunny_new_pixelarray"));
      if (load_file(rt, argv[1]) == -1)
	return (-1);
      fill_pxlarray(rt->img, 0xFF262626);
      /* For fast RT debugging */
      live_display(rt);
    }
  return (0);
}

int	init_engine_ftabs(t_ftab *ftabs)
{
  if ((ftabs->inters_ftab = malloc(sizeof(ftabs->inters_ftab) * 4)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  if ((ftabs->shadow_ftab = malloc(sizeof(ftabs->shadow_ftab) * 4)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  if ((ftabs->hit_ftab = malloc(sizeof(ftabs->hit_ftab) * 4)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  return (0);
}
