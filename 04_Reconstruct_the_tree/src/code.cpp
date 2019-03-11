//
// Created by 邓宇兵 on 2019-03-11.
//
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
{
    int tree_length = pre.size();
    if(tree_length == 0)
    {
        return NULL;
    }
    TreeNode* head = new TreeNode(pre[0]);
    vector<int>left_pre,left_mid,right_pre,right_mid;
  //定义存储左右子树的前序和中序的向量
    int node_pos = 0;
  //用前序和中序找到根节点在中序时的位置
    for (int i = 0; i < tree_length; ++i)
    {
        if(pre[0] == vin[i])
        {
           node_pos = i;
            break;
        }
    }
  //用左右子树向量分别去存储左右子树
    for (int j = 0; j < node_pos; j++)
    {
        left_mid.push_back(vin[j]);
        left_pre.push_back(pre[j+1]);

    }
    for (int k = node_pos+1; k < tree_length; k++)
    {
        right_mid.push_back(vin[k]);
        right_pre.push_back(pre[k]);

    }
  //递归调用重建树
    head->left = reConstructBinaryTree(left_pre,left_mid);
    head->right = reConstructBinaryTree(right_pre,right_mid);
    //cout << head->val << endl;
    return head;
}
int main()
{
    vector<int>tree_pre,tree_mid;
    TreeNode* node;
    tree_pre = {1,2,4,7,3,5,6,8};
    tree_mid = {4,7,2,1,5,3,8,6};
    node = reConstructBinaryTree(tree_pre,tree_mid);
    return 0;
}

