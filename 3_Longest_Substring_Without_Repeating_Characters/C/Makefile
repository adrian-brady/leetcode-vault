CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -v

SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.o,$(TEST_FILES))

MAIN_EXEC = $(BUILD_DIR)/main
TEST_EXEC = $(BUILD_DIR)/run_tests

all: $(MAIN_EXEC) $(TEST_EXEC)

$(MAIN_EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXEC): $(filter-out $(BUILD_DIR)/main.o, $(OBJ_FILES)) $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXEC)
	./$(TEST_EXEC)

run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
