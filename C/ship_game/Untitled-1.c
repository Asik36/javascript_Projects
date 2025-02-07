#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
char getLastCharacter(char *string);
unsigned count_occurences (const char s1[], const char s2[]);
char * func(char word[], int length, int key);
void firstEqualLast();
void getName();
void LongerOne();
void delete_char(char src[], char c);
void reverse (char str[]);
int sumNumbersInString(char string[]);
int main() {
    char s1[] = "hello";
    char s2 = '-';
    printf("%s",func(s1,6,3));
    return 0;
}

void delete_char(char src[], char c){
    int i;
    int j;
    for (i = 0, j = 0; src[i]!= '\0'; i++) {
        if (src[i]!= c) {
            src[j++] = src[i];
        }
    }
    src[j] = '\0';
}

int sumNumbersInString(char string[]){
    int sum = 0;
    int num = 0;
    int i = 0;
    while(string[i]!= '\0'){
        num = 0;
        while(string[i] >= '0' && string[i] <= '9'){
            num = num * 10 + string[i] - '0';
            i++;
        }
        sum += num;

        i++;
    }
    return sum;
}
unsigned count_occurences (const char s1[], const char s2[]){
    unsigned int count = 0;
    int i = 0;
    while(s1[i]!= '\0'){
        if(s1[i] == s2[0]){
            int j = 0;
            int found = 1;
            while(s1[i+j]!= '\0' && s2[j]!= '\0'){
                if(s1[i+j]!= s2[j]){
                    found = 0;
                    break;
                }
                j++;
            }
            
            if(found && s2[j] == '\0'){
                count++;
            }
        }
        i++;
    }
    return count;


}

void reverse (char str[]){
    int start = 0;
    int end = 0;
    while(str[end] != '\0'){
        end++;
    }
    end--;
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


void getName(){
    printf("Enter your name and your lastName: ");
    char name[12];
    
    gets(name);
    int i = 0;
    while(name[i] != '\0'){
        if(i >= 12){
            printf("Error: Name too long\n");
            return;
        }
        i++;
    }
    i = 0;
    while(name[i] != '\0'){
    
        if(name[i] == ' '){
            printf("\n");
            i++;
        }
        printf("%c", name[i]);
        i++;
        
    }

}
void LongerOne(){
    int length1 = 0;
    int length2 = 0;
    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    while(s1[length1]!= '\0'){
        length1++;
    }
    while(s2[length2]!= '\0'){
        length2++;
    }
    if(length1> length2){
        if(length1 >= length2*2){
            printf("%s",s1);
        } else{
            printf("%s",s2);
        }
    }
    else if(length2> length1){
        if(length2 >= length1*2){
            printf("%s",s2);
        } else{
            printf("%s",s1);
        }
    }
    
}


char getLastCharacter(char *string) {
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return string[i-1];
}
void firstEqualLast(){
    char arr[15][20];
    for (int i = 0; i < 15; i++)
    {
        gets(arr[i]);
        
    }
    for (int i = 0; i < 15; i++)
    {
        if(arr[i][0] == getLastCharacter(arr[i])){
            printf("%s\n",arr[i]);
        }
    } 
    
}

char * func(char word[], int length, int key) {

    for (int i = 0; i < length; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = ((word[i] - 'a' + key) % 26) + 'a';

        } else if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = ((word[i] - 'A' + key) % 26) + 'A';
        }
    }

    return word;
}