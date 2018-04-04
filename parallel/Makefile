all: openmp pi

openmp: openmp.c
	gcc-7 -fopenmp -O2 $< -o $@

pi: pi.c
	gcc-7 -fopenmp -O2 $< -o $@

clean:
	rm -f openmp pi
