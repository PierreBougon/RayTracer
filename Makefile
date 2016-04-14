##
## Makefile for RAYTRACER in /home/bougon_p/rendu/gfx_raytracer2
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Wed Apr 13 20:06:22 2016 bougon_p
## Last update Thu Apr 14 16:34:36 2016 romain samuel
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# RT VARIABLES

MAIN		=	src/

ITFC		=	src/interface/

SRC		=	$(MAIN)main.c \
			$(MAIN)init_main.c \
			$(MAIN)delete_clipables.c \
			$(MAIN)antialiasing.c \
			$(MAIN)clear_list.c \
			$(MAIN)create_obj_list.c \
			$(MAIN)diffuse_light.c \
			$(MAIN)display.c \
			$(MAIN)display_objects.c \
			$(MAIN)get_norm.c \
			$(MAIN)get_simple_coords.c \
			$(MAIN)inters.c \
			$(MAIN)limited_objects.c \
			$(MAIN)load_cone.c \
			$(MAIN)load_cylinder.c \
			$(MAIN)load_file.c \
			$(MAIN)load_light.c \
			$(MAIN)load_plan.c \
			$(MAIN)load_sphere.c \
			$(MAIN)order_hit_list.c \
			$(MAIN)rotations.c \
			$(MAIN)set_hit_values.c \
			$(MAIN)shade.c \
			$(MAIN)shadow.c \
			$(MAIN)shadow_inters.c \
			$(MAIN)specular_light.c \
			$(MAIN)tekpixel.c \
			$(MAIN)update_hit_list.c \
			$(MAIN)blit_clipables.c \
			$(ITFC)init_itfc.c \
			$(ITFC)check_buttons.c \
			src/debug.c

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

CFLAGS  =	-W -Wall -Wextra -g

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
