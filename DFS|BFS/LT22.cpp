//
// Created by h4h4da on 8/12/20.
//

#include <vector>
#include <string>

using namespace std;


class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> *v1 = new vector<string>();
        traverse("", 2 * n, 0, 0, v1);
        return *v1;
    }

    void traverse(string parent, int total, int depth, int rightCount, vector<string> *c) {
        //达到最深的节点，停止递归
        if (depth > total) return;
        //不合法的节点1：当前深度左节点小于右节点的个数。 2左节点超过一半。3右节点超过一半。
        if (rightCount > depth - rightCount || rightCount > total / 2 || depth - rightCount > total / 2) return;
        if (depth == total) {
            c->push_back(parent);
            return;
        }
        traverse(parent + "(", total, depth + 1, rightCount, c);
        traverse(parent + ")", total, depth + 1, rightCount + 1, c);
    }


};

