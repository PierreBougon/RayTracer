/*
** delete_spot.c for del in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 17 15:30:36 2016 bougon_p
** Last update Wed May 18 15:54:59 2016 bougon_p
*/

#include "raytracer.h"

static	void	del_first(t_data *data, t_object *light)
{
  data->rt.obj = light->next;
  light->next->prev = NULL;
  bunny_free(light);
}

static	void	del_last(t_data *data, t_object *light)
{
  light->prev->next = NULL;
  bunny_free(light);
}

static	void	del_mid(t_data *data, t_object *light)
{
  light->prev->next = light->next;
  light->next->prev = light->prev;
  bunny_free(light);
}

static	void	del_alone(t_data *data, t_object *light)
{
  bunny_free(light);
  data->rt.obj = NULL;
}

int		delete_spot(t_data *data)
{
  t_object	*light;
  t_object	*save;

  if (data->click_action)
    {
      light = data->itfc.light_selected;
      save = data->rt.obj;
      if (light)
	{
	  if (!light->prev && light->next)
	    del_first(data, light);
	  else if (light->prev && !light->next)
	    del_last(data, light);
	  else if (light->prev && light->next)
	    del_mid(data, light);
	  else if (!data->rt.obj)
	    del_alone(data, light);
	  while (save && save->type != LIGHT)
	    save = save->next;
	  data->itfc.light_selected = save;
	}
    }
  data->click_action = false;
  return (0);
}
