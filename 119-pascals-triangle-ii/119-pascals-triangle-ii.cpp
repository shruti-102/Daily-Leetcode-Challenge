class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        
        ans[0]=1;
        if(rowIndex==0) return ans;
        ans[1]=rowIndex;
        int prev=rowIndex;
        long n=rowIndex;
        for(int i=2,up=rowIndex-1;i<rowIndex+1;i++,up--)
        {
            n=(n*up)/i;;
            ans[i]=n;
        }
        return ans;
    }
};