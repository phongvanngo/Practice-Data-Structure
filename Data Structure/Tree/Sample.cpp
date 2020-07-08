#include "stdio.h"
struct NODE
{
    int Key;
    NODE *pLeft;
    NODE *pRight;
};
void Init(NODE *&TREE)
{
    TREE = NULL;
}
void Insert(NODE *&pRoot, int x)
{
    if (pRoot == NULL)

    {
        NODE *q;
        q = new NODE;
        q->Key = x;
        q->pLeft = q->pRight = NULL;
        pRoot = q;
    }
    else
    {
        if (x < pRoot->Key)
            Insert(pRoot->pLeft, x);
        else if (x > pRoot->Key)
            Insert(pRoot->pRight, x);
    }
}
void CreateTree(NODE *&pRoot)
{
    int Data;
    do
    {
        printf("Nhap vao du lieu, -1 de ket thuc: ");
        scanf("%d", &Data);
        if (Data == -1)
            break;
        Insert(pRoot, Data);
    } while (1);
}
void NLR(NODE *pTree)
{
    if (pTree != NULL)
    {
        NLR(pTree->pLeft);
        printf("%4d", pTree->Key);
        NLR(pTree->pRight);
    }
}
NODE *Search(NODE *pRoot, int x)
{
    if (pRoot == NULL)
        return NULL;
    if (x < pRoot->Key)
        Search(pRoot->pLeft, x);
    else if (x > pRoot->Key)
        Search(pRoot->pRight, x);
    else
    {
        //Ghi chú: Trong trường hợp nào dòng bên dưới được thực hiện?
        return pRoot;
    }
    
}
int Height(NODE *pNode)
{
    if (pNode == NULL)
        return 0;
    int HL, HR;
    HL = Height(pNode->pLeft);
    HR = Height(pNode->pRight);
    if (HL > HR)
        return (1 + HL);
    return (1 + HR);
}
void SearchStandFor(NODE *&Tree, NODE *&q)
{
    if (Tree->pRight)
        SearchStandFor(Tree->pRight, q);
    else
    {
        q->Key = Tree->Key;
        q = Tree;
        Tree = Tree->pLeft;
    }
}
void RemoveNode(NODE *&Tree, int x)
{
    NODE *p;
    if (Tree == NULL)
        printf("%d khong co trong cay", x);
    else
    {
        if (x < Tree->Key)
            RemoveNode(Tree->pLeft, x);
        else if (x > Tree->Key)
            RemoveNode(Tree->pRight, x);
        else
        {
            //Ghi chú: Mục đích phép gán này là gì?
            p = Tree;
            if (p->pRight == NULL)
                Tree = p->pLeft;
            else if (p->pLeft == NULL)
                Tree = p->pRight;
            else
            {
                //Ghi chú: Hàm bên dưới dùng để làm gì?
                SearchStandFor(Tree->pLeft, p);
            }
            delete p;
        }
    }
}

int main()
{
    NODE *pTree, *p;
    int x;
    Init(pTree);
    CreateTree(pTree);
    NLR(pTree);
    printf("Nhap vao 1 gia tri de tim: ");
    scanf("%d", &x);
    p = Search(pTree, x);
    if (p != NULL)
    {
        printf("%d co xuat hien trong cay.\n", x);
        printf("Chieu cao cua nut %d la %d\n", x, Height(p));
        RemoveNode(pTree, x);
        NLR(pTree);
    }
    else

        printf("%d khong co trong cay.\n", x);
}
