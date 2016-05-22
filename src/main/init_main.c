/*
** init_main.c for init in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Apr 13 23:20:17 2016 bougon_p
** Last update Sun May 22 23:12:07 2016 romain samuel
*/

#include "raytracer.h"
#include "live_engine.h"

int	init_main_data(t_data *data)
{
  init_array(data);
  if ((data->win = bunny_start(WIN_WIDTH, WIN_HEIGHT,
			       false, "RAYTRACER")) == NULL)
    return (my_puterr("Could not perform bunny_start"));
  if ((data->ld.loading =
       bunny_new_pixelarray(LOADING_WDT, LOADING_HGT)) == NULL)
    return (my_puterr("Could not perform bunny_new_pixelarray"));
  fill_pxlarray(data->ld.loading, BLUE_LOAD);
  data->ld.pos.x = LOADING_X;
  data->ld.pos.y = LOADING_Y;
  data->ld.coef_load = 14.5;
  data->itfc.txt.win = data->win;
  data->wait_click = false;
  data->click_action = false;
  return (0);
}

t_bunny_position	center_rt(t_rt *rt)
{
  t_bunny_position	pos;

  pos.x = (((MAX_WORK_SPACE_X - WORK_SPACE_X) / 2) + WORK_SPACE_X) -
    (rt->img->clipable.clip_width / 2);
  pos.y = (((MAX_WORK_SPACE_Y - WORK_SPACE_Y) / 2) + WORK_SPACE_Y) -
    (rt->img->clipable.clip_height / 2);
  return (pos);
}

int	init_rt_data(t_rt *rt, int argc, char **argv)
{
  rt->width = FULL_WIDTH;
  rt->height = FULL_HEIGHT;
  rt->img = NULL;
  rt->select = true;
  rt->live = true;
  rt->coef_load = (float)rt->height / 100.0f;
  init_cos_sin(&rt->rotation);
  init_matrices(&rt->rotation);
  rt->obj = NULL;
  rt->opt.aa = 1;
  rt->r_pos.x = 0;
  if (argc == 2)
    {
      if ((rt->img = bunny_new_pixelarray(rt->width, rt->height)) == NULL)
	return (my_puterr("Could not perform bunny_new_pixelarray"));
      if (load_file(rt, argv[1]) == -1)
	return (-1);
      rt->pos = center_rt(rt);
      fill_pxlarray(rt->img, 0xFF262626);
    }
  return (0);
}

static void	init_fct_free(t_ftab *ftabs)
{
  ftabs->fct_free[LIGHT] = free_light;
  ftabs->fct_free[SPHERE] = free_sphere;
  ftabs->fct_free[CYLINDER] = free_cylinder;
  ftabs->fct_free[CONE] = free_cone;
  ftabs->fct_free[PLANE] = free_plane;
  ftabs->fct_free[TORE] = free_tore;
  ftabs->fct_free[BOX] = free_box;
  ftabs->fct_free[HOLE_CUBE] = free_hole_cube;
  ftabs->fct_free[HYPER] = free_hyper;
  ftabs->fct_free[PARAB] = free_parab;
  ftabs->fct_free[CSG] = free_csg;
}

int		init_engine_ftabs(t_ftab *ftabs)
{
  if ((ftabs->inters_ftab =
       bunny_malloc(sizeof(ftabs->inters_ftab) * NB_OBJ)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  if ((ftabs->csg_ftab =
       bunny_malloc(sizeof(ftabs->inters_ftab) * 5)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  if ((ftabs->shadow_ftab =
       bunny_malloc(sizeof(ftabs->shadow_ftab) * 11)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  if ((ftabs->hit_ftab =
       bunny_malloc(sizeof(ftabs->hit_ftab) * NB_OBJ)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  if ((ftabs->tex_ftab =
       bunny_malloc(sizeof(ftabs->tex_ftab) * 8)) == NULL)
    return (my_puterr("Could not malloc ftabs"));
  init_fct_free(ftabs);
  return (0);
}
