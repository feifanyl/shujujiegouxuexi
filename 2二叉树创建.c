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
int main(void){
    tree *p;
    CreateTree(&p);
    prn(p);
    printf("%c",p->data);
}
