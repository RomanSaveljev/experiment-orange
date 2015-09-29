all : build/libport.a

SOURCE_DIR := .

SYSROOT := $(shell ${CC} ${CFLAGS} -print-sysroot)
MULTIOS := $(shell ${CC} ${CFLAGS} -print-multi-os-directory)

ALL_OBJECTS := build/port.o build/heap_4.o

build/%.o : %.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $<

build/libport.a : ${ALL_OBJECTS}
	${AR} -cr $@ $^

install : build/libport.a
	install -m755 -d ${DESTDIR}${SYSROOT}/lib/${MULTIOS}
	install -m644 -t ${DESTDIR}${SYSROOT}/lib/${MULTIOS} $<
