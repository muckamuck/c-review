all: x y

x: x.c
	gcc -o x x.c

y: y.c
	gcc -o y y.c

clean:
	rm -f x y
