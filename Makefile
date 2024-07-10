TARGET=sheap

CC=gcc
CLFAGS=-Wall -Wextra -std=c11 -pedantic

SRC_DIR=./src
BUILD_DIR=./build

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

$(OBJS): $(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm $(OBJS) $(TARGET)
