# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 00:23:24 by rmedeiro          #+#    #+#              #
#    Updated: 2025/04/09 15:50:59 by rmedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome da biblioteca
NAME = libft.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I -g

RM = rm -f
COMPRESS = ar rcs

SRCS = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_bzero.c \
       ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
       ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
       ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
       ft_strtrim.c ft_substr.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_itoa.c ft_tolower.c ft_toupper.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
             ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Cria os arquivos objetos principais e os bónus
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)

# Regra all: Compila os arquivos principais e cria a biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPRESS) $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"

# Regra para compilar a biblioteca incluindo os bónus
bonus: $(NAME) $(OBJS_BONUS)
	@$(COMPRESS) $(NAME) $(OBJS_BONUS)
	@echo "Bonus added to $(NAME)!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra clean: Remove os arquivos objetos (.o)
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Cleaned up object files."

# Regra fclean: Remove os arquivos objetos (.o) e a biblioteca (libft.a)
fclean: clean
	@$(RM) $(NAME)
	@echo "All cleaned up: $(NAME)!"

# Regra re: Limpa tudo e recompila
re: fclean all

.PHONY: all clean fclean re bonus