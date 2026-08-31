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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mindistance = INT_MAX;
        int maxdistance = INT_MIN;
        vector<int> index;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int count = 0;
        while (temp->next != NULL) {
            count++;
            ListNode* curr = temp->next;
            if (prev != NULL && curr != NULL) {
                if (temp->val < prev->val && temp->val < curr->val) {
                    index.push_back(count);
                } else if (temp->val > prev->val && temp->val > curr->val) {
                    index.push_back(count);
                }
            }
            prev = temp;
            temp = curr;
        }
        if (index.size() > 1)
            maxdistance = index[index.size() - 1] - index[0];

        for (int i = 1; i < index.size(); i++) {
            int dis = index[i] - index[i - 1];

            if (dis < mindistance)
                mindistance = dis;
        }

        if (maxdistance == INT_MIN) {
            maxdistance = -1;
        }
        if (mindistance == INT_MAX) {
            mindistance = -1;
        }

        return {mindistance, maxdistance};
    }
};