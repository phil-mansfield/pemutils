# How to use:
# make - puts a library file in ./build
# make tests - runs all tests and benchmarks in ./tests. Assumes the existence
#              of a particular script called runTests.py in that particular
#              directory.
# make clean - removes temporary files and allows for a clean build.
#
# How to change to new project:
# Go to areas commented in this file and do what they say.

CC=gcc
CFLAGS=-O2 -Wall -Wextra -Werror -std=c99

SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
HEADERS=$(patsubst %.c,%.h,$(SOURCES))

# Change this as neccesary. If you aren't making a library, the vast majority of
# this Makefile will be useless to you. Name will be build/*lib.a
LIB_NAME=pemutil

TARGET=$(patsubst %,build/lib%.a,$(LIB_NAME))
SELF_FLAG=-lpemutil
# $(patsubst %,-l%,$(LIB_NAME))

SO_TARGET=$(patsubst, %.a,%.so,$(TARGET))

TEST_SOURCES=$(wildcard tests/*.c)
TESTS=$(patsubst %.c,%,$(TEST_SOURCES))

# Location of libraries being used.
LIBRARIES=
# Flags of libraries being used.
LIBRARY_FLAGS=
# Location of .h files which should be included.
INCLUDES=

ifneq ($(INCLUDES),)
	INCLUDES_WITH_FLAG=-I $(INCLUDES)
else
	INCLUDES_WITH_FLAG=$(INCLUDES)
endif

all: $(TARGET) $(SO_TARGET)

debug: CFLAGS += -g -D DEBUG_MODE
debug: all

build:
	mkdir -p build/

# Change this as needed for each object file. List dependencies that are
# not the corresponding .c and .h file.
pool.o:
%.o: %.c %.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES_WITH_FLAG)

$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(CFLAGS) += -fPIC
$(SO_TARGET): build $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

%_test: %_test.c $(TARGET)
	$(CC) $@.c -o $@ $(CFLAGS) -L build $(LIBRARIES) -I src $(INCLUDES) $(SELF_FLAG) $(LIBRARY_FLAGS)
%_bench: %_bench.c $(TARGET)
	$(CC) $@.c -o $@ $(CFLAGS) -L build $(LIBRARIES) -I src $(INCLUDES) $(SELF_FLAG) $(LIBRARY_FLAGS)

tests: $(TESTS)
	@python tests/runTests.py tests/ test
	@python tests/runTests.py tests/ bench

clean:
	rm -rf tmp/ build/
	rm -f src/*.o
	rm -f tests/*_test
	rm -f tests/*_bench