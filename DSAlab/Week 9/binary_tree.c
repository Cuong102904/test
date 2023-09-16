#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
    int data;
    struct treeNode *leftmost_child;
    struct treeNode *right_sibling;
} treeNode;
treeNode *Root;

treeNode *makeNode(int val)
{
    treeNode *p = (treeNode *)malloc(sizeof(treeNode));
    p->data = val;
    p->leftmost_child = NULL;
    p->right_sibling = NULL;
    return p;
}

int countNodes(treeNode *Root)  
{
    if (Root == NULL)
        return 0;
    else
    {
        int ld = countNodes(Root->leftmost_child);
        int rd = countNodes(Root->right_sibling);
        return 1 + ld + rd;
    }
}
int depth(treeNode *Root)
{
    if (Root == NULL)
        return 0;
    int ld = depth(Root->leftmost_child);
    int rd = depth(Root->right_sibling);
    return 1 + (ld > rd ? ld : rd);
}

void freeTree(treeNode *Root)
{
    if (Root == NULL)
        return;
    freeTree(Root->leftmost_child);
    freeTree(Root->right_sibling);
    free(Root);
}
void PreOrder(treeNode *Root)
{
    if (Root != NULL)
    {
        printf("%d ", Root->data);
        PreOrder(Root->leftmost_child);
        PreOrder(Root->right_sibling);
    }
}
void PostOrder(treeNode *Root)
{
    if (Root != NULL)
    {
        PostOrder(Root->leftmost_child);
        PostOrder(Root->right_sibling);
        printf("%d ", Root->data);
    }
}
void InOrder(treeNode *Root)
{
    if (Root != NULL)
    {
        InOrder(Root->leftmost_child);
        printf("%d ", Root->data);
        InOrder(Root->right_sibling);
    }
}
/*
treeNode *find(treeNode *root, int u)
{
    if (root == NULL)
        return NULL;
    if (root->data == u)
        return root;
    treeNode *p = root->leftmost_child;
    while (p != NULL)
    {
        treeNode *q = find(p, u);
        if (q != NULL)
            return NULL;
        p = p->right_sibling;
    }
    return NULL;
}*/

treeNode *find(treeNode *Root, int u)
{
    if (Root == NULL)
        return NULL;
    if (Root->data == u)
        return Root;
    treeNode *p = find(Root->leftmost_child, u);
    if (p != NULL)
        return p;
    return find(Root->right_sibling, u);
}

void AddLeft(int u, int v)
{
    treeNode *pu = find(Root, v);
    if (pu == NULL)
    {
        return;
    }
    if (pu->leftmost_child != NULL)
    {
        return;
    }
    pu->leftmost_child = makeNode(u);
}

void Addright(int u, int v)
{
    treeNode *pu = find(Root, v);
    if (pu == NULL)
    {
        return;
    }
    if (pu->right_sibling != NULL)
    {
        return;
    }
    pu->right_sibling = makeNode(u);
}

int main()
{
    Root = NULL;
    char trash[20];
    while (1)
    {
        scanf("%s", trash);
        if (strcmp(trash, "*") == 0)
            break;
        if (strcmp(trash, "MakeRoot") == 0)
        {
            int val;
            scanf("%d", &val);
            Root = makeNode(val);
        }
        if (strcmp(trash, "AddLeft") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AddLeft(u, v);
        }
        if (strcmp(trash, "AddRight") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            Addright(u, v);
        }

        if (strcmp(trash, "PreOrder") == 0)
        {
            PreOrder(Root);
            printf("\n");
        }
        if (strcmp(trash, "PostOrder") == 0)
        {
            PostOrder(Root);
            printf("\n");
        }
        if (strcmp(trash, "InOrder") == 0)
        {
            InOrder(Root);
            printf("\n");
        }
    }

    return 0;
}
