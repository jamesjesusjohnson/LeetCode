#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int indexToInsert{1};
        int valueToCheck{nums[0]};
        bool foundTwice{false};

        for (int i{1}; i < static_cast<int>(nums.size()); i++)
        {
            if (nums[i] == valueToCheck)
            {
                if (foundTwice == false)
                {
                    nums[indexToInsert] = valueToCheck;
                    indexToInsert++;
                    foundTwice = true;
                }
                else
                {
                    i += 1;
                    while (i < static_cast<int>(nums.size()) && nums[i] == valueToCheck)
                    {
                        i++;
                    }
                    if (i != static_cast<int>(nums.size()))
                    {
                        nums[indexToInsert] = nums[i];
                        valueToCheck = nums[i];
                        indexToInsert++;
                        foundTwice = false;
                    }
                }
            }
            else
            {
                nums[indexToInsert] = nums[i];
                valueToCheck = nums[i];
                indexToInsert++;
                foundTwice = false;
            }
        }

        return indexToInsert;
    }
};

void print(std::vector<int> &nums)
{
    std::cout << "[ ";
    for (auto val : nums)
    {
        std::cout << val << ' ';
    }
    std::cout << ']' << std::endl;
}

int main()
{
    Solution sol{};

    std::vector<int> vec0{0, 0, 1, 1, 1, 1, 2, 3, 3};

    std::cout << "BEFORE" << std::endl;
    print(vec0);
    std::cout << "Number of unique items: " << sol.removeDuplicates(vec0) << std::endl;
    std::cout << "AFTER" << std::endl;
    print(vec0);

    std::vector<int> vec1{1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 7, 7, 8};

    std::cout << "BEFORE" << std::endl;
    print(vec1);
    std::cout << "Number of unique items: " << sol.removeDuplicates(vec1) << std::endl;
    std::cout << "AFTER" << std::endl;
    print(vec1);

    std::vector<int> vec2{1, 1, 2};

    std::cout << "BEFORE" << std::endl;
    print(vec2);
    std::cout << "Number of unique items: " << sol.removeDuplicates(vec2) << std::endl;
    std::cout << "AFTER" << std::endl;
    print(vec2);
    return 0;
}