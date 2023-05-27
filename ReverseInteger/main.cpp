#include <iostream>
#include <cmath>

int digitsInInteger(int num);
int reverseInteger(int num);
int isolateDigitAtPosition(int num, int position);
bool checkOverUnderflowAddition(int a, int b);
bool checkOverUnderflowMultiplication(int a, int b);

class Solution
{
public:
    int reverse(int x)
    {
        int digits {digitsInInteger(x)};
        int result {0};
        int multiplier {1};


        for (int i {digits - 1}; i > 0; i--)
        {
            result += multiplier * isolateDigitAtPosition(x, i);
            multiplier *= 10;
        }

        if ((checkOverUnderflowMultiplication(multiplier, isolateDigitAtPosition(x, 0))) ||
           (checkOverUnderflowAddition(result, multiplier * isolateDigitAtPosition(x, 0))))
        {
            result = 0;
        }
        else
        {
            result += multiplier * isolateDigitAtPosition(x, 0);
        }

        return result;
    }
};


int main()
{
    Solution sol {};

    std::cout << INT_MIN << std::endl << std::endl;

    int test {12345678};
    int test2 {-12345678};
    int test3 {INT_MIN};
    int test4 {1111111119};
    
    std::cout << sol.reverse(test) << std::endl;
    std::cout << sol.reverse(test2) << std::endl;
    std::cout << sol.reverse(test3) << std::endl;
    std::cout << sol.reverse(test4) << std::endl;

    return 0;
}



int digitsInInteger(int num)
{
    int count {0};

    while (num != 0)
    {
        num = num / 10;
        count++;
    }

    return count;
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

bool checkOverUnderflowAddition(int a, int b)
{
    bool operationWillOverUnderflow {false};

    if (b >= 0)
    {
        if (a > 0 && (b > INT_MAX - a))
            operationWillOverUnderflow = true;
    }
    else
    {
        if ((a < 0 && (b < INT_MIN - a)))
            operationWillOverUnderflow = true;
    }

    return operationWillOverUnderflow;
}

bool checkOverUnderflowMultiplication(int a, int b)
{
    bool operationWillOverUnderflow {false};

    if (b > 0)
    {
        if ((a > 0 && (a > INT_MAX / b)))
        {
            operationWillOverUnderflow = true;
        }
        else if (a < 0 && (a < INT_MIN / b))
        {
            operationWillOverUnderflow = true;
        }
    }
    else if (b < 0)
    {
        if (a > 0 && (b < INT_MIN / a))
        {
            operationWillOverUnderflow = true;
        }
        else if (a < 0 && (b < INT_MAX / a))
        {
            operationWillOverUnderflow = true;
        }
    }

    return operationWillOverUnderflow;
}

