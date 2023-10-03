#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ptrLongerList{nullptr};
        ListNode *firstNode{nullptr};
        ListNode *currentNode{nullptr};
        int sum{l1->val + l2->val};
        bool carry{false};

        if (sum > 9)
        {
            carry = true;
            sum -= 10;
        }

        firstNode = new ListNode(sum);
        currentNode = firstNode;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val;
            if (carry)
            {
                sum++;
            }

            if (sum > 9)
            {
                carry = true;
                sum -= 10;
            }
            else
            {
                carry = false;
            }

            currentNode->next = new ListNode(sum);
            currentNode = currentNode->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ptrLongerList = (l1 == nullptr) ? l2 : l1;

        while (ptrLongerList != nullptr)
        {
            sum = ptrLongerList->val;
            if (carry)
            {
                sum++;
            }

            if (sum > 9)
            {
                carry = true;
                sum -= 10;
            }
            else
            {
                carry = false;
            }

            currentNode->next = new ListNode(sum);
            currentNode = currentNode->next;

            ptrLongerList = ptrLongerList->next;
        }

        if (carry)
        {
            currentNode->next = new ListNode(1);
        }

        return firstNode;
    }
};

int main()
{
    // ListNode l1{9};
    // ListNode l2{9, &l1};
    // ListNode l3{9, &l2};
    // ListNode l4{9, &l3};
    // ListNode l5{9, &l4};
    // ListNode l6{9, &l5};
    // ListNode l7{9, &l6};

    // ListNode l8{9};
    // ListNode l9{9, &l4};
    // ListNode l10{9, &l5};
    // ListNode l11{};

    // ListNode *l1 = new ListNode{9};
    // for (int i{0}; i < 6; i++)
    // {
    //     l1 = new ListNode{9, l1};
    // }

    // ListNode *l2 = new ListNode{9};
    // for (int i = 0; i < 3; i++)
    // {
    //     l2 = new ListNode{9, l2};
    // }

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(8);

    ListNode *l2 = new ListNode(0);

    Solution sol;

    ListNode *newList = sol.addTwoNumbers(l1, l2);
    ListNode *ptrList{newList};

    while (ptrList != nullptr)
    {
        std::cout << ptrList->val << "->";
        ptrList = ptrList->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}