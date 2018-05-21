SRC_DIR := ./src
OBJ_DIR := ./out
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
SRC_REQS := $(SRC_DIR)/%.cpp
LDFLAGS :=
CPPFLAGS :=
CXXFLAGS := -std=c++17 -c -Wall -Iinclude -O3 -Wc++17-extensions
EXECUTABLE := gba
TEST_EXE := gba_tests

$(EXECUTABLE): setup link

tests: setup link_tests

# filter out all test files so we only link non-test objects
link: $(filter-out $(wildcard $(OBJ_DIR)/*_tests.o),$(OBJ_FILES))
	g++ $(LDFLAGS) -o $(EXECUTABLE) $^

# for tests, we need to make everything EXCEPT main.cpp so we
# dont include multiple main functions
link_tests: $(filter-out $(OBJ_DIR)/main.o,$(OBJ_FILES))
	g++ $(LDFLAGS) -o $(EXECUTABLE)_tests $^

$(OBJ_DIR)/%.o: $(SRC_REQS)
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

setup:
	mkdir -p out/

clean:
	rm -rf out/
	[ -e $(EXECUTABLE) ] && rm $(EXECUTABLE)