class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string ss1="",ss2="",ss3="",ss4="";
        int n=s1.length(),ans=1,i;
        for(i=0;i<n;i+=2){
            ss1+=s1[i];
            ss2+=s2[i];
        }
        sort(ss1.begin(),ss1.end());
        sort(ss2.begin(),ss2.end());
        if(ss1!=ss2) return false;
        for(i=1;i<n;i+=2){
            ss3+=s1[i];
            ss4+=s2[i];
        }
        sort(ss3.begin(),ss3.end());
        sort(ss4.begin(),ss4.end());
        if(ss3!=ss4) return false;
        else return true;
        
        
    }
};