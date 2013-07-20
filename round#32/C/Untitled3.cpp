#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    long long  row, col, len, h, v;
    while(cin>>row>>col>>len)
    {
        cout<<((row-1) % len + 1) * ((row-1) / len + 1) * ((col - 1) % len + 1) * ((col - 1) / len + 1) ;
    }
    return 0;
}
