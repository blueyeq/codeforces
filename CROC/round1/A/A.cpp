#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

char s1[1010], s2[1010];
int sum1[1001000], sum2[1001000];

int get(char c1, char c2)
{
    if(c1 == c2)  return 0;
    if(c1 == 'R' && c2 == 'S') return 1;
    if(c1 == 'S' && c2 == 'R') return -1;
    if(c1 == 'S' && c2 == 'P') return 1;
    if(c1 == 'P' && c2 == 'S') return -1;
    if(c1 == 'P' && c2 == 'R') return 1;
    if(c1 == 'R' && c2 == 'P') return -1;
    return -3;
}

int main()
{
    int n;
    scanf("%d", &n);
    {
        scanf("%s%s",s1, s2);
        int la = strlen(s1);
        int lb = strlen(s2);
        int lcm = la * lb / gcd(la, lb);
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        for(int i = 0; i < lcm; ++i)
        {
            char c1 = s1[i % la];
            char c2 = s2[i % lb];
            int tmp = get(c1, c2);

            if(i > 0)
            {
                sum1[i] = sum1[i - 1];
                sum2[i] = sum2[i - 1];
            }
            else  sum1[0] = sum2[0] = 0;
            if(tmp == 1) sum2[i]++;
            if(tmp == -1)  sum1[i]++;
        }
        int ans1 = n / lcm * sum1[lcm - 1];
        int ans2 = n / lcm * sum2[lcm - 1];
        if(n % lcm)
        {
            ans1 += sum1[n % lcm - 1];
            ans2 += sum2[n % lcm - 1];
        }
        printf("%d %d\n",ans1, ans2);
    }

    return 0;
}
