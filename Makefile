SRCS	= main.rs
NAME	= falling_sand
COMPILER = rustc

$(NAME):
	$(COMPILER) $(SRCS) -o $(NAME)

all:	$(NAME)

fclean:
	rm -rf $(NAME)

.PHONY: all fclean