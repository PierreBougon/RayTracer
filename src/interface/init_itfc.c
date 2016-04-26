/*
** init_itfc.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 23:33:13 2016 bougon_p
** Last update Tue Apr 26 15:29:04 2016 bougon_p
*/

#include "raytracer.h"

int	init_pix(t_itfc *itfc)
{
  if ((itfc->layout =
       bunny_load_picture("assets/img/layout.png")) == NULL ||
      (itfc->context[0] =
       bunny_load_picture("assets/img/context_basic.png")) == NULL ||
      (itfc->context[1] =
       bunny_load_picture("assets/img/context_modifs.png")) == NULL ||
      (itfc->context[2] =
       bunny_load_picture("assets/img/context_addform.png")) == NULL ||
      (itfc->context[3] =
       bunny_load_picture("assets/img/context_delete.png")) == NULL ||
      (itfc->context[4] =
       bunny_load_picture("assets/img/context_spot.png")) == NULL ||
      (itfc->context[5] =
       bunny_load_picture("assets/img/context_scene.png")) == NULL ||
      (itfc->context[6] =
       bunny_load_picture("assets/img/context_basic.png")) == NULL ||
      (itfc->context[7] =
       bunny_load_picture("assets/img/context_genopt.png")) == NULL ||
      (itfc->context[8] =
       bunny_load_picture("assets/img/context_save.png")) == NULL)
    return (my_puterr("Could not perform bunny_load_picture"));
  return (0);
}

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

int	init_open(t_itfc *itfc)
{
  itfc->open.need_open = false;
  itfc->open.curs = 0;
  if ((itfc->open.file =
       malloc(sizeof(char) * FILE_LEN + 4 + 1)) == NULL)
    return (1);
  my_bzero(itfc->open.file, FILE_LEN + 1);
  return (0);
}

int	init_itfc_data(t_itfc *itfc, UNUSED int ac)
{
  int	i;

  itfc->layout = NULL;
  if (init_pix(itfc) == -1)
    return (-1);
  itfc->act_context = 0;
  itfc->context_pos.x = 131;
  itfc->context_pos.y = 70;
  i = 0;
  while (i < 19)
    itfc->button[i++] = false;
  itfc->button[0] = true;
  itfc->status = S_MOUSE;
  init_ptr_context(itfc);
  init_ptr_button(itfc);
  init_ptr_state(itfc);
  if (init_ptr_save(itfc) == 1 ||
      init_open(itfc) == 1)
    return (1);
  itfc->rendering = false;
  itfc->rendered = false;
  itfc->move.needmoving = false;
  itfc->left_click = false;
  if ((itfc->txt.font =
       bunny_load_picture("assets/img/incoshow.png")) == NULL)
    return (my_puterr("Could not perform bunny_load_picture"));
  if ((itfc->past.img =
       bunny_load_picture("assets/img/past.png")) == NULL)
    return (my_puterr("Could not perform bunny_load_picture"));
  itfc->past.pos.x = 0;
  itfc->past.pos.y = 0;
  itfc->add.need_form = false;
  return (0);
}
