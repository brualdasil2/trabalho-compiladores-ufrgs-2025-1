CC := gcc
CFLAGS := -fsanitize=address
LFLAGS := -fsanitize=address
OBJDIR := obj
SRC := $(wildcard *.c)
TARGET := etapa3
FLEX_RULES := scanner.l
FLEX_C := lex.yy.c
BISON_RULES := parser.y
BISON_C := parser.tab.c
BISON_H := parser.tab.h
SRC += $(FLEX_C)
SRC += $(BISON_C)
OBJ := $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(LFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: $(BISON_C)

$(FLEX_C): $(FLEX_RULES)
	flex $(FLEX_RULES)

$(FLEX_RULES): $(BISON_C)


$(BISON_C): $(BISON_RULES)
	bison -d $(BISON_RULES)

clean:
	rm *.o $(TARGET) $(FLEX_C) $(BISON_C) $(BISON_H)