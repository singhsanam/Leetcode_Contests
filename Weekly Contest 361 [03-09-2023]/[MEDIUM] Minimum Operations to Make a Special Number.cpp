class Solution {
public:
    int minimumOperations(string s) {
        int n=s.length();
        int c=0,i,j,ans=n;
        // s='0'+s;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                string s1="";
                s1+=s[i];
                s1+=s[j];
                if(s1=="00"||s1=="50"||s1=="25"||s1=="75"){
                    ans=min(ans,n-1-j+j-i-1);
                }
                if(s[j]=='0') ans=min(ans,n-1);
            }
        }

        return ans;
        
    }
};