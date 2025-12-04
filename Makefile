# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 00:23:24 by rmedeiro          #+#    #+#              #
#    Updated: 2025/12/04 14:39:46 by rmedeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS =  output/ft_putchar_fd.c \
        output/ft_putendl_fd.c \
        output/ft_putnbr_fd.c \
        output/ft_putstr_fd.c \
        output/ft_putchar.c \
        output/ft_putnbr.c \
        output/ft_putstr.c \
        memory/ft_bzero.c \
        memory/ft_calloc.c \
        memory/ft_memchr.c \
        memory/ft_memcmp.c \
        memory/ft_memcpy.c \
        memory/ft_memmove.c \
        memory/ft_memset.c \
        strings/ft_split.c \
        strings/ft_strchr.c \
        strings/ft_strdup.c \
        strings/ft_striteri.c \
        strings/ft_strjoin.c \
        strings/ft_strlcat.c \
        strings/ft_strlcpy.c \
        strings/ft_strlen.c \
        strings/ft_strmapi.c \
        strings/ft_strncmp.c \
        strings/ft_strnstr.c \
        strings/ft_strrchr.c \
        strings/ft_strtrim.c \
        strings/ft_substr.c \
        strings/ft_atoi.c \
        strings/ft_itoa.c \
        strings/ft_strcpy.c \
        ctype/ft_isalnum.c \
        ctype/ft_isalpha.c \
        ctype/ft_isascii.c \
        ctype/ft_isdigit.c \
        ctype/ft_islower.c \
        ctype/ft_isprint.c \
        ctype/ft_isspace.c \
        ctype/ft_isupper.c \
        ctype/ft_isxdigit.c \
        ctype/ft_tolower.c \
        ctype/ft_toupper.c

BONUS_SRCS = list/ft_lstnew_bonus.c \
             list/ft_lstadd_front_bonus.c \
             list/ft_lstsize_bonus.c \
             list/ft_lstlast_bonus.c \
             list/ft_lstadd_back_bonus.c \
             list/ft_lstdelone_bonus.c \
             list/ft_lstclear_bonus.c \
             list/ft_lstiter_bonus.c \
             list/ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_SRCS:.c=.o)

INCLUDES = -I. -Ictype -Imemory -Ioutput -Istrings -Ilist

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created!"

bonus: $(OBJS) $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "Bonus added to $(NAME)!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed $(NAME)."

re: fclean all

.PHONY: all clean fclean re bonus