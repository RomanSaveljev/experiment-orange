all : build/libfreertos.a

SOURCE_DIR := freertos/FreeRTOS/Source

CFLAGS += -I${SOURCE_DIR}/include
SYSROOT := $(shell ${CC} ${CFLAGS} -print-sysroot)
MULTIOS := $(shell ${CC} ${CFLAGS} -print-multi-os-directory)

ALL_OBJECTS := $(addprefix build/${SOURCE_DIR}/,croutine.o event_groups.o list.o queue.o tasks.o timers.o)

build/%.o : %.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $<

build/libfreertos.a : ${ALL_OBJECTS}
	${AR} -cr $@ $^

ALL_INCLUDES := $(addprefix ${SOURCE_DIR}/include/, FreeRTOS.h StackMacros.h croutine.h deprecated_definitions.h event_groups.h list.h mpu_wrappers.h portable.h projdefs.h queue.h semphr.h stdint.readme task.h timers.h)

install : build/libfreertos.a
	install -m755 -d ${DESTDIR}${SYSROOT}/lib/${MULTIOS}
	install -m644 -t ${DESTDIR}${SYSROOT}/lib/${MULTIOS} $<
	install -m755 -d ${DESTDIR}${SYSROOT}/include
	install -m644 -t ${DESTDIR}${SYSROOT}/include ${ALL_INCLUDES}
