class Solution {
public:
    int countWays(vector<int>& a) {
        int n=a.size();
        int ans=0;
        sort(a.begin(),a.end());
        map<int,int>f;
        set<int>s1;
        for(int i=0;i<n;i++){
            f[a[i]]++;
            s1.insert(a[i]);
        }
        int max1=a[0],c=0,max2=0;
        // for(i=0;i<n;i++){
        //     max1=max(max1,a[i]);
        //     if()
        // }
        s1.insert(1e9);
        for(auto s:s1){
            max1=max(max1,s);
            if(c<max1&&c>max2) ans++;
            c+=f[s];
            max2=max(max2,s);
            
        }
        if(a[0]!=0) ans++;
        return ans;
    }
};