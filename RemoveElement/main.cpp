#include <iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int k{0};
        int indexToSwap{static_cast<int>(nums.size() - 1)};
        bool foundMismatch{false};

        for (int i{0}; i < static_cast<int>(nums.size()); i++)
        {
            if (i > indexToSwap)
            {
                break;
            }
            else if (i == indexToSwap)
            {
                if (nums[i] != val)
                {
                    k++;
                    foundMismatch = true;
                }
                break;
            }
            else if (nums[i] == val)
            {
                std::swap(nums[i], nums[indexToSwap]);
                // nums.erase(nums.begin() + indexToSwap); You could also erase as you go
                // instead of once at the end using the bool method
                indexToSwap--;
                i--;
            }
            else
            {
                k++;
                foundMismatch = true;
            }
        }

        if (!foundMismatch)
        {
            nums.clear();
        }
        return k;
    }
};

int main()
{
    Solution sol{};

    // std::vector<int> vec1{0, 1, 2, 2, 3, 0, 4, 2};
    // int val{2};

    std::vector<int> vec1{2};
    int val{3};

    std::cout << "Before removal" << std::endl;
    std::cout << "[ ";
    for (auto val : vec1)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;


    std::cout << "Num elements not equal to " << val << ": " << sol.removeElement(vec1, val) << " elements" << std::endl;

    std::cout << "After removal" << std::endl;
    std::cout << "[ ";
    for (auto val : vec1)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;
    return 0;
}