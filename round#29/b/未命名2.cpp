#include <iostream>
#include <stdio.h>
#include <string.h>
#define eps 1e-10

using namespace std;

int main()
{
    double l, d, v, g, r;
    while(cin>>l>>d>>v>>g>>r)
    {                    
         double t1 = d/v;
         int k(1);
         for(double i = g + r; t1 - i >= eps; i += (g+r))
         {
             ++k;
         }
         if((k-1) * (g + r) + g <= t1)  t1 = k * (g+r);
         t1 += (l-d) / v;
         printf("%.8lf\n",t1);
    }
    return 0;
}