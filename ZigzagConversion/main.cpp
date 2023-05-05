#include <iostream>
#include <vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        int rowNumToPushChar{0};
        int currentRow{0};
        bool pushColumn{true};
        std::string output{};

        std::string *string_matrix = new std::string[numRows];

        if (numRows == 1)
        {
            return s;
        }
        else if (numRows == 2)
        {
            for (size_t i{0}; i < s.size(); i += 2)
            {
                output.push_back(s[i]);
            }

            for (size_t i{1}; i < s.size(); i += 2)
            {
                output.push_back(s[i]);
            }
            
            return output;
        }
        else
        {
            for (size_t i{0}; i < s.size(); i++)
            {
                if (pushColumn == true)
                {
                    string_matrix[rowNumToPushChar].push_back(s[i]);
                    rowNumToPushChar++;

                    if (rowNumToPushChar == numRows)
                    {
                        pushColumn = false;
                        rowNumToPushChar = numRows - 1 - 1;
                    }
                }

                else // push diagonal
                {
                    while (currentRow != rowNumToPushChar)
                    {
                        string_matrix[currentRow].push_back(' ');
                        currentRow++;
                    }

                    string_matrix[currentRow].push_back(s[i]);
                    rowNumToPushChar--;
                    currentRow++;

                    while (currentRow < numRows)
                    {
                        string_matrix[currentRow].push_back(' ');
                        currentRow++;
                    }

                    currentRow = 0;

                    if (rowNumToPushChar == 0)
                    {
                        pushColumn = true;
                    }
                }
            }
        }

        for (int i{0}; i < numRows; i++)
        {
            for (auto c : string_matrix[i])
            {
                if (c != ' ')
                {
                    output.push_back(c);
                }
            }
        }

        return output;
    }
};

int main()
{
    Solution s{};
    std::string test1{"PAYPALISHIRING"};

    std::cout << s.convert(test1, 1) << std::endl;
    std::cout << s.convert(test1, 2) << std::endl;
    std::cout << s.convert(test1, 3) << std::endl;
    std::cout << s.convert(test1, 4) << std::endl;

    return 0;
}