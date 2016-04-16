/*
** buttons.c for buttons in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 22:00:12 2016 bougon_p
** Last update Sat Apr 16 18:42:46 2016 bougon_p
*/

#include "raytracer.h"

int	render(UNUSED t_data *data)
{
  printf("FCT => RENDER\n");
  if (!data->itfc.rendering && !data->itfc.rendered)
    {
      data->itfc.rendering = true;
      start_rendering(data);
    }
  return (0);
}

int	live(t_data *data)
{
  printf("FCT => LIVE\n");
  data->rt.live = true;
  return (0);
}

int	open_file(UNUSED t_data *data)
{
  printf("FCT => OPEN\n");
  return (0);
}

int	help(UNUSED t_data *data)
{
  printf("FCT => HELP\n");
  return (0);
}
