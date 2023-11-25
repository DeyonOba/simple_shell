# simple_shell
Write a simple UNIX command line interpreter.

## So what is a simple shell?
This a command line interface for users to interact with a computer (e.g. Bash, Command prompt, Anaconda prompt e.t.c). My shell works in two modes interactive, and non interactive mode.

- **Interactive Mode**: Displays a prompt and then accepts input from users on runtime. The input comes from the terminal.

- **Non Interactive Mode**: Does not display a prompt and does accept input from user on runtime. The input comes from a Stream (i.e standard output) of a file or command.

This is a summary of my simple shell project functionality:

1. **Display a prompt**: This prompt (i.e. "$ ") notifies the user to type in a command.

2. **Save user input as a buffer**: The shell saves the input from the standard input (i.e. user) into a variable which stores strings, my shell does this using the function `getline`.

3. **Parse the data**: This involves converting the data into meaningful arguments that could then be executed using the function `strtok`, if their is an error the shell handles error by displaying an error message in the standard error file, and exits with the corresponding exit status code.

4. **Built in commands**: This shell has some built in functions (i.e. costume built commands) that the shell should first check for before handling the PATH, or absolute path.

5. **Handle PATH**: This shell handle the Path to executable in two different ways:
   - PATH: This the path found the in the environment variable called PATH, this path has numerous directories where your shell should search for executables. What happens if the path is not found in the enviroment Path?, then check for the absolute path.
   - Abosulte Path: This contains the complete path starting from the the home directory down to the excuteable.
Well if the command is not found or the absolute path executable does not exit, then their is an Error which the shell handles.

6. **Execute Command**: This shell first creates a child process where the arguments are executed, if the child fails the parent should handle the error.
7. **Display the Prompt Again**.
