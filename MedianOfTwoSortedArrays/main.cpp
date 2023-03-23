#include <iostream>
#include <vector>
#include <limits>
#include <numbers>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1); 
        }

        int aSize{static_cast<int>(nums1.size())};
        int bSize{static_cast<int>(nums2.size())};
        int aMinValidItems{0};
        int aMaxValidItems{aSize};

        //Edge case for empty arrays
        if (nums1.empty())
        {
            if ((aSize + bSize) == 1)
            {
                return nums2[0];
            }
            else if ((aSize + bSize) % 2 == 0)
            {
                return (nums2[bSize / 2] + nums2[(bSize / 2) - 1]) / 2.0;
            }
            else
            {
                return nums2[bSize / 2];
            }
        }

        while (aMinValidItems <= aMaxValidItems)
        {
            int aCutIndex = (aMinValidItems+aMaxValidItems) / 2;
            int bCutIndex = ((aSize + bSize + 1) / 2) - aCutIndex;

            int aLeftVal = (aCutIndex == 0) ? INT_MIN : nums1[aCutIndex-1];
            int bLeftVal = (bCutIndex == 0) ? INT_MIN : nums2[bCutIndex-1];

            int aRightVal = (aCutIndex == aSize) ? INT_MAX : nums1[aCutIndex];
            int bRightVal = (bCutIndex == bSize) ? INT_MAX : nums2[bCutIndex];

            if (aLeftVal <= bRightVal && bLeftVal <= aRightVal)
            {
                if ((aSize + bSize) % 2 == 0)
                {
                    return (std::max(aLeftVal, bLeftVal) + std::min(aRightVal, bRightVal)) / 2.0;
                }
                else
                {
                    return std::max(aLeftVal, bLeftVal);
                }
            }
            else if (aLeftVal > bRightVal)
            {
                aMaxValidItems = aCutIndex - 1;
            }
            else
            {
                aMinValidItems = aCutIndex + 1;
            }
        }

        return 0.0;
    }
};





int main()
{
    std::vector<int> A {3,3,5,5,6,9,13};
    std::vector<int> B {1,1,3,3,5,8,8,9,9,11};
    Solution sol;

    std::cout << sol.findMedianSortedArrays(A, B) << std::endl;

    A = {1,2,3};
    B = {1,2,3,4,5,6,6,7,8,8,9};

    std::cout << sol.findMedianSortedArrays(A, B) << std::endl;

    A = {};
    B = {1,2,3};

    std::cout << sol.findMedianSortedArrays(A, B) << std::endl;

    return 0;
}