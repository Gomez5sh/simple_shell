# simple_shell
# Jian-Stephen Simple Shell

![logo](/unix.png)

### Project details
-----
This program is a simple shell that can be compiled and launched from the command line within any distro of Linux versions. It contains basic features and functions found in the various shell programs.


### Background
-----
The `Simple Shell` project is a team project conducted by Cristian Hurtado and Emmanuel Gomez, students at Holberton School Bogota. It consists of developing and makng our own `DASH` - Debian Almquist shell found in several versions of Linux. Creating of `DASH` was the general guidance, having the same exact functionalities and features was not the goal.

### Quick Start
-----
1. Git clone all this respository to your local directory.
```
$ git clone https://github.com/g5sh/simple_shell.git
```
2. Compile the program.
```
$ gcc -Wall -Werror -Wextra -pedantic shell.c header.h funtions.c strcmp.c -o sshell
```
3. Execute the shell.
```
$ ./sshell
```
Note: You need to compile gcc 4.8.4

#### Example
Interactive mode:
```
JS$ /bin/ls
```
or
```
JS$ ls -l
```
or
```
JS$ cat textfile
```
Non-interactive mode:
```
$ echo "ls -l" | ./hsh
```

### Builtin Commands
-----
This shell supports a variety of builtin commands:

`cd` - change directory

`env` - list the current environment variables

`exit` - exit the shell

`setenv` - sets an environment variable

`unsetenv` - unsets an environment variable

```
### Authors
-----
[Cristian Hurtado](https://github.com/cristian0497)

[Emmanuel Gomez](https://github.com/g5sh)
