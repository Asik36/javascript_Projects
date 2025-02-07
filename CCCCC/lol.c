#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Node {
    char* data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(char* data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/'); 
}

int getNum(char* str, int n){
    int num = 0;
    if(isdigit(str[n])){
        num = 0;
        while(isdigit(str[n])){
            num = num * 10 + (str[n] - '0');
            n++;
        }
    }

}

Node* solve(Node* node , char* str,int n){
    if(n == 0){
        return node;
    }
    if(str[n-1] == '+' || str[n-1] == '-'){
        node = createNode(str[n-1]);
        node->right =createNode(getNum(str,n));
        solve(node->left, str,n--);

    }
    else{
        solve(node, str, n--);
    }
}
void treeOpe(Node* node){
 
}


//n 
// 5/42+5+300

//aefkoaefoia




void insertEeq(Node* operatorNode, Node* numNode1, Node *numNode2){
    operatorNode->right = numNode2;
    operatorNode->left = numNode1;
}
void printTree(Node* node){
    if(node == NULL)
        return;
    printTree(node->right);
    printf("%c ", node->data);
    printTree(node->left);
}

int main(){
    char expression[] = "5+4-3";
    Node* root;
    solve(root,expression,6);
    printf("The postfix expression is: ");
    printTree(root);
    return 0;
}