n, T = map(int, raw_input().split());
dis = map(int, raw_input().split());
src = map(int, raw_input().split());

res = 0;
now = 0;
mx = 0;
for i in range(n):
    mx = max(mx, src[i]);
    now += src[i];
    if(now < dis[i]):
        tmp = (dis[i] - now + mx - 1) / mx;
        res += tmp * T;
        now += tmp * mx;
    
    res += dis[i];
    now -= dis[i];
print(res);
