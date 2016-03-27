## lldb (on OSX)

```
rm ex4 && CFLAGS="-g" make ex4
lldb ex4
breakpoint set --name main
step
step
...
```
