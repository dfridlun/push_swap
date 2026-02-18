# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfridlun <dfridlun@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 13:46:33 by dfridlun          #+#    #+#              #
#    Updated: 2025/02/19 20:08:57 by dfridlun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iheader

SRCDIR = src
OBJDIR = obj

SRCS = $(SRCDIR)/ft_atoi.c \
		$(SRCDIR)/ft_bzero.c \
		$(SRCDIR)/ft_calloc.c \
		$(SRCDIR)/ft_isalnum.c \
		$(SRCDIR)/ft_isalpha.c \
		$(SRCDIR)/ft_isascii.c \
		$(SRCDIR)/ft_isdigit.c \
		$(SRCDIR)/ft_isprint.c \
		$(SRCDIR)/ft_itoa.c	\
		$(SRCDIR)/ft_memchr.c \
		$(SRCDIR)/ft_memcmp.c \
		$(SRCDIR)/ft_memcpy.c \
		$(SRCDIR)/ft_memmove.c \
		$(SRCDIR)/ft_memset.c \
		$(SRCDIR)/ft_putchar_fd.c \
		$(SRCDIR)/ft_putendl_fd.c \
		$(SRCDIR)/ft_putnbr_fd.c \
		$(SRCDIR)/ft_putstr_fd.c \
		$(SRCDIR)/ft_split.c \
		$(SRCDIR)/ft_strchr.c \
		$(SRCDIR)/ft_strdup.c \
		$(SRCDIR)/ft_striteri.c \
		$(SRCDIR)/ft_strjoin.c \
		$(SRCDIR)/ft_strlcat.c \
		$(SRCDIR)/ft_strlcpy.c \
		$(SRCDIR)/ft_strlen.c \
		$(SRCDIR)/ft_strmapi.c \
		$(SRCDIR)/ft_strncmp.c \
		$(SRCDIR)/ft_strnstr.c \
		$(SRCDIR)/ft_strrchr.c \
		$(SRCDIR)/ft_strtrim.c \
		$(SRCDIR)/ft_substr.c \
		$(SRCDIR)/ft_tolower.c \
		$(SRCDIR)/ft_toupper.c \
		$(SRCDIR)/ft_lstnew_bonus.c \
		$(SRCDIR)/ft_lstadd_front_bonus.c \
		$(SRCDIR)/ft_lstsize_bonus.c \
		$(SRCDIR)/ft_lstlast_bonus.c \
		$(SRCDIR)/ft_lstadd_back_bonus.c \
		$(SRCDIR)/ft_lstdelone_bonus.c \
		$(SRCDIR)/ft_lstclear_bonus.c \
		$(SRCDIR)/ft_lstiter_bonus.c \
		$(SRCDIR)/ft_lstmap_bonus.c \
		$(SRCDIR)/ft_printf.c \
		$(SRCDIR)/ft_formathandling.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = libft.a

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c |$(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR) 
	
fclean: clean
	@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re bonus