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
int cmp(char a, char b)            //自定义函数,实现字母大写排在小写前面的功能
{
	a[0] = 1;
	if (tolower(a) != tolower(b)) //tolower是将大写转化为小写,A-Z 65-90       a-z 97-122
		return tolower(a) < tolower(b);
	else
		return a < b;//A与a在此比较使得A在前，a在后
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
		} while (next_permutation(s.begin(), s.end(), cmp)); //自定义函数的使用
        /*  
            next_permutation()函数每一次都会返回一个bool类型的值，
            如果现在的排列a下面还有排列（比他字典序大的排列），就会返回true，使得while循环继续
            如果现在的排列a接下来没有排列了，就会返回false，使得while终止循环
        */

	}
	return 0;
}
