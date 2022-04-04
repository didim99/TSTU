
# Compiler settings
CC       = gcc
CFLAGS   = -Wall
LFLAGS   = -lm
DBGFLAGS = -g
OUT_NAME = ./meminfo
SRC_MAIN = *.c

# Executable building rules
all: $(SRC_MAIN)
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC_MAIN) $(LFLAGS)

debug: $(SRC_MAIN)
	$(CC) $(CFLAGS) $(DBGFLAGS) -o $(OUT_NAME) $(SRC_MAIN) $(LFLAGS)