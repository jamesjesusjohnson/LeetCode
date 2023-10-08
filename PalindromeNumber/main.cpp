#include <iostream>
#include <cmath>

class Solution
{
private:
    int howManyDigits(int x)
    {
        int numDigits{0};

        if (x == 0)
        {
            numDigits = 1;
        }
        else
        {
            while (x != 0)
            {
                x /= 10;
                ++numDigits;
            }
        }

        return numDigits;
    }

    int isolateDigitAtPosition(int num, int position)
    {
        if (num >= 0)
        {
            return (num / static_cast<int>(pow(10, position))) % 10;
        }
        else
        {
            return (num / static_cast<int>(pow(10, position))) % -10;
        }
    }

public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int numDigits = howManyDigits(x);
        int highTracker{numDigits - 1};
        int lowTracker{0};
        bool isPalindrome{true};

        while (highTracker > lowTracker)
        {
            if (isolateDigitAtPosition(x, highTracker) != isolateDigitAtPosition(x, lowTracker))
            {
                isPalindrome = false;
            }
            highTracker--;
            lowTracker++;
        }

        return isPalindrome;
    }
};

int main()
{

    Solution sol{};

    int n1{101};
    int n2{11};
    int n3{0};
    int n4{2131};
    int n5{-202};

    std::cout << sol.isPalindrome(n1) << std::endl;
    std::cout << sol.isPalindrome(n2) << std::endl;
    std::cout << sol.isPalindrome(n3) << std::endl;
    std::cout << sol.isPalindrome(n4) << std::endl;
    std::cout << sol.isPalindrome(n5) << std::endl;

    return 0;
}