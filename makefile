CXX      := g++ --std=c++11
CXXFLAGS := -pedantic-errors #-Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET_CREATOR	:= builder
TARGET_GAME		:= game
INCLUDE  := -Iinclude/
DEPS     := $(wildcard src/*.hpp src/*/*.hpp src/*/*/*.hpp src/*/*/*/*.hpp)
SRC_GAME :=                       \
	$(filter-out src/Creator.cpp, $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp src/*/*/*/*.cpp))         \

OBJECTS_GAME := $(SRC_GAME:%.cpp=$(OBJ_DIR)/%.o)
SRC_CREATOR :=                       \
	$(filter-out src/Game.cpp, $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp src/*/*/*/*.cpp))         \

OBJECTS_CREATOR := $(SRC_CREATOR:%.cpp=$(OBJ_DIR)/%.o)


all: build creator game

creator: build $(APP_DIR)/$(TARGET_CREATOR)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET_CREATOR): $(OBJECTS_CREATOR) $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET_CREATOR) $(OBJECTS_CREATOR)

game: build $(APP_DIR)/$(TARGET_GAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET_GAME): $(OBJECTS_GAME) $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET_GAME) $(OBJECTS_GAME)

.PHONY: all build clean debug release game creator tree

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

tree:
	@echo \`\`\` > tree.md
	@tree -I "build|CPPLINT.cfg" >> tree.md
	@echo \`\`\` >> tree.md
