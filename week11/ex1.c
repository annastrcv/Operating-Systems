#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main(){
    int fd = open("ex1.txt", O_RDWR);//open the file
    void* ad = mmap(NULL, 1024, PROT_READ | PROT_WRITE,MAP_SHARED,fd, 0);//map to the virtual memory
    char* string = "This is a nice day"; // create string 
    memcpy(ad, string, strlen(string)); // copy the string 
    close(fd);
    return 0;
}