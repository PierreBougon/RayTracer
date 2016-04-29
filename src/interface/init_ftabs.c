/*
** init_ftabs.c for ftabs in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 15:43:21 2016 bougon_p
** Last update Fri Apr 29 01:19:08 2016 bougon_p
*/

#include "raytracer.h"

void	init_ptr_context(t_itfc *itfc)
{
  itfc->fct_context[0] = modif_form;
  itfc->fct_context[1] = add_form;
  itfc->fct_context[2] = sub_form;
  itfc->fct_context[3] = spotlight;
  itfc->fct_context[4] = new_scene;
  itfc->fct_context[5] = filters;
  itfc->fct_context[6] = gen_opt;
  itfc->fct_context[7] = save;
}

void	init_ptr_button(t_itfc *itfc)
{
  itfc->fct_button[0] = open_file;
  itfc->fct_button[1] = help;
  itfc->fct_button[2] = render;
  itfc->fct_button[3] = live;
}

void	init_ptr_state(t_itfc *itfc)
{
  itfc->fct_state[0] = mouse_state;
  itfc->fct_state[1] = move_state;
  itfc->fct_state[2] = rotate_state;
}

int	init_ptr_save(t_itfc *itfc)
{
  itfc->save.need_save = false;
  itfc->save.curs = 0;
  if ((itfc->save.file =
       malloc(sizeof(char) * FILE_LEN + 4 + 1)) == NULL)
    return (1);
  my_bzero(itfc->save.file, FILE_LEN + 1);
  itfc->save.save_state = NOTHING;
  itfc->save.fct_save[0] = nothing_selected;
  itfc->save.fct_save[1] = save_png;
  itfc->save.fct_save[2] = save_jpg;
  itfc->save.fct_save[3] = save_bmp;
  itfc->save.fct_save[4] = save_ini;
  return (0);
}

int	init_ptr_save_ini(t_itfc *itfc)
{
  itfc->save.fct_save_ini_name[0] = sphere_name;
  itfc->save.fct_save_ini_name[1] = cone_name;
  itfc->save.fct_save_ini_name[2] = cylinder_name;
  itfc->save.fct_save_ini_name[3] = plane_name;
  itfc->save.fct_save_ini_name[4] = light_name;
  return (0);
}

int	init_ftabs(t_itfc *itfc)
{
  int	i;

  i = 0;
  while (i < 19)
    itfc->button[i++] = false;
  itfc->button[0] = true;
  itfc->status = S_MOUSE;
  init_ptr_context(itfc);
  init_ptr_button(itfc);
  init_ptr_state(itfc);
  if (init_ptr_save(itfc) == 1)
    return (1);
  init_ptr_save_ini(itfc);
  return (0);
}
