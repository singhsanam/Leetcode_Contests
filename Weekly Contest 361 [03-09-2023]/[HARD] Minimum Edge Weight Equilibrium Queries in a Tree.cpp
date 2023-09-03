int LOG=15;
void rec(vector<vector<int>>&adj,vector<int>&isvis,int u,vector<vector<int>>&up,vector<int>&depth){
    isvis[u]=1;
    
    int i,j,p,q,x,y;
    for(auto v:adj[u]){
        if(isvis[v]==1)
        continue;
        depth[v]=depth[u]+1;
        up[v][0]=u;
        for(j=1;j<=LOG;j++){
            up[v][j]=up[up[v][j-1]][j-1];
        }
        rec(adj,isvis,v,up,depth);
    }
}  
int lca(vector<vector<int>>&up,vector<int>&depth,int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
 
    int k=depth[v]-depth[u];
    int i,j,x;
    for(i=0;i<=LOG;i++){
        x=1<<i;
        if((x&k)>0)
        v=up[v][i];
    }
    if(u==v) return v;
 
    for(i=LOG;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[v][0];
} 
class Solution {
public:
    void rec1(int u,int par,vector<vector<pair<int,int>>>&adj,vector<vector<int>>&dp){
        for(auto v:adj[u]){
            if(v.first!=par){
                int w=v.second;
                for(int j=1;j<=26;j++){
                    dp[j][v.first]=dp[j][u]+(j==w);
                    // if(j==w) dp[j][v]++;
                }
                rec1(v.first,u,adj,dp);
            }
        }
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& ed, vector<vector<int>>& qu) {
        vector<vector<int>>dp(27,vector<int>(n+1,0));
        vector<vector<pair<int,int>>>adj1(n+1);
        vector<vector<int>>adj(n+1);
        vector<int>isvis(n+1,0);
        vector<vector<int>>up(n+1,vector<int>(LOG+1,0));
        vector<int>depth(n+1,0);
        
        // vector<int>de(n+1,0);
        int m=ed.size(),i,j;
        for(i=0;i<m;i++){
            int x=ed[i][0]+1;
            int y=ed[i][1]+1;
            int w=ed[i][2];
            adj1[x].push_back({y,w});
            adj1[y].push_back({x,w});
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        rec(adj,isvis,1,up,depth);
        rec1(1,0,adj1,dp);

        int q=qu.size();
        vector<int>ans;
        for(i=0;i<q;i++){
            int x=qu[i][0]+1;
            int y=qu[i][1]+1;
            int z=lca(up,depth,x,y);

            if(depth[x]>depth[y]) swap(x,y);
            int an=1e9;
            if(z==x){
                for(j=1;j<=26;j++){
                    an=min(an,depth[y]-depth[z]-(dp[j][y]-dp[j][z]));
                }
                ans.push_back(an);
            }
            else{
                for(j=1;j<=26;j++){
                    an=min(an,depth[y]-depth[z]-(dp[j][y]-dp[j][z])+depth[x]-depth[z]-(dp[j][x]-dp[j][z]));
                    
                }
                ans.push_back(an);
            }
        }
        return ans;
        
    }
};