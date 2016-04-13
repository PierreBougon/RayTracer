##
## Makefile for RAYTRACER in /home/samuel_r/EPITECH/GFX/RAYTRACER
##
## Made by romain samuel
## Login   <samuel_r@epitech.net>
##
## Started on  Tue Apr  5 15:21:11 2016 romain samuel
## Last update Wed Apr 13 19:10:09 2016 romain samuel
##

SRC	=	src/antialiasing.c \
		src/clear_list.c \
		src/create_obj_list.c \
		src/diffuse_light.c \
		src/display.c \
		src/display_objects.c \
		src/get_norm.c \
		src/get_simple_coords.c \
		src/inters.c \
		src/load_cone.c \
		src/load_cylinder.c \
		src/load_file.c \
		src/load_light.c \
		src/load_plan.c \
		src/load_sphere.c \
		src/main.c \
		src/order_hit_list.c \
		src/rotations.c \
		src/set_hit_values.c \
		src/shade.c \
		src/shadow.c \
		src/shadow_inters.c \
		src/specular_light.c \
		src/tekpixel.c \
		src/update_hit_list.c \
		src/lib/my_getcolor.c \
		src/lib/my_getnbr.c \
		src/lib/my_puterr.c \
		src/lib/my_strcmp.c \
		src/lib/my_strdup.c \
		src/lib/my_strlen.c

OBJ	= 	$(SRC:.c=.o)

LIB	= 	-L/home/${USER}/.froot/lib/ -llapin \
	  	-L/usr/local/lib \
	  	-lsfml-audio \
	  	-lsfml-graphics \
	  	-lsfml-window \
	  	-lsfml-system \
		-lstdc++ -ldl \
		-lm

NAME	= 	raytracer

CFLAGS	= 	-W -Wall -Wextra -ansi -pedantic -I./include -g

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME) $(CFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
