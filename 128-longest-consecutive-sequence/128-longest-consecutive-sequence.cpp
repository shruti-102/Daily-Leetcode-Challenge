class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); // extract the size of array
        if(n == 0) return 0; // if length of array is zero, then from here simply return 0
        
        unordered_set<int> s(nums.begin(),nums.end());
        int maxlen=INT_MIN;
        for(auto it: s)
        {
           if(!s.count(it-1))   //means no such element exixt we got our minimum limit
           {
               int len=1;
               int num=it;
               
               while(s.count(num+1))    //if 1 means there exits so continue
               {
                   len++;   //increase the length
                   
                   num=num+1;   //update the num
               }
               maxlen=max(maxlen,len);
           }   
        }
        return maxlen;
    }
};