class Solution {
public:
    string count(string s)
    {
        char start=s[0];
        int n=s.size();
        string ans="";
        if(n==1) {
            ans+="1";
            ans+=s;
            return ans;
        }
        int e=1,c=1;
        
        while(e<n)
        {
            if(s[e]==start) c++;
            else
            {
                ans+=(c+'0');
                ans+=start;
                c=1;
                start=s[e];
            }
            e++;
        }
        ans+=(c+'0');
        ans+=start;
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev="1",cur="";
        for(int i=2;i<=n;i++)
        {
            cur=count(prev);
            //cout<<cur<<endl;
            prev=cur;
        }
        return cur;
    }
};