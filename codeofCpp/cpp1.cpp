#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;

struct person
{
    int age;
    int money;
    string name;
    char nickname[100];
};

// union _goods{
//     int ID_int;
//     string ID_str;
// }goods[100];

enum colors
{
    red,
    orange,
    yellow,
    green,
    blue,
    black
}; // ����һ�����ͣ����Բ����õȺ� enum colors = {����};
enum num
{
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};
// ö�ٳ�����ʹ��switch�з��ű���������������

int main()
{
    // ����������Ԫ�س�ʼ��Ϊ0�����ֵ�Ч������
    int num1[100] = {};
    int num2[100]{};
    int num3[100] = {0};
    // int nu3[100] = {1};//�������ʹ������Ԫ��Ϊ1�������Ϊ0

    char str[100];
    char str2[100];

    // cin >> str;//���հ�ֹͣ����,��������в�Ӱ��(��һ�����з�)
    // //(cin >> str).get();//��仰���Խ�����з���������
    // cout << str << endl;
    // cin.getline(str,100);//�û��޷����룬��Ϊgetline��ʱ��ȡ�˻�������'\n'���滻��'\0'
    // cout << str;//��ʱstrֻʣ��һ��'\0'

    // cin.get(str,3);//�ڶ�������ָ��������ַ���
    // cout << str;

    // cin.get(str,100).get();//cin������ó�Ա������᷵��һ��cin������������ʵ��һֱƴ�ӣ���.get()��ʾ������һ���ַ�
    // cout << str << endl;
    // cin.clear();//��ֹ���ֿ���(��ֻ����һ�����з�\�س���)�����º��������ڶ�ȡ����
    // cin.getline(str,100).getline(str2,100);//ֱ�Ӷ�ȡ�����ַ���
    // cout << str << endl << str2 << endl;

    string s1, s2;
    s1 = "abcdef";
    s2 = "ghijkl";
    string s3 = s1 + s2; // ��βƴ��,�����ڵ�����
    s1 += s2;            // ��βƴ��,���������������
    cout << "s3=" << s3 << endl;
    cout << "After s1+=s2 , s1=" << s1 << endl; // abcdefghijkl
    cout << "s1.size()=" << s1.size() << endl;  // 12

    // getline(cin, s3);//string�����ִ����û�����,��cinΪ����
    // cout << s3 << endl;

    cout << R"(scn^&a*sn/\w\n\n\n\n\rt\et\t""S"sf'SF"S"F)" << endl; // raw�ַ���,  ʹ�� R"( �κ��ַ� )""
    cout << R"( "() )" << endl;                                     // �� "( Ҳ�������
    cout << R"+*( )" )+*" << endl;                                  // ���� )" �����ʹ���Զ��嶨���,�����󶨽���� "+*( ,  ���� "+*( �� )+*"  ����� "( �� )"
    cout << R"-( )" )-" << endl;                                    // �����󶨽��Ϊ "-(

    person p1{}; // c++�Ľṹ������ʡ��ǰ���struct �� �Ⱥ�= ,������ struct person p1 = {};
    // ���б��ʼ��ʹÿ����Ա������������Ϊ0����Ȼ�ַ���ÿ��Ԫ����Ϊ'\0'(�ֻ���˵ÿ���ֽڶ���Ϊ0,��ascii��Ϊ0���ַ�����'\0')
    cout << p1.name;     // ʲô��û��
    cout << p1.nickname; // ͬ��ʲô��û��

    // ������(������):ÿ��ֻ��ͬʱʹ��һ����Ա������������Ʒ��ID��ʱ������������(����)����ʱ���ú���ĸ�����ֵ�����(�ַ���)��ʾ
    // ��ȽϽṹ�壬��������Խ�ʡ�ռ䣬��Ϊÿ��������������ȶ�ֻ��������Ա�ĳ��ȣ���������֮��
    //  goods[0].ID_int = 123;
    //  goods[1].ID_str = "XD123";

    colors c1;
    c1 = blue;         // ö�ٱ���ֻ��ʶ���Զ���ö�������еķ��ų���
    cout << c1 << " "; // 4
    // c1 = 4;��������
    c1 = colors(4);     // ������ǿ��ת��Ϊö������
    cout << c1 << endl; // 4

    int *pnum = new int; // �Զ�Ϊpnumָ�����һ���ʺ�int���ڴ�ռ䣬�����ص�ַ����pnum��������ʼ�����Ա���Ұָ��
    *pnum = 123;         // ��ʱ�ٽ����ø�����ֵ�����ᷢ���޸�δ֪��ַ�ϵ�ֵ�Ĵ���
    cout << *pnum << endl;
    delete pnum;

    int *arr = new int[10];
    arr[0] = 1;
    arr[1] = 2;
    arr++;
    cout << *arr << endl;//2
    arr--;//����ָ���ַ�����޸ģ�֮��Ҫ��ԭ��ʼ��ַ״̬��delete�ͷţ���������δ�ͷſռ�
    delete [] arr;//�����ͷ�ռ��д��


    //cctype�⺯�����������ַ������ַ����,���ຯ������P148
    char ch;
    while((ch=cin.get()) != '#')
    {
        if(isalpha(ch)) cout << "alpha " << ch << endl;
        if(isdigit(ch)) cout << "digit " << ch << endl;
        if(ispunct(ch)) cout << "punct " << ch << endl;   
    }


    string stem = "12 123";
    cout << "stoi = " << stoi("123 12" + 3) << endl;//

    return 0;
}











































// #include<iostream>
// using namespace std;
// void print2darr(int (*arr)[5], int r , int c){
// 	for(int i=0;i<r;i++){
// 		for(int j=0;j<c;j++){
// 			cout << *(*(arr+i)+j) << " ";
// 			//printf("%d ", *(*(arr+i)+j));
// 		}
// 		cout << endl;
// 	}
// }
// int main(){
// 	int arr[3][5] = { {1 ,2 ,3 ,4 ,5} , {2 ,3 ,4 ,5 ,6} , {3 ,4 ,5 ,6 ,7}};
// 	print2darr(arr,3,5);
// 	cout << "Hello world!" << endl;
// 	return 0;
// }

// #include <stdio.h>
// #include <windows.h>
// int main()
// {
//     printf("Hello World\n");
//     system("pause");
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main(){
//     cout << "Welcome to C++!";
//     return 0;
// }

// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<cstdlib>
// #include<cmath>
// #include<algorithm>
// using namespace std;
// int main(){
//     char ch = 'M';
//     cout << ch;
//     cout << 'M';
//     cout.put(ch);
//     return 0;
// }

// int n;
// char base[2][5] = {
//     " /\\",
//     "/__\\"
// };
// char buf[1500][2500];
// void DFS(int sz, int y, int x)
// {
//     if(sz == 2)
//     {
//         for(int i = y, ii = 0; ii < 2; i ++, ii ++)
//             for(int j = x, jj = 0; jj < 4; j ++, jj ++)
//                 buf[i][j] = base[ii][jj];
//         return;
//     }
//     DFS(sz >> 1, y, x + (sz >> 1));
//     DFS(sz >> 1, y + (sz >> 1), x);
//     DFS(sz >> 1, y + (sz >> 1), x + sz);
// }
// int main()
// {
//     while(scanf("%d", &n) != EOF && n)
//     {
//         memset(buf, 0, sizeof(buf));
//         int sz = (int)(pow(2, n) + 1e-8);
//         DFS(sz, 0, 0);
//         for(int i = 0; i < sz; i ++)
//         {
//             int j = sz << 1;
//             for(; !buf[i][j]; j --);
//             for(int k = 0; k <= j; k ++)
//                 printf("%c", buf[i][k] ? buf[i][k] : ' ');
//             printf("\n");
//         }
//         printf("\n");
//     }
//     return 0;
// }
