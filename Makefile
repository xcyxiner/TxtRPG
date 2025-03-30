CC = g++  # 改为 g++
RM = rm -rf
MKDIR = mkdir -p

TARGET = build/crpg
SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)  # 改为 .cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -lavformat -lavcodec -lavutil -lswscale -lswresample -lm -lstdc++  # 添加 C++ 库

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(MKDIR) $(dir $@)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(BUILD_DIR)/*.o

