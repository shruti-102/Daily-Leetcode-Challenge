class Solution {
public:
    vector<int> ans;
    void makenumber(int num,int n,int k)
    {
        if(n==0) {
            ans.push_back(num);
            return;
        }
        
        int digit=num%10;   //compute the last digit
        
        if(digit+k<=9)
            makenumber(num*10+(digit+k),n-1,k);
        if(k!=0 && digit>=k)
            makenumber(num*10+(digit-k),n-1,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<=9;i++)
            makenumber(i,n-1,k);
        return ans;
    }
};

 