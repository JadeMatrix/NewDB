CC = clang
CPPC = ${CC}++
# Using C89 because I'm a masochist
CCFLAGS = -std=c89 -Wall -pedantic -Wpadded
CPPCFLAGS = -Wall -pedantic -Wpadded
COMPILE_FLAGS = ``
# LINK_FLAGS = `` -lrt
LINK_FLAGS = ``

# Debug symbols:
#  - DEBUG
#    All debug symbols
#  - DEBUG_VM_ARGCHECK
#    Checks argument types & counts in VM instructions where such checks would
#    impact performace (already enabled where it doesn't)

# Recipes for executables ######################################################

make/test: make/ndb_vm.o make/ndb_vm_builtin.o make/ndb_vm_builtin.ndb_builtin2str.o make/ndb_statcode.o
	${CPPC} ${LINK_FLAGS} make/ndb_vm.o make/ndb_vm_builtin.o make/ndb_vm_builtin.ndb_builtin2str.o make/ndb_statcode.o -o make/test

# Recipes for object files #####################################################

make/ndb_vm.o: src/ndb_vm.c src/ndb_vm.h src/ndb_vm_builtin.h
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm.c -o make/ndb_vm.o

make/ndb_vm_builtin.o: src/ndb_vm_builtin.c src/ndb_vm_builtin.h
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm_builtin.c -o make/ndb_vm_builtin.o

make/ndb_vm_builtin.ndb_builtin2str.o: src/ndb_vm_builtin.cpp src/ndb_vm_builtin.h
	@mkdir -p $(@D)
	${CPPC} ${CPPCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm_builtin.cpp -o make/ndb_vm_builtin.ndb_builtin2str.o

make/ndb_statcode.o: src/ndb_statcode.c src/ndb_statcode.h
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_statcode.c -o make/ndb_statcode.o

# Phony recipes ################################################################

all: 

clean:
	rm -rf make

.PHONY: all clean


