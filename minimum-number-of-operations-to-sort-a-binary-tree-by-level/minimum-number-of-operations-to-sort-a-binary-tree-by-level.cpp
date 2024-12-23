/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findMinSwap(vector<int> &arr) {
        map<int,int> elemIdxMap;
        vector<int> sortedArr(arr.begin(), arr.end());
        int res = 0;

        sort(sortedArr.begin(), sortedArr.end());

        for(int i=0;i<arr.size();i++) {
            elemIdxMap[arr[i]] = i;
        }

        for(int i=0;i<arr.size();i++) {
            if(arr[i] != sortedArr[i]) {
                int sortedIdx = elemIdxMap[sortedArr[i]];
                elemIdxMap[arr[i]] = sortedIdx;
                // elemIdxMap[arr[sortedIdx]] = i;
                swap(arr[i], arr[sortedIdx]);
                res++;
            }
        }

        return res;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> arr(size);

            for(int i=0;i<size;i++) {
                arr[i] = q.front()->val;

                if(q.front()->left)
                    q.push(q.front()->left);
                
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }

            res += findMinSwap(arr);
        }

        return res;
    }
};