.PHONY: clean archive doc memcheck debug create_build_dir
SRC_DIR=src
OBJ_DIR=build
LIB_SRC_DIR=lib/src
LIB_INCLUDE_DIR=lib/include

CC=gcc
CFLAGS=-Wall -Iinclude -I$(LIB_INCLUDE_DIR)
LDFLAGS=-L$(OBJ_DIR) -lcouleurs

TARGET=$(OBJ_DIR)/mastermind
DOC_FOLDER=docs
ARCHIVE_NAME=techdev-mastermind-MAACHE_MUKOKA_MENDE
INCLUDE_DIR=include
FILE_NAME = $(basename $(FILE))

SRCS=$(wildcard $(SRC_DIR)/*.c)
LIB_SRC=$(LIB_SRC_DIR)/couleurs.c
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIB_OBJ=$(LIB_SRC:$(LIB_SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: libcouleurs $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -lcouleurs

libcouleurs: $(LIB_OBJ)
	@mkdir -p $(OBJ_DIR)
	ar rcs $(OBJ_DIR)/libcouleurs.a $(LIB_OBJ)

$(LIB_OBJ): $(LIB_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: create_build_dir $(TARGET)
	$(TARGET)

create_build_dir:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(ARCHIVE_NAME) $(ARCHIVE_NAME).tar.gz $(DOC_FOLDER)


archive:
	tar -czvf $(ARCHIVE_NAME).tar.gz Makefile $(SRC_DIR)/ README.md Doxyfile data/sequence_secrete.txt .gitignore lib/

doc:
	doxygen Doxyfile 

memcheck:
	@if [ -z "$(FILE)" ]; then \
		echo "Utilisation: make memcheck FILE=./chemin/du/fichier.c"; \
	else \
		$(CC) $(CFLAGS) -o $(FILE_NAME) $(FILE) && \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(FILE_NAME); \
	fi

debug:
	@if [ -z "$(FILE)" ]; then \
		echo "Utilisation: make debug FILE=./chemin/du/fichier.c"; \
	else \
		$(CC) $(CFLAGS) -o $(FILE_NAME) $(FILE) && \
		gdb ./$(FILE_NAME); \
	fi 
