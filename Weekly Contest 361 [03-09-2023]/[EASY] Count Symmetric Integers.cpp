class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0,i;
        for(i=low;i<=high;i++){
            string s=to_string(i);
            int n=s.length();
            if(n%2==1) continue;
            int n1=n/2,j=i,c1=0,c2=0;
            while(n1--){
                c1+=j%10;
                j/=10;
            }
            n1=n/2;
            while(n1--){
                c2+=j%10;
                j/=10;
            }
            ans+=(c1==c2);
        }
        return ans;
        
    }
};