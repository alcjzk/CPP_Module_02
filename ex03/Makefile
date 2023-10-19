NAME	= bsp

OBJ_DIR	= ./obj
SRC_DIR = .

CC 		= c++
CFLAGS 	= -MP -MMD -I$(SRC_DIR) -Wall -Wextra -Werror -Wpedantic -g -std=c++98
SHELL	= /bin/sh

SRCS	= main.cpp Fixed.cpp Point.cpp bsp.cpp

all: $(NAME)

run: all
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

.PHONY: all

vpath %.cpp $(SRC_DIR)
-include $(SRCS:%.cpp=$(OBJ_DIR)/%.d)
