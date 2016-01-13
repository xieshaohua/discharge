
src := main.c
target := discharge

all:
	gcc $(src) -lpthread -o $(target)
