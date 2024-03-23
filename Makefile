all : main run 
cc = g++

main : main.cpp
	$(cc) -o main main.cpp -L /usr/local/lib/libraylib.a -lraylib -lm

run : 
	./main

clean : 
	rm ./main	