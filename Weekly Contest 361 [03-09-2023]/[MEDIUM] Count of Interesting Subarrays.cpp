#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& a, int m, int k) {
        int n=a.size();
        int pre[n+1],i;
        pre[0]=0;
        for(i=0;i<n;i++){
            if(a[i]%m==k) pre[i+1]=pre[i]+1;
            else pre[i+1]=pre[i];
        }
        map<int,int>m1;
        ll ans=0;
        for(i=0;i<=n;i++){
            // m1[pre[i]%m]++;
            int x=(pre[i]%m-k+m)%m;
            ans+=m1[x];
            m1[pre[i]%m]++;
        }
        return ans;
    }
};