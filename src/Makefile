# ENV SETTINGS
SRC_DIR := ./
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
HEAD_FILES = $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,%.o,$(SRC_FILES))
FILENAMES = $(patsubst $(SRC_DIR)/%.cpp, %, $(SRC_FILES))

# COMPILER SETTINGS
OUTPUT_NAME = makedit
CC = g++
CFLAGS = -Wall
LIBS = gtkmm-3.0
PKGCONF = `pkg-config --cflags --libs $(LIBS)`

compilesrc: $(SRC_FILES) $(HEAD_FILES)
	@echo "Source files compiling:\n $(SRC_FILES)"
	@echo "Header files:\n$(HEAD_FILES)"
	@$(CC) $(CFLAGS) -o $(OUTPUT_NAME) $(SRC_FILES) $(PKGCONF)
	@echo "Compilation terminated"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $(PKGCONF)

alltobj: $(FILENAMES)
$(FILENAMES): ./%: ./%.cpp
	@echo "Compiling $^ to $@.o"
	$(CC) $(CFLAGS) -c -o $@.o $^ $(PKGCONF)

compileobj: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(OUTPUT_NAME) $(OBJ_FILES) $(PKGCONF)

info:
	@date
	@echo "User@hostname : $(USER)@$(shell hostname)"

clean:
	@rm *.o && echo "All .o files removed"
