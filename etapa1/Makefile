CC := gcc
OBJDIR := obj
SRC := $(wildcard *.c)
TARGET := etapa1
FLEX_RULES := scanner.l
FLEX_C := lex.yy.c
SRC += $(FLEX_C)
OBJ := $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

$(FLEX_C): scanner.l
	flex $(FLEX_RULES)

	
	
