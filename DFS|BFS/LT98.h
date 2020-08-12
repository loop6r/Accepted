//
// Created by h4h4da on 6/12/20.
//

#ifndef LEETCODE_LT98_H
#define LEETCODE_LT98_H


#include <iostream>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 对于某个节点A，A节点的左子树必须小于A。A节点的右子树必须大于A。
 * 左子节点必须小于所有父亲节点
 * 右子节点必须大于所有父亲节点
 */
class LT98 {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        return traverse(root, nullptr, nullptr);
    }

    /**
     *
     * @param node
     * 对于右侧节点，记录记录遇到的最小值
     * @param minNum 左子节点可取的最大值
     * @param maxNum 右子节点可取的最大值
     * @return
     */
    bool traverse(TreeNode *node, int *minNum, int *maxNum) {
        if (node == nullptr) return true;
        if ((minNum == nullptr || node->val > *minNum) && (maxNum == nullptr || node->val < *maxNum)) {
            return traverse(node->left, minNum, &(node->val)) && traverse(node->right, &(node->val), maxNum);
        }
        return false;

    }
};


#endif //LEETCODE_LT98_H
