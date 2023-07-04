## AC2.01背包

[2. 01背包问题 - AcWing题库](https://www.acwing.com/problem/content/2/)

### 同类题型：

[423. 采药 - AcWing题库](https://www.acwing.com/problem/content/description/425/)

[1024. 装箱问题 - AcWing题库](https://www.acwing.com/problem/content/1026/)



### 法一：dp矩阵

```c++
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int main(){
    int v[N];  //重量
    int w[N];  //权重 即价值
    int dp[N][N] = {0};  //dp矩阵 元素初始化为0
    int n,m; //n是物品个数 m是背包容量
    cin >> n >> m;
    
    
    for(int i = 1;i <= n;i ++){
        cin >> v[i] >> w[i];
    }
    
    for(int i = 1;i <= n;i++){  //外层遍历物品
        for(int j = 0;j <= m;j++){  //内层遍历背包重量
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i]){
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
//时间复杂度O(n*m)
```





### 法二：优化为一维

```c++
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int main(){
    int v[N];  //重量数组
    int w[N];  //权重数组 即价值
    int dp[N] = {0};  //dp矩阵
    int n,m; //n是物品个数 m是背包容量
    cin >> n >> m;
    
    
    for(int i = 1;i <= n;i ++){
        cin >> v[i] >> w[i];
    }
    
    for(int i = 1;i <= n;i++){  //外层遍历物品
        for(int j = m;j >= v[i];j--){  //从后往前更新******

            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}

```



### 法三：更他妈优化了



```c++
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int main(){
    int v; //重量
    int w;  //权重 即价值
    int dp[N] = {0};  //dp矩阵
    int n,m; //n是物品个数 m是背包容量
    cin >> n >> m;
    
    while(n--){  
        cin >> v >> w; //不用数组存储，优化了空间复杂度
        for(int j = m;j >= v;j--){  //遍历背包重量

            dp[j] = max(dp[j],dp[j - v] + w);

        }
    }
    cout << dp[m] << endl;
    return 0;
}
```



### 补：

[(56条消息) 【编程语言】C++中未初始化的数组的默认值问题_c++初始化float数组,默认值_机灵鹤的博客-CSDN博客](https://blog.csdn.net/wenxuhonghe/article/details/102853161)

#### 记住三点：

整形数组：

1. 全局数组，未初始化时，默认值都是 0；
2. 局部数组，未初始化时，默认值为随机的不确定的值；
3. 局部数组，初始化一部分时，未初始化的部分默认值为 0；

```c++
char 型数组
全局数组，未初始化的部分，默认值为 ‘ ’ ；
局部数组，初始化一部分后，未初始化部分默认值为 ‘ ’ ；
局部数组，未初始化时，默认值不可预知。
    
double ，float 型数组
全局数组，未初始化时，默认值都是 0.0；
局部数组，未初始化时，默认值为随机的不确定的值；
局部数组，初始化一部分时，未初始化的部分默认值为 0.0；
    
bool 型数组
全局数组，未初始化时，默认值都是 0；
局部数组，未初始化时，默认值为 204；
局部数组，初始化一部分时，未初始化的部分默认值为 0；

```

