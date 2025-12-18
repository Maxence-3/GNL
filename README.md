_This project has been created as part of the 42 curriculum by mde-carv_

## Description

Hi, here is my get_next_line project (GNL). GNL is a function that returns the readed line from a file descriptor. It got the BUFFER_SIZE set by the user or by
default defined at '1000', that represents the number of size 'read()' is allowed to.. read.

## Instructions

Check with 'norminette', add a main.c or uncomment the main in get_next_line.c then
compile with 'cc -Wall -Werror -Wextra', and if you would like to set the value of BUFFER_SIZE, 
add the option '-D BUFFER_SIZE={nb of your choice beside negative value}'

## Resources

* Functionning of the file descriptor - [codequoi](https://www.codequoi.com/manipuler-un-fichier-a-laide-de-son-descripteur-en-c/)
* Static Variables - [geeksforsgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)

## Technical choices

GNL read each time at least one time the size of BUFFER_SIZE and if needed, read while '\n' is not encountered and
while read's return value is superior to 0. A static variable 'next' is used to store excess readen caracters. At first
GNL allocate memory to 'buffer', and if 'next' is not empty, the contained caracters are added, and finally the
variable that checks read's return value is set to 1 to enter in the first while loop. when '\n' or '\0' is reached, read()
stops, the caracters in excess are stocked in the static, and returns the readed line.

- get_next_line.c : contains prototype of get_next_line and 4 other helper functions + commented main
- get_next_line_utils.c : contains 5 more helper functions coded before from libft (strjoin, calloc, strchr, strdup, strndup)
- get_next_line.h : header file