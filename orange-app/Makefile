all : build/orange-app

SOURCE_DIR := .

ALL_OBJECTS := build/main.o

build/%.o : %.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $<

build/orange-app : ${ALL_OBJECTS}
	${CC} ${CFLAGS} -specs=nosys.specs -o $@ $^ -lfreertos -lport

install : build/orange-app
	install -m755 -d ${DESTDIR}/opt/orange-app
	install -m644 -t ${DESTDIR}/opt/orange-app $<
