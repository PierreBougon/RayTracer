/*
** text.c for text in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Apr 21 12:09:03 2016 bougon_p
** Last update Sun May 22 17:58:18 2016 benjamin duhieu
*/

#include "raytracer.h"

void	blit_char(t_text *text, t_bunny_picture *font, char ch)
{
  int	line;
  float	size_x;
  int	decalx;

  size_x = 18.55;
  decalx = 20;
  ch -= 32;
  if (ch < 0)
    return ;
  line = ch / CH_LINE;
  ch %= 32;
  if (ch == 0)
    font->clip_x_position = 0;
  else
    font->clip_x_position = ((ch - 1) * size_x) + decalx;
  font->clip_width = size_x;
  font->clip_y_position = (line * SIZE_Y) + FIRST_Y;
  font->clip_height = SIZE_Y;
  bunny_blit(&text->win->buffer, font, &text->txt_pos);
  text->txt_pos.x += size_x;
}

void			text(char *str, t_itfc *itfc, int x, int y)
{
  static unsigned int	curs = 0;
  int			i;
  int			size;

  itfc->txt.txt_pos.x = x;
  itfc->txt.txt_pos.y = y;
  size = my_strlen(str);
  i = 0;
  while (i < size)
    {
      blit_char(&itfc->txt, itfc->txt.font, str[i]);
      i++;
    }
  if (curs++ % 60 < 40)
    blit_char(&itfc->txt, itfc->txt.font, '|');
}

t_bunny_response	my_txtinput(uint32_t unicode,
				    void *_data)
{
  t_data	*data;

  data = _data;
  if (data->itfc.button[SAVE])
    {
      if (unicode == DELETE && data->itfc.save.curs > 0)
	data->itfc.save.file[--data->itfc.save.curs] = 0;
      else if (unicode == RETURN && data->itfc.save.curs > 0)
	data->itfc.save.need_save = true;
      else if (data->itfc.save.curs < FILE_LEN)
	data->itfc.save.file[data->itfc.save.curs++] = unicode;
    }
  else if (data->itfc.button[OPEN])
    {
      if (unicode == DELETE && data->itfc.open.curs > 0)
	data->itfc.open.file[--data->itfc.open.curs] = 0;
      else if (unicode == RETURN)
	data->itfc.open.need_open = true;
      else if (data->itfc.open.curs < FILE_LEN)
	data->itfc.open.file[data->itfc.open.curs++] = unicode;
    }
  return (GO_ON);
}
