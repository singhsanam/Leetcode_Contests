class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& a, int k) {
        int n=a.size(),ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            int x=i;
            while(x>0){
                x=(x&(x-1));
                c++;
            }
            if(c==k) ans+=a[i];
        }
        return ans;
        
    }
};