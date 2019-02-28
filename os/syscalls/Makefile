
# Compiler settings
GTK_CFLAGS = `pkg-config gtk+-3.0 --cflags`
GTK_LFLAGS = `pkg-config gtk+-3.0 --libs`

CC       = gcc
CFLAGS   = -Wall ${GTK_CFLAGS}
LFLAGS   = -lX11 ${GTK_LFLAGS}
DBGFLAGS = -g
OUT_NAME = ./syscalls
SRC_MAIN = main.c

# Executable building rules
all: $(SRC_MAIN)
	$(CC) $(CFLAGS) -o $(OUT_NAME) $(SRC_MAIN) $(LFLAGS)

debug: $(SRC_MAIN)
	$(CC) $(CFLAGS) $(DBGFLAGS) -o $(OUT_NAME) $(SRC_MAIN) $(LFLAGS)