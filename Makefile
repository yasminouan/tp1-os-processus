CC = gcc
SRC = src
BIN = bin
PROGS = exo1a exo1b exo2 exo3 exo4 carre calcule exo6

all: $(BIN) $(PROGS) racine

$(BIN):
	mkdir -p $(BIN)

$(PROGS): %: $(SRC)/%.c | $(BIN)
	$(CC) $< -o $(BIN)/$@

racine: $(SRC)/racine.c | $(BIN)
	$(CC) $< -o $(BIN)/racine -lm

clean:
	rm -rf $(BIN)
