#include <iostream>
#include <set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::set<char> collection{};
        std::pair<std::set<char>::iterator, bool> result{};
        int count{0};
        int lengthLongestSubstring{0};

        for (size_t i{0}; i < s.size(); i++)
        {
            result = collection.insert(s.at(i));

            if (result.second == true)
            {
                count++;
            }
            else
            {
                if (count > lengthLongestSubstring)
                {
                    lengthLongestSubstring = count;
                }

                i -= count;
                count = 0;
                collection.clear();
            }
        }

        if (count > lengthLongestSubstring)
        {
            lengthLongestSubstring = count;
        }

        return lengthLongestSubstring;

    }
};


int main()
{
    Solution sol{};

    std::string test1{"abcabcbb"};
    std::string test2{"bbbbb"};
    std::string test3{"pwwkew"};
    std::string test4{"dvdf"};

    std::cout << test1 << ": " << sol.lengthOfLongestSubstring(test1) << std::endl;
    std::cout << test2 << ": " << sol.lengthOfLongestSubstring(test2) << std::endl;
    std::cout << test3 << ": " << sol.lengthOfLongestSubstring(test3) << std::endl;
    std::cout << test4 << ": " << sol.lengthOfLongestSubstring(test4) << std::endl;


    return 0;
}