NAME_C = client
NAME_S = server
NAME_Cbonus = client_bonus
NAME_Sbonus = server_bonus
NAME_P= ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC = server.c manage_errors.c
SRC_B = client.c manage_errors.c
SRC_bonus = server_bonus.c manage_errors.c
SRC_Bbonus = client_bonus.c manage_errors.c

all: printf $(NAME_S) $(NAME_C)

bonus: $(SRC_bonus) $(SRC_Bbonus)
	$(CC) $(CFLAGS) $(SRC_bonus) $(NAME_P) -o $(NAME_Sbonus)
	$(CC) $(CFLAGS) $(SRC_Bbonus) $(NAME_P) -o $(NAME_Cbonus)

printf:
	cd ft_printf && make && cd ../

$(NAME_S): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(NAME_P) -o $(NAME_S)

$(NAME_C) : $(SRC_B)
	$(CC) $(CFLAGS) $(SRC_B) $(NAME_P) -o $(NAME_C)

clean:

	cd ft_printf && make clean && cd ../

fclean: clean
	rm -rf $(NAME_S) $(NAME_C) $(NAME_P) $(NAME_Sbonus) $(NAME_Cbonus)

re: fclean all
