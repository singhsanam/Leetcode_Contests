class Solution {
public:

    int minimumMoves(vector<vector<int>>& a) {
        int i,j,p,q;
        int n1;
        vector<vector<int>>v1;
        vector<vector<int>>v2;
        for(p=0;p<3;p++){
            for(q=0;q<3;q++){
                while(a[p][q]>1){
                    v1.push_back({p,q});
                    a[p][q]--;
                }
                if(a[p][q]==0) v2.push_back({p,q});
            }
        }
        int n=v1.size(),k=1;
        n1=n;
        while(n>0){
            k=k*n;
            n--;
        }
        int ans=1e9;
        while(k--){
            int c=0;
            for(i=0;i<n1;i++){
                c+=abs(v1[i][0]-v2[i][0])+abs(v1[i][1]-v2[i][1]);
            }
            ans=min(ans,c);
            next_permutation(v1.begin(),v1.end());
        }
        return ans;

    }
};
// 1 2 2
// 1 1 0
// 0 1 1
// [[1,2,2],[1,1,0],[0,1,1]]
// 3 2 0
// 0 1 0
// 0 3 0
//[[0,2,3],[2,0,1],[0,1,0]]
// 0 2 3
// 2 0 1
// 0 1 0