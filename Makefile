CC = clang
# Using C89 because I'm a masochist
CCFLAGS = -std=c89 -Wall -pedantic
# COMPILE_FLAGS = ``
# LINK_FLAGS = `` -lrt

# Recipes for executables ######################################################

# make/foo: make/foo.o
	# ${CC} ${CCFLAGS} ${LINK_FLAGS} make/foo.o -o make/foo

# Recipes for object files #####################################################

# make/foo.o: make_dir foo.c
# 	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c foo.c -o make/foo.o

# "Recipes" (header dependencies) for source files #############################

# foo.c: foo.h

# Phony recipes ################################################################

all: 

make_dir:
	mkdir -p make

clean:
	rm -rf make

.PHONY: all clean make_dir


