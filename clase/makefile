results.png: runs.dat
	python3 graph.py

runs.dat: integral.x
	mpiexec -np 4 ./integral.x 1000 >> runs.dat
	mpiexec -np 4 ./integral.x 10000 >> runs.dat	
	mpiexec -np 4 ./integral.x 100000 >> runs.dat
	mpiexec -np 4 ./integral.x 1000000 >> runs.dat
	mpiexec -np 4 ./integral.x 10000000 >> runs.dat
	mpiexec -np 4 ./integral.x 100000000 >> runs.dat
integral.x:
	mpicc integra.c -o integral.x
clean:
	rm *.png
	rm *.x
	rm *.dat
