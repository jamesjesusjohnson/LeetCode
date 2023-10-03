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
        ListNode *newListStart{nullptr};
        ListNode *ptrLongerList{nullptr};
        int sum{l1->val + l2->val};
        bool carry{false};

        if (sum > 9)
        {
            carry = true;
            sum -= 10;
        }

        ListNode *firstNode = new ListNode(sum);
        newListStart = firstNode;
        ListNode *currentNode = firstNode;

        ListNode *newNode {nullptr};

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

            newNode = new ListNode(sum);
            currentNode->next = newNode;
            currentNode = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }

        // Did we run out of l1 or l2?
        if (l1 == nullptr)
        {
            ptrLongerList = l2;
        }
        else
        {
            ptrLongerList = l1;
        }

        while (ptrLongerList != nullptr)
        {
            if (carry)
            {
                sum = ptrLongerList->val + 1;
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

            ListNode *newNode = new ListNode(ptrLongerList->val);
            currentNode->next = newNode;
            currentNode = newNode;
            ptrLongerList = ptrLongerList->next;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(1);
            currentNode->next = newNode;
        }

        return newListStart;
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

    ListNode *l1 = new ListNode{9};
    for (int i{0}; i < 7; i++)
    {
        l1 = new ListNode{9, l1};
    }

    // ListNode l8{9};
    // ListNode l9{9, &l4};
    // ListNode l10{9, &l5};
    // ListNode l11{};

    ListNode *l2 = new ListNode{9};
    for (int i = 0; i < 4; i++)
    {
        l2 = new ListNode{9, l2};
    }

    Solution sol;

    sol.addTwoNumbers(l1, l2);

    return 0;
}