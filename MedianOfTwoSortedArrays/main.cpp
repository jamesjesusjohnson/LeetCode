#include <iostream>
#include <vector>
#include <limits>
#include <numbers>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int>& A = nums1;
        std::vector<int>& B = nums2;

        if (A.size() == 0)
        {
            if (B.size() % 2 == 1)
            {
                return B[(B.size() / 2)];
            }
            else
            {
                return (B[(B.size() / 2) - 1] + B[(B.size() / 2)]) / 2.0;
            }
        }
        else if (B.size() == 0)
        {
            if (A.size() % 2 == 1)
            {
                return A[(A.size() / 2)];
            }
            else
            {
                return (A[(A.size() / 2) - 1] + A[(A.size() / 2)]) / 2.0;
            }
        }


        if (nums1.size() > nums2.size())
        {
            B = nums1;
            A = nums2;
        }

        int total {static_cast<int>(A.size() + B.size())};
        int half {total / 2};

        int l {0};
        int r {static_cast<int>(A.size() - 1)};

        while (true)
        {
            int i = (l + r) / 2;    // For array A
            int j = half - i - 2;   // For array B

            int Aleft;
            if (i < 0)
            {
                Aleft = std::numeric_limits<int>::min();
            }
            else
            {
                Aleft = A[i];
            }

            int Aright;
            if ((i + 1) > (static_cast<int>(A.size() - 1)))
            {
                Aright = std::numeric_limits<int>::max();
            }
            else
            {
                Aright = A[i +1];
            }

            int Bleft;
            if (j < 0)
            {
                Bleft = std::numeric_limits<int>::min();
            }
            else
            {
                Bleft = B[j];
            }

            int Bright;
            if ((j + 1) > (static_cast<int>(B.size() - 1)))
            {
                Bright = std::numeric_limits<int>::max();
            }
            else
            {
                Bright = B[j + 1];
            }

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if (total % 2 == 1)
                {
                    return std::min(Aright, Bright);
                }
                else
                {
                    return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }
    }
};





int main()
{
    std::vector<int> A {3};
    std::vector<int> B {-2,-1};

    Solution sol;

    std::cout << sol.findMedianSortedArrays(A, B) << std::endl;

    return 0;
}