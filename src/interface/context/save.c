/*
** save.c for SAVE in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 22 19:09:00 2016 bougon_p
** Last update Mon May  9 17:04:49 2016 bougon_p
*/

#include "raytracer.h"

int	save_png(t_data *data)
{
  if (data->itfc.save.need_save)
    {
      if (data->rt.img == NULL)
	my_puterr("Save: Could not find any image to save");
      else
	{
	  my_strcat(data->itfc.save.file, ".png");
	  bunny_save_pixelarray(data->rt.img, data->itfc.save.file);
	}
      data->itfc.save.need_save = false;
      my_bzero(data->itfc.save.file, FILE_LEN);
      data->itfc.save.curs = 0;
      data->itfc.button[SAVE] = false;
    }
  else
    text(data->itfc.save.file, &data->itfc, TXT_X, TXT_Y);
  return (0);
}

int	save_jpg(t_data *data)
{
  if (data->itfc.save.need_save)
    {
      if (data->rt.img == NULL)
	my_puterr("Save: Could not find any image to save");
      else
	{
	  my_strcat(data->itfc.save.file, ".jpg");
	  bunny_save_pixelarray(data->rt.img, data->itfc.save.file);
	}
      data->itfc.save.need_save = false;
      my_bzero(data->itfc.save.file, FILE_LEN);
      data->itfc.save.curs = 0;
      data->itfc.button[SAVE] = false;
    }
  else
    text(data->itfc.save.file, &data->itfc, TXT_X, TXT_Y);
  return (0);
}

int	save_bmp(t_data *data)
{
  if (data->itfc.save.need_save)
    {
      if (data->rt.img == NULL)
	my_puterr("Save: Could not find any image to save");
      else
	{
	  my_strcat(data->itfc.save.file, ".bmp");
	  bunny_save_pixelarray(data->rt.img, data->itfc.save.file);
	}
      data->itfc.save.need_save = false;
      my_bzero(data->itfc.save.file, FILE_LEN);
      data->itfc.save.curs = 0;
      data->itfc.button[SAVE] = false;
    }
  else
    text(data->itfc.save.file, &data->itfc, TXT_X, TXT_Y);
  return (0);
}

int	save_ini(t_data *data)
{
  if (data->itfc.save.need_save)
    {
      if (data->rt.img == NULL)
	my_puterr("Save: Could not find any scene to save");
      else
	{
	  my_strcat(data->itfc.save.file, ".ini");
	  save_new_ini(data);
	}
      data->itfc.save.need_save = false;
      my_bzero(data->itfc.save.file, FILE_LEN);
      data->itfc.save.curs = 0;
      data->itfc.button[SAVE] = false;
    }
  else
    text(data->itfc.save.file, &data->itfc, TXT_X, TXT_Y);
  return (0);
}
