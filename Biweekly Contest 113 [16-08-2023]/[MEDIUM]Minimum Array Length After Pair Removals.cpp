class Solution {
public:
    int countPairs(vector<vector<int>>& co, int k) {// base case for k=0
        int n=co.size();
        int i,j,x,y;
        map<int,int>m2;
        map<pair<int,int>,int>m1;
        int ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<=k;j++){
                int x=j^co[i][0],y=(k-j)^co[i][1];
                // if(m1.find({x,y})!=m1.end())
                    ans+=m1[{x,y}];
            }
            m1[{co[i][0],co[i][1]}]++;
        }
        if(k==0){
            ans=0;
            for(i=0;i<n;i++){
                int x=m1[{co[i][0],co[i][1]}];
                ans+=1ll*x*(x-1)/2;
                m1[{co[i][0],co[i][1]}]=0;
            }
        }
        return ans;
        
        
    }
};