#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    system("mpstat| grep -w \"all\"| awk '{o = 100-$NF; if(o > 70){print \"overload\"}
			 else if(30 < o && o < 70) {print \"moderately loaded \"} else {print \"lightly-loaded\"}}'");

    return 0;
}