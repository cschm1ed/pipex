# Pipex - Handling Pipes

## Learning Outcomes

- **UNIX Pipes**: Acquired skills in working with UNIX pipes to connect the output of one process to the input of another.
- **Process Management**: Gained experience in managing processes using fork, execve, and wait functions.
- **File Handling**: Learned file handling techniques, including opening, closing, reading, and writing files.
- **Exit Codes**: Developed proficiency in managing exit codes to communicate the status of a program's execution.

## Implementation Rules

 - **Allowed functions:** open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid ft_printf and any equivalent YOU coded
 - **Error Handling:** errors should be thoroughly handled. There shoudl be no unexpected aborts, and there must be no memory leaks.

"./pipex file cmd1 cmd2 file2"

must behave exactly the same as:

< file1 cmd1 | cmd2 > file2

