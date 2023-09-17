class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n=nums.size();
        int a[2*n],i;
        for(i=0;i<2*n;i++) a[i]=nums[i%n];
        int ans=-1;
        for(i=0;i<=n;i++){
            if(is_sorted(a+i,a+i+n)){
                ans=n-i;
            }
        }
        return ans;
    }
};