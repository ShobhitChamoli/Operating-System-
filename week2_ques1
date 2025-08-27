#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    DIR *dir;
    struct dirent *entry;
    dir=opendir(".");
    if(dir==NULL){
        printf("Error opening the Directory...\n");
        exit(1);
    }
    else{
        printf("Listing all File names in current directory...\n");
        while((entry=readdir(dir))!=NULL){
            printf("%s\n",entry->d_name);
        }
        closedir(dir);
        printf("All files Listed...\n");
    }
    return 0;
}
