#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) : val(_val),left(nullptr),right(nullptr){}
};
void preOrder(TreeNode* root)
{
    auto node = root;
    stack<TreeNode*> stk;
    while(node || stk.size())
    {
        while(node)
        {
            std::cout << node->val << " \n";
            stk.push(node);
            node = node->left;
        }

        node = stk.top();
        stk.pop();
        node = node->right;
    }
}
void inOrder(TreeNode* root)
{
    auto node = root;
    stack<TreeNode*> stk;
    while(node || stk.size())
    {
        while(node)
        {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        std::cout << node->val << " \n";
        stk.pop();
        node = node->right;
    }
}
void postOrder(TreeNode* root)
{
    auto node = root;
    TreeNode* pre = nullptr;
    stack<TreeNode*> stk;
    while(node || stk.size())
    {
        while(node)
        {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();

        if(node->right == nullptr || node->right == pre)
        {
            std::cout << node->val << " \n";
            pre = node;
            node = nullptr;
        }
        else
        {
            stk.push(node);
            node = node->right;
        }
    }
}
int main()
{
    
}