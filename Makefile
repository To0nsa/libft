# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 12:19:10 by nlouis            #+#    #+#              #
#    Updated: 2025/03/25 10:19:53 by nlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                          LIBFT MAKEFILE 💻                                   #
# **************************************************************************** #

# Compiler settings
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -fPIE -I include

# Library output
NAME    := libft.a
LIBDIR  := lib
LIBFT   := $(LIBDIR)/$(NAME)

# Source and object files
SRCS    := $(shell find srcs -name "*.c")
OBJSDIR := objs
OBJS    := $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

# Colors
GREEN   := \033[0;32m
CYAN    := \033[0;36m
YELLOW  := \033[1;33m
RESET   := \033[0m

# Default goal
.DEFAULT_GOAL := all

# Build rules
all: $(LIBFT)

$(LIBFT): $(OBJS)
	@mkdir -p $(LIBDIR)
	@ar rcs $@ $^
	@echo "$(CYAN)📦 Archive created:$(RESET) $(NAME)"

$(OBJSDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

clean:
	@rm -rf $(OBJS) $(OBJSDIR)
	@echo "$(YELLOW)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@rm -rf $(LIBFT) $(LIBDIR)
	@echo "$(YELLOW)🗑️  Removed $(NAME) and $(LIBDIR)/ directory.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

# ****************************************************************************#
#                                💡 USAGE GUIDE                            	  #
# ****************************************************************************#
# make            → Compile all source files and create libft.a 📦
# make clean      → Remove all object files 🧹
# make fclean     → Remove object files, libft.a, and the lib/ folder 🗑️
# make re         → Fully clean and recompile everything 🔁
# **************************************************************************** #
