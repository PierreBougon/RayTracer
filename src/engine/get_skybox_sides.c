/*
** get_skybox_sides.c for RAYTRACER in /home/samuel_r/EPITECH/GFX/gfx_raytracer2
**
** Made by romain samuel
** Login   <samuel_r@epitech.net>
**
** Started on  Fri Apr 29 17:59:04 2016 romain samuel
** Last update Mon May  2 19:05:01 2016 romain samuel
*/

#include "raytracer.h"

int			is_full_line(t_bunny_pixelarray *img, int line)
{
  t_bunny_position	pos;
  t_color		*color;

  pos.y = line;
  pos.x = 0;
  color = (t_color *)img->pixels;
  while (pos.x < img->clipable.clip_width)
    {
      if (color[pos.y * img->clipable.clip_width + pos.x].full > 0xFF000000)
	return (1);
      pos.x++;
    }
  return (0);
}

int			is_full_column(t_bunny_pixelarray *img, int column)
{
  t_bunny_position	pos;
  t_color		*color;

  pos.y = 0;
  pos.x = column;
  color = (t_color *)img->pixels;
  while (pos.y < img->clipable.clip_height)
    {
      if (color[pos.y * img->clipable.clip_width + pos.x].full > 0xFF000000)
	return (1);
      pos.y++;
    }
  return (0);
}

t_bunny_pixelarray	*get_skybox_right_side(t_bunny_pixelarray *img,
					       t_bunny_position *start,
					       t_bunny_position *size)
{
  t_bunny_pixelarray	*side;
  t_bunny_position	min;
  t_bunny_position	max;
  t_bunny_position	pos;
  t_bunny_position	tex;
  t_color		*color;

  color = (t_color *)img->pixels;
  min.y = start->y + (double)size->y / 3.0 + 2;
  max.y = start->y + (2.0 * (double)size->y) / 3.0 + 1;
  min.x = start->x + (3.0 * (double)size->x) / 4.0 + 2;
  max.x = start->x + (double)size->x + 1;
  if ((side = bunny_new_pixelarray(size->x / 4.0,
				   size->y / 3.0)) == NULL)
    return (NULL);
  pos.y = min.y;
  tex.y = 0;
  while (pos.y < max.y)
    {
      tex.x = 0;
      pos.x = min.x;
      while (pos.x < max.x)
	{
	  tekpixel(side, &tex, &color[img->clipable.clip_width * pos.y + pos.x]);
	  pos.x++;
	  tex.x++;
	}
      pos.y++;
      tex.y++;
    }
  return (side);
}

t_bunny_pixelarray	*get_skybox_left_side(t_bunny_pixelarray *img,
					      t_bunny_position *start,
					      t_bunny_position *size)
{
  t_bunny_pixelarray	*side;
  t_bunny_position	min;
  t_bunny_position	max;
  t_bunny_position	pos;
  t_bunny_position	tex;
  t_color		*color;

  color = (t_color *)img->pixels;
  min.y = start->y + (double)size->y / 3.0 + 2;
  max.y = start->y + (2.0 * (double)size->y) / 3.0 + 1;
  min.x = start->x + (double)size->x / 4.0 + 2;
  max.x = start->x + (2.0 * (double)size->x);
  if ((side = bunny_new_pixelarray(size->x / 4.0,
				   size->y / 3.0)) == NULL)
    return (NULL);
  pos.y = min.y;
  tex.y = 0;
  while (pos.y < max.y)
    {
      tex.x = 0;
      pos.x = min.x;
      while (pos.x < max.x)
	{
	  tekpixel(side, &tex, &color[img->clipable.clip_width * pos.y + pos.x]);
	  pos.x++;
	  tex.x++;
	}
      pos.y++;
      tex.y++;
    }
  return (side);
}

t_bunny_pixelarray	*get_skybox_up_side(t_bunny_pixelarray *img,
					    t_bunny_position *start,
					    t_bunny_position *size)
{
  t_bunny_pixelarray	*side;
  t_bunny_position	min;
  t_bunny_position	max;
  t_bunny_position	pos;
  t_bunny_position	tex;
  t_color		*color;

  color = (t_color *)img->pixels;
  min.y = start->y;
  max.y = start->y + (1.0 * (double)size->y) / 3.0;
  min.x = start->x + (2.0 * (double)size->x) / 4.0;
  max.x = start->x + (3.0 * (double)size->x) / 4.0;
  if ((side = bunny_new_pixelarray(size->x / 4.0,
				   size->y / 3.0)) == NULL)
    return (NULL);
  pos.y = min.y;
  tex.y = 0;
  while (pos.y < max.y)
    {
      tex.x = 0;
      pos.x = min.x;
      while (pos.x < max.x)
	{
	  tekpixel(side, &tex, &color[img->clipable.clip_width * pos.y + pos.x]);
	  pos.x++;
	  tex.x++;
	}
      pos.y++;
      tex.y++;
    }
  return (side);
}

t_bunny_pixelarray	*get_skybox_down_side(t_bunny_pixelarray *img,
					      t_bunny_position *start,
					      t_bunny_position *size)
{
  t_bunny_pixelarray	*side;
  t_bunny_position	min;
  t_bunny_position	max;
  t_bunny_position	pos;
  t_bunny_position	tex;
  t_color		*color;

  color = (t_color *)img->pixels;
  min.y = start->y + (2.0 * (double)size->y) / 3.0 + 1;
  max.y = start->y + (3.0 * (double)size->y) / 3.0;
  min.x = start->x + (2.0 * (double)size->x) / 4.0;
  max.x = start->x + (3.0 * (double)size->x) / 4.0;
  if ((side = bunny_new_pixelarray(size->x / 4.0,
				   size->y / 3.0)) == NULL)
    return (NULL);
  pos.y = min.y;
  tex.y = 0;
  while (pos.y < max.y)
    {
      tex.x = 0;
      pos.x = min.x;
      while (pos.x < max.x)
	{
	  tekpixel(side, &tex, &color[img->clipable.clip_width * pos.y + pos.x]);
	  pos.x++;
	  tex.x++;
	}
      pos.y++;
      tex.y++;
    }
  return (side);
}

t_bunny_pixelarray	*get_skybox_forward_side(t_bunny_pixelarray *img,
						 t_bunny_position *start,
						 t_bunny_position *size)
{
  t_bunny_pixelarray	*side;
  t_bunny_position	min;
  t_bunny_position	max;
  t_bunny_position	pos;
  t_bunny_position	tex;
  t_color		*color;

  color = (t_color *)img->pixels;
  min.y = start->y + (double)size->y / 3.0 + 2;
  max.y = start->y + (2.0 * (double)size->y) / 3.0 + 1;
  min.x = start->x + (2.0 * (double)size->x) / 4.0;
  max.x = start->x + (3.0 * (double)size->x) / 4.0;
  if ((side = bunny_new_pixelarray(size->x / 4.0,
				   size->y / 3.0)) == NULL)
    return (NULL);
  pos.y = min.y;
  tex.y = 0;
  while (pos.y < max.y)
    {
      tex.x = 0;
      pos.x = min.x;
      while (pos.x < max.x)
	{
	  tekpixel(side, &tex, &color[img->clipable.clip_width * pos.y + pos.x]);
	  pos.x++;
	  tex.x++;
	}
      pos.y++;
      tex.y++;
    }
  return (side);
}

t_bunny_pixelarray	*get_skybox_backward_side(t_bunny_pixelarray *img,
						  t_bunny_position *start,
						  t_bunny_position *size)
{
  t_bunny_pixelarray	*side;
  t_bunny_position	min;
  t_bunny_position	max;
  t_bunny_position	pos;
  t_bunny_position	tex;
  t_color		*color;

  color = (t_color *)img->pixels;
  min.y = start->y + (double)size->y / 3.0 + 2;
  max.y = start->y + (2.0 * (double)size->y) / 3.0 + 2;
  min.x = start->x;
  max.x = start->x + (double)size->x / 4.0;
  if ((side = bunny_new_pixelarray(size->x / 4.0,
				   size->y / 3.0 + 1)) == NULL)
    return (NULL);
  pos.y = min.y;
  tex.y = 0;
  while (pos.y < max.y)
    {
      tex.x = 0;
      pos.x = min.x;
      while (pos.x < max.x)
	{
	  tekpixel(side, &tex, &color[img->clipable.clip_width * pos.y + pos.x]);
	  pos.x++;
	  tex.x++;
	}
      pos.y++;
      tex.y++;
    }
  return (side);
}

int			get_skybox_sides(t_rt *s, t_bunny_pixelarray *img)
{
  t_bunny_position	start;
  t_bunny_position	end;
  t_bunny_position	size;

  start.x = 0;
  start.y = 0;
  end.x = img->clipable.clip_width - 1;
  end.y = img->clipable.clip_height - 1;
  is_full_column(img, end.x);
  while (is_full_line(img, start.y) == 0)
    start.y++;
  while (is_full_column(img, start.x) == 0)
    start.x++;
  while (is_full_line(img, end.y) == 0)
    end.y--;
  while (is_full_column(img, end.x) == 0)
    end.x--;
  size.x = end.x - start.x;
  size.y = end.y - start.y;
  s->opt.skybox_right = get_skybox_right_side(img, &start, &size);
  s->opt.skybox_left = get_skybox_left_side(img, &start, &size);
  s->opt.skybox_up = get_skybox_up_side(img, &start, &size);
  s->opt.skybox_down = get_skybox_down_side(img, &start, &size);
  s->opt.skybox_forward = get_skybox_forward_side(img, &start, &size);
  s->opt.skybox_backward = get_skybox_backward_side(img, &start, &size);
  return (0);
}
