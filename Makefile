# Define the compiler
CXX = g++

# Define compiler flags
# -Wall: Enable all standard warnings
# -Wextra: Enable extra warnings
# -g: Include debugging information
# -std=c++17: Use C++17 standard
CXXFLAGS = -Wall -Wextra -g -std=c++17

# Define the output directory for object files and the executable
BUILD_DIR = build

# Define the source directory
SRC_DIR = src

# Define the executable name and path
# Now the target explicitly includes the BUILD_DIR
TARGET = $(BUILD_DIR)/mineclone

# Find all C++ source files in the SRC_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Generate a list of object files in the BUILD_DIR
# e.g., src/main.cpp -> build/main.o
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# The linking rule remains mostly the same, as $@ already points to the full target path
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) # Only remove the build directory, which now contains the executable
