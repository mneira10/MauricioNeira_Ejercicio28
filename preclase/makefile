all: pi.x
	mpiexec -np 4 ./pi.x
pi.x:
	mpicc pi.c -o pi.x
clean:
	rm *.x