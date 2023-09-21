class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double ans = 0;

        int i=0 , j = 0 , n = nums1.size() + nums2.size() , x = 0;

        if(n%2==0)
        {
            while(i<nums1.size() || j<nums2.size())
            {
                x++;
                if(j>=nums2.size() || (i<nums1.size() && nums1[i]<=nums2[j]))
                {
                    i++;
                    if(x==n/2)
                    {
                        ans += nums1[i-1];
                
                        if(j>=nums2.size() || (i<nums1.size() && nums1[i]<=nums2[j]))
                        {
                            ans += nums1[i];
                            return ans/2;
                        }
                        else
                        {
                            ans += nums2[j];
                            return ans/2;
                        }
                    }
                }
                else
                {
                        j++;
                        if(x==n/2)
                        {
                            ans += nums2[j-1];
                            if(j>=nums2.size() || (i<nums1.size() && nums1[i]<=nums2[j]))
                            {
                                ans += nums1[i];
                                return ans/2;
                            }
                            else
                            {
                                ans += nums2[j];
                                return ans/2;
                            }
                        }
                }
            }
        }   
        else
        {
             while(i<nums1.size() || j<nums2.size())  
             {
                x++;
                if(j>=nums2.size() || (i<nums1.size() && nums1[i]<=nums2[j]))
                {
                    i++;
                    if(x==(n+1)/2)
                    {
                        ans+=nums1[i-1];
                        return ans;
                    }
                }    
                else
                {
                    j++;
                    if(x==(n+1)/2)
                    {
                        ans+=nums2[j-1];
                        return ans;
                    }
                }
             } 
        } 
        return 0;
    }
};