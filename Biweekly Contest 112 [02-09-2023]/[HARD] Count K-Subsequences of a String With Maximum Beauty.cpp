// int MOD=1e9+7;
// const int MAXL=64;
int power(int a, int b, int p){
    if(a==0)
    return 0;
    int res=1;
    a%=p;
    while(b>0)
    {
        if(b&1)
        res=(1ll*res*a)%p;
        b>>=1;
        a=(1ll*a*a)%p;
    }
    return res;
}
int modInverse(int n,int p)
{
	return power(n, p - 2, p);
}
class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int m=1e9+7;
        int f[26]={0};
        set<char>s1;
        int n=s.length(),i;
        for(i=0;i<n;i++){
            f[s[i]-'a']++;
            s1.insert(s[i]);
        }
        if(k>s1.size()) return 0;
        vector<pair<int,int>>v1;
        map<int,int>m1;
        for(i=0;i<26;i++){
            v1.push_back({f[i],i});
            m1[f[i]]++;
        }
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        int x=v1[k-1].first;
        int y=m1[x];
        int ans=1,c=0;
        for(i=0;i<26;i++){
            if(f[i]>x){
                ans=(1ll*ans*f[i])%m;
                c++;
            }
        }
        k-=c;
        int temp=k;
        // cout<<y<<endl;
        int z=1,p=1;
        while(k--){
            ans=(1ll*ans*y)%m;
            p=(1ll*p*z)%m;
            z++;
            y--;
        }
        k=temp;
        ans=(1ll*ans*modInverse(p,m))%m;
        ans=(1ll*ans*power(x,k,m))%m;
        return ans;
        
        
    }
};