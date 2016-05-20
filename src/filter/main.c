/*
** main.c for test in /home/brout_m/RENDU/INFOGRAPHIE/gfx_raytracer2/src/filter
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed May 18 20:58:09 2016 marc brout
** Last update Fri May 20 12:32:55 2016 marc brout
*/

#include "lapin.h"

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_data;

t_bunny_response	my_loop(void *_data)
{
  t_data		*data;

  data = _data;
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  srand(time(0));
  data.pix = bunny_load_pixelarray(av[1]);
  data.win = bunny_start(data.pix->CW, data.pix->CH, 0, "test");
  bunny_set_loop_main_function(my_loop);
  bunny_loop(data.win, 25, &data);
  return (0);
}
