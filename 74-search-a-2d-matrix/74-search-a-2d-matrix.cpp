class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
    
        int targetrow=n-1;
        bool found=false;
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            cout<<mid<<" ";
            if(matrix[mid][0]==target)
            {
                found=true;
                targetrow=mid;
                break;
            }
            else if(matrix[mid][0]<target && matrix[mid][m-1]>=target)
            {
                cout<<"&&";
                found=true;
                targetrow=mid;
                break;
            }
            if(matrix[mid][0]>target)
            {
                h=mid-1;
            }
            
            else if(matrix[mid][0]<target)
            {
                l=mid+1;
            }
        }cout<<endl;
        cout<<targetrow<<endl;
        if(!found) return false;
        
        l=0,h=m-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(matrix[targetrow][mid]==target) return true;
            else if(matrix[targetrow][mid]>target)
            {
                h=mid-1;
            }
            else if(matrix[targetrow][mid]<target)
            {
                l=mid+1;
            }
        }
        return false;
    }
};