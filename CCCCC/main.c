#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

Node* buildExpressionTree(char* expression, int start, int end) {
    if (start > end) return NULL;

    int minPrecedence = INT_MAX;
    int minIndex = -1;
    int parenCount = 0;

    for (int i = start; i <= end; i++) {
        if (expression[i] == '(') {
            parenCount++;
        } else if (expression[i] == ')') {
            parenCount--;
        } else if (isOperator(expression[i]) && parenCount == 0) {
            int currentPrecedence = precedence(expression[i]);
            if (currentPrecedence <= minPrecedence) {
                minPrecedence = currentPrecedence;
                minIndex = i;
            }
        }
    }

    if (minIndex == -1) {
        if (expression[start] == '(' && expression[end] == ')') {
            return buildExpressionTree(expression, start + 1, end - 1);
        } else {
            return createNode(expression[start]);
        }
    }

    Node* root = createNode(expression[minIndex]);

    root->left = buildExpressionTree(expression, start, minIndex - 1);
    root->right = buildExpressionTree(expression, minIndex + 1, end);

    return root;
}

int evaluateExpressionTree(Node* root) {
    if (root == NULL) return 0;

    if (!root->left && !root->right) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0;
    }
}

void printTree(Node* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%c ", root->data);
    printTree(root->right);
}

int main() {
    char expression[] = "(3+5)*(7-2)";
    int length = strlen(expression);

    Node* root = buildExpressionTree(expression, 0, length - 1);

    printf("In-order traversal of the expression tree: ");
    printTree(root);
    printf("\n");

    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}