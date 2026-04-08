
image:image.c image.h
	gcc -g image.c -o image -lm

threads:threads.c threads.h
	gcc -g threads.c -o threads -lpthread

openmp:openmp.c image.h
	gcc -g openmp.c -o openmp -fopenmp

clean:
	rm -f image output.png threads output2.png openmp output3.png