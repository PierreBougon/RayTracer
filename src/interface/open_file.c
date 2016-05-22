/*
** open_file.c for open in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 23 15:24:05 2016 bougon_p
** Last update Sun May 22 17:57:37 2016 benjamin duhieu
*/

#include "raytracer.h"

static void	reset_text_open(t_data *data)
{
  data->itfc.open.need_open = false;
  my_bzero(data->itfc.open.file, FILE_LEN);
  data->itfc.open.curs = 0;
}

static	void	reset_var_open(t_data *data)
{
  data->rt.pos = center_rt(&data->rt);
  data->itfc.open.need_open = false;
  my_bzero(data->itfc.open.file, FILE_LEN);
  data->rt.live = true;
  fill_pxlarray(data->rt.img, 0xFF262626);
  live_display(&data->rt);
  data->itfc.open.curs = 0;
}

int	f_open_file(t_data *data)
{
  char	*name;

  if (data->itfc.open.need_open && data->itfc.open.curs > 0)
    {
      my_strcat(data->itfc.open.file, ".ini");
      if (!(name = my_strdup("assets/scenes/")))
	return (1);
      name = myrealloc(name, my_strlen(data->itfc.open.file));
      my_strcat(name, data->itfc.open.file);
      if (load_file(&data->rt, name) == -1)
        return (reset_text_open(data),
		my_puterr("Load : Could not load the scene"));
      if (data->rt.img != NULL)
	bunny_delete_clipable(&data->rt.img->clipable);
      if ((data->rt.img =
	   bunny_new_pixelarray(data->rt.width,	data->rt.height)) == NULL)
        return (reset_text_open(data),
		my_puterr("Could not perform bunny_new_pixelarray"), 1);
      reset_var_open(data);
      bunny_free(name);
      data->itfc.button[OPEN] = false;
    }
  else
    text(data->itfc.open.file, &data->itfc, TXT_X, TXT_Y);
  return (0);
}
