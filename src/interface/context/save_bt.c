/*
** save_bt.c for save in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 21:58:12 2016 bougon_p
** Last update Thu Apr 28 16:17:30 2016 bougon_p
*/

#include "raytracer.h"

/*
** Use to save the RT pixelarray
** You can save as png / jpg / bmp
** You can also save as .ini to save your scene and reopen this as scene
*/
static	void	reset_txt(t_itfc *itfc)
{
  itfc->save.curs = 0;
  my_bzero(itfc->save.file, FILE_LEN);
  itfc->save.need_save = false;
}

static	void	check_which_save(int i, t_itfc *itfc)
{
  if (i == 0)
    {
      itfc->save.save_state = PNG;
      reset_txt(itfc);
    }
  else if (i == 1)
    {
      itfc->save.save_state = JPG;
      reset_txt(itfc);
    }
  else if (i == 2)
    {
      itfc->save.save_state = BMP;
      reset_txt(itfc);
    }
  else if (i == 3)
    {
      itfc->save.save_state = INI;
      reset_txt(itfc);
    }
}

int				save(t_data *data)
{
  int				i;
  int				decal;
  const	t_bunny_position	*mpos;
  t_itfc			*itfc;

  itfc = &data->itfc;
  i = 0;
  mpos = data->itfc.mpos;
  decal = 35;
  while (i < NB_SAVE_BT)
    {
      if (mpos->x > (SAVE_FIRST_BT_X)
	  && mpos->x < (SAVE_FIRST_BT_X) + SAVE_FIRST_BT_WDT
	  && mpos->y > SAVE_FIRST_BT_Y +
	  (SAVE_FIRST_BT_HGT * i) + (decal * i)
	  && mpos->y < (SAVE_FIRST_BT_Y
			+ (SAVE_FIRST_BT_HGT * i) +
			SAVE_FIRST_BT_HGT + (decal * i)))
	{
	  check_which_save(i, itfc);
	}
      i++;
    }
  return (0);
}
