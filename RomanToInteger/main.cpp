#include <string>
#include <iostream>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int result{0};
        int index{0};
        std::string temp{""};

        // Thousands Place
        while (s[index] == 'M')
        {
            result += 1000;
            index++;
        }

        // Hundreds Place
        while (s[index] == 'C' || s[index] == 'D' || s[index] == 'M')
        {
            temp += s[index];
            index++;
        }

        if (temp == "CM")
        {
            result += 900;
        }
        else if (temp == "CD")
        {
            result += 400;
        }
        // 500 to 800
        else if (temp == "D" ||
                 temp == "DC" ||
                 temp == "DCC" ||
                 temp == "DCCC")
        {
            result += 500;
            for (size_t i{1}; i < temp.size(); i++)
            {
                result += 100;
            }
        }
        // 100 to 300
        else
        {
            for (size_t i{0}; i < temp.size(); i++)
            {
                result += 100;
            }
        }

        temp = "";

        // Tens Place
        while (s[index] == 'X' || s[index] == 'L' || s[index] == 'C')
        {
            temp += s[index];
            index++;
        }

        if (temp == "XC")
        {
            result += 90;
        }
        else if (temp == "XL")
        {
            result += 40;
        }
        // 50 to 80
        else if (temp == "L" ||
                 temp == "LX" ||
                 temp == "LXX" ||
                 temp == "LXXX")
        {
            result += 50;
            for (size_t i{1}; i < temp.size(); i++)
            {
                result += 10;
            }
        }
        // 10 to 30
        else
        {
            for (size_t i{0}; i < temp.size(); i++)
            {
                result += 10;
            }
        }

        temp = "";

        // Ones Place
        while (s[index] == 'I' || s[index] == 'V' || s[index] == 'X')
        {
            temp += s[index];
            index++;
        }

        if (temp == "IX")
        {
            result += 9;
        }
        else if (temp == "IV")
        {
            result += 4;
        }
        // 5 to 8
        else if (temp == "V" ||
                 temp == "VI" ||
                 temp == "VII" ||
                 temp == "VIII")
        {
            result += 5;
            for (size_t i{1}; i < temp.size(); i++)
            {
                result += 1;
            }
        }
        // 1 to 3
        else
        {
            for (size_t i{0}; i < temp.size(); i++)
            {
                result += 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol{};

    std::string romanNum1{"MCMXCIV"};

    std::cout << sol.romanToInt(romanNum1) << std::endl;

    return 0;
}