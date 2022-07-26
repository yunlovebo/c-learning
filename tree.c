#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * 生成随机二叉树
 */

typedef struct node {
    char data;
    struct node *left, *right;
} node;

node *insert_node(node *root, char c) {
    if(root == NULL) {
        node *p = (node *)malloc(sizeof(node));
        p->data = c;
        p->left = p->right = NULL;
        return p;
    }
    int x = rand() % 2;
    if (x == 0) {
        root->left = insert_node(root->left, c);
    } else {
        root->right = insert_node(root->right, c);
    }
    return root;
}

void preorder(node *root) {
    if (root == NULL) {
        return ;
    }
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == NULL) {
        return ;
    }
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void postorder(node *root) {
    if (root == NULL) {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

/**
 * @brief 层序遍历，需要一个队列num
 * 
 * @param root 
 */
void lefelorder(node *root) {
    node *num[30];
    int front = 0, rear = 1;
    num[0] = root;
    while(front != rear) { // 队列非空时
        // step1. 拿出队首、出队、打印
        node *p = num[front];
        front++;
        printf("%c", p->data);
        // step2. 左子树、右子树非空时，分别入队
        if (p->left != NULL) num[rear++] = p->left;
        if (p->right != NULL) num[rear++] = p->right;
    }
    printf("\n");
}


int main() {
    srand(time(0));
    int n, mark[30] = {0};
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x = rand() % 26;
        while(mark[x] == 1) {
            x = rand() % 26;
        }
        mark[x] = 1;
        root = insert_node(root, 'A' + x);
    }

    printf("先序：");
    preorder(root);
    printf("\n");
    printf("中序：");
    inorder(root);
    printf("\n");
    printf("后序：");
    postorder(root);
    printf("\n");
    printf("层序：");
    lefelorder(root); // 层序遍历
    printf("\n");


    return 0;
}
/**
 * 先序：CZAFLYXMGP
 * 中序：FALZYXCGMP
 * 还原二叉树，写出它的后序: FLAXYZGPMC
 * 
 */


