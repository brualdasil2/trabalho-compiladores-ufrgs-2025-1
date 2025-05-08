CC := gcc
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -fsanitize=address
SRC := main.c item_tabela.c argumento.c hash.c tabela_simbolos.c pilha_tabelas.c

tabela: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o tabela

clean:
	rm tabela