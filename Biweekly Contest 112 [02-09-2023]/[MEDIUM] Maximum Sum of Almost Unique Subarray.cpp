#define ll long long
class Solution {
public:
    long long maxSum(vector<int>& a, int m, int k) {
        // multiset<int>m1;
        map<int,int>m1;
        set<int>s1;
        int n=a.size(),i;
        ll sum=0,ans=0;
        for(i=0;i<k;i++){
            m1[a[i]]++;
            s1.insert(a[i]);
            sum+=a[i];
        }
        if(s1.size()>=m){
            ans=sum;
        }
        for(i=k;i<n;i++){
            m1[a[i-k]]--;
            if(m1[a[i-k]]==0) s1.erase(a[i-k]);
            m1[a[i]]++;
            if(m1[a[i]]==1) s1.insert(a[i]);
            sum-=a[i-k];
            sum+=a[i];
            if(s1.size()>=m){
                ans=max(ans,sum);
            }
        }
        return ans;
        
    }
};