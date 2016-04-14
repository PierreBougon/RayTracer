/*
** main.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:24:28 2016 romain samuel
** Last update Thu Apr 14 18:42:11 2016 bougon_p
*/

#include "raytracer.h"

t_bunny_response        my_click(t_bunny_event_state state,
				 t_bunny_mousebutton mbutton,
				 void *_data)
{
  t_data	*data;

  data = _data;
  if (mbutton == BMB_LEFT && state == GO_DOWN)
    check_all_buttons(&data->itfc);
  return (GO_ON);
}

t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       UNUSED void *_data)
{
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response        mainloop(void *_data)
{
  t_data			*data;
  UNUSED t_rt				*rt;
  UNUSED t_itfc			*itfc;

  data = _data;
  rt = &data->rt;
  itfc = &data->itfc;
  /* debug_pos(); */
  blit_clipables(data);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int argc, char **argv, char **env)
{
  t_data	data;

  if (*env == NULL)
    return (my_puterr("Invalid environment"));
  bunny_set_maximum_ram(100000000);
  if (init_main_data(&data) == -1 ||
      init_rt_data(&data.rt, argc, argv) == -1 ||
      init_itfc_data(&data.itfc) == -1)
    return (1);
  bunny_set_key_response(my_key);
  bunny_set_click_response(my_click);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, 30, &data);
  delete_all_clipables(&data);
  bunny_stop(data.win);
  return (0);
}
