#include<stdio.h >
#include<windows.h >
#include<string.h >
#include<stdbool.h>
bool IfMatch(char *s,int i, char *p, int j);
bool isMatch(char *s, char *p);//调用bool IfMatch
#define size 100
int main(){
	int status ;//判断最后输出true还是false
	char strings[size] = { 0 }, stringp[size] = { 0 }; 
	printf("请输入字符串s:"); 
	gets(strings); 
	printf("请输入字符串p:"); 
	gets(stringp);  
	status = isMatch(strings, stringp);    
	if (status == 1) 
		printf("True\n");
	else if 
		(status == 0) 
		printf("False\n");
	system("pause");
}
//使用从后往前递归的方法
//如果p[j]出现'*',比较p[j-1]和s[i],s[i-1],s[i-2]。
//如果全部匹配，返回true;如果出错，比较p[j-2]和不匹配的s[i]
//如果p[j]不是'*',比较p[j]和s[i]即可
bool IfMatch(char *s, int i, char *p, int j) {  //i是字符串s的位置，j是字符串p的位置
	if (j == -1) {  //结果处理
		if (i==-1) 
			return true;
		 else 
			return false;
	}
	if (p[j] == '*') {
		if (i>-1&&(s[i] == p[j - 1] || p[j - 1] == '.')) {
			if (IfMatch(s, i - 1, p, j)) return true;			
		}
		return IfMatch(s, i, p, j - 2);
	}
	if (i>-1&&(p[j]=='.'||s[i]==p[j]))  
		return IfMatch(s, i-1, p, j - 1);
	 else  
		return false;
}
bool isMatch(char *s, char *p)
{
  return  IfMatch(s, strlen(s) - 1, p, strlen(p) - 1);
}