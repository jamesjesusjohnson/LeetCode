#include <iostream>
#include <memory>

struct ListNode
{
    int val;
    std::shared_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, std::shared_ptr<ListNode> next) : val(x), next(next) {}
};
 
class Solution
{
public:
    std::shared_ptr<ListNode> addTwoNumbers(std::shared_ptr<ListNode> l1, std::shared_ptr<ListNode> l2)
    {
        int runningTotal {0};
        int multiplier {1};
        std::shared_ptr<ListNode> trav {l1};

        while (trav != nullptr)
        {
            runningTotal += trav->val * multiplier;
            multiplier *= 10;
            trav = trav->next;
        }

        multiplier = 1;
        trav = l2;

        while (trav != nullptr)
        {
            runningTotal += trav->val * multiplier;
            multiplier *= 10;
            trav = trav->next;
        }

        std::shared_ptr returnList = std::make_shared<ListNode>(0);
        int divisor {1};
        int modulus {10};
        int subset {0};
        bool done {false};

        trav = returnList;

        do
        {
            subset = runningTotal % modulus;
            trav->val = subset / divisor;

            modulus *= 10;
            divisor *= 10;

            if (subset == runningTotal)
            {
                done = true;
            }
            else
            {
                trav->next = std::make_shared<ListNode>();
            }

            trav = trav->next;

        } while (!done);

        return returnList;
    }
};


void print(const std::shared_ptr<ListNode>& l)
{
    std::shared_ptr<ListNode> trav {l};

    std::cout << "[ ";
    while(trav != nullptr)
    {
        std::cout << trav->val << " ";
        trav = trav->next;
    }
    std::cout << "]" << std::endl;
}


int main()
{
    Solution sol{};
    std::shared_ptr<ListNode> lResult;

    // Create List 1
    std::shared_ptr<ListNode> lhead1 = std::make_shared<ListNode>(2);
    lhead1->next = std::make_shared<ListNode>(4);
    lhead1->next->next = std::make_shared<ListNode>(3);

    // Create List 2
    std::shared_ptr<ListNode> lhead2 = std::make_shared<ListNode>(5);
    lhead2->next = std::make_shared<ListNode>(6);
    lhead2->next->next = std::make_shared<ListNode>(4);

    lResult = sol.addTwoNumbers(lhead1, lhead2);
    print(lResult);

    // Create List 3 & 4
    std::shared_ptr<ListNode> lhead3 = std::make_shared<ListNode>(0);
    std::shared_ptr<ListNode> lhead4 = std::make_shared<ListNode>(0);

    lResult = sol.addTwoNumbers(lhead3, lhead4);
    print(lResult);

    // Create List 5
    std::shared_ptr<ListNode> lhead5 = std::make_shared<ListNode>(9);
    lhead5->next = std::make_shared<ListNode>(9);
    lhead5->next->next = std::make_shared<ListNode>(9);
    lhead5->next->next->next = std::make_shared<ListNode>(9);
    lhead5->next->next->next->next = std::make_shared<ListNode>(9);
    lhead5->next->next->next->next->next = std::make_shared<ListNode>(9);
    lhead5->next->next->next->next->next->next = std::make_shared<ListNode>(9);

    // Create List 6
    std::shared_ptr<ListNode> lhead6 = std::make_shared<ListNode>(9);
    lhead6->next = std::make_shared<ListNode>(9);
    lhead6->next->next = std::make_shared<ListNode>(9);
    lhead6->next->next->next = std::make_shared<ListNode>(9);

    lResult = sol.addTwoNumbers(lhead5, lhead6);
    print(lResult);

    return 0;
}