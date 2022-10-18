class Solution {
public:
//here we create a custom sort function.
    static bool cmp(string a , string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr; //created to convert all the elements from int to string for easy iteration.
        for(int i = 0 ; i<nums.size() ; i++)
            arr.push_back(to_string(nums[i]));
        
        sort(arr.begin() , arr.end() , cmp);
        string ans = "";
        //after sorting we will add all the sorted values in aur ans.
        for(int i = 0 ; i<arr.size() ; i++){
            ans+=arr[i];
        }
		
		//written to handle the corner case like [0,0,0] in these cases of all zeros we need to return 0 only. 
        int i = 0 ; 
        while(ans[i]=='0'){
            i++;
        }
        if(i==ans.size())
            ans="0";
        return ans;
        
    }
};