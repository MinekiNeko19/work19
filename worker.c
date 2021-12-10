#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {    
    int fromu = open("wtou",O_WRONLY);
    int tou = open("utow",O_RDONLY);

    char line[100];
    int e = 1;

    while (e) {
        // copied from work18
        read(tou, line, 100);
        if (!strcmp(line, "exit\n")) {
            e = 0;
        } else {
            int i = 0;
            while (line[i] != '\n') {
                line[i] = toupper(line[i]);
                i++;
            }
            write(fromu, line, 100);
        }

    return 0;
    }
}