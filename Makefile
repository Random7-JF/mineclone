CC = g++
BUILD_DIR = build
SRC_FILE = src/*.cpp # Note: This will expand to all .cpp files in src/
TARGET = $(BUILD_DIR)/mineclone

# Use pkg-config to get SDL3 CFLAGS and LIBS
SDL_CFLAGS = $(shell pkg-config --cflags sdl3)
SDL_LIBS = $(shell pkg-config --libs sdl3)

.PHONY: all clean run

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(BUILD_DIR) $(SRC_FILE)
	$(CC) $(SRC_FILE) -o $(TARGET) $(SDL_CFLAGS) $(SDL_LIBS)

run: all
	@echo "Running $(TARGET)..."
	@./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)