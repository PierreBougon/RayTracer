/*
** check_workspace.c for check in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May 18 16:37:38 2016 bougon_p
** Last update Sun May 22 21:25:32 2016 benjamin duhieu
*/

#include "raytracer.h"

bool	check_workspace(const t_bunny_position *mpos, t_rt *rt)
{
  if (rt->img &&
      mpos->x > ((((MAX_WORK_SPACE_X - WORK_SPACE_X) / 2) + WORK_SPACE_X) -
                 (rt->img->clipable.clip_width / 2))
      && mpos->x < ((((MAX_WORK_SPACE_X - WORK_SPACE_X) / 2) +
		     WORK_SPACE_X) -
                    (rt->img->clipable.clip_width / 2) +
                    rt->img->clipable.clip_width)
      && mpos->y > ((((MAX_WORK_SPACE_Y - WORK_SPACE_Y) / 2) +
		     WORK_SPACE_Y) -
                    (rt->img->clipable.clip_height / 2))
      && mpos->y < ((((MAX_WORK_SPACE_Y - WORK_SPACE_Y) / 2) +
		     WORK_SPACE_Y) -
                    (rt->img->clipable.clip_height / 2)) +
      rt->img->clipable.clip_height)
    {
      return (true);
    }
  return (false);
}
