/*
** text_obj.c for text in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 20 15:31:43 2016 bougon_p
** Last update Fri May 20 16:54:23 2016 bougon_p
*/

#include "raytracer.h"

int	texture_obj(t_data* data)
{
  //change archi call it on click from the detect

  if (data->click_action)
    printf("TEXT OBJ \n");
  data->click_action = false;
  return (0);
}
