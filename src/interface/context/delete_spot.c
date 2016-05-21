/*
** delete_spot.c for del in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 17 15:30:36 2016 bougon_p
** Last update Thu May 19 22:18:05 2016 bougon_p
*/

#include "raytracer.h"

static	void	del_first(t_data *data, t_object *light, t_object **save)
{
  printf("DEL FIRST\n");
  data->rt.obj = light->next;
  light->next->prev = NULL;
  *save = data->rt.obj;
  bunny_free(light);
}

static	void	del_last(t_object *light)
{
  printf("DEL LAST\n");
  light->prev->next = NULL;
  bunny_free(light);
}

static	void	del_mid(t_object *light)
{
  printf("DEL MID\n");
  light->prev->next = light->next;
  light->next->prev = light->prev;
  bunny_free(light);
}

static	void	del_alone(t_data *data, t_object *light, t_object **save)
{
  printf("DEL ALONE\n");
  bunny_free(light);
  data->rt.obj = NULL;
  *save = data->rt.obj;
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
	    del_first(data, light, &save);
	  else if (light->prev && !light->next)
	    del_last(light);
	  else if (light->prev && light->next)
	    del_mid(light);
	  else if (!data->rt.obj)
	    del_alone(data, light, &save);
	  while (save && save->type != LIGHT)
	    save = save->next;
	  if (save && save->type == LIGHT)
	    data->itfc.light_selected = save;
	}
    }
  data->click_action = false;
  return (0);
}
