#include <iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int indexToWrite{0};

        for (const int &x : nums)
        {
            if (x != val)
            {
                nums[indexToWrite] = x;
                indexToWrite++;
            }
        }

        if (indexToWrite == 0)
        {
            nums.clear();
        }

        return indexToWrite;
    }
};

int main()
{
    Solution sol{};

    std::vector<int> vec1{0, 1, 2, 2, 3, 0, 4, 2};
    int val1{2};

    std::cout << "Before removal" << std::endl;
    std::cout << "[ ";
    for (auto val : vec1)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;

    std::cout << "Num elements not equal to " << val1 << ": " << sol.removeElement(vec1, val1) << " elements" << std::endl;

    std::cout << "After removal" << std::endl;
    std::cout << "[ ";
    for (auto val : vec1)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;

    std::vector<int> vec2{1};
    int val2{1};

    std::cout << "Before removal" << std::endl;
    std::cout << "[ ";
    for (auto val : vec2)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;

    std::cout << "Num elements not equal to " << val2 << ": " << sol.removeElement(vec2, val2) << " elements" << std::endl;

    std::cout << "After removal" << std::endl;
    std::cout << "[ ";
    for (auto val : vec2)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;
    return 0;
}