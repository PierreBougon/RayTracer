/*
** my_strcmp.c for compare in /home/bougon_p/rendu/PSU_2015_my_ls/lib/my
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Nov 28 23:15:22 2015 Pierre Bougon
** Last update Wed Apr 13 21:16:02 2016 bougon_p
*/

#include "my.h"

int     my_strcmp(char *need, char *tar)
{
  int   i;

  i = 0;
  while ((tar[i]) && (need[i]) && (tar[i] == need[i]))
    i = i + 1;
  return (need[i] - tar[i]);
}
