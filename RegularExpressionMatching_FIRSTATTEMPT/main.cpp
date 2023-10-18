#include <iostream>
#include <string>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        bool isMatch{true};
        auto currCharInPattern{p.begin()};
        auto currCharInString{s.begin()};
        char charForComparison{};

        while (isMatch && currCharInPattern != p.end())
        {
            if (*currCharInPattern == '.')
            {
                currCharInString++;
            }
            else if (*currCharInPattern == '*')
            {
                currCharInPattern--;
                if (*currCharInPattern == '.')
                {
                    // This means char in string can be any value OR none
                    // but if it is a value, that value must continue until the end or
                    // until new value is seen
                    charForComparison = *currCharInString;
                }
                else
                {
                    charForComparison = *currCharInString;
                    currCharInString++;
                }

                currCharInPattern++;

                while (charForComparison == *currCharInString && currCharInString != s.end())
                {
                    currCharInString++;
                }
            }
            else
            {
                charForComparison = *currCharInPattern;
                if (*currCharInString != charForComparison)
                {
                    isMatch = false;
                }
                currCharInString++;
            }

            currCharInPattern++;
        }

        if (currCharInString != s.end())
        {
            isMatch = false;
        }

        return isMatch;
    }
};

int main()
{
    Solution sol{};

    sol.isMatch("ab", ".*");

    return 0;
}