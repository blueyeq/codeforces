#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

char ch[1010];
bool fg[300];
int main()
{
    while(scanf("%s", ch) != EOF)
    {
        int n = strlen(ch);
        for(int i = 0; i < n; ++i)
            if(ch[i] >= 'A' && ch[i] <= 'Z')  ch[i] = ch[i] - 'A' + 'a';
        memset(fg, 0, sizeof(fg));
        fg['a'] = fg['e'] = fg['i'] = fg['o'] = fg['u'] = fg['y'] = 1; // "A", "O", "Y", "E", "U", "I"
        for(int i = 0; i < n; ++i)
        {
            if(fg[ch[i]])  continue;
            else printf(".%c", ch[i]);
        }
        puts("");
    }


    return 0;
}
