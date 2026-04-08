
image:image.c image.h
	gcc -g image.c -o image -lm

threads:threads.c threads.h
	gcc -g threads.c -o threads -lpthread

clean:
	rm -f image output.png threads output2.png