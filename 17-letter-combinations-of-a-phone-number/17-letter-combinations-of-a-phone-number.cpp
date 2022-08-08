class Solution {
public:
    void helper(string digit,int indx,unordered_map<int,string>& mp,vector<string>& res,string str)
    {
        if(indx>=digit.size())
        {
            res.push_back(str);
            return;
        }
        
        int key=digit[indx]-'0';
        string value=mp[key];
        
        for(int i=0;i<value.size();i++)
        {
            str+=value[i];
            helper(digit,indx+1,mp,res,str);
            str.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[5]="jkl";
        mp[6]="mno";
        mp[4]="ghi";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        vector<string> res;
        if(digits.size()==0) return res;
        
        helper(digits,0,mp,res,"");
        return res;
    }
};