/*
** delete.c for delete in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 16 20:18:36 2016 bougon_p
** Last update Thu May 19 21:47:45 2016 bougon_p
*/

#include "raytracer.h"

static	void	del_first(t_data *data, t_object *obj, t_object **save)
{
  printf("DEL FIRST\n");
  data->rt.obj = obj->next;
  *save = data->rt.obj;
  obj->next->prev = NULL;
  bunny_free(obj);
}

static	void	del_last(t_object *obj)
{
  printf("DEL LAST\n");
  obj->prev->next = NULL;
  bunny_free(obj);
}

static	void	del_mid(t_object *obj)
{
  printf("DEL MID\n");
  obj->prev->next = obj->next;
  obj->next->prev = obj->prev;
  bunny_free(obj);
}

static	void	del_alone(t_data *data, t_object *obj)
{
  printf("DEL ALONE\n");
  bunny_free(obj);
  data->rt.obj = NULL;
}

int	delete_form(t_data *data)
{
  t_object	*obj;
  t_object	*save;
  t_object	*tmp;

  if (data->click_action)
    {
      obj = data->itfc.obj_selected;
      save = data->rt.obj;
      tmp = save;
      printf("\n===LIST OBJ===\n");
      while (tmp)
	{
	  printf("type = %d\n", tmp->type);
	  tmp = tmp->next;
	}
      if (data->itfc.obj_selected)
	{
	  printf("Deleting form\n");
	  if (!obj->prev && obj->next)
	    del_first(data, obj, &save);
	  else if (obj->prev && !obj->next)
	    del_last(obj);
	  else if (obj->prev && obj->next)
	    del_mid(obj);
	  else if (!data->rt.obj)
	    del_alone(data, obj);
	  while (save && save->type == LIGHT)
	    save = save->next;
	  if (save && save->type != LIGHT)
	    data->itfc.obj_selected = save;
	  else
	    data->itfc.obj_selected = NULL;


	  tmp = data->itfc.obj_selected;
	  printf("\n===LIST OBJ===\n");
	  while (tmp)
	    {
	      printf("type = %d\n", tmp->type);
	      tmp = tmp->next;
	    }
	}
    }
  data->click_action = false;
  return (0);
}
