/*
** init_main.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 23:20:17 2016 bougon_p
** Last update Thu Apr 14 00:15:46 2016 bougon_p
*/

#include "raytracer.h"

int	init_main_data(t_data *data)
{
  if ((data->win = bunny_start(WIN_WIDTH, WIN_HEIGHT,
			      false, "RAYTRACER")) == NULL)
    return (my_puterr("Could not perform bunny_start"));
  return (0);
}

int	init_rt_data(t_rt *rt, int argc, char **argv)
{
  rt->width = INIT_WIDTH;
  rt->height = INIT_HEIGHT;
  rt->img = NULL;
  if (argc == 2)
    {
      if ((rt->img = bunny_new_pixelarray(rt->width, rt->height)) == NULL)
	return (my_puterr("Could not perform bunny_new_pixelarray"));
      if (load_file(rt, argv[1]) == -1)
	return (-1);
      display(rt);
    }
  return (0);
}
