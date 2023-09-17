class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size(),max1=1;
        map<int,int>m1;
        for(int i=0;i<n;i++){
            m1[nums[i]]++;
            max1=max(max1,m1[nums[i]]);
        }
        int ans=max1-(n-max1);
        if(ans<0) ans=0;
        if(n%2==1) ans=max(ans,1);
        return ans;
    }
};