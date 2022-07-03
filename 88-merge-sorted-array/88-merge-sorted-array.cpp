class Solution {
public:
    //insertion sort intution
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr1=0;
        int ptr2=0;
        while(ptr1<m && ptr2<n)
        {
            if(nums1[ptr1]>nums2[0])
            {
                swap(nums1[ptr1],nums2[0]);
                
                //find correct pos
                int val=nums2[0],i;
                
                for(i=1;i<n && nums2[i]<val;i++)
                {
                    nums2[i-1]=nums2[i];
                }
                nums2[i-1]=val;
            }
            ptr1++;
        }
        
        for(int i=m,j=0;i<m+n;i++,j++)
        {
            nums1[i]=nums2[j];
        }
    }
};