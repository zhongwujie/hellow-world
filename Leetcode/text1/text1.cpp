#include<stdio.h >
#include<windows.h >
#include<string.h >
int ifmatch(char *s,int i, char *p, int j);
#define size 100
#define true 1
#define false 0
int main(){
	int status ;//�ж�������True����False
	char strings[size] = { 0 }, stringp[size] = { 0 }; 
	printf("�������ַ���s:"); 
	gets_s(strings); 
	printf("�������ַ���p:"); 
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
			if (ifmatch(s, i - 1, p, j))//�Ӻ���ǰ�ݹ飬�ҳ�s����p[j-1]�Ĳ�һ�����Ǹ�
				return true;
		}
		return ifmatch(s, i, p, j - 2);//�������p[j-2]���бȽϣ�һ���Ļ�����ִ��ǰ��ģ���һ���Ļ�һֱ����false
	}
	if(i>-1&&(p[j]=='.'||s[i]==p[j]))  return ifmatch(s, i-1, p, j - 1);//���ƥ����˾�ȥ��ǰһ��(i=-1ʱj������-1,����false)
	else  return false;
}