#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool used[10];

struct assiged{
    char ch;
    int val;
};
bool check(int uniqueChar, struct assiged assignlist[], char* s1, char* s2, char* s3){
    int i1=0,i2=0,i3=0,i=0;
    // char c;
    while(s1[i]!="\0"){
        i1*=10;
        for (int j=0;j<uniqueChar;j++){
            if (s1[i] ==assignlist[j].ch){
                i1+=assignlist[j].val;
                j=uniqueChar;
            }
        }
    }
    i=0;
    while(s2[i]!="\0"){
        i2*=10;
        for (int j=0;j<uniqueChar;j++){
            if (s2[i] ==assignlist[j].ch){
                i2+=assignlist[j].val;
                j=uniqueChar;
            }
        }
    }
    i=0;
    while(s3[i]!="\0"){
        i3*=10;
        for (int j=0;j<uniqueChar;j++){
            if (s3[i] ==assignlist[j].ch){
                i3+=assignlist[j].val;
                j=uniqueChar;
            }
        }
    }
    return(i3==i1+i2);
}
void permutate(int uniqueChar,int n,struct assiged assignlist[], char* s1, char* s2, char* s3){
    if (uniqueChar-n == 1)

}

void findcsp(char* s1, char* s2, char* s3){
    int len1= strlen(s1);
    int len2= strlen(s2);
    int len3= strlen(s3);

    int freq[26] = {0};

    for (int i = 0; i < len1; i++) {
        ++freq[s1[i] - "a"];
    }
    for (int i = 0; i < len2; i++) {
        ++freq[s2[i] - "a"];
    }
    for (int i = 0; i < len3; i++) {
        ++freq[s3[i] - "a"];
    }
    int uniqueChar = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            uniqueChar++;
        }
    }
    // if (uniqueChar > 10) {
    //     printf("Invalid strings\n");
    //     return;
    // }
    struct assiged assignlist[uniqueChar];
    int i=0,int j=0;
    while (i<26){
        if(freq[i] > 0){
            assignlist[j].ch= (char) (i + "a");
            j++;
        }
    }
    for (i=0;i<10;i++){
        used[i]=false;
    }
    permutate(uniqueChar,0,assignlist,s1,s2,s3);
}
