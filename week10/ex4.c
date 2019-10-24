#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


char ***inodes;
// inodes = [
//    ["1234", "file1", "file2"],
//    ["235", "file3"],
//    ["456", "file4"],
//    ["567", "file5"], 
// ]
// size = 4
// sizes = [3, 2, 2, 2]
int size;
int *sizes;

void add_file(char* filename, long long int inode)
{
    bool flag = false;
    char *inode_str = calloc(1024, sizeof(char));
    sprintf(inode_str, "%lld", inode);
    for(int i = 0; i < size; i++)
    {
        if(strcmp(inode_str,inodes[i][0]) == 0){
            char* copyfilename = calloc(1024,sizeof(char));
            strcpy(copyfilename,filename);
            inodes[i][sizes[i]++] = copyfilename;
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        inodes[size] = calloc(1024, sizeof(char*));
        inodes[size][0] = inode_str;
        char* copyfilename = calloc(1024,sizeof(char));
        strcpy(copyfilename,filename);
        inodes[size][1] = copyfilename;
        sizes[size] = 2;
        size++;
    }
}
void print(char **arr,int size)
{
    printf("%s: ", arr[0]);
    for(int i = 1; i < size; i++){
        printf("%s ", arr[i]);
    }
    printf("\n");
}
int main(){
    DIR *dirp = opendir("tmp");
    struct dirent *dp; //gonna hold files or directories inside tmp
    struct stat *st; //gonna hold the info about the directory entry

    inodes = calloc(1024, sizeof(char**));
    size = 0;
    sizes = calloc(1024, sizeof(int));

    while((dp = readdir(dirp)) != NULL){
        st = malloc(sizeof(struct stat));
        char *f_path = calloc(1024, sizeof(char));
        strcpy(f_path, "tmp/");
        strcpy(f_path + 4, dp->d_name);
        if( stat(f_path, st) == -1 ) {
            printf("Failed to stat the file %s\n", f_path);
            return 1;
        }
        free(f_path);
        add_file(dp->d_name,(long long int) st->st_ino);
        free(st);
    }
    closedir(dirp);
    for(int i = 0; i < size; i++ ){
        if(sizes[i] >= 3)
            print(inodes[i],sizes[i]);
        for(int j = 0; j < sizes[i]; j++){
            free(inodes[i][j]);
        }
        free(inodes[i]);
    }
    free(inodes);

    return 0;
}