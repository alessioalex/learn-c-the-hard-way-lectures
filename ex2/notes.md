## Makefile example

# comment
# (note: the <tab> in the command line is necessary for make to work) 
target:  dependency1 dependency2 ...
      <tab> command

for example:
#
# target entry to build program executable from program and mylib 
# object files 
#
program: program.o mylib.o
	gcc -o program program.o mylib.o

## CFLAGS

-g    adds debugging information to the executable file
-Wall turns on most, but not all, compiler warnings

## More on makefiles

https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
