# C - Simple Shell

This is an implementation of the standard shell done by <strong>Kelvin Warui</strong> and <strong>Alexander Maina</strong>. Our shell implements a few standard commands i.e ls, cat, echo and builtins such as the exit command.

### Synopsis
This repository holds all the code necessary for the shell to work.

### Builtins
* ```exit``` exits shell (```Usage: exit [status]```)
* ```env``` prints environmental variables (Usage: ```env```)
* ```setenv``` creates or modifies an environmental variable (Usage: ```setenv name value```)
* ```unsetenv``` removes an envrionmental variable (Usage: ```unsetenv name value```)
* ```cd``` changes directories (Usage: ```cd [-][~][path]```)

### Functions and system calls used
```read```, ```signal```, ```malloc```, ```free```, ```getcwd```, ```chdir```, ```access```, ```execve```, ```wait```, ```write```,  ```exit```

### Environment
* Language: C
* OS: Ubuntu 22.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style]

## How To Install, Compile, and Use
Install and Compile
```
(your_terminal)$ git clone https://github.com/Alekiie/simple_shell.git
(your_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o simple_shell
```
**Non-Interactive Mode**
```
echo "ls -l" | ./simple_shell
```
**Interactive Mode***
Activate the shell
```
(your_terminal)$ ./simple_shell
$
```
Sample Usage
```
$ echo "This is a pretty cool!"
This is pretty cool!
```
Stop and return to your original shell
```
$ exit
(your_terminal)$
```

### Authors
Kelvin Warui  <Kelvinwarui457@gmail.com><br>
Alexander Maina <amnjogu78@gmail.com>
