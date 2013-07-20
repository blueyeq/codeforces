
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int sqr(int x)
{
    return x * x;
}
int con(int x1, int y1, int r1, int x2, int y2, int r2)
{
    if(sqr(x1 - x2) + sqr(y1 - y2) >= sqr(r1 + r2))  return 0;
    if(sqr(x1 - x2) + sqr(y1 - y2) <= sqr(r1 - r2))
    {
        if(r1 > r2)  return 1;
        return 2;
    }
    return 3;
}

int main()
{
//    freopen("B.in", "r", stdin);
    int x1, x2, y1, y2, r11, r12, r21, r22;
    while(scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &r11, &r12, &x2, &y2, &r21, &r22) != EOF)
    {
        int res(0);
        int t1 = con(x1, y1, r11, x2, y2, r21);
        int t2 = con(x1, y1, r11, x2, y2, r22);
        if((!t1 && !t2) || (t1 + t2 != 3 && t1 != 3 && t2 != 3)) ++res;
//        printf("%d %d\n", t1, t2);

        t1 = con(x1, y1, r12, x2, y2, r21);
        t2 = con(x1, y1, r12, x2, y2, r22);
        if((!t1 && !t2) || (t1 + t2 != 3 && t1 != 3 && t2 != 3)) ++res;
//        printf("%d %d\n", t1, t2);

        t1 = con(x1, y1, r11, x2, y2, r21);
        t2 = con(x1, y1, r12, x2, y2, r21);
        if((!t1 && !t2) || (t1 + t2 != 3 && t1 != 3 && t2 != 3)) ++res;
//        printf("%d %d\n", t1, t2);

        t1 = con(x1, y1, r11, x2, y2, r22);
        t2 = con(x1, y1, r12, x2, y2, r22);
        if((!t1 && !t2) || (t1 + t2 != 3 && t1 != 3 && t2 != 3)) ++res;
//        printf("%d %d\n", t1, t2);

        printf("%d\n", res);
    }

    return 0;
}
