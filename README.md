# get_next_line@42  

The aim of this project is to return a line ending with a new line, read from a file descriptor.  
Reading a line on a fd is way too tedious. This is the project after [fillit](https://github.com/yixuandang/fillit) and also it is my third project in University 42.

------------------------------------------------------------

### Compile 

It can be complied like this:  
`make -C libft/ fclean && make -C libft/`  
Then  
`clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c`  
`clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c`  
`clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft`  
PS:  
I put some extra main.c files in the folder  
`main_rdfile.c` is reading from a file.  
`main_stdinput.c` is reading from a standard input.  
if you want to test the project just change the `main_rdfile.c` or `main_stdinput.c` to `main.c` and then run the compile command.  

-------------------------------------------------------------

### Excutable

Once the file get compiled, run `./test_gnl (filename)`  
It should get the output of each line whenever we call the function.:) 

-------------------------------------------------------------

Please contact me if you run into any issues.
