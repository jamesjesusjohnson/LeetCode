#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s)
    {
        bool palindromeFound {true};
        int lengthOfCandidatePalindrome{0};
        std::string valueOfCandidatePalindrome{""};
        int lengthOfLongestPalindrome{1};
        std::string valueOfLongestPalindrome{s[0]};

        int i_temp{0};
        int j_temp{0};

        for (size_t i {0}; i < (s.size() - 1); i++)
        {
            for (size_t j {i + 1}; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {
                    // palindrome candidate
                    lengthOfCandidatePalindrome = (j - i) + 1;

                    // is palindrome long enough to consider?
                    if (lengthOfCandidatePalindrome > lengthOfLongestPalindrome)
                    {
                        valueOfCandidatePalindrome = s.substr(i,lengthOfCandidatePalindrome);
                        i_temp = i + 1;
                        j_temp = j - 1;

                        while (palindromeFound && (i_temp <= j_temp))
                        {
                            if(s[i_temp] == s[j_temp])
                            {
                                i_temp++;
                                j_temp--;
                            }
                            else
                            {
                                // failure
                                palindromeFound = false;
                            }
                        }

                        if (palindromeFound)
                        {
                            lengthOfLongestPalindrome = lengthOfCandidatePalindrome;
                            valueOfLongestPalindrome = valueOfCandidatePalindrome;
                        }
                        else
                        {
                            // reset variables
                            palindromeFound = true;
                        }
                    }
                }
            }
        }

        return valueOfLongestPalindrome;
    }
};

int main()
{
    Solution sol{};

    std::string s1{"babad"};
    std::string s2{"cbbd"};
    std::string s3{"aatacocatacocatabwerty"};

    std::cout << std::endl;
    std::cout << sol.longestPalindrome(s1) << std::endl;

    std::cout << std::endl;
    std::cout << sol.longestPalindrome(s2) << std::endl;

    std::cout << std::endl;
    std::cout << sol.longestPalindrome(s3) << std::endl;

    std::cout << std::endl;

    return 0;
}