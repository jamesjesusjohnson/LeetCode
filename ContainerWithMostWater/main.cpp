#include <vector>
#include <iostream>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        /*
                BRUTE FORCE SOLUTION
                int res{0};

                for (int l{0}; l < height.size() - 1; l++)
                {
                    for (int r{l + 1}; r < height.size(); r++)
                    {
                        int test = std::min(height[l], height[r]);
                        int area = (r - l) * std::min(height[l], height[r]);
                        res = std::max(res, area);
                    }
                }

                return res; */

        // BETTER SOLUTION
        int maxArea{0};
        int l{0};
        int r{static_cast<int>(height.size()) - 1};

        while (l < r)
        {
            maxArea = std::max(maxArea, (r - l) * std::min(height[l], height[r]));
            if(height[r] < height[l])
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution sol{};

    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    std::cout << sol.maxArea(height) << std::endl;
    return 0;
}