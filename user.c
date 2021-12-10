#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    mkfifo("utow",0644);
    mkfifo("wtou",0644);

    int fromw = open("wtou",O_RDONLY);
    int tow = open("utow",O_WRONLY);
    // printf("fromw: %d\ttow: %d\n",fromw,tow);

    int e = 1;

    while (e) {        
        // copied from work18
        char line[100];
        printf("Enter input (exit to exit): ");
        fgets(line, 100, stdin);

        if (!strcmp(line, "exit\n")) {
            e = 0;
        } else {
            write(tow, line, 100);
            read(fromw, line, 100);
            printf("parent got from child: %s\n",line);
        }
    }

    return 0;
}