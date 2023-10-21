#include <string>
#include <iostream>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        int numToConvert{num % 10};
        int place{1};
        std::string result{""};
        std::string temp{""};

        do
        {
            switch (place)
            {
            case 1:
                if (numToConvert == 1 || numToConvert == 2 || numToConvert == 3)
                {
                    for (int i{0}; i < numToConvert; i++)
                    {
                        temp += "I";
                    }
                }
                else if (numToConvert == 4)
                {
                    temp += "IV";
                }
                else if (numToConvert == 5)
                {
                    temp += "V";
                }
                else if (numToConvert == 6 || numToConvert == 7 || numToConvert == 8)
                {
                    temp += "V";
                    for (int i{5}; i < numToConvert; i++)
                    {
                        temp += "I";
                    }
                }
                else if (numToConvert == 9)
                {
                    temp += "IX";
                }
                else
                {
                    temp = "";
                }
                break;
            case 10:
                if (numToConvert == 1 || numToConvert == 2 || numToConvert == 3)
                {
                    for (int i{0}; i < numToConvert; i++)
                    {
                        temp += "X";
                    }
                }
                else if (numToConvert == 4)
                {
                    temp += "XL";
                }
                else if (numToConvert == 5)
                {
                    temp += "L";
                }
                else if (numToConvert == 6 || numToConvert == 7 || numToConvert == 8)
                {
                    temp += "L";
                    for (int i{5}; i < numToConvert; i++)
                    {
                        temp += "X";
                    }
                }
                else if (numToConvert == 9)
                {
                    temp += "XC";
                }
                else
                {
                    temp = "";
                }

                break;
            case 100:
                if (numToConvert == 1 || numToConvert == 2 || numToConvert == 3)
                {
                    for (int i{0}; i < numToConvert; i++)
                    {
                        temp += "C";
                    }
                }
                else if (numToConvert == 4)
                {
                    temp += "CD";
                }
                else if (numToConvert == 5)
                {
                    temp += "D";
                }
                else if (numToConvert == 6 || numToConvert == 7 || numToConvert == 8)
                {
                    temp += "D";
                    for (int i{5}; i < numToConvert; i++)
                    {
                        temp += "C";
                    }
                }
                else if (numToConvert == 9)
                {
                    temp += "CM";
                }
                else
                {
                    temp = "";
                }

                break;
            case 1000:
                if (numToConvert == 1 || numToConvert == 2 || numToConvert == 3)
                {
                    for (int i{0}; i < numToConvert; i++)
                    {
                        temp += "M";
                    }
                }
                else
                {
                    temp = "";
                }
                break;

            default:
                break;
            }

            result = temp + result;
            temp = "";
            num /= 10;
            numToConvert = num % 10;
            place *= 10;

        } while (num != 0);

        return result;
    }
};

int main()
{
    
    return 0;
}