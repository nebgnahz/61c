all: openmp pi simd

openmp: openmp.c
	gcc-7 -fopenmp -fdump-tree-optimized -O2 $< -o $@

simd: simd.c
	gcc-7 -msse4 -O2 $< -o $@

pi: pi.c
	gcc-7 -fopenmp -O2 $< -o $@

clean:
	rm -f openmp pi
