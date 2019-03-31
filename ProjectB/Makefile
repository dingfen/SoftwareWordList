CC=g++ -std=c++11
FILE=./src/*.cpp
CFLAGS=-fprofile-arcs -ftest-coverage

LCOV=$(shell (which lcov))

ifeq ($(LCOV), )
	echo "No lcov found.Please install lcov first."
endif

all : WordList

WordList: $(FILE)
	$(CC) $(CFLAGS) -o bin/WordList $(FILE)

clean:
	rm  *.gcda *.gcno *.info	
