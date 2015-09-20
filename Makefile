CC = clang
# Using C89 because I'm a masochist
CCFLAGS = -std=c89 -Wall -pedantic -Wpadded
COMPILE_FLAGS = ``
# LINK_FLAGS = `` -lrt
LINK_FLAGS = ``

# Recipes for executables ######################################################

# make/foo: make/foo.o
	# ${CC} ${CCFLAGS} ${LINK_FLAGS} make/foo.o -o make/foo

# Recipes for object files #####################################################

make/ndb_vm.o: src/ndb_vm.c src/ndb_vm.h src/ndb_vm_builtin.h
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm.c -o make/ndb_vm.o

make/ndb_vm_builtin.o: src/ndb_vm_builtin.c src/ndb_vm_builtin.h
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm_builtin.c -o make/ndb_vm_builtin.o

# Phony recipes ################################################################

all: 

clean:
	rm -rf make

.PHONY: all clean


