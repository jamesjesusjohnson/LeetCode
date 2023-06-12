#include <iostream>

int myAtoi(std::string s);
bool checkOverUnderflowMultiplication(int a, int b);

enum StringToIntegerParseStates
{
    LEADING_WHITE_SPACE = 0,
    CHECK_FOR_SIGNED,
    PARSE_INTEGERS,
    CLAMP_RESULT,
    RETURN_FINAL_RESULT
};

int main()
{

    std::string test[] {"42", "   -42", "4193 with words", "       -00473882 random words and chars %$@##  "};

    std::cout << std::endl;

    for (int i {0}; i < 4; i++)
    {
        std::cout << "Test " << i << ": " << myAtoi(test[i]) << std::endl; 
    }

    std::cout << std::endl << std::endl;

    return 0;
}


int myAtoi(std::string s)
{
    StringToIntegerParseStates currentState {LEADING_WHITE_SPACE};
    int index{0};
    int signForFinalResult {0};
    long long int runningTotal {0};
    int multiplier {10};

    if (!s.empty())
    {
        while (currentState != RETURN_FINAL_RESULT)
        {
            switch (currentState)
            {
            case LEADING_WHITE_SPACE:
                {
                    if (s[index] == ' ')
                    {
                        index++;
                    }
                    else
                    {
                        currentState = CHECK_FOR_SIGNED;
                    }
                }
                break;

            case CHECK_FOR_SIGNED:
                {
                    if (s[index] == '-')
                    {
                        signForFinalResult = -1;
                        index++;
                    }
                    else if (s[index] == '+')
                    {
                        signForFinalResult = 1;
                        index++;
                    }
                    else
                    {
                        signForFinalResult = 1;
                    }

                    currentState = PARSE_INTEGERS;
                }
                break;

            case PARSE_INTEGERS:
                {
                    if (s[index] >= 48 && s[index] <= 57)
                    {
                        runningTotal += (s[index] - 48);
                        index++;

                        while (s[index] >= 48 && s[index] <= 57)
                        {
                            if (checkOverUnderflowMultiplication(runningTotal, multiplier))
                            {
                                runningTotal *= multiplier;
                                runningTotal += (s[index] - 48);
                                index++;
                                currentState = CLAMP_RESULT;
                                break;
                            }
                            runningTotal *= multiplier;
                            runningTotal += (s[index] - 48);
                            index++;
                        }

                        runningTotal *= signForFinalResult;
                    }

                    currentState = CLAMP_RESULT;
                }
                break;

            case CLAMP_RESULT:
                {
                    if (runningTotal > INT_MAX)
                    {
                        runningTotal = INT_MAX;
                    }
                    else if (runningTotal < INT_MIN)
                    {
                        runningTotal = INT_MIN;
                    }
                    
                    currentState = RETURN_FINAL_RESULT;
                }
                break;
            
            default:
                break;
            }
        }
    }

    return runningTotal;
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