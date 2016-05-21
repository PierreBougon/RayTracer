/*
** init_ftabs.c for ftabs in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 28 15:43:21 2016 bougon_p
** Last update Sat May 21 14:05:56 2016 bougon_p
*/

#include "raytracer.h"

void	init_ptr_set_size(t_itfc *itfc)
{
  itfc->fct_set_size[0] = set_full_size;
  itfc->fct_set_size[1] = set_high_size;
  itfc->fct_set_size[2] = set_hd_size;
  itfc->fct_set_size[3] = set_xga_size;
  itfc->fct_set_size[4] = set_vga_size;
}

void	init_ptr_key(t_itfc *itfc)
{
  itfc->key.key_move[0] = BKS_Z;
  itfc->key.key_move[1] = BKS_S;
  itfc->key.key_move[2] = BKS_Q;
  itfc->key.key_move[3] = BKS_D;
  itfc->key.f_key_move[0] = move_up;
  itfc->key.f_key_move[1] = move_down;
  itfc->key.f_key_move[2] = move_left;
  itfc->key.f_key_move[3] = move_right;
  itfc->key.key_rot[0] = BKS_UP;
  itfc->key.key_rot[1] = BKS_DOWN;
  itfc->key.key_rot[2] = BKS_LEFT;
  itfc->key.key_rot[3] = BKS_RIGHT;
  itfc->key.f_key_rot[0] = rot_up;
  itfc->key.f_key_rot[1] = rot_down;
  itfc->key.f_key_rot[2] = rot_left;
  itfc->key.f_key_rot[3] = rot_right;
}

void	init_ptr_resize(t_itfc *itfc)
{
  itfc->fct_resize[0] = resize_sphere;
  itfc->fct_resize[1] = resize_cylinder;
  itfc->fct_resize[2] = resize_cone;
  itfc->fct_resize[3] = resize_plan;
}

void	init_ptr_apply(t_itfc *itfc)
{
  itfc->fct_apply_image[0] = apply_sphere;
  itfc->fct_apply_image[1] = apply_cylinder;
  itfc->fct_apply_image[2] = apply_cone;
  itfc->fct_apply_image[3] = apply_plan;
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
  init_ptr_key(itfc);
  init_ptr_resize(itfc);
  init_ptr_apply(itfc);
  if (init_ptr_save(itfc) == 1)
    return (1);
  init_ptr_save_ini(itfc);
  init_ptr_set_size(itfc);
  return (0);
}
