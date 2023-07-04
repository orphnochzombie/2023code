#include<iostream>
#include<vector>
#include<string>
using namespace std;
//
//    
//vector< vector<string> > res;  //实际上是三维数组了，存放了不同的棋盘结果
//vector<string> cb;
//bool col[15] = {false};
//bool dg[15] = {false};
//bool udg[15] = {false};
//int t;
//
//void dfs(int m,int n){ //m是行 i是列
//    if(m == n){
//        res.push_back(cb);
//        return;
//    }
//
//    for(int i = 0;i < n;i++){
//    	if(!col[i] && !dg[i + m] && !udg[i - m + n]){ //m是行 i是列
//            res[m][i] = 'Q';
//            col[i] = dg[i + m] = udg[i - m + n] = true;
//            dfs(m + 1,n);
//            res[m][i] = '.';
//            col[i] = dg[i + m] = udg[i - m + n] = false;
//        }
//    }
//}
//
//vector<vector<string> > solveNQueens(int n) {
//    cb.resize(n,string(n,'.'));
//    dfs(0,n);
//    return res;
//}

int main(){
	
	vector<vector<string> > queen;
	queen.resize(4,string(4,string(4,'.')));

	for(vector<vector<string> > ::iterator it = queen.begin();it != queen.end();it++){
		vector<string> tmp = *it;
		for(vector<string>::iterator ite = tmp.begin();ite != tmp.end();ite++){
			cout << *ite << endl;
		}
	}
	return 0;
}
