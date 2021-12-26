NAME		= so_long

SRCS		= $(shell find ./srcs -name "*c")

OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= $(shell find ./bonus -name "*.c")

BONUS_OBJS	= $(patsubst ./bonus/%.c, ./bonus/%.o, $(BONUS_SRCS))

CC			= gcc

CFLAGS		= -Werror -Wextra -Wall

IS_BONUS	= 0

LIB			= ./libs

LIBFT		= $(LIB)/libft

LIBGNL		= $(LIB)/get_next_line

LIBMLX_L	= $(LIB)/mlx_linux
LIBMLX_L_	= -L$(LIBMLX_L) -lmlx_Linux -lXext -lX11 -lm -lz

LIBMLX_M	= $(LIB)/mlx
LIBMLX_M_	= -L$(LIBMLX_M) -lmlx -framework OpenGL -framework AppKit
MACH_EXTRA	= install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${MLX}/libmlx.dylib $(NAME)

UNIX_NAME	= $(shell uname -s)

ifeq ($(UNIX_NAME),Darwin)
LIBMLX		= $(LIBMLX_M)
LIBMLX_LINK	= $(LIBMLX_M_)
else ($(UNIX_NAME),Linux)
LIBMLX		= $(LIBMLX_L)
LIBMLX_LINK	= $(LIBMLX_L_)
endif

INCLUDES	= -I./includes -I$(LIBMLX)

LINKERS		= -L$(LIBGNL) -lgnl -L$(LIBFT) -lft $(LIBMLX_LINK) 

RM			= rm -rf

.PHONY:		all bonus withbonus clean fclean re

srcs/%.o:	srcs/%.c
			@$(CC) $(CFLAGS) -DBONUS=$(ISBONUS) $(INCLUDES) -c $< -o $@

bonus/%.o:	bonus/%.c
			@$(CC) $(CFLAGS) -DBONUS=$(ISBONUS) $(INCLUDES) -c $< -o $@

all:		bonus

bonus:		withbonus $(NAME)

withbonus:
			$(eval ISBONUS = 1)

$(NAME):	$(OBJS) $(BONUS_OBJS)
			@$(MAKE) all -C $(LIBFT)
			@$(MAKE) all -C $(LIBGNL)
			@$(MAKE) all -C $(LIBMLX)
			@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(BONUS_OBJS) $(LINKERS) -o $(NAME)
ifeq ($(UNIX_NAME),Darwin)
			@$(MACH_EXTRA)
endif

clean:
			@$(MAKE) clean -C $(LIBFT)
			@$(MAKE) clean -C $(LIBGNL)
			@$(MAKE) clean -C $(LIBMLX)
			@$(RM) $(BONUS_OBJS)
			@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT)
			@$(MAKE) fclean -C $(LIBGNL)
			@$(RM) $(NAME)

re:			fclean all
