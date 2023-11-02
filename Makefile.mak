CC     = gcc
WINDRES= windres
RM     = rm -f
OBJS   = main.o \
         telas.o \
         validadores.o \
         pedidos.o \
         pessoas.o \
         produtos.o \
         AppResource.res

LIBS   =
CFLAGS =

.PHONY: Hamburgueria.exe clean clean-after

all: Hamburgueria.exe

clean:
	$(RM) $(OBJS) Hamburgueria.exe

clean-after:
	$(RM) $(OBJS)

Hamburgueria.exe: $(OBJS)
	$(CC) -Wall -s -o $@ $(OBJS) $(LIBS)

main.o: main.c telas.h validadores.h pedidos.h pessoas.h produtos.h
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

telas.o: telas.c telas.h
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

validadores.o: validadores.c validadores.h
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

pedidos.o: pedidos.c
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

pessoas.o: pessoas.c
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

produtos.o: produtos.c
	$(CC) -Wall -s -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

