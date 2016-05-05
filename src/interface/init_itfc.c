/*
** init_itfc.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 23:33:13 2016 bougon_p
** Last update Wed May  4 22:51:38 2016 bougon_p
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
       bunny_load_picture("assets/img/context_save.png")) == NULL ||
      (itfc->curs = bunny_load_picture("assets/img/curs.png")) == NULL)
    return (my_puterr("Could not perform bunny_load_picture"));
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

void	init_slide_pos(t_itfc *itfc, t_data *data)
{
  itfc->gen.acc_curs_aa.x = START_SLIDE_AA_X;
  itfc->gen.acc_curs_aa.y = START_SLIDE_AA_Y + HALF_CURS_Y;
  itfc->gen.acc_curs_amb.x = START_SLIDE_AMB_X +
    data->rt.opt.ambient * 175;
  itfc->gen.acc_curs_amb.y = START_SLIDE_AMB_Y + HALF_CURS_Y;
  itfc->gen.pos_curs_aa.x = (int)itfc->gen.acc_curs_aa.x +
    (data->rt.opt.aa * 1.75);
  itfc->gen.pos_curs_aa.y = (int)itfc->gen.acc_curs_aa.y;
  itfc->gen.pos_curs_amb.x = (int)itfc->gen.acc_curs_amb.x;
  itfc->gen.pos_curs_amb.y = (int)itfc->gen.acc_curs_amb.y;
  itfc->gen.needmoving = false;
}

int	init_itfc_data(t_itfc *itfc, t_data *data)
{
  itfc->layout = NULL;
  if (init_pix(itfc) == -1 || init_ftabs(itfc) == 1
      || init_open(itfc) == 1)
    return (-1);
  itfc->act_context = 0;
  itfc->context_pos.x = 131;
  itfc->context_pos.y = 70;
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
  init_slide_pos(itfc, data);
  return (0);
}
