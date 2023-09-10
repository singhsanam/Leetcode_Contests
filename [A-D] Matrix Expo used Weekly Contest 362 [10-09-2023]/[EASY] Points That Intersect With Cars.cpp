class Solution {
public:
    int numberOfPoints(vector<vector<int>>& a) {
        int n=a.size(),i,j;
        sort(a.begin(),a.end());
        int n1;
        for(i=0;i<n;i++){
            n1=max(n1,a[i][1]);
        }
        // int vis[n1+1];
        vector<int>vis(n1+1,0);
        for(i=0;i<n;i++){
            for(j=a[i][0];j<=a[i][1];j++){
                vis[j]=1;
            }
        }
        int ans=0;
        for(i=0;i<=n1;i++){
            ans+=vis[i];
        }
        return ans;
    }
};