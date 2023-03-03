#include <bits/stdc++.h>
struct s
{
    char c[4];
};

int fn(int val)
{
    unsigned int x = (unsigned)val;

    if (x > (1 << 31))
        return -1;
    else if (x > 0)
        return 1;

    return 0;
}

int main()
{
    // struct s *s1 = (struct s *)"1234";

    // printf("%c%c%c%c%c", s1->c[0], s1->c[1], s1->c[2], s1->c[3]);

    // unsigned int a = 0xabcdef;

    // unsigned char *ptr = (unsigned char *)&a;

    // printf("%xnn", *ptr);

    // printf("%d %d %d", fn(-3), fn(2), fn(0));

    // struct bitfi
    // {
    //     unsigned int x : 2;
    //     unsigned int y : 2;
    // };

    // struct bitfi p;
    // p.x = 4;
    // p.y = 3;

    // printf("%d %d", p.x, p.y);

    // int num = 5;

    // for (int i = 0; i < 32; i++)
    // {
    //     printf("%d", (num << i & 1 << 31 ? 1 : 0));
    // }

    bool y = (int)(1.1 + 0.1) == int(1.1);

    printf("%d", y);
}
