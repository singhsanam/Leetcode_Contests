class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int min1=abs(sx-fx)+abs(sy-fy);
        min1-=min(abs(sx-fx),abs(sy-fy));
        if(t<min1) return 0;
        if(t==1 && min1==0) return 0;
        return 1;
    }
};