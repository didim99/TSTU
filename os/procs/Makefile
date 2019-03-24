
# Compiler settings
CC       = gcc
CFLAGS   = -Wall
LFLAGS   = -lm
OUT_NAME = ./procs
SRC_INFO = procinfo.c terminal.c
SRC_FORK = procfork.c

# Executable building rules
info: $(SRC_INFO)
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC_INFO) $(LFLAGS)

fork: $(SRC_FORK)
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC_FORK) $(LFLAGS)
