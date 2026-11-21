
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SDL_FLAGS = $(shell pkg-config --cflags sdl2 SDL2_image)
SDL_LIBS = $(shell pkg-config --libs sdl2 SDL2_image)

SRC = main.cpp $(shell find src -type f -name "*.cpp")
HEADERS = $(shell find src -type f -name "*.hpp")
PROJECT_ROOT = $(CURDIR)
INCLUDES = -I$(PROJECT_ROOT)

OUT = VISUAL_NOVEL

all: $(OUT)

$(OUT): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SDL_FLAGS) $(SRC) -o $(OUT) $(SDL_LIBS)

clean:
	rm -f $(OUT)

run: $(OUT)
	./$(OUT)

rebuild: clean
	$(MAKE) all

.PHONY: all clean run rebuild
