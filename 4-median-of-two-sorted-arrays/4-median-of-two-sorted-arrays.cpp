class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        double median=0;
        
        if(n1==0)
        {
            int mid=n2/2;
            if(n2%2==0) median=(nums2[mid-1]+nums2[mid])/2.0;
            else median=double(nums2[mid]);
            
            return median;
        }
        else if(n2==0)
        {
            int mid=n1/2;
            if(n1%2==0) median=(nums1[mid-1]+nums1[mid])/2.0;
            else median=double(nums1[mid]);
            
            return median;
        }
        int n=n1+n2;
        int left=n/2;
        
        int i=0,j=0;
        while(i<n1 && j<n2 && left--)
        {
            if(nums1[i]<=nums2[j]) i++;
            else j++;
        }
        //cout<<i<<" "<<j;
        
        if(i==n1)
        {
            while(left-- && j<n2)
            {
                j++;
            }
        }
        
        else if(j==n2)
        {
            while(left-- && i<n1)
            {
                i++;
            }
        }
        
         int l1,r1,l2,r2;
         if(i>=n1) r1=INT_MAX;
         else r1=nums1[i];
        
         if(j>=n2) r2=INT_MAX;
         else r2=nums2[j];
        
         if(i==0) l1=0;
         else l1=nums1[i-1];
        
         if(j==0) l2=0;
         else l2=nums2[j-1];
       
        cout<<l1<<" "<<l2<<endl;
        cout<<r1<<" "<<r2;
        if(n%2==0)  //even
        {
           
            int x=max(l1,l2);
            int y=min(r1,r2);
            median=(x+y)/2.0;
        }
        else
        {
            median=double(min(r1,r2));
        }
        return median;
    }
};