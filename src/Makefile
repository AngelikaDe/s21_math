GCC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
LDFLAGS = -O2 -Wall -Werror -Wextra -std=c11
SOURCE = $(wildcard s21_*.c)
HEADER = $(wildcard s21_*.h)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
TESTS_SOURCE = tests.c
TESTS_OBJECTS = $(patsubst %.c,%.o, ${TESTS_SOURCE})
UNAME_S := $(shell uname -s)

all: clean s21_math.a test

s21_math.a: ${SOURCE}
	$(GCC) $(CFLAGS) $(ADD_LIB) $(SOURCE)
	ar rc $@ $(OBJECTS)
	ranlib $@
	cp $@ lib$@

test: ${TESTS_SOURCE} s21_math.a
	${GCC} $(LDFLAGS) -o test $^ -lcheck -lm
	./test

# gcov_report: s21_math.a 
# 	gcc --coverage $(ADD_LIB) ${SOURCE} ${TESTS_SOURCE} -o gcov_test -lcheck -lm -lpthread
# 	# ./gcov_test
# 	# lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
# 	# genhtml -o report gcov_test.info
# 	# open ./report/gcov_test.html

gcov_report: clean lcov ${SOURCE}
	gcc --coverage ${SOURCE} tests.c -o s21_test -lcheck
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif



clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf ./s21_test
