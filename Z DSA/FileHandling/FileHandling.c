#include <stdio.h>

int main()
{
    FILE *filePtr;
    char ch;

    filePtr = fopen("test.txt", "r");

    if (filePtr == NULL)
    {
        printf("File can not be open.");
        return 0;
    }

    printf("Reading File character by character: \n");

    do
    {
        ch = fgetc(filePtr);
        printf("%c", ch);
    } while (ch != EOF);

    fclose(filePtr);

    printf("\n\n");

    // Reading file by line by line
    filePtr = fopen("test.txt", "r");

    char str[100];

    printf("Reading File line by line: \n");
    while (fgets(str, 50, filePtr) != NULL)
    {
        printf("%s", str);
    }

    printf("\n\n");
    fclose(filePtr);

    return 0;
}