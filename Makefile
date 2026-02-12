# force macs to use g++-15 to avoid clang mapped to g++
ifeq ($(OS),Windows_NT)
	CXX = g++
else
	OS_NAME := $(shell uname -s)
	ifeq ($(OS_NAME),Darwin)
		CXX = g++-15
	else
		CXX = g++
	endif
endif

# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++20 -fmodules-ts -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion -Wuninitialized
# uncomment the following lines to enable address sanitizer on non-Windows platforms
# ifneq ($(OS),Windows_NT)
# 	CXXFLAGS += -fsanitize=address
# endif

# list .h files here
HEADERS = Item.h Armor.h Weapon.h RangedWeapon.h

# list .cpp files here
TEST_FILES = tests.cpp Item.cpp Armor.cpp Weapon.cpp RangedWeapon.cpp
SHARED_FILES = 

# When you are ready to use Character, uncomment the following
# HEADERS += Character.h
# TEST_FILES += Character.cpp characterTests.cpp

.PHONY: all
all: tests.exe

.PHONY: tests.exe # Always force rebuild of tests
tests.exe: $(TEST_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SHARED_FILES) -o $@

.PHONY: clean
clean:
	rm -f tests.exe
