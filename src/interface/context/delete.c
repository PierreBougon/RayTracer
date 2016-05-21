/*
** delete.c for delete in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 20:18:36 2016 bougon_p
** Last update Sat May 21 17:46:56 2016 bougon_p
*/

#include "raytracer.h"

static	void	del_first(t_data *data, t_object *obj, t_object **save)
{
  data->rt.obj = obj->next;
  *save = data->rt.obj;
  obj->next->prev = NULL;
  bunny_free(obj);
}

static	void	del_last(t_object *obj)
{
  obj->prev->next = NULL;
  bunny_free(obj);
}

static	void	del_mid(t_object *obj)
{
  obj->prev->next = obj->next;
  obj->next->prev = obj->prev;
  bunny_free(obj);
}

static	void	del_alone(t_data *data, t_object *obj)
{
  bunny_free(obj);
  data->rt.obj = NULL;
}

int	delete_form(t_data *data)
{
  t_object	*obj;
  t_object	*save;

  if (data->click_action)
    {
      obj = data->itfc.obj_selected;
      save = data->rt.obj;
      if (data->itfc.obj_selected)
	{
	  if (!obj->prev && obj->next)
	    del_first(data, obj, &save);
	  else if (obj->prev && !obj->next)
	    del_last(obj);
	  else if (obj->prev && obj->next)
	    del_mid(obj);
	  else if (!data->rt.obj)
	    del_alone(data, obj);
	  reset_select(save, data);
	}
    }
  data->click_action = false;
  return (0);
}
