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

# Include chains ###############################################################

# TODO: Auto-generate (automake?)
NDB_CONNECTION_H = src/ndb_connection.h
NDB_DEBUG_H = src/ndb_debug.h ${NDB_VM_H}
NDB_PAGE_H = src/ndb_page.h #{NDB_STATCODE_H} ${NDB_UTIL_H}
NDB_QUERY_H = src/ndb_query.h
NDB_STATCODE_H = src/ndb_statcode.h
NDB_VM_H = src/ndb_vm.h ${NDB_PAGE_H} ${NDB_CONNECTION_H} ${NDB_QUERY_H} ${NDB_STATCODE_H}
NDB_VM_BUILTIN_H = src/ndb_vm_builtin.h ${NDB_VM_H}
NDB_CHECKSUM_H = src/ndb_checksum.h ${NDB_UTIL_H} ${NDB_FIXEDWIDTH_H}
NDB_UTIL_H = src/ndb_util.h
NDB_FIXEDWIDTH_H = src/ndb_fixedwidth.h

# Recipes for executables ######################################################

make/test: make/ndb_vm.o make/ndb_vm_builtin.o make/ndb_debug.o make/ndb_page.o make/ndb_checksum.o
	${CPPC} ${LINK_FLAGS} make/ndb_vm.o make/ndb_vm_builtin.o make/ndb_debug.o make/ndb_page.o make/ndb_checksum.o -o make/test

# Recipes for object files #####################################################

make/ndb_vm.o: src/ndb_vm.c ${NDB_VM_H} ${NDB_VM_BUILTIN_H} ${NDB_DEBUG_H}
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm.c -o make/ndb_vm.o

make/ndb_vm_builtin.o: src/ndb_vm_builtin.c ${NDB_VM_BUILTIN_H}
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_vm_builtin.c -o make/ndb_vm_builtin.o

make/ndb_page.o: src/ndb_page.c ${NDB_PAGE_H} ${NDB_CHECKSUM_H}
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_page.c -o make/ndb_page.o

make/ndb_checksum.o: src/ndb_checksum.c ${NDB_CHECKSUM_H}
	@mkdir -p $(@D)
	${CC} ${CCFLAGS} ${COMPILE_FLAGS} -c src/ndb_checksum.c -o make/ndb_checksum.o

make/ndb_debug.o: src/ndb_debug.cpp ${NDB_DEBUG_H} ${NDB_VM_BUILTIN_H}
	@mkdir -p $(@D)
	${CPPC} ${CPPCFLAGS} ${COMPILE_FLAGS} -c src/ndb_debug.cpp -o make/ndb_debug.o

# Other recipes ################################################################

src/ndb_fixedwidth.h: make/ndb_make_fixedwidth_h
	@./make/ndb_make_fixedwidth_h > src/ndb_fixedwidth.h

make/ndb_make_fixedwidth_h: src/ndb_make_fixedwidth_h.c
	@mkdir -p $(@D)
	@${CC} ${CCFLAGS} ${COMPILE_FLAGS} ${LINK_FLAGS} src/ndb_make_fixedwidth_h.c -o make/ndb_make_fixedwidth_h

# Phony recipes ################################################################

all: 

clean:
	rm -rf make

.PHONY: all clean


