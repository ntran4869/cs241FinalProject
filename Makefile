all: checkersboard

checkersboard: checkersboard.cpp
	g++ -o checkersboard checkersboard.cpp

clean:
	rm -f checkersboard
