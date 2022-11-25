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
}; // 这是一种类型，所以不能用等号 enum colors = {……};
enum num
{
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};
// 枚举常用来使得switch中符号变量具有名字意义

int main()
{
    // 将数组所有元素初始化为0的三种等效方法：
    int num1[100] = {};
    int num2[100]{};
    int num3[100] = {0};
    // int nu3[100] = {1};//这样则会使数组首元素为1，其余均为0

    char str[100];
    char str2[100];

    // cin >> str;//遇空白停止读入,但输入空行不影响(即一个换行符)
    // //(cin >> str).get();//这句话可以解决换行符留存问题
    // cout << str << endl;
    // cin.getline(str,100);//用户无法输入，因为getline此时读取了缓冲区的'\n'并替换成'\0'
    // cout << str;//此时str只剩下一个'\0'

    // cin.get(str,3);//第二个参数指允许读入字符数
    // cout << str;

    // cin.get(str,100).get();//cin对象调用成员函数后会返回一个cin对象，这样可以实现一直拼接，而.get()表示吸收下一个字符
    // cout << str << endl;
    // cin.clear();//防止出现空行(即只输入一个换行符\回车键)而导致后续不能在读取东西
    // cin.getline(str,100).getline(str2,100);//直接读取两行字符串
    // cout << str << endl << str2 << endl;

    string s1, s2;
    s1 = "abcdef";
    s2 = "ghijkl";
    string s3 = s1 + s2; // 首尾拼接,作用于第三方
    s1 += s2;            // 首尾拼接,并且作用于左对象
    cout << "s3=" << s3 << endl;
    cout << "After s1+=s2 , s1=" << s1 << endl; // abcdefghijkl
    cout << "s1.size()=" << s1.size() << endl;  // 12

    // getline(cin, s3);//string类型字串的用户输入,以cin为对象
    // cout << s3 << endl;

    cout << R"(scn^&a*sn/\w\n\n\n\n\rt\et\t""S"sf'SF"S"F)" << endl; // raw字符串,  使用 R"( 任何字符 )""
    cout << R"( "() )" << endl;                                     // 含 "( 也可以输出
    cout << R"+*( )" )+*" << endl;                                  // 而含 )" 则必须使用自定义定界符,这里左定界符是 "+*( ,  即用 "+*( 和 )+*"  替代了 "( 和 )"
    cout << R"-( )" )-" << endl;                                    // 这里左定界符为 "-(

    person p1{}; // c++的结构体允许省略前面的struct 和 等号= ,即无需 struct person p1 = {};
    // 空列表初始化使每个成员变量都被设置为0，当然字符串每个元素设为'\0'(抑或者说每个字节都设为0,而ascii码为0的字符就是'\0')
    cout << p1.name;     // 什么都没有
    cout << p1.nickname; // 同样什么都没有

    // 共用体(联合体):每次只能同时使用一个成员变量，比如商品的ID有时候用数字序列(整数)，有时候用含字母和数字的序列(字符串)表示
    // 相比较结构体，联合体可以节省空间，因为每个联合体变量长度都只是其最大成员的长度，而非两者之和
    //  goods[0].ID_int = 123;
    //  goods[1].ID_str = "XD123";

    colors c1;
    c1 = blue;         // 枚举变量只能识别自定义枚举类型中的符号常量
    cout << c1 << " "; // 4
    // c1 = 4;不被允许
    c1 = colors(4);     // 但可以强制转换为枚举类型
    cout << c1 << endl; // 4

    int *pnum = new int; // 自动为pnum指针分配一个适合int的内存空间，并返回地址赋给pnum，这样初始化可以避免野指针
    *pnum = 123;         // 此时再解引用赋具体值，不会发生修改未知地址上的值的错误
    cout << *pnum << endl;
    delete pnum;

    int *arr = new int[10];
    arr[0] = 1;
    arr[1] = 2;
    arr++;
    cout << *arr << endl;//2
    arr--;//若对指针地址进行修改，之后要还原初始地址状态再delete释放，否则会存在未释放空间
    delete [] arr;//数组释放占用写法


    //cctype库函数便利处理字符串各字符情况,更多函数见书P148
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
