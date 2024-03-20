all: add-nbo

add-nbo:
	gcc -o add-nbo add-nbo.cpp

clean:
	rm add-nbo *.bin
