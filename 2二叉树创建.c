#include "stdio.h"
#include "stdlib.h"
typedef struct tree{
    char data;
    struct tree *lchild;
    struct tree *rchild;
}tree;
//创建结点
void CreateTree(tree **p){
    char check;//用于判断是否创建左右孩子
    char info;
    *p=(tree*) malloc(sizeof(tree));
    printf("请输入结点信息:");
    scanf("%c",&info);
    getchar();//用于接收scanf后的回车字符
    (*p)->data=info;
    printf("是否创建%c左孩子?",(*p)->data);
    scanf("%c",&check);
    getchar();
    if(check=='Y'){
        CreateTree(&((*p)->lchild));//递归创建左孩子
    } else{
        (*p)->lchild=NULL;
    }
    printf("是否创建%c右孩子?",(*p)->data);
    scanf("%c",&check);
    getchar();
    if(check=='Y'){
        CreateTree(&((*p)->rchild));
    } else{
        (*p)->rchild=NULL;
    }
}
/*----公共部分---*/
int top=-1;
//前序遍历使用的进栈函数
void push(tree** a,tree* elem){
    a[++top]=elem;
}
//弹栈函数
void pop( ){
    if (top==-1) {
        return ;
    }
    top--;
}
//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(tree* elem){
    printf("%c ",elem->data);
}
//拿到栈顶元素
tree* getTop(tree**a){
    return a[top];
}
/*----公共部分---*/

/*------先序遍历------*/
//先序遍历非递归算法
void PreOrderTraverse(tree* Tree){
    tree* a[20];//定义一个顺序栈
    tree * p;//临时指针
    push(a, Tree);//根结点进栈
    while (top!=-1) {
        p=getTop(a);//取栈顶元素
        pop();//弹栈
        while (p) {
            displayElem(p);//调用结点的操作函数
            //如果该结点有右孩子，右孩子进栈
            if (p->rchild) {
                push(a,p->rchild);
            }
            p=p->lchild;//一直指向根结点最后一个左孩子
        }
    }
}
/*------先序遍历------*/

/*------中序遍历------*/
//中序遍历非递归算法
void InOrderTraverse1(tree* Tree){
    tree* a[20];//定义一个顺序栈
    tree * p;//临时指针
    push(a, Tree);//根结点进栈
    while (top!=-1) {//top!=-1说明栈内不为空，程序继续运行
        while ((p=getTop(a)) &&p){//取栈顶元素，且不能为NULL
            push(a, p->lchild);//将该结点的左孩子进栈，如果没有左孩子，NULL进栈
        }
        pop();//跳出循环，栈顶元素肯定为NULL，将NULL弹栈
        if (top!=-1) {
            p=getTop(a);//取栈顶元素
            pop();//栈顶元素弹栈
            displayElem(p);
            push(a, p->rchild);//将p指向的结点的右孩子进栈
        }
    }
}
/*------中序遍历------*/

/*------后序遍历------*/
//后序遍历
void PostOrderTraverse1(tree* T){
    if (T) {
        PostOrderTraverse1(T->lchild);//遍历左孩子
        PostOrderTraverse1(T->rchild);//遍历右孩子
        displayElem(T);//调用操作结点数据的函数方法
    }
    //如果结点为空，返回上一层
    return;
}
/*------后序遍历------*/
int main(void){
    tree *p;
    CreateTree(&p);
    printf("先序遍历：");
    PreOrderTraverse(p);
    printf("\n中序遍历：");
    InOrderTraverse1(p);
    printf("\n后序遍历：");
    PostOrderTraverse1(p);
}
