NAME		= so_long

SRCS		= $(shell find ./srcs -name "*c")

OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= $(shell find ./bonus -name "*.c")

BONUS_OBJS	= $(patsubst ./bonus/%.c, ./bonus/%.o, $(BONUS_SRCS))

CC			= gcc

ISBONUS		= 0

INCLUDES	= -Iincludes -Imlx

CFLAGS		= -Werror -Wextra -Wall

LIBFT		= ./libft

GNL			= ./get_next_line

MLX			= ./mlx
MLXLIB		= -L$(MLX) -lmlx -framework OpenGL -framework AppKit
MACH_EXTRA	= install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${MLX}/libmlx.dylib $(NAME)

LINKERS		= -L$(LIBFT) -lft -L$(GNL) -lgnl $(MLXLIB) 

RM			= rm -rf

srcs/%.o:	srcs/%.c
			@$(CC) $(CFLAGS) -DBONUS=$(ISBONUS) $(INCLUDES) -c $< -o $@

bonus/%.o:	bonus/%.c
			@$(CC) $(CFLAGS) -DBONUS=$(ISBONUS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) $(BONUS_OBJS)
			@$(MAKE) all -C $(LIBFT)
			@$(MAKE) all -C $(GNL)
			@$(MAKE) all -C $(MLX)
			@$(CC) $(CFLAGS) $(INCLUDES) $(LINKERS) $(OBJS) $(BONUS_OBJS) -o $(NAME)
			@$(MACH_EXTRA)

all:		bonus

withbonus:
			$(eval ISBONUS = 1)

bonus:		withbonus $(NAME)

clean:
			@$(MAKE) clean -C $(LIBFT)
			@$(MAKE) clean -C $(GNL)
			@$(MAKE) clean -C $(MLX)
			@$(RM) $(BONUS_OBJS)
			@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT)
			@$(MAKE) fclean -C $(GNL)
			@$(RM) $(NAME)

re:			fclean $(NAME)

re_b:		fclean all

.PHONY:		all bonus withbonus clean fclean re re_b
