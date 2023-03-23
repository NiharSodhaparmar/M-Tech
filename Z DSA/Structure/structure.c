#include <stdio.h>

typedef struct structa_tag
{
    char c;
    short int s;
} structa_t;

typedef struct structb_tag
{
    short int s;
    char c;
    int i;
} structb_t;

// structure C
typedef struct structc_tag
{
    char c;
    double d;
    int s;
} structc_t;

// structure D
typedef struct structd_tag
{
    int s;
    char c;
    char c2;
    char c3;
    double d2;
    double d;

} structd_t;

int main()
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));
}