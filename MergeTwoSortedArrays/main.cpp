#include <vector>

class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        int placementIndex{static_cast<int>(nums1.size() - 1)};

        while (m > 0 && n > 0)
        {
            if (nums1[m - 1] >= nums2[n - 1])
            {
                nums1[placementIndex] = nums1[m - 1];
                m--;
            }
            else
            {
                nums1[placementIndex] = nums2[n - 1];
                n--;
            }
            placementIndex--;
        }

        if (m > 0)
        {
            for (; m > 0; m--)
            {
                nums1[placementIndex] = nums1[m - 1];
                placementIndex--;
            }
        }
        else if (n > 0)
        {
            for (; n > 0; n--)
            {
                nums1[placementIndex] = nums2[n - 1];
                placementIndex--;
            }
        }
        return;
    }
};

int main()
{

    Solution sol;

    std::vector<int> vec1{1, 2, 3, 0, 0, 0};
    std::vector<int> vec2{2, 5, 6};
    int numElementsInVec1{3};
    int numElementsInVec2{3};

    sol.merge(vec1, numElementsInVec1, vec2, numElementsInVec2);

    std::vector<int> vec3{4, 5, 6, 0, 0, 0};
    std::vector<int> vec4{1, 2, 3};
    int numElementsInVec3{3};
    int numElementsInVec4{3};

    sol.merge(vec3, numElementsInVec3, vec4, numElementsInVec4);

    return 0;
}