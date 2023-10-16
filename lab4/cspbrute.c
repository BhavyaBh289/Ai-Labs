#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool used[10];

struct assiged{
    char ch;
    int val;
};
bool sol = false;
int nums = 0;
bool check(int uniqueChar, struct assiged assignlist[], char* s1, char* s2, char* s3){
    int i1=0, i2=0, i3=0, i=0;
    int k = strlen(s1);
    while (i<k){
        i1*=10;
        for (int j=0; j<uniqueChar; j++){
            if (s1[i] == assignlist[j].ch){
                i1 +=assignlist[j].val;
                j = uniqueChar;
            }
        }
        i++;
    }
    i=0;
    k = strlen(s2);
    while (i<k){
        i2*=10;
        for (int j=0; j<uniqueChar; j++){
            if (s2[i] ==assignlist[j].ch){
                i2+=assignlist[j].val;
                j=uniqueChar;
            }
        }
        i++;
    }
    i=0;
    k = strlen(s3);
    while(i<k){
        i3*=10;
        for (int j=0;j<uniqueChar;j++){
            if (s3[i] ==assignlist[j].ch){
                i3+=assignlist[j].val;
                j=uniqueChar;
            }
        }
        i++;
    }
    return(i3==i1+i2);
}
void permutate(int uniqueChar,int n,struct assiged assignlist[], char* s1, char* s2, char* s3){
    if (uniqueChar-n == 1){
        for(int i =0;i<10;i++){
            if(!used[i]){
                assignlist[n].val=i;
                if(check(uniqueChar, assignlist, s1, s2, s3)){
                    sol = true;
                    nums+=1;
                    printf("solution %d \n",nums);
                    for (int j = 0; j <= n; j++) {
                        printf(" %c = %d\t", assignlist[j].ch, assignlist[j].val);
                    }
                    printf("\n");
                    return;
                }
            }
        }
        return;
    }
    for(int i =0;i<10;i++){
        if(!used[i]){
            assignlist[n].val=i;
            used[i]=true;
            permutate(uniqueChar, n+1, assignlist, s1, s2, s3);
            used[i]= false;
        }
    }
    return;
}

void findcsp(char* s1, char* s2, char* s3){
    int len1= strlen(s1);
    int len2= strlen(s2);
    int len3= strlen(s3);

    int freq[26] = {0};

    for (int i = 0; i < len1; i++) {
        freq[s1[i] - (int) ('a')]+=1;
    }
    for (int i = 0; i < len2; i++) {
        freq[s2[i] - (int) ('a')]+=1;
    }
    for (int i = 0; i < len3; i++) {
        freq[s3[i] - (int) ('a')]+=1;
    }
    int uniqueChar = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            uniqueChar++;
        }
    }
    struct assiged assignlist[uniqueChar];
    int i=0, j=0;
    while (i<26){
        if(freq[i] > 0){
            assignlist[j].ch= (char) (i + 'a');
            j++;
        }
        i++;
    }
    for (i=0; i<10; i++){
        used[i] = false;
    }
    permutate(uniqueChar, 0, assignlist, s1, s2, s3);
    if(!sol){
        printf("no sollutions");
    }
}
int main(){
    char s1[] = "crack";
    char s2[] = "hack";
    char s3[] = "error";
    findcsp(s1, s2, s3);
    return 0;
}
