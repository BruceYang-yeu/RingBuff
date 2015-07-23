test: main.o ring_que.o
	gcc  main.o ring_que.o -o  test
main.o: main.c
	gcc  -c main.c

ring_que.o:ring_que.c
	gcc  -c ring_que.c 
