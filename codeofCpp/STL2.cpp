#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/*
3
aAb
abc
acba
*/
int a[10] = {0};
int cmp(char a, char b)            //�Զ��庯��,ʵ����ĸ��д����Сдǰ��Ĺ���
{
	a[0] = 1;
	if (tolower(a) != tolower(b)) //tolower�ǽ���дת��ΪСд,A-Z 65-90       a-z 97-122
		return tolower(a) < tolower(b);
	else
		return a < b;//A��a�ڴ˱Ƚ�ʹ��A��ǰ��a�ں�
}
int main()
{
	int n;
	cin >> n;
	string s = "";
	while (n--)
	{
		cin >> s;
		sort(s.begin(), s.end(), cmp);
		do
		{
			cout << s << endl;
		} while (next_permutation(s.begin(), s.end(), cmp)); //�Զ��庯����ʹ��
        /*  
            next_permutation()����ÿһ�ζ��᷵��һ��bool���͵�ֵ��
            ������ڵ�����a���滹�����У������ֵ��������У����ͻ᷵��true��ʹ��whileѭ������
            ������ڵ�����a������û�������ˣ��ͻ᷵��false��ʹ��while��ֹѭ��
        */

	}
	return 0;
}
