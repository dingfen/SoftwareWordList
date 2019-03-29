CC=g++ -std=c++11
FILE=./src/*.cpp
CFLAGS=-fprofile-arcs -ftest-coverage

WordList: $(FILE)
	$(CC) $(CFLAGS) -o WordList $(FILE)
	./WordList
	lcov -c -d . -o test.info
	genhtml -o result test.info

clean:
	rm -rf WordList *.gcda *.gcno *.info result	
