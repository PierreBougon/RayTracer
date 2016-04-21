/*
** save.c for save in /home/bougon_p/rendu/gfx_raytracer2
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Apr 15 21:58:12 2016 bougon_p
** Last update Wed Apr 20 16:34:41 2016 bougon_p
*/

#include "raytracer.h"

/*
** Use to save the RT pixelarray
** You can save as png / jpg / bmp
** You can also save as .ini to save your scene and reopen this as scene
*/

int				save(t_data *data)
{
  int				i;
  int				decal;
  const	t_bunny_position	*mpos;

  /* printf("FCT => SAVE\n"); */
      i = 0;
      mpos = data->itfc.mpos;
      decal = 35;
      while (i < NB_SAVE_BT)
	{
	  if (mpos->x > (SAVE_FIRST_BT_X )
	      && mpos->x < (SAVE_FIRST_BT_X) + SAVE_FIRST_BT_WDT
	      && mpos->y > SAVE_FIRST_BT_Y +
	      (SAVE_FIRST_BT_HGT * i) + (decal * i)
	      && mpos->y < (SAVE_FIRST_BT_Y
			    + (SAVE_FIRST_BT_HGT * i) +
			    SAVE_FIRST_BT_HGT + (decal * i)))
	    {
	      if (i == 0)
		{
		  bunny_save_pixelarray(data->rt.img, "test.png");
		}
	      if (i == 1)
		{
		  bunny_save_pixelarray(data->rt.img, "test.jpg");
		}
	      if (i == 2)
		{
		  bunny_save_pixelarray(data->rt.img, "test.bmp");
		}
	      if (i == 3)
		{
		  printf("INI HIT\n");
		}
	    }
	  i++;
	}
  return (0);
}
