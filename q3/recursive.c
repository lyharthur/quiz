#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 }TreeNode;
void flatten(struct TreeNode *root){
    if(!root)return ;
    if(root->left) flatten(root->left);
    if(root->right) flatten(root->right);
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left=NULL;
    while(root->right)
        root=root->right;
    root->right=tmp;
    return;
}
void inorderTraversal(TreeNode *root)
{
    if(!root)
        return;
    inorderTraversal(root->left);
    printf("%d ",root->val);
    inorderTraversal(root->right);
}
void posorderTraversal(TreeNode *root)
{
    if(!root)
        return;
    posorderTraversal(root->left);
    posorderTraversal(root->right);
    printf("%d ",root->val);
}

int main()
{
    TreeNode* root;
    TreeNode* cursor;

    root = malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = malloc(sizeof(TreeNode));
    root->right= malloc(sizeof(TreeNode));

    cursor = root->left;
    cursor->val = 2;
    cursor->left = malloc(sizeof(TreeNode));
    cursor->right= malloc(sizeof(TreeNode));

    cursor = root->right;
    cursor->val = 5;
    cursor->left = NULL;
    cursor->right= malloc(sizeof(TreeNode));

    cursor = (root->left)->left;
    cursor->val = 3;
    cursor->left = NULL;
    cursor->right= NULL;

    cursor = (root->left)->right;
    cursor->val = 4;
    cursor->left = NULL;
    cursor->right= NULL;

    cursor = (root->right)->right;
    cursor->val = 6;
    cursor->left = malloc(sizeof(TreeNode));
    cursor->right= NULL;

    cursor = (cursor)->left;
    cursor->val = 7;
    cursor->left = NULL;
    cursor->right= NULL;


    printf("Before:\nInorder:");
    inorderTraversal(root);
    printf("\nPosorder:");
    posorderTraversal(root);
    printf("\n");

    flatten(root);

    printf("After:\nInorder:");
    inorderTraversal(root);
    printf("\nPosorder:");
    posorderTraversal(root);
    printf("\n");
    free(root);
    return 0;
}


