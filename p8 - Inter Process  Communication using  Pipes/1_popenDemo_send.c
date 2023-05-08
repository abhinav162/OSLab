// Program to demonstrate the use of popen() function
// popen() function opens a process by creating a pipe, forking and invoking the shell
// popen() function returns a pointer to a stream that can be used to either read from or write to the pipe
// Below is the program to send a string to the wc -c command using popen() function and count the number of characters in the string

#include <stdio.h>      //Standard I/O header file 
#include <string.h>     //String operations header file
int main()
{
    FILE *rd;    //File pointer to store the opened file
    char buffer[50];   //character array to store the text to be written in a file
    sprintf(buffer, "name first");   //Formats string and stores it in buffer
    rd = popen("wc -c", "w"); //Opens the specified command filename for writing, associated with stream  
    fwrite(buffer, sizeof(char), strlen(buffer), rd);  // fwrite() writes data from the array pointed to, by ptr to the given stream (ie, it will take the string stored in buffer and execute the command wc -c and store the output in rd)
    pclose(rd);  //Closes the given stream and its associated process 
}