.PHONY: all clean

all: firefault

clean:
	rm firefault

firefault: firefault.c
	$(CC) -std=c89 -Wall -m32 -O0 -D_FORTIFY_SOURCE=0 -fno-stack-protector -fomit-frame-pointer -o $@ $<
