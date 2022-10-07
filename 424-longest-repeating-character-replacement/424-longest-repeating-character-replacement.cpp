/*class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i=0,j=0,ans=-1,maxfreq=0,n=s.size();
        while(j<n){
            mp[s[j]]++;
            maxfreq=max(maxfreq,mp[s[j]]);
            int len=j-i+1;
            while(i<j && len-maxfreq>k){
                mp[s[i]]--;
                ++i;
            }
            len=j-i+1;
            ans=max(ans,len);
            j++;
        }
        return ans;
    }
};*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0;//->window start
        int j=0;//->window end
        int maxC=0;//->max no of repeating elements 
        int ans=-1;
        unordered_map<char,int> mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxC=max(maxC,mp[s[j]]);
            
            int curr_len=j-i+1;//Curr Len of the window
            if(curr_len-maxC>k) //the curr window has more than k replacable items case
            {
                mp[s[i]]--;
                i++;// shrinking the window
            }
            curr_len=j-i+1;// just in case i is changed
            ans=max(ans,curr_len);
            j++;
        }
        
        return ans;
    }
};