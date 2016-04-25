/*
** main.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:24:28 2016 romain samuel
** Last update Mon Apr 25 20:19:10 2016 bougon_p
*/

#include "raytracer.h"

t_bunny_response        my_click(t_bunny_event_state state,
				 t_bunny_mousebutton mbutton,
				 void *_data)
{
  t_data	*data;

  data = _data;
  data->mbutton = mbutton;
  data->mstate = state;
  if (data->rt.live)
    data->itfc.fct_state[data->itfc.status](data, state, mbutton);
  if (mbutton == BMB_LEFT && state == GO_DOWN)
    {
      if (check_all_buttons(&data->itfc) == 1)
	return (EXIT_ON_SUCCESS);
      check_button_activated(&data->itfc, data);
    }
  return (GO_ON);
}

t_bunny_response        my_wheel(int wheelid,
				 int delta,
				 void *_data)
{
  t_data	*data;
  t_acc		vec;

  data = _data;
  vec.x = 0;
  vec.y = 0;
  vec.z = 500;
  if (data->rt.live)
    {
      if (delta == 1 && wheelid == 0)
	{
	  rotate_x(&vec, (double)data->rt.eye.rot.x);
	  rotate_y(&vec, (double)data->rt.eye.rot.y);
	  rotate_z(&vec, (double)data->rt.eye.rot.z);
	  data->rt.eye.pos.x += vec.x;
	  data->rt.eye.pos.y += vec.y;
	  data->rt.eye.pos.z += vec.z;
	}
      else if (delta == -1 && wheelid == 0)
	{
	  vec.z = -500;
	  rotate_x(&vec, (double)data->rt.eye.rot.x);
	  rotate_y(&vec, (double)data->rt.eye.rot.y);
	  rotate_z(&vec, (double)data->rt.eye.rot.z);
	  data->rt.eye.pos.x += vec.x;
	  data->rt.eye.pos.y += vec.y;
	  data->rt.eye.pos.z += vec.z;
	}
      /* if (delta == 1 && wheelid == 1) */
      /* 	data->rt.eye.pos.x += 100; */
      /* else if (delta == -1 && wheelid == 1) */
      /* 	data->rt.eye.pos.x -= 100; */
    }
  return (GO_ON);
}

t_bunny_response        my_txtinput(uint32_t unicode,
				    void *_data)
{
  t_data	*data;

  data = _data;
  /* printf("%c => %d\n", unicode, unicode); */
  if (data->itfc.button[SAVE])
    {
      if (unicode == DELETE && data->itfc.save.curs > 0)
	data->itfc.save.file[--data->itfc.save.curs] = 0;
      else if (unicode == RETURN)
	data->itfc.save.need_save = true;
      else if (data->itfc.save.curs < FILE_LEN)
	data->itfc.save.file[data->itfc.save.curs++] = unicode;
    }
  else if (data->itfc.button[OPEN])
    {
      if (unicode == DELETE && data->itfc.open.curs > 0)
	data->itfc.open.file[--data->itfc.open.curs] = 0;
      else if (unicode == RETURN)
	data->itfc.open.need_open = true;
      else if (data->itfc.open.curs < FILE_LEN)
	data->itfc.open.file[data->itfc.open.curs++] = unicode;
    }
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
  UNUSED t_rt			*rt;
  UNUSED t_itfc			*itfc;

  data = _data;
  rt = &data->rt;
  itfc = &data->itfc;
  /* debug_pos(); */
  if (data->rt.live && data->rt.img != NULL)
    live_display(&data->rt);
  blit_clipables(data);
  if (interface(data) == 1)
    return (EXIT_ON_SUCCESS);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int argc, char **argv, char **env)
{
  t_data	data;

  if (*env == NULL)
    return (my_puterr("Invalid environment"));
  srand(time(NULL));
  bunny_set_memory_check(true);
  bunny_set_maximum_ram(100000000);
  if (init_main_data(&data) == -1 ||
      init_engine_ftabs(&data.rt.ftabs) == -1 ||
      init_rt_data(&data.rt, argc, argv) == -1 ||
      init_itfc_data(&data.itfc, argc) == -1)
    return (1);
  bunny_set_key_response(my_key);
  bunny_set_click_response(my_click);
  bunny_set_wheel_response(my_wheel);
  bunny_set_text_response(my_txtinput);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, 30, &data);
  delete_all_clipables(&data);
  free_all(&data);
  bunny_stop(data.win);
  return (0);
}
