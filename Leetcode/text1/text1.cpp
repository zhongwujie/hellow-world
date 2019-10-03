#include<stdio.h >
#include<windows.h >
#include<string.h >
int ifmatch(char *s,int i, char *p, int j);
#define size 100
#define true 1
#define false 0
int main(){
	int status ;//判断最后输出True还是False
	char strings[size] = { 0 }, stringp[size] = { 0 }; 
	printf("请输入字符串s:"); 
	gets_s(strings); 
	printf("请输入字符串p:"); 
	gets_s(stringp); 
	status = ifmatch(strings,strlen(strings)-1, stringp, strlen(stringp)-1);
	if (status == 1) printf("True\n");
	else if (status == 0) printf("False\n");
	system("pause");
}
int ifmatch(char *s, int i, char *p, int j){
	if (j == -1) {
		if(i==-1) return true;
		else return false;
	}
	if (p[j] == '*') {
		if (i>-1&&(s[i] == p[j - 1] || p[j - 1] == '.')) {
			if (ifmatch(s, i - 1, p, j))//从后往前递归，找出s中与p[j-1]的不一样的那个
				return true;
		}
		return ifmatch(s, i, p, j - 2);//让这个与p[j-2]进行比较，一样的话继续执行前面的，不一样的话一直返回false
	}
	if(i>-1&&(p[j]=='.'||s[i]==p[j]))  return ifmatch(s, i-1, p, j - 1);//这个匹配好了就去看前一个(i=-1时j不等于-1,故是false)
	else  return false;
}