C-SIMPLE SHELL

   REQUIREMENTS
Language: C OS: Ubuntu 20.04 LTS Compiler: gcc 11.2.0 Style guidelines: Betty style

      DESCRIPTION OF EACH FILE
A code that passes the Betty checks

A UNIX command line interpreter.

Simple shell 0.1 +

Handle command lines with arguments

3.Simple shell 0.2 +

Handle the PATH fork must not be called if the command doesn’t exist

4.Simple shell 0.3 +

Implement the exit built-in, that exits the shell Usage: exit You don’t have to handle any argument to the built-in exit

Simple shell 0.4 +
Implement the env built-in, that prints the current environment

Simple shell 0.1 +
Write your own getline functions Use a buffer to read many chars at once and call the least possible the read system call You will need to use static variables You are not allowed to use getline

Simple shell 0.2 +
You are not allowed to use strtok

Simple shell 0.4 +
handle arguments for the built-in exit Usage: exit status, where status is an integer used to exit the shell

Simple shell 1.0 +
Implement the setenv and unsetenv builtin commands

Simple shell 1.0 +
Implement the builtin command cd

Simple shell 1.0 +
Handle the commands separator ;

Simple shell 1.0 +
Handle the && and || shell logical operators

13.Simple shell 1.0 +

Implement the alias builtin command

Simple shell 1.0 +
Handle variables replacement Handle the $? variable Handle the $$ variable

Simple shell 1.0 +
Handle comments (#)

Simple shell 1.0 +
Usage: simple_shell [filename] In this mode, the shell should not print a prompt and should not read from stdin
