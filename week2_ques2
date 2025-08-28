#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
int main() { 
    printf("Executing ls command using execlp():\n"); 
    if (execlp("ls", "ls", "-l", NULL) == -1) { 
        perror("execip failed"); 
        return 1; 
    } 
    printf("This will not be printed if execlp() executes successfully.\n"); 
    return 0; 
}
