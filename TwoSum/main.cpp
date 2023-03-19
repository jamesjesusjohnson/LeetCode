#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::vector<int> result{};

        for (size_t i {0}; i < nums.size() - 1; i++)
        {
            for (size_t j {i + 1}; j < nums.size(); j++)
            {
                if((nums.at(i) + nums.at(j)) == target)
                {
                    result.push_back(i);
                    result.push_back(j);

                    return result;
                }
            }
        }
        return result;
    }
};


void display(const std::vector<int>& vec)
{
    std::cout << "[ ";
    for(int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}


int main()
{
    Solution sol{};

    // Case 1
    std::vector<int> nums {2,7,11,15};
    std::vector<int> result = sol.twoSum(nums, 9);

    display(result);

    // Case 2
    nums = {3,2,4};
    result = sol.twoSum(nums, 6);

    display(result);

    // Case 3
    nums = {3,3};
    result = sol.twoSum(nums, 6);

    display(result);

    std::cout << std::endl;
    return 0;
}