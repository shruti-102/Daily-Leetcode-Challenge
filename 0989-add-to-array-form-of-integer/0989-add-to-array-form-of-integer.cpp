class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int i=n-1,r,x,carry=0;
        while(i>=0 && k!=0){
            r=k%10;
            x=nums[i]+r;
            if(carry){
                x+=carry;
                
            }
            ans.push_back(x%10);
            carry=x/10;
            i--;
            k=k/10;
        }
        while(i>=0){
            if(carry) {
                ans.push_back((nums[i]+carry)%10);
                carry=(nums[i]+carry)/10;
            }
            else ans.push_back(nums[i]);
            i--;
        }
        cout<<k<<carry;
        while(k!=0){
             r=k%10;
            if(carry){
               
                ans.push_back((carry+r)%10);
                carry=(carry+r)/10;
            }
            else ans.push_back(r);
            k=k/10;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};