
# Compiler settings
CC       = g++
CPPFLAGS = -Wall
DBGFLAGS = -g
OUT_NAME = ./test
SRC_MAIN = main.cpp

# Executable building rules
all: $(SRC_MAIN)
	$(CC) $(CPPFLAGS) -o $(OUT_NAME) $(SRC_MAIN)

debug: $(SRC_MAIN)
	$(CC) $(CPPFLAGS) $(DBGFLAGS) -o $(OUT_NAME) $(SRC_MAIN)