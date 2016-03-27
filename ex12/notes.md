- The size of an int differs based on the compiler
(which in turn makes the decision based on the underlying hardware, for perf reasons).

- One of the elements of a string is '\0' (the last one); it might be added for you

- You cannot get the size of the data of a pointer, you need to keep track of it yourself
