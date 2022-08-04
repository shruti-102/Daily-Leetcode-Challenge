class Solution {
public:
    double findMedianSortedArrays(vector<int>& ar1, vector<int>& ar2) {
        int n=ar1.size();
        int m=ar2.size();
        double median=0;
        
        int i = 0; 
        int j = 0; /* Current index of input array ar2[] */
        int count;
        int m1 = -1, m2 = -1;
        /*loop till (m+n)/2*/
        for (count = 0; count <= (m + n)/2; count++)
        {
            //store (n+m)/2-1 in m2
            m2=m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if(i < n)
            {
                m1 = ar1[i++];
            }
            // for case when j<m,
            else
            {
                m1 = ar2[j++];
            }
        }
        // Since there are (n+m) elements,
        // There are following two cases
        // if n+m is odd then the middle
        // index is median i.e. (m+n)/2
        // other wise median will be average of elements
        // at index ((m+n)/2 - 1) and (m+n)/2
        // in the array obtained after merging ar1 and ar2
        if((m + n) % 2 == 1){
            return double(m1);
        }
        else{
            return double(m1+m2)/2.0;
        }

        }
};