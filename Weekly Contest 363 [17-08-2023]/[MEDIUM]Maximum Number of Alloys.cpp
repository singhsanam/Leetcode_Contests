#define ll long long
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& comp, vector<int>& stock, vector<int>& cost) {
        ll i,j,x,y;
        int ans=0;
        for(i=0;i<comp.size();i++){
            ll l=0,r=1e9;
            int ansx=0;
            while(l<=r){
                ll mid=l+(r-l)/2;
                ll cost1=0;
                for(j=0;j<comp[i].size();j++){
                    ll x=1ll*comp[i][j]*mid;
                    ll y=1ll*(x-stock[j])*cost[j];
                    cost1+=max(y,0ll);
                }
                if(cost1<=budget){
                    ansx=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            ans=max(ans,ansx);
        }
        return ans;
    }
};