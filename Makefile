OBJS = main.o tlistaPedidos.o tpedido.o tlista.o tproducto.o thora.o tcad.o base_de_datos.o
BINARY = programa 
CFLAGS = -lsqlite3 -Wall -pedantic -DTEST --debug

#si no paso argumentos has esto
#all: programa


programa: $(OBJS)
	gcc -o programa $(OBJS) $(CFLAGS)
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
	# $< => nombre del objetivo ( %.o )
	# $@ => nombre de la dependencia ( %.c )
	 
#main.o: main.c tpedido.h
#tpedido.o: tpedido.c tpedido.h
#thora.o: thora.c thora.h  
#tcad.o: tcad.c tcad.h
clean:
	rm -f $(BINARY) *.o
