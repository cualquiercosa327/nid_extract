CC=gcc
CFLAGS=
LDFLAGS=
SOURCES=main.c
EXECUTABLE=nid_extract
all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(EXECUTABLE)
clean:
	rm -rf $(EXECUTABLE)
