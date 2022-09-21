class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumeven=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) {
                //cout<<nums[i];
                sumeven+=nums[i];
                //cout<<endl;
                //cout<<sumeven<<endl;
            }
        }//cout<<endl;
        //cout<<sumeven<<endl;
        vector<int> ans;
        int k=queries.size();
        for(int i=0;i<k;i++){
            int val=queries[i][0];
            int indx=queries[i][1];
            
            if(nums[indx]%2==0) {
                sumeven-=nums[indx];
                nums[indx]+=val;
                if(nums[indx] %2 == 0) sumeven+=nums[indx];
            }
            else
            {
                nums[indx]+=val;
                if(nums[indx]%2==0) sumeven+=nums[indx];
            }
            ans.push_back(sumeven);
        }
        return ans;
    }
};