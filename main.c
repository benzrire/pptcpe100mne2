#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

int main()
{
    char buffer[MAX];
    int i;
    FILE *fp;

    fp = fopen("output.txt", "w");

    while(1) {
        printf("Input : ");
        fgets(buffer, MAX, stdin);
        sscanf(buffer, "%s", buffer);
        strlwr(buffer);

        if(strcmp(buffer, "quit") == 0) {
            break;
        }

        for(i = 0; i < strlen(buffer); i++) {
            if(buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u') {
                buffer[i] = toupper(buffer[i]);
            }
        }
        printf("(%d) %s\n", strlen(buffer), buffer);
        fprintf(fp, "%s\n", buffer);
    }

    fclose(fp);

    return 0;
}
