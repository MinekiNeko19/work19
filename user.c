#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {

    char line[100];
    int e = 1;

    while (e) {        
        // copied from work18
        close(ctop[WRITE]);
        close(ptoc[READ]);
        printf("Enter input (exit to exit): ");
        fgets(line, 100, stdin);

        if (!strcmp(line, "exit\n")) {
            e = 0;
        } else {
            write(ptoc[WRITE], line, 100);   
            char line[100];
            read(ctop[READ], line, 100);
            printf("parent got from child: %s\n",line);
        }   
    }

    return 0;
}