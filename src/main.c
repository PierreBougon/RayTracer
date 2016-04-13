/*
** main.c<RAYTRACER> for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Tue Apr  5 14:24:28 2016 romain samuel
** Last update Wed Apr 13 22:02:25 2016 bougon_p
*/

#include "raytracer.h"

t_bunny_response	my_key(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data)
{
  (void)data;
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response        mainloop(void *_data)
{
  t_rt			*rt;

  rt = _data;
  bunny_blit(&rt->win->buffer, &rt->img->clipable, 0);
  bunny_display(rt->win);
  return (GO_ON);
}

int	main(int argc, char **argv, char **env)
{
  t_rt	rt;

  if (*env == NULL)
    return (my_puterr("Invalid environment"));
  if (argc != 2)
    return (my_puterr("Usage: ./raytracer1 scene"));
  bunny_set_maximum_ram(50000000);
  if (load_file(&rt, argv[1]) == -1)
    return (-1);
  if ((rt.win = bunny_start(WIDTH, HEIGHT, false, "RAYTRACER")) == NULL)
    return (my_puterr("Could not perform bunny_start"));
  if ((rt.img = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (my_puterr("Could not perform bunny_new_pixelarray"));
  bunny_set_key_response((t_bunny_key)&my_key);
  bunny_set_loop_main_function(mainloop);
  display(&rt);
  bunny_loop(rt.win, 30, &rt);
  bunny_delete_clipable(&rt.img->clipable);
  bunny_stop(rt.win);
  return (0);
}
