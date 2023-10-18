#include <iostream>
#include <string>
#include <map>

std::map<std::pair<int, int>, bool> cache{};

class Solution
{
private:
    bool dfs(const std::string &s, const std::string &p, const int &i, const int &j)
    {
        std::cout << cache.count({std::make_pair(i, j)}) << std::endl;
        if (cache.count({std::make_pair(i, j)}))
        {
            return cache[std::make_pair(i, j)];
        }

        if ((i >= s.size()) && (j >= p.size()))
        {
            return true;
        }
        else if (j >= p.size())
        {
            return false;
        }

        bool match{(i < s.size()) && ((s[i] == p[j]) || (p[j] == '.'))};

        if (((j + 1) < p.size()) && (p[j + 1] == '*'))
        {
            cache.insert({std::make_pair(i, j), (dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j)))});
            return cache[std::make_pair(i, j)];
            // return (dfs(cache, s, p, i, j + 2) || (match && dfs(cache, s, p, i + 1, j)));
        }
        else if (match)
        {
            cache.insert({std::make_pair(i, j), dfs(s, p, i + 1, j + 1)});
            return cache[std::make_pair(i, j)];
        }
        else
        {
            cache.insert({std::make_pair(i, j), false});
            return false;
        }
    }

public:
    bool isMatch(std::string s, std::string p)
    {
        return dfs(s, p, 0, 0);
    }
};

int main()
{
    Solution sol{};
    std::string s1{"asdfgaccccuisabcpoclld"};
    std::string p1{"a.*ac*bc.*c.*"};

    std::cout << sol.isMatch(s1, p1) << std::endl;

    return 0;
}