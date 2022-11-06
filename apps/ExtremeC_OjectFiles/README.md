# Executable Object Files - Example 3.1

Generate relocatable object files:

 - gcc -c examples_chapter3_1_funcs.c -o funcs.o
 - gcc -c examples_chapter3_1.c -o main.o

To see file sections:

- readelf -hSl funcs.o

Mac alternative

- otool -t main.o

Dump the symbol table

 - readelf -s main.o

 Generate executable file

 - gcc funcs.o main.o -o ex3_1.out

 # Static Linking - Example 3.2

 First create object files:

 - `gcc -c examples_chapter3_2_funcs.c -o maxMin.o`

Archive object files into static library file:

- `ar crs libMinMax.a maxMin.o`

to see exported symbols:

- `nm libMinMax.a `

to see content of the archived file:

- `ar t libMinMax.a`

Create main object file and link the library

- `gcc -c examples_chapter3_2.c -o main2.o`
- `gcc main2.o -L./ -lMinMax -lm -o ex3_2.out`

# Dynamic Libraries

create object files with fPIC:

- `gcc -c examples_chapter3_2_funcs.c -fPIC -o maxMin_d.o`

create a shared object:

- `gcc -shared maxMin_d.o -o libMinMax_d.so`

Create executable and link shared object

create main object file and generate output:

- `gcc -c examples_chapter3_2.c -o main_d.o`
- `gcc main_d.o -L./ -lMinMax_d -lm -o ex3_d.out`

check what you link and execute on MAC

- `otool -L ./ex3_d.out`
- `LD_LIBRARY_PATH=./ ./ex3_d.out`
