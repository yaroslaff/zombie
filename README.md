# Zombie - small zombie program for learning/debugging

## Compile
~~~
$ make
gcc -Wall -g   -o zombie zombie.c
~~~

dymanic ELF binary is 18Kb, static (gcc -Wall -g --static   -o zombie zombie.c) 800Kb

You can find statically compiled binary in Releases page.

## Usage:
Accepts one argument (int), sleep time. Default value is 30.

~~~
$ ./zombie 50
Parent process (PID: 1011803) is running, child (PID: 1011804) will become a zombie.
Child process (PID: 1011804) is exiting.
~~~

When it's running, in ps you can see:
~~~
$ ps auxww|grep zombie
xenon    1011803  0.0  0.0   2364   568 pts/6    S+   20:44   0:00 ./zombie 50
xenon    1011804  0.0  0.0      0     0 pts/6    Z+   20:44   0:00 [zombie] <defunct>
~~~