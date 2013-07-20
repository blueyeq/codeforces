#include <string>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
struct Mat
{
    int x1, y1, x2, y2, val, h;
}mat[MAXN];

bool Nocross(Mat mat1, Mat mat2)
{
   return (mat1.x1 > mat2.x2 || mat1.y1 > mat2.y2 || mat1.x2 < mat2.x1 || mat1.y2 < mat2.y1);
}

int main()
{
//    freopen("in.c", "r", stdin);
    int row, col, m;
    while(scanf("%d%d%d", &row, &col, &m) != EOF)
    {
        for(int i = 0; i < m; ++i)
        {
            int  a, b, h;
            scanf("%d%d%d%d%d", &a, &b, &mat[i].h, &mat[i].x1, &mat[i].y1);
            mat[i].x2 = min(row - 1, mat[i].x1 + a - 1);
            mat[i].y2 = min(col - 1, mat[i].y1 + b - 1);
            mat[i].val = 0;
        }

        for(int i = 0; i < m; ++i)
        {
            mat[i].val += mat[i].h;
            for(int j = i + 1; j < m; ++j)
            {
                if(Nocross(mat[i], mat[j]))continue;
                mat[j].val = max(mat[j].val, mat[i].val);

            }
        }
        int ans(0);
        for(int i = 0; i < m; ++i)  ans = max(ans, mat[i].val);
        printf("%d\n", ans);
    }
    return 0;
}
