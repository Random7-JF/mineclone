CC = g++
BUILD_DIR = build
SRC_FILE = src/*.cpp
TARGET = $(BUILD_DIR)/mineclone

# Use pkg-config to get SDL3 CFLAGS and LIBS
SDL_CFLAGS = $(shell pkg-config --cflags sdl3)
SDL_LIBS = $(shell pkg-config --libs sdl3)

.PHONY: all clean

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(BUILD_DIR) $(SRC_FILE)
	$(CC) $(SRC_FILE) -o $(TARGET) $(SDL_CFLAGS) $(SDL_LIBS)

clean:
	rm -rf $(BUILD_DIR)