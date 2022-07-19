Generate relocatable object files:

 - gcc -c examples_chapter3_1_funcs.c -o funcs.o
 - gcc -c examples_chapter3_1.c -o main.o

To see file sections:

- readelf -hSl funcs.o

Dump the symbol table

 - readelf -s main.o

 Generate executable file

 -gcc funcs.o main.o -o ex3_1.out

 