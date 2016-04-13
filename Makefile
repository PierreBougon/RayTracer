##
## Makefile for RAYTRACER in /home/bougon_p/rendu/gfx_raytracer2
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Wed Apr 13 20:06:22 2016 bougon_p
## Last update Wed Apr 13 21:32:34 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# RT VARIABLES

MAIN		=	src/

SRC		=	src/antialiasing.c \
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

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBBUNNY     =		-L/home/${USER}/.froot/lib/ -llapin \
	                -L/usr/local/lib \
			-lsfml-audio \
	                -lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

LIBPATH =       lib/

LIB	=	lib/libmy.a

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_power_rec.c \
		$(LIBPATH)my/my_printf.c \
		$(LIBPATH)my/my_printfcsspb.c \
		$(LIBPATH)my/my_printfdiouxx.c \
		$(LIBPATH)my/my_printfmetc.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strncmp.c \
		$(LIBPATH)my/my_strncmp.c \
		$(LIBPATH)my/my_getcolor.c \
		$(LIBPATH)my/my_puterr.c \
		$(LIBPATH)my/my_strcpy.c \
		$(LIBPATH)my/my_strcat.c \
		$(LIBPATH)my/my_bzero.c \
		$(LIBPATH)my/my_realloc.c \
		$(LIBPATH)my/my_alpha_num.c \
		$(LIBPATH)my/my_getcolor.c \
		$(LIBPATH)my/my_puterr.c \


LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)


# PROJECT VARIABLES

NAME	=	raytracer

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra

CC      =	gcc $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(NAME)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB) $(LIBBUNNY)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@$(ECHO) "$(GREEN)\n> Compiling Library\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"


all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIB)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
