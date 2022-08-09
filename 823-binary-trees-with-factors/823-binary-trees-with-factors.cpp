//#define MOD 1e+7
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            long long count=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)    //6%3
                {
                    auto it1=mp.find(arr[i]/arr[j]);  //6/3=2
                    auto it2=mp.find(arr[j]);   //3
                    if(it1!=mp.end()){
                        long long val1=it1->second;
                        long long val2=it2->second;
                      count+=(val1*val2)%1000000007;
                    }
                    
                }
            }
            mp[arr[i]]+=(count%1000000007);
        }
        long long count=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            count+=(it->second)%1000000007;
        }
        return count%1000000007;
    }
};