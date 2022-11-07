class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
       // int d=stoi(num);
       // if(d%2!=0) return num;
        int i=0,j=n-1;
        string ans="";
        while(i<=j){
            if(num[j]%2==0) j--;
            else if(num[j]%2!=0) {
                ans=num.substr(i,j-i+1);
                break;
            }
        }
        return ans;
    }
};