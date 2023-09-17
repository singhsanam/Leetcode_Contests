#define MAXN 100001
 #define ll long long
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> gF(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
int flag=0;
class Solution {
public:
    
    long long maximumSum(vector<int>& a) {
        if(flag==0){
            flag=1;
            sieve();
        }
        int n=a.size(),i;
        map<int,ll>m1;
        ll ans=0;
        m1[1]=a[0];
        ans=a[0];
        for(i=1;i<n;i++){
            vector<int>v1=gF(i+1);
            // v1.push_back(1);
            // cout<<i+1<<endl;
            // for(auto v:v1) cout<<v<<" ";
            // cout<<endl;
            int n1=v1.size();
            int p=1,c=1;
            for(int j=1;j<n1;j++){
                if(v1[j]==v1[j-1]) c++;
                else{
                    if(c%2==1)
                    p*=v1[j-1];
                    c=1;
                }
            }
            if(c%2==1)
                    p*=v1[n1-1];
            // cout<<i+1<<" "<<p<<" "<<a[i]<<endl;
            
            m1[p]+=a[i];
            ans=max(ans,m1[p]);
        }
        return ans;
        
    }
};