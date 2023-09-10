
#define ll long long
int mod=1e9+7;
int power(int x,int y){
    if(y==0) return 1;
    int z=power(x,y/2);
    z=(1ll*z*z)%mod;
    if(y%2==1) z=(1ll*x*z)%mod;
    return z;
}
int modInverse(int n){
    return power(n,mod-2);
}
vector<int>inv1;
vector<int>inv2;
void preinv(int n){
    inv1.clear();
    inv2.clear();
    inv1.resize(n+1);
    inv2.resize(n+1);
    mod=1e9+7;
    inv1[n]=modInverse(power(29,n));
    for(int i=n-1;i>=0;i--){
        inv1[i]=(1ll*inv1[i+1]*29)%mod;
    }
    mod=1e9+9;
    inv2[n]=modInverse(power(37,n));
    for(int i=n-1;i>=0;i--){
        inv2[i]=(1ll*inv2[i+1]*37)%mod;
    }

}
int MOD=1e9+7;
void multiply(vector<vector<int>> &a, vector<vector<int>> &b)
{

    vector<vector<int>>mul(4,vector<int>(4,0));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 4; k++)
                mul[i][j] =(mul[i][j]+ 1ll*a[i][k]*b[k][j])%MOD;
        }
    }
 
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            a[i][j] = mul[i][j];  // Updating our matrix
}
void powerM(vector<vector<int>> &a, int n){
    if(n==1) return;
    
    vector<vector<int>>temp=a;
    powerM(a,n/2);
    vector<vector<int>>b=a;
    // powerM(b,n/2);
    multiply(a,b);
    if(n%2==1) multiply(a,temp);
}
int R1=4,C1=4,R2=4,C2=1;
void mulMat(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    int rslt[R1][C2];
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
            for (int k = 0; k < R2; k++) {
                rslt[i][j] =(rslt[i][j] + 1ll*mat1[i][k] * mat2[k][j])%MOD;
            }
        }
    }
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            mat2[i][j]=rslt[i][j];
        }
    }
}
class Solution {
public:
    
    int numberOfWays(string s, string t, long long k) {
        int n=s.length();
        //using double Hashing to be deterministic
        vector<int>hash1(n+1);//1 indexed
        preinv(n+1);// precomputing ModInverse in O(N+log(MOD)) time
        int i,j,x,y,p,q,q1=0,q2=0;
        int p1=29,p2=37;
        int h=0;
        hash1[0]=0;
        mod=1e9+7;
        for(i=0;i<n;i++){
            h=(h+1ll*(s[i]-'a'+1)*p1)%mod;
            hash1[i+1]=h;// creating first hash
            p1=(1ll*p1*29)%mod;
        }
        vector<int>hash2(n+1);//1 indexed
        hash2[0]=0;
        p1=37;
        h=0;
        mod=1e9+9;
        int pow1[n+1],pow2[n+1];
        pow1[0]=1;
        pow2[0]=1;
        for(i=0;i<n;i++){
            pow1[i+1]=(1ll*pow1[i]*29)%((int)1e9+7);
            pow2[i+1]=(1ll*pow2[i]*37)%((int)1e9+9);

            h=(h+1ll*(s[i]-'a'+1)*p1)%mod;
            hash2[i+1]=h;// creating second Hash
            p1=(1ll*p1*37)%mod;
        }
        
        int h1=0;
        int h2=0;
        p1=29;
        p2=37;
        for(i=0;i<n;i++){
            mod=1e9+7;
            h1=(h1+1ll*(t[i]-'a'+1)*p1)%mod;
            p1=(1ll*p1*29)%mod;
            mod=1e9+9;
            h2=(h2+1ll*(t[i]-'a'+1)*p2)%mod;
            p2=(1ll*p2*37)%mod;
        }

        p1=1;
        p2=1;
        int c=0,z=0;
        for(i=0;i<n;i++){
            mod=1e9+7;
            q1=(hash1[n]-hash1[i]+mod)%mod;
            q1=(1ll*q1*inv1[i])%mod;
            q1=(q1+1ll*hash1[i]*pow1[n-i])%mod;
            p1=(1ll*p1*29)%mod;
            mod=1e9+9;
            q2=(hash2[n]-hash2[i]+mod)%mod;
            q2=(1ll*q2*inv2[i])%mod;
            q2=(q2+1ll*hash2[i]*pow2[n-i])%mod;
            p2=(1ll*p2*37)%mod;
            if(q1==h1&&q2==h2) c++;
            if(q1==h1&&q2==h2&&i==0) z=1;

        }
        if(c==0) return 0;
        k%=MOD-1;
        if(k==1) return c-z;
        if(k==0) return z;
        
        int ans;
        int a=n-c,b=c-1;
        vector<vector<int>>v1={{b,0,a,0},{1,0,0,0},{b+1,0,a-1,0},{0,0,1,0}};// Creating Matrix
        vector<vector<int>>st={{b},{1},{b+1},{0}};
            // Matrix Exponentiation
            powerM(v1,k-1);
            mulMat(v1,st);

        ans=st[2-2*z][0];
        return ans;
        
    }
};