write system call wrapper (GNU/Linux and Mac OS X)

Just an example of using the dynamic linker to wrap an
existing function, defined in an external library, with
the purpose of adding extra functionality on top of it.

In this case the external library is the C library, and
the function is the write() system call wrapper.

