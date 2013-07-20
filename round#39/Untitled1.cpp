#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    while(cin>>x>>y)
    {
        double r = sqrt(x*x + y*y);
        int ri = int(r);
        if(r == ri || x == 0 || y == 0)   puts("black");
        else if(x * y > 0 && ri&1 || x * y < 0 && !ri&1)  puts("black");
        else  puts("white");

    }

    return 0;
}
