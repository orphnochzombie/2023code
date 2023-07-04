## AcWing 835. Trie字符串统计

[835. Trie字符串统计 - AcWing题库](https://www.acwing.com/problem/content/837/)

```c++
#include<iostream>
using namespace std;

const int N = 100010;
int son[N][26] = {0}; //Trie
int count[N] = {0};  //标记结尾
int idx = 0; //数组模拟的idx,当前用的下标


void insert(char* str){
    int p = 0;
    for(int i = 0;str[i] ;i++){
        int u = str[i] - 'a';
        if(!son[p][u]){
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    count[p]++;
}

int query(char* str){
    int p = 0;
    for(int i = 0;str[i] ;i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return count[p];
}

int main(){
    int n;
    scanf("%d",&n);

    while(n --){
        char str[N];
        char op[2];
        scanf("%s%s",&op,str);
        if(op[0] == 'I') insert(str);
        else printf("%d\n",query(str));
    }
    return 0;

}
```

