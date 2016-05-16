/*
** savebmp.c for rt in /home/brout_m/RENDU/INFOGRAPHIE/gfx_tekdoom/demo
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri May 13 18:48:54 2016 marc brout
** Last update Mon May 16 17:02:25 2016 marc brout
*/

#include "bmploader.h"

static void	init_head(t_head *head)
{
  my_bzero(head, sizeof(t_head), 0);
  ((unsigned short *)&head->head)[0] = 0x42;
  ((unsigned short *)&head->head)[1] = 0x4D;
  head->offset = sizeof(t_head) + sizeof(t_bmp);
}

static void	init_bmp(t_bmp *bmp, int width, int height)
{
  my_bzero(bmp, sizeof(t_bmp), 0);
  bmp->height = height;
  bmp->width = width;
}

static int	putcolor(t_bunny_pixelarray *pix, const int fd,
			 const int width)
{
  t_color	*pixels;
  t_col		col;
  int		x;
  int		y;

  y = pix->clipable.clip_height;
  pixels = pix->pixels;
  while (--y >= 0)
    {
      x = 0;
      while (x < width)
	{
	  col.alpha = pixels[x + y * width].argb[0];
	  col.b = pixels[x + y * width].argb[1];
	  col.r = pixels[x + y * width].argb[2];
	  col.a = pixels[x + y * width].argb[3];
	  if (write(fd, &col, sizeof(t_col)) < 0)
	    return (1);
	  ++x;
	}
    }
  return (0);
}

static int	savebmp(const char *name, t_bunny_pixelarray *pix)
{
  t_head	head;
  t_bmp		bmp;
  int		fd;

  my_bzero(&bmp, sizeof(t_bmp), 0);
  init_head(&head);
  init_bmp(&bmp, pix->clipable.clip_width, pix->clipable.clip_height);
  if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0 ||
      write(fd, &head, sizeof(t_head)) < 0 ||
      write(fd, &bmp, sizeof(t_bmp)) < 0)
    return (1);
  if (putcolor(pix, fd, pix->clipable.clip_width))
    return (1);
  return (0);
}

int			main(int ac, char **av)
{
  t_bunny_pixelarray	*pix;

  if (ac < 2 || !av[1][0])
    return (1);
  if (!(pix = bunny_load_pixelarray(av[1])))
    return (1);
  if (savebmp("test.bmp", pix))
    return (1);
  return (0);
}
