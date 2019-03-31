make

FILE="test/test_5.txt test/test_6.txt test/test_4.txt test/test_9.txt test/test_11.txt"

bin/WordList $FILE
lcov -c -d . -o test.info
genhtml -o result test.info
rm  *.gcda *.gcno *.info