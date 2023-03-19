#include <iostream>
#include <memory>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* trav1 {l1};
        unsigned long long multiplier{1};
        unsigned long long runningTotal{0};

        // Traverse l1
        while(trav1 != nullptr)
        {
            runningTotal += trav1->val * multiplier;
            multiplier *= 10;
            trav1 = trav1->next;
        }

        trav1 = l2;
        multiplier = 1;

        // Traverse l2
        while (trav1 != nullptr)
        {
            runningTotal += trav1->val * multiplier;
            multiplier *= 10;
            trav1 = trav1->next;
        }

        ListNode* lResultHead = new ListNode{};
        unsigned long long divisor {1};
        unsigned long long modulus {divisor * 10};
        unsigned long long subsetNum{0};
        bool done {false};

        trav1 = lResultHead;

        do
        {
            subsetNum = (runningTotal % modulus);
            trav1->val = subsetNum / divisor;

            divisor *= 10;
            modulus *= 10;

            if(subsetNum == runningTotal)
            {
                done = true;
            }
            else
            {
                trav1->next = new ListNode;
                trav1 = trav1->next;
            }

        } while (!done);        
        
        return lResultHead;
    }
};



void printList(const ListNode* l)
{
    const ListNode* trav {l};

    std::cout << "[ ";
    while (trav != nullptr)
    {
        std::cout << trav->val << " ";
        trav = trav->next;
    }
    std::cout << "]" << std::endl << std::endl;
}



int main()
{
    Solution sol{};
    ListNode* lResult;

    // Create List 1
    ListNode* lhead1 = new ListNode{2};
    lhead1->next = new ListNode{4};
    lhead1->next->next = new ListNode{3};

    // Create List 2
    ListNode* lhead2 = new ListNode{5};
    lhead2->next = new ListNode{6};
    lhead2->next->next = new ListNode{4};

    lResult = sol.addTwoNumbers(lhead1, lhead2);

    printList(lResult);

    ListNode* lhead3 = new ListNode{1};
    lhead3->next = new ListNode{9};
    lhead3->next->next = new ListNode{9};
    lhead3->next->next->next = new ListNode{9};
    lhead3->next->next->next->next = new ListNode{9};
    lhead3->next->next->next->next->next = new ListNode{9};
    lhead3->next->next->next->next->next->next = new ListNode{9};
    lhead3->next->next->next->next->next->next->next = new ListNode{9};
    lhead3->next->next->next->next->next->next->next->next = new ListNode{9};
    lhead3->next->next->next->next->next->next->next->next->next = new ListNode{9};

    ListNode* lhead4 = new ListNode{9};

    lResult = sol.addTwoNumbers(lhead4, lhead3);
    printList(lResult);

    return 0;
}