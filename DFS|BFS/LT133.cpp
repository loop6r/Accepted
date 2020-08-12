//
// Created by h4h4da on 8/12/20.
//

#include <vector>
#include <queue>

using namespace std;


class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;
        vector<Node *> cached = vector<Node *>();
        vector<Node *> finishedCloneList = vector<Node *>();
        Node *root = new Node();
        cached.push_back(root);
        traverse(node, root, cached, finishedCloneList);
        return root;
    }

    void traverse(Node *node, Node *cloneItem, vector<Node *> &cachedList, vector<Node *> &finishedCloneList) {
        cloneItem->val = node->val;
        if (isExist(node, finishedCloneList)) return;
        if (node->neighbors.empty()) {
            cachedList.push_back(cloneItem);
            finishedCloneList.push_back(cloneItem);
            return;
        }
        //复制node的子节点到 cloneItem下面
        for (Node *it:node->neighbors) {
            Node *cachedItem = getNodeFromCache(it, cachedList, finishedCloneList);
            cloneItem->neighbors.push_back(cachedItem);
        }
        //将node加入已经复制的列表中，防止无限递归。
        finishedCloneList.push_back(node);
        //向下递归子节点
        for (int i = 0; i < node->neighbors.size(); i++) {
            traverse(node->neighbors[i], cloneItem->neighbors[i], cachedList, finishedCloneList);
        }
    }

    /**
     * 尝试从缓存中获取节点，没有则创建
     * @param current
     * @param cachedList
     * @param finishedCloneList
     * @return
     */
    Node *getNodeFromCache(Node *current, vector<Node *> &cachedList, vector<Node *> &finishedCloneList) {

        for (Node *c:cachedList) {
            if (current->val == c->val) {
                return c;
            }
        }
        Node *newNode = new Node();
        newNode->val = current->val;
        cachedList.push_back(newNode);
        return newNode;
    }

    bool isExist(Node *t, vector<Node *> &finishedCloneList) {
        for (Node *n:finishedCloneList) {
            if (t->val == n->val) {
                return true;
            }
        }
        return false;
    }

};