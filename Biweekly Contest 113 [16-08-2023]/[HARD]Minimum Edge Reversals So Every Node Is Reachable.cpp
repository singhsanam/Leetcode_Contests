class Solution {
public:
    map<pair<int,int>,int>m1;
    void rec(int u,int par,vector<vector<int>>&adj,vector<int>&dp){
        for(auto v:adj[u]){
            if(v!=par){
                rec(v,u,adj,dp);
                dp[u]+=dp[v];
                dp[u]+=m1[{v,u}];
            }
        }
    }
    void rerout(int u,int par,vector<vector<int>>&adj,vector<int>&dp){
        int ans=dp[u];
        if(par!=-1)
        ans=dp[par]-(dp[u]+m1[{u,par}])+dp[u]+m1[{par,u}];
        dp[u]=ans;
        for(auto v:adj[u]){
            if(v!=par){
                rerout(v,u,adj,dp);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& ed) {
        m1.clear();
        vector<vector<int>>adj(n);
        vector<int>dp(n,0);
        int i,j,x,y;
        for(i=0;i<n-1;i++){
            int x=ed[i][0];
            int y=ed[i][1];
            m1[{x,y}]=1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        rec(0,-1,adj,dp);
        rerout(0,-1,adj,dp);
        return dp;
    }
};