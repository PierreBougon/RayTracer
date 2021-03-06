/*
** main.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:24:28 2016 romain samuel
** Last update Sun May 22 19:37:50 2016 benjamin duhieu
*/

#include "raytracer.h"

t_bunny_response	my_click(t_bunny_event_state state,
				 t_bunny_mousebutton mbutton,
				 void *_data)
{
  t_data	*data;

  data = _data;
  data->mbutton = mbutton;
  data->mstate = state;
  if (data->wait_click && mbutton == BMB_LEFT && state == GO_DOWN)
    {
      data->click_action = true;
      data->wait_click = false;
    }
  if (data->rt.live)
    data->itfc.fct_state[data->itfc.status](data, state, mbutton);
  if (data->itfc.askobj_click)
    move_stateobj(data, state, mbutton);
  if (mbutton == BMB_LEFT && state == GO_DOWN)
    {
      if (check_all_buttons(&data->itfc) == 1)
	return (EXIT_ON_SUCCESS);
      if (check_button_activated(&data->itfc, data) == 1)
	return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_bunny_response	my_wheel(int wheelid,
				 int delta,
				 void *_data)
{
  t_data	*data;

  data = _data;
  if (data->rt.live)
    {
      zoom(data, wheelid, delta);
      move_on_wheel(data, wheelid, delta);
    }
  return (GO_ON);
}

t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *_data)
{
  t_data		*data;

  data = _data;
  if (data->itfc.txt.writing)
    return (GO_ON);
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN)
    {
      check_key(data, state, keysym);
      if (data->itfc.rendered)
	keys_filter(keysym, _data);
    }
  return (GO_ON);
}

t_bunny_response	mainloop(void *_data)
{
  t_data			*data;
  UNUSED t_rt			*rt;
  UNUSED t_itfc			*itfc;

  data = _data;
  rt = &data->rt;
  itfc = &data->itfc;
  blit_clipables(data);
  if (data->itfc.rendering)
    {
      if ((display(&data->rt, data)) == -1)
	return (EXIT_ON_ERROR);
    }
  else
    {
      if (data->rt.live && data->rt.img != NULL)
	live_display(&data->rt);
      if (interface(data) == 1)
	return (EXIT_ON_SUCCESS);
    }
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int argc, char **argv, char **env)
{
  t_data	data;

  if (*env == NULL)
    return (my_puterr("Invalid environment"));
  else
    data.itfc.env = env;
  srand(time(NULL));
  bunny_set_maximum_ram(2000000000);
  if (init_main_data(&data) == -1 ||
      init_engine_ftabs(&data.rt.ftabs) == -1 ||
      init_rt_data(&data.rt, argc, argv) == -1 ||
      init_itfc_data(&data.itfc, &data) == -1)
    return (1);
  bunny_set_key_response(my_key);
  bunny_set_click_response(my_click);
  bunny_set_wheel_response(my_wheel);
  bunny_set_text_response(my_txtinput);
  bunny_set_loop_main_function(mainloop);
  if ((bunny_loop(data.win, 45, &data)) == EXIT_ON_ERROR)
    return (1);
  delete_all_clipables(&data);
  free_all(&data);
  bunny_stop(data.win);
  return (0);
}
