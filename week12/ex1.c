#include <stdio.h>

int main()
{
    FILE *f = fopen("/dev/random","r");
    FILE *output = fopen("ex1.txt","w");

    char str[21]; // 20 symbols + null terminator
    for(int i = 0; i < 20; i++){ 
        fscanf(f,"%c", &str[i]);//reading from the /dev/random file
    }
    str[20] = '\0';// null terminator
    fprintf(output, "%s", str); //write the string into the output file

    fclose(f);
    fclose(output);
    return 0;
}