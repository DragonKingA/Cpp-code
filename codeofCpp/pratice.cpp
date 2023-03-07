/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓算法↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/

/*一.STL*/
/*
容器的选择:
1. 如果你需要高效的随即存取，而不在乎插入和删除的效率，使用vector
2. 如果你需要大量的插入和删除，而不关心随即存取，则应使用list
3. 如果你需要随即存取，而且关心两端数据的插入和删除，则应使用deque。
*/


//set
//单词数
//以下无法处理全是空格的行
// #include <iostream>
// #include <set>
// #include <string>
// using namespace std;
// int main()
// {
//     set<string> se;
//     string s;
//     char ch;
//     int ifnot=0;
//     while((cin >> s) && s[0] != '#')
//     {
//         se.insert(s);
//         if((ch = cin.get()) == '\n') ifnot=1;
//         if(ifnot)
//         {
//             cout << se.size() << endl;
//             se.clear();
//             ifnot=0;
//         }
//     }
//     return 0;
// }
//AC
// #include <iostream>
// #include <set>
// #include <string>
// using namespace std;
// int main()
// {
//     string s;
//     set<string> se;
//     while(getline(cin, s))
//     {
//         if(s[0] == '#') break;
//         string st = "";
//         for(int i=0 ;; i++)
//         {
//             if(s[i] == ' ')
//             {
//                 if(st.size() == 0) continue;//处理连续空格和前导空格
//                 se.insert(st);
//                 st = "";
//             }
//             else if(s[i]=='\0')
//             {
//                 if(st.size() != 0) se.insert(st);
//                 break;
//             }
//             else
//                 st += s[i];
//         }
//         cout << se.size() << endl;
//         se.clear();
//     }
//     return 0;
// }



//stack
//1.简单操作栈,后进先出
// #include <iostream>
// #include <stack>
// using namespace std;
// int main()
// {
//     stack<int> st;
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int n,x;
//         cin >> n;
//         if(n-1)
//         {
//             if(st.empty()) cout << "empty\n";
//             else
//             {
//                 cout << st.top() << endl;
//                 st.pop();
//             }
//         }
//         else
//         {
//             cin >> x;
//             st.push(x);
//         }
//     }
//     return 0;
// }

//2.愚人节的礼物
//满足后进先出，用栈来操作
// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;
// int main()
// {
//     while(!cin.eof())
//     {
//         stack<char> sta;
//         string s;
//         getline(cin, s);
//         for(int i = 0 ; s[i] != '\0' ; i++)
//         {
//             if(s[i] == '(') sta.push(s[i]);
//             else if(s[i] == ')') sta.pop();
//             else 
//             {
//                 cout << sta.size() << endl;
//                 break;
//             }
//         }
//     }
//     return 0;
// }

//3.Train Problem I
/*stack满树
                    { 1 }
            { }             {1，2}
        {2}               {1}       {1，2，3}
    {2，3} { }          { }  {1,3}       {1，2}
  {2}        {3}      {3}         {1}          {1}
{ }            { }     { }         { }           { }
*/
//TLE
// #include <iostream>
// #include <string>
// #include <stack>
// #include <vector>
// using namespace std;
// struct node{
//     int index;//记录这个栈读到str的哪个字符, 0 ~ (n-1)
//     string ans;
//     vector<bool> InOut;
//     stack<char> sta;
// };
// int main()
// {
//     while(!cin.eof())
//     {
//         int n, yn=1;
//         string str, res;
//         cin >> n >> str >> res;
//         node t{0, "", {1}}; //构建vec初始化第一个元素
//         t.sta.push(str[0]);
//         vector<node> vec[2*n]{{t}};//存储栈状态，第一个栈直接在容器初始化中存储
//         /*
//             t.index=0;
//             t.ans="";
//             t.InOut.push_back(1);
//             vec[0].push_back(t);
//         */
//         for(int i = 0 ; i < 2*n ; i++)//全遍历
//         {
//             for(auto j : vec[i])
//             {
//                 node temp1 = j, temp2 = j;
//                 if(j.index < n-1)
//                 {
//                     //进栈，并更新栈状态
//                     temp1.sta.push(str[j.index + 1]);
//                     temp1.InOut.push_back(1);
//                     temp1.index++;
//                     vec[i+1].push_back(temp1);
//                 }
//                 if(!j.sta.empty())
//                 {
//                     //出栈，并更新栈状态
//                     temp2.ans += temp2.sta.top();
//                     temp2.InOut.push_back(0);
//                     temp2.sta.pop();
//                     vec[i+1].push_back(temp2);
//                 }
//                 //最后检索是否有答案出现
//                 if(i==2*n-1)
//                 {
//                     if(j.ans==res)
//                     {
//                         cout << "Yes.\n";
//                         yn = 0;
//                         for(auto m : j.InOut)
//                             if(m) cout << "in\n";
//                             else cout << "out\n";
//                     }
//                 }
//             }
//         }
//         if(yn) cout << "No.\n";
//         cout << "FINISH\n";
//         // for(auto k : vec[2*n - 1])
//         //     if(k.ans == res)
//         //     {
//         //         cout << "Yes.\n";
//         //         yn = 0;
//         //         for(auto m : k.InOut)
//         //             if(m) cout << "in\n";
//         //             else cout << "out\n";
//         //         break;
//         //     }
//         // if(yn) cout << "No.\n";
//         // cout << "FINISH\n";
//     }
//     return 0;
// }
//TLE
// #include <iostream>
// #include <string>
// #include <stack>
// #include <vector>
// #include <vis>
// using namespace std;
// struct node{
//     int index;
//     string ans;
//     vector<bool> InOut;
//     stack<char> sta;
// };
// multivis<string, node> mmp;
// int main()
// {
//     while(!cin.eof())
//     {
//         int n, yn=1;
//         string str, res;
//         cin >> n >> str >> res;
//         auto it = mmp.find(str);
//         if(it == mmp.end())
//         {
//             node t{0, "", {1}};
//             t.sta.push(str[0]);
//             vector<node> vec[2*n]{{t}};
//             for(int i = 0 ; i < 2*n ; i++)
//             {
//                 for(auto j : vec[i])
//                 {
//                     node temp1 = j, temp2 = j;
//                     if(j.index < n-1)
//                     {
//                         temp1.sta.push(str[j.index + 1]);
//                         temp1.InOut.push_back(1);
//                         temp1.index++;
//                         vec[i+1].push_back(temp1);
//                     }
//                     if(!j.sta.empty())
//                     {
//                         temp2.ans += temp2.sta.top();
//                         temp2.InOut.push_back(0);
//                         temp2.sta.pop();
//                         vec[i+1].push_back(temp2);
//                     }
//                     if(i==2*n-1) mmp.insert(pair<string, node>(str, j));
//                 }
//             }
//         }
//         it = mmp.find(str);
//         while(it != mmp.end())
//         {
//             if(it->second.ans == res){
//                 yn = 0;
//                 cout << "Yes.\n";
//                 for(auto k : it->second.InOut)
//                 if(k) cout << "in\n";
//                 else cout << "out\n";
//             }
//             it++;
//         }
//         if(yn) cout << "No.\n";
//         cout << "FINISH\n";
//     }
//     return 0;
// }
//AC
// #include <cstdio>
// #include <string>
// #include <stack>
// #include <vector>
// using namespace std;
// string a, b;
// int main()
// {
//     int n;
//     while (scanf("%d%s%s", &n, &a[1], &b[1]) != EOF)
//     {
//         vector<int> ve;
//         stack<char> stk;
//         int j = 1, fl = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             stk.push(a[i]);
//             ve.push_back(1);
//             while (!stk.empty() && stk.top() == b[j])//此处重点
//             {
//                 stk.pop();
//                 j++;
//                 ve.push_back(0);
//             }
//         }
//         while (j <= n)
//         {
//             if (stk.top() == b[j])
//             {
//                 if (stk.empty())
//                 {
//                     fl = 0;
//                     break;
//                 }
//                 stk.pop();
//                 j++;
//                 ve.push_back(0);
//             }
//             else
//             {
//                 fl = 0;
//                 break;
//             }
//         }
//         if (stk.empty() && fl)
//         {
//             printf("Yes.\n");
//             for (auto v : ve)
//                 if (v == 0) printf("out\n");
//                 else printf("in\n");
//         }
//         else
//             printf("No.\n");
//         printf("FINISH\n");
//     }
//     return 0;
// }

//4.波兰表达式(现以整数运算为例)
/*
以中缀表达式 (3 + 4) * 5 - 6 为例
波兰表达式分为：
1.前缀波兰表达式:操作符位于操作数之前，如 - * + 3 4 5 6
  使用栈原理(其实递归法符合输入顺序可以轻松解决，否则直接用栈极难处理)，从右往左，对数值先压栈，然后依次读取运算符对栈顶两个元素弹出并运算再把结果回栈
2.中缀波兰表达式（人所理解的表达式）
3.后缀(逆)波兰表达式:操作符位于操作数之后，如 3 4 + 5 * 6 -
*/
//前缀波兰表达式(最好用递归实现)
// #include <iostream>
// #include <string>
// #include <cstdio>
// using namespace std;
// double func(){
//     char str[33000];
//     cin >> str;//* + 11.0 12.0 + 24.0 35.0
//     switch(str[0]){
//         case '+':
//             return func() + func();
//         case '-':
//             return func() - func();
//         case '*':
//             return func() * func();
//         case '/':
//             return func() / func();
//         default:
//             return atof(str);
//     }
// }
// int main(){
//     printf("%f\n", func());
//     return 0;
// }
//后缀(逆)波兰表达式(最好用栈实现)
// #include <iostream>
// #include <string>
// #include <stack>
// #include <cctype>
// using namespace std;
// int main()
// {
//     string s;
//     while(!getline(cin, s).eof())//3 4 + 5 * 6 -
//     {
//         stack<int> sta;
//         for(int i = 0; i < s.size() ; i++)
//         {
//             string temp = "";
//             for( ; isdigit(s[i]) ; temp += s[i++]);//遇到数字就截取出来
//             if(!temp.empty())   sta.push(stoi(temp));
//             char x = s[i];//此时一般为空格
//             if(ispunct(x))
//             {
//                 int n1 = sta.top(); sta.pop();
//                 int n2 = sta.top(); sta.pop();
//                 switch(x)
//                 {
//                     case '+': sta.push(n2 + n1); break;
//                     case '-': sta.push(n2 - n1); break;
//                     case '*': sta.push(n2 * n1); break;
//                     case '/': sta.push(n2 / n1); break;//默认n1 != 0
//                 }
//             }
//         }
//         cout << s << " at the result of " << sta.top() << endl;
//     }
//     return 0;
// }
/*
转为中缀表达式(可能需要第二个栈来存表达式)以输出可能有用：
    string exp = "";//结果表达式
    exp += "(" + to_string(n2) + x + to_string(n1) + ")";
    exp += "(" + to_string(n2) + x + to_string(n1) + ")";
    exp += to_string(n2) + x + to_string(n1);
    exp += to_string(n2) + x + to_string(n1);
*/




                






//queue
//1.简单操作队列,先进先出
// #include <iostream>
// #include <queue>
// using namespace std;
// int main()
// {
//     queue<int> que;
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int n,x;
//         cin >> n;
//         if(n-1)
//         {
//             if(que.empty()) cout << "empty\n";
//             else
//             {
//                 cout << que.front() << endl;
//                 que.pop();
//             }
//         }
//         else
//         {
//             cin >> x;
//             que.push(x);
//         }
//     }
//     return 0;
// }

//*2.Windows Message Queue
//优先队列用运算符重载来设置优先级
//运算符重载方式多样！！！！
// #include <iostream>
// #include <string>
// #include <queue>
// #include <vector>
// using namespace std;
// struct node{
//     string name;
//     int x;
//     int pri;
//     int cnt;
// };
// struct cmp{
//     bool operator()(const node &a, const node &b)
//     {
//         return a.pri == b.pri ? (a.cnt > b.cnt) : (a.pri > b.pri);
//     }
// };
// int main()
// {
//     priority_queue<node, vector<node>, cmp> pq;
//     int count = 0;
//     while(!cin.eof())
//     {
//         string cmd, msg;
//         cin >> cmd;
//         if(cmd == "GET")
//         {
//             if(pq.empty()) cout << "EMPTY QUEUE!\n";
//             else
//             {
//                 cout << pq.top().name << " " << pq.top().x << endl;
//                 pq.pop();
//             }
//         }
//         else
//         {
//             int t1,t2;
//             cin >> msg >> t1 >> t2;
//             node temp = {msg, t1, t2, count++};
//             pq.push(temp);
//         }
//     }
//     return 0;
// }



//3.Stones
// #include <iostream>
// #include <queue>
// #include <string>
// using namespace std;
// struct stone{
//     int x, dx;//找位置前,dx小的出列
//     //结构体内运算符重载写法：
//     bool operator < (const stone &a) const
//     {
//         return x == a.x ? (dx > a.dx) : (x > a.x); 
//     }
// }temp;
// int main()
// {
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int ifthrow=1,t1,t2,n,sz;
//         priority_queue<stone> pq;
//         cin >> n;
//         while(n--)
//         {
//             cin >> t1 >> t2;
//             temp = {t1, t2};
//             pq.push(temp);
//         }
//         while(sz = pq.size())
//         {
//             if(ifthrow++ & 1)
//             {
//                 temp = {pq.top().x + pq.top().dx, pq.top().dx};
//                 pq.pop();
//                 pq.push(temp);
//                 if(sz == 1)
//                 {
//                     cout << pq.top().x << endl;
//                     break;
//                 }
//             }
//             else
//                 pq.pop();
//         }
//     }
//     return 0;
// }



//vis
// 1.Let the Balloon Rise
// #include <iostream>
// #include <string>
// #include <vis>
// using namespace std;
// int main()
// {
//     int T;
//     while((cin >> T) && T)
//     {
//         vis<string, int> mp;
//         string str;
//         int t=T;
//         while(t--)
//         {
//             cin >> str;
//             mp[str] += 1;                        
//         }
//         int max = mp[str];
//         for(auto &x : mp) 
//         {
//             if(x.second > max)
//             {
//                 max = x.second;
//                 str = x.first;
//             }
//         }
//         cout << str << endl;
//     }
//     return 0;
// }



//2.水果(嵌套vis)
//问：vis对string的排序是以首字母排列还是整体ASCII码值
// #include <iostream>
// #include <string>
// #include <vis>
// using namespace std;
// int main()
// {
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         vis<string, vis<string, int> > mp;
//         int t;
//         cin >> t;
//         while(t--)
//         {
//             string fru, place;
//             int n;
//             cin >> fru >> place >> n;
//             mp[place][fru] += n;
//         }
//         for(auto x1 : mp)
//         {
//             cout << x1.first << endl;
//             for(auto x2 : x1.second)
//             {
//                 cout << "   |----" << x2.first << "(" << x2.second << ")\n";
//             }
//         }
//         if(T!=0) cout << endl;
//     }
//     return 0;
// }



//list
/*
1.与vector的不同
头节点的前驱元素指针域保存的是链表中尾元素的首地址，list的尾节点的后继元素指针域则保存了头节点的首地址，这样，list实际上就构成了一个双向循环链。
由于list元素节点并不要求在一段连续的内存中，显然在list中是不支持快速随机存取的，
因此对于迭代器，只能通过“++”或“--”操作将迭代器移动到后继/前驱节点元素处。而不能对迭代器进行+n或-n的操作，这点，是与vector等不同的地方。
2.特点
list就是数据结构中的双向链表(根据sgi stl源代码)，因此它的内存空间是不连续的，通过指针来进行数据的访问，
这个特点使得它的随即存取变的非常没有效率，因此它没有提供[]操作符的重载。但由于链表的特点，它可以以很好的效率支持任意地方的删除和插入。
*/






















/*二.搜索技术*/

//全排列问题（排列基础元素小于等于10个时运行耗时在1秒内）
//1.STL法
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int data[] = {4, 2, 3, 1};
//     sort(data, data+4, less());
//     do{
//         for(int i=0;i<4;i++) cout << data[i];
//         cout << endl;
//     }while(next_permutation(data, data+4));

//     return 0;
// }

//2.递归法
// #include <iostream>
// using namespace std;
// #define Swap(a, b) {int temp = a; a = b; b = temp;}
// //宏函数Swap比STL中swap函数运行效率更快(对于普通静态数组来说)
// int cnt = 0;
// int datas[10] = {1,2,3,4,5,6,7,8,9,10};
// int Perm(int begin, int end)
// {
    
//     if(begin == end) cnt++;
//     else
//     {
//         for(int i=begin;i<=end;i++)
//         {
//             Swap(datas[begin], datas[i]);//把固定数(begin位置上的数)与其他所有数都交换一次位置
//             Perm(begin+1, end);//切换固定数继续
//             Swap(datas[begin], datas[i]);//恢复，用于下一次交换
//         }
//     }    
// }
// int main()
// {
//     Perm(0, 9);//表示从索引0到9共10个元素全排列，可以改成其他区间
//     cout << "cnt = " << cnt << endl;// 10! = 3628800
//     return 0;
// }





//子集的生成问题
/*
用二进制数理解:如求集合{a1, a2, a3}的子集，我们知道元素个数为 n 的集合其子集个数为 2^n （包括空集）
不难发现 n -> 2^n 的关系与 二进制位 -> 二进制数大小 相仿,故用3位二进制表示该集合，每位上为1则取该元素，为0则不取该元素
如 a1 a2 a3 -> 1 1 1 ,  而  a2 a3 -> 0 1 1 ;  a1 -> 1 0 0 。则有从 0 0 0(空集) 到 1 1 1(原集合) 共8种情况
*/
// #include <iostream>
// using namespace std;
// void print_subset(int n, const string *s, int k)
// {
//     for(int i = 0 ; i < (1<<n) ; i++)//2^n种情况
//     {
//         //统计1的个数,使函数只输出含 k 个元素的子集
//         int cnt = 0, kk = i;
//         while(kk)
//         {
//             kk = kk & (kk-1);//该句能做到使二进制数kk的最后一个1变成0,即每使用一次 1 的个数就减少一个
//             cnt++;
//         }
//         if(cnt == k)
//         {
//             for(int j = 0 , ifpunct = 0 ; j < n ; j++)//以i用二进制数理解，检索i的二进制数的每一位，该二进制位上的1对应取数组s[j]上的元素
//                 if(i & (1<<j))
//                     cout << "," + !(ifpunct++) << s[j];
//             cout << endl;
//         }
//     }
// }
// int main()
// {
//     string str[] = {"a1", "a2", "a3", "a4"};
//     int len = sizeof(str)/sizeof(str[0]);
//     print_subset(len, str, 2);//打印所有元素个数为k个的子集
//     //该方法打印出各子集的次序可能与题目要求次序相异
//     return 0;
// }


//简单搜索

//BFS（广度优先搜索）
//一般是队列实现，故 BFS = 队列, 该算法尽量使用队列解决而不是递归（故函数中一般有while(条件为队列不为空)循环）
//可以解决最优问题（最长/最短路径）

// 1.红与黑(BFS实现)
/*Code
// #include <iostream>
// #include <queue>
// using namespace std;
// struct node{
//     int x, y;
// }origin;
// char room[22][22];
// int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// int wid, hei, cnt = 1;
// void BFS(node origin)
// {
//     queue<node> que;
//     que.push(origin);
//     while(!que.empty())//尽量非递归
//     {
//         node next, start = que.front();
//         //cout << "Test: now at " << start.x << " " << start.y << endl;
//         que.pop();
//         for(int i=0;i<4;i++)
//         {
//             next = {start.x + dir[i][0], start.y + dir[i][1]};
//             if(next.x >= 0 && next.x < wid && next.y >= 0 && next.y < hei && room[next.y][next.x] == '.')
//             {
//                 room[next.y][next.x] = '#';
//                 que.push(next);
//                 cnt++;
//             }
//         }
//     }
// }
// int main()
// {
//     while((cin >> wid >> hei) && wid && hei)
//     {
//         for(int i=0;i<hei;i++)
//         {
//             for(int j=0;j<wid;j++)
//             {
//                 cin >> room[i][j];
//                 if(room[i][j] == '@')   origin = {j, i};
//             }
//         }
//         cnt = 1;
//         BFS(origin);
//         cout << cnt << endl;
//     }
//     return 0;
// }
*/

//2.马走日(最短路径问题)
/*Code
// 首先d[N][N]初始化为 - 1，然后d[x][y]入队，进行bfs循环，行走固定位置；
// 然后用d[N][N]来储存能到走“车”的最短步数
// 最后输出最小步数；
// https://blog.csdn.net/qq_64162685/article/details/124002779?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166930838716800184173076%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166930838716800184173076&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-124002779-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_controx1&utm_term=c%2B%2B%E9%A9%AC%E8%B5%B0%E6%97%A5BFS&spm=1018.2226.3001.4187
// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int, int>PII;//定义队列
// queue<PII>q;
// const int N = 1010;
// int n, m, l;
// int d[N][N];
// int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
// int dy[8] = { 1,-1,2,-2,2,-2,1,-1 }; //8个位置
// void bfs()
// {
//     while (q.size())
//     {
//         PII t = q.front();
//         q.pop();
//         int x = t.first, y = t.second;
//         for (int i = 0; i < 8; i++)
//         {
//             int tx = x + dx[i];
//             int ty = y + dy[i];
//             if (d[tx][ty] != -1 || tx <= 0 || ty <= 0 || tx > n || ty > m) continue;
//             else
//             {
//                 d[tx][ty] = d[x][y] + 1;//步数加1
//                 q.push({ tx,ty });
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n >> m >> l;
//     int a, b;
//     cin >> a >> b;
//     memset(d, -1, sizeof(d));//初始化为-1
//     d[a][b] = 0;
//     q.push({ a,b });
//     bfs();
//     while (l--)
//     {
//         int x, y;
//         cin >> x >> y;
//         cout << d[x][y] << endl;
//     }
// }
*/

//3.Find the multiple
//以下前两组代码只能用G++交,递归频繁调用时最好用G++交
/*队列法
// #include <iostream>
// #include <queue>
// using namespace std;
// void BFS(long long int num)
// {
//     queue<long long int> q;
//     q.push(1);
//     while(!q.empty())
//     {
//         long long int m=q.front();
//         q.pop();
//         if(m%num==0)
//         {
//             cout<<m<<endl;
//             return;
//         }
//         q.push(m*10);
//         q.push(m*10+1);
//     }
// }
// int main()
// {   
//     long long int n;
//     while(cin>>n, n) BFS(n);
//     return 0;
// }
*/
/*打表法：可输入前获取全部情况结果存在数组里，比上述代码耗时短，而空间利用也不会太多
// #include <iostream>
// #include <queue>
// using namespace std;
// long long res[202], n, i=1;
// void BFS(long long num)
// {
//     queue<long long> q;
//     q.push(1);
//     while(!q.empty())
//     {
//         long long m=q.front();
//         q.pop();
//         if(m%num==0)
//         {
//             res[num]=m;
//             return;
//         }
//         q.push(m*10);
//         q.push(m*10+1);
//     }
// }
// int main()
// {   
//     while(i<=200) BFS(i++);
//     while(cin>>n, n) cout<<res[n]<<endl;
//     return 0;
// }
*/
/**设置最大递归终止点：由上述打的表得知要得到结果最多位数为19位，即19次递归，故可以到了第20次就终止递归线程
//该代码C++和G++都不会超时，且最快
// #include <iostream>
// using namespace std;
// bool fl;
// int n;
// void BFS(long long m, int x){
//     if(x>19 || fl);//fl为真就终止该递归线程
//     else if(m%n==0){
//         cout<<m<<endl;
//         fl=1;
//         return;
//     }else{
//         BFS(m*10,x+1);
//         BFS(m*10+1,x+1);
//     }
// }
// int main(){   
//     while(cin>>n, n) {
//         fl=0;
//         BFS(1,1);
//     }
//     return 0;
// }
*/

//4.Catch That Cow
/*AC
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> p;
// bool ocu[100005];
// int x1,x2,f,s,nx;
// void BFS()
// {
//     queue<p> q;
//     q.push(p(x1,0));
// 	ocu[x1]=1;
//     while(q.size())
//     {
//         f=q.front().first;
//         s=q.front().second;
//         q.pop();
//         if(f==x2)
//         {
//             cout<<s;
//             return;
//         }
// 		for(int i=1;i<=3;i++)
// 		{
// 			switch(i)
// 			{
// 				case 1:nx=2*f;break;
// 				case 2:nx=f-1;break;
// 				case 3:nx=f+1;break;
// 			}
// 			if(nx>=0&&nx<=100000&&!ocu[nx])//注意条件顺序，谨防越界访问
// 			{
// 				ocu[nx]=1;
// 				q.push(p(nx,s+1));
// 			}
// 		}
//     }
// }
// int main()
// { 
//     cin>>x1>>x2;
//     BFS();
//     return 0;
// }
*/

//*5.Prime Path(队列的重要用法)
/*AC
// #include <iostream>
// #include <cstring>
// #include <cmath>
// #include <queue>
// using namespace std;
// int T,a,b,ne,res,sz,t;
// queue<int> q;
// bool prime[10000];
// bool vis[10000];
// #define Operate(x) {if(!vis[x] && prime[x]) {q.push(x); vis[x] = 1;}}
// bool BFS()
// {
// 	q.push(a);
// 	vis[a]=1;
// 	res=-1;
// 	while(sz = q.size())
// 	{
// 		res++;
// 		while(sz--)//*本程序重点：每次循环掉所有原先队列中的元素, 即保证当前层的元素都是上一步变化产生的
// 		{
// 			t = q.front();
// 			q.pop();
// 			if(t == b) return 1;
// 			for(int i=0;i<=9;i++)
// 			{
// 				if(i!=0)
// 				{
// 					ne = i*1000 + t%1000;
// 					Operate(ne);
// 				}
// 				ne = i*100 + t%100 + t/1000*1000;
// 				Operate(ne);
// 				ne = i*10 + t%10 + t/100*100;
// 				Operate(ne);
// 				ne = i + t/10*10;
// 				Operate(ne);
// 			}
// 		}
// 	}
// 	return 0;//队列跑完了都没有就是找不到
// }
// int main()
// {
// 	for(int n=1000;n<=9999;n++)//素数表打印，避免多次递归中重复运算
// 	{
// 		prime[n]=1;
// 		for(int i=2;i<=sqrt(n);i++)//CE 就 换成n/2
// 			if(n%i==0) {prime[n]=0; break;}
// 	}
// 	cin>>T;
// 	while(T--)
// 	{
// 		memset(vis, 0, sizeof(vis));
// 		while(q.size()) q.pop();
// 		cin>>a>>b;
// 		if(BFS()) cout<<res<<endl;
// 		else cout<<"Impossible"<<endl;
// 	}
// 	return 0;
// }
*/

//*6.迷宫问题（关于对搜索树一条分支信息的存储，便于输出一条分支的过程）
/*路径存储方法(重点)分析
ans[5][5]数组每个点对应迷宫上的点，并且值为该点的“前一个点”，类似于链表的链接形态
即对于某迷宫：
0, 1, 0, 0, 0,		[0,0] (1,0) (2,0) (3,0) (4,0)

0, 1, 0, 1, 0,		[0,1] (1,1) (2,1) (3,1) (4,1)

0, 0, 0, 0, 0,  --> [0,2] [1,2] [2,2] [3,2] [4,2]	点[x,y]均为最短路径上的点

0, 1, 1, 1, 0,		(0,3) (1,3) (2,3) (3,3) [4,3]

0, 0, 0, 1, 0,		(0,4) (1,4) (2,4) (3,4) [4,4]
ans[5][5]呈现最短路径示意图(ans[y][x]):
	0	   1	  2	     3	   4

0	*
	|
1 (0,0)
	|
2 (0,1)——(0,2)——(1,2)——(2,2)——(3,2)
								|
3							  (4,2)
								|
4							  (4,3)
如对于ans[1][0] = (0,0) , 因为路径上点(0,1)的上一个点是(0,0)
  对于ans[4][4] = (4,3) , 因为路径上终点(4,4)的上一个点是(4,3)
这样就能建立起一条路径点与点之间的关系，方便将路径上的所有点打印出来
*/
/*AC
// #include <cstdio>
// #include <queue>
// using namespace std;
// int maze[5][5], dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
// struct node{
// 	int x,y;
// 	bool operator == (const node &n) const{//判等号的重载，使结构体之间能直接用==号判等
// 		return x==n.x && y==n.y;
// 	}
// }ans[5][5],BEGIN{0,0},END{4,4},te,ne;
// #define CHECK(x,y) (x>=0&&x<5&&y>=0&&y<5&&!maze[y][x])
// void Pri(node pt)//因为是以最后一个点(4,4)开始定位最短路径，所有要用递归逆序打印
// {
// 	if(pt==BEGIN) printf("(0, 0)\n");
// 	else
// 	{
// 		Pri(ans[pt.y][pt.x]);
// 		printf("(%d, %d)\n", pt.y, pt.x);
// 	}
// }
// void BFS()
// {
// 	queue<node>q;
// 	q.push(BEGIN);
// 	while(q.size())
// 	{
// 		if((te=q.front())==END) return;
// 		q.pop();
// 		for(int i=0,nx,ny;i<4;i++)
// 		{
// 			ne={nx=te.x+dir[i][0], ny=te.y+dir[i][1]};
// 			if(CHECK(nx, ny))
// 			{
// 				maze[ny][nx]=1;
// 				ans[ny][nx]=te;//在该点位置存 上一个点的坐标信息
// 				q.push(ne);
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	for(int i=0;i<5;i++)
// 		for(int j=0;j<5;j++)
// 			scanf("%d",&maze[i][j]);
// 	BFS();
// 	Pri(END);
// 	return 0;
// }
*/

//7.Find a way(过程较为复杂，容易在各个环节出错！)
/*案例分析:
..............................
..............................
..............................
..............................
..............................

4 7
Y....#@
M....##
......@
@......
55

4 7
Y....##
M....##
......@
@......
55

3 30
Y.............................
M...........................#@
..........@..................#
253

3 30
Y.............................
M...........................#@
@............................#
33

3 30
Y...........................#@
M............................#
...........................#.@
671

180 30
Y...........................#.
M..........................#@#
...........................#..
............................##
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
............................#.
...........................#@#
...........................#..
............................##
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
............................#.
...........................#@#
...........................#..
............................##
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
............................#.
...........................#@#
...........................#..
............................##
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
............................#.
...........................#@#
...........................#..
............................##
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
............................#.
...........................#@#
...........................#..
............................##
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
..............................
@............................@
3927
*/
/*WAs
//DFS不能实现
// void DFS(int x, int y, int time)
// {	
// 	if(fl) return;
// 	if(store.find(p(x,y))!=store.end())
// 	{
// 		fl=1;
// 		store[p(x,y)]+=time;
// 		return;
// 	}
// 	vis[y][x]=1;
// 	for(int i=0,nx,ny;i<4;i++)
// 	{
// 		nx=x+dir[i][0];
// 		ny=y+dir[i][1];
// 		if(CHECK(nx,ny)) DFS(nx,ny,time+11);
// 	}
// }
//WA
// #include <cstring>
// #include <iostream>
// #include <queue>
// #include <vis>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int fl=0,n,m,dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
// char road[205][205];
// bool vis[205][205];
// p pY,pM;
// vis<p, int> store;
// #define CHECK(x,y) (x>=0&&x<m&&y>=0&&y<n&&road[y][x]!='#'&&!vis[y][x])
// void BFS(int x, int y)
// {	
// 	queue<pp> q;
// 	q.push(pp(p(x,y),0));
// 	while(q.size())
// 	{
// 		pp temp=q.front();
// 		q.pop();
// 		int dx=temp.first.first, dy=temp.first.second;
// 		if(store.find(temp.first) != store.end())
// 			store[temp.first] += temp.second;
// 		for(int i=0,nx,ny;i<4;i++)
// 		{
// 			nx = dx + dir[i][0];
// 			ny = dy + dir[i][1];
// 			if(CHECK(nx,ny))
// 			{
// 				vis[ny][nx]=1;
// 				q.push(pp(p(nx,ny),temp.second+11));
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	while(!(cin>>n>>m).eof())
// 	{
// 		for(int i=0;i<n;i++)
// 			for(int j=0;j<m;j++)
// 			{
// 				cin>>road[i][j];
// 				switch(road[i][j])
// 				{
// 					case 'Y': pY={j,i};break;
// 					case 'M': pM={j,i};break;
// 					case '@': store[p(j,i)]=0;break;
// 				}
// 			}
// 		memset(vis, 0, sizeof(vis));
// 		BFS(pY.first,pY.second);
// 		memset(vis, 0, sizeof(vis));
// 		BFS(pM.first,pM.second);
// 		int min = store.begin()->second;
// 		for(auto x : store)
// 		{
// 			if(x.second!=0)
// 				min = min < x.second ? min:x.second;
// 		}
// 		cout<<min<<endl;
// 		store.clear();
// 	}
// 	return 0;
// }
//WA
// #include <cstring>
// #include <string>
// #include <iostream>
// #include <queue>
// #include <vis>
// #include <vector>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int fl=0,n,m,dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
// char road[205][205];
// bool vis[205][205];
// p pY,pM;
// #define STR(x,y) (to_string(x)+to_string(y))
// vis<string,int> store;
// #define CHECK(x,y) (x>=0&&x<m&&y>=0&&y<n&&road[y][x]!='#'&&!vis[y][x])
// void BFS(int x, int y)
// {	
// 	queue<pp> q;
// 	q.push(pp(p(x,y),0));
// 	while(q.size())
// 	{
// 		pp temp=q.front();
// 		q.pop();
// 		int dx=temp.first.first, dy=temp.first.second;
// 		if(store.find(STR(dx,dy)) != store.end())
// 			store[STR(dx,dy)] += temp.second;
// 		for(int i=0,nx,ny;i<4;i++)
// 		{
// 			nx = dx + dir[i][0];
// 			ny = dy + dir[i][1];
// 			if(CHECK(nx,ny))
// 			{
// 				vis[ny][nx]=1;
// 				q.push(pp(p(nx,ny),temp.second+11));
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	while(!(cin>>n>>m).eof())
// 	{
// 		for(int i=0;i<n;i++)
// 			for(int j=0;j<m;j++)
// 			{
// 				cin>>road[i][j];
// 				switch(road[i][j])
// 				{
// 					case 'Y': pY={j,i};break;
// 					case 'M': pM={j,i};break;
// 					case '@': store[STR(j,i)]=0;break;
// 				}
// 			}
// 		memset(vis, 0, sizeof(vis));
// 		BFS(pY.first,pY.second);
// 		memset(vis, 0, sizeof(vis));
// 		BFS(pM.first,pM.second);
// 		int min = store.begin()->second;
// 		for(auto x : store) 
// 		{
// 			if(x.second!=0)
// 				min=min<x.second?min:x.second;
// 		}
// 		cout<<min<<endl;
// 		store.clear();
// 	}
// 	return 0;
// }
*/
/*ACs
//AC(78ms)
// #include <cstdio>
// #include <cstring>
// #include <queue>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int RES=0,n,m,store[200][200],dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
// char road[205][205];
// bool vis[205][205];
// #define CHECK(x,y) (x>=0&&x<m&&y>=0&&y<n&&road[y][x]!='#'&&!vis[y][x])
// void BFS(int x, int y)
// {	
// 	queue<pp> q;
// 	q.push(pp(p(x,y),0));
// 	while(q.size())
// 	{
// 		pp temp=q.front();
// 		q.pop();
// 		int dx=temp.first.first, dy=temp.first.second;
// 		if(store[dy][dx]!=-1) 
// 		{
// 			store[dy][dx]+=temp.second;
// 			RES=store[dy][dx];
// 		}
// 		for(int i=0,nx,ny;i<4;i++)
// 		{
// 			nx = dx + dir[i][0];
// 			ny = dy + dir[i][1];
// 			if(CHECK(nx,ny))
// 			{
// 				vis[ny][nx]=1;
// 				q.push(pp(p(nx,ny),temp.second+11));
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	p pY,pM;
// 	while(~scanf("%d%d",&n,&m))
// 	{
// 		memset(store, -1, sizeof(store));
// 		for(int i=0;i<n;i++)
// 		{
// 			getchar();
// 			for(int j=0;j<m;j++)
// 			{
// 				scanf("%c",&road[i][j]);
// 				switch(road[i][j])
// 				{
// 					case 'Y': pY={j,i};break;
// 					case 'M': pM={j,i};break;
// 					case '@': store[i][j]=0;break;
// 				}
// 			}
// 		}
// 		memset(vis, 0, sizeof(vis));
// 		BFS(pY.first,pY.second);
// 		memset(vis, 0, sizeof(vis));
// 		BFS(pM.first,pM.second);
// 		for(int i=0;i<200;i++)
// 			for(auto x : store[i]) 
// 				if(x!=-1&&x!=0)
// 					RES = RES < x ? RES:x;
// 		printf("%d\n",RES);
// 	}
// 	return 0;
// }
//AC:本题用iostream也可，不会超时(109ms)
// #include <iostream>
// #include <cstring>
// #include <queue>
// #define N 205
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int RES=0,n,m,dx,dy,store[N][N],dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
// char road[N][N];
// bool vis[N][N];
// void BFS(int x, int y)
// {	
// 	queue<pp> q;
// 	q.push(pp(p(x,y),0));
// 	memset(vis, 0, sizeof(vis));
// 	while(q.size())
// 	{
// 		pp temp=q.front(); q.pop();
// 		dx=temp.first.first;
// 		dy=temp.first.second;
// 		if(store[dy][dx]!=-1) 
// 		{
// 			store[dy][dx]+=temp.second;
// 			RES=store[dy][dx];
// 		}
// 		for(int i=0,nx,ny;i<4;i++)
// 		{
// 			nx=dx+dir[i][0];
// 			ny=dy+dir[i][1];
// 			if(nx>=0&&nx<m&&ny>=0&&ny<n&&road[ny][nx]!='#'&&!vis[ny][nx])
// 			{
// 				vis[ny][nx]=1;
// 				q.push(pp(p(nx,ny),temp.second+11));
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	p pY,pM;
// 	while(cin>>n>>m)
// 	{
// 		memset(store, -1, sizeof(store));
// 		for(int i=0;i<n;i++)
// 			for(int j=0;j<m;j++)
// 			{
// 				cin>>road[i][j];
// 				switch(road[i][j])
// 				{
// 					case 'Y': pY={j,i};break;
// 					case 'M': pM={j,i};break;
// 					case '@': store[i][j]=0;break;
// 				}
// 			}
// 		BFS(pY.first,pY.second);
// 		BFS(pM.first,pM.second);
// 		for(int i=0;i<N;i++)
// 			for(auto x : store[i]) 
// 				if(x!=-1&&x!=0)
// 					RES = RES < x ? RES:x;
// 		cout<<RES<<endl;
// 	}
// 	return 0;
// }
*/



//***8.Pots
/*草稿
//草稿1
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int a,b,c,sz,res,temp,t1,t2,op;
// int ans[11][600][10],save;
// bool BFS(bool fl)
// {
//     queue<pp> q;
//     memset(ans,0,sizeof ans);
//     if(fl)
//     {
//         q.push(pp(p(a,0),1));
//         ans[0][0][1]=-1;
//     }
//     else
//     {
//         q.push(pp(p(0,b),2));
//         ans[0][0][2]=-1;
//     }
//     res=0;
//     while(sz=q.size())
//     {
//         res++;
//         int ind=0;
//         while(sz--)
//         {
//             pp te=q.front(); 
//             q.pop();
//             op=te.second;
//             if(((t1=te.first.first)==c)||((t2=te.first.second)==c))
//             {
//                 save=ans[res][ind-1][op];
//                 return 1;
//             }
//             if(res>9) return (res=0);
//             //operate1() operate2()
//             if(op!=1&&t1!=a) 
//             {
//                 q.push(pp(p(a,t2),1));
//                 ans[res][ind][1]=op;
//             }
//             if(op!=2&&t2!=b) 
//             {
//                 q.push(pp(p(t1,b),2));
//                 ans[res][ind][2]=op;
//             }
//             if(op!=3&&t1>0)
//             {
//                 q.push(pp(p(0,t2),3));
//                 ans[res][ind][3]=op;
//             }
//             if(op!=4&&t2>0) 
//             {
//                 q.push(pp(p(t1,0),4));
//                 ans[res][ind][4]=op;
//             }
//             if(op!=5&&t2!=b) 
//             {
//                 if(t1>0)
//                 {
//                     if(t1<b-t2) 
//                     {
//                         q.push(pp(p(0,t2+t1),5));
//                     }
//                     else 
//                     {
//                         q.push(pp(p(t1+t2-b,b),5));
//                     }
//                     ans[res][ind][5]=op;
//                 }
//             }
//             if(op!=6&&t1!=a) 
//             {
//                 if(t2>0)
//                 {
//                     if(t2<a-t1) 
//                     {
//                         q.push(pp(p(t1+t2,0),6));
//                     }
//                     else 
//                     {
//                         q.push(pp(p(a,t1+t2-a),6));
//                     }
//                     ans[res][ind][6]=op;
//                 }
//             }
//             ind++;
//             //cout<<"res="<<res<<endl;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     cin>>a>>b>>c;
//     //if(BFS(1)) temp=res;
//     if(BFS(0)) res=min(res,temp);
//     if(res) cout<<res<<endl;
//     else cout<<"impossible";
//     return 0;
// }
//草稿2
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,p> pp;
// int a,b,c,sz,res,temp,t1,t2,op,ind;
// p ans[105][105];
// bool BFS(bool fl)
// {
//     queue<pp> q;
//     if(fl)
//     {
//         q.push(pp(p(a,0),p(1,0)));
//     }
//     else
//     {
//         q.push(pp(p(0,b),p(2,0)));
//     }
//     res=0;
//     while(sz=q.size())
//     {
//         res++;
//         //int ind=0;
//         while(sz--)
//         {
//             pp te=q.front(); 
//             q.pop();
//             op=te.second.first;
//             ind=te.second.second;
//             if(((t1=te.first.first)==c)||((t2=te.first.second)==c))
//             {
//                 return 1;
//             }
//             if(res>9) return (res=0);
//             if(op!=1&&t1!=a) 
//             {
//                 q.push(pp(p(a,t2),p(1,ind+1)));
//             }
//             if(op!=2&&t2!=b) 
//             {
//                 q.push(pp(p(t1,b),p(2,ind+1)));
//             }
//             if(op!=3&&t1>0)
//             {
//                 q.push(pp(p(0,t2),p(3,ind+1)));
//             }
//             if(op!=4&&t2>0) 
//             {
//                 q.push(pp(p(t1,0),p(4,ind+1)));
//             }
//             if(op!=5&&t2!=b) 
//             {
//                 if(t1>0)
//                 {
//                     if(t1<b-t2) 
//                     {
//                         q.push(pp(p(0,t2+t1),p(5,ind+1)));
//                     }
//                     else 
//                     {
//                         q.push(pp(p(t1+t2-b,b),p(5,ind+1)));
//                     }
//                 }
//             }
//             if(op!=6&&t1!=a) 
//             {
//                 if(t2>0)
//                 {
//                     if(t2<a-t1) 
//                     {
//                         q.push(pp(p(t1+t2,0),p(6,ind+1)));
//                     }
//                     else 
//                     {
//                         q.push(pp(p(a,t1+t2-a),p(6,ind+1)));
//                     }
//                 }
//             }
//             //ind++;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     cin>>a>>b>>c;
//     //if(BFS(1)) temp=res;
//     if(BFS(0)) res=min(res,temp);
//     if(res) cout<<res<<endl;
//     else cout<<"impossible";
//     return 0;
// }
//草稿3
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int a,b,c,res1=0,res2=0,t1,t2,op,vis[105][105];
// pp t,ans[105][105],END1,END2,BEGIN1{p(a,0),1},BEGIN2{p(0,b),2};
// #define PriOP(t) {switch(t){\
//         case 1:case 2:printf("FILL(%d)\n",t);break;\
//         case 3:case 4:printf("DROP(%d)\n",t-2);break;\
//         case 5:printf("POUR(1,2)\n");break;\
//         case 6:printf("POUR(2,1)\n");break;}}
// void Pri(int w1,int w2,int cnt)
// {
//     if(ans[w1][w2]==(t=BEGIN1)||ans[w1][w2]==(t=BEGIN2))
//     {
//         cout<<cnt<<endl;
//         PriOP(t.second);
//         return;
//     }
//     Pri(ans[w1][w2].first.first,ans[w1][w2].first.second,cnt+1);
//     PriOP(ans[w1][w2].second);
// }
// bool BFS(bool fl)
// {
//     queue<pp> q;
//     memset(vis,0,sizeof vis);
//     if(fl)
//     {
//         q.push(pp(p(a,0),1));
//         vis[a][0]=1;
//         ans[a][0]=BEGIN1;
//     }
//     else
//     {
//         q.push(pp(p(0,b),2));
//         vis[0][b]=1;
//         ans[0][b]=BEGIN2;
//     }
//     while(q.size())
//     {
//         if(fl) res1++;
//         else res2++;
//         pp te=q.front(); 
//         q.pop();
//         p pf=te.first;
//         op=te.second;
//         if(((t1=te.first.first)==c)||((t2=te.first.second)==c))
//         {
//             if(fl) END1=te;
//             else END2=te;
//             return 1;
//         }
//         if(op!=1&&!vis[a][t2]&&t1!=a) 
//         {
//             q.push(pp(p(a,t2),1));
//             vis[a][t2]=1;
//             ans[a][t2]=pp(pf,1);
//         }
//         if(op!=2&&!vis[t1][b]&&t2!=b) 
//         {
//             q.push(pp(p(t1,b),2));
//             vis[t1][b]=1;
//             ans[t1][b]=pp(pf,2);
//         }
//         if(op!=3&&!vis[0][t2]&&t1>0)
//         {
//             q.push(pp(p(0,t2),3));
//             vis[0][t2]=1;
//             ans[0][t2]=pp(pf,3);
//         }
//         if(op!=4&&!vis[t1][0]&&t2>0) 
//         {
//             q.push(pp(p(t1,0),4));
//             vis[t1][0]=1;
//             ans[t1][0]=pp(pf,4);
//         }
//         if(op!=5&&t2!=b) 
//         {
//             if(t1>0)
//             {
//                 if(t1<b-t2&&!vis[0][t2+t1]) 
//                 {
//                     q.push(pp(p(0,t2+t1),5));
//                     vis[0][t2+t1]=1;
//                     ans[0][t2+t1]=pp(pf,5);
//                 }
//                 else if(t1>=b-t2&&!vis[t1+t2-b][b])
//                 {
//                     q.push(pp(p(t1+t2-b,b),5));
//                     vis[t1+t2-b][b]=1;
//                     ans[t1+t2-b][b]=pp(pf,5);
//                 }
//             }
//         }
//         if(op!=6&&t1!=a) 
//         {
//             if(t2>0)
//             {
//                 if(t2<a-t1&&!vis[t1+t2][0]) 
//                 {
//                     q.push(pp(p(t1+t2,0),6));
//                     vis[t1+t2][0]=1;
//                     ans[t1+t2][0]=pp(pf,6);
//                 }
//                 else if(t2>=a-t1&&!vis[a][t1+t2-a])
//                 {
//                     q.push(pp(p(a,t1+t2-a),6));
//                     vis[a][t1+t2-a]=1;
//                     ans[a][t1+t2-a]=pp(pf,6);
//                 }
//             }
//         }
//     }
//     return 0;
// }
// int main()
// {
//     cin>>a>>b>>c;
//     if(BFS(0)||BFS(1))
//     {
//         if(res1==0) Pri(END2.first.first,END2.first.second,1);
//         else Pri(END1.first.first,END1.first.second,1);
//     }
//     else cout<<"impossible";
//     return 0;
// }
*/
/*案例分析：
3 5 4
w1=0,w2=5;
w1=3,w2=2;
w1=0,w2=2;
w1=2,w2=0;
w1=2,w2=5;
w1=3,w2=4;(w2满足条件)
任意一个w==c即可

7  5
w1=7,w2=1

规定
w1->a->1,w2->b->2
0=NULL
FILL(1)=1
FILL(2)=2
DROP(1)=3
DROP(2)=4
POUR(1,2)=5
POUR(2,1)=6
{{w1,w2}, op}
*/
/*CE
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> p;
// typedef pair<p,int> pp;
// int a,b,c,t1,t2,op,vis[105][105];
// pp t,ans1[105][105],ans2[105][105],END1,END2,BEGIN1=pp(p(a,0),1),BEGIN2=pp(p(0,b),2);
// #define PriOP(t) {switch(t){\
// case 1:case 2:printf("FILL(%d)\n",t);break;\
// case 3:case 4:printf("DROP(%d)\n",t-2);break;\
// case 5:printf("POUR(1,2)\n");break;\
// case 6:printf("POUR(2,1)\n");break;}\
// }
// #define Oper(w1,w2,opt,pp1,fl) {q.push(pp(p(w1,w2),opt));vis[w1][w2]=1;if(fl){ans1[w1][w2]=pp1;}else{ans2[w1][w2]=pp1;}}
// #define CHECK(w1,w2,opt) (op!=opt&&!vis[w1][w2])
// #define RECORD(w1,w2,opt,pp1,fl) {if(CHECK(w1,w2,opt)){Oper(w1,w2,opt,pp1,fl);}}
// void Pri(int w1,int w2,int cnt,pp BEGIN,int fl)
// {
//     pp m;
//     if(fl)
//     {
//         if((m=ans1[w1][w2])==(t=BEGIN))
//         {
//             cout<<cnt<<endl;
//             PriOP(t.second);
//             return;
//         }
//     }
//     else
//     {
//         if((m=ans2[w1][w2])==(t=BEGIN))
//         {
//             cout<<cnt<<endl;
//             PriOP(t.second);
//             return;
//         }
//     }
//     Pri(m.first.first,m.first.second,cnt+1,t,fl);
//     PriOP(m.second);
// }
// bool BFS(bool fl)
// {
//     queue<pp> q;
//     memset(vis,0,sizeof vis);
//     if(fl) {Oper(a,0,1,BEGIN1,fl);}
//     else {Oper(0,b,2,BEGIN2,fl);}
//     while(q.size())
//     {
//         pp te=q.front(); 
//         p pf=te.first;
//         op=te.second;
//         q.pop();
//         if(((t1=te.first.first)==c)||((t2=te.first.second)==c))
//         {
//             if(fl) END1=te;
//             else END2=te;
//             return 1;
//         }
//         if(t1!=a) RECORD(a,t2,1,pp(pf,1),fl);
//         if(t2!=b) RECORD(t1,b,2,pp(pf,2),fl);
//         if(t1>0) RECORD(0,t2,3,pp(pf,3),fl);
//         if(t2>0) RECORD(t1,0,4,pp(pf,4),fl);
//         if(op!=5&&t2!=b&&t1>0) 
//         {
//             if(t1<b-t2&&!vis[0][t2+t1]) {Oper(0,t2+t1,5,pp(pf,5),fl);}
//             else if(t1>=b-t2&&!vis[t1+t2-b][b]) {Oper(t1+t2-b,b,5,pp(pf,5),fl);}
//         }
//         if(op!=6&&t1!=a&&t2>0) 
//         {
//             if(t2<a-t1&&!vis[t1+t2][0]) {Oper(t1+t2,0,6,pp(pf,6),fl);}
//             else if(t2>=a-t1&&!vis[a][t1+t2-a]) {Oper(a,t1+t2-a,6,pp(pf,6),fl);}
//         }
//     }
//     return 0;
// }
// int main()
// {
//     cin>>a>>b>>c;
//     BFS(1);
//     BFS(0);
//     Pri(END1.first.first,END1.first.second,1,BEGIN1,1);
//     Pri(END2.first.first,END2.first.second,1,BEGIN2,0);
        
//     // else cout<<"impossible";
//     return 0;
// }
*/
/*CE
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// int a,b,c,t1,t2,op,ct,vis[105][105];
// struct nd{
//     int w1,w2,op,cnt;
//     bool operator == (const nd &n){
//         return (w1==n.w1&&w2==n.w2&&op==n.op&&cnt==n.cnt);
//     }
// }t,ans1[105][105],ans2[105][105],END1,END2,BEGIN1,BEGIN2;
// string str[]={"","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
// #define CHECK(last,next,opt) (last.op!=opt&&!vis[next.w1][next.w2])
// void Pri(int w1,int w2,nd BEGIN,bool fl)
// {
//     nd m;
//     if(fl)
//     {
//         if((m=ans1[w1][w2])==(t=BEGIN))
//         {
//             cout<<END1.cnt<<endl;
//             cout<<str[t.op]<<endl;
//             return;
//         }
//     }
//     else
//     {
//         if((m=ans2[w1][w2])==(t=BEGIN))
//         {
//             cout<<END2.cnt<<endl;
//             cout<<str[t.op]<<endl;
//             return;
//         }
//     }
//     Pri(m.w1,m.w2,t,fl);
//     cout<<str[m.op]<<endl;
// }
// queue<nd> q;    
// bool BFS(bool fl)
// {
//     while(q.size()) q.pop();
//     memset(vis,0,sizeof vis);
//     auto Oper = [](nd last,nd next,bool fl)
//     {
//         int w1=next.w1, w2=next.w2;
//         q.push(next);
//         vis[w1][w2]=1;
//         last.op=next.op;
//         if(fl) ans1[w1][w2]=last;
//         else ans2[w1][w2]=last;
//     };
//     auto RECORD = [](nd last,nd next,bool fl,int opt,auto Oper)
//     {
//         if(CHECK(last,next,opt)) Oper(last,next,fl);
//     };
//     if(fl) {Oper(BEGIN1,BEGIN1,fl);}
//     else {Oper(BEGIN2,BEGIN2,fl);}
//     while(q.size())
//     {
//         nd te=q.front(); 
//         op=te.op;
//         ct=te.cnt;
//         q.pop();
//         if(((t1=te.w1)==c)||((t2=te.w2)==c))
//         {
//             if(fl) END1=te;
//             else END2=te;
//             return 1;
//         }
//         if(t1!=a) RECORD(te,nd{a,t2,1,ct+1},fl,1,Oper);
//         if(t2!=b) RECORD(te,nd{t1,b,2,ct+1},fl,2,Oper);
//         if(t1>0) RECORD(te,nd{0,t2,3,ct+1},fl,3,Oper);
//         if(t2>0) RECORD(te,nd{t1,0,4,ct+1},fl,4,Oper);
//         if(op!=5&&t2!=b&&t1>0) 
//         {
//             if(t1<b-t2&&!vis[0][t2+t1]) {Oper(te,nd{0,t2+t1,5,ct+1},fl);}
//             else if(t1>=b-t2&&!vis[t1+t2-b][b]) {Oper(te,nd{t1+t2-b,b,5,ct+1},fl);}
//         }
//         if(op!=6&&t1!=a&&t2>0) 
//         {
//             if(t2<a-t1&&!vis[t1+t2][0]) {Oper(te,nd{t1+t2,0,6,ct+1},fl);}
//             else if(t2>=a-t1&&!vis[a][t1+t2-a]) {Oper(te,nd{a,t1+t2-a,6,ct+1},fl);}
//         }
//     }
//     return 0;
// }
// int main()
// {
//     cin>>a>>b>>c;
//     BEGIN1={a,0,1,1};
//     BEGIN2={0,b,2,1};
//     BFS(1);
//     BFS(0);
//     if(END1.cnt!=0&&END1.cnt<END2.op)Pri(END1.w1,END1.w2,BEGIN1,1);
//     else if(END2.cnt!=0) Pri(END2.w1,END2.w2,BEGIN2,0);
//     else cout<<"impossible";
//     return 0;
// }
*/
/*妙解！！！！！！！
// #include <cstdio>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> P;
// P root[101][101];//保存路径
// int vis[101][101],op[101][101],sign[101][101],a,b,c;
// void judge(int fl, int x){
//     if(fl==0) printf("FILL(%d)\n",x);
//     else if(fl==1) printf("DROP(%d)\n",x);
//     else printf("POUR(%d,%d)\n",x/10,x%10);    
// }
// void link(P p){
//     if(p == P()) return;//p为P(0,0)时即终止输出
//     link(root[p.first][p.second]);
//     judge(op[p.first][p.second], sign[p.first][p.second]);
// }
// void BFS(){
//     queue<P> que;
//     que.push(P(0,0));//直接从两个容器都为空开始，省去分两次求的麻烦
//     vis[0][0]=1;
//     while(que.size()){
//         P s=que.front(); que.pop();
//         int x=s.first, y=s.second;
//         if(x==c || y==c){
//             printf("%d\n",vis[x][y]-1);
//             link(P(x,y));//路径
//             return;
//         }
//         int k=min(a-x,y), k1=min(b-y,x);
//         int st[6][2] = {{a,y},{x,b},{0,y},{x,0},{x+k,y-k},{x-k1,y+k1}};//6种可能的操作
//         int oper[6] ={1,2,1,2,21,12};//容器i
//         for(int i=0;i<6;i++){//0,1,2,3,4,5
//             int dx = st[i][0], dy = st[i][1];
//             if(!vis[dx][dy]){
//                 vis[dx][dy]=vis[x][y]+1;//存步数的同时相当于存了状态
//                 root[dx][dy] = P(x,y); 
//                 sign[dx][dy] = oper[i];
//                 op[dx][dy] = i/2;//将6个步骤分成3部分
//                 que.push(P(dx,dy));
//             }
//         }
//     }
//     printf("impossible");
// }
// int main(){
//     cin>>a>>b>>c;
//     BFS();
//     return 0;
// }

//关于输出结果时可以替换Judge()函数
//构建输出模板 char oplist[3][22] = {"FILL(%d)\n", "DROP(%d)\n", "POUR(%d,%d)\n"};
//输出时按最大操作数写 printf(oplist[第二维度下标], 操作数1(应用到第一个%d) , 操作数2(应用到第二个%d) );

*/
/*试图合并成一个多元结构体数组
// #include <cstdio>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> P;
// struct node{
//     P now,last;
//     int op;//6种操作
//     int type;//3类操作
//     int cnt;//步数兼状态
//     bool operator ==(const node &n)const{
//         return (now==n.now&&last==n.last&&op==n.op&&type==n.type&&cnt==n.cnt);
//     }
// }root[101][101],BEGIN{P(0,0),P(0,0),0,0,0};//保存路径
// int a,b,c;
// void judge(int fl, int x){
//     if(fl==0) printf("FILL(%d)\n",x);
//     else if(fl==1) printf("DROP(%d)\n",x);
//     else printf("POUR(%d,%d)\n",x/10,x%10);    
// }
// void link(node n){
//     if(n.now==P(0,0)&&n.last==P(0,0)&&n.op==0&&n.type==0&&n.cnt==0) return;;//p为P(0,0)时即终止输出
//     link(root[n.last.first][n.last.second]);
//     judge(root[n.now.first][n.now.second].type, root[n.now.first][n.now.second].op);
// }
// void BFS(){
//     queue<node> que;
//     que.push(BEGIN);//直接从两个容器都为空开始，省去分两次求的麻烦
//     root[0][0]=BEGIN;
//     while(que.size()){
//         node s=que.front(); que.pop();
//         int x=s.last.first, y=s.last.second;
//         if(x==c || y==c){
//             printf("%d\n",root[x][y].cnt-1);
//             link(s);//路径
//             return;
//         }
//         int k=min(a-x,y), k1=min(b-y,x);
//         int st[6][2] = {{a,y},{x,b},{0,y},{x,0},{x+k,y-k},{x-k1,y+k1}};//6种可能的操作
//         int oper[6] ={1,2,1,2,21,12};//容器i
//         for(int i=0;i<6;i++){//0,1,2,3,4,5
//             int dx=st[i][0], dy=st[i][1];
//             if(!root[dx][dy].cnt){
//                 root[dx][dy].now=P(x,y);
//                 root[dx][dy].cnt=root[x][y].cnt+1;//存步数的同时相当于存了状态
//                 root[dx][dy].last=P(dx,dy); 
//                 root[dx][dy].op = oper[i];
//                 root[dx][dy].type = i/2;//将6个步骤分成3部分
//                 que.push(root[dx][dy]);
//             }
//         }
//     }
//     printf("impossible");
// }
// int main(){
//     cin>>a>>b>>c;
//     BFS();
//     return 0;
// }
*/
/*郭教的结构体方法
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
typedef std::pair<int, int> pii;
const int maxn = 1e2 + 10;
struct Node {
    int pa, pb, op, opf, step;
};
Node vis[maxn][maxn];
int cup[2], c, snow[2], snex[2]; 
inline void InitNex() {memcpy(snex, snow, sizeof(snex));}
void FILL(int cn) {
    InitNex();
    snex[cn] = cup[cn];
}
void DROP(int cn) {
    InitNex();
    snex[cn] = 0;
}
void POUR(int cn) {
    InitNex();
    int pn = std::min(cup[cn ^ 1] - snex[cn ^ 1], snex[cn]);
    snex[cn ^ 1] += pn;
    snex[cn] -= pn;
}
void InQ(int op, int opf, std::queue<pii> &q) {
    Node &now = vis[snex[0]][snex[1]];
    if(now.op != -1) return;
    now.op = op;
    now.opf = opf;
    now.pa = snow[0];
    now.pb = snow[1];
    now.step = vis[snow[0]][snow[1]].step + 1;
    q.push(pii(snex[0], snex[1]));
}
bool BFS() {
    memset(vis, -1, sizeof(vis));
    std::queue<pii> q;
    q.push(pii(0, 0));
    vis[0][0].op = -2; // 无特殊含义，只是标记该状态已访问
    vis[0][0].step = 0;
    while(!q.empty()) {
        pii now = q.front();
        q.pop();
        snow[0] = now.first, snow[1] = now.second;
        if(snow[0] == c || snow[1] == c) return true;
        for(int i = 0; i <= 1; i ++) {
            FILL(i); InQ(0, i, q);
            DROP(i); InQ(1, i, q);
            POUR(i); InQ(2, i, q);
        }
    }
    return false;
}
char oplist[3][22] = {"FILL(%d)\n", "DROP(%d)\n", "POUR(%d,%d)\n"};
void DFSPrint(int a, int b) {
    if(a == -1) return;
    DFSPrint(vis[a][b].pa, vis[a][b].pb);
    printf(oplist[vis[a][b].op], vis[a][b].opf + 1, (vis[a][b].opf ^ 1) + 1);
}
int main() {
    while(scanf("%d%d%d", &cup[0], &cup[1], &c) != EOF) {
        if(BFS()) {
            printf("%d\n", vis[snow[0]][snow[1]].step);
            DFSPrint(snow[0], snow[1]);
        }
        else {
            printf("impossible\n");
        }
    }
    return 0;
}



*/









//DFS（深度优先搜索）
//一般是递归实现，有时候同一个问题其代码比BFS短
//可以用于解决全路径数问题

//1.红与黑(DFS实现)
// #include <iostream>
// using namespace std;
// char room[22][22];
// int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// int wid, hei, cnt = 0;
// #define check(x, y) (x<wid && x>=0 && y<hei && y>=0)
// void DFS(int dx, int dy)
// {
//         room[dy][dx] = '#';
//         cnt++;
//         for(int i=0;i<4;i++)
//         {
//             int nx = dx + dir[i][0];
//             int ny = dy + dir[i][1];
//             if(check(nx, ny) && room[ny][nx] == '.') DFS(nx, ny);
//         }
// }
// int main()
// {
//     int dx, dy;
//     while((cin >> wid >> hei) && wid && hei)
//     {
//         for(int i=0;i<hei;i++)
//             for(int j=0;j<wid;j++)
//             {
//                 cin >> room[i][j];
//                 if(room[i][j] == '@')
//                 {
//                     dx=j;
//                     dy=i;
//                 }
//             }
//         cnt = 0;
//         DFS(dx, dy);
//         cout << cnt << endl;
//     }
//     return 0;
// }

//2.马走日
/* 5 4 0 0
  0 1 2 3 4
0 X x x x x
1 x x x x x
2 x x x x x
3 x x x x x
*/
// #include <iostream>
// #include <cstring>
// using namespace std;
// int wid,hei,times=0;
// bool board[10][10];
// int dir[8][2] = {{-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}};//顺时针
// #define check(x, y) (x<wid && x>=0 && y<hei && y>=0)
// void DFS(int dx, int dy, int cnt)
// {
//     if(cnt >= wid*hei)
//     {
//         times++;
//         return;
//     }
//     for(int i=0, nx, ny ; i<8 ; i++)
//     {
//         nx = dx + dir[i][0];
//         ny = dy + dir[i][1];
//         if(check(nx, ny) && !board[ny][nx]) 
//         {
//             board[ny][nx] = 1;//更新 已走 的状态
//             DFS(nx, ny, cnt+1);//搜索至末端
//             board[ny][nx] = 0;//恢复状态(当搜索到末端时回溯一步，并且把末端状态恢复为 未走到)
//         }
//     }
// }
// int main()
// {
//     int T,dx,dy;
//     cin >> T;
//     while(T--)
//     {
//         cin >> wid >> hei >> dx >> dy;
//         memset(board, 0, sizeof(board));
//         times = 0;
//         board[dy][dx] = 1;
//         DFS(dx, dy, 1);
//         cout << times << endl;
//     }
//     return 0;
// }

//3.*棋盘问题
// #include <iostream>
// #include <cstring>
// using namespace std;
// int n,k,cnt=0;
// bool d[10];//0无，1有
// char pic[10][10];
// void DFS(int y, int num)
// {
//     if(num==k) 
//     {
//         cnt++;
//         return;
//     }
//     if(y>=n) return;
//     for(int x=0;x<n;x++)
//     {
//         if(pic[y][x]=='#' && !d[x])
//         {
//             d[x]=1;
//             // cout << "Now at " << x << " " << y << endl;
//             DFS(y+1, num+1);
//             d[x]=0;
//         }
//     }
//     DFS(y+1, num);//*重点
//     /*
//         因为存在n>k的情况，起初是以第一行为起始，开始计数放棋数，当出现像
//         3 1
//         # .
//         . #
//         # .
//         的案例时，第一行判断完就已经有num==k的情况并计数，同样第二行和第三行显然可以作为新的起始行重新判断也会出现num==k的情况，共计3次
//         而对于是否新建起始行，我们判断是否y>=n碰界，是则停止即可，此时就不会存在第四行新建，整个递归程序结束
//     */
// }
// int main()
// {
//     while(cin>>n>>k,(n+1)&&(k+1))
//     {
//         for(int i=0;i<n;i++) cin>>pic[i];
//         memset(d, 0, sizeof(d));
//         cnt=0;
//         DFS(0, 0);
//         cout << cnt << endl;
//     }
//     return 0;
// }

//4.Oil Deposits
// #include <iostream>
// using namespace std;
// int n, m, cnt;
// int dir[8][2] = {{-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}};
// char pic[105][105];
// void DFS(int x, int y)
// {
//     pic[y][x]='*';
//     for(int i=0,nx,ny;i<8;i++)
//     {
//         nx = x + dir[i][0];
//         ny = y + dir[i][1];
//         if(nx>=0&&nx<m&&ny>=0&&ny<n&&pic[ny][nx]=='@') DFS(nx, ny);
//     }
// }
// int main()
// {
//     while(!(cin>>n>>m).eof(), m&&n)
//     {
//         for(int i=0;i<n;i++) cin>>pic[i];
//         cnt=0;
//         for(int i=0;i<n;i++)
//             for(int j=0;j<m;j++)
//                 if(pic[i][j]=='@')
//                 {
//                     DFS(j, i);
//                     cnt++;
//                 }
//         cout << cnt << endl;
//     }
//     return 0;
// }


//进阶搜索
//搜索剪枝、记忆化搜索
/*dfs的剪枝手段：
可行性剪枝：当目前状态和题意不符，并且由于题目可以推出，往后的所有情况和题意都不符，那么就可以进行剪枝，
           直接把这种情况及后续的所有情况判断为不可行，直接返回。

排除等效冗余：当几个子树具有完全相同的效果的时候，只选择其中一个搜索。

搜索顺序剪枝：不同的搜索顺序会导致搜索树形态差异很大，那么时间复杂度自然差异也很大。
            比如说我们搜索一个最小值，那肯定是从最小的节点开始搜索，而非从最大的节点开始搜索。
            一般来讲，有单调性存在的搜索问题可以和贪心思想结合，进行顺序剪枝。

最优性剪枝：当搜索还没结束的时候，当前记录的状态已经比当前保存的最优解更劣，就没有必要在继续搜索下去了，
            因为该路径已经不可能成为我们的最优解了。(如限定步数等条件下的曼哈顿距离剪枝)
*/
//1.选数
// #include <cstdio>
// int n, k, ans = 0, a[30];
// bool isprime(int x)
// {
//     for(int i = 2; i * i <= x; i++)
//         if(x % i == 0) return 0;
//     return x != 1;
// }
// //遵循不降原则，升序地选数，避免重复
// void dfs(int cnt, int sum, int st)//st为最近一次选数的下标
// {
//     if(cnt == k)
//     {
//         if(isprime(sum)) ans++;
//         return ;
//     }
//     for(int i = st; i < n; i++)
//         dfs(cnt + 1, sum + a[i], i + 1);
//     return;
// }
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//     dfs(0,0,0);
//     printf("%d\n", ans);
//     return 0;
// }



//2.非常可乐
//4 1 3 -- 4 0 0
//s -> m -- 1 0 3
//m -> n -- 1 1 2
//n -> s -- 2 0 2
//最后平分后都会放在最大的两个杯子里(算上可乐瓶一共三个杯子)，且两者相等，第三者为 0
//已知 s 为两个最大杯子之一，那么再设 n 为第二大杯子，即最终结果平方在 s, n 上
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// struct nd{
//     int s, n, m, step;
// };
// int S, N, M, ans;
// bool vis[105][105][105];
// bool bfs()
// {
//     queue<nd> q;
//     memset(vis, 0, sizeof(vis));
//     q.push(nd{S, 0, 0, 0});
//     vis[S][0][0] = 1;
//     while(q.size())
//     {
//         nd nx, t = q.front(); q.pop();
//         if(t.s == t.n && !t.m)
//         {
//             ans = t.step;
//             return 1;
//         }
//         for(int i = 1; i <= 6; i++)//1->2, 1->3, 2->1, 2->3, 3->1, 3->2
//         {
//             if(i == 1) nx = t.s + t.n <= N ? nd{0, t.s + t.n, t.m} : nd{t.s + t.n - N, N, t.m};
//             if(i == 2) nx = t.s + t.m <= M ? nd{0, t.n, t.s + t.m} : nd{t.s + t.m - M, t.n, M};
//             if(i == 3) nx = t.s + t.n <= S ? nd{t.s + t.n, 0, t.m} : nd{S, t.s + t.n - S, t.m};
//             if(i == 4) nx = t.m + t.n <= M ? nd{t.s, 0, t.m + t.n} : nd{t.s, t.m + t.n - M, M};
//             if(i == 5) nx = t.s + t.m <= S ? nd{t.s + t.m, t.n, 0} : nd{S, t.n, t.s + t.m - S};
//             if(i == 6) nx = t.m + t.n <= N ? nd{t.s, t.m + t.n, 0} : nd{t.s, N, t.m + t.n - N};
//             if(!vis[nx.s][nx.n][nx.m]) nx.step = t.step + 1, vis[nx.s][nx.n][nx.m] = 1, q.push(nx);
//         }
//     }
//     return 0;
// }
// int main()
// {
//     untie();
//     while(!(cin >> S >> N >> M).eof(), S)
//     {
//         if(S & 1)
//         {
//             cout << "NO\n";
//             continue;
//         }
//         if(N < M) swap(N, M);
//         if(bfs()) cout << ans << '\n';
//         else cout << "NO\n";
//     }
//     return 0;
// }



//3.八数码难题
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <queue>
// #include <vector>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// typedef vector<vector<int> > vvi;
// string STA, END = "123804765";
// map<string, bool> vis;//共 9! 种状态
// vvi dir = vvi(8) = {{1, 3}, {-1, 1, 3}, {-1, 3}, {-3, 1, 3}, {-3, -1, 1, 3}, {-3, -1, 3}, {-3, 1}, {-3, -1, 1}, {-3, -1}};
// struct nd{
//     string mp;
//     int step;
// };
// void bfs()
// {
//     queue<nd> q;
//     q.push(nd{STA, 0});
//     vis[STA] = 1;
//     while(q.size())
//     {
//         nd now = q.front(); q.pop();
//         string str = now.mp;
//         int x = str.find('0'), cnt = now.step;
//         if(str == END)
//         {
//             cout << cnt << '\n';
//             return;
//         }
//         for(auto dx : dir[x])
//         {
//             string t = str;
//             swap(t[x], t[x + dx]);
//             if(!vis[t]) vis[t] = 1, q.push(nd{t, cnt + 1});
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> STA;
//     bfs();
//     return 0;
// }



//4.Network Saboteur
//N <= 20 可以用dfs枚举策略
//起初将所有点留在A组，再计算 继续留在A组 和 分去B组 的情况
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int n, ans = 0, mp[25][25], vis[25];
// void dfs(int i, int sum)
// {
//     if(i == n)
//     {
//         ans = max(ans, sum);
//         return;
//     }
//     dfs(i + 1, sum);//留在A组
//     //分去B组，重算∑Cij
//     vis[i] = 1;
//     for(int j = 0; j < n; j++)
//     {
//         if(j != i)
//         {
//             if(vis[j]) sum -= mp[i][j];//有已经移过去B组的点j，消去当时产生的权值mp[i][j]
//             else sum += mp[i][j];//i移过去后，j -> i 间有权值，加权
//         }
//     }
//     dfs(i + 1, sum);//分去B组后继续递归
//     vis[i] = 0;//回溯
// }
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             cin >> mp[i][j];
//     dfs(0, 0);
//     cout << ans;
//     return 0;
// }



//5.Tempter of the Bone(曼哈顿距离优化 + 简单剪枝)
//小图，dfs
//764ms，以下四个优化缺一个都会TLE
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// char mp[10][10];
// int n, m, T, vis[10][10], sx, sy, ex, ey;
// int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// bool res = 0;
// void dfs(int x, int y, int time)
// {
//     if(res) return;//优化1
//     if(time == T)//优化2
//     {
//         res |= mp[x][y] == 'D';
//         return;
//     }
//     if(mp[x][y] == 'D')//优化3
//     {
//         res |= time == T;
//         return;
//     }
//     for(int i = 0; i < 4; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && mp[nx][ny] != 'X')
//         {
//             vis[nx][ny] = 1;
//             dfs(nx, ny, time + 1);
//             vis[nx][ny] = 0;
//         }
//     }
// }
// int main()
// {
//     untie();
//     while(cin >> n >> m >> T, n)
//     {
//         memset(vis, 0, sizeof(vis));
//         res = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= m; j++)
//             {
//                 cin >> mp[i][j];
//                 if(mp[i][j] == 'S') sx = i, sy = j;
//                 else if(mp[i][j] == 'D') ex = i, ey = j;
//             }
//         }
//         //曼哈顿距离优化
//         int mdis = abs(sx - ex) + abs(sy - ey);
//         if(T < mdis) cout << "NO\n";//优化4
//         else 
//         {
//             vis[sx][sy] = 1;
//             dfs(sx, sy, 0);
//             if(res) cout << "YES\n";
//             else cout << "NO\n";
//         }
//     }
//     return 0;
// }
//更佳优化（6处）-- 374ms
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// char mp[10][10];
// int n, m, T, vis[10][10], sx, sy, ex, ey;
// int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// bool res = 0;
// void dfs(int x, int y, int time)
// {
//     if(res) return;
//     if(time == T)
//     {
//         res |= mp[x][y] == 'D';
//         return;
//     }
//     if(mp[x][y] == 'D')
//     {
//         res |= time == T;
//         return;
//     }
//     if(time + abs(x - ex) + abs(y - ey) > T)//若当前最短距离所花费时间超过T，就一定不能在time==T时到达，该路径作废
//     {
//         return;
//     }
//     for(int i = 0; i < 4; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && mp[nx][ny] != 'X')
//         {
//             vis[nx][ny] = 1;
//             dfs(nx, ny, time + 1);
//             vis[nx][ny] = 0;
//         }
//     }
// }
// int main()
// {
//     untie();
//     while(cin >> n >> m >> T, n)
//     {
//         memset(vis, 0, sizeof(vis));
//         res = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= m; j++)
//             {
//                 cin >> mp[i][j];
//                 if(mp[i][j] == 'S') sx = i, sy = j;
//                 else if(mp[i][j] == 'D') ex = i, ey = j;
//             }
//         }
//         //曼哈顿距离优化
//         int mdis = abs(sx - ex) + abs(sy - ey);
//         if(T < mdis || mdis % 2 != T % 2) cout << "NO\n";// 曼哈顿距离和最短步数奇偶性必然相同
//         else 
//         {
//             vis[sx][sy] = 1;
//             dfs(sx, sy, 0);
//             if(res) cout << "YES\n";
//             else cout << "NO\n";
//         }
//     }
//     return 0;
// }



//***6.小木棍
//n <= 65, dfs + 枚举
//最小可能长度范围 [max_len, sum]，升序枚举答案即可，最先符合条件的长度即最小值
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int n, sum = 0, max_ = 0, min_ = 1e9;
// int num[100];//num[x] 为 长度为x 的木棍的根数
// //len:每根木棍长度，now:现在拼成一根长为len的木棍的进度，cnt:要拼成cnt个长为len的木棍的进度，
// //last:最近一次选取的木棍长度 -- 每次从最长的木棍选起，并继续降序选取，这样选取的次数一定最少
// bool dfs(int len, int now, int cnt, int last)
// {
//     if(cnt == 0) return 1;//全部拼完
//     if(now == len) return dfs(len, 0, cnt - 1, max_);//拼完一根，重置now和last 并 计数后继续拼
//     for(int i = last; i >= min_; i--)//降序选取
//     {
//         if(num[i] && now + i <= len)//初步判断方案具有搜索价值
//         {
//             --num[i];
//             if(dfs(len, now + i, cnt, i))//拓展方案
//                 return 1;
//             ++num[i];//回溯
//             //最重要的两个优化：都是基于 降序选取，如果放入这一根 i 就完成了拼接，但最后的结果是失败的，那么前面的抉择有问题，回溯重选
//             //now == 0，代表现在是拼木棍的第一根棒子，并且后面无论怎么拼都不行，那么当前这一根换成其他的当然也就不行。
//             //          当上面的dfs没有返回1时，说明 木棍i 没有用上，此时 now 仍为刚拼完上一根时初始的 0。
//             //now + i == len，代表现在是拼木棍的最后一根棒子，此时 木棍i 显然最优，若最优都怎么拼也不行，那么换成其他的棒子来拼也依旧不行。
//             if(now == 0 || now + i == len) 
//                 return 0;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1, x; i <= n; i++)
//     {
//         cin >> x;
//         num[x]++;
//         max_ = max(max_, x);
//         min_ = min(min_, x);
//         sum += x;
//     }
//     for(int len = max_; len <= sum; len++)//枚举最小答案
//     {
//         if(sum % len == 0 && dfs(len, 0, sum / len, max_))//答案需满足 sum % len == 0，即能够整分
//         {
//             cout << len << '\n';
//             break;
//         }
//     }
//     return 0;
// } 



//7.矩形嵌套 (DAG图的记忆化搜索)
//路径需满足每个矩形能嵌套在下一个矩形，现求最长路径的长度。
//建图：对满足嵌套条件的两个矩阵建边，权值为 1 
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define CHECK(a, b, c, d) ((a < c && b < d) || (a < d && b < c))
// typedef pair<int, int> p;
// const int N = 1e3 + 5;
// int n, gra[N][N], f[N];
// p a[N];
// int dfs(int i)
// {
//     if(f[i] != -1) return f[i];
//     f[i] = 1;
//     for(int v = 1; v <= n; v++)
//         if(gra[i][v])
//             f[i] = max(f[i], dfs(v) + 1);
//     return f[i];
// }
// int main()
// {
//     untie();
//     int T; cin >> T;
//     while(T--)
//     {
//         cin >> n;
//         memset(gra, 0, sizeof(gra));
//         memset(f, -1, sizeof(f));
//         for(int i = 1; i <= n; i++) 
//             cin >> a[i].first >> a[i].second;
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= n; j++)
//                 if(i != j && CHECK(a[i].first, a[i].second, a[j].first, a[j].second))
//                     gra[i][j] = 1;
//         int res = 0;
//         for(int i = 1; i <= n; i++)
//             res = max(res, f[i] = dfs(i));
//         cout << res << '\n';
//     }
//     return 0;
// }



//8.滑雪 (DAG图的记忆化搜索)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e2 + 5;
// int n, m;
// int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// int dis[N][N], gra[N][N];
// int dfs(int x, int y)
// {
//     if(dis[x][y] != -1) return dis[x][y];
//     dis[x][y] = 1;
//     for(int i = 0; i < 4; i++)
//     {
//         int nx = x + dir[i][0], ny = y + dir[i][1];
//         if(nx >= 0 && nx < n && ny >= 0 && ny < m && gra[nx][ny] < gra[x][y])
//             dis[x][y] = max(dis[x][y], dfs(nx, ny) + 1);
//     }
//     return dis[x][y];
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     memset(dis, -1, sizeof(dis));
//     for(int i = 0; i < n; i++)
//         for(int j = 0, x; j < m; j++)
//             cin >> gra[i][j];
//     int res = 1;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             dis[i][j] = max(dis[i][j], dfs(i, j));
//             res = max(res, dis[i][j]);
//         }
//     }
//     cout << res;
//     return 0;
// }



//9.食物链 (DAG图的记忆化搜索)
//从食物链顶点(入度为0)开始搜，遇到一个叶子结点(出度为0)就计数一条食物链
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e5 + 5;
// int n, m, res = 0;
// int f[N], indegree[N];//f[i] 记录以 i 为顶点的食物链条数
// vector<int> gra[N];
// int dfs(int u)
// {
//     if(f[u]) return f[u];
//     if(!gra[u].size()) return 1;//没有邻居出边，说明是叶子结点
//     int cnt = 0;
//     for(int v = 0; v < gra[u].size(); v++)
//         cnt += dfs(gra[u][v]);
//     return f[u] = cnt;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     while(m--)
//     {
//         int x, y; cin >> x >> y;
//         gra[x].push_back(y);
//         ++indegree[y];
//     }
//     for(int i = 1; i <= n; i++)
//         if(!indegree[i] && gra[i].size())//size是否为空(相当于出度)判断单独点，单独点不计数
//             res += dfs(i);
//     cout << res;    
//     return 0;
// }



//10.Tian Ji -- The Horse Racing (区间DP + 记忆化搜索)
//定义状态dp[k][i][j] 为第 k 轮比赛时(与国王第k只马比赛时)田忌剩下马[i, j]。用区间[i, j]来快速定位最小和最大的马。
//贪心策略：如果该轮一定输（田忌最快赢不了其最慢），田忌就派最小的马；最快比最快能赢就比；打平就搜索派最小和最大的最优解
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e3 + 5;
// int n;
// int dp[N][N], a[N], b[N];
// bool cmp(int a, int b) {return a > b;}
// int dfs(int i, int j, int k)//返回钱数
// {
//     if(k == n + 1) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     if(a[i] > b[k])//最快的马能赢就赢
//         return dp[i][j] = dfs(i + 1, j, k + 1) + 1;
//     else if(a[i] < b[k])//赢不了就拿最差的马当炮灰
//         return dp[i][j] = dfs(i, j - 1, k + 1) - 1;
//     else//平局就搜索最佳选择 -- 选择平局还是拿劣马去输
//         return dp[i][j] = max(dfs(i + 1, j, k + 1), dfs(i, j - 1, k + 1) - 1);
// }
// int main()
// {
//     untie();
//     while(cin >> n, n) 
//     {
//         memset(dp, -1, sizeof(dp));
//         for(int i = 1; i <= n; i++) cin >> a[i];
//         for(int i = 1; i <= n; i++) cin >> b[i];
//         sort(a + 1, a + 1 + n, cmp);
//         sort(b + 1, b + 1 + n, cmp);
//         printf("%d\n", 200 * dfs(1, n, 1));
//     }
//     return 0;
// }
//也可以用双指针解










































































//N皇后问题(未修改)
// #include <iostream>
// using namespace std;
// int n, k, cnt=0;
// int col[10]{};//存一列里有没有放
// char pic[10][10];
// bool check(int x, int y)
// {   
//     for(int i=0;i<y;i++)
//         if(col[i]==x)
//             return false;
//     return true;
// }
// void DFS(int y)
// {
//     if(y==n)
//     {
//         cnt++;
//         return;
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(pic[y][i]=='#' && check(i, y))
//         {
//             col[y] = i;
//             DFS(y+1);
//         }
//     }
// }
// int main()
// {
//     while(cin>>n>>k,(n+1)&&(k+1))
//     {
//         for(int i=0;i<n;i++) cin>>pic[i];
//         cnt=0;
//         DFS(0);
//         cout<<cnt<<endl;
//     }
    
//     return 0;
// }

















































/*三.前缀和 与 差分*/
/*简单理解:
1.前缀和是指某序列的前n项和，可以把它理解为数学上的数列的前n项和;
2.差分可以看成前缀和的逆运算。合理的使用前缀和与差分，可以将某些复杂的问题简单化。
*/

//前缀和
/*知识梳理
//一维前缀和
//对于线性数列an，当对某区间范围内数值求和时，若每次都要循环遍历该区间内所有元素并加和，可能会导致时间复杂度 O(n*m) 在 n*m 很大时过高
//因此我们用一个数组S[i]，依次存储前i项和，即S[1] = a1 , S[2] = S2 = a1 + a2 ,  S[3] = S3 = a1 + a2 + a3  (S[0] 被定义为 0)
//那么在求数列的某范围[n,m] (n<=m)内数和时,只需要输出 S[m] - S[n-1] (其中S[n-1]自行理解,因为要求第n到m个数和不能减去含第n项的S[n]) 
//存储公式：sum[i] = sum[i-1] + arr[i]
//读取公式：res = sum[m] - sum[n-1]
// #include <iostream>
// using namespace std;
// const int N = 1e8 + 1;
// int arr[N], sum[N];
// int main()
// {       
//     int n,m;//待求的范围
//     //初始化数列
//     for(int i=1;i<=N-1;i++) arr[i]=i;
//     //前缀和操作(实际上可以边读取arr数列数，边进行求和操作)
//     for(int i=1;i<=N-1;i++) 
//     {
//         sum[i] = sum[i-1] + arr[i];//sum[0]=0
//     }   
//     while(cin>>n>>m)
//         cout<<sum[m]-sum[n-1]<<endl;
//     return 0;
// }

//二维前缀和
//存储公式：sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// 读取公式：res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
// #include <iostream>
// using namespace std;
// const int N = 1e4 + 1;
// int arr[N][N];
// int sum[N][N];
// int main()
// {       
//     int x1,x2,y1,y2;//待求的范围
//     //初始化数列
//     for(int i=1;i<=N-1;i++) 
//         for(int j=1;j<=N-1;j++)
//             arr[i][j]=i+j;
//     //前缀和操作(实际上可以边读取arr数列数，边进行求和操作)
//     for(int i=1;i<=N-1;i++) 
//         for(int j=1;j<=N-1;j++)
//             sum[i][j] +=  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];//sum[0][0]=0
//     while(cin>>x1>>y1>>x2>>y2)
//     {
//         int res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]; 
//         //sum[2][2] = sum[1][2] + sum[2][1] - sum[1][1] + arr[2][2] 
//         cout<< res <<endl;
//     }
//     return 0;
// }
*/


//1. P1115 最大子段和
// //前缀和 + 动规DP\贪心
// // 7
// // 2 -4 3 -1 2 -4 3
// //sum[i] = 2 -2 3 2 4 0 3
// #include <iostream>
// using namespace std;
// const int N=2*1e5+1;
// int a[N],sum[N],n,res=-N,i;
// int main()
// {
//     cin>>n;
//     for(i=1;i<=n;i++) 
//     {
//         cin>>a[i];
//         sum[i]=max(sum[i-1]+a[i],a[i]);
//         //动规下的前缀和具有选择性，若上一次前缀和小于读取到的数，那就从该数开始重新计算前缀和，这样得到能各最大子序列的前缀和序列
//         //此时前缀和思想实际上作用在所有子序列中，而不是对整体。
//         //该案例会被分成两个最大子序列，{2,-4} {3,-1,2,-4,3}
//         //分别得到前缀和序列 {2,-2} {3,2,4,0,3}
//         //其中第二个前缀和序列中的最大值 4 即答案
//         res=max(res,sum[i]);//取各前缀和序列中最大值
//     }
//     cout<<res;
//     return 0;
// }
//
// #include <iostream>
// using namespace std;
// const int N = 1000;
// int arr[N][N],sum[N][N],m,n,res=0;
// int main()
// {       
//     cin>>m>>n;
//     for(int i=1;i<=m;i++) 
//         for(int j=1;j<=n;j++)
//         {
//             cin>>arr[i][j];
//             sum[i][j] = max(sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j],arr[i][j]);
//             res=max(res,sum[i][j]);
//         }            
//     cout<< res <<endl;
//     return 0;
// }



//2.sum
//该类只需找到一个符合条件解的题无需顾虑直接搜索,但是以下是尽量减少时间(鸽巢原理)和空间复杂度(使用vector)的写法
// #include <iostream>
// #include <vector>
// using namespace std;
// int n,m,T;
// bool jud(vector<int> &s)
// {
//     if(n>=m) return true;//鸽巢原理: n+1只鸽子飞回n个鸽笼至少有一个鸽笼含有不少于2只的鸽子
//     for(int i=1;i<=n;i++)//排除n>=m情况再遍历n<m的情况，此时只有直接等于m才有可能符合，减少时间复杂度
//         for(int j=0;j<i;j++)
//             if(s[i]-s[j]==m) return true;
//     return false;
// }
// int main()
// {
//     for(cin>>T;T--&&cin>>n>>m;)
//     {
//         vector<int> s(n+5,0);
//         for(int i=1;i<=n&&cin>>s[i];i++) s[i]+=s[i-1];
//         cout<<(jud(s)?"YES\n":"NO\n");
//     }
//     return 0;
// }
//原来的写法:
// for(int i=1;i<=n;i++)
//     for(int j=i;j<=n;j++)
//         if((s[j]-s[i-1])%m==0)
//         {
//             res=1;
//             goto Here;
//         }
//     Here:
//     cout<<(res?"YES\n":"NO\n");
/*
5
2 4 9 22 31
s= 2 6 15 37 68 
r= 2 1 0 2 3
举个例子：设m=7，且整数为 2,4,6,3,5,5,6 。
计算上面的和得到 2,6,12,15,20,25,31，这些整数被7除时余数分别为 2,6,5,1,6,4,3。
有两个等于6的余数，这意味着结论：6+3+5=14 可被7整除

证明：
考虑有m个和（Sn）,
a1,a1+a2,a1+a2+a3,……,a1+a2+a3+...+am
要证这其中至少有一个和可以被m整除
1.若这些和其中一个Si可以被m整除即Si%m=0，则该段序列之和Si可以被m整除
2.这些和中的每一个除以m都有一个非零余数，余数等于1,2，……，m-1 中的一个数。
因为有m个和，而只有m-1个余数，所以必然有两个和除以m有相同的余数。(鸽巢原理)
因此，存在整数 k和l，k<l，使得a1+a2+...+ak 和 a1+a2+...+al除以m有相同的余数r：
a1+a2+...+ak=b*m+r，a1+a2+...+al=c*m+r
两式相减得 ak + ak+1 + ak+2 + …… + al = (c-b)*m
即该段连续子序列之和可以被m整除
*/

//3.Olympiad
/*AC
#include <iostream>
#include <set>
using namespace std;
int T,sum[100005],x1,x2;
bool jud(int x,set<int> &s)//判定是否为完美数
{
    if(!x) return 1;
    if(!s.count(x%10)) s.insert(x%10), jud(x/10,s);//没重复就先放进集合，方便下次判重，并且递归继续深入判重
    else return 0;//已经有这个元素，说明重复
}
int main()
{
    //先打表
    for(int i=1;i<=100000;i++)
    {
        set<int> s;
        sum[i]=jud(i,s);
        sum[i]+=sum[i-1];
    }
    for(cin>>T;T--&&cin>>x1>>x2;) cout<<sum[x2]-sum[x1-1]<<endl;
    return 0;
}
*/
/*郭教（对单个数各位数的判重 更佳写法——位运算）
bool Judge(int x) {
    int flag = 0;
    for(; x; x /= 10) {
        if(flag >> x % 10 & 1) return false;
        flag |= 1 << x % 10;
    }
    return true;
}
flag用二进制视角理解初始为 00 0000 0000 (只需要判数0~9，即10个位置，低位对0判重)
如一个数 343
先对个位3操作
    首次判断无效
    1 << x % 10 即 1 << 3 --> 00 0000 1000
    然后 flag（00 0000 0000） |= 00 0000 1000 即 00 0000 1000 （可以理解为标记插入一个1）
再对十位的4操作
    先判断:
        flag >> x % 10 即 flag>>4 即产生  00 0000 0000（里面的1被抛出）
        随即 00 0000 0000 & 1 发现没有重复(该数没有被标记过)
    然后 flag（00 0000 1000） |= 00 0001 0000 （由1<<4产生），即标记得到 00 0001 1000
最后对百位的3操作
    判重：
        flag >> 3 即 00 0000 0011
        随机 00 0000 0011 & 1 （实际上是对低位求 按位与 1），发现低位也为1（即3已被标记），得到1,故判定其为重复数
*/



//4.Intense Heat
/*AC
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int n,m,s[5005];
// double res=0;
// int main()
// {
//     scanf("%d%d",&n,&m);
//     for(int i=1;i<=n && scanf("%d",&s[i]);i++) s[i]+=s[i-1];
//     for(int i=m;i<=n;i++)
//         for(int j=i;j<=n;j++)
//             res=max(res, 1.0*(s[j]-s[j-i])/i);
//     printf("%.8f\n",res);
//     return 0;
// }
*/


//5.最大子矩阵(二级前缀和)
/*AC
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int T,n,m,x,y,a[1000][1000];
// int main()
// {
//     cin>>T;
//     while(T--)
//     {
//         int res=0;
//         cin>>m>>n>>x>>y;
//         for(int i=1;i<=m;i++)
//             for(int j=1;j<=n;j++)
//             {
//                 cin>>a[i][j];
//                 a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
//                 if(i>=x&&j>=y) res=max(res,a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y]);
//             }
//         cout<<res<<endl;
//     }
//     return 0;
// }
*/
/*写法优化
#include <iostream>
#include <algorithm>
using namespace std;
int T,n,m,x,y,res=0,a[1000][1000];
int main()
{
    for(cin>>T;T--&&cin>>m>>n>>x>>y;res=0)
    {
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
                if(i>=x&&j>=y) res=max(res,a[i][j]-a[i-x][j]-a[i][j-y]+a[i-x][j-y]);
            }
        cout<<res<<endl;
    }
    return 0;
}
*/


//6. P1719 最大加权矩形
//AC O(n^4)
// #include <cstdio>
// #include <algorithm> 
// int a[130][130];
// int main()
// {
//     int n,res=-__INT32_MAX__;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=n;j++)
//         {
//             scanf("%d",&a[i][j]);
//             a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
//         }
//     for(int x1=1;x1<=n;x1++)
//         for(int y1=1;y1<=n;y1++)
//             for(int x2=x1;x2<=n;x2++)
//                 for(int y2=y1;y2<=n;y2++)
//                     res = std::max(res,a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1]);
//     printf("%d",res);
//     return 0;
// }
//DP动规方法！
// #include<cstdio>
// int b[125][125];
// int main() {
// 	int n,ans=-1828805;//经过计算，最小不会小过这个值 
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;++i) {
// 		for(int j=1;j<=n;++j) {
// 			int a;
// 			scanf("%d",&a);
// 			b[i][j]=b[i-1][j]+a;//只存竖向每一列的前缀和
// 		}
// 	}
// // 0 -2 -7 0
// //  9 2 -6 2
// // -4 1 -4  1
// // -1 8  0 -2
// //转换为以下竖向前缀和
// // 0 -2 -7 0 
// // 9 0 -13 2
// // 5 1 -17 3
// // 4 9 -17 1
//     for(int i=1;i<=n;++i,printf("\n")) {
// 		for(int j=1;j<=n;++j) {
// 			printf("%d ",b[i][j]);
// 		}
// 	}
// 	for(int i=1;i<=n;++i) {
// 		for(int j=0;j<i;++j) {//竖向双层循环全遍历
// 			int sum=0;
// 			for(int k=1;k<=n;++k) {
// 				int tmp=b[i][k]-b[j][k];//取一段竖向的前缀和 
// 				if(sum<0)	sum=0;//小于0的和重新计算
//                 sum+=tmp;
// 				if(sum>ans)	ans=sum;
// 			}
// 		}
// 	}
// 	printf("%d",ans);
// 	return 0;
// }




















//差分
// 差分数组：
// 首先给定一个原数组a[]：a[1], a[2], a[3],,,,,, a[n];
// 然后我们构造一个数组b[] ： b[1], b[2], b[3],,,,,, b[i];
// 使得 a[i] = b[1] + b[2] + b[3] + ,,,,,, + b[i]
// 也就是说，a数组是b数组的前缀和数组，反过来我们把b数组叫做a数组的差分数组。换句话说，每一个a[i]都是b数组中从头开始的一段区间和。
// 用途：
// 如给定区间[l, r]，让我们把a数组中的[l, r] 区间中的每一个数都加上c,即 a[l] + c , a[l + 1] + c , a[l + 2] + c ,,,,,, a[r] + c;
// 即能高效地对一个范围内数进行更改\运算,而不是遍历整个区块
// 算法重点:
// 给a数组中的[l, r] 区间中的每一个数都加上c,只需对差分数组b[]做 b[l] + = c, b[r+1] -= c 
// 而 b[r+1] -= c 可以使得该区间后的数不会受前面修改的影响！做到只修改某一区间的值

//一维差分
// #include<iostream>
// using namespace std;
// const int N = 1e5 + 10;
// int a[N],b[N]; 
// int main()
// {
//     int n,m;
//     scanf("%d%d", &n, &m);
//     for(int i = 1;i <= n; i++) 
//     {
//         scanf("%d", &a[i]);
//         b[i] = a[i] - a[i - 1];      //构建差分数组
//     }
//     int l, r, c;
//     while(m--)
//     {
//         scanf("%d%d%d", &l, &r, &c);
//         b[l] += c;     //表示将序列中[l, r]之间的每个数加上c
//         b[r + 1] -= c;
//     }
//     for(int i = 1;i <= n; i++) 
//     {
//         b[i] += b[i - 1];  //求前缀和运算
//         printf("%d ",b[i]);
//     }
//     return 0;
// }

//二维差分
// #include<iostream>
// #include<cstdio>
// using namespace std;
// const int N = 1e3 + 10;
// int a[N][N], b[N][N];
// void insert(int x1, int y1, int x2, int y2, int c)
// {
//     b[x1][y1] += c;
//     b[x2 + 1][y1] -= c;
//     b[x1][y2 + 1] -= c;
//     b[x2 + 1][y2 + 1] += c;
// }
// int main()
// {
//     int n, m, q;
//     cin >> n >> m >> q;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             cin >> a[i][j];
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             insert(i, j, i, j, a[i][j]);      //构建差分数组
//     while (q--)
//     {
//         int x1, y1, x2, y2, c;
//         cin >> x1 >> y1 >> x2 >> y2 >> c;
//         insert(x1, y1, x2, y2, c);
//     }
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //二维前缀和
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             printf("%d ", b[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


//1.Color the ball
/*AC 简单一级差分 及 其前缀和查询
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int N=1e5+5;
// int b[N],n,x1,x2;
// int main()
// {
//     while(~scanf("%d",&n),n)
//     {
//         memset(b,0,sizeof b);
//         for(int i=0;i<n&&scanf("%d%d",&x1,&x2);i++) b[x1]+=1, b[x2+1]-=1;
//         for(int i=1,t=b[1];i<=n;t+=b[++i]) printf(" %d"+!(i-1),t);
//         printf("\n");
//     }
//     return 0;
// }
*/


//2.Tallest Cow
/*AC
// #include <iostream>
// #include <set>
// using namespace std;
// typedef pair<int,int> p;
// int b[10000],N,I,H,R,A,B;
// set<p> s;//可能会有重复区间，判重
// int main()
// {
//     cin>>N>>I>>H>>R;
//     b[0]=H;//每头牛基础高度定为最高高度
//     while(R--)
//     {
//         cin>>A>>B;
//         if(A>B) swap(A,B);
//         if(!s.count(p(A,B))) 
//         {
//             s.insert(p(A,B));
//             b[A+1]--,b[B]++;//处理牛之间高度的相对关系
//         }
//     }
//     for(int i=1;i<=N;i++)
//     {
//         b[i]+=b[i-1];
//         cout<<b[i]<<endl;
//     }
//     return 0;
// }
*/


//3.Monitor(二级差分)
//小知识: cmath头文件里面定义了y1,j0,j1,jn,y0,yn(均用于贝塞尔函数解)，所以这些变量尽量不用在全局变量中
/*AC
// #include <cstdio>
// #include <vector>
// using namespace std;
// typedef vector<int> vi;
// void bsum(int n,int m,bool op,vector<vi> &b)//1=前缀和,0=转bool
// {
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             if(op) b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
//             else b[i][j]=bool(b[i][j]);//表示重复区域 >1 的仍为1, 为0的仍为0
// }
// int main()
// {       
//     int n,m,p,q,x1,x2,y1,y2;
//     while(~scanf("%d%d",&n,&m))
//     {
//         vector<vi> b(n+5,vi(m+5,0));
//         for(scanf("%d",&p);p-- && scanf("%d%d%d%d",&x1,&y1,&x2,&y2);)
//             b[x1][y1]++,b[x2+1][y1]--,b[x1][y2+1]--,b[x2+1][y2+1]++;
//         bsum(n,m,1,b);
//         bsum(n,m,0,b);
//         bsum(n,m,1,b);
//         for(scanf("%d",&q);q-- && scanf("%d%d%d%d",&x1,&y1,&x2,&y2);)
//         {
//             int sum=b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1];
//             printf(sum>=(x2-x1+1)*(y2-y1+1) ? "YES\n":"NO\n");
//         }
//     }
//     return 0;
// }
*/
/*郭教代码（二维差分 转 二维前缀和 的另类写法）
#include<cstdio>
#include<algorithm>
#include<set>
int n, m, p, q;
int main() {
    int x1, y1, x2, y2; // 小课堂：y1不能做全局变量，新手的坑
    while(scanf("%d%d", &n, &m) != EOF) {
        std::vector<std::vector<int> > a(n + 10, std::vector<int>(m + 10, 0));
        for(scanf("%d", &p); p --; ) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            a[x1][y1] ++;
            a[x1][y2 + 1] --;
            a[x2 + 1][y1] --;
            a[x2 + 1][y2 + 1] ++;
        }
        //以下代码理解即可(加深对该算法的理解)
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                a[i][j] += a[i][j - 1];
            }
            for(int j = 1; j <= m; j ++) {
                a[i][j] += a[i - 1][j];
            }
        }
        //该写法先对横向求和，再纵向求和，这样对于二维差分转二维前缀和极其方便！！！！！
        //如矩阵(由x=1,y=1起头,x=0或y=0处值均为0):
        //1 1 1 1
        //1 1 1 1
        //1 1 1 1
        //外层循环,当i=1时
        //  内层第一循环先求和该行，得到:
        //  1 2 3 4
        //  1 1 1 1
        //  1 1 1 1
        //  内层第二循环给该行附上上一行的值，由于此时上一行为x=0，值均为0，循环后矩阵不变
        //外层循环,i=2
        //  内层第一循环先求和该行，得到：
        //  1 2 3 4
        //  1 2 3 4
        //  1 1 1 1
        //  内层第二循环给该行附上上一行的值，则：
        //  1 2 3 4
        //  2 4 6 8
        //  1 1 1 1
        //外层循环，i=3，同理：
        //  第一循环得到：
        //  1 2 3 4
        //  2 4 6 8
        //  1 2 3 4
        //  第二循环得到：
        //  1 2 3 4
        //  2 4 6 8
        //  3 6 9 12
        //最后每个点代表着一个范围的求和，即二维前缀和
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                a[i][j] = (!!a[i][j]) + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];    // 按bool处理
            }//!!a[i][j] 相当于 bool(a[i][j])
        }
        for(scanf("%d", &q); q --; ) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int sum = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
            if(sum == (x2 - x1 + 1) * (y2 - y1 + 1)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
*/


//4.P3397 地毯
// #include <cstdio>
// int b[1005][1005];//数组定义每一维长度一定要至少多出5，不然容易越界
// int main()
// {
//     int n,m,x1,y1,x2,y2;
//     for(scanf("%d%d",&n,&m);m--&&scanf("%d%d%d%d",&x1,&y1,&x2,&y2);)
//         b[x1][y1]++, b[x2+1][y1]--, b[x1][y2+1]--, b[x2+1][y2+1]++;
//     for(int i=1;i<=n;i++,printf("\n"))
//         for(int j=1;j<=n;j++)
//             printf(" %d"+!(j-1),b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1]);
//     return 0;
// }


















/*四. 高精度问题*/
//1. A+B problem
//WA
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;
// int a[600],b[600],res[600];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     string as,bs;
//     cin>>as>>bs;
//     if(as.size()<bs.size()) swap(as,bs);
//     int len1=as.size(), len2=bs.size();
//     for(int i=0;i<len1;i++) res[len1-i-1]=a[len1-i-1]=as[i]-'0';
//     for(int i=0;i<len2;i++) b[len2-i-1]=bs[i]-'0';
//     for(int i=0;i<len2;i++)
//     {
//         res[i]+=b[i];
//         res[i+1]+=res[i]/10;
//         res[i]%=10;
//     }
//     for(int i=len1;i>=0;i--)
//     {
//         if(i==len1&&!res[i]);
//         else cout<<res[i];
//     }
//     return 0;
// }
//AC (下标的艺术)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// char a1[505],b1[505];
// int a[505],b[505],res[505],len1,len2,len3;
// int main()
// {
//     cin>>a1>>b1;
//     len1=strlen(a1);
//     len2=strlen(b1);
//     len3=max(len1,len2);
//     for(int i=0,j=len3-len1+1;i<len1&&j<=len3;i++,j++) a[j]=a1[i]-'0';
//     for(int i=0,j=len3-len2+1;i<len2&&j<=len3;i++,j++) b[j]=b1[i]-'0';
//     for(int i=len3;i>=1;i--)
//     {
//         res[i]+=a[i]+b[i];
//         res[i-1]+=res[i]/10;
//         res[i]%=10;
//     }
//     if(res[0]!=0) cout<<res[0];
//     for(int i=1;i<=len3;i++) cout<<res[i];
//     return 0;
// }


//2. A*B problem
// #include <cstdio>
// #include <cstring>
// using namespace std;
// char n1[2005],n2[2005];
// int a[8000],b[8000],res[8000];
// int main(){
//     scanf("%s%s",&n1,&n2);
//     if(n1[0]=='0'||n2[0]=='0')//一个为 0 则直接输出 0 并退出程序
//     {
//         printf("0");
//         return 0;
//     }
//     int len1=strlen(n1), len2=strlen(n2);
//     for(int i = 0; i < len1; i++) a[i] = n1[len1-1-i] - '0';
//     for(int i = 0; i < len2; i++) b[i] = n2[len2-1-i] - '0';
//     for(int i = 0; i < len1; i++)
//     {
//         for(int j = 0; j < len2; j++)
//         {
//             res[i+j] += a[i] * b[j];
//             res[i+j+1] += res[i+j] / 10;//十位数进位至下一个索引位置
//             res[i+j] %= 10;//在该位结果只保留个位数
//         }
//     }
//     for(int i = len1+len2-1; i >= 0; i--)
//     {
//         if(i == len1+len2-1 && res[i] == 0) continue;//乘数可能太小，未产生进位，导致在结果的最高位产生前导零,如 100000000 * 3
//         printf("%d", res[i]);
//     }
//     return 0;
// }






















/*五. */
//二分查找
// mid = (right + left) / 2 的写法中 (right + left) 容易超限，为了避免两数相加过大超限，采用如下写法：
// mid = left + (right - left) / 2
// 该算法需要序列是有序的，故常与 sort() 函数搭配
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int nums[100000];
// int binary_search(int nums[], int size, int target)
// {
//     int left = 0, right = size - 1;
//     while(left <= right)//注意这里区间为双闭区间 [left, right] 即left和right都能取到值,故left==right的情况也可以取到值
//     {
//         int mid = left + (right - left) / 2;
//         if(nums[mid] < target) left = mid + 1;
//         else if(nums[mid] > target) right = mid - 1;
//         else 
//             return mid;//找到就返回下标
//     }
//     return -1;//没找到的情况
// }
// int main()
// {
//     int tg;
//     while(cin >> tg, tg!=-1)
//     {
//         int n,i=0;
//         while(cin>>n,n!=-1) nums[i++] = n;
//         sort(nums, nums + i);
//         int res = binary_search(nums, i, tg);
//         cout << res << endl;
//     }
//     return 0;
// }


//1. P2249 查找
//二分法(稍有变通) 0.3s 4.25mb
// #include <iostream>
// using namespace std;
// int nums[1000005],n,m;
// int bin_search(int tg)
// {
//     int lef = 1, rig = n + 1;//左闭右开区间
//     while(lef < rig)
//     {
//         int mid = lef + (rig - lef) / 2;
//         if(nums[mid] >= tg) rig = mid;//*当等于 tg 时也继续二分下去，直到 lef 指向最左侧的目标值
//         else lef = mid + 1;
//     }
//     if(nums[lef] == tg) return lef;
//     else return -1;
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     cin >> n >> m;
//     for(register int i = 1; i <= n; i++) cin >> nums[i];
//     while(m--)
//     {
//         int target, res;
//         cin >> target;
//         res = bin_search(target);
//         cout << res << ' ';
//     }
//     return 0;
// }
//set查找 与 无序映射 的应用(需要O2优化并且耗时超过 1s,空间超过67mb)
// #include <iostream>
// #include <set>
// #include <unordered_map>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n,m;
//     multiset<int> ms;//multiset允许重复数据，即不会检测重复值，效率更快
//     unordered_map<int,int> mp;//存入时无需排序功能故不用map，若用map会超时
//     cin >> n >> m;
//     for(register int i = 1; i <= n; i++) 
//     //因为答案编号从1开始，存入数组也从下标1开始，省去一些麻烦 ； register int减少多次循环的耗时
//     {
//         int k;
//         cin >> k;
//         ms.insert(k);
//         if(mp[k]==0) mp[k] = i;//存该数对应的编号
//     }
//     while(m--)
//     {
//         int target, res;
//         cin >> target;
//         res = *ms.lower_bound(target);//该函数返回 >= target 的元素的指针位置，可以解引用直接取到该值
//         if(res != target) cout<<-1<<' ';
//         else cout<< mp[res] << ' ';
//     }
//     return 0;
// }


//2. P1102 A-B 数对
//映射法
// #include <iostream>
// #include <map>
// using namespace std;
// typedef long long ll;
// ll a[200005];
// map<ll, int> mp;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll N, C, ans=0;
//     cin>>N>>C;
//     for(register int i=0;i<N;i++)
//     {
//         cin>>a[i];//读入A
//         mp[a[i]]++;
//         a[i]-=C;//转成B
//     }
//     for(register int i=0;i<N;i++)
//         ans += mp[a[i]];//A-B=C -> A-C=B,现在查B有多少个（次）即得到多少对A-B=C
//     cout<<ans<<'\n';
//     return 0;
// }
//双指针法
//原理：符合条件的数可能是一个，也可能在一个连续区间里
//  那么我们用rig1找到这个区间左索引，用rig2找到区间右索引（不包含于此）
// #include <iostream>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// ll a[200005];
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll N, C, ans=0;
//     cin>>N>>C;
//     for(register int i = 1;i <= N;i++) cin>>a[i];
//     sort(a+1, a+1+N);
//     int lef = 1, rig1 = 1, rig2 = 1;
//     for(lef = 1; lef <= N; lef++)
//     {
//         while(rig1 <= N && a[rig1]-a[lef] < C) rig1++;//左闭 a[rig1]满足条件     
//         while(rig2 <= N && a[rig2]-a[lef] <= C) rig2++;//右开！a[rig1<=i<rig2]满足条件       
//         if(a[rig1] - a[lef] == C && a[rig2-1] - a[lef] == C && rig2 >= 2)//rig2 >= 2说明至少要有两个数
//             ans += rig2 - rig1;
//     }
//     cout<<ans<<'\n';
//     return 0;
// }






//三分查找
//将待查元素x与n/3处的元素比较，然后将x与2n/3处的元素进行比较。比较的结果或者找到x,或者将搜索范围缩小到原来的n/3
//每次由两个mid来滑动，m1 = (2/3)*left + (1/3)rig 在左侧；m2 = (1/3)left + (2/3)rig 在右侧
//同样的，防止超限的写法：m1 = lef + (rig - lef) / 3 ；m2 = rig - (rig - lef) / 3;
//lef=0            m1            m2         rig=n-1
//若       x
//lef=0      rig=m1-1  
//若                                    x
//                             lef=m2+1     rig=n-1
//若                      x
//                lef=m1+1   rig=m2(因为时直接用else,没有另外讨论nums[m2],故nums[m2]也可能为x，所以不减1)
// #include <iostream>
// using namespace std;
// int nums[] = {1,2,3,4,5,6}, n=6;
// int third_search(int lef, int rig, int x)
// {
//     if(lef <= rig)//双闭区间
//     {
//         int m1 = lef + (rig - lef) / 3;
//         int m2 = rig - (rig - lef) / 3;
//         if(x == nums[m1]) return m1;
//         if(x == nums[m2]) return m2;
//         if(x < nums[m1]) return third_search(lef, m1 - 1, x);
//         if(x > nums[m2]) return third_search(m2+1, rig, x);
//         else return third_search(m1+1,m2,x);
//     }
//     return -1;
// }
// int main()
// {
//     int res, x;
//     while(cin>>x)
//     {
//         res = third_search(0, n-1, x); 
//         cout<<res<<endl;
//     }
//     return 0;
// }





//1. 跳石头
//二分寻找最大的最短距离，使得按该距离搬走石头，刚好搬走M个
//可尝试用差分简化
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// ll dis[50010], L;
// int N, M;
// bool judge(ll x)
// {   
//     int now = 0, cnt = 0;
//     for(int i = 1 ; i <= N + 1 ; i++)
//         if(dis[i] - dis[now] < x)//距离小于期望距离x（x是我们希望的可以跳过的两石头间距离）
//             cnt++;
//         else
//             now = i;//这块石头不能搬走，或者说它因为大于等于x 所有我们可以跳，无需搬走，现在它变成了起点来算其后石头的距离
//     return cnt <= M;
// }
// int main()
// {
//     scanf("%lld%d%d",&L,&N,&M);
//     for(int i = 1; i <= N; i++) scanf("%lld", &dis[i]);//一定要从1开始，因为dis[0]需要为0
//     dis[N+1] = L;
//     ll lef = 1, rig = L, ans = 0;
//     while(lef <= rig)
//     {
//         ll mid = lef + (rig - lef) / 2;
//         if(judge(mid)) 
//         {
//             ans = mid;//最后的ans即是最优解
//             lef = mid + 1;//mid左边的石头都判断过了,再查其右边有无更优
//         }
//         else
//             rig = mid - 1;
//     }
//     printf("%lld", ans);
//     return 0;
// }



//2. Cable master(二分 与 小数精度 问题)
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #define MaxInt 2147483647
// using namespace std;
// double a[10005];
// int N,k;
// bool cal(double x)
// {
//     long long res = 0;
//     for(int i = 0;i < N;i++)
//         res += (int)(a[i] / x);
//     return res >= k;
// }
// int main()
// {
//     double l=0, r=MaxInt, mid;
//     scanf("%d%d", &N, &k);
//     for(int i=0;i<N;i++) scanf("%lf", &a[i]);
//     for(int i=0;i<100;i++)
//     {
//         mid = l + (r - l) / 2;
//         if(cal(mid)) l = mid;
//         else r = mid;
//     }
//     printf("%.2f", floor(l*100.0)/100.0);
//     return 0;
// }
 /*
问题案例：
4 10
0.01
0.01
0.02
0.01
若直接输出结果则会输出0.01 ,实际上这是0.005被四舍五入的结果，但应当输出0.00
 */



//3. P2440 木材加工
// #include <iostream>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// ll a[100005];
// int N,k;
// bool cal(ll x)
// {
//     ll res = 0;
//     for(register int i = 0;i < N;i++)
//     {
//         res += a[i] / x;
//     }
//     return res >= k;
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     ll l=0, r=1e8 + 1, mid;
//     cin>>N>>k;
//     for(int i=0;i<N;i++) cin>>a[i];
//     while(l+1 < r)
//     {
//         mid = l + (r - l) / 2;
//         if(cal(mid)) l = mid;
//         else r = mid;
//     }
//     cout << l << '\n';
//     return 0;
// }



//4. Pie
// #define _USE_MATH_DEFINES
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// double a[10005];
// int N,k;
// bool cal(double x)
// {
//     long long res = 0;
//     for(int i = 0;i < N;i++)
//         res += (int)(a[i] / x);
//     return res >= k;
// }
// int main()
// {
//     int T;
//     scanf("%d",&T);
//     while(T--)
//     {
//         double l=0, r=0, mid;
//         scanf("%d%d", &N, &k);
//         k++;
//         for(int i=0;i<N;i++) 
//         {
//             scanf("%lf", &a[i]);
//             a[i]*=M_PI*a[i];
//             r=max(r,a[i]);
//         }
//         r+=1.0;
//         for(int i=0;i<100;i++)
//         {
//             mid = l + (r - l) / 2;
//             if(cal(mid)) l = mid;
//             else r = mid;
//         }
//         printf("%.4lf\n", l);
//     }
//     return 0;
// }



//5. Freefall
// #include <cstdio>
// #include <cmath>
// typedef double db;
// using namespace std;
// const db eps = 1e-8;
// db A, B;
// db f(db x)
// {
//     return A / sqrt(x + 1) + x * B;
// }
// int main()
// {
//     while(~scanf("%lf%lf", &A, &B))
//     {
//         db low = 0, high = A, m1, m2;
//         for(int i=0 ; i<1000 ; i++)
//         {
//             m1 = low + (high - low) / 3;
//             m2 = high - (high - low) / 3;
//             if(f(m1) - f(m2) >= eps) low = m1;
//             else high = m2;
//         }
//         printf("%.10f\n", min(f(ceil(low)), f(floor(low))));
//     }
//     return 0;
// }
/*
四舍五入就：x + 0.5 转 整型
向下取整就是：转int
向上取整就是：x - eps + 1 转 整型
*/



//6. Monthly Expense (二分 + 贪心)
// #include <cstdio>
// #include <algorithm>
// using namespace  std;
// int n, m, a[100005];
// bool judge(int x)
// {
//     int cnt = 0, sum = 0;
//     for(int i = 1;i <= n;i++)
//     {
//         if(sum + a[i] <= x) sum += a[i];//能装多少就装多少
//         else 
//         {
//             cnt++;
//             sum = a[i];//直到装不下再重新算
//         }
//     }
//     return cnt >= m;
// }
// int main()
// {
//     while(~scanf("%d%d",&n,&m))
//     {
//         int l = 0, r = 1e9, mid;
//         for(int i = 1;i <= n;i++) 
//         {
//             scanf("%d",&a[i]);
//             l = max(a[i], l);//排除特殊案例，最小开销至少为max(a[i]) （最大开销至少为所有和 这个倒没关系）
//         }
//         while(l <= r)
//         {
//             mid = l + (r - l) / 2;
//             if(judge(mid)) 
//                 l = mid + 1;
//             else 
//                 r = mid - 1;
//         }
//         printf("%d\n", l);
//     }
//     return 0;
// }



//*7. Last Rook(交互式二分)
// 问题转换为两个子问题
// ·哪一列不包含 Rook？
// ·哪一行不包含 Rook？
// 分别查找二分答案即可，最后将共同指向一个坐标
// #include <cstdio>
// int IO(int a, int b, int c, int d)
// {
//     int rec;
//     printf("? %d %d %d %d\n", a, b, c, d);
//     fflush(stdout);
//     scanf("%d", &rec);
//     return rec;
// }
// int main()
// {
//     int N;
//     scanf("%d", &N);
//     int x1 = 1, x2 = N + 1, y1 = 1, y2 = N + 1;
//     //二分行
//     while(x1 + 1 < x2)
//     {
//         int mid = (x1 + x2) >> 1;
//         if(IO(x1, mid - 1, 1, N) == mid - x1) x1 = mid;//个数若与间距相仿，则缩小左界范围
//         else x2 = mid;
//     }
//     //二分列
//     while(y1 + 1 < y2)
//     {
//         int mid = (y1 + y2) >> 1;
//         if(IO(1, N, y1, mid - 1) == mid - y1) y1 = mid;
//         else y2 = mid;
//     }
//     printf("! %d %d\n", x1, y1);
//     fflush(stdout);
//     return 0;
// }



//8. Yukari's Birthday
//枚举 + 二分
//本题重点，数据乘积容易溢出，学会如何判溢出
// #include <cstdio>
// #include <cmath>
// #include <iostream>
// using namespace std;
// typedef long long ll;
// #define R first
// #define K second
// ll n;
// ll cal(ll k, ll r)
// {
//     ll res = 0, base = 1;
//     //base需要是 __int128_t 或者 提前判断溢出，否则当 n = 1e12, k = 1e11时溢出
//     //合法范围 base * k <= max ,  max = n
//     //换成除法形式判溢出
//     for(int i = 1; i <= r; i++)
//     {
//         if(n / base < k) return n + 1; //当base过大时，所得k就会过小
//         res += (base *= k);
//         if(res > n) return n + 1;
//     }
//     return res;
// }
// int main()
// {
//     while(~scanf("%lld", &n))
//     {
//         pair<ll, ll> ans(1, n - 1);//初始化为可能性较大的 (r, k)对
//         for(int r = 2; r <= 40; r++)
//         {
//             ll k1 = 2, k2 = n - 1;// 2 <= k <= n - 1
//             while(k1 <= k2)
//             {
//                 ll mid = k1 + ((k2 - k1) >> 1);
//                 ll res = cal(mid, r);
//                 if(res == n || res == n - 1) 
//                 {
//                     if(r * mid < ans.R * ans.K || (r * res == ans.R * ans.K && r < ans.R)) 
//                         ans = pair<ll, ll>(r, mid);
//                 }   
//                 if(res < n - 1) k1 = mid + 1;//注意二分界
//                 else k2 = mid - 1;
//             }
//         }
//         printf("%lld %lld\n", ans.R, ans.K);
//     }
//     return 0;
// }



//9. A-B 数对
//正常写要两次二分，直接用函数
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int a[200005];
// int main()
// {
//     int n, c;
//     long long cnt = 0;
//     scanf("%d%d", &n, &c);
//     for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//     sort(a+1, a+1+n);
//     for(int i = 1; i <= n; i++)
//     {
//         cnt += (upper_bound(a+1, a+1+n, a[i]-c) - a) - (lower_bound(a+1, a+1+n, a[i]-c) - a);
//         //两个指针相减的结果是他们之间的距离
//     }
//     printf("%lld", cnt);
//     return 0;
// }



//10. 三分法
//完全三分
// #include <cstdio>
// #include <cmath>
// int n;
// double l, r, base[15], eps = 1e-8;
// double cal(double x)
// {
//     double res = 0;
//     for(int i = 0; i <= n; i++) res += base[i] * pow(x, n - i);
//     return res;
// }
// int main()
// {
//     scanf("%d%lf%lf", &n, &l, &r);
//     for(int i = 0; i <= n; i++) scanf("%lf", &base[i]);
//     for(int i = 0; i < 100; i++)
//     {
//         double k = (r - l) / 3.0;
//         double m1 = l + k, m2 = r - k;
//         if(cal(m1) <= cal(m2)) l = m1;
//         else r = m2;
//     }
//     printf("%.5f", l);
//     return 0;
// }
//近似三分
// #include <cstdio>
// #include <cmath>
// int n;
// double l, r, base[15], eps = 1e-8;
// double cal(double x)
// {
//     double res = 0;
//     for(int i = 0; i <= n; i++) res += base[i] * pow(x, n - i);
//     return res;
// }
// int main()
// {
//     scanf("%d%lf%lf", &n, &l, &r);
//     for(int i = 0; i <= n; i++) scanf("%lf", &base[i]);
//     for(int i = 0; i < 100; i++)
//     {
//         double mid = (l + r) / 2;
//         if(cal(mid+eps) >= cal(mid-eps)) l = mid;
//         else r = mid;
//     }
//     printf("%.5f", l);
//     return 0;
// }



//11. 查找
// #include <cstdio>
// int a[1000005];
// int main()
// {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//     while(m--)
//     {
//         int x;
//         scanf("%d", &x);
//         int l = 1, r = n + 1, mid;
//         for(int i = 0; i < 100; i++)
//         {
//             mid = l + ((r - l)>>1);
//             if(a[mid] < x) l = mid + 1;
//             else r = mid;
//         }
//         if(a[l] == x) printf("%d ", l);
//         else printf("-1 ");
//     }
//     return 0;
// }
//二分函数
// #include <cstdio>
// #include <algorithm>
// int a[1000005];
// int main()
// {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//     while(m--)
//     {
//         int x, ind;
//         scanf("%d", &x);
//         ind = std::lower_bound(a+1, a+1+n, x) - a;
//         if(a[ind] == x) printf("%d ", ind);
//         else printf("-1 ");
//     }
//     return 0;
// }



//12. 分巧克力
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// typedef pair<ll,ll> pll;
// pll s[100005];
// int n, k;
// bool judge(ll x)
// {
//     ll res = 0;
//     for(int i = 1; i <= n; i++) res += (s[i].first / x) * (s[i].second / x);//重点
//     return res >= k;
// }
// int main()
// {   
//     scanf("%d%d", &n, &k);
//     for(int i = 1; i <= n; i++) scanf("%lld%lld", &s[i].first, &s[i].second);
//     ll lef = 1, rig = 1e5, mid;
//     while(lef <= rig)
//     {
//         mid = lef + ((rig - lef) >> 1);
//         if(judge(mid)) lef = mid + 1;
//         else rig = mid - 1;
//     }
//     printf("%lld", lef - 1);
//     return 0;
// }











/*六. 单调栈 与 单调队列*/
//单调栈是一种特殊的栈，特殊之处在于栈内的元素都保持一个单调性。出现不单调者时抛出
//释义场景：高个子同学可以看到身高比自己矮的同学，但是目光一旦遇到高于或等于自己的同学后，便无法继续向前看。
//         现先给出所有同学的身高，求所有同学能看到的同学数量之和。
//如需要输出某个值的下标或编号等，则需要先将输入的值都存入数组，若还是个递增栈需要子结果，还得再开个存储答案的数组
//模板:
//1.只要求每个子结果之和，则正向遍历(首个元素为终止点，且所获结果一般为 0 )
// #include <iostream>
// #include <stack>
// using namespace std;
// // int ans[1000000];
// int main()
// {
//     int n, sum = 0; cin >> n;
//     stack<int> sta;
//     for(int i = 1; i <= n; i++)
//     {
//         int t; cin >> t;
//         while(!sta.empty() && t >= sta.top()) sta.pop();
//         // ans[i] = sta.size();
//         sum += sta.size();
//         sta.push(t);
//     }
//     //for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';
//     cout<<sum; 
//     return 0;
// }
//2.对每个子结果有存储需求，需逆向遍历(最后一个元素为终止点，一般对应所存结果为 0)
// P5788 【模板】单调栈
//输出每个数对应的其后面找到第一个大于该数的数的编号(从1开始看)
//如序列 1 4 2 3 5, 1后面最先大于它的数为4，下标为2，则f(1)=2,同理f(4)=5
//故答案 2 5 4 5 0
//从最后一个作为 首个较高者 来看
// #include <stack>
// #include <iostream>
// using namespace std;
// int a[3000005], f[3000005];
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     stack<int> sta;
//     for(int i = n; i >= 1; i--)
//     {
//         while(!sta.empty() && a[sta.top()] <= a[i]) sta.pop();//抛出栈顶比当前数小的，切换较高者为当前数
//         f[i] = sta.empty() ? 0 : sta.top();//空栈说明前面没有较高者,即该部分序列单调不增
//         sta.push(i);//候选较高者的下标,不符合则会被抛出
//     }
//     for(int i = 1; i <= n; i++) cout<<(" "+!(i-1))<<f[i];
//     return 0;
// }



//1.POJ2559 直方图中的最大矩形
//数组模拟单调栈(若直接使用 栈stack 会TLE)
//满足单调栈使用前提：若矩形高度从左向右单调递增，则以每个矩形的高度乘以其到右边界的宽度得到一个面积，取这些面积中的最大值。
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// const int MAXN = 1e5 + 10;
// struct nd{
//     ll h, x;//记录矩形的 高度 和 横坐标
//     nd(){h = 0, x = 0;}//初始化各参数值为 0
// }a[MAXN];//模拟单调栈
// int main()
// {
//     int n;
//     while(~scanf("%d", &n), n)
//     {
//         ll ans = 0, H;
//         int top = 0;//单指针 模拟指向栈顶
//         for(int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &H);
//             if(H >= a[top].h) a[++top].h = H, a[top].x = i;//递增区间（实际上是单调不减）均入栈
//             else
//             {
//                 //以 高为 H 的矩形 为右界，对栈顶矩形计算面积，直到不能再作为右界（即栈中重新满足单调不减）
//                 while(H < a[top].h)
//                 {
//                     ans = max(ans, a[top].h * (i - a[top - 1].x - 1));//严格递增区间上，top矩形的左界必然为(top-1)矩形
//                     top--;
//                 }
//                 //右界矩形本身具有意义，自然入栈
//                 a[++top].h = H, a[top].x = i;
//             } 
//         }
//         //以 i = n + 1 的高度为 0 的矩形 为右界，计算剩余矩形面积
//         //此时宽度计算为 L = a[top - 1].x ，R = n + 1，故 width = (R - L - 1) = (n - a[top - 1].x) 
//         while(top) ans = max(ans, a[top].h * (n - a[top - 1].x)), top--;
//         printf("%lld\n", ans);
//     }    
//     return 0;
// }
//简洁版
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// const int MAXN = 1e5 + 10;
// struct nd{
//     ll h, x;
//     nd(){h = 0, x = 0;}
// }a[MAXN];
// int main()
// {
//     int n;
//     while(~scanf("%d", &n), n)
//     {
//         ll ans = 0, top = 0, H;
//         for(int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &H);
//             while(H < a[top].h) ans = max(ans, a[top].h * (i - a[top - 1].x - 1)), top--;
//             a[++top].h = H, a[top].x = i;
//         }
//         while(top) ans = max(ans, a[top].h * (n - a[top - 1].x)), top--;
//         printf("%lld\n", ans);
//     }
//     return 0;
// }
/*
假设案例
     9
     3 4 2 1 2 3 5 2 3
i= 0 1 2 3 4 5 6 7 8 9 10 (其中i=0和i=10仅为定位所用，其高度意义为0或无穷小)
解析见博客
*/



//2.发射站
//感受不同的存法带来的空间复杂度差异
//存结构体(15.9 MB)
// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int h, v, id;
// }q[1000005];
// stack<nd> sta;
// int ans[1000005];
// int main()
// {
//     untie();
//     int n, height, val, mval = 0;
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> height >> val;
//         q[i] = nd{height, val, i};
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         while(!sta.empty() && q[i].h > sta.top().h) ans[i] += q[sta.top().id].v, sta.pop();
//         if(!sta.empty() && q[i].h < sta.top().h) ans[sta.top().id] += q[i].v;
//         sta.push(q[i]);
//     }
//     for(int i = 1; i <= n; i++) mval = max(mval, ans[i]);
//     cout << mval;
//     return 0;
// }
//stack 存 id 比较好(11.5 MB)
// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int h, v;
// }q[1000005];
// stack<int> sta;
// int ans[1000005];
// int main()
// {
//     untie();
//     int n, height, val, mval = 0;
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> height >> val;
//         q[i] = nd{height, val};
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         while(!sta.empty() && q[i].h > q[sta.top()].h) ans[i] += q[sta.top()].v, sta.pop();
//         if(!sta.empty() && q[i].h < q[sta.top()].h) ans[sta.top()] += q[i].v;
//         sta.push(i);
//     }
//     for(int i = 1; i <= n; i++) mval = max(mval, ans[i]);
//     cout << mval;
//     return 0;
// }
//均存人数组(11.7 MB)
// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e6 + 5;
// stack<int> sta;
// int ans[N], h[N], v[N];
// int main()
// {
//     untie();
//     int n, height, val, mval = 0;
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> h[i] >> v[i];
//     for(int i = 1; i <= n; i++)
//     {
//         while(!sta.empty() && h[i] > h[sta.top()]) ans[i] += v[sta.top()], sta.pop();
//         if(!sta.empty() && h[i] < h[sta.top()]) ans[sta.top()] += v[i];
//         sta.push(i);
//     }
//     for(int i = 1; i <= n; i++) mval = max(mval, ans[i]);
//     cout << mval;
//     return 0;
// }



//3.Po
//答案即是划分出的区间个数
//例如 1 2 3 2 1 3
//区间操作有 [1, 6] +1 ，[2, 4] +1 ，[3, 3] + 1，[6, 6] + 2
//共4次
//对山形 1 2 4 1，层数共3层(递增区间长度为3)，则操作次数为 3，故只要获得 递增次数 即可，显然维护一个单调栈即可解决问题
// #include <iostream>
// #include <stack>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// stack<int> sta;
// int main()
// {
//     untie();
//     int n, x, cnt = 0;
//     cin >> n;
//     while(n--)
//     {
//         cin >> x;
//         while(!sta.empty() && sta.top() > x) sta.pop();
//         if(!sta.empty() && sta.top() == x) continue;
//         if(x) cnt++, sta.push(x);
//     }
//     cout << cnt;
//     return 0;
// }



//4.Patrik 音乐会的等待
//对等高者特殊记录，好好理解题意
// #include <iostream>
// #include <stack>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int h, s;//s为该人之前与他等高的人的人数(包括他自己)
// };
// stack<nd> sta;
// int main()
// {
//     untie();
//     int n, x;
//     long long ans = 0;
//     cin >> n;
//     while(n--)
//     {
//         cin >> x;
//         int cnt = 1;
//         while(!sta.empty() && x >= sta.top().h) 
//         {
//             ans += sta.top().s;
//             if(sta.top().h == x) cnt += sta.top().s;
//             sta.pop();
//         }
//         if(!sta.empty()) ans++;//栈中若还有元素，说明前面与 x 相邻的人比他高，可配对
//         sta.push(nd{x, cnt});
//     }
//     cout << ans;
//     return 0;
// }
//4 3 2 1 5 6
//2 4 1 2 2 5 1
//10
//3 2 2 2
//3 + 2 + 1 = 6










// 单调队列 是 队列中元素之间的关系具有单调性，而且，队首和队尾都可以进行出队操作，只有队尾可以进行入队操作，本质是由双端队列deque实现的。
// 对于单调队列，允许两端弹出，只允许一端插入 。【单调队列方法】实际上是【优先级队列方法】的一种优化
// 队头 ----> 队尾
// 递减队列，维护递减性，遇破坏递减性元素X，则弹出队头所有小于 x 的元素
// 递增队列，维护递增性，遇破坏递增性元素X，则弹出队头所有大于 x 的元素
// 这里递增递减是由 队头 往 队尾 看

//1.Sliding Window(滑动窗口)
// #include <cstdio>
// #include <queue>
// using namespace std;
// const int MAXN = 1e6 + 10;
// int arr[MAXN];
// int ans1[MAXN], ans2[MAXN];//存储每个窗口的最值
// deque<int> dq1, dq2;
// //dq1递减队列，获取窗口最大值；dq2递增队列，获取窗口最小值
// int main()
// {
//     int n, k, index1 = 0, index2 = 0;
//     scanf("%d%d", &n, &k);
//     for( int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     //使用第一个窗口去初始化单调队列
//     for( int i = 0; i < k; i++)
//     {
//         while(!dq1.empty() && arr[i] >= arr[dq1.back()]) dq1.pop_back();
//         while(!dq2.empty() && arr[i] <= arr[dq2.front()]) dq2.pop_front();//对称操作即可
//         dq1.push_back(i);
//         dq2.push_front(i);
//     }
//     ans1[index1++] = arr[dq1.front()];
//     ans2[index2++] = arr[dq2.back()];
//     for( int i = k; i < n; i++)
//     {
//         while(!dq1.empty() && arr[i] >= arr[dq1.back()]) dq1.pop_back();
//         while(!dq2.empty() && arr[i] <= arr[dq2.front()]) dq2.pop_front();
//         dq1.push_back(i);
//         dq2.push_front(i);
//         //判定最值是否仍包含于窗口中，若已不在则出队
//         if(dq1.front() + k <= i) dq1.pop_front();
//         if(dq2.back() + k <= i) dq2.pop_back();
//         ans1[index1++] = arr[dq1.front()];
//         ans2[index2++] = arr[dq2.back()];
//     }
//     for( int i = 0; i < index2; i++) printf(" %d" + !i, ans2[i]);//各窗口最小值
//     printf("\n");
//     for( int i = 0; i < index1; i++) printf(" %d" + !i, ans1[i]);//各窗口最大值
//     return 0;
// }
//数组模拟
// #include <cstdio>
// int a[1000000], q[1000000];
// int main()
// {
//     int n, k;
//     scanf("%d%d", &n, &k);
//     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
//     int hh = 0, tt = -1;
//     for (int i = 0; i < n; i++){
//         if(hh <= tt && q[hh] + k <= i) hh++;
//         while (hh <= tt && a[q[tt]] >= a[i]) tt--;
//         q[++tt] = i;
//         if(i + 1 >= k) printf("%d ", a[q[hh]]);//每个窗口完成操作后就能输出一次最值
//     }
//     puts("");//puts自动换行
//     hh = 0, tt = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (hh <= tt && q[hh] + k <= i) hh++;
//         while (hh <= tt && a[q[tt]] <= a[i]) tt--;
//         q[++tt] = i;
//         if (i + 1 >= k) printf("%d ", a[q[hh]]);
//     }
//     return 0;
// }



//2.Sum of Consecutive Prime Numbers
//单调队列
// #include <cstdio>
// #include <deque>
// using namespace std;
// int prime[10000] = {2};
// bool check(int x)
// {
//     for(register int i = 2; i < x; i++)
//         if(!(x % i)) return 0;
//     return 1;
// }
// int main()
// {
//     int index = 0, n;
//     for(register int i = 3; i < 10000; i++)
//         if((i & 1) && check(i)) prime[++index] = i;
//     while(~scanf("%d", &n), n)
//     {
//         int sum = 0, ans = 0, ind = -1;
//         deque<int> dq;
//         for(register int i = 0; i < 10000; i++) 
//             if(prime[i] >= n) 
//             {
//                 ind = i;
//                 break;
//             }
//         if(ind == -1) ind = index;
//         //从第一个不小于n的质数开始，若没有则从10000内的最大质数开始
//         for(register int i = ind; i >= 0; i--)
//         {
//             if(!dq.empty() && sum >= n) sum -= dq.front(), dq.pop_front();
//             dq.push_back(prime[i]);
//             sum += prime[i];
//             if(sum == n) ans++;
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }
//也可用双指针(尺取法)
// 17
// 2 3 5 7 11 13 17 19
// 2 3 5 7
//   3 5 7
//   3 5 7 11
//     5 7 11
//       7 11
//         11
//         11 13
//            13 17
//               17
// #include <cstdio>
// #include <deque>
// using namespace std;
// int prime[10000] = {2};
// bool check(int x)
// {
//     for(register int i = 2; i < x; i++)
//         if(!(x % i)) return 0;
//     return 1;
// }
// int main()
// {
//     int index = 0, n;
//     for(register int i = 3; i < 10000; i++)
//         if((i & 1) && check(i)) prime[++index] = i;
//     while(~scanf("%d", &n), n)
//     {
//         int sum = 2, ans = 0, l = 0, r = 0;
//         while(prime[l] <= n)
//         {
//             while(sum < n) sum += prime[++r];
//             ans += (sum == n);
//             sum -= prime[l++];
//         }
//         printf("%d\n", ans);
//     }
//     return 0;
// }



//3.切蛋糕
// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// deque<int> dq;//维护前缀和递增的双端队列，长度超过 m 就pop队头(存下标方便获取前缀和)
// //max(ans) = max(sum[i] - min(sum[i - m]))，所以 dq.front() 需要是当前最小的前缀和
// int sum[500005], ans = -25e7;
// int main()
// {
//     untie();
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> sum[i], sum[i] += sum[i - 1];
//     dq.push_front(0);//作为sum[0]存在
//     for(int i = 1; i <= n; i++)
//     {
//         while(!dq.empty() && i - dq.front() > m) dq.pop_front();
//         ans = max(ans, sum[i] - sum[dq.front()]);
//         while(!dq.empty() && sum[i] <= sum[dq.back()]) dq.pop_back();
//         dq.push_back(i);
//     }
//     cout << ans;
//     return 0;
// }
// 0 1 3 6 10 15
//  1 -2 3 -4 5 -6
//0 1 -1 2 -2 3 -3
















































/*七. 双指针(尺取法)*/
//1.Palindromes _easy version 
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     string str;
//     int n;
//     cin >> n;
//     while(n--)
//     {
//         cin >> str;
//         int l = 0, r = str.size() - 1, ifyes = 1;
//         while(l < r)
//         {
//             if(str[l] != str[r])
//             {
//                 ifyes = 0;
//                 break;
//             }
//             l++, r--;
//         }
//         if(ifyes) cout << "yes\n";
//         else cout << "no\n";
//     }
//     return 0;
// }



//2.Subsequence 
// #include <cstdio>
// #include <algorithm>
// int a[100005];
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         int n, s, Max = 0;
//         scanf("%d%d", &n, &s);
//         for(int i = 1; i <= n; i++) 
//         {
//             scanf("%d",&a[i]);
//             Max += a[i];
//         }
//         if(s > Max) 
//         {
//             printf("0\n");
//             continue;
//         }
//         int l = 1, r = 1, sum = a[1], len = n;
//         while(l <= r)
//         {
//             while(r < n && sum < s) sum += a[++r];
//             if(sum >= s) len = std::min(len, r - l + 1);
//             sum -= a[l++];
//         }
//         printf("%d\n", len);
//     }
//     return 0;
// }



//3.Unique Snowflakes 
//双指针(最佳)
// #include <cstdio>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;
// int a[1000005];
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         int n, len = 1, l = 1, r = 1;
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//         unordered_map<int, bool> mp{make_pair(a[1], 0)};
//         while(1)
//         {
//             while(r <= n && !mp[a[r]]) mp[a[r++]] = 1;
//             len = max(len, r - l);
//             if(l > n) break;
//             mp[a[l++]] = 0;
//         }
//         printf("%d\n", len);
//     }
//     return 0;
// }
//双指针 区间收束，但没法1好
// #include <cstdio>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;
// int a[1000005];
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         int n, len = 1, l = 1, r = 1;
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//         while(1)
//         {
//             unordered_map<int, int> mp{make_pair(a[l], l)};
//             while(r < n && !mp.count(a[r + 1])) mp[a[++r]] = r;
//             len = max(len, r - l + 1);
//             if(r == n) break;
//             r = l = mp[a[r + 1]] + 1;
//         }
//         printf("%d\n", len);
//     }
//     return 0;
// }
//非双指针 超 1s
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         int n, len = 1;
//         vector<int> v;
//         scanf("%d", &n);
//         for(int i = 1; i <= n + 1; i++)
//         {
//             int x;
//             if(i <= n) scanf("%d", &x);
//             vector<int>::iterator ind;
//             if(!v.empty() && (ind = find(v.begin(), v.end(), x)) != v.end()) 
//             {
//                 len = max(len, (int)v.size());
//                 v.erase(v.begin(), ind + 1);
//             }
//             v.push_back(x);
//         }
//         printf("%d\n", len);
//     }
//     return 0;
// }



//4.A-B 数对 
//A - C = B
//双指针
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int a[200005];
// int main()
// {
//     int n, c, x;
//     long long cnt = 0;
//     scanf("%d%d", &n, &c);
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//     sort(a, a + n);
//     int l = 0, r = 0;
//     for(int i = 0; i < n; i++)
//     {
//         while(l < n && a[l] - a[i] < c) l++;
//         while(r < n && a[r] - a[i] <= c) r++;
//         if(r > 1 && a[l] - a[i] == c && a[r - 1] - a[i] == c) cnt += r - l;//1 2 3 时要进行后两个条件的判定
//     }
//     printf("%lld", cnt);
//     return 0;
// }
//其他方法见上文



//***5.Bound Found (Hard)
// #include <cstdio>
// #include <algorithm>
// typedef long long ll;
// using namespace std;
// struct nd{
//     ll sum;
//     int id;
//     nd(){sum = 0; id = 0;}
//     bool operator <(const nd &x)const{
//         return sum < x.sum;
//     }
// }s[100005];
// ll LLabs(ll x)
// {
//     return x > 0 ? x : -x;
// }
// int main()
// {
//     int n, k, tar;
//     while(~scanf("%d%d", &n, &k), n)
//     {
//         s[0].sum = s[0].id = 0;//每次都得初始化！！！
//         for(int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &s[i].sum);
//             s[i].sum += s[i - 1].sum;
//             s[i].id = i;
//         }
//         sort(s, s + 1 + n);
//         while(k--)
//         {
//             int l = 0, r = 1, ml = 0, mr = 0;
//             ll res = 0x7FFFFFFFFFFFFFFF, ans = 0;
//             scanf("%d", &tar);
//             while(r <= n)
//             {
//                 ll tep = s[r].sum - s[l].sum;
//                 if(LLabs(s[r].sum - s[l].sum - tar) < LLabs(res - tar))
//                 {
//                     res = s[r].sum - s[l].sum;
//                     ml = s[l].id, mr = s[r].id;
//                     ans = tep;
//                 }
//                 if(tep == tar) break;
//                 if(tep < tar) r++;
//                 else l++;
//                 if(l == r) r++;
//             }
//             if(ml > mr) swap(ml, mr);
//             printf("%lld %d %d\n", ans, ml + 1, mr);
//         }
//     }
//     return 0;
// }



//6.First One 
//未完成
// #include <cstdio>
// #include <cmath>
// typedef long long ll;
// ll s[100005];
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         int n;
//         ll ans = 0;
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &s[i]);
//             s[i] += s[i - 1];
//         }
//         for(register int i = 1; i <= n; i++)
//         {
//             for(register int j = i; j <= n; j++)
//             {
//                 ll sum = s[j] - s[i - 1], res = (ll)(sum == 0 ? 0 : log2l(sum));
//                 ans += (res + 1) * (i + j);
//             }
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }



//7.Takahashi's Solitaire 
//本题存在序列尾部可以接头部形成闭环的情况，所以当满足闭环条件时用 tep 存序列头部满足题意的和，s += tep 就算完成接环
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// ll a[200005], n, m, ans, asum = 0, tep = -1;
// int main()
// {
//     scanf("%lld%lld", &n, &m);
//     for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), asum += a[i];
//     ans = asum;
//     sort(a + 1, a + 1 + n);
//     int l = 1, r = 1;
//     while(r <= n)
//     {
//         ll s = a[l];
//         while(r < n && (a[r + 1] == a[r] || a[r + 1] == (a[r] + 1) % m)) s += a[++r];
//         if(a[1] == 0) tep = s;
//         if(l > 1 && r == n && tep != -1 && a[n] == m - 1) s += tep;
//         ans = min(ans, asum - s);
//         l = ++r;
//     }
//     printf("%lld", ans);
//     return 0;
// }



//8.Good Subarrays (Easy Version) 
// #include <cstdio>
// int a[200010];
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)
//     {
//         int n;
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//         int l = 1, r = 1;
//         long long ans = 0;//极限情况下 int 必会超限
//         while(l <= n)
//         {
//             while(r <= n && a[r] >= r - l + 1) r++;
//             ans += r - l;
//             l++;
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }



//*9.binary string
//(尺取 + 贪心) || 二分
//以下只展示前者
// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int main()
// {
//     untie();
//     int T; 
//     cin >> T;
//     while(T--)
//     {
//         unordered_map<char, int> mp{{'0', 0}, {'1', 0}};
//         string s; 
//         cin >> s;
//         for(auto ch : s) mp[ch]++;
//         int len = s.size(), ans = mp['0'], tep = mp['1'], l = 0, r = 0;
//         mp['0'] = mp['1'] = 0;
//         while(l < len)//由于 删除区间 是连续的，则可尺取 剩余区间，这样遍历复杂度为O(n)
//         {
//             //贪心：剩余区间中'0'的个数(即含有'0'的代价) 与 删除区间中'1'的个数(即减去'1'的代价) 相等时为 最优解
//             while(r < len && mp['0'] != (tep - mp['1'])) mp[s[r++]]++;
//             ans = min(ans, max(mp['0'], tep - mp['1']));
//             mp[s[l++]]--;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }



//10.±1 Operation 2 
//(离线 && 尺取) || (二分 && 前缀和)
// pair<type1, type2> 默认对 first 升序，当 first 相同时才对 second 升序；
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// #define x first
// #define id second
// ll a[200010], ans[200010], sum = 0, tep = 0;
// pair<ll, int> q[200010];
// int main()
// {
//     int n, Q;
//     scanf("%d%d", &n, &Q);
//     for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
//     for(int i = 1; i <= Q; i++) scanf("%lld", &q[i].x), q[i].id = i;
//     sort(a + 1, a + 1 + n);
//     sort(q + 1, q + 1 + Q);
//     //思路：存起问题 X 并升序排序，先解决 X 小的问题，之后的问题只需要补差值即可
//     int l = 1, r = 1;
//     for(int i = 1; i <= Q; i++)
//     {
//         while(r <= n && a[r] <= q[i].x) r++;//寻找 x 与 ai 差值的正负转折点，划出转折区间
//         for(int j = l; j < r; j++)//特别地，转折区间内补差
//         {
//             sum -= a[j] - tep;//减去 前者 的获利
//             sum += q[i].x - a[j];//取 当前者 的获利
//         }
//         sum += (q[i].x - tep) * (l - 1);//补 转折区间左侧 的差值
//         sum -= (q[i].x - tep) * (n - r + 1);//补 转折区间右侧 的差值
//         tep = q[i].x;
//         ans[q[i].id] = sum;
//         l = r;
//     }
//     for(int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
//     return 0;
// }
//二分方法见 集训赛1



//11.Prefix Equality 
//WA
// #include <iostream>
// #include <set>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define x first
// #define y second
// const int MAXN = 2e2 + 10;//////////////////////////////////
// struct nd{
//     pair<int, int> que;
//     int id;
//     bool operator <(const nd &t)const{
//         return que < t.que;
//     }
// }q[MAXN];
// int a[MAXN], b[MAXN];
// bool ans[MAXN];
// int main()
// {
//     untie();
//     int n, Q; 
//     cin >> n;
//     set<int> sa, sb;

//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= n; i++) cin >> b[i];
//     cin >> Q;
//     for(int i = 1; i <= Q; i++) cin >> q[i].que.x, cin >> q[i].que.y, q[i].id = i;
//     sort(q + 1, q + 1 + Q);
//     int ra = 0, rb = 0;
//     for(int i = 1; i <= Q; i++)
//     {
//         while(ra < q[i].que.x) sa.insert(a[++ra]);
//         while(rb < q[i].que.y) sb.insert(b[++rb]);
//         ans[q[i].id] = (sa == sb);
        
//     }
//     for(int i = 1; i <= Q; i++) cout << (ans[i] ? "Yes\n":"No\n");
//     return 0;
// }

/*
问题在于：离线排序后没有单调性
5
2 1 3 4 5
1 2 3 4 5
6
1 2
2 2
3 3
4 4
5 5
1 4

1 2
1 4
*/



//12.Graveyard Design
// #include <iostream>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// typedef pair<int, int> pii;
// vector<pii> v;
// int main()
// {
//     untie();
//     ll n, sum = 1;
//     cin >> n;
//     ll l = 0, r = 1;
//     while(l * l <= n && l != r)
//     {
//         while(l <= r && sum < n) ++r, sum += r * r;
//         if(sum == n) v.push_back(pii(r, r - l));
//         l++;
//         sum -= l * l;
//     }
//     int len = v.size();
//     cout << len << '\n';
//     for(int i = 0; i < len; i++)
//     {
//         cout << v[i].second;
//         for(int j = v[i].second - 1; j >= 0; j--)
//             cout << " " << v[i].first - j;
//         cout << '\n';
//     }
//     return 0;
// }



//13.pairs
// #include <cstdio>
// #include <algorithm>
// int arr[100005];
// int main()
// {
//     int t, n, k;
//     scanf("%d", &t);
//     while(t--)
//     {
//         long long cnt = 0;
//         scanf("%d%d", &n, &k);
//         for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
//         std::sort(arr, arr + n);
//         int l = 0, r = 1;
//         while(r < n)
//         {
//             if(arr[r] - arr[l] <= k)
//             {
//                 cnt += 1LL * (r - l);
//                 r++;
//             }
//             else
//                 l++;
//         }
//         printf("%lld\n", cnt);
//     }
//     return 0;
// }



//14.String 
// #include <iostream>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// char str[1000005];
// #define id(x) (str[x] - 'a')
// int main()
// {
//     untie();
//     int T, k;
//     cin >> T;
//     while(T--)
//     {
//         long long ans = 0;
//         int vis[30];
//         memset(vis, 0, sizeof(vis));
//         cin >> str >> k;
//         int l = 0, r = 0, cnt = 0, len = strlen(str);
//         for(; l < len; l++)//选出[l, r]区间符合含 k 个不同字母，那么任意 x 属于[r, len - 1]可使得任一[l, x]满足题意,故该次答案更新加的是 r 及 r后面 的字母长度
//         {
//             while(r < len && cnt < k)
//             {
//                 vis[id(r)]++;
//                 if(vis[id(r)] == 1) cnt++;
//                 r++;
//             }
//             if(cnt == k) ans += len - r + 1;
//             vis[id(l)]--;
//             cnt -= !vis[id(l)];
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }



//15.单词背诵
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// map<string, int> mp, cnt;
// string str[100005], s;
// int main()
// {
//     untie();
//     int n, m, ans1 = 0, ans2 = 0;
//     cin >> n;
//     while(n--) cin >> s, mp[s] = 1;
//     cin >> m;
//     for(int i = 0; i < m; i++) cin >> str[i];
//     for(int r = 0, l = 0; r < m; r++)
//     {
//         if(mp[str[r]]) cnt[str[r]]++;
//         if(cnt[str[r]] == 1) ans1++, ans2 = r - l + 1;//出现新单词，长度更新，ans2直接更新(因为背诵长度优先级更高)
//         while(l <= r)//排除不用背的 和 重复的，尽量缩短长度
//         {
//             if(!mp[str[l]]) l++;
//             else if(cnt[str[l]] > 1) cnt[str[l]]--, l++;
//             else break;//遇到确实要背的，且存在性唯一
//         }
//         ans2 = min(ans2, r - l + 1);
//     }
//     cout << ans1 << '\n' << ans2;
//     return 0;
// }


























/*八. 数论分块*/
//
//1.除法向下取整求和
// #include <cstdio>
// int main()
// {
//     int t = 1000;
//     while(t--)
//     {
//         long long ans = 0;
//         int n, r;
//         scanf("%d", &n);
//         for(int l = 1; l <= n; l = r + 1)
//         {
//             r = n / (n / l);
//             ans += 1ll * (n / l) * (r - l + 1);
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }



//2.两个除法向下取整求和
// #include <cstdio>
// #include <algorithm>
// int main()
// {
//     int t = 1000;
//     while(t--)
//     {
//         long long ans = 0;
//         int n, m, r;
//         scanf("%d%d", &n, &m);
//         for(int l = 1; l <= std::min(n, m); l = r + 1)
//         {
//             r = std::min(m / (m / l), n / (n / l));
//             ans += 1ll * (n / l) * (m / l) * (r - l + 1);
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }



//3.等差数列与除法向下取整之积求和
// #include <cstdio>
// int main()
// {
//     int t = 1000;
//     while(t--)
//     {
//         long long ans = 0;
//         int n, r;
//         scanf("%d", &n);
//         for(int l = 1; l <= n; l = r + 1)
//         {
//             r = n / (n / l);
//             ans += 1ll * (n / l) * (r - l + 1) * (l + r) >> 1;
//         }// Sn = n * (a1 + an) / 2,  n = len;
//         printf("%lld\n", ans);
//     }
//     return 0;
// }



//4.数论分块之小小的变通
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int t = 100;
//     while(t--)
//     {
//         int n, k, r;
//         scanf("%d%d", &n, &k);
//         long long ans = 1ll * n * k;
//         //i > k时各项值恒为 k，此时 (k / i) = 0 ，故 l 循环到 min(n, k) 即可
//         for(int l = 1; l <= min(n, k); l = r + 1)
//         {
//             r = min(n, k / (k / l));//当 n < k 时，如 2 3，当 l == n 时，可能会导致 r >= k，但应当限制在 r <= n 上
//             ans -= 1ll * (k / l) * (l + r) * (r - l + 1) >> 1;
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }
// f(n, k)
// f(10, 7)
//i      1 2 3 4 5 6 7 8 9 10
//k % i  0 1 1 3 2 1 0 7 7 7



//5.稍显复杂的数论分块
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// const ll base = 1e9 + 7, N = 1e6 + 5;
// ll fib[N + 5] = {1, 1}, n[105];//1 1 2 3 5 8
// int main()
// {
//     int m;
//     for(int i = 2; i <= N; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % base;
//     for(int i = 1; i <= N; i++) fib[i] = (fib[i] + fib[i - 1]) % base;
//     while(~scanf("%d", &m))
//     {
//         ll nmin = N, ans = 0;
//         for(int i = 1; i <= m; i++) scanf("%lld", &n[i]), nmin = min(nmin, n[i]);
//         for(int l = 1, r; l <= nmin; l = r + 1)
//         {
//             ll res = 1;
//             r = n[1] / (n[1] / l);
//             for(int i = 1; i <= m; i++)//向右找第一个右端点
//             {
//                 r = min(1ll * r, n[i] / (n[i] / l));
//                 res = 1ll * (n[i] / l) * res % base;//存储式子右侧累乘的结果
//             }
//             ans = (ans + (fib[r] - fib[l - 1]) * res % base) % base;//fib从 L 到 R 项求和 与 连乘的乘积 的分块，说明该区块下连乘结果为定值
//         }
//         printf("%lld\n", (ans + base) % base);
//         //存在减法取 序列和，前缀和 被取余后 计算得到的一段 序列和 的值很可能会为 负
//         //而且由于编程语言对 负数 取模仍会得到 负值 ，所以先对其先 增加余数 再 取余，结果才是数学结果
//         // 4
//         // 44444 
//         // 55555
//         // 66666
//         // 77777
//         //该案例若不进行如上处理，会出现负数
//     }
//     return 0;
// }







/*九. 分治*/
/*
采用分治法解决的问题一般具有的特征如下：
1.问题的规模缩小到一定的规模就可以较容易地解决。
2.问题可以分解为若干个规模较小的模式相同的子问题，即该问题具有最优子结构性质。
3.合并问题分解出的子问题的解可以得到问题的解。
4.问题所分解出的各个子问题之间是独立的，即子问题之间不存在公共的子问题。

设计步骤：
1.划分步：把输入的问题划分为k个子问题，并尽量使这k个子问题的规模大致相同。
2.治理步：当问题的规模大于某个预定的阈值n0时，治理步由k个递归调用组成。
3.组合步：组合步把各个子问题的解组合起来，它对分治算法的实际性能至关重要，算法的有效性很大地依赖于组合步的实现。

分治法的关键是算法的组合步。究竟应该怎样合并，目前没有统一的模式，因此需要对具体问题进行具体分析，以得出比较好的合并算法。
*/
/*
快速幂
郭的板子：
int PowMod(int a, int n, int mod)
{
    int ret = 1;
    for(; n; n >>= 1, a = 1LL * a * a % mod)
        if(n & 1) ret = 1LL * ret * a % mod;
    return ret;
}

*我的板子：
//base 底数；index 指数
//线性整数快速幂：
typedef long long ntype;
ntype mod = ;
ntype quick_pow(ll base, ntype index)
{
    ntype ans = 1;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base % mod;
        base = base * base % mod;
    }
    return ans;
}
//矩阵快速幂：
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//这里 N 指最大矩形边长，n 指实际矩形边长
ntype n, k;
struct matrix{
    ntype mat[N][N];
    matrix operator *(matrix &t){
        matrix ret;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                ntype sum = 0;
                for(int k = 0; k < n; k++) 
                    sum += mat[i][k] * t.mat[k][j] % mod;
                ret.mat[i][j] = sum % mod;
            }
        return ret;
    }
}orimat;
matrix mat_quick_pow(matrix base, ntype index)
{
    matrix ans = orimat;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base;
        base = base * base;
    }
    return ans;
}
void init(){ for(int i = 0; i < N; i++) orimat.mat[i][i] = 1;}

*/



//1.快速幂
//线性快速幂
// #include <cstdio>
// typedef long long ll;
// ll a, b, mod;
// ll quick_pow(ll base, ll index)
// {
//     ll ans = 1;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base % mod;
//         base = base * base % mod;
//     }
//     return ans;
// }
// int main()
// {
//     scanf("%lld%lld%lld", &a, &b, &mod);
//     printf("%lld^%lld mod %lld=%lld", a, b, mod, quick_pow(a, b));
//     return 0;
// }
//矩阵(matrix)快速幂
//把矩阵看作数即可，对于快速幂运算，只需重载乘法运算符即可转化为线性表达
// #include <cstdio>
// typedef long long ll;
// const ll mod = 1e9 + 7, N = 110;
// ll n, k;
// struct matrix{
//     ll mat[N][N];
//     matrix operator *(matrix &t){
//         matrix ret;
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++)
//             {
//                 ll sum = 0;
//                 for(int k = 0; k < n; k++) 
//                     sum += mat[i][k] * t.mat[k][j] % mod;
//                 ret.mat[i][j] = sum % mod;
//             }
//         return ret;
//     }
// }orimat, a;
// matrix mat_quick_pow(matrix base, ll index)
// {
//     matrix ans = orimat;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base;
//         base = base * base;
//     }
//     return ans;
// }
// int main()
// {
//     //写入单位矩阵 A0 ，其与任何矩阵 X 相乘得到 X 本身(A0 的斜向右下对角线位上均为1，其余为0)
//     for(int i = 0; i < N; i++) orimat.mat[i][i] = 1;
//     scanf("%lld%lld", &n, &k);
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             scanf("%lld", &a.mat[i][j]);
//     a = mat_quick_pow(a, k);
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n; j++)
//             printf(" %lld" + !j, a.mat[i][j]);
//         puts("");
//     }
//     return 0;
// }



//2.最大子段和
//贪心\dp：
// #include <iostream>
// using namespace std;
// const int N = 2*1e5 + 1;
// int a[N], sum[N], n, res = -100 * N;
// int main()
// {
//     cin >> n;
//     for(int i = 1; i <= n; i++) 
//     {
//         cin>>a[i];
//         sum[i]=max(sum[i-1]+a[i],a[i]);//贪心，当前数大于该段前缀和时，说明该前缀和非最优解，故弃之取当前数，并重新计算前缀和
//         res=max(res,sum[i]);//取各前缀和序列中最大值
//     }
//     cout << res;
//     return 0;
// }
//分治法：
//采用分治法的思想，将该序列一分为二，分别求取这两个序列的最大子段和。
//当然最大字段和也可能跨越在这两段中，即为我们要探讨的第三种情况
// #include <iostream>
// using namespace std;
// const int MINA = -2e7 - 10;
// int n, arr[200005];
// inline int tmax(int a, int b, int c){ return (a >= b && a >= c)  ?  a  :  ((b >= a && b >= c) ? b : c);}
// int subsum(int l, int r)
// {
//     int sum = MINA, lsum = 0, rsum = 0, msum = 0;
//     if(l == r) sum = arr[l];
//     else
//     {
//         int mid = (l + r) >> 1, sl = MINA, sr = MINA, sl_tmp = 0, sr_tmp = 0;
//         //以下返回左右段
//         lsum = subsum(l, mid);//中间元素划入左区间
//         rsum = subsum(mid + 1, r);

//         //以下计算中间段
//         for(int i = mid; i >= l; i--)//左序列求最大和,由于中间段连续所有要从 mid 往 l 走
//         {
//             sl_tmp += arr[i];
//             if(sl_tmp > sl) sl = sl_tmp;
//         }
//         for(int i = mid + 1; i <= r; i++)//右序列求最大和,由于中间段连续所有要从 mid + 1 往 r 走
//         {
//             sr_tmp += arr[i];
//             if(sr_tmp > sr) sr = sr_tmp;
//         }
//         msum = sl + sr;//两者之和得到中间段和
        
//         //三种情况下的和的比较，取最大者
//         sum = tmax(lsum, rsum, msum);
//     }
//     return sum;
// }
// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> arr[i];
//     cout << subsum(0, n - 1);
//     return 0;
// }
/*
分治算法时间复杂度分析：
1.首先把一个递归的函数当做一个结点，这道题的话就非叶子结点（l==r时为叶子节点）都会产生两个子节点 -> log2n
2.结点里面可以对其L，R进行分析。实际上轴上的位置，每一个最多被访问logn次（这个logn就是树的高度）
3.在树的同一层里，数轴上的一个位置仅会被一个节点访问 -> n
O(log2n * n) = O(nlogn)
*/

//3.汉诺塔问题
// #include <cstdio>
// void move(int n, char init, char temp, char dest)
// {
//     if(n == 1) printf("1:%c->%c\n", init, dest);
//     else
//     {
//         move(n - 1, init, dest, temp);
//         printf("%d:%c->%c\n", n, init, dest);
//         move(n - 1, temp, init, dest);
//     }
// }
// int main()
// {
//     int n;
//     char a, b, c;
//     scanf("%d %c %c %c", &n, &a, &b, &c);
//     move(n, a, b, c);
//     return 0;
// }



//*4.快速排序
// https://blog.csdn.net/weixin_44915226/article/details/119535259?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167176851016800222868521%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167176851016800222868521&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-5-119535259-null-null.142^v68^control,201^v4^add_ask,213^v2^t3_control1&utm_term=c%2B%2B%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F&spm=1018.2226.3001.4187
// #include <cstdio>
// #include <algorithm>
// int arr[100000], n;
// //1.以下方便理解(慢) -- 两个函数可以合起来
// // int partition(int low, int high)
// // {
// //     int x = arr[low];//取第一个为基准元素，并提出来，故low处此时为空位，这也使得后续low指针是空位
// //     while(low < high)
// //     {
// //         while(low < high && arr[high] >= x) high--;//high指针找到第一个小于x的元素，并置于x原位置上
// //         arr[low] = arr[high];//此时high指针所在位置为空位
// //         while(low < high && arr[low] <= x) low++;//low指针找到第一个小于x的元素，并置于high位置上
// //         arr[high] = arr[low];
// //     }
// //     arr[low] = x;//最后将基准元素置于low上的空位
// //     return low;//返回最终基准位
// // }
// // int quick_sort(int low, int high)
// // {
// //     if(low < high)
// //     {
// //         int xpos = partition(low, high);//取基准元素
// //         quick_sort(low, xpos - 1);//对分割后左右两个序列分别 再分割再排序
// //         quick_sort(xpos + 1, high);
// //     }
// // }
// //2.较慢(交换方式与法1不同) -> 遇到不满足升序的两个元素就直接交换,最终基准元素置于两指针重合位
// // void quick_sort(int left, int right){
// // 	if(left >= right) return;
// // 	int i = left, j = right, base = arr[left];
// // 	while(i < j){
// // 		while(arr[j] >= base && i < j) j--;
// // 		while(arr[i] <= base && i < j) i++;
// // 		if(i < j) std::swap(arr[i], arr[j]);
// // 	}
// // 	arr[left] = arr[i];
// // 	arr[i] = base;
// // 	quick_sort(left, i - 1);
// // 	quick_sort(i + 1, right);
// // }
// //3.结合二分(极快)
// void quick_sort(int l,int r)//应用二分思想
// {
//     int mid = arr[((l + r) >> 1)];//中间数
//     int i = l, j = r;
//     do{
//         while(arr[i] < mid) i++;//查找左半部分比中间数大的数
//         while(arr[j] > mid) j--;//查找右半部分比中间数小的数
//         if(i <= j)//如果有一组不满足排序条件（左小右大）的数
//         {
//             std::swap(arr[i], arr[j]);//交换
//             i++, j--;
//         }
//     }while(i <= j);//这里注意要有=
//     if(l < j) quick_sort(l, j);//递归搜索左半部分
//     if(i < r) quick_sort(i, r);//递归搜索右半部分
// }
// int main()
// {
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     quick_sort(0, n - 1);
//     for(int i = 0; i < n; i++) printf(" %d" + !i, arr[i]);
//     return 0;
// }



//*5.逆序对(归并排序)
//归并操作指的是将两个顺序序列合并成一个顺序序列的方法。
// #include <cstdio>
// const int N = 5e5 + 5;
// int n, arr[N], tmp[N];
// long long cnt = 0;
// void merge(int l, int r)
// {
//     if(l >= r) return;
//     int mid = ((l + r) >> 1);
//     int posl = l, pos_tmp = l, posr = mid + 1;//posr指向右侧区间第一个元素
//     merge(l, mid);//排序左侧区间(中间元素归入左侧)
//     merge(mid + 1, r);//排序右侧区间
//     while(posl <= mid && posr <= r)
//     {
//         if(arr[posl] <= arr[posr]) tmp[pos_tmp++] = arr[posl++];//置入小者
//         else tmp[pos_tmp++] = arr[posr++], cnt += mid - posl + 1;
//     }
//     //左右区间剩余元素都分别存入tmp中（因为最终会有一侧留下一些较大者没进数组）
//     while(posl <= mid) tmp[pos_tmp++] = arr[posl++];
//     while(posr <= r) tmp[pos_tmp++] = arr[posr++];
//     //将排序后数组存入原数组中
//     for(int i = l; i <= r; i++) arr[i] = tmp[i];
// }
// int main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
//     merge(1, n);
//     printf("%lld", cnt);
//     return 0;
// }
/*
如序列 8 3 2 6 7 1 5 4
递归二分划分区间最终变成两两一对
[8 3]  [2 6]  [7 1]  [5 4]
分别排序(升序)
[3 8]  [2 6]  [1 7]  [4 5]
两两合并：用两个指针，比如 [3 8]  [2 6]，用指针 l1 指向 3 ， l2 指向 2 ，小的一方即 l2 存入数组 并 l2++ ，得到[2]；
                          此时3 < 6，得到[2 3]；此时6 < 8得到[2 3 6]，然后后面循环补入 8 得到 [2 3 6 8]
即[2 3 6 8]  [1 4 5 7]
同理类推得到最终序列 [1 2 3 4 5 6 7 8]
*/



//6.Fractal
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// char map[1024][1024];//以左上角为基点，分形5个区块
// void setpic(int x, int y, int n)
// {
//     if(n == 1) 
//     {
//         map[x][y] = 'X';
//         return;
//     }
//     int k = (int)pow(3.0, n - 2);//基于上一个degree的图形长度
//     setpic(x, y, n - 1);            //左上角
//     setpic(x + 2*k, y, n - 1);      //右上角
//     setpic(x + k, y + k, n - 1);    //中间
//     setpic(x, y + 2*k, n - 1);      //左下角
//     setpic(x + 2*k, y + 2*k, n - 1);//右下角
// }
// int main()
// {
//     int n;
//     while(~scanf("%d", &n), n + 1)
//     {
//         int size = (int)pow(3.0, n - 1);
//         memset(map, 32, sizeof(map));
//         setpic(0, 0, n);
//         for(int i = 0; i < size; i++)
//         {
//             for(int j = 0; j < size; j++)
//                 printf("%c", map[i][j]);
//             puts("");
//         }
//         printf("-\n");
//     }
//     return 0;
// }



//*7.很大的数组的第k小
//实际上有函数nth_element(a,a+k,a+len)  -> O(n)，函数意义为将第 k 小元素放在a[k]上，但不知道为什么会WA
// maxn 数量级为 1e7，对于O(nlogn)的排序算法(sort)会超时(该复杂度下 1s 只能操作数量级 <= 1e6的数据)，故寻求下一级复杂度O(n) ( <= 1e7)
//快排最差情况为 O(n^2)，但此时 n 并不大（序列未达到取模点），所以平均情况几乎可以认为是 O(n)
// #include <cstdio>
// const int mod = 1e9 + 7, maxn = 5e7 + 5;
// int n, m, k, arr[maxn];
// int quick_search(int l, int r, int k)
// {
//     if(l >= r) return arr[l];
//     int low = l, high = r, x = arr[l];
//     while(low < high)
//     {
//         while(low < high && arr[high] >= x) high--;//这样就能找到取模点后比arr[0]还小的元素
//         arr[low] = arr[high];
//         while(low < high && arr[low] <= x) low++;
//         arr[high] = arr[low];
//     }
//     arr[low] = x;//最终low左侧元素均 <= x，如果low指针正好指向第(k - 1)位置元素即为ans,此时low - l == k - 1
//     if(low - l == k - 1) return arr[low];
//     //若low - l < k - 1说明左侧区间较小元素不够，留下排好的low的左侧区间并计入已寻得的项数，继续往low右侧寻找小元素
//     //若low - l > k - 1说明low左侧区间条件充分，抛弃右侧区间即可，从 (l, low] 找剩余第k项  
//     if(low - l < k - 1) return quick_search(low + 1, r, k - 1 - (low - l));
//     else return quick_search(l, low, k);//当 k > 取模点时用到
// }
// int main()
// {
//     while(~scanf("%d%d%d", &n, &m, &k))
//     {
//         arr[0] = m;
//         for(int i = 1; i < n; i++) arr[i] = 1LL * m * arr[i- 1] % mod;
//         printf("%d\n", quick_search(0, n - 1, k));
//     }
//     return 0;
// }
//nth_element法
// #include <cstdio>
// #include <algorithm>
// const int mod = 1e9 + 7, maxn = 5e7 + 5;
// int n, m, k, arr[maxn];
// int main()
// {
//     while(~scanf("%d%d%d", &n, &m, &k))
//     {
//         arr[0] = m;
//         for(int i = 1; i < n; i++) arr[i] = 1LL * m * arr[i- 1] % mod;
//         std::nth_element(arr, arr + k - 1, arr + n);
//         printf("%d\n", arr[k - 1]);
//     }
//     return 0;
// }



//8.Fibonacci( 矩阵公式 -> O(logn) )
//1s，本题 maxn = 1e9，而O(n) -> 1e7 ~ 1e8 故必须降级到 O(logn) 求解，题意已给出方法
// #include <cstdio>
// typedef int ntype;
// const ntype mod = 1e4, N = 2;
// ntype n, k;
// struct matrix{
//     ntype mat[N][N];
//     matrix operator *(matrix &t){
//         matrix ret;
//         for(int i = 0; i < N; i++)
//             for(int j = 0; j < N; j++)
//             {
//                 ntype sum = 0;
//                 for(int k = 0; k < N; k++) 
//                     sum += 1LL * mat[i][k] * t.mat[k][j] % mod;
//                 ret.mat[i][j] = sum % mod;
//             }
//         return ret;
//     }
// }orimat;
// matrix mat_quick_pow(matrix base, ntype index)
// {
//     matrix ans = orimat;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base;
//         base = base * base;
//     }
//     return ans;
// }
// void init(){ for(int i = 0; i < N; i++) orimat.mat[i][i] = 1;}
// int main()
// {
//     init();
//     while(~scanf("%d", &n), n + 1)
//     {
//         matrix fib1 = {{{1, 1}, {1, 0}}};
//         printf("%d\n", mat_quick_pow(fib1, n).mat[0][1]);
//     }
//     return 0;
// }



//9.地毯填补问题
//大问题分为四个区域，最小问题为 2 X 2 问题，其中最小问题需要探讨是否有 公主点(特殊点)，来确定地毯形状
//唯一公主点 只会在其中一个区域，我们以 唯一公主点 确认中心地毯(x, y)的对角方位，
//得到(x, y)后，其所占用的点就是其他三个区域的特殊点(视为公主点)，可以通过 2X2 -> 4X4 -> n*n 递推得到
//对4x4方格，给每个2×2的格子都增加一个特殊点，正中间旁边的3个白色格子都填上同一种颜色，然后再分别处理三个2×2的格子就行了
//注意，最中间留空处区域的方向就是公主点所在区域
// #include <cstdio>
// int k, n = 1;
// #define pf(a, b, id) {printf("%d %d %d\n", a, b, id);}
// void dfs(int x1, int y1, int x2, int y2, int X, int Y)
// {
//     if(x2 - x1 + 1 == 2 && y2 - y1 + 1 == 2)//此时为最小问题 2x2 问题，依据特殊点位置即可输出对应方案
//     {
//         if(X == x1 && Y == y1) pf(x2, y2, 1);//特殊点位置在左上角，对角使用地毯方案 1
//         if(X == x1 && Y == y2) pf(x2, y1, 2);//右上角
//         if(X == x2 && Y == y1) pf(x1, y2, 3);//左下角
//         if(X == x2 && Y == y2) pf(x1, y1, 4);//右下角
//         return;
//     }
//     int x = ((x2 - x1 + 1) >> 1) + (x1 - 1);//取中点(x, y)分治
//     int y = ((y2 - y1 + 1) >> 1) + (y1 - 1);
//     //据公主点方位分治
//     if(X <= x && Y <= y)//公主位于左上区域
//     {
//         pf(x + 1, y + 1, 1);
//         dfs(x1, y1, x, y, X, Y);//左上区域，亦是公主点区域
//         //以(x+1, y+1)点的地毯方案，其上三个点分别视作特殊点，继续分治其他三个区域，每个区域都用左上角点与右下角点框选
//         dfs(x + 1, y1, x2, y, x + 1, y);//左下区域
//         dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);//右下区域
//         dfs(x1, y + 1, x, y2, x, y + 1);//右上区域
//     }
//     if(X <= x && Y > y)//右上
//     {
//         pf(x + 1, y, 2);
//         dfs(x1, y + 1, x, y2, X, Y);//右上区域，公主点区域
//         dfs(x1, y1, x, y, x, y);//左上区域
//         dfs(x + 1, y1, x2, y, x + 1, y);//左下区域
//         dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);//右下区域
//     }
//     if(X > x && Y <= y)//左下
//     {
//         pf(x, y + 1, 3);
//         dfs(x + 1, y1, x2, y, X, Y);//左下，公主点
//         dfs(x1, y1, x, y, x, y);//左上区域
//         dfs(x1, y + 1, x, y2, x, y + 1);//右上区域
//         dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);//右下区域
//     }
//     if(X > x && Y > y)//右下
//     {
//         pf(x, y, 4);
//         dfs(x + 1, y + 1, x2, y2, X, Y);//右下，公主点        
//         dfs(x1, y1, x, y, x, y);//左上区域
//         dfs(x1, y + 1, x, y2, x, y + 1);//右上区域
//         dfs(x + 1, y1, x2, y, x + 1, y);//左下区域
//     }
// }
// int main()
// {
//     int X, Y;
//     scanf("%d%d%d", &k, &X, &Y);
//     n <<= k;
//     dfs(1, 1, n, n, X, Y);
//     return 0;
// }




















/*十. 并查集 优先队列*/
//理解模板：
// #include <cstdio>
// #include <iostream>
// using namespace std;
// const int N = 1e4;
// int ds[N];
// void init_ds(int n)
// { 
//     for(int i = 1; i <= n; i++)
//         ds[i] = i;
// }
// int find_ds(int x)
// { 
//     return x == ds[x] ? x : find_ds(ds[x]);
// }
// void merge_ds(int x, int y)
// {
//     if((x = find_ds(x)) != (y = find_ds(y)))
//         ds[x] = ds[y];
// }
// int main()
// {
//     int n; cin >> n;
//     init_ds(n);
//     int x = 2, y = 3;
//     find_ds(x);
//     merge_ds(x, y);
//     return 0;
// }

//非权值优化模板：
// #include <cstdio>
// #include <iostream>
// using namespace std;
// const int N = 1e4;
// int ds[N];
// void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}

//权值优化模板：
// #include <cstdio>
// #include <iostream>
// using namespace std;
// const int N = 1e4;
// int ds[N], d[N];
// void init_set(int n)
// { 
//     for(int i = 1; i <= n; i++)
//         ds[i] = i, d[i] = 0;
// }
// int find_set(int x)
// {
//     if(x != ds[x])
//     {
//         int t = ds[x];
//         ds[x] = find_set(ds[x]);
//         d[x] += d[t];//权值计算需符合题意要求，此处以加和权值为例
//     }
//     return ds[x];
// }
// void merge_set(int x, int y)//合并操作需符合题意要求
// {
//     int rootx = find_set(x), rooty = find_set(y);
//     if(rootx == rooty)
//     {

//     }
//     else
//     {

//     }
// }



//1.并查集 模板题
// #include <cstdio>
// const int N = 2e5 + 10;
// int ds[N];
// void init_set(int n)
// {
//     for(int i = 1; i <= n; i++)
//         ds[i] = i;
// }
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }
// void merge_set(int x, int y)
// {
//     if((x = find_set(x)) != (y = find_set(y)))  ds[x] = ds[y];
// }
// int main()
// {
//     init_set(N - 10);
//     int n, m;
//     scanf("%d%d", &n, &m);
//     while(m--)
//     {
//         int op, x, y;
//         scanf("%d%d%d", &op, &x, &y);
//         if(op - 1) printf("%c\n", find_set(x) == find_set(y) ? 'Y':'N');
//         else merge_set(x, y);
//     }
//     return 0;
// }
 


//2.修复公路
//虽然sort慢，但毕竟数据量不大，故可以先离线排序
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// const int N = 1e5 + 10;
// struct nd{
//     int x, y, t;
//     bool operator <(const nd &k)const{
//         return t < k.t;
//     }
// }q[N];
// int ds[N], n, m;
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= m; i++) scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].t), ds[i] = i;
//     sort(q + 1, q + 1 + m);
//     for(int i = 1; i <= m; i++)//n 个村庄只需 n - 1 次连通即可
//     {
//         int rx = find_set(q[i].x), ry = find_set(q[i].y);
//         if(rx != ry) ds[rx] = ds[ry], n--;
//         if(n == 1)
//         {
//             printf("%d\n", q[i].t);
//             return 0;
//         }
//     }
//     printf("-1\n");
//     return 0;
// }



//3.亲戚(板子题)
// #include <cstdio>
// const int N = 5e3 + 10;
// int n, m, p, ds[N];
// void init_set(int n)
// {
//     for(int i = 1; i <= n; i++) ds[i] = i;
// }
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }
// void merge_set(int x, int y)
// {
//     if((x = find_set(x)) != (y = find_set(y)))
//         ds[x] = ds[y];
// }
// int main()
// {
//     scanf("%d%d%d", &n, &m, &p);
//     init_set(n);
//     for(int i = 1; i <= m; i++)
//     {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         merge_set(x, y);
//     }
//     while(p--)
//     {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         if(find_set(x) == find_set(y)) printf("Yes\n");
//         else printf("No\n");
//     }
//     return 0;
// }



//4.一中校运会之百米跑(集合元素不是数值时，而是字符串)
// #include <iostream>
// #include <string>
// #include <unordered_map>//数据量为2e4，理应不会被卡常，用无序map查找最快
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e4 + 10;
// int n, m, k;
// unordered_map<string, string> ds;
// string find_strset(string x)
// {
//     return x == ds[x] ? x : (ds[x] = find_strset(ds[x]));
// }
// void merge_strset(string x, string y)
// {
//     string rx = find_strset(x), ry = find_strset(y);
//     if(rx != ry) ds[rx] = ds[ry];
// }
// int main()
// {
//     untie();
//     string str, x, y;
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) cin >> str, ds[str] = str;
//     while(m--)
//     {
//         cin >> x >> y;
//         merge_strset(x, y);
//     }
//     cin >> k;
//     while(k--)
//     {
//         cin >> x >> y;
//         if(find_strset(x) == find_strset(y)) cout << "Yes.\n";
//         else cout << "No.\n";
//     }
//     return 0;
// }



//5.朋友
// #include <cstdio>
// const int N = 2e4 + 100;
// int n, m, p, q, ds[N], base = 1e4;//9999 10001
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }
// void merge_set(int x, int y)
// {
//     if((x = find_set(x)) != (y = find_set(y)))
//         ds[x] = ds[y];
// }
// int main()
// {
//     int p1 = base - 1, p2 = base + 1, cnt1 = 0, cnt2 = 0;
//     scanf("%d%d%d%d", &n, &m, &p, &q);
//     for(int i = 0; i < N; i++) ds[i] = i;
//     q += p;
//     while(q--)
//     {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         merge_set(x + base, y + base);
//     }
//     p1 = find_set(p1), p2 = find_set(p2);//初始p1,p2很可能不作为根节点，故先找含p1\p2的根节点
//     for(int i = 0; i < N; i++)
//     {
//         int rt = find_set(i);
//         if(rt == p1) cnt1++;
//         else if(rt == p2) cnt2++;
//     }
//     printf("%d\n", cnt1 > cnt2 ? cnt2 : cnt1);
//     return 0;
// }



//6.家谱
// #include <iostream>
// #include <string>
// #include <unordered_map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// unordered_map<string, string> ds;
// string find_strset(string x)
// {
//     return x == ds[x] ? x : (ds[x] = find_strset(ds[x]));
// }
// void merge_strset(string x, string y)
// {
//     if((x = find_strset(x)) != (y = find_strset(y)))
//         ds[x] = ds[y];
// }
// int main()
// {
//     untie();
//     char op;
//     string str, anc;
//     while(!(cin >> str).eof(), str != "$")
//     {
//         op = str[0], str = str.substr(1);
//         if(!ds.count(str)) ds[str] = str;
//         switch(op)
//         {
//             case '#': 
//                 anc = str;//存祖先
//                 break;
//             case '+':
//                 merge_strset(str, anc);
//                 break;
//             case '?':
//                 cout << str << " " << find_strset(str) << '\n';
//                 // cout << str << " " << ds[str] << '\n'; //*误区：这里不能直接用 ds[str] 得到根节点
//                 // 因为 高度为 2 的树 与 其他树根节点 合并时，其自身已经压缩好了，但是合并过去后高度变成3，
//                 // 对于另一棵树来说，其自身也已经压缩好了，但是合并后并没有进行压缩，所以这类情况还是需要查询才可得到根节点
//                 // 因此合并时的压缩除非是 高度为1 的根节点 与其他根节点相连得到高度为2的压缩树，否则都是高度为3的未压缩树
//                 break;
//         }
//     }
//     return 0;
// }



//以下均为优先队列
//7.合并果子 / [USACO06NOV] Fence Repair G
// #include <cstdio>
// #include <queue>
// #include <vector>
// #include <functional>
// using namespace std;
// priority_queue<int, vector<int>, greater<int>> q;
// int main()
// {
//     int n, x, sum = 0;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) 
//     {
//         scanf("%d", &x);
//         q.push(x);
//     }
//     while(q.size() > 1)//每次取两个最小堆合并即可
//     {
//         int s = q.top(); q.pop();
//         s += q.top(); q.pop();
//         sum += s;
//         q.push(s);
//     }
//     printf("%d\n", sum);
//     return 0;
// }



//8.世界杯
// #include <cstdio>
// #include <queue>
// using namespace std;
// priority_queue<int> q1, q2, q3, q4;
// int main()
// {
//     int k, d, m, f, q, tmp;
//     scanf("%d%d%d%d", &k, &d, &m, &f);
//     while(k--) scanf("%d", &tmp), q1.push(tmp);
//     while(d--) scanf("%d", &tmp), q2.push(tmp);
//     while(m--) scanf("%d", &tmp), q3.push(tmp);
//     while(f--) scanf("%d", &tmp), q4.push(tmp);//q2 - q3 - q4
//     scanf("%d", &q);
//     while(q--)
//     {
//         int a, b, c;
//         double sum = q1.top();
//         q1.pop();
//         scanf("%d%d%d", &a, &b, &c);
//         while(a--) sum += q2.top(), q2.pop();
//         while(b--) sum += q3.top(), q3.pop();
//         while(c--) sum += q4.top(), q4.pop();
//         sum /= 11.0;
//         printf("%.2lf\n", (long long)(sum * 100 + 0.5) / 100.0);
//     }
//     return 0;
// }



//9.序列合并
//数学方法
// i * j >= n 就不可能是前 n 小的答案(设i，j都从0开始)
// #include <cstdio>
// #include <queue>
// #include <vector>
// #include <functional>
// using namespace std;
// typedef long long ll;
// int a[100005], b[100005];
// priority_queue<ll, vector<ll>, greater<ll> > q;
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//     for(int i = 0; i < n; i++) scanf("%d", &b[i]);
//     for(int i = 0; i < n; i++)
//         for(int j = 0; i * j < n && j < n; j++) 
//             q.push(1LL * a[i] + 1LL * b[j]);
//     for(int i = 0; i < n; i++)
//         printf(" %lld" + !i, q.top()), q.pop();
//     return 0;
// }
//优先队列方法
//把 N^2 个和看成 N 个升序队列
// a[1] + b[1] -> a[1] + b[2] -> ... -> a[1] + b[N]
// a[2] + b[1] -> a[2] + b[2] -> ... -> a[2] + b[N]
// ...
// a[N] + b[1] -> a[N] + b[2] -> ... -> a[N] + b[N]
//维护一个堆，堆中初始含有N个队列的第一个元素
//经 小值优先排序 后，每次取出堆中的最小值，若这个最小值来自于第k个队列，那么，就将第k个队列的下一个元素放入堆中
//这样就能保证每次取得的最小值确实是当前所得最小值
// #include <cstdio>
// #include <queue>
// #include <vector>
// #include <functional>
// using namespace std;
// typedef pair<int, int> pii;
// #define v first
// #define id second
// const int maxn = 1e5 + 5;
// int a[maxn], b[maxn], vis[maxn];
// priority_queue<pii, vector<pii>, greater<pii> > q;//两数相和不会超int，此时优先队列中存的是 N 个队列中各自的最小值
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) scanf("%d", &b[i]);
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]), q.push(pii(a[i] + b[0], i));
//     for(int i = 0; i < n; i++)
//     {
//         int pos = q.top().id;
//         printf(" %d" + !i, q.top().v), q.pop();
//         q.push(pii(a[pos] + b[++vis[pos]], pos));
//     }
//     return 0;
// }



//10.Cow Dance Show S
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <functional>
// using namespace std;
// typedef pair<int, int> pii;
// int n, t, arr[10005];
// priority_queue<int, vector<int>, greater<int> > q;
// //维护一个存储 牛表演结束时间点 的栈，时间点越早，越近栈顶，越早出队
// //在到达栈顶牛时间点才能进队，所以此时进队说明其结束时间点是 （栈顶牛表演耗时 + 自身表演耗时）即 top + arr[i]
// //那么最终栈底最晚结束表演的牛，其时间点即为答案
// bool check(int k)
// {
//     int ans = 0, tmp;
//     for(int i = 0; i < k; i++) q.push(arr[i]);
//     for(int i = k; i < n; i++)
//     {
//         tmp = q.top(); q.pop();
//         q.push(tmp + arr[i]);
//     }
//     for(; q.size(); q.pop()) ans = q.top();
//     return ans <= t;
// }
// int main()
// {
//     scanf("%d%d", &n, &t);
//     for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     int l = 1, r = n, ans = 0;
//     while(l <= r)
//     {
//         int mid = (l + r) >> 1;
//         if(check(mid)) r = mid - 1, ans = mid;
//         else l = mid + 1;
//     }
//     printf("%d\n", ans);
//     return 0;
// }

























/*十一. 线性DP*/

//更多题目与题解:https://github.com/CSGrandeur/s-1problem1day1ac/discussions/552
//1.Bone Collector(0/1 背包问题)
//dp[i][j] 表示 容量为 j 的背包装前 i 个物品的最大价值
//只有两种操作：装与不装第 i 个物品
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i])
//递推版：
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1024;
// int T, n, v, dp[N][N], val[N], vol[N];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         memset(dp, 0, sizeof(dp));
//         cin >> n >> v;
//         for(int i = 1; i <= n; i++) cin >> val[i];
//         for(int i = 1; i <= n; i++) cin >> vol[i];
//         for(int i = 1; i <= n; i++)
//             for(int j = 0; j <= v; j++)//j = 0 表示空背包
//             {
//                 if(vol[i] > j) dp[i][j] = dp[i - 1][j];//第 i 个物品装不下，只能延续上一个状态
//                 else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i]);//能装就取两种情况的最佳者
//             }
//         cout << dp[n][v] << '\n';
//     }
//     return 0;
// }
//记忆化版：
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1024;
// int T, n, v, dp[N][N], val[N], vol[N];
// int solve(int i, int j)
// {
//     if(!i) return 0;
//     if(dp[i][j]) return dp[i][j];
//     int res;
//     if(vol[i] > j) res = solve(i - 1,j);
//     else res = max(solve(i - 1,j), solve(i - 1,j- vol[i]) + val[i]);
//     return dp[i][j] = res;
// }
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         memset(dp, 0, sizeof(dp));
//         cin >> n >> v;
//         for(int i = 1; i <= n; i++) cin >> val[i];
//         for(int i = 1; i <= n; i++) cin >> vol[i];
//         cout << solve(n, v) << '\n';
//     }
//     return 0;
// }
//以下为压缩空间的技巧：
//*滚动数组(覆盖中间转移状态，只输出结果，但不能输出转移方案)
//1.交替滚动
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1024;
// int T, n, v, dp[2][N], val[N], vol[N];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         memset(dp, 0, sizeof(dp));
//         cin >> n >> v;
//         for(int i = 1; i <= n; i++) cin >> val[i];
//         for(int i = 1; i <= n; i++) cin >> vol[i];
//         for(int i = 1; i <= n; i++)
//             for(int j = 0; j <= v; j++)//dp[i][] 只与 dp[i - 1][] 有关，故只需要两行数组复用即可
//             {
//                 //这里也可以逆序遍历至 vol[i]，省去判断
//                 if(vol[i] > j) dp[i & 1][j] = dp[(i & 1) ^ 1][j];//(i & 1) ^ 1 即 i & 1 与 1 异或, i & 1 表示新状态，(i & 1) ^ 1 表示旧状态
//                 else dp[i & 1][j] = max(dp[(i & 1) ^ 1][j], dp[(i & 1) ^ 1][j - vol[i]] + val[i]);
//             }
//         cout << dp[n & 1][v] << '\n';
//     }
//     return 0;
// }
//*2.自我滚动(重点是最后一维的逆向遍历，防止覆盖有用的旧状态)
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1024;
// int T, n, v, dp[N], val[N], vol[N];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         memset(dp, 0, sizeof(dp));
//         cin >> n >> v;
//         for(int i = 1; i <= n; i++) cin >> val[i];
//         for(int i = 1; i <= n; i++) cin >> vol[i];
//         for(int i = 1; i <= n; i++)
//             for(int j = v; j >= vol[i]; j--)// vol[i] > j 时装不下，当作旧状态保留即可
//                 dp[j] = max(dp[j], dp[j - vol[i]] + val[i]);
//         cout << dp[v] << '\n';
//     }
//     return 0;
// }



//2.Common Subsequence
//三种情况：01 10 11
//dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 10;
// int dp[N][N];
// int main()
// {
//     untie();
//     string a, b;
//     while(cin >> a >> b)//*这里cin会自动判断是否到达EOF，所以不能用 !(cin >> a >> b).eof() 来判断是否到达EOF，会WA的
//     {
//         memset(dp, 0, sizeof dp);
//         a = '*' + a, b = '*' + b;
//         int alen = a.size(), blen = b.size();
//         for(int i = 1; i < alen; i++)
//             for(int j = 1; j < blen; j++)
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
//             }
//         cout << dp[alen - 1][blen - 1] << '\n';
//     }
//     return 0;
// }
//相同方法，不同写法，耗时从 32ms 优化至 0ms
// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int main()
// {
//     untie();
//     string a, b;
//     while(cin >> a >> b)
//     {
//         int alen = a.size(), blen = b.size();
//         vector<vector<int> > dp(alen + 5, vector<int>(blen + 5, 0));
//         for(int i = 0; i < alen; i++)
//             for(int j = 0; j < blen; j++)
//             {
//                 if(a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
//                 else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
//             }
//         cout << dp[alen][blen] << '\n';
//     }
//     return 0;
// }



//*3.Longest Ordered Subsequence(最经典问题 LIS - Longest  Increasing Subsequence - 最长上升子序列)
//动规方法 - O(n^2)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 10;
// int n, res = 0, arr[N], dp[N];
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> arr[i];
//     for(int i = 1; i <= n; i++)//第 i 个作为最大子序列的最后一个元素
//     {
//         dp[i] = 1;
//         for(int j = 1; j < i; j++)
//             if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);//dp[j] + 1 即取前 j 个最长子序列加上第 i 个元素
//         res = max(res, dp[i]);
//     }
//     cout << res;
//     return 0;
// }
//* 二分 + 贪心(反链构造法) - O(nlogn) - 该写法与第 4 题相比较好 
// 这样构造出 cnt 个非升序集合（即：反链）,得到的不是LIS,也不是实际连续有序的序列，而是 各反链最小值的升序集合 -- 最长升序链,详情第 4 题
// 当然，LIS长度 = 最长升序链长度，尽管内容很可能不相同
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 10;
// int n, x, cnt = 1, lis[N];
// int main()
// {
//     untie();
//     cin >> n;
//     cin >> lis[1];
//     for(int i = 2; i <= n; i++)
//     {
//         cin >> x;
//         if(x > lis[cnt]) lis[++cnt] = x;//严格递增, >
//         else *lower_bound(lis + 1, lis + 1 + cnt, x) = x;
//     }
//     cout << cnt;
//     return 0;
// }
//树状数组优化 - O(nlogn)





//4.最少拦截系统(LIS问题)
//作出散点图，连接所有升序链，最长升序链长度为 k，则拦截系统至少要有 k 个，否则至少会有一个拦截系统截取到最长升序链中至少 2 个导弹
//容易证得最长升序链长度 k，就是拦截系统最少个数
/*
反链：非升序集合，如 9 8 389 207 155 300 299 170 158 65 --> {8}、{389，207，155，65}、{300，299，170，158} --> 三条反链
每个集合的最小元素相集合起来形成一条升序链 {8, 65, 158}，若有新元素加入，由升序链判断 延长 或 更新升序链头(即该反链最小元素)
那么 最长升序链的长度 就 代表着 单调不增子序列的总个数，且 LIS长度 = 最长升序链长度， 但内容不一定相同
解决过程：
—> {8} // 初始状态，a数组的值：[8], k=1
—> {8} 、{389} // 与8构成升序链，a数组的值：[8, 389], k=2
—> {8} 、{389，207} // 与8构成升序链，a数组的值：[8, 207], k=2
—> {8} 、{389，207，155} // 与8构成升序链，a数组的值：[8, 155], k=2
—> {8} 、{389，207，155} 、{300} // 与207、155构成升序链，a数组的值：[8, 155, 300], k=3
—> {8} 、{389，207，155} 、{300，299} // 与207、155构成升序链，a数组的值：[8, 155, 299], k=3
—> {8} 、{389，207，155} 、{300，299，177} // 与155构成升序链，a数组的值：[8, 155, 177], k=3
—> {8} 、{389，207，155} 、{300，299，177，158} // 与155构成升序链，a数组的值：[8, 155, 158], k=3
—> {8} 、{389，207，155， 65} 、{300，299，177，158} // 与8构成升序链，a数组的值：[8, 65, 158], k=3
*/
//dp
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 10;
// int n, arr[N];
// int main()
// {
//     untie();
//     while(cin >> n)
//     {
//         int res = 0;
//         vector<int> dp(n + 5, 0);
//         for(int i = 1; i <= n; i++) cin >> arr[i];
//         for(int i = 1; i <= n; i++)
//         {
//             dp[i] = 1;
//             for(int j = 1; j < i; j++)
//                 if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
//             res = max(res, dp[i]);
//         }
//         cout << res << "\n";
//     }
//     return 0;
// }
//二分 + 贪心(写法与上面有点不同)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 10, MAXH = 3e4;
// int n, a[N];
// int main()
// {
//     untie();
//     while(cin >> n)
//     {
//         int x, len = 0;//最长升序链的长度 - 1
//         vector<int> lis(n + 1, MAXH);//维护得到最长升序链(区别于连续的LIS)
//         for(int i = 0; i < n; i++)
//         {
//             cin >> x;
//             int pos = lower_bound(lis.begin(), lis.begin() + n, x) - lis.begin();
//             lis[pos] = x;
//             len = max(len, pos);
//         }
//         cout << ++len << "\n";
//     }
//     return 0;
// }


//线段树 -- O(nlogn) -- 最快















//5.编辑距离
//dp[i][j]定义为字符串A 1~i子串转换为 B 1~j子串的最少操作数
//将A转换至B，现对A操作
//状态转移对象是 A 串的第 i 个字符 ca 和 B串的第 j 个字符 cb
//删除ca dp[i - 1][j] + 1 ; 
//插入cb使得两个子串尾部相同，此时相当于删除cb，延续 j - 1 状态即可 dp[i][j - 1] + 1
//若ca!=cb, 替换 ca 为 cb，相当于同时删除 ca 和 cb dp[i - 1][j - 1] + 1
//若ca==cb, dp[i - 1][j - 1]
/*更好的解答：
字符串A("xyzab")和字符串B("axyzc")，问至少经过多少步操作可以把A变成B。

我们还是从两个字符串的最后一个字符来考察即'b'和'c'。显然二者不相同，那么我们有以下三种处理办法：
(1)增加：在A末尾增加一个'c'，那么A变成了"xyzabc"，B仍然是"axyzc"，由于此时末尾字符相同了，那么就变成了比较"xyzab"和"axyz"的距离，即dp(xyzab,axyzc) = dp(xyzab,axyz) + 1。
   可以写成 dp(i,j) = dp(i,j - 1) + 1。表示下次比较的字符串B的长度减少了1，而加1表示当前进行了一次字符的操作。

(2)删除：删除A末尾的字符'b'，考察A剩下的部分与B的距离。即dp(xyzab,axyzc) = dp(xyza,axyzc) + 1。
   可以写成dp(i,j) = dp(i - 1,j) + 1。表示下次比较的字符串A的长度减少了1。

(3)替换：把A末尾的字符替换成'c'，这样就与B的末尾字符一样了，那么接下来就
*/
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// string a, b;
// int main()
// {
//     untie();
//     cin >> a >> b;
//     a = '*' + a, b = '*' + b;
//     int alen = a.size(), blen = b.size();
//     vector<vector<int> > dp(alen + 5, vector<int>(blen + 5, 0));
//     for(int i = 1; i < alen; i++) dp[i][0] = i;//初始化空串状态
//     for(int i = 1; i < blen; i++) dp[0][i] = i;
//     for(int i = 1; i < alen; i++)
//         for(int j = 1; j < blen; j++)
//             dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (a[i] != b[j]));
//     cout << dp[alen - 1][blen - 1];
//     return 0;
// }



//6.滑雪
//实际上可以记忆化搜索，此处与 dp 差异不大
//但是本题使用dp的话，重点在于创造无后效性，即将各点依据高度排序，由低到高依次求解，使得高点直接使用低点的求解结果
//dp[i][j] 定义为 从 i 处到 j 处最长严格递增长度
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 105;
// struct nd{
//     int r, c, h;
//     nd(int R, int C, int H) {r = R, c = C, h = H;}
//     bool operator <(const nd &n)const{
//         return h > n.h;
//     }
// };
// priority_queue<nd> h;
// int n, m, res = 0, arr[N][N], dp[N][N], dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//         {
//             cin >> arr[i][j];
//             dp[i][j] = 1;
//             h.push(nd(i, j, arr[i][j]));
//         }
//     while(h.size())
//     {
//         nd now = h.top(); h.pop();
//         int i = now.r, j = now.c, h = now.h;
//         for(int k = 0; k < 4; k++)
//         {
//             int di = i + dir[k][0], dj = j + dir[k][1];
//             if(di >= 1 && di <= n && dj >= 1 && dj <= m && arr[di][dj] < h) dp[i][j] = max(dp[i][j], dp[di][dj] + 1);
//         }
//         res = max(dp[i][j], res);
//     }
//     cout << res;
//     return 0;
// }



//7.饥饿的奶牛
//91分，TLE一个点
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 15e4 + 5;
// struct nd{
//     int l, r, len;
//     bool operator <(const nd &n)const{
//         return r == n.r ? l < n.l : r < n.r;
//     }
// }arr[N];
// int n, res = 0, dp[N];
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         arr[i] = nd{a, b, b - a + 1};
//     }
//     sort(arr + 1, arr + 1 + n);
//     for(int i = 1; i <= n; i++)
//     {
//         dp[i] = arr[i].len;
//         for(int j = 1; j < i; j++)
//             if(arr[j].r < arr[i].l) dp[i] = max(dp[i], dp[j] + arr[i].len);
//         res = max(res, dp[i]);
//     }
//     cout << res;
//     return 0;
// }
//AC
//dp[i] 定义为从起点到 i 处时可获得最多的总牧草量
//排序左端点 x，每次取一个[x, y]段作为最终段，累积 y - x + 1 长度，并加上 1 ~ (x - 1) 段的最长段长度(last)，即为当前最大状态dp[y]
//状态存储在dp[y]使得只有当 x 大于该处 y 时才能使用这个值dp[y]，此时这个 y 在 x 的左侧作为旧状态
//last存储前面的牧草量最大值
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// #define x first
// #define y second
// const int N = 15e4 + 5, M = 3e3 + 5;
// pair<int, int> arr[N];
// int n, last = 0, dp[M];
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y;
//     sort(arr + 1, arr + 1 + n);
//     for(int i = 0, j = 1; i < M; i++)
//     {
//         while(j <= n && arr[j].x == i)
//         {
//             dp[arr[j].y] = max(dp[arr[j].y], arr[j].y - arr[j].x + 1 + last);
//             j++;
//         }
//         last = max(last, dp[i]);
//     }
//     cout << *max_element(dp, dp + M);
//     return 0;
// }



//8.Cut Ribbon
//完全背包问题 -- 同一物品可以重复使用或者说有无限个
//但这里比较特殊，要求必须装满背包
//dp[i] 定义为 长度为 i 时所需短条数最大值,由于这个完全背包必须装满，存在无解情况即凑不齐 i (定义为 dp[i] < 0)，特殊地 dp[0] 的解就是 0
//只有延续有效解的状态进行转移才能正确装满背包
//如案例 918 102 1327 1733 自行dubug看转移方程即可理解
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 4e3 + 5;
// int n, x[4], dp[N];
// int main()
// {
//     untie();
//     cin >> n >> x[1] >> x[2] >> x[3];
//     memset(dp, -2, sizeof dp);//初始状态为无解，-16843010
//     dp[0] = 0;
//     for(int i = 1 ; i <= 3; i++)
//         for(int j = x[i] ; j <= n; j++)
//             dp[j] = max(dp[j], dp[j - x[i]] + 1);
//     cout << dp[n];
//     return 0;
// }



//9.The Triangle
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 110;
// int arr[N][N], dp[N][N], n, res = 0;
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= i; j++)
//             cin >> arr[i][j];
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= i; j++)
//             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
//     for(int i = 1; i <= n; i++) res = max(res, dp[n][i]);
//     cout << res;
//     return 0;
// }



//10.合唱队形
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 110;
// int arr[N], dp1[N], dp2[N], n, ans = 1e6;
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> arr[i];
//     for(int i = 1; i <= n; i++)//左侧最长严格上升子序列
//     {
//         dp1[i] = 1;
//         for(int j = 1; j < i; j++)
//             if(arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
//     }
//     for(int i = n; i >= 1; i--)//右侧最长严格下降子序列
//     {
//         dp2[i] = 1;
//         for(int j = n; j > i; j--)
//             if(arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
//     }
//     for(int i = 1; i <= n; i++)
//         ans = min(ans, n - dp1[i] - dp2[i] + 1);
//     cout << ans;
//     return 0;
// }




//背包问题
//背包九讲：https://github.com/CSGrandeur/s-1problem1day1ac/discussions/554

//1.Bone Collector
//01背包问题
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int M = 1100;
// int T, n, v, N[M], V[M], dp[M];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         memset(dp, 0, sizeof dp);
//         cin >> n >> v;
//         for(int i = 1; i <= n; i++) cin >> N[i];
//         for(int i = 1; i <= n; i++) cin >> V[i];
//         for(int i = 1; i <= n; i++)
//             for(int j = v; j >= V[i]; j--)
//                 dp[j] = max(dp[j], dp[j - V[i]] + N[i]);
//         cout << dp[v] << '\n';
//     }
//     return 0;
// }



//2.疯狂的采药
//完全背包问题
/*
形式上，我们只需要将 01 背包问题的「一维空间优化」解法中的「容量维度」遍历方向从「从大到小 改为 从小到大」就可以解决完全背包问题。
但本质是因为两者进行状态转移时依赖了不同的格子：
 01背包 依赖的是「上一行正上方的格子」和「上一行左边的格子」。
完全背包 依赖的是「上一行正上方的格子」和「本行左边的格子」。
*/
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e4 + 5;
// typedef long long ll;
// int t, m, T[N], val[N];
// int main()
// {
//     untie();
//     cin >> t >> m;
//     vector<ll> dp(t + 1, 0);
//     for(int i = 1; i <= m; i++) cin >> T[i] >> val[i];
//     for(int i = 1; i <= m; i++)
//         for(int j = T[i]; j <= t; j++)//正序遍历：刚装入背包的马上变成旧状态被利用，即前面的件数可以叠加到新状态，小背包可以装入大背包里
//             dp[j] = max(dp[j], dp[j - T[i]] + val[i]);
//     cout << dp[t];
//     return 0;
// }



//3.宝物筛选
//多重背包问题 -- 一样物品可以选多件，即不同物品有不同的选择上限

//一法：转化为 01背包 -- 枚举 k 件物品，把问题看成仅有一件的占用空间为 k*Vi ，价值为 k*Wi 的物品该不该拿
//无优化(单例最高耗时922ms)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, W;
// int main()
// {
//     untie();
//     cin >> n >> W;
//     vector<int> dp(W + 5, 0);
//     for(int i = 1; i <= n; i++)
//     {
//         int v, w, sum;
//         cin >> v >> w >> sum;
//         for(int j = W; j >= 0; j--)
//             for(int k = 1; k <= sum && k * w <= j; k++)
//                 dp[j] = max(dp[j], dp[j - k * w] + k * v);
//     }
//     int res = 0;
//     for(int i = 1; i <= W; i++) res = max(res, dp[i]);
//     cout << res;
//     return 0;
// }

//二进制优化(最好用) -- 一种有一定数量 sum 的物品，拆分成 x 个基元，由这 x 个基元组成 1 ~ sum 所有的取件数情况 (单例最高耗时141ms) -- 优化效果显著
// 先按 2 的倍数升序拆分为 x - 1 个数，最后剩下一个余数，共 x 个基数，
// 如 sum = 25，分成 1, 2, 4, 8, 10(10 < 2^4 = 16) 五个基元，并且由 5 个数任意自由组合得到 1 ~ 25 的所有数字
// 多重背包问题 就转化成对 每种物品 的 每个基元数 的 选与不选，即 01背包问题
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int MAXN = 1e6 + 5;//数组一定要够大
// int n, m, dp[MAXN];
// struct nd{
//     int v, w;
// }goods[MAXN];//存储一种物品分成的若干个01背包，规定在[1, cnt]
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++)//遍历每种物品
//     {
//         int v, w, sum, cnt = 0;
//         cin >> v >> w >> sum;
//         //二进制倍数枚举拆分
//         for(int j = 1; j <= sum; j <<= 1)
//         {
//             goods[++cnt] = nd{v * j, w * j};
//             sum -= j;//减去已拆分
//         }
//         //最后一个余数 处理
//         if(sum) goods[++cnt] = nd{v * sum, w * sum};
//         //01背包 -- 每种物品分成若干个 01背包
//         for(int k = 1; k <= cnt; k++)
//             for(int j = m; j >= goods[k].w; j--)//逆序
//                 dp[j] = max(dp[j], dp[j - goods[k].w] + goods[k].v);
//     }
//     cout << dp[m];
//     return 0;
// }
//单调队列优化(最优耗时)











//二法：转化为 01背包 + 完全背包 (3.8s微小优化，*仅供加深两种背包的理解*)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, W;
// int main()
// {
//     untie();
//     cin >> n >> W;
//     vector<int> dp(W + 5, 0);
//     for(int i = 1; i <= n; i++)
//     {
//         int v, w, sum;
//         cin >> v >> w >> sum;
//         if(sum * w >= W)//完全背包,对于总体积为 W 的背包来说，此时 v 物体相当于可以无限选取，即不用担心超额
//         {
//             for(int j = w; j <= W; j++)
//                 dp[j] = max(dp[j], dp[j - w] + v);
//         }
//         else
//         {
//             for(int j = W; j >= w; j--)//01背包，必须逆序遍历
//                 for(int k = 1; k <= sum && k * w <= j; k++)//该层遍历顺序不影响结果
//                     dp[j] = max(dp[j], dp[j - k * w] + k * v);
//         }
//     }
//     cout << dp[W];
//     return 0;
// }



//4.NASA的食物计划
// 二维费用的背包问题
// 指对于每件物品，具有两种不同的空间耗费，选择这件物品必须同时付出这两种代价。
// 对于每种代价都有一个可付出的最大值 （背包容量），问怎样选择物品可以得到最大的价值。
// 由于每个物品只能选一次，所以这是个 二维01背包问题
// 定义 dp[i][j][k] 为遍历到第 i 个物品时体积不超过 j，质量不超过 k 的最大卡路里值
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int H, T, n, dp[500][500];
// int main()
// {
//     untie();
//     cin >> H >> T >> n;
//     for(int i = 0; i < n; i++)
//     {
//         int h, t, K;
//         cin >> h >> t >> K;
//         for(int j = H; j >= h; j--)
//             for(int k = T; k >= t; k--)
//                 dp[j][k] = max(dp[j][k], dp[j - h][k - t] + K);
//     }
//     cout << dp[H][T];
//     return 0;
// }
//有时,"二维费用" 的条件是以这样一种隐含的方式给出的：最多只能取 U 件物品。
//这事实上相等于每件物品多了一种 "件数" 的费用，每个物品的件数费用均为 1，可以付出的最大件数费用为 U。



//5.通天之分组背包
//分组背包问题 -- 本质上，对于每个物品组就是 01背包问题，又可以称为 多组01背包问题
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 5;
// struct nd{
//     int w, v;
// };
// int n, m, ind = 0, dp[N];
// int main()
// {
//     untie();
//     cin >> m >> n;
//     vector<vector<nd> > goods(n + 1); 
//     while(n--)
//     {
//         int w, v, grp;
//         cin >> w >> v >> grp;
//         goods[grp].push_back(nd{w, v});
//         ind = max(ind, grp);
//     }
//     for(int i = 1; i <= ind; i++)//组数
//         for(int j = m; j >= 0; j--)//01背包问题，逆序遍历体积（代价）
//             for(auto x : goods[i])//方案数（物品数）
//                 if(j >= x.w)
//                     dp[j] = max(dp[j], dp[j - x.w] + x.v);
//     cout << dp[m];
//     return 0;
// }



//6.金明的预算方案
// 一个主件及其若干附件将称为分组背包中的一个物品组，故为 有依赖的分组背包问题 -- 依赖性表现在附件选择的前提是先选主件
// 我们可以将每个附件看成一个01背包问题，这样当我们给一个主件分配多少价钱的时候，
// 就可以知道此时这个主件及其附件在对应的价钱可以获得的最大价值。
/*
案例：
2000 10
500 1 0
400 4 0
300 5 1
400 5 1
200 5 0
500 4 5
400 4 0
320 2 0
410 3 0
400 3 5
7430
*/
//先处理附件价值状态，再往主件中加入附件 (230 ms)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int v, p, pos;
// };
// int n, m;
// int main()
// {
//     untie();
//     cin >> n >> m;
//     n /= 10;//降低复杂度
//     vector<nd> goods[m + 1];//goods[0]为主件组，1 ~ m 为附件组
//     vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
//     for(int i = 1; i <= m; i++)
//     {
//         int v, p, q;
//         cin >> v >> p >> q;
//         goods[q].push_back(nd{v / 10, p, i}); 
//     }
//     //dp[i][j]表示给第 i 个背包分配 j 钱数的最大价值
//     for(int i = 1; i <= m; i++)//*遍历背包
//         for(auto x : goods[i])//遍历物品(附件)
//             for(int j = n; j >= x.v; j--)//遍历代价
//                 dp[i][j] = max(dp[i][j], dp[i][j - x.v] + x.v * x.p * 10);
//     //遍历主件，给附件分配空间，据最大价值判断是否并入主件
//     for(int i = 0; i < goods[0].size(); i++)
//     {
//         nd base = goods[0][i];
//         for(int j = n; j >= base.v; j--)//遍历主件的代价
//             for(int k = j - base.v; k >= 0; k--)//遍历加入附件的代价
//                 dp[0][j] = max(dp[0][j], dp[0][j - base.v - k] + base.p * base.v * 10 + dp[base.pos][k]);
//     }
//     cout << dp[0][n];
//     return 0;
// }

//实际上也可以当成有 5 种操作的 01背包来写 (38 ms)
//| 1.不变 | 2.只拿主件 | 3.主件 + 附件1 | 4.主件 + 附件2 | 5.主件 + 附件1 + 附件2 |
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, m, v[65][3], p[65][3];//v[i][j] 第 i 个物品，若 j = 0，为主件；而 j = 1, 2 为附件 1，2
// //物品价值定义为 v * p，直接将原值存入p数组中
// int main()
// {
//     untie();
//     cin >> n >> m;
//     n /= 10;//降低复杂度
//     vector<int> dp(n + 1, 0);
//     for(int i = 1; i <= m; i++)
//     {
//         int a, b, grp;
//         cin >> a >> b >> grp;
//         if(grp) v[grp][2 - !v[grp][1]] = a / 10, p[grp][2 - !p[grp][1]] = a * b;//附件1位置未占用就存入位置1，已占用就会存入位置2
//         else v[i][0] = a / 10, p[i][0] = a * b;
//     }
//     for(int i = 1; i <= m; i++)
//         for(int j = n; j >= v[i][0]; j--)
//         {
//             dp[j] = max(dp[j], dp[j - v[i][0]] + p[i][0]);//情况1, 2
//             if(j >= v[i][0] + v[i][1]) dp[j] = max(dp[j], dp[j - v[i][0] - v[i][1]] + p[i][0] + p[i][1]);//3
//             if(j >= v[i][0] + v[i][2]) dp[j] = max(dp[j], dp[j - v[i][0] - v[i][2]] + p[i][0] + p[i][2]);//4
//             if(j >= v[i][0] + v[i][1] + v[i][2]) dp[j] = max(dp[j], dp[j - v[i][0] - v[i][1] - v[i][2]] + p[i][0] + p[i][1] + p[i][2]);//5
//         }
//     cout << dp[n];
//     return 0;
// }

//也可以认为是特殊的树形背包问题 (深度为 2)



//7.Bone Collector II
//求第 k 优解(第 k 大价值)
// 在原来 01背包 的基础上在加一维记录即可，即 dp[i][j][k] - 遍历到第 i 个物品，且体积不超过 j 时可得的第 k 大价值
// 当然可以滚动掉第一维，剩余 dp[j][k]
//a数组记录的是 不选第 i 个物品 的 k 个最大价值
//b数组记录的是 选第 i 个物品 的 k 个最大价值
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int MAXN = 1e2 + 5;
// int T, val[MAXN], vol[MAXN];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         int n, v, k;
//         cin >> n >> v >> k;
//         vector<vector<int> > dp(v + 1, vector<int>(k + 1, 0));
//         for(int i = 1; i <= n; i++) cin >> val[i];
//         for(int i = 1; i <= n; i++) cin >> vol[i];
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = v; j >= vol[i]; j--)
//             {
//                 int ai = 1, bi = 1;
//                 vector<int> a(k + 2, 0), b(a);
//                 a[k + 1] = b[k + 1] = -1;
//                 //填充a, b
//                 for(int m = 1; m <= k; m++)
//                 {
//                     a[m] = dp[j][m];
//                     b[m] = dp[j - vol[i]][m] + val[i];
//                 }
//                 //合并a, b 取较大者存入 dp
//                 for(int m = 1; m <= k && (a[ai] != -1 || b[bi] != -1); )//相当于从 2*k 个数排序后取前 k 个数
//                 {
//                     dp[j][m] = a[ai] > b[bi] ? a[ai++] : b[bi++];
//                     if(dp[j][m] != dp[j][m - 1])//题意：两种不同方法得到相同价值是算作同一个种，即去除重复。若无该条件，则去掉该句即可
//                         m++;//不重复说明该解占用有效
//                 }
//             }
//         }
//         cout << dp[v][k] << "\n";
//     }
//     return 0;
// }



//8.投资的最大效益
//经典技巧降低时空复杂度：由于 a 是 1000 的倍数，那就全程用 a /= 1000 计算
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 2e5 + 5;
// int n, d, val[50], cost[50];
// ll s, sum, dp[N];
// int main()
// {
//     untie();
//     cin >> s >> n >> d;
//     sum = s;
//     for(int i = 1; i <= d; i++) cin >> cost[i] >> val[i], cost[i] /= 1000;
//     for(int i = 1; i <= n; i++)
//     {
//         ll tp = 0;
//         memset(dp, 0, sizeof dp);
//         for(int k = 1; k <= d; k++)
//         {
//             for(int j = 1; j <= sum / 1000; j++)
//             {
//                 if(j >= cost[k]) dp[j] = max(dp[j], dp[j - cost[k]] + val[k]);
//                 tp = max(tp, dp[j]);
//             }
//         }
//         sum += tp;
//     }
//     cout << sum;
//     return 0;
// }



//9.樱花
//混合背包问题
//老实分算三个背包，并且二进制优化多重背包 (55ms)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, T;
// struct nd{
//     int t, c;
// }arr[10005];
// string st, se;
// int transform(string t)
// {
//     int h = 0, m = 0, pos = t.find(':');
//     for(int i = 0; i < pos; i++) h = h * 10 + (t[i] - '0');
//     for(int i = pos + 1; i < t.size(); i++) m = m * 10 + (t[i] - '0');
//     return h * 60 + m;
// }
// int main()
// {
//     untie();
//     cin >> st >> se >> n;
//     T = transform(se) - transform(st);
//     vector<int> dp(T + 1, 0);
//     for(int i = 0; i < n; i++)
//     {
//         int t, c, p;
//         cin >> t >> c >> p;
//         if(p == 0 || t * p >= T)//完全背包
//         {
//             for(int j = t; j <= T; j++)
//                 dp[j] = max(dp[j], dp[j - t] + c);
//         }
//         else if(p == 1)//01背包
//         {
//             for(int j = T; j >= t; j--)
//                 dp[j] = max(dp[j], dp[j - t] + c);
//         }
//         else//多重背包
//         {
//             int cnt = 0;
//             for(int j = 1; j <= p; j <<= 1)
//             {
//                 arr[++cnt] = nd{t * j, c * j};
//                 p -= j;
//             }
//             if(p) arr[++cnt] = nd{t * p, c * p};
//             for(int k = 1; k <= cnt; k++)//转为01背包
//                 for(int j = T; j >= arr[k].t; j--)
//                     dp[j] = max(dp[j], dp[j - arr[k].t] + arr[k].c);
//         }
//     }
//     cout << dp[T];
//     return 0;
// }

//全部转化为01背包，用二进制优化(77ms)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, T, h1, h2, m1, m2;
// struct nd{
//     int t, c;
// }arr[10005];
// int main()
// {
//     scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
//     T = (h2 - h1) * 60 + m2 - m1;
//     vector<int> dp(T + 1, 0);
//     for(int i = 0; i < n; i++)
//     {
//         int t, c, p, cnt = 0;
//         scanf("%d%d%d", &t, &c, &p);
//         if(!p) p = T / t;//完全背包的无限次转为有效次数即可
//         for(int j = 1; j <= p; j <<= 1)
//         {
//             arr[++cnt] = nd{t * j, c * j};
//             p -= j;
//         }
//         if(p) arr[++cnt] = nd{t * p, c * p};
//         for(int k = 1; k <= cnt; k++)
//             for(int j = T; j >= arr[k].t; j--)
//                 dp[j] = max(dp[j], dp[j - arr[k].t] + arr[k].c);
//     }
//     printf("%d\n", dp[T]);
//     return 0;
// }

//亦可单调队列优化



//10.ACboy needs your help
//分组背包
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, m, a[105][105];
// int main()
// {
//     untie();
//     while(cin >> n >> m, n || m)
//     {
//         vector<int> dp(m + 1, 0);
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= m; j++)
//                 cin >> a[i][j];
//         for(int i = 1; i <= n; i++)
//             for(int j = m; j >= 0; j--)
//                 for(int k = 1; k <= m; k++)
//                     if(j >= k)
//                         dp[j] = max(dp[j], dp[j - k] + a[i][k]);
//         cout << dp[m] << '\n';
//     }
//     return 0;
// }



//11.Acwing 12	背包问题求具体方案
//背包问题求具体方案，且要求字典序最小(贪心)












/*十二. 图论基础, 拓扑排序, 最小生成树*/
/*
概念:
顶点（Vertex）：图G中的数据元素称为顶点。一条边连接两个顶点。

无向图：若图G中的每条边都是没有方向的，则称图G为无向图。

有向图：若图G中的每条边都是有方向的，则称图G是有向图。

弧：即有向边。边的终点被称为弧头，起始点被称为弧尾。

度（degree）：一个顶点的度就是与该顶点相关联的边的数目。

出度：有向图中，顶点所连接的出边的数量。

入度：有向图中，顶点所连接的入边的数量。

环：环是一条只有第一个和最后一个顶点重复的非空路径。

有向无环图：又称DAG图，即没有环的有向图。DAG图是动态规划和记忆化搜索的结构基础。

子图（Subgraph）：由图中部分节点以及这些节点间的边组成的图。

连通图（Connected Graph）：若图G中的任意两个结点u和v，结点u与结点v相互可达，则成图G是连通图。

连通分量（Connected Component）：各节点间至少存在一条边可以连通。

树: 树就是无环连通图。互不相连的树组成的集合称为森林。具有n个顶点和n-1条边的连通图，是树的充要条件。
    如果一个无向连通图不包含回路(连通图中不存在环)，那么就是一棵树。

生成树：含有连通图全部顶点并有n-1条边的连通子图。

邻接矩阵: 所谓矩阵其实就是二维数组。对于有n个顶点的图 G=(V,E) 来说，我们可以用一个 n×n 的矩阵 A 来表示 G 中各顶点的相邻关系
         如果点 i 和 点 j 之间存在边(或弧)，则 A[i][j] = 1，否则 A[i][j] = 0。一个图的邻接矩阵是唯一的，矩阵的大小只与顶点个数N有关。

邻接表：邻接表的思想是，对于图中的每一个顶点，用一个数组来记录这个点和哪些点相连。由于相邻的点会动态的添加，所以对于每个点，我们需要用vector来记录。

*/
//邻接矩阵 gra[N][N]，gra[i][j]表示边(i, j)的权值，若为无权边，则用 1 表示有边，否则 0 表示无边

//*邻接表
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 +5;// N 个点
// int n, m;                 
// struct edge{
//     int from, to, w;                                          
// };
// vector<edge> e[N];
// void init()
// {
//     for(int i = 0; i <= n; i++)
//         e[i].clear();
// }
// int main()
// {
//     untie();
//     init();
//     cin >> n >> m;                                  //n个点，m条边
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         e[u].push_back(edge{u, v, w});
//     }
//     //遍历各节点的所有邻居
//     for(int u = 0; u <= n; u++)
//     {
//         if(e[u].empty()) continue;
//         cout << "node " << u << " 's neighbours: ";
//         // for(int i = 0; i < e[u].size(); i++)
//         for(auto v : e[u])
//         {
//             cout << v.to << " ";//不同于链式前向星，这里会按输入顺序输出
//         }
//         cout << '\n';
//     }
//     return 0;
// }

//*链式前向星
//1.节点编号范围为 0 ~ n - 1
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 5, M = 2e3 + 5;                 //N为最大结点数，M为最多边数
// int n, m, head[N], cnt = 0;                         //head[u]指向 u 的一个邻居在edge[]中的存储位置 即 连着 u 的最后一条边(按录入顺序的最后者), cnt记录当前可存储位置
// struct node{
//     int from, to, next;                             //from为边的起点(一般不需要)，to为边的终点，next为 u 的下一个邻居
//     int w;                                          //边权
// }edge[M];
// void init()
// {
//     for(int i = 0; i < N; i++) head[i] = -1;        //点初始化
//     for(int i = 0; i < M; i++) edge[i].next = -1;   //边初始化
//     cnt = 0;
// }
// void addedge(int u, int v, int w)
// {
//     edge[cnt] = node{u, v, head[u], w};
//     //edge[cnt].next = head[u] 将已录入位置存起，对于同一个起点 u，最终是从最后录入的位置连向最先录入的位置以遍历所有邻居
//     head[u] = cnt++;
// }
// int main()
// {
//     untie();
//     init();
//     cin >> n >> m;                                  //n个点，m条边
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         addedge(u, v, w);
//     }
//     //遍历各节点的所有邻居
//     for(int u = 0; u <= n; u++)
//     {
//         if(!~head[u]) continue;
//         cout << "node " << u << " 's neighbours: ";
//         for(int i = head[u]; ~i; i = edge[i].next)//~i = -(i + 1) ，这里相当于 i != -1
//             cout << edge[i].to << " ";
//         cout << '\n';
//     }
//     return 0;
// }
//2.节点编号范围为 1 ~ n，这里就可以用 0 表示空，而不是 -1，省去 init() 函数
//简化版
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 5, M = 2e3 + 5;
// int n, m, head[N], cnt = 1;
// struct node{ int to, next, w;} edge[M];
// void addedge(int u, int v, int w)
// {
//     edge[cnt] = node{v, head[u], w};
//     head[u] = cnt++;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;                                  
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         addedge(u, v, w);
//     }
//     //遍历各节点的所有邻居
//     for(int u = 0; u <= n; u++)
//     {
//         if(!head[u]) continue;
//         cout << "node " << u << " 's neighbours: ";
//         for(int i = head[u]; i; i = edge[i].next)//不为 0
//             cout << edge[i].to << " ";
//         cout << '\n';
//     }
//     return 0;
// }
/*
TEST:
6 11
1 2 1
2 1 2
5 2 3
6 3 4 
2 3 5
1 4 6
2 4 7
4 1 8
2 5 9
4 5 10
5 6 11
*/


//拓扑排序
/*
概念：
    对一个有向无环图(Directed Acyclic Graph简称DAG)G进行拓扑排序，是将G中所有顶点排成一个线性序列，
    使得图中任意一对顶点u和v，若边<u,v>∈E(G)，则u在线性序列中出现在v之前。
    通常，这样的线性序列称为满足拓扑次序(Topological Order)的序列，简称拓扑序列。
    简单的说，由某个集合上的一个偏序得到该集合上的一个全序，这个操作称之为拓扑排序。
    出度：有向图中，顶点所连接的出边的数量。
    入度：有向图中，顶点所连接的入边的数量。
?简单地说，在一个有向图中，对所有的节点进行排序，要求没有一个节点指向它前面的节点。当前仅当图是有向无环图时，拓扑排序有解，否则必有环。
排序方法：
    基于BFS：
        1.无前驱的顶点优先：从入度为 0 的点开始，正序
        2.无后继的顶点优先：从出度为 0 的点逆推，逆序
    基于DFS：

无前驱的顶点优先法的实现步骤：
    1.先统计所有节点的入度，将所有入度为 0 的点入队
    2.遍历此时入度为 0 的点 u，将其指向的所有节点的入度减 1，即分离出 u
    3.一直重复该操作，直到所有的节点全部入过队
    4.如果最后不存在入度为0的节点，那就说明有环，不存在拓扑排序，也就是很多题目的无解的情况。

两种拓扑排序：
1.正向拓扑排序（最常见）：一般出队元素为队中编号最小的元素，适用于输出 字典序最小 的拓扑序列
2.反向拓扑排序（题意有优先级要求）：建立反图，一般出队元素为队中编号最大的元素，适用于输出 符合优先级要求 的拓扑序列(需翻转输出) —— 这与字典序区别开来
*/
//一般写法 - 点(1 ~ n)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <functional>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5;
// int indegree[N];//记录每个点的入度
// int n, m;//n 个点， m 条边
// queue<int> q;//当时入度为 0 的点集
// //若输出字典序最小或编号升序的拓扑序列，则需要优先队列 priority_queue<int> q;
// vector<int> edge[N], ans;//ans 为拓扑序列
// void bfs()
// {
//     //初始化队列 -- 入度为 0 的点
//     for(int i = 1; i <= n; i++)
//         if(indegree[i] == 0) q.push(i);
//     while(!q.empty())
//     {
//         int now = q.front(); q.pop();
//         ans.push_back(now);
//         for(int x : edge[now])
//             if(--indegree[x] == 0)
//                 q.push(x);
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         edge[u].push_back(v);
//         indegree[v]++;
//     }
//     bfs();
//     for(int i = 0; i < ans.size(); i++)
//         cout << (" " + !i) << ans[i];
//     return 0;
// }

//1.确定比赛名次
//要求输出时编号小的队伍在前，将 queue 更换为 优先队列；该题保证拓扑序列存在。
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <functional>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 505;
// int n, m;
// vector<int> ans;
// int main()
// {
//     untie();
//     while(cin >> n >> m)
//     {
//         vector<int> edge[N];
//         int indegree[N] = {0};
//         priority_queue<int, vector<int>, greater<int> > q;
//         for(int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin >> u >> v;
//             edge[u].push_back(v);
//             indegree[v]++;
//         }
//         for(int i = 1; i <= n; i++)
//             if(!indegree[i]) q.push(i);
//         while(!q.empty())
//         {
//             int now = q.top(); q.pop();
//             ans.push_back(now);
//             for(int x : edge[now])
//                 if(!(--indegree[x])) q.push(x);
//         }
//         for(int i = 0; i < ans.size(); i++)
//             cout << (" " + !i) << ans[i];
//         cout << '\n';
//         ans.clear();
//     }
//     return 0;
// }



//*2.逃生
//*反向拓扑排序 + 优先队列
/*
//较好的题解：https://blog.csdn.net/u012861385/article/details/38059515
反向拓扑排序 应用于：题目在基本的拓扑排序的基础上又增加了一个要求：编号最小的节点要尽量排在前面；在满足上一个条件的基础上，编号第二小的节点要尽量排在前面；
                   在满足前两个条件的基础上，编号第三小的节点要尽量排在前面……依此类推。（注意，这和字典序是两回事，不可以混淆。）
本题要求**并不是字典序最小**，正向建表会出错，逆向建表再倒序输出才是正确答案 （注：拓扑序列保证存在）
如案例
5 4
1 4
4 2
5 3
3 2
正向建表的答案为 1 4 5 3 2 是错误的，而正确答案应为 1 5 3 4 2，
因为实际上处于同层关系的有{1， 5} {3， 4} {2}，按部排序就是 1 5 3 4 2
由于正向建表，队列每次取最小的头，很可能会取到非平行（不在同一层）元素，这样就违背了 ai 与 bi 既定的优先级，故这种贪心是“目光短浅”的。
对于有约束有平行的拓扑排序，对于若干条平行的路径，小的头部不一定排在前面，但是大的尾部一定排在后面。因为头部会受到尾部的约束，但是尾部没有约束。
因此，当我们从尾部的 2 出发，此时队列有 {4，3}，只要我们每次取最大元素，这种贪心就能保证平行关系不被破坏；
选择 4 后，序列为 2 4，队列为{3，1}；选择 3 后，序列为 2 4 3，队列为{5， 1}；故最终为 2 4 3 5 1
倒序输出后即 1 5 3 4 2
*/
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <functional>
// #include <cstring>
// using namespace std;
// const int N = 3e4 + 10;
// int n, m, T;
// vector<int> ans;
// vector<int> edge[N];
// int indegree[N];
// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d%d", &n, &m);
//         memset(indegree, 0, sizeof indegree);
//         for(int i = 0; i <= n; i++) edge[i].clear();
//         ans.clear();
//         priority_queue<int> q;
//         for(int i = 0; i < m; i++)
//         {
//             int u, v;
//             scanf("%d%d", &u, &v);
//             edge[v].push_back(u);//建反图
//             indegree[u]++;
//         }
//         for(int i = 1; i <= n; i++)
//             if(!indegree[i]) q.push(i);
//         while(!q.empty())
//         {
//             int now = q.top(); q.pop();
//             ans.push_back(now);
//             for(int x : edge[now])
//                 if(!(--indegree[x])) q.push(x);
//         }
//         for(int i = n - 1; i >= 0; i--)
//         {
//             if(i != n - 1) printf(" ");
//             printf("%d", ans[i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }




//图论基础
//1.图的遍历
//建反图（边的方向反过来），从大到小遍历点
// #include <iostream>
// #include <algorithm>
// #include <set>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 5;
// int n, m, ans[N];
// vector<int> gra[N];
// void dfs(int now, int x)
// {
//     if(ans[now]) return;
//     ans[now] = x;
//     for(auto i : gra[now])
//         dfs(i, x);
// }
// int main()
// {
//     untie();
//     cin >> n >> m;                             
//     for(int i = 1; i <= m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         gra[v].push_back(u);
//     }
//     for(int i = n; i > 0; i--)
//         dfs(i, i);
//     for(int i = 1; i <= n; i++)
//         cout << (" " + !(i - 1)) << ans[i];
//     return 0;
// }



//2.产生冠军
//寻找是否有入度为 0 的唯一点，有则产生冠军，否则无
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 5;
// int n;
// int main()
// {
//     untie();
//     while(cin >> n, n)
//     {
//         int cnt = 0;
//         map<string, int> indegree;
//         set<string> node;
//         for(int i = 0; i < n; i++)
//         {
//             string x, y;
//             cin >> x >> y;
//             node.insert(x);
//             node.insert(y);
//             ++indegree[y];
//         }
//         for(auto u : node)
//             if(!indegree[u]) cnt++;
//         if(cnt == 1) cout << "Yes\n";
//         else cout << "No\n";
//     }
//     return 0;
// }





//最小生成树 Minimal Spanning Tree（有边权的无向图问题，可以得到连通一个图所花费的最小代价(最小边权和)）
/*
设一个图有 n 个点，m 条边（m >= n - 1）,连通一个图至少要 n - 1 条边
概念：
树：如果一个无向连通图不包含回路(连通图中不存在环)，那么就是一个树。
生成树：在无向图中，连通且不含回路（不存在环）的一个子图，它包含全部 n 个点 和 其中 n - 1 条边，称为一颗生成树。
最小生成树：当图中每条边都存在权重时，生成树的总代价就是其包含的每条边的权重相加之和。
           生成树通常不唯一，我们称包含全部 n 个点及其中 n - 1 条边，并具有 最小权重之和 的生成树为 最小生成树（MST）。
由于最小生成树一定包含图中权值最小的 n - 1 条边，故可以使用 贪心法 构造MST，满足全局最优包含局部最优。
基于 贪心思想 的算法具体有两种：
Kruskal算法：O(mlogm) -- （常用）
    执行对象：对 图中所有的边 进行贪心选择
    核心：使用 并查集 判环(O(m))。
    实现过程：
        1.排序所有的边，从最短边开始
        2.每次选中边集合中剩余的权值最小的边
        3.判断该边是否生成环，若不成环则加入 Tree 上
        4.重复上述操作，直至 Tree 上包含所有 n 个点，并仅由 n - 1 条边连通所有点
        5.cnt 统计边数是否为 n - 1 条，以此判断生成树的合法性
    评估：编码简单，依靠并查集实现，复杂度主要来源于使用 sort() 对 m 条边进行排序，即 O(mlogm)
Prim算法：O(mlogn)
    执行对象：对 点的最近邻居 进行贪心选择
    核心：遍历过程类似BFS + 优先队列 O(mlogn)；用状态数组判断点是否已经在MST中，若在则不做操作即防止成环。
    实现过程：
        1.从任意点 u 开始，加入 Tree 上
        2.每次选择优先队列中距离 Tree 最近的邻居点 v，加入到 Tree 上
        3.然后将 v 的未遍历过的邻居点都加入队列中
        4.重复上述操作，直至 Tree 上包含所有 n 个点，并仅由 n - 1 条边连通所有点
        5.cnt 统计顶点数是否为 n 个，以此判断生成树的合法性
    评估：当边数非常多（相较于点数）时，才能发挥其高效性，且编码较复杂
*/
/*
//Kruskal算法模板（常用）
#include <iostream>
#include <algorithm>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
const int N = 5e3 + 5, M = 2e5 + 5;
struct Edge{
    int u, v, w;
    bool operator < (const Edge &x) const{ return w < x.w;}
}edge[M];
int n, m;
int ds[N];//并查集（用于判断 待取边的两个端点是否已经连通 即 是否属于同一个集合，若是则取该边会导致成环，故此时不取该边）
void init_set(){ for(int i = 1; i <= n; i++) ds[i] = i;}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];} //合并操作无需单独写
void kruskal()
{
    int ans = 0, cnt = 0;//ans为权值和，cnt记录加入MST边数
    sort(edge + 1, edge + 1 + m);
    for(int i = 1; i <= m; i++)
    {
        if(cnt == n - 1) break;//小优化，MST必是 n - 1 条边
        int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);//判断第 i 条边的两端点是否已经连通
        if(e1 == e2) continue;//若已连通则不使用该边
        else
        {
            ans += edge[i].w;
            ds[e1] = e2;//合并,与 ds[e1] = ds[e2] 没有区别
            ++cnt;
        }
    }
    if(cnt == n - 1) cout << ans << '\n';
    else cout << "orz\n";
}
int main()
{
    untie();
    cin >> n >> m;
    init_set();
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = Edge{u, v, w};
    }
    kruskal();
    return 0;
}

//Prim算法模板 -- 与最短路的Dijkstra算法实现过程相似，而两者区别在于Prim算法无需更新当前集合所有点到起点的距离
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
const int N = 5e3 + 5, M = 2e5 + 5;
int n, m;
struct edge{
    int to, w;//边的终点和权值
};
struct node{
    int id, dis;//终点的编号 和 到该点的权值
    bool operator < (const node &x) const{ return dis > x.dis;}//使优先队列的堆顶为最小值
};
vector<edge> G[N];//用 G[u.id].to = v 来表示边 u -> v
bool vis[N];//记录点是否已经在 MST 上
void prim()
{
    //memset(vis, 0, sizeof vis);
    int s = 1;//从任意点开始，不妨从点 1 开始
    int ans = 0, cnt = 0;//cnt记录MST上的顶点数
    priority_queue<node> q;
    q.push(node{s, 0});
    while(!q.empty())
    {
        node u = q.top(); q.pop();
        if(vis[u.id]) continue;//弃去已在MST上的点，防止成环
        vis[u.id] = 1;
        ans += u.dis;//累计权值
        ++cnt;
        for(auto v : G[u.id])//遍历点 u 的邻居点 v
        {
            if(vis[v.to]) continue;
            q.push(node{v.to, v.w});
        }
    }
    if(cnt == n) cout << ans << '\n';
    else cout << "orz\n";
}
int main()
{
    untie();
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(edge{v, w});
        G[v].push_back(edge{u, w});//双向边
    }
    prim();
    return 0;
}
*/


//1.繁忙的都市
//题意：保证数据将所有点连通，边数尽量少，最大权值边的权值尽量小，选出整体权值最小的子图。双向边。
//转义：符合无向连通图性质，不难想到构造其最小生成树，要求输出 边数 和 最大单边权值，而由于最小生成树必存在，边数恒确定为 n - 1
//数据分析：m >> n，考虑 O(mlogn) 优于 O(mlogm)，选择 prim (43ms)。但实际上该题 n 和 m 都比较小，两个算法耗时上没区别
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 305, M = 1e5 + 5;
// int n, m;
// struct edge{
//     int to, w;//边的终点和权值
// };
// struct node{
//     int id, dis;//终点的编号 和 到该点的权值
//     bool operator < (const node &x) const{ return dis > x.dis;}//使优先队列的堆顶为最小值
// };
// vector<edge> G[N];//用 G[u.id].to = v 来表示边 u -> v
// bool vis[N];//记录点是否已经在 MST 上
// void prim()
// {
//     int s = 1;
//     int res = 0;
//     priority_queue<node> q;
//     q.push(node{s, 0});
//     while(!q.empty())
//     {
//         node u = q.top(); q.pop();
//         if(vis[u.id]) continue;//弃去已在MST上的点，防止成环
//         vis[u.id] = 1;
//         res = max(res, u.dis);
//         for(auto v : G[u.id])//遍历点 u 的邻居点 v
//         {
//             if(vis[v.to]) continue;
//             q.push(node{v.to, v.w});
//         }
//     }
//     cout << (n - 1) << " " << res;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         G[u].push_back(edge{v, w});
//         G[v].push_back(edge{u, w});//双向边
//     }
//     prim();
//     return 0;
// }
//而实际，整体上 n 和 m 是比较小的，用kruskal显然更方便(42ms)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 305, M = 1e5 + 5;
// struct Edge{
//     int u, v, w;
//     bool operator < (const Edge &x) const{ return w < x.w;}
// }edge[M];
// int n, m;
// int ds[N];
// void init_set(){ for(int i = 1; i <= n; i++) ds[i] = i;}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void kruskal()
// {
//     int res = 0, cnt = 0;
//     sort(edge + 1, edge + 1 + m);
//     for(int i = 1; i <= m; i++)
//     {
//         if(cnt == n - 1) break;
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             res = max(res, edge[i].w);
//             ds[e1] = e2;//合并
//             ++cnt;
//         }
//     }
//     cout << (n - 1) << " " << res;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     init_set();
//     for(int i = 1; i <= m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edge[i] = Edge{u, v, w};
//     }
//     kruskal();
//     return 0;
// }



//2.口袋的天空
//要求全部连通，构造最小生成树 并 划分 k 个部分
// 思路：全连通，构造 n 个点的最小生成树，要分成 k 个部分，那么取出 k - 1 条较大的边，总体代价减去这些边，就是最终答案
//     由于 最小生成树构造过程 与 最后分k个部分 时都是贪心的，该树只需构造到 n - k 个点即可，其后的边都无需考虑，因为会被去掉
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 5, M = 1e4 + 5;
// struct Edge{
//     int u, v, w;
//     bool operator < (const Edge &x) const{ return w < x.w;}
// }edge[M];
// int n, m, k;
// int ds[N];
// void init_set(){ for(int i = 1; i <= n; i++) ds[i] = i;}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void kruskal()
// {
//     int ans = 0, cnt = 0;//ans为权值和，cnt记录加入MST边数
//     sort(edge + 1, edge + 1 + m);
//     for(int i = 1; i <= m; i++)
//     {
//         if(cnt == n - k) break;
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             ans += edge[i].w;
//             ds[e1] = e2;//合并
//             ++cnt;
//         }
//     }
//     if(cnt == n - k) cout << ans << '\n';
//     else cout << "No Answer\n";
// }
// int main()
// {
//     untie();
//     cin >> n >> m >> k;
//     init_set();
//     for(int i = 1; i <= m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edge[i] = Edge{u, v, w};
//     }
//     kruskal();
//     return 0;
// }



//3.买礼物
//最小生成树答案必大于等于权值 a ，设一个虚点，所有实际点到该点权值为 a，且该点必要，故该树的边数变成 n 条 
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 505, M = N * N;
// struct Edge{
//     int u, v, w;
//     bool operator < (const Edge &x) const{ return w < x.w;}
//     // Edge() = default; 这个也可以解决自定义构造函数导致无法编译的问题
//     Edge(){}
//     Edge(int a, int b, int c) {u = a, v = b, w = c;}
// }edge[M];
// int a, b, n, m;
// int ds[N];
// void init_set(){ for(int i = 1; i <= n; i++) ds[i] = i;}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void kruskal()
// {
//     int ans = 0, cnt = 0;
//     sort(edge + 1, edge + 1 + m);
//     for(int i = 1; i <= m; i++)
//     {
//         if(cnt == n) break;//自定义多一个点，最终点数共 n + 1 个，故树的边数变成 n 条
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             ans += edge[i].w;
//             ds[e1] = e2;//合并
//             ++cnt;
//         }
//     }
//     cout << ans;
// }
// int main()
// {
//     untie();
//     cin >> a >> b;
//     n = b, m = 0;
//     init_set();
//     for(int i = 1; i <= b; i++)
//     {
//         for(int j = 1; j <= b; j++)
//         {
//             int w; 
//             cin >> w;
//             if(j > i && w) edge[++m] = Edge(i, j, w);//优惠为零无需再建边，只需要建 b 个“原价边”即可
//         }
//     }
//     for(int i = 1; i <= b; i++) edge[++m] = Edge(0, i, a);
//     kruskal();
//     return 0;
// }



//4.局域网
//题意相当于求 全体边权 与 最小生成树权值和 之差
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e2 + 5, M = 1e5 + 5;
// int n, m, sum = 0, ds[N];
// struct edge{
//     int u, v, w;
//     edge(){}
//     edge(int _u, int _v, int _w) { u = _u, v = _v, w = _w;}
//     bool operator <(const edge &x) const{ return w < x.w;}
// }E[M];
// int find_set(int x) { return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void kruskal()
// {
//     int ans = 0, cnt = 0;
//     sort(E + 1, E + 1 + m);
//     for(int i = 1; i <= m; i++)
//     {
//         if(cnt == n - 1) break;
//         int e1 = find_set(E[i].u), e2 = find_set(E[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             ans += E[i].w;
//             ds[e1] = e2;
//             ++cnt;
//         }
//     }
//     cout << (sum - ans);
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) ds[i] = i;
//     for(int i = 1; i <= m; i++)
//     {
//         int x, y, w;
//         cin >> x >> y >> w;
//         E[i] = edge(x, y, w);
//         sum += w;
//     }
//     kruskal();
//     return 0;
// }



//5.部落划分
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #include <cstdio>
// using namespace std;
// typedef pair<int, int> p;
// const int N = 1e3 + 5, M = 1e6 + 5;//MAX_M < 1e6
// const double eps = 1e-3;
// int n, m = 0, k, ds[N];
// vector<p> node;
// struct edge{
//     int u, v;
//     double w;
//     edge(){}
//     edge(int _u, int _v, double _w) { u = _u, v = _v, w = _w;}
//     bool operator <(const edge &x) const{ return w < x.w;}
// }E[M];
// double dabs(double x) { return x > 1e-6 ? x : -x;}
// double getdis(p n1, p n2)
// {
//     double dis1 = dabs(n1.first - n2.first), dis2 = dabs(n1.second - n2.second);
//     return sqrt(dis1*dis1 + dis2*dis2);
// }
// int find_set(int x) { return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void kruskal()
// {
//     int cnt = 0;
//     sort(E + 1, E + 1 + m);
//     //成环边也遍历掉，那么剩余的边都是部落间的距离，则这之后的第一条边即为最小答案
//     for(int i = 1; i <= m; i++)
//     {
//         int e1 = find_set(E[i].u), e2 = find_set(E[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             ds[e1] = e2;
//             ++cnt;
//         }
//         if(cnt == n - k + 1)
//         {
//             printf("%.2lf\n", E[i].w);
//             return;
//         }
//     }
// }
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for(int i = 1; i <= n; i++) ds[i] = i;
//     for(int i = 1; i <= n; i++)
//     {
//         int x, y;
//         scanf("%d%d", &x, &y);
//         node.push_back(p(x, y));
//     }
//     for(int i = 0; i < node.size(); i++)
//         for(int j = i + 1; j < node.size(); j++)
//             E[++m] = edge(i, j, getdis(node[i], node[j]));
//     kruskal();
//     return 0;
// }
//Prim更快？



//*6.Explorer
// 本题重点在于 减少边数，要求最小生成树，一个点可能连接最多 4 个点，同条线上与之相邻的 2 个点 以及 向另一条线作垂线，该线上与垂足最近的 2 个点。
// 1.因为特殊地，一组点在一条直线上，其连接方向除了映射到另一条线上，就只有其左右两个方向。
// 2.我们要知道无序点建图要建全图再sort排序边来得到最小生成树，建全图是因为没办法判断哪个方向是全局最优，所以当算是映射方向只有3个方向时就好说了
// 3.并且左右两个方向所有点共线，所以对于线ABCD，连接AD 与 连接AB,BC,CD 没有区别，所以同一条线上只需要相邻两点相连就可以局部全连通并且实现局部最小生成树，当然两条线都是这样
// 4.那么现在只剩下两条线的相互关系，将一个点投影到另一条线上，这样该点就可以评估与该线上点的距离，左右方向分别与垂足最近的点，与该点连接后
// 5.每个点都实现了所有方向上的最短连接
// 故一个点产生的边数最多是 4 条
// 思路：求两线交点（特判平行情况），找出将一条线上的一个点映射到另一个线的方法，并找出寻找映射点最近两点的方法
// #include <iostream>
// #include <algorithm>
// #include <cstdio>
// #include <cmath>
// using namespace std;
// typedef double db;
// const int N = 2e5 + 5, M = 6 * N;
// struct node{
//     double x, y;
//     bool operator < (const node &n) const{ return x < n.x;}
// }a[N], b[N];
// struct Edge{
//     int u, v;
//     double w;
//     bool operator < (const Edge &x) const{ return w < x.w;}
// }edge[M];
// int n, m, ind = 0, ds[N];
// db ax, ay, bx, by, cx, cy, dx, dy, t;
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// db getdis(node a, node b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);}
// void kruskal()
// {
//     db ans = 0;
//     int cnt = 0;//ans为权值和，cnt记录加入 MST 的边数
//     sort(edge + 1, edge + 1 + ind);
//     for(int i = 1; i <= ind; i++)
//     {
//         if(cnt == n + m - 1) break;
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 != e2)
//         {
//             ans += sqrt(edge[i].w);
//             ds[e1] = e2;//合并
//             ++cnt;
//         }
//     }
//     printf("%.3lf\n", ans);
// }
// int main()
// {
//     scanf("%d%d%lf%lf%lf%lf%lf%lf%lf%lf", &n, &m, &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
//     for(int i = 1; i <= n + m; i++) ds[i] = i;
//     for(int i = 1; i <= n; i++) scanf("%lf", &t), a[i] = node{ax * t + bx * (1 - t), ay * t + by * (1 - t)};
//     for(int i = 1; i <= m; i++) scanf("%lf", &t), b[i] = node{cx * t + dx * (1 - t), cy * t + dy * (1 - t)};
//     sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
//     //先连接同一条线上相邻两点的边
//     for(int i = 1; i < n; i++) edge[++ind] = Edge{i, i + 1, getdis(a[i], a[i + 1])};
//     for(int i = 1; i < m; i++) edge[++ind] = Edge{n + i, n + i + 1, getdis(b[i], b[i + 1])};
//     //再各自选取不共线两点的边，三分法框选可连接的不共线点，理论上只需要两条最近的边，这里直接选取[l, r]上三条边更方便（即无需判断第二条边是左右哪条）
//     //不同的映射方向，其结果不一样，并不能保证一种映射方向囊括所有情况，所以需遍历两种方向
//     for(int i = 1; i <= n; i++)//直线ab 映射到 直线cd 上
//     {
//         int l = 1, r = m;
//         while(l < r - 2)
//         {
//             int midl = (l * 2 + r) / 3, midr = (l + r * 2) / 3;
//             if(getdis(a[i], b[midl]) < getdis(a[i], b[midr])) r = midr;//三分逼近极小值邻域
//             else l = midl;
//         }
//         for(int j = l; j <= r; j++) edge[++ind] = Edge{i, n + j, getdis(a[i], b[j])};
//     }
//     for(int i = 1; i <= m; i++)//直线cd 映射到 直线ab 上
//     {
//         int l = 1, r = n;
//         while(l < r - 2)
//         {
//             int midl = (l * 2 + r) / 3, midr = (l + r * 2) / 3;
//             if(getdis(b[i], a[midl]) < getdis(b[i], a[midr])) r = midr;//三分逼近极小值邻域
//             else l = midl;
//         }
//         for(int j = l; j <= r; j++) edge[++ind] = Edge{n + i, j, getdis(b[i], a[j])};
//     }
//     kruskal();
//     return 0;
// }



//7.Heavy Transportation（最大生成树）
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// using namespace std;
// const int N = 1e3 + 5;
// struct Edge{
//     int u, v, w;
//     bool operator < (const Edge &x) const{ return w > x.w;}//大顶堆
// };
// vector<Edge> edge;
// int n, m, ds[N];
// void init_set(){ for(int i = 1; i <= n; i++) ds[i] = i;}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// int kruskal()
// {
//     sort(edge.begin(), edge.end());
//     for(int i = 0; i < edge.size(); i++)
//     {
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);//判断第 i 条边的两端点是否已经连通
//         if(e1 != e2)
//         {
//             ds[e1] = e2;
//             //用若干条长边连通1和n的那一刻就完成任务了，此时最后用的边自然是所有路段边中的最小限重
//             if(find_set(1) == find_set(n)) return edge[i].w;
//         }
//     }
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     for(int k = 1; k <= T; k++)
//     {
//         scanf("%d%d", &n, &m);
//         init_set();
//         edge.clear();
//         for(int i = 1; i <= m; i++)
//         {
//             int u, v, w;
//             scanf("%d%d%d", &u, &v, &w);// All streets can be travelled in both directions.无向图
//             Edge x = {u, v, w};
//             edge.push_back(x);
//         }
//         printf("Scenario #%d:\n%d\n\n", k, kruskal());//Terminate the output for the scenario with a blank line.案例之间有空行
//     }
//     return 0;
// }

























/*十三. 最短路径问题*/
/*
各最短路算法应用区别：
所求最短路径对象            边权                    算法(复杂度)
一个起点，一个终点      非负；无边权或边权为1   A*算法(<O((m + n)logn))，双向广搜(<O((m + n)logn))，贪心最优搜索(<O(m + n))      
一个起点到其他所有点    无边权或边权为1         BFS(O(m + n))
                      非负数                 Dijkstra算法-堆优化优先队列(O((m + n)logn))
                      含负数                 SPFA(<O(m*n)) 
所有点对之间           含负数                 Floyd-Warshall(O(n^3))
*/



/*BFS 一个起点到其他所有点, 无边权或边权为1*/
//1.最短路计数
//一个起点到所有其他点，且边权为 1 (无边权) -- 邻接表 + BFS
//思路：边确定最短路距离，边更新符合最短路的路径个数
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e6 + 5, mod = 100003, INF = 0x3f3f3f3f;
// int n, m, s = 1;
// int dis[N], cnt[N], vis[N];
// vector<int> e[N];
// void bfs()
// {
//     memset(dis, 0x3f, sizeof(dis));
//     cnt[1] = 1, vis[1] = 1;
//     queue<int> q;
//     q.push(1);
//     while(!q.empty())
//     {
//         int now = q.front(); q.pop();
//         for(int i = 0; i < e[now].size(); i++)
//         {
//             int to = e[now][i];
//             if(!vis[to])//固定最短路距离
//             {
//                 vis[to] = 1;
//                 dis[to] = dis[now] + 1;
//                 q.push(to);
//             }
//             if(dis[to] == dis[now] + 1)//最短路径数叠加，把 now点 的路径数全部加到 to点 上
//                 cnt[to] = (cnt[to] + cnt[now]) % mod;
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     while(m--)
//     {
//         int u, v;
//         cin >> u >> v;
//         e[u].push_back(v);
//         e[v].push_back(u); //无向图
//     }
//     bfs();
//     for(int i = 1; i <= n; i++)
//     {
//         if(i != 1 && dis[i] == INF) cout << "0\n";
//         else cout << cnt[i] % mod << "\n";
//     }
//     return 0;
// }











/*Floyd 算法（多源最短路径问题） -- O(n^3) -- 求得所有点对之间的最短路径 -- 三重循环，只适用于小规模的稠密图(n < 300)
应用 动态规划 的思路，定义 dp[k][i][j] 为从第一个点遍历到第 k 个点时，从点 i 到点 j 的最短距离(最小边权和)
从含有 k - 1 个点的子图拓展到含 k 个点的图，若经历点k使得距离更短，则将点 k 接入到 i -> j 路径上，假设 i -> k -> j
此时 distance(i -> k -> j) < distance(i -> j)，则 k 点应用到该状态上
转移方程为 dp[k][i][j] = min(dp[k - 1][i][j], dp[k - 1][i][k] + dp[k - 1][k][j])
由于第一维状态只与第 k - 1 层状态有关，故可以滚动掉: dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

最短距离(处理所有点对间的距离大小)：
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
typedef long long ll;
const int N = 305;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, q;
ll dp[N][N];

void floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

int main()
{
    untie();
    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = min(dp[u][v], w);//防止有重边
    }
    floyd();
    while(q--)
    {
        int s, t;
        cin >> s >> t;
        if(dp[s][t] == INF) cout << "-1";
        else if(s == t) cout << "0";
        else cout << dp[s][t];
        cout << '\n';
    }
    return 0;
}



传递闭包(处理所有点对间的优先关系)：
    在交际网络中，给定若干个元素和若干对二元关系，且关系具有传递性（假如a 与 b有关系，b与c有关系，那么a和c必定有关系）。”
    通过传递性推导出尽量多的元素之间的关系"的问题被称为传递闭包。
    建立邻接矩阵d，其中 d[i, j] = 1 表示 i 与 j 有关系，d[i, j] = 0表示 i 与 j 没有关系。特别的，d[i, i]始终为 1。
    核心代码：
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] |= d[i][k] & d[k][j];
    bitset优化(从n<500优化到接受n<=1000)：

*/

//1.Cow Contest(传递闭包)
//必须知道任一一头奶牛与其他所有奶牛之间的胜负关系，并依个判定其排名是否确认，最后输出个数即可
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 105;
// int n, m;
// bool dp[N][N];
// void floyd()
// {
//     for(int k = 1; k <= n; k++)//遍历所有点作中间点k，若经历k点能连通 i->k->j 则说明 i 与 j 连通
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= n; j++)
//                 dp[i][j] |= dp[i][k] & dp[k][j];
//                 //即 if(dp[i][k] && dp[k][j]) dp[i][j] = 1;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     while(m--)
//     {
//         int s, t;
//         cin >> s >> t;
//         dp[s][t] = 1;
//     }
//     floyd();
//     //判定点 i 是否以确定排名：点 i 与其他n-1个点是否都具有连通关系
//     int ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for(int j = 1; j <= n; j++)
//             if(dp[i][j] || dp[j][i]) ++cnt;
//         if(cnt == n - 1) ++ans;
//     }
//     cout << ans << endl;
//     return 0;
// }
//bitset优化
// #include <iostream>
// #include <algorithm>
// #include <bitset>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 105;
// int n, m;
// bitset<N> dp[N];//N串长度为N的二进制，可以对一整串二进制操作，故省去第 j 层循环
// void floyd()
// {
//     for(int k = 1; k <= n; k++)//遍历所有点作中间点k，若经历k点能连通 i->k->j 则说明 i 与 j 连通
//         for(int i = 1; i <= n; i++)
//             if(dp[i][k]) 
//                 dp[i] |= dp[k];            
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     while(m--)
//     {
//         int s, t;
//         cin >> s >> t;
//         dp[s][t] = 1;
//     }
//     floyd();
//     //判定点 i 是否已确定排名：点 i 与其他n-1个点是否都具有连通关系
//     int ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for(int j = 1; j <= n; j++)
//             if(dp[i][j] || dp[j][i]) ++cnt;
//         if(cnt == n - 1) ++ans;
//     }
//     cout << ans;
//     return 0;
// }



//2.MPI Maelstrom
//*题意：本题在于题意难解，给一个邻接矩阵(输入给半边)，让你来求从点 1 到 其他点 所花费最短时间集里面的的最大值
//解法：由于 n <= 100 ，用编码简单的floyd更方便
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdlib>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 105;
// const ll INF = 0x4ffffffffLL;
// int n, m;
// ll dp[N][N];
// char str[N];
// void floyd()
// {
//     for(int k = 1; k <= n; k++)
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= n; j++)
//                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
// }
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 2; i <= n; i++)
//         for(int j = 1; j < i; j++)
//         {
//             cin >> str;
//             if(str[0] != 'x') dp[i][j] = dp[j][i] = 1LL * atoi(str);
//             else dp[i][j] = dp[j][i] = INF;
//         }
//     floyd();
//     ll _max = 0;
//     for(int i = 1; i <= n; i++) _max = max(_max, dp[1][i]);
//     cout << _max;
//     return 0;
// }








/*dijkstra算法（单源最短路径问题） -- BFS + 优先队列（方便得到距 起点s 距离最小的点）
应用场景：
    稀疏图：n 较大，用 dijkstra + 优先队列，便于获取最短距离的点  O((m + n)logn)
    稠密图：n^2 约等于 m，不用优先队列，直接在所有节点中找距离最短的点  O(n^2)


dijkstra + 优先队列 的模板(图论题一般输入输出很多，用cstdio完成更好)

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

const ll inf = (1LL << 31) - 1;
const int N = 1e5 + 5;

struct edge{
    int to; ll w;
    edge(int a = 0, ll b = 0){ to = a, w = b;}
};
struct node{
    int id; ll dis;//dis 为该点到起点的距离
    node(int a = 0, ll b = 0){ id = a, dis = b;}
    bool operator <(const node &x)const{ return dis > x.dis;}
};

int n, m, s = 1;//起点s
int pre[N];//pre[i] 记录前驱节点即 点 i 的上一个点的编号，用于打印路径
ll dis[N];//记录 所有节点 到 起点s 的距离
bool vis[N];//记录是否已找到 节点i 的 最短距离
vector<edge> e[N];

void print_path(int t)//从 终点n 递归打印
{
    if(t == s) { printf("%d", s); return;}
    print_path(pre[t]);
    printf("%d ", t);
}

void dijkstra()
{
    for(int i = 0; i <= n; i++) {dis[i] = inf, vis[i] = 0;}
    dis[s] = 0;
    priority_queue<node> q;
    q.push(node(s, dis[s]));
    while(!q.empty())
    {
        node u = q.top(); q.pop();
        if(vis[u.id]) continue;
        vis[u.id] = 1;
        for(int i = 0; i < e[u.id].size(); i++)//遍历邻居
        {
            edge ne = e[u.id][i];
            if(!vis[ne.to] && dis[ne.to] > u.dis + ne.w)//更新邻居点的最短距离
            {
                dis[ne.to] = u.dis + ne.w;
                q.push(node(ne.to, dis[ne.to]));
                pre[ne.to] = u.id;
            }
        }
    }
    // print_path(n);//打印路径
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i <= n; i++) e[i].clear();
    for(int i = 0; i < m; i++)
    {
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        e[u].push_back(edge(v, w));
        // e[v].push_back(edge(u, w)); //双向边
    }
    dijkstra();
    for(int i = 1; i <= n; i++) 
    {
        if(i != 1) printf(" ");
        printf("%lld", dis[i]);
    }
    return 0;
}

*/
//1.Til the Cows Come Home
//要分析出这是个无向图
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const ll inf = (1LL << 31) - 1;
// const int N = 1e3 + 5;

// struct edge{
//     int to; ll w;
// };
// struct node{
//     int id; ll dis;//dis 为该点到起点的距离
//     bool operator <(const node &x)const{ return dis > x.dis;}
// };

// int n, m, s = 1;//起点s
// ll dis[N];//记录 所有节点 到 起点s 的距离
// bool vis[N];//记录是否已找到 节点i 的 最短距离
// vector<edge> e[N];

// void dijkstra()
// {
//     for(int i = 1; i <= n; i++) dis[i] = inf;
//     dis[s] = 0;
//     priority_queue<node> q;
//     node sta = {s, 0};
//     q.push(sta);
//     while(!q.empty())
//     {
//         node u = q.top(); q.pop();
//         if(vis[u.id]) continue;
//         vis[u.id] = 1;
//         for(int i = 0; i < e[u.id].size(); i++)//遍历邻居
//         {
//             edge ne = e[u.id][i];
//             if(!vis[ne.to] && dis[ne.to] > u.dis + ne.w)//更新邻居点的最短距离
//             {
//                 dis[ne.to] = u.dis + ne.w;
//                 node next = {ne.to, dis[ne.to]};
//                 q.push(next);
//             }
//         }
//     }
// }

// int main()
// {
//     scanf("%d%d", &m, &n);
//     for(int i = 0; i < m; i++)
//     {
//         int u, v; ll w;
//         scanf("%d%d%lld", &u, &v, &w);
//         edge e1 = {v, w}, e2 = {u, w};
//         e[u].push_back(e1);
//         e[v].push_back(e2); //双向边
//     }
//     dijkstra();
//     printf("%lld", dis[n]);
//     return 0;
// }



//*2.Heavy Transportation
//题意：图里有不同载重限度的路段，一条完整的路上由不同的路段连接，货车重量需能经过其中最小载重限度的路段，整条路才算连通
//      求 1 ~ n 路上 各路段都采取最大限重连接后 的最小限重路段的限重，即邻居点找最长边连接
//最长路径问题，题目较特殊，采用非优先队列写法，用邻接矩阵存储方便
//实际上该题应用最大生成树更合适，但现在拿来练习 Dijkstra算法的变形写法，有点类似动态规划。
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const int N = 1e3 + 5;
// int n, m, s = 1;//起点s
// int dp[N];//dp[i] 定义为 从 起点1 到 点i 路上的最小限重值
// int gra[N][N];
// bool vis[N];
// void dijkstra()
// {
//     for(int i = 1; i <= n; i++) dp[i] = gra[1][i];//状态初始化为直连情况下的限重值，这样来对比非直连哪个限重更高
//     memset(vis, 0, sizeof(vis));
//     dp[1] = 0;
//     vis[1] = 1;
//     //最大生成树，遍历 n-1 次，即取前 n - 1 大的边来连通 n 个点
//     for(int i = 1; i < n; i++)
//     {
//         int _max = -1, ne = 0;
//         for(int j = 1; j <= n; j++)//寻找最大限重的中间点
//             if(!vis[j] && dp[j] > _max)
//                 _max = dp[j], ne = j;
//         vis[ne] = 1;
//         for(int j = 1; j <= n; j++)//更新dp状态，如果经历 中间点ne 的 非直连路中最小限重值更大，就取该非直连路径
//             dp[j] = max(dp[j], min(dp[ne], gra[ne][j]));
//     }
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     for(int k = 1; k <= T; k++)
//     {
//         scanf("%d%d", &n, &m);
//         memset(gra, -1, sizeof(gra));//求最长路径，初始化为无穷小，可判断 点i 与 点j 是否为邻居
//         for(int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             scanf("%d%d%d", &u, &v, &w);// All streets can be travelled in both directions.无向图
//             gra[u][v] = gra[v][u] = w;// gra[u][v] = gra[v][u] = max(gra[u][v], w);//该题无重边
//         }
//         dijkstra();
//         printf("Scenario #%d:\n%d\n\n", k, dp[n]);//Terminate the output for the scenario with a blank line.案例之间有空行
//     }
//     return 0;
// }
//前向星或邻接表 + 优先队列
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// const int inf = (1LL << 31) - 1;
// const int N = 1e5 + 5;
// struct edge{
//     int to, w;
// };
// struct node{
//     int id, dis;//dis 为该点到起点的距离
//     bool operator <(const node &x)const{ return dis < x.dis;}
// };
// int n, m, s = 1;
// int dis[N];//记录 所有节点 到 起点s 的距离
// bool vis[N];//记录是否已找到 节点i 的 最短距离
// vector<edge> e[N];
// void dijkstra()
// {
//     for(int i = 0; i <= n; i++) {dis[i] = 0, vis[i] = 0;}
//     dis[s] = inf;
//     priority_queue<node> q;
//     node sta = {s, dis[s]};
//     q.push(sta);
//     while(!q.empty())
//     {
//         node u = q.top(); q.pop();
//         if(vis[u.id]) continue;
//         vis[u.id] = 1;
//         for(int i = 0; i < e[u.id].size(); i++)//遍历邻居
//         {
//             edge ne = e[u.id][i];
//             if(vis[ne.to]) continue;
//             if(dis[ne.to] < min(dis[u.id], ne.w))
//             {
//                 dis[ne.to] = min(dis[u.id], ne.w);
//                 node next = {ne.to, dis[ne.to]};
//                 q.push(next);
//             }
//         }
//     }
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     for(int k = 1; k <= T; k++)
//     {
//         scanf("%d%d", &n, &m);
//         for(int i = 0; i <= n; i++) e[i].clear();
//         for(int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             scanf("%d%d%d", &u, &v, &w);
//             edge e1 = {v, w}, e2 = {u, w};
//             e[u].push_back(e1);
//             e[v].push_back(e2); //双向边
//         }
//         dijkstra();
//         printf("Scenario #%d:\n%d\n\n", k, dis[n]);//Terminate the output for the scenario with a blank line.案例之间有空行
//     }
//     return 0;
// }



//*3.昂贵的聘礼（Dijkstra + 枚举限制区间）
//题意：有多样物品，每样物品可能有若干件替代品(以更低代价购得原品)，寻找 购得第一件物品所需最低总价钱的购买方案
//      并且 能否购买i物品 受限于 购买的前一样物品j 与 i物品的地位系数差，|p[i] - p[j]| <= limit 才能购买
//分析：对于第一件物品，它是必购买的，也就是购买的终点，可直接购买(增设原点)，也可购买其替代品集合中的某一件以代替购买
//     故图中含有 原点0到每个物品的单向边(边权为物品本身的价钱) 和 物品间具有替代关系的单向边(边权为优惠价)
//重点：虽然对所有路径全域条件为 p[i] - limit <= p[j] <= p[i] + limit，但若直接以此为条件不符合题意，涉及区间长度并非 limit 而是 2*limit
//      故由于地位系数都是整数，对于一整条路径，满足题意的条件有 [p[i] - limit, p[j]] [p[i] - limit + 1, p[j] + 1] ··· [p[i], p[j] + limit]
//      所以存在多个基于不同松弛条件的最短路，现枚举不同的松弛条件(区间)，并从所得的所有最短路中选出最小代价的最短路。
//      而每条最短路必定经过 终点-点1，那么 对所有路径的全域范围 可简化为 只针对所有最短路的全域范围 [p[1] - limit, p[1] + limit]
//16ms
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int N = 105;
// struct edge{
//     int to; ll w;
//     edge(int a = 0, ll b = 0){ to = a, w = b;}
// };
// struct node{
//     int id; ll dis;
//     node(int a = 0, ll b = 0){ id = a, dis = b;}
//     bool operator <(const node &x)const{ return dis > x.dis;}
// };
// int n, limit, s = 0;
// int level[N];
// ll dis[N];
// bool vis[N];
// vector<edge> e[N];
// ll dijkstra(int l, int r)
// {
//     memset(dis, 0x3f, sizeof(dis));
//     memset(vis, 0, sizeof(vis));
//     dis[s] = 0;
//     priority_queue<node> q;
//     q.push(node(s, 0));
//     while(!q.empty())
//     {
//         node u = q.top(); q.pop();
//         if(vis[u.id]) continue;
//         vis[u.id] = 1;
//         for(int i = 0; i < e[u.id].size(); i++)
//         {
//             edge ne = e[u.id][i];
//             if(!vis[ne.to] && level[ne.to] >= l && level[ne.to] <= r && dis[ne.to] > u.dis + ne.w)
//             {
//                 dis[ne.to] = u.dis + ne.w;
//                 q.push(node(ne.to, dis[ne.to]));
//             }
//         }
//     }
//     return dis[1];//返回到达终点1的当前最小价值
// }
// int main()
// {
//     scanf("%d%d", &limit, &n);
//     for(int v = 1; v <= n; v++)
//     {
//         int k; ll w;
//         scanf("%lld%d%d", &w, &level[v], &k);
//         e[0].push_back(edge(v, w));
//         while(k--)
//         {
//             int u; ll c;
//             scanf("%d%lld", &u, &c);
//             e[u].push_back(edge(v, c));
//         }
//     }
//     ll ans = INF;
//     for(int l = level[1] - limit; l <= level[1]; l++)
//         ans = min(ans, dijkstra(l, l + limit));
//     printf("%lld", ans);
//     return 0;
// }
//79ms(由于 N <= 100，完全可以用邻接矩阵，结合dp思想解决。)
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int N = 105;
// int n, limit, s = 0;
// int level[N];
// ll dis[N], gra[N][N];
// bool vis[N];
// ll dijkstra(int l, int r)
// {
//     memset(dis, 0x3f, sizeof(dis));
//     memset(vis, 0, sizeof(vis));
//     dis[s] = 0;
//     for(int i = 0; i <= n; i++)//从 自设原点0 到 点n 共 n + 1 个点，也就是子图大小拓展至全图大小
//     {
//         int ind = -1;
//         for(int j = 0; j <= n; j++)//寻找当前未使用的最短边，同时也是在确定以ind为终点的最短路是否已确定
//             if(!vis[j] && (ind == -1 || dis[j] < dis[ind])) ind = j;
//         vis[ind] = 1;//不论是直连(初始状态)或非直连(已经过更新)，以ind为终点的最短路此时便能确定
//         for(int j = 1; j <= n; j++)//遍历所有终点的最短路，更新其状态，判断接入或不接 0与ind的直连边(或者是终点为ind的最短路径)
//             if(level[j] >= l && level[j] <= r)
//                 dis[j] = min(dis[j], dis[ind] + gra[ind][j]);
//     }
//     return dis[1];
// }
// int main()
// {
//     memset(gra, 0x3f, sizeof(gra));
//     scanf("%d%d", &limit, &n);
//     for(int v = 1; v <= n; v++)
//     {
//         int u, k; ll c, w;
//         scanf("%lld%d%d", &w, &level[v], &k);
//         gra[0][v] = w;
//         while(k--) scanf("%d%lld", &u, &c), gra[u][v] = c;
//     }
//     ll ans = INF;
//     for(int l = level[1] - limit; l <= level[1]; l++)
//         ans = min(ans, dijkstra(l, l + limit));
//     printf("%lld", ans);
//     return 0;
// }



//4.Frogger（最短路径中最长路段最小值 -- 最短路极大极小问题）
//题意：求最短路中最长路段的最小值，起点1 与 终点2 均唯一确定
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <cmath>
// using namespace std;
// typedef double db;
// const int N = 205;
// struct p{
//     int x, y;
//     p(int a = 0, int b = 0){ x = a, y = b;}
// }point[N];
// db getdis(p e1, p e2) { return 1.0 * (e1.x - e2.x) * (e1.x - e2.x) + 1.0 * (e1.y - e2.y) * (e1.y - e2.y);}
// int n, T = 0, s = 1, sx, sy, ex, ey;
// db dis[N];
// bool vis[N];
// db dijkstra()
// {
//     dis[s] = 0;
//     memset(vis, 0, sizeof(vis));
//     for(int i = 2; i <= n; i++) dis[i] = getdis(point[1], point[i]);
//     for(int i = 1; i <= n; i++)//子图拓展
//     {
//         int ind = -1;
//         for(int j = 1; j <= n; j++)//找现存最短路径
//             if(!vis[j] && (ind == -1 || dis[j] < dis[ind])) ind = j;
//         vis[ind] = 1;
//         for(int j = 1; j <= n; j++)//更新最短路中最大路段的最小值
//             dis[j] = min(dis[j], max(dis[ind], getdis(point[ind],point[j])));
//     }    
//     return sqrt(dis[2]);
// }
// int main()
// {
//     while(~scanf("%d", &n), n)
//     {
//         for(int i = 1, x, y; i <= n; i++)
//             scanf("%d%d", &x, &y), point[i] = p(x, y);
//         printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++T, dijkstra());
//     }
//     return 0;
// }



//*5.通往奥格瑞玛的道路 (最短路 + 二分答案 求解极大极小问题)
//题意：在所有符合血量条件的路径中，都有一个城市最大收费 x，得出其在所有路径中的最小值
//思路：用dijkstra维护血量消耗，尽量使其符合血量条件；二分最大收费 x，大于该 x 的二分值的城市不走，二分完毕后得到的便是最小值。
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const int N = 1e4 + 5;
// struct edge{
//     int to; ll w;
//     edge(int a = 0, ll b = 0){ to = a, w = b;}
// };
// struct node{
//     int id; ll dis;//dis 为该点到起点的距离
//     node(int a = 0, ll b = 0){ id = a, dis = b;}
//     bool operator <(const node &x)const{ return dis > x.dis;}
// };
// int n, m, blood, s = 1;//起点s
// ll dis[N], cost[N];
// bool vis[N];
// vector<edge> e[N];
// bool dijkstra(ll mid)
// {
//     if(mid < cost[s]) return 0;//优化，若起点都走不了，就返回
//     memset(dis, 0x3f, sizeof(dis));
//     memset(vis, 0, sizeof(vis));
//     dis[s] = 0;
//     priority_queue<node> q;
//     q.push(node(s, dis[s]));
//     while(!q.empty())
//     {
//         node u = q.top(); q.pop();
//         if(vis[u.id]) continue;
//         vis[u.id] = 1;
//         for(int i = 0; i < e[u.id].size(); i++)
//         {
//             edge ne = e[u.id][i];
//             if(!vis[ne.to] && mid >= cost[ne.to] && dis[ne.to] > u.dis + ne.w)
//             {
//                 dis[ne.to] = u.dis + ne.w;
//                 if(ne.to == n) return dis[n] <= blood;//到n点
//                 q.push(node(ne.to, dis[ne.to]));
//             }
//         }
//     }
//     return 0;//无法到达点 n
// }
// int main()
// {
//     ll l = 1, r = 1, ans = -1;
//     scanf("%d%d%d", &n, &m, &blood);
//     for(int i = 1; i <= n; i++) scanf("%lld", &cost[i]), r = max(r, cost[i]);
//     for(int i = 0; i < m; i++)
//     {
//         int u, v; ll w;
//         scanf("%d%d%lld", &u, &v, &w);
//         e[u].push_back(edge(v, w));
//         e[v].push_back(edge(u, w)); //双向边
//     }
//     while(l <= r)
//     {
//         ll mid = (l + r) >> 1;
//         if(dijkstra(mid)) r = mid - 1, ans = mid;
//         else l = mid + 1;
//     }
//     if(ans == -1) printf("AFK");//一个符合条件的路径都没有
//     else printf("%lld\n", ans);
//     return 0;
// }




















/* A*算法（单起点单终点问题） -- 贪心最优搜索(基于估价函数h(i)) + BFS(Dijkstra) + 优先队列
重点：此时进入优先队列的不是 起点到当前点的距离，而是 当前点到终点的距离。
      A*算法的实现关键在于 h函数 的设计是否符合题意。


*/
















/*十四. 线段树、树状数组*/
/*
//https://blog.csdn.net/weixin_45697774/article/details/104274713?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167533467316782428699964%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167533467316782428699964&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-104274713-null-null.142^v72^pc_new_rank,201^v4^add_ask&utm_term=%E7%BA%BF%E6%AE%B5%E6%A0%91&spm=1018.2226.3001.4187
线段树是一种基于 分治思想 的 二叉树(二分)，用于在 区间 上进行信息的统计(对于 区间操作 的通用解法)。
它把一些对于区间（或者线段）的修改、维护，从 O(N) 的时间复杂度变成 O(logN)
线段树 可以理解为 分治思想 + 二叉树结构 + Lazy-Tag技术 

1.线段树的每一个节点都代表一个区间
2.线段树具有的唯一根节点，代表的区间是整个统计范围，[1，n]
3.线段树的每个叶节点都代表长度为 1 的元区间 [x，x]
4.对于每个内部节点 [l，r]，它的左节点是 [l, mid]，右节点是 [mid, r]，其中 mid = (l + r) / 2(向下取整)
一个线段树基本结构有：信息和节点的存储、信息合并、信息更新、建树、单点修改、区间查询等

线段树的每个区间维护自己的 左右边界 和 区间总和\最大值\最小值等，假设当前节点维护的区间为[L, R]，
则 mid = (L + R) / 2，他的左子节点维护[L, mid]，右子节点维护[mid + 1, R]。

操作分析 O(logn)：
    线段树构造 build() 分治构造 ，pushup() (从下往上传递区间信息)
    单点修改        ：直接修改叶子节点上元素的值，然后从下往上更新线段树
    区间查询 query()：查询[L, R]信息(最值或区间和等)，从根节点区间[1, n]开始递归，设为[pl, pr]，每次递归操作分两种情况：
        [L, R] 完全覆盖 [pl, pr]，直接返回 编号p 所代表的值；
        [L, R] 与 [pl, pr] 部分重叠，那么二分搜索有重叠的部分。若 L < pr，左子节点与区间有重叠，则继续递归左子。若 R > pl，继续递归右子
    区间修改update()：用标记数组 tag[i] 统计记录对 区间i 的修改(延迟修改)，仅当修改操作间产生重叠或冲突时不得不向子节点传递 pushdown() (从上往下传递)

*/

//区间修改 + 区间查询 模板
/*
//有注释
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
const int N = 1e5 + 10;
ll n, m;
ll a[N];//元素值数列，从下标1开始
ll tree[N << 2], tag[N << 2];
il ll ls(ll p) { return p << 1;}       //定位左子：p * 2
il ll rs(ll p) { return p << 1 | 1;}   //定位右子：p * 2 + 1
il void addtag(ll p, ll pl, ll pr, ll d) //打标记同时更新tree
{
    tag[p] += d;//区间p增量加d
    tree[p] += d * (pr - pl + 1);//[pl, pr]区间p上的每个值都加 d，计算区间和
}
il void pushup(ll p) //向上更新编号为 p 的 “区间值”
{
    tree[p] = tree[ls(p)] + tree[rs(p)]; //区间和
    // tree[p] = min(tree[ls(p)], tree[rs(p)]); //区间最值
}
il void pushdown(ll p, ll pl, ll pr) //不能覆盖时，将tag传给子树
{
    if(tag[p])
    {
        ll mid = (pl + pr) >> 1;
        addtag(ls(p), pl, mid, tag[p]); //传给左子树
        addtag(rs(p), mid + 1, pr, tag[p]); //传给右子树
        tag[p] = 0; //传走后自身清零
    }
}
void build(ll p, ll pl, ll pr) //p为节点编号，指向区间[pl, pr]
{
    tag[p] = 0;
    if(pl == pr) { tree[p] = a[pl]; return;} //叶子节点
    ll mid = (pl + pr) >> 1; //二分分治
    build(ls(p), pl, mid); //左子
    build(rs(p), mid + 1, pr); //右子
    pushup(p); //从下往上传值
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d) //区间修改，给[L, R]每个元素都加上 d
{
    if(pl >= L && pr <= R) //完全覆盖则打标记
    {
        addtag(p, pl, pr, d);
        return;
    }
    pushdown(p, pl, pr); //不能覆盖时，将tag传给子树
    ll mid = (pl + pr) >> 1;
    if(mid >= L) update(L, R, ls(p), pl, mid, d); //有重叠则递归左子树
    if(mid < R) update(L, R, rs(p), mid + 1, pr, d); // (mid + 1 <= R) 有重叠则递归右子树
    pushup(p); //递归的最后向上更新
}
ll query(ll L, ll R, ll p, ll pl, ll pr) //查询 [L, R] 区间和
{
    if(pl >= L && pr <= R) return tree[p];
    pushdown(p, pl, pr);
    ll res = 0;
    ll mid = (pl + pr) >> 1;
    if(mid >= L) res += query(L, R, ls(p), pl, mid);
    if(mid < R) res += query(L, R, rs(p), mid + 1, pr);
    return res;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    while(m--)
    {
        ll op, L, R, d;
        scanf("%lld", &op);//操作数
        if(op == 1) //区间修改，加d
        {
            scanf("%lld%lld%lld", &L, &R, &d);
            update(L, R, 1, 1, n, d);
        }
        else //区间和查询
        {
            scanf("%lld%lld", &L, &R);
            printf("%lld\n", query(L, R, 1, 1, n));
        }
    }
    return 0;
}

//无注释版
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
const int N = 1e5 + 10;
ll a[N], tree[N << 2], tag[N << 2];
il ll ls(ll p){ return p << 1;} 
il ll rs(ll p){ return p << 1 | 1;} 
il void addtag(ll p, ll pl, ll pr, ll d){ tag[p] += d, tree[p] += d * (pr - pl + 1);}
il void push_up(ll p){ tree[p] = tree[ls(p)] + tree[rs(p)];}
il void push_down(ll p, ll pl, ll pr)
{
    if(tag[p])
    {
        ll mid = (pl + pr) >> 1;
        addtag(ls(p), pl, mid, tag[p]);
        addtag(rs(p), mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}
void build(ll p, ll pl, ll pr)
{
    tag[p] = 0;
    if(pl == pr)
    {
        tree[p] = a[pl];
        return ;
    }
    ll mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
{
    if(L <= pl && pr <= R){ addtag(p, pl, pr, d); return;}
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if(L <= mid) update(L, R, ls(p), pl, mid, d);
    if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
    push_up(p);
}
ll query(ll L, ll R, ll p, ll pl, ll pr)
{
    if(pl >= L && R >= pr) return tree[p];
    push_down(p, pl, pr);
    ll res = 0;
    ll mid = (pl + pr) >> 1;
    if(L <= mid) res += query(L, R, ls(p), pl, mid);
    if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
    return res;
}
int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    while(m--)
    {
        ll q, L, R, d;
        scanf("%lld", &q);
        if(q == 1)
        {
            scanf("%lld%lld%lld", &L, &R, &d);
            update(L, R, 1, 1, n, d);
        }else
        {
            scanf("%lld%lld", &L, &R);
            printf("%lld\n", query(L, R, 1, 1, n));
        }
    }
    return 0;
}

//应对 操作多(标记多)时，标记之间会有互相影响，产生不同优先级的处理顺序，没办法单独列出addtag()函数。
//结构体模板
//有注释
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
#define ls (p << 1)
#define rs (p << 1 | 1)
const int N = 1e5 + 10;
struct node{
    ll sum;//要查询的值，区间和、区间乘等
    ll sum_tag, mul_tag;//lazy标记(对区间内的个值的操作)，加值、乘值等
    node(ll a = 0, ll b = 0, ll c = 0) {sum = a, sum_tag = b, mul_tag = c;}
}tree[N << 2];
ll n, m, mod;

il void push_up(ll p) //计算 查询值
{
    tree[p].sum = (tree[ls].sum + tree[rs].sum) % mod;
}
il void push_down_change(ll p, ll u, ll pl, ll pr) //方便push_down()的修改作用到左右子树，传递方向 u -> p
{
    //区间值更新
    tree[p].sum = (tree[p].sum * tree[u].mul_tag % mod + (pr - pl + 1) * tree[u].sum_tag % mod) % mod;
    //标记积累
    tree[p].sum_tag = (tree[u].sum_tag + tree[p].sum_tag * tree[u].mul_tag % mod) % mod;
    tree[p].mul_tag = tree[p].mul_tag * tree[u].mul_tag % mod;
}
il void push_down(ll p, ll pl, ll pr) //标记传递至左右子树 与 子树查询值的更新
{
    if(tree[p].sum_tag != 0 || tree[p].mul_tag != 1) //小优化，所有标记都为初始值时无需传递
    {
        //区间值更新，传下所有标记，最后清除当前所有标记
        ll mid = (pl + pr) >> 1;
        push_down_change(ls, p, pl, mid);
        push_down_change(rs, p, mid + 1, pr);
        tree[p].sum_tag = 0, tree[p].mul_tag = 1;
    }
}
void build(ll p, ll pl, ll pr) //直接读取叶子结点的值，省去原数列空间(除非原数列值有用)
{
    tree[p] = node(0, 0, 1);
    if(pl == pr)
    {
        scanf("%lld", &tree[p].sum);
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(ls, pl, mid);
    build(rs, mid + 1, pr);
    push_up(p);//计算初始查询值(区间值)
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d, ll op)
{
    if(L <= pl && R >= pr)
    {
        //更新区间值 并 添加标记
        if(op == 1)//乘值操作
        {
            tree[p].sum = tree[p].sum * d % mod;
            tree[p].sum_tag = tree[p].sum_tag * d % mod; //对已有的和标记产生影响
            tree[p].mul_tag = tree[p].mul_tag * d % mod; 
        }
        else//加值操作
        {
            tree[p].sum = (tree[p].sum + d * (pr - pl + 1) % mod) % mod;
            tree[p].sum_tag = (tree[p].sum_tag + d) % mod;
        }
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if(L <= mid) update(L, R, ls, pl, mid, d, op);
    if(R > mid) update(L, R, rs, mid + 1, pr, d, op);
    push_up(p);
}
ll query(ll L, ll R, ll p, ll pl, ll pr)
{
    if(L <= pl && R >= pr) return tree[p].sum % mod;
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1, res = 0;
    if(L <= mid) res = (res + query(L, R, ls, pl, mid)) % mod;
    if(R > mid) res = (res + query(L, R, rs, mid + 1, pr)) % mod;
    return res % mod;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &mod);
    build(1, 1, n);
    while(m--)
    {
        ll q, L, R, d;
        scanf("%lld%lld%lld", &q, &L, &R);
        if(q == 3) printf("%lld\n", query(L, R, 1, 1, n));
        else scanf("%lld", &d), update(L, R, 1, 1, n, d, q);
    }
    return 0;
}

//无注释(可以再参照题目 序列操作 的代码)
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
#define ls (p << 1)
#define rs (p << 1 | 1)
const int N = 1e5 + 10;
struct node{
    ll sum;//要查询的值，区间和、区间乘等
    ll sum_tag, mul_tag;//lazy标记(对区间内的个值的操作)，加值、乘值等
    node(ll a = 0, ll b = 0, ll c = 0) {sum = a, sum_tag = b, mul_tag = c;}
}tree[N << 2];
ll n, m, mod;

il void push_up(ll p)
{
    tree[p].sum = (tree[ls].sum + tree[rs].sum) % mod;
}
il void push_down_change(ll p, ll u, ll pl, ll pr)
{
    tree[p].sum = (tree[p].sum * tree[u].mul_tag % mod + (pr - pl + 1) * tree[u].sum_tag % mod) % mod;
    tree[p].sum_tag = (tree[u].sum_tag + tree[p].sum_tag * tree[u].mul_tag % mod) % mod;
    tree[p].mul_tag = tree[p].mul_tag * tree[u].mul_tag % mod;
}
il void push_down(ll p, ll pl, ll pr)
{
    if(tree[p].sum_tag != 0 || tree[p].mul_tag != 1)
    {
        ll mid = (pl + pr) >> 1;
        push_down_change(ls, p, pl, mid);
        push_down_change(rs, p, mid + 1, pr);
        tree[p].sum_tag = 0, tree[p].mul_tag = 1;
    }
}
void build(ll p, ll pl, ll pr)
{
    tree[p] = node(0, 0, 1);
    if(pl == pr)
    {
        scanf("%lld", &tree[p].sum);
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(ls, pl, mid);
    build(rs, mid + 1, pr);
    push_up(p);
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d, ll op)
{
    if(L <= pl && R >= pr)
    {
        if(op == 1)
        {
            tree[p].sum = tree[p].sum * d % mod;
            tree[p].sum_tag = tree[p].sum_tag * d % mod;
            tree[p].mul_tag = tree[p].mul_tag * d % mod; 
        }
        else
        {
            tree[p].sum = (tree[p].sum + d * (pr - pl + 1) % mod) % mod;
            tree[p].sum_tag = (tree[p].sum_tag + d) % mod;
        }
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if(L <= mid) update(L, R, ls, pl, mid, d, op);
    if(R > mid) update(L, R, rs, mid + 1, pr, d, op);
    push_up(p);
}
ll query(ll L, ll R, ll p, ll pl, ll pr)
{
    if(L <= pl && R >= pr) return tree[p].sum % mod;
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1, res = 0;
    if(L <= mid) res = (res + query(L, R, ls, pl, mid)) % mod;
    if(R > mid) res = (res + query(L, R, rs, mid + 1, pr)) % mod;
    return res % mod;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &mod);
    build(1, 1, n);
    while(m--)
    {
        ll q, L, R, d;
        scanf("%lld%lld%lld", &q, &L, &R);
        if(q == 3) printf("%lld\n", query(L, R, 1, 1, n));
        else scanf("%lld", &d), update(L, R, 1, 1, n, d, q);
    }
    return 0;
}

*/

//1.P3374 树状数组 1
//线段树写法(855ms)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// const int N = 5e5 + 10;
// ll a[N], tree[N << 2], tag[N << 2];
// il ll ls(ll p){ return p << 1;} 
// il ll rs(ll p){ return p << 1 | 1;} 
// il void addtag(ll p, ll pl, ll pr, ll d){ tag[p] += d, tree[p] += d * (pr - pl + 1);}
// il void push_up(ll p){ tree[p] = tree[ls(p)] + tree[rs(p)];}
// il void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p])
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(ls(p), pl, mid, tag[p]);
//         addtag(rs(p), mid + 1, pr, tag[p]);
//         tag[p] = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tag[p] = 0;
//     if(pl == pr)
//     {
//         tree[p] = a[pl];
//         return ;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && pr <= R){ addtag(p, pl, pr, d); return;}
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(pl >= L && R >= pr) return tree[p];
//     push_down(p, pl, pr);
//     ll res = 0;
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) res += query(L, R, ls(p), pl, mid);
//     if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
//     return res;
// }
// int main()
// {
//     ll n, m;
//     scanf("%lld%lld", &n, &m);
//     for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
//     build(1, 1, n);
//     while(m--)
//     {
//         ll q, L, R, d;
//         scanf("%lld", &q);
//         if(q == 1)
//         {
//             scanf("%lld%lld", &L, &d);
//             update(L, L, 1, 1, n, d);
//         }else
//         {
//             scanf("%lld%lld", &L, &R);
//             printf("%lld\n", query(L, R, 1, 1, n));
//         }
//     }
//     return 0;
// }



//2. P1816 忠诚
//求线段区间最小值，修改传递函数push_up()即可
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int N = 1e5 + 10;
// ll a[N], tree[N << 2], tag[N << 2];
// il ll ls(ll p){ return p << 1;} 
// il ll rs(ll p){ return p << 1 | 1;} 
// il void addtag(ll p, ll pl, ll pr, ll d){ tag[p] += d, tree[p] += d * (pr - pl + 1);}
// il void push_up(ll p){ tree[p] = min(tree[ls(p)], tree[rs(p)]);}
// il void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p])
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(ls(p), pl, mid, tag[p]);
//         addtag(rs(p), mid + 1, pr, tag[p]);
//         tag[p] = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tag[p] = 0;
//     if(pl == pr)
//     {
//         tree[p] = a[pl];
//         return ;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && pr <= R){ addtag(p, pl, pr, d); return;}
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(pl >= L && R >= pr) return tree[p];
//     push_down(p, pl, pr);
//     ll res = INF;
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) res = min(res, query(L, R, ls(p), pl, mid));
//     if(R > mid) res = min(res, query(L, R, rs(p), mid + 1, pr));
//     return res;
// }
// int main()
// {
//     ll n, m;
//     scanf("%lld%lld", &n, &m);
//     for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
//     build(1, 1, n);
//     for(int i = 0; i < m; i++)
//     {
//         ll L, R;
//         scanf("%lld%lld", &L, &R);
//         printf(" %lld" + !i, query(L, R, 1, 1, n));
//     }
//     return 0;
// }



//3.开关
//初始数列为 0串，无需单独建树
//异或1 实现lazy标记状态切换 ，区间长度 - 原本亮灯的数量 = 现在亮灯的数量
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// const int N = 1e5 + 10;
// ll a[N], tree[N << 2], tag[N << 2];
// il ll ls(ll p){ return p << 1;} 
// il ll rs(ll p){ return p << 1 | 1;} 
// il void addtag(ll p, ll pl, ll pr, ll d){ tag[p] ^= 1, tree[p] = pr - pl + 1 - tree[p];}
// il void push_up(ll p){ tree[p] = tree[ls(p)] + tree[rs(p)];}
// il void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p])
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(ls(p), pl, mid, tag[p]);
//         addtag(rs(p), mid + 1, pr, tag[p]);
//         tag[p] = 0;
//     }
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && pr <= R){ addtag(p, pl, pr, d); return;}
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(pl >= L && R >= pr) return tree[p];
//     push_down(p, pl, pr);
//     ll res = 0;
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) res += query(L, R, ls(p), pl, mid);
//     if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
//     return res;
// }
// int main()
// {
//     ll n, m, q, L, R;
//     scanf("%lld%lld", &n, &m);
//     while(m--)
//     {
//         scanf("%lld%lld%lld", &q, &L, &R);
//         if(q) printf("%lld\n", query(L, R, 1, 1, n));
//         else update(L, R, 1, 1, n, 1);
//     }
//     return 0;
// }



//*4.线段树 2
//操作有 区间和，区间乘 以及 查询区间和
//重点在于如何维护lazy标记实现两种赋值操作，自然需要引入第二个标记实现区间乘
//对[L, R]每个数乘以 k，实际上就是 tree[p] = tree[p] * k % p，p 即区间[L, R]的编号
/*多操作问题解读（以加法和乘法操作为例）：
首先要记住，lazy标记是用于 当前编号 的 儿子区间 的 修改，当前区间的修改需引用 父区间 的标记
优先级关系：乘法（加法），因此添加标记时需要注意 积标记 对 和标记 的影响
和标记 与 积标记 的关系推导：从需求出发(查询的是什么) -- 查询和
此前区间值(可能已改变，并非特指初始化时的数列) X = al + ··· + ar，和操作 与 乘操作 都是对原数列各值作用。
不同情况下：
    添加标记时的更新 update()：
        1.此前无标记 + 添加 和\积标记: X' = al + ··· + ar + (r - l + 1) * d_sum 或 X' = (al + ··· + ar) * d_mul

        2.原和标记 + 和标记: X' = (al + ··· + ar) + (r - l + 1) * d_sum + (r - l + 1) * d_sum' = (al + ··· + ar) + (r - l + 1) * (d_sum + d_sum') 
                            = X + (r - l + 1) * (d_sum + d_sum') -- 和标记间累和
          原积标记 + 积标记：X' = X * d_mul * d_mul'

        3.原和标记 + 积标记：X' = (al + d_sum) * d_mul + (al+1 + d_sum) * d_mul ··· (ar + d_sum) * d_mul
                            = (al + ··· + ar) * d_mul + (r - l + 1) * d_sum * d_mul
                            = X * d_mul + (r - l + 1) * (d_sum * d_mul) -- 此处 新和标记 = 原和标记 * 新积标记
                            所以进行乘法操作时，除了 原乘法标记 的更新，还需要更新 原和标记
          原积标记 + 和标记：X' = (al * d_mul + d_sum) + (al+1 * d_mul + d_sum) ··· (ar * d_mul + d_sum) = (al + ··· + ar) * d_mul + (r - l + 1) * d_sum
                            = X * d_mul + (r - l + 1) * d_sum
                            结合 和+和，任何情况下，进行加和操作时，只需要更新 原和标记
    区间值更新，标记的传递与积累 push_down()：
        （此前区间值(含 原和标记，原积标记) =  X * d_mul + (r - l + 1) * d_sum * d_mul = X * mul_tag + (r-l+1) * sum_tag，其中 X 为 此前数列值和）
        由于这些标记的传递是统一的，同时的，互相影响的，需将两种标记的传递合并：
            可知，乘法标记向下传递时影响儿子的所有标记，因为 和标记 实际上是 原来要加的值d * 当前积标记自顶向下的累乘值
            所以，各标记积累：
                sum_tag = sum_tag' + sum_tag * mul_tag'，
                mul_tag = mul_tag * mul_tag'。
            区间值更新(基于新标记)：
                X' = X * mul_tag' + (r - l + 1) * sum_tag'。
*/
//结构体写法
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// const int N = 1e5 + 10;
// struct node{
//     ll sum;//要查询的值，区间和、区间乘等
//     ll sum_tag, mul_tag;//lazy标记(对区间内的个值的操作)，加值、乘值等
//     node(ll a = 0, ll b = 0, ll c = 0) {sum = a, sum_tag = b, mul_tag = c;}
// }tree[N << 2];
// ll n, m, mod;

// il void push_up(ll p) //计算 查询值
// {
//     tree[p].sum = (tree[ls].sum + tree[rs].sum) % mod;
// }
// il void push_down_change(ll p, ll u, ll pl, ll pr) //方便push_down()的修改作用到左右子树，传递方向 u -> p
// {
//     //区间值更新
//     tree[p].sum = (tree[p].sum * tree[u].mul_tag % mod + (pr - pl + 1) * tree[u].sum_tag % mod) % mod;
//     //标记积累
//     tree[p].sum_tag = (tree[u].sum_tag + tree[p].sum_tag * tree[u].mul_tag % mod) % mod;
//     tree[p].mul_tag = tree[p].mul_tag * tree[u].mul_tag % mod;
// }
// il void push_down(ll p, ll pl, ll pr) //标记传递至左右子树 与 子树查询值的更新
// {
//     if(tree[p].sum_tag != 0 || tree[p].mul_tag != 1) //小优化，所有标记都为初始值时无需传递
//     {
//         //区间值更新，传下所有标记，最后清除当前所有标记
//         ll mid = (pl + pr) >> 1;
//         push_down_change(ls, p, pl, mid);
//         push_down_change(rs, p, mid + 1, pr);
//         tree[p].sum_tag = 0, tree[p].mul_tag = 1;
//     }
// }
// void build(ll p, ll pl, ll pr) //直接读取叶子结点的值，省去原数列空间(除非原数列值有用)
// {
//     tree[p] = node(0, 0, 1);
//     if(pl == pr)
//     {
//         scanf("%lld", &tree[p].sum);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls, pl, mid);
//     build(rs, mid + 1, pr);
//     push_up(p);//计算初始查询值(区间值)
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d, ll op)
// {
//     if(L <= pl && R >= pr)
//     {
//         //更新区间值 并 添加标记
//         if(op == 1)//乘值操作
//         {
//             tree[p].sum = tree[p].sum * d % mod;
//             tree[p].sum_tag = tree[p].sum_tag * d % mod; //对已有的和标记产生影响
//             tree[p].mul_tag = tree[p].mul_tag * d % mod; 
//         }
//         else//加值操作
//         {
//             tree[p].sum = (tree[p].sum + d * (pr - pl + 1) % mod) % mod;
//             tree[p].sum_tag = (tree[p].sum_tag + d) % mod;
//         }
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d, op);
//     if(R > mid) update(L, R, rs, mid + 1, pr, d, op);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) return tree[p].sum % mod;
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1, res = 0;
//     if(L <= mid) res = (res + query(L, R, ls, pl, mid)) % mod;
//     if(R > mid) res = (res + query(L, R, rs, mid + 1, pr)) % mod;
//     return res % mod;
// }

// int main()
// {
//     scanf("%lld%lld%lld", &n, &m, &mod);
//     build(1, 1, n);
//     while(m--)
//     {
//         ll q, L, R, d;
//         scanf("%lld%lld%lld", &q, &L, &R);
//         if(q == 3) printf("%lld\n", query(L, R, 1, 1, n));
//         else scanf("%lld", &d), update(L, R, 1, 1, n, d, q);
//     }
//     return 0;
// }
//非结构体：
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// const int N = 1e5 + 10;
// ll n, m, mod;
// ll a[N], tree[N << 2], tag[N << 2], tag2[N << 2];
// il ll ls(ll p){ return p << 1;} 
// il ll rs(ll p){ return p << 1 | 1;} 
// il void addtag(ll p, ll pl, ll pr, ll d)
// {
//     tag[p] = (tag[p] + d) % mod, tree[p] = (tree[p] + d * (pr - pl + 1) % mod) % mod;
// }
// il void addtag2(ll p, ll pl, ll pr, ll d)//乘法标记影响加法标记
// {
//     tag[p] = tag[p] * d % mod, tag2[p] = tag2[p] * d % mod, tree[p] = tree[p] * d % mod;
// }
// il void push(ll p, ll pl, ll pr, ll u) //传值时同时计算加法和乘法，并且传递加法标记时，加法标记受原乘法标记影响
// {
//     tree[p] = ((pr - pl + 1) * tag[u] % mod + (tree[p] * tag2[u]) % mod) % mod;
//     tag[p] = (tag[p] * tag2[u] % mod + tag[u]) % mod;
//     tag2[p] = tag2[p] * tag2[u] % mod;
// }
// il void push_up(ll p){ tree[p] = (tree[ls(p)] + tree[rs(p)]) % mod;}
// il void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p] || tag2[p] != 1)
//     {
//         ll mid = (pl + pr) >> 1;
//         push(ls(p), pl, mid, p);
//         push(rs(p), mid + 1, pr, p);
//         tag[p] = 0, tag2[p] = 1;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tag[p] = 0, tag2[p] = 1;//乘法标记初始化为 1
//     if(pl == pr){ tree[p] = a[pl] % mod; return;}
//     ll mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d, ll op)
// {
//     if(L <= pl && pr <= R)
//     {
//         if(op == 2) addtag(p, pl, pr, d);
//         else addtag2(p, pl, pr, d);
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d, op);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d, op);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(pl >= L && R >= pr) return tree[p] % mod;
//     push_down(p, pl, pr);
//     ll res = 0, mid = (pl + pr) >> 1;
//     if(L <= mid) res += query(L, R, ls(p), pl, mid);
//     if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
//     return res % mod;
// }
// int main()
// {
//     scanf("%lld%lld%lld", &n, &m, &mod);
//     for(ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
//     build(1, 1, n);
//     while(m--)
//     {
//         ll q, L, R, d;
//         scanf("%lld%lld%lld", &q, &L, &R);
//         if(q == 3) printf("%lld\n", query(L, R, 1, 1, n));
//         else scanf("%lld", &d), update(L, R, 1, 1, n, d, q);
//     }
//     return 0;
// }







//5.无聊的数列
// 区间修改操作为各元素加上相应的等差数列中的值
// 例如对原区间[1, 6]-{0, 0, 0, 0, 0, 0} 加上 [1, 6]-{1, 3, 5, 7, 9, 0}
// 要转化为对区间加同一个数，不难想到其公差d，上述数列转化为差分数组就是 [1, 6]-{1, 2, 2, 2, 2, -9}
// 那么就可以维护一个线段树求差分数组的区间和，查询某点x上的值即求[1, x]区间和，
// 则每次更新操作都有三次update()：1. tree[L] += k  2.tree的[L + 1, R]上都加d  3. tree[R + 1] -= 末项 即 tree[R + 1] -= k + (R - L) * d
//线段树(526ms)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// const int N = 1e5 + 10;
// ll a[N], tree[N << 2], tag[N << 2];
// il ll ls(ll p){ return p << 1;} 
// il ll rs(ll p){ return p << 1 | 1;} 
// il void addtag(ll p, ll pl, ll pr, ll d){ tag[p] += d, tree[p] += d * (pr - pl + 1);}
// il void push_up(ll p){ tree[p] = tree[ls(p)] + tree[rs(p)];}
// il void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p])
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(ls(p), pl, mid, tag[p]);
//         addtag(rs(p), mid + 1, pr, tag[p]);
//         tag[p] = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tag[p] = 0;
//     if(pl == pr)
//     {
//         tree[p] = a[pl];
//         return ;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && pr <= R){ addtag(p, pl, pr, d); return;}
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(pl >= L && R >= pr) return tree[p];
//     push_down(p, pl, pr);
//     ll res = 0;
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) res += query(L, R, ls(p), pl, mid);
//     if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
//     return res;
// }
// int main()
// {
//     ll n, m;
//     scanf("%lld%lld", &n, &m);
//     for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
//     for(int i = n; i >= 1; i--) a[i] = a[i] - a[i - 1];//构建差分数组
//     build(1, 1, n);
//     while(m--)
//     {
//         ll q, L, R, k, d;
//         scanf("%lld", &q);
//         if(q == 1)
//         {
//             scanf("%lld%lld%lld%lld", &L, &R, &k, &d);
//             update(L, L, 1, 1, n, k);//包括 L==R 时的单点修改
//             if(L != R) update(L + 1, R, 1, 1, n, d);
//             if(R < n) update(R + 1, R + 1, 1, 1, n, -(k + (R - L) * d));//减去末项
//         }else
//         {
//             scanf("%lld", &R);
//             printf("%lld\n", query(1, R, 1, 1, n));
//         }
//     }
//     return 0;
// }

//实际上本题经过转化后变成 “和” 问题，可以使用树状数组更快(303ms)
//由于树状数组本身查询的是原数组前缀和，现在变成 查询差分数组的前缀和，即用tree数组维护二阶差分
//区间下标     l-1  l   l+1    l+2   ···        r          r+1             r+2
//原数列增值    0   k   k+d    k+2d  ···    k+(r-l)*d       0               0
//一阶差分增值  0   k   d       d    ···        d       -(k+(r-l)*d)        0
//二阶差分增值  0   k   d-k     0    ···        0       -(k+(r-l+1)*d)  -(k+(r-l)*d)
//实际上tree[]存的是一维差分的值
//*还没能理解！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e5 + 10;
// ll n, m, tree[N], tree2[N];
// void update(ll x, ll d)
// {
//     for(int i = x; i <= n; i += lowbit(i))
//     {
//         tree[i] += d;
//         tree2[i] += x * d;
//     }
// }
// ll sum(ll x)
// {
//     ll res = 0;
//     for(int i = x; i; i -= lowbit(i))
//     {
//         res += (x + 1) * tree[i] - tree2[i];
//     }
//     return res;
// }
// int main()
// {
//     scanf("%lld%lld", &n, &m);
//     for(int i = 1; i <= n; i++)
//     {
//         ll x; scanf("%lld", &x);
//         //输入二阶差分，这样update()初始化前缀和后实际上变成一阶差分？？？？
//         //此处不理解
//         update(i, x), update(i + 1, -x);
//         update(i + 1, -x), update(i + 2, x);
//     }
//     while(m--)
//     {
//         ll op, L, R, k, d;
//         scanf("%lld", &op);
//         if(op == 1)
//         {
//             scanf("%lld%lld%lld%lld", &L, &R, &k, &d);
//             //添加的是一阶差分的值，则最终查询前缀和就是某元素值
//             // update(L, k), update(L + 1, -k);//单点修改，由于差分性质需要在 L+1 上减去k
//             // update(L + 1, d), update(R + 1, -d);//区间修改，[L + 1, R]上每个数都加 d
//             // update(R + 1, -(k + (R - L) * d)), update(R + 2, k + (R - L) * d);//单点修改，R+1 上减去末项，由于差分性质需要在 R+2 上加回末项
//             //简化上述操作，前后相接后为：
//             update(L, k);
//             update(L + 1, d - k);
//             update(R + 1, -(k + (R - L + 1) * d));
//             update(R + 2, k + (R - L) * d);
//         }
//         else
//         {
//             scanf("%lld", &R);
//             printf("%lld\n", sum(R));//差分求和[1, R] 即 原数组中R上的元素值
//         }
//     }
//     return 0;
// }



//6.数学计算
//起初，操作次数级别是5e5，认为可以模拟，但是可能由于炸long long导致答案是错的
//X
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// typedef long long ll;
// const int N = 5e5 + 10;
// ll t, q, mod, op[N];
// int main()
// {
//     scanf("%lld", &t);
//     while(t--)
//     {
//         ll now = 1;
//         scanf("%lld%lld", &q, &mod);
//         for(int i = 0; i <= q; i++) op[i] = 1;
//         for(int i = 1; i <= q; i++)
//         {
//             ll tp, k;
//             scanf("%lld%lld", &tp, &k);
//             if(tp == 1)
//                 now = now * k % mod, op[i] = k;
//             else
//                 now /= op[k];
//             printf("%lld\n", now % mod);
//         }
//     }
//     return 0;
// }
// 实际上，在一个时间轴(1 ~ q)上可以认为不同时间上不同的 改变值m 组成一段序列，初始时只是一段均为 1 的序列，
// 经过 操作1 的单点修改后，[1, q]的区间乘就是最终(当前)的x值，所以可以维护一个线段树处理区间乘，tree[1]就是总乘量即当前x值
// 该线段树操作简单，只有单点修改 -- 操作1 对某时间点乘值修改为 m ； 操作2 对某时间点乘值修改为 1；而查询操作直接查询[1, q]总值，即tree[1]
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define il inline
// const int N = 1e5 + 10;
// ll T, q, mod;
// ll tree[N << 2], tag[N << 2];
// il ll ls(ll p){ return p << 1;} 
// il ll rs(ll p){ return p << 1 | 1;} 
// il void addtag(ll p, ll pl, ll pr, ll d)
// {
//     if(d) tag[p] = tag[p] * d % mod, tree[p] = tree[p] * d % mod;
//     else tag[p] = 1, tree[p] = 1;
// }
// il void push_up(ll p){ tree[p] = tree[ls(p)] * tree[rs(p)] % mod;}
// il void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p] != 1)
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(ls(p), pl, mid, tag[p]);
//         addtag(rs(p), mid + 1, pr, tag[p]);
//         tag[p] = 1;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tag[p] = 1, tree[p] = 1;
//     if(pl == pr) return;
//     ll mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && pr <= R){ addtag(p, pl, pr, d); return;}
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d);
//     push_up(p);
// }
// int main()
// {
//     scanf("%lld", &T);
//     while(T--)
//     {
//         scanf("%lld%lld", &q, &mod);
//         build(1, 1, q);
//         for(int i = 1; i <= q; i++)
//         {
//             ll op, d;
//             scanf("%lld%lld", &op, &d);
//             if(op == 1) update(i, i, 1, 1, q, d);
//             else update(d, d, 1, 1, q, 0);
//             printf("%lld\n", tree[1] % mod);
//         }
//     }
//     return 0;
// }



//***7.序列操作
/*如序列 01101011
            01101011
      0110           1011
   01      10     10      11
 0   1   1   0   1   0   1   1
push_up():
    1. 1的个数sum，即两子区间的sum之和
    2. 连续1的最大数量cnt，
        若 左儿子的cntr && 右儿子的cntl，则 cnt = 左儿子区间从右往左的连续1数量cntr + 右儿子区间从左往右的连续1数量cntl
        若有一个为0则无法连接，取max(左儿子cnt，右儿子cnt)
    3. 由于翻转操作的存在，连续0串的最大数量也需同上存储，最终视 是否进行了翻转 来决定是取 连续0 还是 连续1 的个数
操作优先级：取反（单点修改置值1或0），则当 (tag0 || tag1) == 1 时取反操作应用到两个标记上，对两标记取反，否则对 nega_tag取反
该题实际操作过程中极容易出错。
*/
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll int
// #define il inline
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// const int N = 2e5 + 10;
// struct node{
//     ll sum, cnt[2], cntl[2], cntr[2];//要查询的值，1的个数(亦可得出0的个数)、连续0\1的最大数量，从左往右最长0\1个数cntl，从右往左最长0\1个数cntr
//     ll set_tag, nega_tag;//lazy标记，set_tag初始为-1，若为0或1则说明置为0或1，nega_tag 为1说明进行取反操作
//     ll len;//特别地，存一下该区间长度
// }tree[N << 2];
// ll n, m;
// il void push_up(ll p)
// {
//     tree[p].sum = tree[ls].sum + tree[rs].sum;
//     for(int i = 0; i < 2; i++)
//     {
//         tree[p].cntl[i] = tree[ls].cntl[i];//先传递左子的cntl，作为当前区间的cntl
//         if(tree[ls].cntl[i] == tree[ls].len) tree[p].cntl[i] += tree[rs].cntl[i]; //如果左子是全1串，那么当前区间的cntl可以继续接上右子的cntl
//         tree[p].cntr[i] = tree[rs].cntr[i];//同上
//         if(tree[rs].cntr[i] == tree[rs].len) tree[p].cntr[i] += tree[ls].cntr[i];
//         //上述更新的是cntl 和 cntr，现在更新cnt
//         tree[p].cnt[i] = max(tree[ls].cntr[i] + tree[rs].cntl[i], max(tree[ls].cnt[i], tree[rs].cnt[i])); //合并后中间连续串 与 左、右连续子串 求三者的最大
//     }
// }
// il void push_set(ll p, ll d)
// {
//     tree[p].set_tag = d, tree[p].nega_tag = 0, tree[p].sum = d * tree[p].len;
//     tree[p].cnt[d] = tree[p].cntl[d] = tree[p].cntr[d] = tree[p].len;
//     tree[p].cnt[!d] = tree[p].cntl[!d] = tree[p].cntr[!d] = 0;
// }
// il void push_rev(ll p)
// {
//     tree[p].sum = tree[p].len - tree[p].sum;
//     swap(tree[p].cnt[0], tree[p].cnt[1]);
//     swap(tree[p].cntl[0], tree[p].cntl[1]);
//     swap(tree[p].cntr[0], tree[p].cntr[1]);
//     if(tree[p].set_tag != -1) tree[p].set_tag ^= 1;//影响置值
//     else tree[p].nega_tag ^= 1;
// }
// il void push_down(ll p, ll pl, ll pr)
// {
//     ll mid = (pl + pr) >> 1;
//     if(tree[p].set_tag != -1)
//     {
//         push_set(ls, tree[p].set_tag);
//         push_set(rs, tree[p].set_tag);
//         tree[p].set_tag = -1;
//     }
//     if(tree[p].nega_tag)
//     {
//         push_rev(ls);
//         push_rev(rs);
//         tree[p].nega_tag = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p].set_tag = -1, tree[p].len = pr - pl + 1;
//     if(pl == pr)
//     {
//         ll d; scanf("%d", &d);
//         tree[p].sum = d, tree[p].cnt[d] = tree[p].cntl[d] = tree[p].cntr[d] = 1;
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls, pl, mid);
//     build(rs, mid + 1, pr);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr){ d == 2 ? push_rev(p) : push_set(p, d); return;}
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d);
//     if(R > mid) update(L, R, rs, mid + 1, pr, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) return tree[p].sum;
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1, res = 0;
//     if(L <= mid) res += query(L, R, ls, pl, mid);
//     if(R > mid) res += query(L, R, rs, mid + 1, pr);
//     return res;
// }
// ll query2(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) return tree[p].cnt[1];
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(R <= mid) return query2(L, R, ls, pl, mid);
//     else if(L > mid) return query2(L, R, rs, mid + 1, pr);
//     else return max(max(query2(L, mid, ls, pl, mid), query2(mid + 1, R, rs, mid + 1, pr)), min(tree[ls].cntr[1], mid + 1 - L) + min(tree[rs].cntl[1], R - mid));
// }
// int main()
// {
//     ll n, m;
//     scanf("%d%d", &n, &m);
//     build(1, 1, n); 
//     while(m--)
//     {
//         ll q, L, R, d;
//         scanf("%d%d%d", &q, &L, &R);
//         ++L, ++R;
//         if(q == 3) printf("%d\n", query(L, R, 1, 1, n));
//         else if(q == 4) printf("%d\n", query2(L, R, 1, 1, n));
//         else update(L, R, 1, 1, n, q);
//     }
//     return 0;
// }
//query2如下写法也行
// node query2(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) 
//     {
//         return tree[p];
//     }
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid && R > mid)
//     {
//         node lans, rans, ans;
//         lans = query2(L, R, ls, pl, mid);
//         rans = query2(L, R, rs, mid + 1, pr);
//         ans.cntl[1] = lans.cntl[1];
//         if(lans.cntl[1] == lans.len) ans.cntl[1] += rans.cntl[1];
//         ans.cntr[1] = rans.cntr[1];
//         if(rans.cntr[1] == rans.len) ans.cntr[1] += lans.cntr[1];
//         ans.cnt[1] = max(lans.cntr[1] + rans.cntl[1], max(lans.cnt[1], rans.cnt[1]));
//         return ans;
//     }
//     if(L <= mid) return query2(L, R, ls, pl, mid);
//     if(R > mid) return query2(L, R, rs, mid + 1, pr);
// }



//8.踩气球
//强制在线 + 线段树
// 本题显然需要用线段树维护区间操作，而难点在于如何快速判定给定孩子区间上所有个值是否均为 0
// 思路：若是直接遍历全部孩子区间，1e5的线性复杂度O(M) 乘上线段树的查询复杂度 O(QlogN) -- 查询操作 O(M * Q * logN) 肯定会TLE
//     那么重点就在于每个区间结点该如何存储某样信息，以快速对应到哪些孩子与该区间有关 -- vector<int>存储孩子编号
//     一个孩子可能对应线段树的多个区间，当其中的区间变成全0时，那么涉及该孩子的区间就少一个 cnt[孩子编号]--
//     当涉及区间减到 0 即该孩子全区间为 0 时就能计数 lastans++
//     每次update()更新时都判断当前叶子结点是否为0，且是否对应至少一个孩子
//     修改操作：只有 单点修改。 查询操作：无。
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll int
// #define il inline
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// const int N = 1e5 + 10;
// struct node{
//     ll sum;
//     vector<ll> rel;//该区间涉及的孩子
// }tree[N << 2];
// ll n, m, q, lastans = 0;
// ll cnt[N];//cnt[孩子编号] 记录孩子涉及的线段树区间个数
// il void check(ll p)
// {
//     for(int i = 0; !tree[p].sum && i < tree[p].rel.size(); i++)
//         if(--cnt[tree[p].rel[i]] == 0) 
//             ++lastans;
// }
// il void push_up(ll p, bool op)
// {
//     tree[p].sum = tree[ls].sum + tree[rs].sum;
//     if(op) check(p);
// }
// void build(ll p, ll pl, ll pr)
// {
//     if(pl == pr)
//     {
//         scanf("%d", &tree[p].sum);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls, pl, mid);
//     build(rs, mid + 1, pr);
//     push_up(p, 0);
// }
// void sign(ll L, ll R, ll p, ll pl, ll pr, ll id) //标记涉及孩子区间的线段树区间，id为孩子区间编号
// {
//     if(pl >= L && pr <= R)
//     {
//         ++cnt[id];
//         tree[p].rel.push_back(id);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) sign(L, R, ls, pl, mid, id);
//     if(R > mid) sign(L, R, rs, mid + 1, pr, id);
// }
// void update(ll p, ll pl, ll pr, ll x) //单点修改
// {
//     if(pl == pr)
//     {
//         --tree[p].sum;
//         check(p);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     if(x <= mid) update(ls, pl, mid, x);
//     else update(rs, mid + 1, pr, x);
//     push_up(p, 1);
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     build(1, 1, n);
//     for(int i = 1, l, r; i <= m; i++)
//     {
//         scanf("%d%d", &l, &r);
//         sign(l, r, 1, 1, n, i);
//     }
//     scanf("%d", &q);
//     while(q--)
//     {
//         ll x; scanf("%d", &x);
//         x = (x + lastans - 1) % n + 1;
//         update(1, 1, n, x);
//         printf("%d\n", lastans);
//     }
//     return 0;
// }


//以下为kuanbin题单的线段树专题
//9.敌兵布阵
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// using namespace std;
// #define ll int
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const ll N = 5e4 + 4;
// ll tree[N << 2], tag[N << 2];
// string op;
// void addtag(ll p, ll pl, ll pr, ll d)
// {
//     tree[p] += d * (pr - pl + 1);
//     tag[p] += d;
// }
// void push_up(ll p)
// {
//     tree[p] = tree[ls] + tree[rs];
// }
// void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p] != 0)
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(ls, pl, mid, tag[p]);
//         addtag(rs, mid + 1, pr, tag[p]);
//         tag[p] = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = 0;
//     tag[p] = 0;
//     if(pl == pr)
//     {
//         cin >> tree[p];
//         return ;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls, pl, mid);
//     build(rs, mid + 1, pr);
//     push_up(p);
// }
// void update(ll x, ll p, ll pl, ll pr, ll d)
// {
//     if(pl == pr)
//     {
//         addtag(p, pl, pr, d);
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(x <= mid) update(x, ls, pl, mid, d);
//     if(x > mid) update(x, rs, mid + 1, pr, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr)
//         return tree[p];
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1, res = 0;
//     if(L <= mid) res += query(L, R, ls, pl, mid);
//     if(R > mid) res += query(L, R, rs, mid + 1, pr);
//     return res;
// }
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     for(int i = 1; i <= T; i++)
//     {
//         printf("Case %d:\n", i);
//         int n;
//         cin >> n;
//         build(1, 1, n);
//         while(cin >> op && op != "End")
//         {
//             ll x, y;
//             cin >> x >> y;
//             if(op == "Add") update(x, 1, 1, n, y);
//             else if(op == "Sub") update(x, 1, 1, n, -y);
//             else printf("%d\n", query(x, y, 1, 1, n));
//         }
//     }
//     return 0;
// }



//10.I Hate It
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll int
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// const ll N = 2e5 + 10;
// ll tree[N << 2];
// ll n, m;
// void push_up(ll p){ tree[p] = max(tree[ls], tree[rs]);}
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = 0;
//     if(pl == pr)
//     {
//         scanf("%d", &tree[p]);
//         return ;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(lc);
//     build(rc);
//     push_up(p);
// }
// void update(ll x, ll p, ll pl, ll pr, ll d)
// {
//     if(pl == pr)
//     {
//         tree[p] = d;
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     if(x <= mid) update(x, lc, d);
//     if(x > mid) update(x, rc, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) return tree[p];
//     ll mid = (pl + pr) >> 1, res = 0;
//     if(L <= mid) res = max(res, query(L, R, lc));
//     if(R > mid) res = max(res, query(L, R, rc));
//     return res;
// }
// int main()
// {
//     while(~scanf("%d%d", &n, &m))
//     {
//         build(1, 1, n);
//         while(m--)
//         {
//             char op;
//             ll x, y;
//             getchar();
//             scanf("%c%d%d", &op, &x, &y);
//             if(op == 'U') update(x, 1, 1, n, y);
//             else printf("%d\n", query(x, y, 1, 1, n));
//         }
//     }
//     return 0;
// }



//11.A Simple Problem with Integers(区间和)
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define ll long long
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// const int N = 1e5 + 10;
// struct node{
//     ll sum;
//     ll tag;
// }tree[N << 2];
// void addtag(ll p, ll pl, ll pr, ll d)
// {
//     tree[p].tag += d;
//     tree[p].sum += d * (pr - pl + 1);
// }
// void push_up(ll p)
// {
//     tree[p].sum = tree[ls].sum + tree[rs].sum;
// }
// void push_down(ll p, ll pl, ll pr)
// {
//     if(tree[p].tag != 0)
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(lc, tree[p].tag);
//         addtag(rc, tree[p].tag);
//         tree[p].tag = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p].tag = 0;
//     if(pl == pr)
//     {
//         scanf("%lld", &tree[p].sum);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(lc);
//     build(rc);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         addtag(p, pl, pr, d);
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr)
//         return tree[p].sum;
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1, res = 0;
//     if(L <= mid) res += query(L, R, lc);
//     if(R > mid) res += query(L, R, rc);
//     return res;
// }
// int main()
// {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     build(1, 1, n);
//     while(m--)
//     {
//         char op;
//         ll a, b, c;
//         getchar();
//         scanf("%c%lld%lld", &op, &a, &b);
//         if(op == 'Q') printf("%lld\n", query(a, b, 1, 1, n));
//         else
//         {
//             scanf("%lld", &c);
//             update(a, b, 1, 1, n, c);
//         }
//     }
//     return 0;
// }



//12.Balanced Lineup(区间当前最值)
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll int
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// const ll N = 5e4 + 5, INF = 1e6;
// struct node{
//     ll min_, max_;
//     node(ll mmin = 0, ll mmax = 0) {min_ = mmin, max_ = mmax;}
// }tree[N << 2];
// ll min_res = INF, max_res = 0;
// void push_up(ll p)
// {
//     tree[p].max_ = max(tree[ls].max_, tree[rs].max_);
//     tree[p].min_ = min(tree[ls].min_, tree[rs].min_);
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = node(INF, 0);
//     if(pl == pr)
//     {
//         ll t;
//         scanf("%d", &t);
//         tree[p] = node(t, t);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(lc);
//     build(rc);
//     push_up(p);
// }
// void query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr)
//     {
//         max_res = max(max_res, tree[p].max_);
//         min_res = min(min_res, tree[p].min_);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) query(L, R, lc);
//     if(R > mid) query(L, R, rc);
//     return;
// }
// int main()
// {
//     int n, q;
//     scanf("%d%d", &n, &q);
//     build(1, 1, n);
//     while(q--)
//     {
//         min_res = INF, max_res = 0;
//         ll l, r;
//         scanf("%d%d", &l, &r);
//         query(l, r, 1, 1, n);
//         printf("%d\n", max_res - min_res);
//     }
//     return 0;
// }
//同时查询最大最小值的写法
// PII query(int now, int L, int R) {
//     // 找到了要的区间返回这个区间的最大值和最小值，用来和后面的区间进行对比 
//     if (L <= root[now].l && root[now].r <= R) return PII(root[now].hei, root[now].low);
//     // 规定first为最大值，second为最小值，那么没找到就返回一个极端值就行了 
//     if (L > root[now].r || R < root[now].l) return PII(-1e9, 1e9);
//     // 不用pushdown
//     // 找到左右子树的最大值和最小值对，然后对比 
//     PII nhei = query(now << 1, L, R);
//     PII nlow = query(now << 1 | 1, L ,R); 
//     // 对比左区间的最大值和右区间的最大值，左区间的最小值和右区间的最小值... 
//     return PII(max(nhei.first, nlow.first), min(nhei.second, nlow.second));
// }



//13.Just a Hook(简单置值 与 区间和)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define ll int
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// const ll N = 1e5 + 10;
// long long tree[N << 2];
// ll tag[N << 2];
// void addtag(ll p, ll pl, ll pr, long long d)
// {
//     tag[p] = d;
//     tree[p] = d * (pr - pl + 1);
// }
// void push_up(ll p)
// {
//     tree[p] = tree[ls] + tree[rs];
// }
// void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p])
//     {
//         ll mid = (pl + pr) >> 1;
//         addtag(lc, tag[p]);
//         addtag(rc, tag[p]);
//         tag[p] = 0;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tag[p] = 0, tree[p] = 0;
//     if(pl == pr)
//     {
//         tree[p] = 1;
//         return ;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(lc);
//     build(rc);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, long long d)
// {
//     if(L <= pl && R >= pr)
//     {
//         addtag(p, pl, pr, d);
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
//     push_up(p);
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     for(int i = 1; i <= T; ++i)
//     {
//         int n, q;
//         scanf("%d%d", &n, &q);
//         build(1, 1, n);
//         while(q--)
//         {
//             ll x, y;
//             long long z;
//             scanf("%d%d%lld", &x, &y, &z);
//             update(x, y, 1, 1, n, z);
//         }
//         printf("Case %d: The total value of the hook is %lld.\n", i, tree[1]);
//     }
//     return 0;
// }



//*14.Mayor's posters （一维染色问题 + 特殊离散化处理）
//给一个无限长广告牌，给你n个广告和其放置的位置，按照输入数据的顺序放置前后，问能看见几个广告（注意，看见一部分也算）。
//题意转换：设每个广告都是独立的一种颜色，放置广告相当于给一个区间染色，问某个区间有多少种颜色。
//由于 l, r <= 1e7，需要离散化降低复杂度，并且l和r两两离散，为保证不交叉区间的非连续性，需要离散时 间隔一个数
//如输入区间[1, 100],[1, 30],[50, 100]，其答案为3，若连续离散则得到[1, 4],[1, 2],[3, 4]导致答案为2，因此应该将离散数字两两间隔一个数
//即[1, 7],[1, 3],[5, 7]，才能得到答案为3，
//unique() 的返回值是一个地址指向去重后序列（这个序列不含有重复数值）的 末尾 的 下一个元素
//v.erase(unique(v.begin(), v.end()), v.end()) 可以去掉容器中后面重复的元素
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <vector>
// #include <set>
// using namespace std;
// #define ll int
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// const ll N = 1e6 + 5;
// vector<ll> v;
// set<ll> st;
// pair<ll, ll> que[N];
// ll tree[N << 2], n ,T;
// void pushdown(ll p)
// {
//     if(tree[p])
//     {
//         tree[ls] = tree[rs] = tree[p];
//         tree[p] = 0;
//     }
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         tree[p] = d;
//         return;
//     }
//     pushdown(p);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
// }
// void query(ll L, ll R, ll p, ll pl, ll pr)//重点
// {
//     if(tree[p]) //区间p有颜色就记录
//     {
//         st.insert(tree[p]);
//         return;//区间p有颜色，说明该区间下都为这个颜色，故不用再搜索
//     }
//     if(pl == pr) return;
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) query(L, R, lc);
//     if(R > mid) query(L, R, rc);
// }
// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         v.clear();
//         st.clear();
//         memset(tree, 0, sizeof(tree));
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++)
//         {
//             ll l, r;
//             scanf("%d%d", &l, &r);
//             que[i] = make_pair(l, r);
//             v.push_back(l);
//             v.push_back(r);
//         }
//         sort(v.begin(), v.end());
//         v.erase(unique(v.begin(), v.end()), v.end());
//         ll len = v.size();
//         for(int i = 1; i < len; i++)
//             if(v[i] - v[i - 1] > 1) // 即两区间不连续
//                 v.push_back(v[i - 1] + 1);
//         sort(v.begin(), v.end());
//         len = v.size();
//         for(int i = 1; i <= n; i++)
//         {
//             ll L = lower_bound(v.begin(), v.end(), que[i].first) - v.begin() + 1;//记得要使其从1开始，都得加1。
//             ll R = lower_bound(v.begin(), v.end(), que[i].second) - v.begin() + 1;
//             update(L, R, 1, 1, len, i);
//         }
//         query(1, len, 1, 1, len);
//         printf("%d\n", st.size());
//     }
//     return 0;
// }
//一维、二维染色问题讲解：https://blog.csdn.net/qq_45748404/article/details/119489831?ops_request_misc=&request_id=&biz_id=102&utm_term=Mayor%27s%20posters&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-3-119489831.142^v73^pc_search_v2,201^v4^add_ask,239^v2^insert_chatgpt&spm=1018.2226.3001.4187



//*15.Count the Colors（一维染色问题）
//题意：在长度为n的线段上，每次操作给其中一个区间染上颜色c，可以覆盖前面的颜色，求最后整条线段上能看到多少种颜色。
//l, r <= 8e3，无需离散化
//本题重点在于如何联系连续区间(注意区间[1,3][3,5]连续可看作[1,5]，而[1,2][3,4]不连续，因为被[2,3]分开了)。
//搞明白涂色的是区间而不是点，染色区间[a,b]并不是把a～b的所有点都染成c，故区间不能取闭区间。
//防止不连续区间判断为连续，需要将一侧的端点收束（左端点+1 或 右端点-1）或直接两端点值乘2，来使得连续数字间有中间值，因为连续数字的两个区间其实不连续，
//这里可以选择用 左开右闭 区间，设染色区间[l, r]即染色[l + 1, r]上的每个点，对于一个单位区间[0, 1]，将点1染色等同于将[0, 1]染色，
//即染色某个点，即染色该点的前一段单位区间。
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <set>
// #include <map>
// using namespace std;
// #define ll int
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// const ll N = 8e3 + 5;
// ll tree[N << 2], ans[N], last = 0;//重点：记录上次碰到的颜色或者说上次碰到非颜色区间，方便排除连续区间
// void pushdown(ll p)
// {
//     if(tree[p])
//     {
//         tree[ls] = tree[rs] = tree[p];
//         tree[p] = 0;
//     }
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(tree[p] == d) return;//优化，若已经染成d色，则退出
//     if(L <= pl && R >= pr)
//     {
//         tree[p] = d;
//         return;
//     }
//     pushdown(p);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d);
//     if(R > mid) update(L, R, rs, mid + 1, pr, d);
// }
// void query(ll p, ll pl, ll pr)//搜索每个线段树区间
// {
//     if(tree[p])//有颜色
//     {
//         if(tree[p] != last) 
//         {
//             ans[tree[p]]++;//非连续区间才计数
//             last = tree[p];//更新last
//         }
//         return;
//     }
//     if(pl == pr)//到了叶子结点都还没颜色，说明颜色断片，已经不连续了，那就初始化last
//     {
//         last = 0;
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     query(ls, pl, mid);
//     query(rs, mid + 1, pr);
// }
// int main()
// {
//     int n;
//     while(~scanf("%d", &n))
//     {
//         last = 0;
//         memset(ans, 0, sizeof(ans));
//         memset(tree, 0, sizeof(tree));
//         for(int i = 1; i <= n; i++)
//         {
//             ll l, r, c;
//             scanf("%d%d%d", &l, &r, &c);
//             update(l + 1, r, 1, 1, N, c + 1);
//         }
//         query(1, 1, N);
//         for(int i = 1; i < N; i++)
//             if(ans[i]) printf("%d %d\n", i - 1, ans[i]);
//         printf("\n");
//     }
//     return 0;
// }



//16.Can you answer these queries? （题意转换 + update()的优化）
//注意题目并不保证 X <= Y，题意每次原值x减去平方根值d = sqrt(x)，而d要四舍五入，则原值x即向下取整的平方根值，得到每次修改 x = x - round(d) = ceil(d)
//不优化会TLE:当区间[l,r]上每个点都是1时，取平方根值还是1，没有更新的必要
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cmath>
// using namespace std;
// #define ll long long
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define mid ((pl + pr) >> 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// const ll N = 1e5 + 5;
// ll n, m, tree[N << 2];
// inline void push_up(ll p) { tree[p] = tree[ls] + tree[rs];}
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = 0;
//     if(pl == pr)
//     {
//         scanf("%lld", &tree[p]);
//         return;
//     }
//     build(lc);
//     build(rc);
//     push_up(p);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr)//单点修改
// {
//     if(tree[p] == pr - pl + 1) return;//*优化：当这个区间每个点都是1时，没有更新的必要
//     if(pl == pr)
//     {
//         tree[p] = (ll)sqrt(tree[p]);
//         return;
//     }
//     if(L <= mid) update(L, R, lc);
//     if(R > mid) update(L, R, rc);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) return tree[p];
//     if(R <= mid) return query(L, R, lc);
//     else if(L > mid) return query(L, R, rc);
//     else return  query(L, R, lc) + query(L, R, rc);
// }
// int main()
// {
//     int _ = 1;
//     while(~scanf("%lld", &n))
//     {
//         printf("Case #%d:\n", _++);
//         build(1, 1, n);
//         scanf("%lld", &m);
//         while(m--)
//         {
//             ll t, x, y;
//             scanf("%lld%lld%lld", &t, &x, &y);
//             if(x > y) swap(x, y);
//             if(t) printf("%lld\n", query(x, y, 1, 1, n));
//             else update(x, y, 1, 1, n);
//         }
//         printf("\n");
//     }
//     return 0;
// }



//17.Tunnel Warfare (区间合并问题)
//三种操作：单点修改、求最长连续1的个数 和 撤销上一次单点修改
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll int
// const ll N = 5e4 + 5;
// ll tree[N << 2], pre[N << 2], suf[N << 2];//线段树维护子节点，pre保存区间前缀最长1的个数，suf保存区间后缀最长1的个数
// ll history[N];//存在撤回操作，记录村庄被毁的历史
// void push_up(ll p, ll len)//更新区间p的前缀1和后缀1个数
// {
//     //先传承，再判断左右子区间合并情况
//     pre[p] = pre[ls];
//     suf[p] = suf[rs];
//     //如果左子区间均为1，则可以将值合并到右子区间的前缀1和。右子同理。
//     if(pre[ls] == len - (len >> 1)) pre[p] += pre[rs];
//     if(suf[rs] == (len >> 1)) suf[p] += suf[ls];
// }
// void build(ll p, ll pl, ll pr)
// {
//     if(pl == pr)
//     {
//         tree[p] = pre[p] = suf[p] = 1;
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(lc);
//     build(rc);
//     push_up(p, pr - pl + 1);
// }
// void update(ll x, ll p, ll pl, ll pr, ll d)
// {
//     if(pl == pr) 
//     {
//         tree[p] = pre[p] = suf[p] = d;
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     if(x <= mid) update(x, lc, d);
//     else update(x, rc, d);
//     push_up(p, pr - pl + 1);
// }
// ll query(ll x, ll p, ll pl, ll pr)
// {
//     if(pl == pr) return tree[p];
//     ll mid = (pl + pr) >> 1;
//     if(x <= mid)//查询点落在左子
//     {
//         //若查询点落在左子的后缀最长1区间内，直接返回最长连续1；若不是则继续探查左子
//         if(x + suf[ls] > mid) return suf[ls] + pre[rs];
//         else return query(x, lc);
//     }
//     else
//     {
//         if(pre[rs] >= x - mid) return suf[ls] + pre[rs];
//         else return query(x, rc);
//     }
// }
// int main()
// {
//     ll n, q;
//     while(~scanf("%d%d", &n, &q))
//     {
//         ll ind = 0;
//         build(1, 1, n);
//         while(q--)
//         {
//             char op[5];
//             ll x;
//             scanf("%s", &op);
//             if(op[0] == 'D')
//             {
//                 scanf("%d", &x);
//                 update(x, 1, 1, n, 0);
//                 history[++ind] = x;//依次记录破坏操作
//             }
//             else if(op[0] == 'Q')
//             {
//                 scanf("%d", &x);
//                 printf("%d\n", query(x, 1, 1, n));
//             }
//             else
//             {
//                 x = history[ind--];
//                 update(x, 1, 1, n, 1);
//             }
//         }
//     }
//     return 0;
// }



//18.Hotel (区间合并)
//区间修改 + 统计连续个数
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll int
// const ll N = 5e4 + 4;
// struct nd{
//     ll sum, pre, suf;//统计对象为1，即空位置个数
//     ll tag;          //为0\1时区间置为0\1
//     nd(ll s = 0, ll p = 0, ll sf = 0, ll t = 0) { sum = s, pre = p, suf = sf, tag = t;}
// }tree[N << 2];
// void addtag(ll p, ll len, ll d)
// {
//     ll x = d * len;
//     tree[p] = nd(x, x, x, d);
// }
// void push_up(ll p, ll len)
// {
//     tree[p].pre = tree[ls].pre;
//     tree[p].suf = tree[rs].suf;
    
//     if(tree[ls].pre == len - (len >> 1)) tree[p].pre += tree[rs].pre;
//     if(tree[rs].suf == (len >> 1)) tree[p].suf += tree[ls].suf;
//     tree[p].sum = max(max(tree[ls].sum, tree[rs].sum), tree[ls].suf + tree[rs].pre);
// }
// void push_down(ll p, ll pl, ll pr)
// {
//     if(tree[p].tag != -1)
//     {
//         ll mid = pl + pr >> 1;
//         addtag(ls, mid - pl + 1, tree[p].tag);
//         addtag(rs, pr - mid, tree[p].tag);
//         tree[p].tag = -1;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     ll len = pr - pl + 1;
//     tree[p] = nd(len, len, len, -1);
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     build(lc);
//     build(rc);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         addtag(p, pr - pl + 1, d);
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
//     push_up(p, pr - pl + 1);
// }
// ll query(ll p, ll pl, ll pr, ll k)
// {
//     if(pl == pr && k == 1) return pl;//特判
//     push_down(p, pl, pr);
//     //按左端点编号由小到大搜，左->中->右
//     ll mid = pl + pr >> 1;
//     if(tree[p].sum < k) return 0;
//     if(tree[ls].sum >= k)
//         return query(lc, k);
//     else if(tree[ls].suf + tree[rs].pre >= k)
//         return mid - tree[ls].suf + 1;
//     else
//         return query(rc, k);
// }
// int main()
// {
//     ll n, m;
//     scanf("%d%d", &n, &m);
//     build(1, 1, n);
//     while(m--)
//     {
//         ll op, x, d;
//         scanf("%d", &op);
//         if(op == 1)
//         {
//             scanf("%d", &d);
//             ll res = query(1, 1, n, d);
//             printf("%d\n", res);
//             if(res) update(res, res + d - 1, 1, 1, n, 0);
//         }
//         else
//         {
//             scanf("%d%d", &x, &d);
//             update(x, x + d - 1, 1, 1, n, 1);
//         }
//     }
//     return 0;
// }



//*19. Assign the task (DFS序 将 树结构 转换为 线段树区间处理)
//题意：给你一棵树，共n个结点，每个结点具有一个颜色，可以对结点所处的子树（包括其自身）的染色 以及 查询某结点的颜色
//dfs序是指：每个节点在dfs深度优先遍历中的进出栈的时间序列。
//先建图存树，用 dfs序 将 树 区间化，可以求出每个节点的管辖区间（即 所得该节点区间 表示 以该节点为根的子树），以此维护任意一个子树或单个结点的变化
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll int
// const int N = 5e4 + 5;
// ll tree[N << 2], tag[N << 2];
// ll in[N], out[N];//记录结点在dfs序上进出栈的时间
// ll n, q, time = 0;//时间
// ll indegree[N];//记录入度，方便找树根
// vector<ll> G[N];
// void init()
// {
//     memset(tree, -1, sizeof(tree));
//     memset(tag, -1, sizeof(tag));
//     for(int i = 1; i <= n; i++) G[i].clear();
//     time = 0;
// }
// void dfs(int u)
// {
//     in[u] = ++time;
//     for(int i = 0; i < G[u].size(); i++) dfs(G[u][i]);
//     out[u] = time;
// }
// void push_down(ll p)
// {
//     if(tag[p] != -1)
//     {
//         tree[ls] = tree[rs] = tag[p];
//         tag[ls] = tag[rs] = tag[p];
//         tag[p] = -1;
//     }
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         tree[p] = tag[p] = d;
//         return;
//     }
//     push_down(p);
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
// }
// ll query(ll x, ll p, ll pl, ll pr)
// {
//     if(pl == pr) return tree[p];
//     push_down(p);
//     ll mid = pl + pr >> 1;
//     if(x <= mid) return query(x, lc);
//     else return query(x, rc);
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     for(int _ = 1; _ <= T; _++)
//     {
//         printf("Case #%d:\n", _);
//         scanf("%d", &n);
//         init();
//         for(int i = 1; i < n; i++)//n个结点建一颗单根树，需要 n-1 条边
//         {
//             ll u, v;
//             scanf("%d%d", &v, &u);
//             G[u].push_back(v);
//             ++indegree[v];
//         }
//         //存储dfs时间序列
//         for(int i = 1; i <= n; i++)
//         {
//             if(!indegree[i]) //从树根出发一次即可
//             {
//                 dfs(i);
//                 break;
//             }
//         }
//         scanf("%d", &q);
//         while(q--)
//         {
//             char op[5];
//             ll x, d;
//             scanf("%s", &op);
//             if(op[0] == 'T')
//             {
//                 scanf("%d%d", &x, &d);
//                 update(in[x], out[x], 1, 1, n, d);
//             }
//             else
//             {
//                 scanf("%d", &x);
//                 printf("%d\n", query(in[x], 1, 1, n));
//             }
//         }
//     }
//     return 0;
// }



//20.Transformation (混合多种区间操作)
//一个长为n的序列，对区间[l,r]有4种操作：每个数加c，每个数乘c，每个数置为c，查询每个数p次方后的区间和
//思路1：对查询操作的p次方和，用s[3]分别存起1次到3次方的值，传递时结合完全平方式和完全立方式
//对于(x + d)^3 = x^3 + 3 * x^2 * d + 3 * x * d^2 + d^3，拓展到长度为len的区间得到：Σ(x + d)^3 = Σx^3 + 3 * d * Σ(x^2) + 3 * d^2 * Σx + Σd^3
//即tree[p].s[2] = tree[p].s[2] + 3 * d * tree[p].s[1] + 3 * d * d * tree[p].s[0] + len * d * d * d 
//(x + d)^2 = x^2 + 2*d*x + d^2，同理
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// #include <cmath>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll int
// #define mod(x) ((x) % 10007)
// const int N = 1e5 + 5;
// ll n, m;
// struct nd{
//     ll s[3];
//     ll sum, mul, setx;
//     nd(ll a = 0, ll b = 0, ll c = 0, ll d = 0, ll e = 0, ll f = 0) {s[0] = a, s[1] = b, s[2] = c, sum = d, mul = e, setx = f;}
// }tree[N << 2];
// void addtag_sum(ll p, ll pl, ll pr, ll d)//注意三种求和的更新先后关系
// {
//     ll len = pr - pl + 1;
//     tree[p].s[2] = mod(tree[p].s[2] + mod(3 * d * tree[p].s[1]) + mod(3 * d * d * tree[p].s[0]) + mod(len * d * d * d));
//     tree[p].s[1] = mod(tree[p].s[1] + mod(2 * d * tree[p].s[0]) + mod(len * d * d));
//     tree[p].s[0] = mod(tree[p].s[0] + mod(len * d));
//     tree[p].sum  = mod(tree[p].sum + d);
// }
// void addtag_mul(ll p, ll pl, ll pr, ll d)
// {
//     tree[p].s[2] = mod(tree[p].s[2] * d * d * d);
//     tree[p].s[1] = mod(tree[p].s[1] * d * d);
//     tree[p].s[0] = mod(tree[p].s[0] * d);
//     tree[p].sum  = mod(tree[p].sum * d);
//     tree[p].mul  = mod(tree[p].mul * d);
// }
// void addtag_set(ll p, ll pl, ll pr, ll d)
// {
//     ll len = pr - pl + 1;
//     tree[p].s[2] = mod(len * d * d * d);
//     tree[p].s[1] = mod(len * d * d);
//     tree[p].s[0] = mod(len * d);
//     tree[p].setx = d;
// }
// void push_up(ll p)
// {
//     for(int i = 0; i < 3; i++) tree[p].s[i] = mod(tree[ls].s[i] + tree[rs].s[i]);
// }
// void push_down(ll p, ll pl, ll pr)//注意标记更新的先后关系和覆盖性
// {
//     ll mid = pl + pr >> 1;
//     if(tree[p].setx != -1)//覆盖其他标记
//     {
//         addtag_set(lc, tree[p].setx);
//         addtag_set(rc, tree[p].setx);
//     }
//     else
//     {
//         if(tree[p].mul != 1)
//         {
//             addtag_mul(lc, tree[p].mul);
//             addtag_mul(rc, tree[p].mul);
//         }
//         if(!tree[p].sum)
//         {
//             addtag_sum(lc, tree[p].sum);
//             addtag_sum(rc, tree[p].sum);
//         }
//     }
//     tree[p].sum = 0, tree[p].mul = 1, tree[p].setx = -1;
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = nd(0, 0, 0, 0, 1, -1);
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     build(lc);
//     build(rc);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll op, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         ll len = pr - pl + 1;
//         if(op == 1) addtag_sum(p, pl, pr, d);
//         else if(op == 2) addtag_mul(p, pl, pr, d);
//         else addtag_set(p, pl, pr, d);
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, lc, op, d);
//     if(R > mid) update(L, R, rc, op, d);
//     push_up(p);
// }
// ll query(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr) return mod(tree[p].s[d]);
//     push_down(p, pl, pr);
//     ll mid = pl + pr >> 1, ans = 0;
//     if(L <= mid) ans = mod(ans + query(L, R, lc, d));
//     if(R > mid) ans = mod(ans + query(L, R, rc, d));
//     return mod(ans);
// }
// int main()
// {
//     while(~scanf("%d%d", &n, &m), n)
//     {
//         build(1, 1, n);
//         while(m--)
//         {
//             ll op, x, y, k;
//             scanf("%d%d%d%d", &op, &x, &y, &k);
//             if(op == 4) printf("%d\n", query(x, y, 1, 1, n, k - 1));
//             else update(x, y, 1, 1, n, op, k);
//         }
//     }
//     return 0;
// }



//21.Vases and Flowers












































//问题：zkw线段树是什么？


























































/*树状数组（Binary Indexed Tree, BIT）-- O(logn) -- 一种利用数的二进制特征进行检索的树状结构
用于高效地 查询和维护 前缀和、前缀积等，它只能维护“操作和”。
树状数组能用以简洁的编码高效地完以下操作
    查询前缀和sum:
        查询的过程是 每次去掉编号二进制最后的 1 来定位，如求 前7个数和 sum(7) = tree[7] + tree[6] + tree[4]，
        详细地，编号7 二进制为 111，去掉最后的 1，得 110，即定位到 tree[6]，叠加该值，
        然后 110 去掉最后的 1，得 100，定位到 tree[4]，继续叠加，最后 100 去掉1后为 0，则查询完毕。
    维护，即可以动态更新树中元素(非静态数组):
        维护的过程是 每次在编号的二进制最后的 1 上加 1（即最后的 1 进一位），例如当更新了元素 a3 时，除了更新tree[3]还要更新tree[4]、tree[8]等
        详细地，编号3 二进制为 011，最后的 1 上加 1，得 100，定位到tree[4]，并对其更新，
        然后 100 最后的 1 进位得 1000，定位到tree[8]，而后tree[16]、tree[32]···以此类推直到 N。
    单点修改： 
        update(ind, val)
    区间修改：
        利用 前缀和 和 差分 的性质，也可以将 单点修改 拓展为 区间修改
        只需要这两句：update(L, 1)，update(R + 1, -1)

注意事项：
1.取二进制数最后一个 1 用函数 lowbit()，设返回值为 m，那么tree[i] = Ai + Ai-1 + ··· + Ai-m+1，即 tree[i] 的值为 包括ai的前m个数的和。
2.区间修改后，每个元素 ai 都需要用 sum(i) - sum(i - 1) 求得，对于某段和也是一样，它满足差分的运用
3.原数列a[N]一般是不需要的，因为原值需要直接更新到tree上

从效率来说，如果只用于求和(积)，更推荐写树状数组，代码精简，线段树的空间复杂度常数较大，占用空间也更多。且树状数组通常速度更快。

前缀和模板：
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define lowbit(x) ((x) & -(x))
const int N = 5e5 + 10;
ll n, m;
ll tree[N];
void update(int x, ll d)
{
    while(x <= N)
    {
        tree[x] += d;
        x += lowbit(x);
    }
}
ll sum(ll x)
{
    ll res = 0;
    while(x > 0)
    {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        ll x;
        scanf("%lld", &x);
        update(i, x);
    }
    while(m--)
    {
        ll op, x, y, k;
        scanf("%lld", &op);
        if(op == 1)
        {
            scanf("%lld%lld", &x, &k);
            update(x, k);//单点修改
            // update(x, k), update(y + 1, -k);//区间修改，[L, R]上每个数都加 k
        }
        else
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", sum(y) - sum(x - 1));//差分求和
        }
    }
    return 0;
}


*/



//1.P3374 树状数组 1
//树状数组写法(492ms，明显更快)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 5e5 + 10;
// ll n, m;
// ll tree[N];
// void update(int x, ll d)
// {
//     while(x <= N)
//     {
//         tree[x] += d;
//         x += lowbit(x);
//     }
// }
// ll sum(ll x)
// {
//     ll res = 0;
//     while(x > 0)
//     {
//         res += tree[x];
//         x -= lowbit(x);
//     }
//     return res;
// }
// int main()
// {
//     scanf("%lld%lld", &n, &m);
//     for(int i = 1; i <= n; i++)
//     {
//         ll x; scanf("%lld", &x);
//         update(i, x);
//     }
//     while(m--)
//     {
//         ll op, x, y;
//         scanf("%lld%lld%lld", &op, &x, &y);
//         if(op == 1) update(x, y);
//         else printf("%lld\n", sum(y) - sum(x - 1));
//     }
//     return 0;
// }



//2.贪婪大陆
// 分析：起初以为可以 区间叠加1 并 求区间最大值 来计算种类，假设查询[1, 6]，已知两次埋地雷操作[1, 3]，[5, 6]，此时序列为 {1, 1, 1, 0, 1, 1}，应输出2，但求最大值却输出1
//      证明这个思路是错的，所以这类查询”区间种类数“的题需要在其两端点数量关系下手，正序地看，[1, 3],[5, 6]的右端点3, 6均在[1, 6]上，且由于左端点1, 5也在[1, 6]上，所以
//      这两个区间都与所求区间有关，假设某序列{1 1 [1 0 1 1 0 1 1 0 1 1] 1}，查询区间[L, R]设为[3, 12]，[1, R]的所有左端点都可能为答案做贡献，
//      而我们还要删除那些右端点在 L 之前的，因为这些地雷的区间不在[L, R]之间是不合法的，现问题转化为 区间种数 = [1, R]上左端点数 - [1, L - 1]上右端点数
// 考虑"操作和"问题，维护两个树状数组分别记录左右端点个数更方便
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e5 + 10;
// ll n, m, tl[N], tr[N];//tl[]记录左端点数，tr[]记录右端点数
// void update(ll *t, ll x)
// {
//     for(; x <= n; x += lowbit(x)) ++t[x];
// }
// ll sum(ll *t, ll x)
// {
//     ll res = 0;
//     for(; x > 0; x -= lowbit(x)) res += t[x];
//     return res;
// }
// int main()
// {
//     scanf("%lld%lld", &n, &m);
//     while(m--)
//     {
//         ll op, L, R;
//         scanf("%lld%lld%lld", &op, &L, &R);
//         if(op == 1) update(tl, L), update(tr, R);//两次单点修改
//         else printf("%lld\n", sum(tl, R) - sum(tr, L - 1));//[1,R]上左端个数 - [1,L-1]上右端个数
//     }
//     return 0;
// }



//3.线段树 1
//树状数组写法(差分)，重点在于开第二个数组 tree2[i]=tree1[i]*(i-1)
//https://www.luogu.com.cn/problem/solution/P3372





































































/*数学原理应用*/

//曼哈顿距离(又名出租车距离)
//d(i,j)=|x1-x2|+|y1-y2|
/*
应用1：打印中心规律图形
//如打印一个菱形
// 当n=5时，有" * “号的地方是距离中心点曼哈顿距离小于2的地方；
// 当n=7时，有” * " 号的地方是距离中心点曼哈顿距离小于3的地方。
// 找到中心点与n的关系：中心点用n表示为（n/2，n/2），将与中心点距离小于n/2的点用" * "表示，其他地方用空格表示，
// 完成一行（一行指i的一次循环）后进行换行。
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;//n为奇数
    int cx = n/2, cy = n/2;//中心点(cx,cy)
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(abs(i-cx) + abs(j-cy) <= n/2)
                 cout << '*' ;
            else
                 cout << ' ';
        }
        cout << endl;
    }
    return 0;
}

应用2：搜索的剪枝和优化
如在图中行走的过程中，限定步数或时间 limit
已知起点s(sx, sy) 和 终点e(ex, ey)
记曼哈顿距离 mdis = |sx - ex| + |sy - ey|;
搜索前：
    如果 limit < mdis 或 mdis % 2 != limit % 2 ，则该图无解
    （特性：曼哈顿距离 和 最短步数(或至少步数) 奇偶性必然相同）
搜索中：
    若搜索到当前点(x, y)，且已经过步数或时间 step，仍可以用当前点与终点的曼哈顿距离剪枝
    如果 step + |x - ex| + |y - ey| > limit 则该路径无解
*/


/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑算法↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//。。。





//结构体操作符重载
// #include<cstdio>
// using namespace std;
// struct node{
//     int x,y;
//     int step;
//     bool operator == (const node &n)const{
//         return x==n.x && y==n.y;
//     }
//     bool operator > (const node &n)const{
//         return x+y > n.x+n.y;
//     }
//     bool operator < (const node &n)const{
//         // return x+y < n.x+n.y;
//         if(x==n.x) return y<n.y;
//         else x<n.x;
//     }
//     friend bool operator <(const node &n1, const node &n2)
//     {
//         if(n1.x==n2.x) return n1.y<n2.y;
//         else n1.x<n2.x;
//     }
//     node operator - (node &n){
//         x-=n.x;
//         y-=n.y;
//         return node{x,y,step};
//     }
//     node operator = (node &n){
//         x=n.x;
//         y=n.y;
//         return node{x,y,step};
//     }
// };
// int main(){
//     int x1,y1,x2,y2,step=1;
//     while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)){
//         node t1={x1,y1,step++};
//         node t2={x2,y2,step++};
//         if(t1==t2) printf("==\n");
//         if(t1>t2) printf(">\n");
//         if(t1<t2) printf("<\n");
//         node t = t1 - t2;
//         printf("t1-t2=( %d , %d )\n",t.x,t.y);
//         printf("After minus t1.x = %d, t1.y = %d\n",t1.x,t2.y);
//     }
//     return 0;
// }






































/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//*树
/*
https://blog.csdn.net/qq_43762191/article/details/107280503?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166927609816800182199745%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166927609816800182199745&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-107280503-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_controx1&utm_term=%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91&spm=1018.2226.3001.4187
*/

//哈希算法
/*
可用于如对数序列中各数出现次数计数，以该数为下标，数组元素为次数来记录，可能会出现数组大小定义需求过大，这时候对数进行哈希映射处理，之后要输出再逆映射得到原数
https://blog.csdn.net/qq_38609781/article/details/84836583?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166927649216782425154549%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166927649216782425154549&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-84836583-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_controx1&utm_term=%E5%93%88%E5%B8%8C%E6%98%A0%E5%B0%84&spm=1018.2226.3001.4187
*/
















//小知识

/*~scanf(...)
//1. 机器数为补码表示
//2. ~ 按位取反
//3. scanf() 返回正确读取到的个数，读取错误返回-1
//4. -1的补码为全1，取反后就全0，退出循环
//5. ~scanf() == (scanf() != EOF)
//6.scanf的读取速度 远快于 cin :
	在同样输入一个数，cin的编译时间大约是scanf的3~4倍。所以，在使用大量数据的时候，cin的运算速度明显要满于scanf。
	简单来讲scanf 和 cin 在时间效率上差别很大的原因是：
	在scanf元素的类型我们已经告知了，机器不用再去查找元素类型，scanf需要自己写格式，是一种格式化输入。
	而在cin 元素类型由机器自己查找，cin是字符流输入，需要先存入缓冲区再输入。
*/


/* ios::sync_with_stdio(false)
该可以将cin和scanf的效率相匹敌。
默认的时候，cin与stdin总是保持同步的，也就是说这两种方法可以混用，而不必担心文件指针混乱，
同时cout和stdout也一样，两者混用不会输出顺序错乱。
正因为这个兼容性的特性，导致cin有许多额外的开销，使用该句可以禁用这个特性，取消cin于stdin的同步。
*/

/* cin.tie(0) 和 cout.tie(0)
tie()
tie是将两个stream绑定的函数，空参数的话返回当前的输出流指针。
在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率。
ACM应用
在ACM里，经常出现数据集超大造成 cin TLE的情况。这时候大部分人认为这是cin的效率不及scanf的错，甚至还上升到C语言和C++语言的执行效率层面的无聊争论。其实像上文所说，这只是C++为了兼容而采取的保守措施。我们可以在IO之前将stdio解除绑定，这样做了之后要注意不要同时混用cout和printf之类。
在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率。
原来而cin，cout之所以效率低，是因为先把要输出的东西存入缓冲区，再输出，导致效率降低，而这段代码可以来打消iostream的输入 输出缓存，可以节省许多时间，使效率与scanf与printf相差无几.
说白了，这两句加上就可以提高C++代码输入输出执行效率使得和C相差无几
*/

/*综上，cin,cout使用前的小技巧，解决读取输出而导致过长耗时的疑虑
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

第1，2句可以合成为：
cin.tie(0)->sync_with_stdio(false);
*/

/*register int
其中的 register 表示其后是使用 cpu内部寄存器 的变量
平时的int是把变量放在内存中，而这里存到寄存器中可以加快变量的读写速度
举例：
    循环1e8次，使用普通的int变量，耗时 0.5032s
    而使用register int，耗时 0.1375s
    提升极为明显
用途：
    用于较多次规定 i 范围的循环中，亦多用于多层循环中
*/





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓月赛1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://soj.csgrandeur.cn/csgoj/contest/problem?cid=1035&pid=D
题解链接：https://soj.csgrandeur.cn/index/answer/detail?nid=1045
*/

//A. A + B
// #include<bits/stdc++.h>
// #define ull unsigned long long
// using namespace std;
// ull a, b;
// int main()
// {
//     cin >> a >> b;
//     cout << a + b << endl;
// }



//B. 梦里什么都有
//WA 没办法处理有多个s0的情况
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int n,m,start,pos=1;
//     string s0,s1,t;
//     cin>>n>>m;
//     cin>>s0>>s1;
//     t=s1;
//     while(s1.find(s0,pos)!=s1.npos)
//     {
//         start=s1.find(s0,pos);
//         pos=start+1;
//         if(m < start+s0.size()) s1 = s1.substr(start + s0.size() - m);
//         cout<<"s1="<<s1<<endl;
//         start=s1.find(s0);
//         for(int i=0;i<=start && s1.size()>=m;i++)
//         {
//             cout<<s1.substr(0,m)<<endl;
//             s1=s1.substr(1);
//         }
//         s1=t;
//     }
//     return 0;
// }
//AC 直接遍历查找，含s0就输出，不能想复杂
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     int n,m;
//     string s0,s1,t;
//     cin>>n>>m;
//     cin>>s0>>s1;
//     for(int i=0;i<=n-m;i++)
//         if((t=s1.substr(i,m)).find(s0) != t.npos)
//             cout<<t<<endl;
//     return 0;
// }



//C. 关于我转生成为一匹赛马娘这档事
// 因为只能向右下方移动。可设方程2x?+?y?=?dis1,?x?+?2y?=?dis2，合并方程可得 3(x + y) = dis1 + dis2 = 两点间曼哈顿距离(实质是路程)，
// 实质来讲，马每次行动都会走 3 步格子(路程上看)，算出曼哈顿距离等于算出步数，所以步数%3==0说明是马走得到的，
// 所以只要终点与起点之间曼哈顿距离可以被3整除，就可以达到。
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n,res=0;
//     cin >> n;
//     while(n--)
//     {
//         int x,y,Mdis;
//         cin>>x>>y;
//         Mdis = (x+y-1-1);//(x,y)与点(1,1)的曼哈顿距离
//         if(Mdis%3==0 && x>Mdis/3 && y>Mdis/3)//右边两个条件限制只能是往右下方的曼哈顿距离
//             res++;
//     }
//     cout<<res<<endl;
//     return 0;
// }



//D. 封校之我想吃麦当劳
//dp状态：dp[n][m][2]，他的含义是在前i天内，吃了j次麦当劳，0/1表示第i天是否吃了麦当劳。
//在第i天的时候，如果上一天吃了，今天就不能吃，如果上一天没有吃，今天就可以吃。(且一天最多只能吃一顿)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[2005],f[2005][1005][2],n,m,res=0;
// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>a[i];//先存下幸福度
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//         {
//             f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]);//表示第i天不吃，并累计之前吃出来的幸福度，即今天不吃后总共的幸福度
//             f[i][j][1] = f[i-1][j-1][0] + a[i];//表示第i天吃，累计昨天若吃了之后的幸福度 加上 该天产生的幸福度，即今天吃了后总共的幸福度
//         }
//     cout<<max(f[n][m][0], f[n][m][1])<<endl;//取两种行为产生的结果的最大者
//     return 0;
// }



//E. 面基大作战
//结构体排序裸题
// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// struct per{
//     char name[15];
//     int sex,cf,at,fac,bod,id;
// };
// bool cmp(const per a, const per b)
// {
//     if(a.sex!=b.sex) return a.sex>b.sex;
//     if(a.cf!=b.cf) return a.cf>b.cf;
//     if(a.at!=b.at) return a.at>b.at;
//     if(a.fac!=b.fac) return a.fac>b.fac;
//     if(a.bod!=b.bod) return a.bod>b.bod;
//     return a.id<b.id;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     //上面三句使得 43ms -> 25ms，在其他题目可能体现更明显
//     int n;
//     cin>>n;
//     vector<per> v(n);
//     for(int i=0;i<n;i++)
//     {
//         per t={.id=i};
//         cin>>t.name>>t.sex>>t.cf>>t.at>>t.fac>>t.bod;
//         v[i]=t;
//     }
//     sort(v.begin(),v.end(),cmp);
//     for(int i=0;i<n;i++)
//     {
//         per t=v[i];
//         printf("%s %d %d %d %d %d\n",t.name, t.sex, t.cf, t.at, t.fac, t.bod);
//     }
//     return 0;
// }



//F. 删库跑路
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[30000],n;
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     long long x,y,sum=0;
//     cin>>n;
//     for(int i=0;i<n;i++) cin>>a[i];
//     cin>>x>>y;
//     for(int i=0;i<n;i++) sum+=min(y, x*a[i]);
//     cout<<sum<<endl;
//     return 0;
// }



/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑月赛1↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓月赛2↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://soj.csgrandeur.cn/csgoj/contest/problem?cid=1036&pid=A
题解链接：
*/

//A.  缺失的数字
// #include <iostream>
// #include <string>
// using namespace std;
// int a[15];
// int main()
// {
//     string n;
//     cin>>n;
//     for(int i=0;i<9;i++)
//     {
//         int num=n[i]-'0';
//         a[num]=1;
//     }
//     for(int i=0;i<=9;i++)
//     {
//         if(!a[i]) cout<<i;
//     }
//     return 0;
// }



//B. “本“
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n,a[]={2,4,5,7,9,0,1,6,8,3};
//     cin>>n;
//     n%=10;
//     for(int i=0;i<10;i++)
//     {
//         if(n==a[i]){
//             if(i<=4) cout<<"hon";
//             else if(i<9) cout<<"pon";
//             else cout<<"bon";
//         }
//     }
//     return 0;
// }



//C. 取数
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n,m,sum;
//     cin>>n>>m;
//     sum=n*(n-1)/2+m*(m-1)/2;
//     cout<<sum;
//     return 0;
// }



//D. When?
// #include <cstdio>
// using namespace std;
// int main()
// {
//     int sum,h,m;
//     scanf("%d",&sum);
//     h=sum/60;
//     m=sum%60;
//     if(22+h==24) printf("00:00");
//     else printf("%02d:%02d",22+h,m);
//     return 0;
// }



//E. 1! 5!
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n,x,t=-1,res=0;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         if(t==1&&x==5) res++;
//         t=x;
//     }
//     cout<<res;
//     return 0;
// } 



//F. 摆木棍(以数组下标存长度，本身就有序，所以越在数组前面越短，能一次性选完4根最好，不能就往后选)
// #include <cstdio>
// using namespace std;
// const int N = 5e4 + 5;
// int arr[N];
// int main()
// {
//     int n,t;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&t);
//         arr[t]++;
//     }
//     int x1=0,x2=0;
//     for(int i=1;i<N;i++)
//     {
//         while(arr[i]>=2)
//         {
//             arr[i]-=2;
//             if(!x1)
//             {
//                 x1=i;
//                 continue;
//             }
//             if(!x2)
//             {
//                 x2=i;
//                 continue;
//             }
//             break;
//         }
//         if(x1&&x2) break;
//     }
//     if(x1&&x2) printf("%lld",1ll*x1*x2);
//     else printf("-1");
//     return 0;
// }



//G. 开趴（思维很重要）
// 想象一数轴，任意找一个点，它左边有4个点，右边有2个点，把该点往左移动一点点，不要移动太多，以免碰到其他输入点。
//假设移动了d单位距离，则该点到左边4个点的距离各减少d，该点都右边2个点的距离各增加d,但总的来说，距离之和减少了2d。
//即对于两侧的点来说，由于一侧的点多于另一侧，那么它从中间点过来的时候一定徒增了很多距离。
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[100005];
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     int n;
//     long long ans=0;
//     cin>>n;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     sort(a+1,a+1+n);
//     for(int l=1,r=n; l<r ;l++,r--)
//     {
//         ans+=a[r]-a[l];
//     }
//     cout<<ans;
//     return 0;
// }



//H. 复合函数
// #include <iostream>
// using namespace std;
// int a[105];
// long long func(int n, int k)
// {
//     if(k==1) return a[n];
//     return func(a[n],k-1);
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     int n,q;
//     cin>>n;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     cin>>q;
//     while(q--)
//     {
//         int num,b;
//         cin>>num>>b;
//         cout<<func(num,b)<<endl;
//     }
//     return 0;
// }   



/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑月赛2↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓迎新赛↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://soj.csgrandeur.cn/csgoj/problemset/problem?pid=1449
题解链接：https://soj.csgrandeur.cn/index/answer/detail?nid=1046
*/
//A. 阶梯数
// #include <cstdio>
// using namespace std;
// int a[510];
// int main()
// {
//     int ind = 1;
//     for(register int i = 123456789; i > 0 && ind <= 501; i--)
//     {   
//         int t = i, fl = 1, x;
//         do{
//             x = t % 10;
//             t /= 10;
//             if(t%10 >= x)
//             {
//                 fl = 0;
//                 break;
//             }
//         }while(t);
//         if(fl) a[ind++] = i;
//     }
//     int k;
//     scanf("%d", &k);
//     printf("%d", a[k]);
//     return 0;
// }



//B. 宝石冒险
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// ll b[100005];
// int main()
// {
//     int n, k;
//     ll sum = 0;
//     scanf("%d%d", &n, &k);
//     for(int i = 0; i < n; i++)
//     {
//         ll x, y;
//         scanf("%lld%lld", &x, &y);
//         b[i] = y - x;//若大于0，意味着拿y宝石更赚
//         sum += x;
//     }
//     sort(b, b + n, greater<ll>() );
//     for(int i = 0; i < k; i++)
//         sum += b[i];
//     printf("%lld", sum);
//     return 0;
// }



//C. 快来玩2048！(双指针-滑动窗口)
// #include <iostream>
// using namespace std;
// int arr[110][110];
// int n;
// void up()
// {
//     //从第一个(u=1)和第二个(d=2)开始看，可以合并就合并而且合并后才u++，合并不了时++u并置入t值，接着d也往后找非零块
//     //可以竖向或横向的 0 4 2 2 0 串来理解四个操作
//     for(int i=1;i<=n;i++)
//     {
//         int u = 1, d = 2;
//         while(d <= n)
//         {
//             int t = arr[d][i];
//             arr[d][i] = 0;
//             d++;
//             if(t==0) continue;
//             if(!arr[u][i])
//                 arr[u][i]=t;
//             else if(arr[u][i]==t)
//                 arr[u++][i]+=t;
//             else
//                 arr[++u][i]=t;
//         }
//     }
// }
// void down()
// {
//     for(int i=1;i<=n;i++)
//     {
//         int u = n - 1, d = n;
//         while(u >= 1)
//         {
//             int t = arr[u][i];
//             arr[u][i] = 0;
//             u--;
//             if(t==0) continue;
//             if(!arr[d][i])
//                 arr[d][i]=t;
//             else if(arr[d][i]==t)
//                 arr[d--][i]+=t;
//             else
//                 arr[--d][i]=t;
//         }
//     }
// }
// void left()
// {
//     for(int i=1;i<=n;i++)
//     {
//         int l = 1, r = 2;
//         while(r <= n)
//         {
//             int t = arr[i][r];
//             arr[i][r] = 0;
//             r++;
//             if(t==0) continue;
//             if(!arr[i][l])
//                 arr[i][l]=t;
//             else if(arr[i][l]==t)
//                 arr[i][l++]+=t;
//             else
//                 arr[i][++l]=t;
//         }
//     }
// }
// void right()
// {
//     for(int i=1;i<=n;i++)
//     {
//         int l = n - 1, r = n;
//         while(l >= 1)
//         {
//             int t = arr[i][l];
//             arr[i][l] = 0;
//             l--;
//             if(t==0) continue;
//             if(!arr[i][r])
//                 arr[i][r]=t;
//             else if(arr[i][r]==t)
//                 arr[i][r--]+=t;
//             else
//                 arr[i][--r]=t;
//         }
//     }
// }
// int main()
// {
//     int m;
//     bool if2048 = 0;
//     cin>>n>>m;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= n; j++)
//             cin>>arr[i][j];
//     for(int k = 1; k <= m; k++)
//     {
//         char ch;
//         int x, y;
//         cin>>ch>>x>>y;
//         switch(ch)
//         {
//             case 'U': 
//                 up(); break;
//             case 'D': 
//                 down(); break;
//             case 'L': 
//                 left(); break;
//             case 'R': 
//                 right(); break;
//         }
//         if(!arr[x][y]) arr[x][y] = 2;
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= n; j++)
//                 if(arr[i][j]==2048)
//                     if2048 = 1, k = m + 1;
//     }
//     cout<<(if2048 ? "Yes\n":"No\n");
//     for(int i = 1; i <= n; i++)
//         {
//             for(int j = 1; j <= n; j++)
//             {
//                 cout<<arr[i][j];
//                 cout<<(j == n ? '\n':' ');
//             }
//         }
//     return 0;
// }
/*
竖向为x轴，横向为y轴
4 3
0 0 2 4
4 4 8 4
8 8 2 4
2 2 2 2
U 4 2
D 1 1
L 3 3

4 4 2 8
8 8 8 4
2 2 4 2
0 2 0 0

2 0 0 0
4 4 2 8
8 8 8 4
2 4 4 2

2 0 0 0
8 2 8 0
16 8 4 0
2 8 2 0
*/



//？？？D. 卡牌游戏 
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int b[100010];
// int main()
// {
//     int n, x, m, q, l, r, val, cnt1 = 0, cnt2 = 0;
//     scanf("%d%d%d%d", &n, &x, &m, &q);
//     while(m--)
//     {
//         scanf("%d%d%d", &l, &r, &val);
//         b[l] += val, b[r + 1] -= val;
//     }
//     for(int i = 2; i <= n; i++)
//     {
//         if(b[i] >= 0) cnt1 += b[i]; 
//         else cnt2 -= b[i];
//     }
//     int cnt = max(cnt1, cnt2);
//     if(cnt <= q) printf("%d", cnt);
//     else printf("-1");
//     return 0;
// }
//找规律关系
// 2 2 2 2
// 1 1 2 2
// 1 2 3 2
// 2 3 4 2
//2

//3 3 3 3 3 3
//2 2 2 2 3 3
//2 2 1 1 2 2
//3 3 2 1 2 2
//3 2 1 1 2 2
//0 -1 -1 0 1 0 
//2

//3 3 3 3 3 3
//2 2 2 2 3 3
//2 1 1 1 2 2
//2 1 0 0 2 2
//-1 -1 -1 0 2 0 
//2
//对于改变牌大小的操作，可以忽略b[1]操作
//只选i = 2 ~ n的操作讨论，并顺着规律得到结果



//E. Joshua想见甘雨！
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int n, m, sum = 0;
//     cin >> n >> m;
//     while(n--)
//     {
//         string str;
//         cin >> str;
//         for(int i = 0; i < m; i++)
//         {
//             switch(str[i])
//             {
//                 case 'G': sum += 50; break;
//                 case 'B': sum += 40; break;
//                 case 'H': sum += 30; break;
//             }
//         }
//     }
//     cout << sum;
//     return 0;
// }



//F. 烦人的屏蔽系统
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     string str, ch, wd;
//     getline(cin, str);
//     getline(cin, ch);
//     getline(cin, wd);
//     int ind = str.find(wd);
//     while(ind != -1)
//     {
//         for(int i = 1; i < 2*wd.size() - 1; i += 2)
//         {
//             str.insert(ind + i, ch);
//         }
//         ind = str.find(wd);
//     }
//     cout << str;
//     return 0;
// }



//G. “虚空”一下，你就知道
// #include <iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cin >> x;
//     x%=100;
//     char ch = 'A' + x;
//     cout << ch;
//     return 0;
// }



//H. 我不想工作!
//案例数为 36 种情况，草稿纸列情况，发现规律
// #include <cstdio>
// using namespace std;
// int m, n;
// bool jud()
// {
//     if(n == 2) return 0;
//     if(2*m >= n) return 1;
//     return 0;
// }
// int main()
// {
//     scanf("%d%d", &m, &n);
//     printf(jud() ? "(^ v ^)" : "(; w ;)");
//     return 0;
// }



//I. zwc怎么办？
// #include <iostream>
// #include <string>
// #include <unordered_map>
// using namespace std;
// int main()
// {
//     int w, n, m, k, s1=20211016, s2=20221002;
//     cin >> n >> m >> k; 
//     unordered_map<string, int> strs;
//     string s;
//     for(int i=0;i<n;i++) cin>>s;
//     for(int i=0;i<m;i++) cin>>s, strs[s]=2;
//     for(int i=0;i<k;i++) cin>>s, strs[s]=1;
//     cin >> w;
//     while(w--)
//     {
//         cin>>s;
//         int x = strs[s];
//         if(x == 1) s1++, s2++;
//         else if(x == 2) s1--, s2++;
//     }
//     cout << s1 << ' ' << s2;
//     return 0;
// }



//J. 小A喜欢吃糖果
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int a[10005];
// int main()
// {   
//     int k, n, l, r;
//     int sum = 0;
//     scanf("%d%d%d%d", &k, &n , &l, &r);
//     for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//     sort(a, a + n);
//     for(int i = 0; i < n; i++)
//         if(a[i] >= l && a[i] <= r)
//         {
//             if(k >= a[i])
//             {
//                 k-=a[i];
//                 sum++;
//             }
//             else 
//                 break;
//         }
//     printf("%d", sum);
//     return 0;
// }



//K. 新年好
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const int MAXN = 2e5 + 10;
// ll a[MAXN];
// int n, m;
// bool check(ll x)
// {
//     //看能选出多少种花，若有 m 种以上说明该捆数某区间内可行，即可以有更多捆(>=x)，故舍去 l 的左区间，否则舍去 r 的右区间
//     ll cnt = 0, sum = 0;
//     if(!x) return 1;//0捆特判
//     for(int i = 0; i < n; ++i)
//     {
//         if(a[i] >= x) cnt++;//如此，每捆花肯定都能选到这一种花
//         else sum += a[i];
//     }
//     cnt += sum / x;//其余总和分给各捆花，加上每捆花所能分到的花种数，最终cnt即为一捆花的花种数量
//     return cnt >= m;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for(int i = 0; i < n; i++)  scanf("%lld", &a[i]);
//     ll l = 0, r = 0x7fffffffffffffff, ans = 0;
//     while(l <= r)
//     {
//         ll mid = l + (r - l) / 2;//对捆数二分查找
//         if(check(mid)) l = mid + 1, ans = mid;//最终答案是mid
//         else r = mid - 1;
//     }
//     printf("%lld", ans);
//     return 0;
// }
//竖向看,其和 >= m 即算一捆
// 3 3
// 3 2 1 
// 1
//1 1 1
//1 1
//1
//仅第一列为三种，故1捆

// 5 4
// 4 3 2 2 1
//1 1 1 1
//1 1 1
//1 1
//1 1
//1
//第一、二列满足，2捆

//2 2
//3 3
//1 1 1
//1 1 1
//三列均满足，3捆



//L. 要是不难，也挺简单的
//TLE (里面至少有双层循环，即时间复杂度至少为O(n*n),最大时为2000*2000*9=36e6,而实际不允许超过25e6,故超时)
// #include <iostream>
// #include <string>
// #include <unordered_set>
// #include <cmath>
// using namespace std;
// typedef long long ll;
// const ll base = 1e9 + 7;//1000000007
// ll F[15], N, K, res = 0;
// ll num[11]={0, 131, 17161, 2248091, 294499921, 579489385, 913108910, 617266377, 861894826, 908221553, 977022617};
// void judge(string s)
// {   
//     unordered_set<char> st;
//     for(auto ch : s)
//         if(!st.count(ch)) st.insert(ch);
//     F[st.size()]++;
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     string str = "";
//     cin>>N>>K;
//     for(register int i=0;i<N;i++) 
//     {
//         string s;
//         cin>>s;
//         str+=s;
//     }
//     for(register int i = 1;i <= N; i++)
//         for(register int j = 0; i + j <= N; j++)
//             judge(str.substr(j, i));
//     for(int i=1; i<=K; i++)
//         res += (F[i] * num[i]) % base;
//     cout << (res % base);
//     return 0;
// }

//需要使用 动态规划








/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑迎新赛↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓第二届程序设计竞赛↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://soj.csgrandeur.cn/csgoj/problemset#search=%E6%B7%B1%E5%9C%B3%E6%8A%80%E6%9C%AF%E5%A4%A7%E5%AD%A6%E7%AC%AC%E4%BA%8C%E5%B1%8A%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1%E7%AB%9E%E8%B5%9B

*/


//1.[doge]
// #include <cstdio>
// using namespace std;
// #define print() printf(\
// "         i:                       ;1ii1    \n\
//         ;;:i1                  :1;;:::i:   \n\
//         i::::;;              ;1:;:111;;1   \n\
//         i:::;i11ii1111iiii11i:::;iiii;:1   \n\
//        .i1;,,,,,,,1,,,,,,,,,,::::;;;;;:1   \n\
//      ii,,,,,,,,,,,,,,,,,,,,,,,,,:::::::1   \n\
//    :i,.......,,,,,,,,,,.. .....,,::::::1   \n\
//   .i.        .,,,,,,,.           ,::::::1  \n\
//   tfffffffG00f,,,,,:LfffffffffLCGf,:::::;; \n\
//  f,      00@@0G;:::f.        @@@00f::::::i \n\
//  ;f.     :0000f,::,f;        G00001::::::i.\n\
//  .i:::::::::::,::,:::::::::::::::::::::::;.\n\
//  ;;::::,,..ffLGCC,   ,:::::::::::::::::::;.\n\
//  ;:        .CCCL             .,,,.       i \n\
//  i          tG:                         ,; \n\
//  ;:..    ,GtGGGt    fGC               .,i  \n\
//   ;..          1GGGf.                .,i   \n\
//     ;;,..                      ..,,;i      \n\
//       .;;:,,...          ....,,:;;:        \n\
//           ,;;;;::,,,,,:::::;;;:.           \n\
// ")
// int main()
// {
//     print();
//     return 0;
// }



//2.绝地求生
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int base[] = {0,6,5,4,3,2,1,1};
// int main()
// {   
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         int a[16];
//         for(int i = 0; i < 16; i++)
//             scanf("%d", &a[i]);
//         sort(a + 1, a + 16);
//         for(int i = 1; i <= 7; i++)
//             a[i]+=base[i];
//         sort(a + 1, a + 16);
//         a[0]+=10+60;
//         if(a[0]==a[15]) printf("extra match\n");
//         else printf(a[0] > a[15] ? "Yes\n":"No\n");
//     }
//     return 0;
// }



//3.仲夏梦
//未完成
// #include <cstdio>
// using namespace std;
// int main()
// {   
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
        
//     }
//     return 0;
// }



//4.象棋残局
//WA
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int arr[15][15];
// int dir[8][2]={{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1}};
// int foot[4][2]={{0,-1},{-1,0},{0,1},{-1,0}};
// bool judge(int x, int y)
// {
//     for(int i=1;i<=10;i++)
//         for(int j=1;j<=9;j++)
//         {
//             int t = arr[i][j];
//             if(!t||t==5||t==6) continue;
//             if(t==1)
//             {
//                 int ok = 1;
//                 if(i==x)
//                 {
//                     for(int m = min(j,y)+1;m<max(j,y);m++)
//                         if(arr[x][m]!=0)
//                         {
//                             ok = 0;
//                             break;
//                         } 
//                 }
//                 else if(j==y)
//                 {
//                     for(int m = min(i,x)+1;m<max(i,x);m++)
//                         if(arr[m][y]!=0)
//                         {
//                             ok = 0;
//                             break;
//                         } 
//                 }
//                 if(ok&&(i==x||j==y)) return 1;
//             }
//             else if(t==4)
//             {
//                 int cnt = 0;
//                 if(i==x)
//                 {
//                     for(int m = min(j,y)+1;m<max(j,y);m++)
//                         if(arr[x][m]!=0) cnt++;
//                 }
//                 else if(j==y)
//                 {
//                     for(int m = min(i,x)+1;m<max(i,x);m++)
//                         if(arr[m][y]!=0) cnt++;
//                 }
//                 if(cnt==1) return 1;
//             }
//             else if(t==2 && (abs(i-x)==1 && j==y) || (abs(j-y)==1 && i==x))
//             {
//                 return 1;
//             }
//             else if(t==3)
//             {
//                 int dx, dy, fl = -1;
//                 for(int m=0;m<8;m++)
//                 {
//                     dx = i + dir[m][0];
//                     dy = j + dir[m][1];
//                     if(dx==x&&dy==y) 
//                     {
//                         fl=m;
//                         break;
//                     }
//                 }
//                 if(fl!=-1 && !arr[ i+foot[fl/2][0] ][ j+foot[fl/2][1] ]) 
//                     return 1;
//             }
            
//         }
//     return 0;
// }
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)
//     {
//         int x, y;
//         for(int i=1;i<=10;i++)
//         {
//             for(int j=1;j<=9;j++)
//             {
//                 scanf("%d", &arr[i][j]);
//                 if(arr[i][j]==5) x = i, y = j;
//             }
//         }
//         printf(judge(x,y) ? "Yes\n":"No\n");
//     }
//     return 0;
// }
//WA
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// int arr[15][15];
// int dir[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
// int foot[4][2]={{0,-1},{-1,0},{0,1},{-1,0}};
// int base[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};
// bool judge(int x, int y)
// {
//     for(int i=x-1;i>=1;i--)
//     {
//         if(arr[i][y]!=0) 
//         {
//             if(arr[i][y]==1) return 1;
//             break;
//         }
//     }
//     for(int i=x+1;i<=10;i++)
//     {
//         if(arr[i][y]!=0) 
//         {
//             if(arr[i][y]==1) return 1;
//             break;
//         }
//     }

//     for(int i=0;i<4;i++)
//     {
//         int dx=x+foot[i][0];
//         int dy=y+foot[i][1];
//         if(arr[dx][dy]==2) return 1;
//     }

//     for(int i=0;i<8;i++)
//     {
//         int dx = x + dir[i][0];
//         int dy = y + dir[i][1];
//         if(dx>=1&&dx<=10&&dy>=1&&dy<=10&&arr[dx][dy]==3&&!arr[ x+base[i/2][0] ][ y+base[i/2][1] ]) 
//         {
//             return 1;
//         }
//     }

//     for(int i=1;i<=10;i++)
//     {
//         for(int j=1;j<=9;j++)
//         {
//             int t = arr[i][j], cnt = 0;
//             if(t!=4) continue;
//             if(i==x)
//             {
//                 for(int m = min(j,y)+1;m<max(j,y);m++)
//                     if(arr[x][m]!=0) cnt++;
//             }
//             else if(j==y)
//             {
//                 for(int m = min(i,x)+1;m<max(i,x);m++)
//                     if(arr[m][y]!=0) cnt++;
//             }
//             if(cnt==1) return 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)
//     {
//         int x, y;
//         for(int i=1;i<=10;i++)
//         {
//             for(int j=1;j<=9;j++)
//             {
//                 scanf("%d", &arr[i][j]);
//                 if(arr[i][j]==5) x = i, y = j;
//             }
//         }
//         printf(judge(x,y) ? "Yes\n":"No\n");
//     }
//     return 0;
// }
/*
0 0 3 0 6 6 3 0 0
0 0 0 0 5 0 0 0 0
0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

0 0 3 6 4 3 3 0 0
0 0 3 4 5 4 1 0 4
0 0 3 1 4 4 3 0 0 
0 0 0 0 0 0 0 0 0
0 0 0 0 4 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/



//5.徒手拆机甲的前提
// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <unordered_map>
// using namespace std;
// unordered_map<string, int> mp;
// string str[9]={"SSS","SS","S","A","B","C","D","E","F"};
// struct node{
//     string name, level;
//     int m, id;
//     bool operator < (const node &x)const{
//         if(level!=x.level) return mp[level]<mp[x.level];
//         if(m!=x.m) return m<x.m;
//         return id<x.id;
//     }
// }arr[100005];
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     for(int i=0;i<9;i++) mp[str[i]] = i;
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         node t = {.id=i};
//         cin>>t.name>>t.level>>t.m;
//         arr[i] = t;
//     }
//     sort(arr+1, arr+1+n);
//     for(int i=1;i<=n;i++) cout<<arr[i].name<<' '<<arr[i].level<<' '<<arr[i].m<<'\n';
//     return 0;
// }



//6.星空指挥官的素养
//TLE
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;
// vector<unordered_set<int> > vs;
// bool judge(int a, int b)
// {
//     for(auto &t : vs)
//     {
//         if(t.find(a)!=t.end() || t.find(b)!=t.end())
//         {
//             t.insert(a);
//             t.insert(b);
//             return 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     cout.tie(0);
//     int n, m, t, ind = 0;
//     cin>>n>>m>>t;
//     for(int i=0;i<m;i++)
//     {
//         int a, b;
//         cin>>a>>b;
//         if(!vs.empty() && judge(a,b));
//         else 
//         {
//             unordered_set<int> st{a,b};
//             vs.push_back(st);
//         }
//     }

//     //上述分组后，想办法优化搜索，以空间换时间

//     while(t--)
//     {
//         char op;
//         int a,b,ok=0;
//         cin>>op;
//         if(op=='C')
//         {
//             cin>>a>>b;
//             for(auto t : vs)
//             {
//                 if(t.find(a)!=t.end() && t.find(b)!=t.end())
//                 {
//                     ok = 1;
//                     break;
//                 }
//             }
//             cout<<(ok ? "The data is normal.\n":"Warning! Please review the data!\n");
//         }
//         else if(op=='S')
//         {
//             cin>>a;
//             for(auto t : vs)
//             {
//                 if(t.find(a)!=t.end())
//                 {
//                     cout<<t.size()<<'\n';
//                     break;
//                 }
//             }
//         }
//     } 
//     return 0;
// }
/*
10 9 5
1 2
1 3
1 4
2 4
3 4
5 4
6 7
8 9
10 8
C 10 9
C 5 1
C 1 4
S 1
S 4
*/



//School Badge
// #include <iostream>
// using namespace std;
// bool judge(string s)
// {
//     for(auto ch: s)
//     {
//         if(ch != 'B' && ch != 'W') return 1;
//     }
//     return 0;
// }
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     int T;
//     cin>>T;
//     while(T--)
//     {
//         int n, m, ok = 1, cnt1 = 0, cnt2 = 0;
//         cin>>n>>m;
//         while(n--)
//         {
//             string str;
//             cin>>str;
//             for(auto ch: str)
//             {
//                 if(ch != 'B' && ch != 'W') ok = 0;
//                 cnt1 += ch == 'B';
//                 cnt2 += ch == 'W';
//             }
//         }
//         cout<<(ok&&cnt1>=1&&cnt2>=1 ? "Yes\n":"No\n");
//     }
//     return 0;
// }



//产品测试
// #include <iostream>
// using namespace std;
// int a[105][105];
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n, m;
//         cin>>n>>m;
//         for(int i=1;i<=n;i++)
//             for(int j=1;j<=m;j++)
//                 cin>>a[i][j];
//         for(int i=1;i<=n;i++)
//             for(int j=1;j<=m;j++)

//     }
//     return 0;
// }
























/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑第二届程序设计竞赛↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓SZTU Monthly 2020 Oct↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://soj.csgrandeur.cn/csgoj/problemset#search=SZTU%20Monthly%202020%20Oct.
题解链接：https://soj.csgrandeur.cn/index/answer/detail?nid=1003
*/
//1.闰年
// #include <cstdio>
// int main()
// {
//     int N; scanf("%d",&N);
//     printf((N%4==0&&N%100!=0)||N%400==0 ? "%d is a leap year." : "%d is not a leap year.", N);
//     return 0;
// }



//2.zjb学长想要玩！
// #include <cstdio>
// int main()
// {
//     long double x, sum = 0;
//     int n;
//     scanf("%d",&n);
//     while(n--) scanf("%Lf",&x), sum += x;
//     printf("%.0Lf",sum);
//     return 0;
// }



//3.火柴人
//贪心 尽量摆1，最多把1换成7
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n,x;
//     for(cin>>n;n--;)
//     {
//         cin>>x;
//         if(x<2) cout<<"-1\n";
//         else
//         {
//             string s(x/2 - x%2,'1');
//             s = (x%2?"7":"") + s;
//             cout<<s<<'\n';
//         }
//     }
//     return 0;
// }
//题解写法（更简洁）
// #include <iostream>
// using namespace std;
// int main() 
// {
//     int t,n;
//     cin >> t;
//     while(t--) {
//         cin >> n;
//         if(n<=1) printf("-1"),n=0;
//         if(n & 1) printf("7"), n -= 3;
//         while(n) printf("1"), n -= 2;
//         printf("\n");
//     }
//     return 0;
// }


//4.素（质）数
// #include <cstdio>
// bool judge(int x)
// {
//     for(int i = 2; i < x; i++)
//         if(x % i == 0) return 0;
//     return 1;
// }
// int main()
// {
//     int a, b, t = 0;
//     for(scanf("%d%d", &a, &b); a <= b; a++)
//         if(a != 1 && judge(a))
//             printf(" %d" + !t, a), t = 1;
//     if(!t) printf("-1");
//     return 0;
// }
//打表
// #include <cstdio>
// int arr[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
// int main()
// {
//     int a,b,ok=1,i=1;
//     for(scanf("%d%d",&a,&b);arr[i]<=b;i++)
//         if(arr[i]>=a) printf(" %d"+ok,arr[i]),ok=0;
//     printf(ok?"-1":"");
//     return 0;
// }



//5.总之就是不太可爱
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string t,str;
//     cin>>t;
//     while(!(cin>>str).eof())
//     {
//         int ok=0,ind;
//         for(auto ch : t) 
//             while((ind=str.find(ch))!=str.npos)
//                 str.erase(ind,1), ok=1;
//         cout<<(ok?str:"That's so cute!")<<'\n';
//     }
//     return 0;
// }



//6.钱钱的steam游戏
// #include<cstdio>
// #include<algorithm>
// using namespace std;
// struct node{
//     int W, id;
//     bool operator <(const node&y)const{
//         if(W==y.W) return id<y.id;
//         return W>y.W;
//     }
// }arr[40000];
// int n, k, E[40000];
// int main()
// {
//     scanf("%d%d",&n,&k);
//     for(int i=1;i<=10;i++) scanf("%d",&E[i]);
//     for(int i=1;i<=n;i++) 
//     {
//         node t{.id=i};
//         scanf("%d",&t.W);
//         arr[i]=t;
//     }
//     sort(arr+1,arr+1+n);
//     for(int i=1;i<=n;i++) arr[i].W += E[(i - 1)%10 + 1];
//     sort(arr+1,arr+1+n);
//     for(int i=1;i<=k;i++) printf(" %d"+!(i-1), arr[i].id);
//     return 0;
// }
/*
题解的struct定义 ?
struct node
{
    ll val;
    int id;
    node(){}
    node(ll _val, int _id){val = _val; id = _id;}
}num[maxn];
*/



//7.食堂调查
// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;
// int main()
// {
//     int n;
//     double x, m = 0;
//     string s;
//     map<string, double> mp;
//     for(cin>>n;n--;)
//     {
//         cin>>x>>s;
//         if(mp.count(s)) mp[s] += x;
//         else mp.insert({s,x});
//         if(mp[s]>m) m = mp[s];
//     }
//     for(auto x : mp)
//         if(x.second==m)
//         {
//             cout<<x.first;
//             break;
//         }
//     return 0;
// }



//8.辉辉翻扑克牌
// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     string b;
//     int cnt = 0, t;
//     cin >> b;
//     for(int i = b.size() - 1; i >= 0; i--)
//         if(b[t = i] == '0' && ++cnt)
//             while(t >= 0) b[t--] = (b[t] == '1' ? '0':'1');
//     cout << cnt;
//     return 0;
// }
//11011010100 无论从左开始看还是从右开始看都是8次
//题解：其实只用看当前状态是否和之前相同就好了
// #include<iostream>
// #include<cstring>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     int m = s.size(), k = m - 1;//s.size测量字符串s的长度
//     for(int i = 1;i < m; ++i)
//         if(s[i] == s[i - 1]) k--;
//     if(s[m - 1] == '0') k++; //判断最后一位
//     cout << k;
//     return 0;
// }



//9.万圣节大作战
//排序标准为 总价值大者 先被选，即题意中的最优策略
// #include <iostream>
// #include <algorithm>
// using namespace std;
// struct nd{
//     long long a, b;
//     bool operator <(const nd&x)const{
//         return (a+b)>(x.a+x.b);
//     }
// }monster[100010];
// int main()
// {
//     cin.tie(0)->sync_with_stdio(false);
//     int n;
//     long long sum1=0,sum2=0;
//     cin>>n;
//     for(int i=1;i<=n;i++) cin>>monster[i].a;
//     for(int i=1;i<=n;i++) cin>>monster[i].b;
//     sort(monster+1, monster+1+n);
//     for(int i=1;i<=n;i++)
//     {
//         if(i&1) sum1+=monster[i].a;
//         else sum2+=monster[i].b;
//     }
//     cout<<abs(sum1-sum2);
//     return 0;
// }



//10.在二叉树寻求邂逅是否搞错了什么
//947ms，险过，可优化算法
// #include <cstdio>
// #include <cmath>
// typedef long long ll;
// const double eps = 1e-5;
// int main()
// {
//     int n; 
//     for(scanf("%d", &n);n--;)
//     {
//         ll x, i = 0;
//         scanf("%lld",&x);
//         while(!(x>pow(2,i)-eps && x<pow(2,i+1)-eps)) i++;
//         printf("%lld\n",i+1);
//     }
//     return 0;
// }
//题解: 位运算
//在完全二叉树上，对于每个子节点来说，将其编号除以 2 就可以得到其父节点的编号
// #include <cstdio>
// int main()
// {
//     int n, num;
//     scanf("%d",&n);
//     for(int i=1; i<=n; i++)
//     {
//         int ans = 1;
//         scanf("%d", &num);
//         while(num >>= 1) ans++;
//         printf("%d\n", ans);
//     }
//     return 0;
// }



//11.怪物入侵
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// int arr[200010], n, a, b, k, sum = 0, x;
// using namespace std;
// int main()
// {
//     scanf("%d%d%d%d", &n, &a, &b, &k);
//     for(int i=1;i<=n;i++) 
//     {
//         scanf("%d", &x);
//         x %= a + b;
//         if(x > 0 && x <= a) sum++;
//         else if(x == 0) arr[i] = a >= b ? 1 : ceil(1.0 * b / a);
//         else arr[i] = ceil(1.0 * (x - a) / a);//x>a
//     }
//     sort(arr + 1, arr + 1 + n);
//     for(int i = 1; i <= n; i++) 
//     {
//         if(!arr[i]) continue;//跳过0
//         if(k - arr[i] < 0) break;
//         else k -= arr[i], sum++;
//     }
//     printf("%d", sum);
//     return 0;
// }
//7 10 50 12 1 8
//a+b=5
//2 0 0 2 1 3
//0 0 1 2 2 3
//x = hp%(a+b)
//0 < x <= a 可
//以下两者排序出所需k较小者
//x == 0
//x > a



//*12.我的青春爬山物语果然有问题(单调栈)
//TLE
// #include <cstdio>
// int h[80005];
// int main()
// {
//     int n, sum = 0;
//     scanf("%d",&n);
//     for(register int i = 1; i <= n; i++) scanf("%d",&h[i]);
//     int l = 1, r = 2;
//     while(l<n)
//     {
//         while(h[r]>=h[l]) l++,r++;
//         while(r<=n && h[l]>h[r]) r++;
//         sum += r - l - 1;
//         r = (++l) + 1;
//     }
//     printf("%d", sum);
//     return 0;
// }
//AC 递减栈
// #include <cstdio>
// #include <stack>
// using namespace std;
// int main()
// {
//     long long n, h, sum = 0; 
//     stack<int> sta;
//     for(scanf("%lld", &n); n--;)
//     {
//         scanf("%lld", &h);
//         while(!sta.empty() && h >= sta.top()) sta.pop();
//         sum += sta.empty() ? 0 : sta.size();
//         sta.push(h);
//     }
//     printf("%lld", sum);
//     return 0;
// }















/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑SZTU Monthly 2020 Oct↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓寒期集训赛1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://vjudge.net/contest/534933

*/


//Count Distinct Integers 
// unique函数可以删除有序数组中的重复元素。
// 注意：
//  这里的删除不是真的delete，而是将重复的元素放到容器末尾
//  unique函数的返回值是去重之后的尾地址
//  一定要先对数组进行排序才可以使用unique函数
// 写法：顺便计算新长度 int len = unique(arr, arr+10) - arr;
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[2000];
// int main()
// {
//     int n; cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     sort(a, a + n);
//     cout << (unique(a, a + n) - a);
//     return 0;
// }
//原判重写法
// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <cctype>
// #include <cstring>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// #include <unordered_set>
// using namespace std;
// int main()
// {
//     unordered_set<int> st;
//     int n;
//     scanf("%d", &n);
//     while(n--)
//     {
//         int x;
//         scanf("%d", &x);
//         st.insert(x);
//     }
//     int num = st.size();
//     printf("%d", num);
//     return 0;
// }



//Better Students Are Needed! 
//挺臭的，但手速题无需精简
// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <cctype>
// #include <cstring>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// #include <vector>
// using namespace std;
// struct nd{
//     int a, b, id;
// }arr[1500];
// bool cp1(const nd &x, const nd &y)
// {
//     if(x.a == y.a) return x.id < y.id;
//     return x.a > y.a;
// }
// bool cp2(const nd &x, const nd &y)
// {
//     if(x.b == y.b) return x.id < y.id;
//     return x.b > y.b;
// }
// bool cp3(const nd &x, const nd &y)
// {
//     if((x.a + x.b) == (y.a +y.b)) return x.id < y.id;
//     return (x.a + x.b) > (y.a +y.b);
// }
// vector<int> ans;
// int main()
// {
//     int n,x,y,z;
//     scanf("%d%d%d%d",&n,&x,&y,&z);
//     for(int i =1;i<=n;i++) scanf("%d",&arr[i].a), arr[i].id = i;
//     for(int i =1;i<=n;i++) scanf("%d",&arr[i].b), arr[i].id = i;
//     sort(arr+1, arr+n+1, cp1);
//     for(int i =1;i<=n&&x;i++)
//         if(arr[i].a != -1)
//         {
//             arr[i].a = -1;
//             ans.push_back(arr[i].id);
//             x--;
//         }
//     sort(arr+1, arr+n+1, cp2);
//     for(int i =1;i<=n&&y;i++)
//         if(arr[i].a != -1)
//         {
//             arr[i].a = -1;
//             ans.push_back(arr[i].id);
//             y--;
//         }
//     sort(arr+1, arr+n+1, cp3);
//     for(int i =1;i<=n&&z;i++)
//         if(arr[i].a != -1)
//         {
//             arr[i].a = -1;
//             ans.push_back(arr[i].id);
//             z--;
//         }
//     sort(ans.begin(), ans.end());
//     for(auto i : ans) printf("%d\n",i);  
//     return 0;
// }



//±1 Operation 2 (二分 + 前缀和)
//简洁版
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// ll a[200010],s[200010];
// int main()
// {
//     ll n, q, x;
//     scanf("%lld%lld", &n, &q);
//     for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
//     sort(a + 1, a + 1 + n);
//     for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
//     while(q--)
//     {
//         scanf("%lld", &x);
//         int m2 = upper_bound(a + 1, a + 1 + n, x) - (a + 1);
//         printf("%lld\n", (2 * m2 - n) * x - 2 * s[m2] + s[n]);
//     }
//     return 0;
// }
//理解版
// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <cctype>
// #include <cstring>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// #include <vector>
// using namespace std;
// typedef long long ll;
// ll a[200010],s[200010];
// int main()
// {
//     ll n,q;
//     scanf("%lld%lld",&n,&q);
//     for(int i = 1; i <= n;i++) scanf("%lld", &a[i]);
//     sort(a+1,a+1+n);
//     for(int i = 1; i <= n;i++)
//         s[i] = s[i-1] + a[i];
//     while(q--)
//     {
//         ll x;
//         scanf("%lld", &x);
//         if(x >= a[n]) printf("%lld\n", n*x - s[n]);
//         else if(x <= a[1]) printf("%lld\n", s[n] - n*x);
//         else{
//             ll ans = 0;
//             int m1 = lower_bound(a+1,a+1+n,x) - a;
//             int m2 = upper_bound(a+1,a+1+n,x) - a;
//             m1--;
//             // ans = m1*x - s[m1] + s[n] - s[m2 - 1] - (n - m2 + 1)*x;
//             ans = (m1 - n + m2 - 1)*x - s[m1] - s[m2 - 1] + s[n];
//             printf("%lld\n",ans);
//         }
//     }
//     return 0;
// }



//*Submask 
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// typedef long long ll;
// vector<ll> ans;
// int main()
// {
//     ll N;
//     cin >> N;
//     //题意中最大N的二进制有15个1，即 2^60 - 1
//     //用 i 枚举出所有 N 的二进制子集
//     for(ll i = (1ll << 60) - 1; i >= 0; i--)//0 也是答案
//     {
//         i &= N;//取子集
//         ans.push_back(i);
//     }
//     reverse(ans.begin(), ans.end());//由于是逆序枚举存入的子集，翻转后输出
//     for(auto x : ans) cout << x << '\n';
//     return 0;
// }
/*
题解思路：
用 & 取 T 和 U 的交集：
T = {A,B,C}: 0111
U = {B,D}:   1010
T ∩ U = {B}: 0111 & 1010 = 0010 
枚举所有包含于 T 的 U
设 N = 11 ，二进制表示为 1011
imax = 0111 1111 1111 1111
显然此时 i 与 N 交集即为 N (i ∩ N = N) 
缩减 i 的同时(i--)，重复进行取子集步骤
序号    i    i & N  
1     imax   1011  （步骤：遍历往下进行i--，取子集，存子集）
2     1010   1010
3     1001   1001
4     1000   1000
5     0111   0011
6     0010   0010
7     0001   0001
8     0000   0000
END
*/


//Equal Candies 
// #include <iostream>
// #include <cstdio>
// #include <string>
// #include <cctype>
// #include <cstring>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// using namespace std;
// int a[100];
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)
//     {
//         int n;
//         scanf("%d", &n);
//         for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//         sort(a, a + n);
//         long long ans = 0;
//         for(int i = 1; i < n; i++) ans += a[i] - a[0];
//         printf("%lld\n", ans);
//     }
//     return 0;
// }



//Spell Check 
//刘学长的解法 :)
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         sort(s.begin(), s.end());//将字符串序列统一按字典序排序，用字典序升序的序列判断即可
//         if(s == "Timru") cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }











/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑寒期集训赛1↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////











/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓寒期集训赛2↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://vjudge.csgrandeur.cn/contest/535123

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}

using namespace std;



int main()
{
    





    return 0;
}
*/



//"atcoder".substr() 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// int main()
// {
//     string s = "atcoder";
//     int l ,r;
//     cin >> l >> r;
//     cout << s.substr(l - 1 ,r - l + 1);
//     return 0;
// }



//NewFolder(1) 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// int main()
// {
//     untie();
//     map<string, int> mp;
//     int n;
//     cin >> n;
//     while(n--)
//     {
//         string s;
//         cin >> s;
//         mp[s]++;
//         if(mp[s]==1) cout << s << '\n';
//         else cout << s << "(" << (mp[s]-1) <<")\n";
//     }
//     return 0;
// }



//Counting Arrays 
//此题方法甚多
//1. (map || set) && vector
//2. (map || set) && list
//3. (map || set) && string (要一整句连着空格)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <list>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// map<list<int>, bool> mp;
// int main()
// {
//     untie();
//     int n, L;
//     cin >> n;
//     while(n--)
//     {
//         cin >> L;
//         list<int> li;
//         while(L--) 
//         {
//             int x;
//             cin >> x;
//             li.push_back(x);
//         }
//         mp[li] = 1;
//     }
//     cout<<mp.size();
//     return 0;
// }



//激光炸弹 
// #include <iostream>
// #include <cstdio>
// using namespace std;
// const int N = 5e3 + 1;
// int arr[N+5][N+5];
// int main()
// {       
//     int n,m,a,b,val;
//     scanf("%d%d",&n,&m);
//     for(int i = 1; i <= n;i++)
//     {
//         scanf("%d%d%d",&a,&b,&val);
//         arr[a+1][b+1] += val;//从(1,1)开始
//     }
//     for(int i=1;i<=N;i++) 
//         for(int j=1;j<=N;j++)
//             arr[i][j] = arr[i - 1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
//     int ans = 0;
//     for (int x = m; x <= N; x++)
// 		for (int y = m; y <= N; y++)
//         {
//             int res = arr[x][y] - arr[x-m][y] - arr[x][y-m] + arr[x-m][y-m]; 
//             ans = max(ans, res);
//         } 
//     printf("%d\n",ans);
//     return 0;
// }



//Buy an Integer 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// typedef long long ll;
// using namespace std;
// int count(ll x)
// {
//     ll t = x;
//     int res = 0;
//     while(t)
//     {
//         res++;
//         t/=10;
//     }
//     return res;
// }
// int main()
// {
//     untie();
//     ll a, b ,x;
//     cin >> a >> b>> x;
//     ll L = 0, R = 1e9, m1;
//     for(int i = 0 ;i<100;i++)
//     {
//         m1 = L + ((R - L)>>1);
//         if(a*m1 + b*count(m1) <= x) L = m1 + 1;
//         else R = m1 - 1;
//     }
//     L--;
//     if(a*L + b*count(L) <= x) cout << L;
//     else cout << '0';
//     return 0;
// }



//Full House 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// int main()
// {
//     int a;
//     map<int,int> mp;
//     for(int i = 0;i<5;i++) 
//     {
//         scanf("%d",&a);
//         mp[a]++;
//     }
//     int ifno = 1,b,c;
//     for(auto x : mp)
//     {
//         if(ifno) b = x.second, ifno =  0;
//         else c = x.second;
//     }
//     if(mp.size() == 2 && (b==2&&c==3) || (b==3&&c==2)) printf("Yes\n");
//     else printf("No\n");
//     return 0;
// }




/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑寒期集训赛2↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓寒期集训赛3↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://vjudge.csgrandeur.cn/contest/535422

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}

using namespace std;



int main()
{
    





    return 0;
}

*/



//语文成绩
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int arr[5000005], b[5000005];
// int main()
// {
//     int n, p;
//     scanf("%d%d", &n, &p);
//     for(int i = 1; i <= n ; i++) scanf("%d", &arr[i]), b[i] = arr[i] - arr[i - 1];
//     while(p--)
//     {
//         int l, r, x;
//         scanf("%d%d%d", &l, &r, &x);
//         b[l] += x;
//         b[r + 1] -= x;
//     }
//     int mmin = 300;
//     for(int i = 1; i <= n; i++)
//     {
//         b[i] += b[i - 1];
//         mmin = min(mmin, b[i]);
//     }
//     printf("%d\n", mmin);
//     return 0;
// }



//Do use hexagon grid 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// bool mp[2100][2100], vis[2100][2100];
// int dir[6][2] = {{-1, -1}, {0, -1}, {-1, 0}, {1, 0}, {0, 1}, {1, 1}};
// int n, m, cnt = 0;
// void dfs(int i, int j)
// {
//     vis[i][j] = 1;
//     for(int k = 0; k < 6; k++)
//     {
//         int ni = i + dir[k][0];
//         int nj = j + dir[k][1];
//         if(ni >= 0 && nj >= 0 && ni <= 2000 && nj <= 2000 && !vis[ni][nj] && mp[ni][nj])
//             dfs(ni, nj);
//     }
// }
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin>> x >> y;
//         x += 1000, y += 1000;
//         mp[x][y] = 1;
//     }
//     for(int i = 0; i <= 2000; i++)
//         for(int j = 0; j <= 2000; j++)
//         {
//             if(mp[i][j] && !vis[i][j])
//             {
//                 cnt ++;
//                 dfs(i, j);
//             }
//         }
//     cout << cnt << '\n';
//     return 0;
// }



//Minimum Varied Number 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int main()
// {
//     untie();
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n, cnt = 9, ans = 0;
//         cin >> n;
//         vector<int> v;
//         //20  9 8 3
//         //8 8 
//         //10 9 1
//         //45 
//         //45 9 8 7 6 5 4 3 2 1
//         while(n || cnt)
//         {
//             if(n >= cnt)
//             {
//                 v.push_back(cnt);
//                 n -= cnt;
//                 cnt--;
//             }
//             else
//             {
//                 v.push_back(n);
//                 break;
//             }
//         }
//         int len = v.size() - 1;
//         while(len >= 0) ans = ans * 10 + v[len--];
//         cout << ans << '\n';
//     }
//     return 0;
// }



//EKO / 砍树 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// typedef long long ll;
// ll arr[1000005], n, m;
// bool judge(ll mid)
// {
//     ll sum = 0;
//     for(int i = 1; i <= n; i++)
//         if(arr[i] > mid) sum += arr[i] - mid;
//     return sum >= m;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     ll mmax = 0;
//     for(int i = 1;i <= n; i++) cin >> arr[i], mmax = max(mmax, arr[i]);
//     ll l = 1, r = mmax;
//     while(l <= r)
//     {
//         ll mid = l + ((r - l) >> 1);
//         if(judge(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << (l - 1) << '\n';
//     return 0;
// }



//Atilla's Favorite Problem 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// int arr[10000];
// int main()
// {
//     untie();
//     int t;
//     cin >> t;
//     for(int i = 'a'; i <= 'z'; i++) arr[i] = i - 'a' + 1;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         string s;
//         cin >> s;
//         sort(s.begin(), s.end());
//         cout << arr[s.back()] << '\n';
//     }
//     return 0;
// }



//Belt Conveyor 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// using namespace std;
// char mp[555][555];
// bool vis[555][555];
// int ansi = 0, ansj = 0, n, m, ifnot = 0;
// void dfs(int i, int j)
// {
//     int ni = i, nj = j;
//     switch(mp[i][j])
//     {
//         case 'U': ni--;break;
//         case 'D': ni++;break;
//         case 'L': nj--;break;
//         case 'R': nj++;break;
//     }
//     if(ni >= 0 && ni < n && nj >= 0 && nj < m)
//     {
//         if(vis[ni][nj]) 
//         {
//             ifnot = 1;
//             return;
//         }
//         vis[ni][nj] = 1;
//         ansi = ni;
//         ansj = nj;
//         dfs(ni, nj);
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) cin >> mp[i];
//     dfs(0, 0);
//     if(ifnot) cout << "-1\n";
//     else
//         cout << (ansi + 1) << " " << (ansj + 1) << '\n';
//     return 0;
// }






/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑寒期集训赛3↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓寒期集训赛4↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://vjudge.csgrandeur.cn/contest/535668

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>



using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}





int main()
{
    





    return 0;
}

*/


//Misjudge the Time 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int cnth = 0, cntm = 0, i = -1;
// bool check(int h, int m)
// {
//     int th = h / 10 * 10 + m / 10;
//     int tm = h % 10 * 10 + m % 10;
//     if(th <= 23 && tm <= 59)
//     {
//         cout << h << " " << m;
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     untie();
//     cin >> cnth >> cntm;
//     while(1)
//     {
//         if(check(cnth, cntm)) break;
//         cntm ++;
//         if(cnth == 24) cnth = 0;
//         if(cntm == 60) cntm = 0, cnth++;
//         if(cnth == 24) cnth = 0;
//     }
//     return 0;
// }



//* 铺设道路 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int a[100005];
// int main()
// {
//     untie();
//     int cnt = 0, n;
//     cin >> n;
//     for(int i = 1; i <=n;i++) cin >> a[i];
//     for(int i = 1; i <=n;i++) 
//         if(a[i]>a[i-1])
//         cnt += a[i] - a[i-1];
//     cout << cnt;
// //大坑附近的小坑肯定会在填大坑的时候填完，所以无需顾虑
// //0 4 3 2 5 3 5 0 （两侧的 0 方便理解）
// //最小天数为第一个坑，即 4，(可推)
// //4 后面的小坑会在填大坑时顺便填完，
// //而 5 也会跟着前面的小坑一起被填，5 - 2 = 3，
// //所以 5 这个大坑只需要多 3 天就可填完
// //5 后面的 3 自然也是顺便被填
// //3 后面的 5 也会跟着 3 被填平而被填，所以最后只需要多 5 - 3 = 2 天来填最后一个大坑 5
// //总和为 4 + 3 + 2 = 9 天
//     return 0;
// }



//Cypher 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int arr[200];
// int main()
// {
//     untie();
//     int T, n;
//     cin >> T;
//     while(T--)
//     {
//         cin >> n;
//         for(int i = 1; i<=n;i++) cin >> arr[i];
//         for(int i = 1; i<=n;i++)
//         {
//             int x;
//             cin >> x;
//             for(int j = 1; j <= x; j++)
//             {
//                 char op;
//                 cin >> op;
//                 switch(op)
//                 {
//                     case 'D': 
//                         arr[i]++;
//                         if(arr[i] == 10) arr[i] = 0;
//                         break;
//                     case 'U': 
//                         arr[i]--;
//                         if(arr[i] == -1) arr[i] = 9;
//                         break;
//                 }
//             }
//         }
//         for(int i = 1; i<=n;i++)
//         {
//             printf(" %d" + !(i -1), arr[i]);
//         }
//         puts("");
//     }
//     return 0;
// }



//Prime Path 
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int times, a, b, net, res;
// bool prime[10000], vis[10000];
// queue<int> q;
// #define PUSH(x) {if(!vis[x] && prime[x]) {q.push(x); vis[x] = 1;}}
// bool BFS()
// {
// 	q.push(a);
// 	res = -1;
// 	vis[a] = 1;
//     int sz;
// 	while(sz = q.size())
// 	{
// 		res++;
// 		while(sz--)
// 		{
// 			int t = q.front(); q.pop();
// 			if(t == b) return 1;
// 			for(int i = 0; i <= 9; i++)
// 			{
// 				if(i!=0)
// 				{
// 					net = i*1000 + t%1000;
// 					PUSH(net);
// 				}
// 				net = i*100 + t%100 + t/1000*1000;
// 				PUSH(net);
// 				net = i*10 + t%10 + t/100*100;
// 				PUSH(net);
// 				net = i + t/10*10;
// 				PUSH(net);
// 			}
// 		}
// 	}
// 	return 0;
// }
// void init()
// {
//     for(int n=1000;n<=9999;n++)
// 	{
// 		prime[n]=1;
// 		for(int i=2;i*i<=n;i++)
// 			if(n%i==0) {prime[n]=0; break;}
// 	}
// }
// int main()
// {
//     untie();
// 	init();
// 	cin >> times;
// 	while(times--)
// 	{
// 		memset(vis, 0, sizeof(vis));
// 		while(q.size()) q.pop();
// 		cin >> a >> b;
// 		if(BFS()) cout << res << '\n';
// 		else cout<<"Impossible\n";
// 	}
// 	return 0;
// }



//*Ladder Takahashi （图论基础）
//要学习图论，先学邻接矩阵建图，对其会搜索
//建图(重点) 与 搜索
// #include <iostream>
// #include <map>
// #include <vector>
// #include <queue>
// #include <set>
// using namespace std;
// int n, a, b;
// map<int, vector<int> > gra;//可一对多，构建出所有路径
// set<int> ans;
// //1.利用集合不重复性，防止无意义的原路返回 和 路径重复
// //2.利用有序性，存储各路径能到达的高度，最后取容器尾部的最大者即可
// void bfs()
// {
//     queue<int> q;
//     q.push(1);
//     while(q.size())
//     {
//         int ori = q.front(); q.pop();//取一个起点
//         for(int next : gra[ori])//遍历该起点后所有路径
//         {
//             if(!ans.count(next))
//             {
//                 ans.insert(next);
//                 q.push(next);
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         cin >> a >> b;
//         gra[a].push_back(b);
//         gra[b].push_back(a);//梯子是双向可行的
//     }
//     ans.insert(1);//至少能到达 1
//     bfs();
//     cout << *ans.rbegin();//输出最大者
//     return 0;
// }



//Stripes 
//BFS解法，巨麻烦
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int cntB = 0, cntR = 0;
// char mp[10][10];
// bool vis[10][10];
// int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
// struct nd{
//     int x, y, t;
// };
// void bfs(int x, int y, char ch)
// {
//     queue<nd> q;
//     q.push(nd{x, y, 1});
//     vis[x][y] = 1;
//     while(q.size())
//     {
//         nd tmp = q.front();
//         q.pop();
//         if(tmp.t == 8)
//         {
//             if(ch == 'R') cntR++;
//             else cntB++;
//         }
//         int m = 0;
//         if(ch == 'R') m = 2;
//         for(int i = m ; i < 2 + m; i++)
//         {
//             int nx = tmp.x + dir[i][0];
//             int ny = tmp.y + dir[i][1];
//             if(nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7 && mp[nx][ny] == ch && !vis[nx][ny])
//             {
//                 vis[nx][ny] = 1;
//                 q.push(nd{nx,ny,tmp.t+1});
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         cntB = cntR = 0;
//         memset(vis, 0, sizeof(vis));
//         for(int i = 0; i <= 7; i++)
//             cin >> mp[i];
//         for(int i = 0; i <= 7; i++)
//             for(int j = 0; j <= 7; j++)
//             {
//                 if(mp[i][j]!='.'&& !vis[i][j])
//                 {
//                     bfs(i, j, mp[i][j]);
//                 }
//             }
//         if(cntR > cntB) cout << "R\n";
//         else cout << "B\n";
//     }
//     return 0;
// }
//可双向遍历
// #include <iostream>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// string baseR = "RRRRRRRR", baseB = "BBBBBBBB";
// int main()
// {
//     untie();
//     int T; cin >> T;
//     while(T--)
//     {
//         int cntr = 0, cntb = 0;
//         string r[10], b[10];
//         for(int i = 0; i < 8; i++)
//             for(int j = 0; j < 8; j++)
//             {
//                 char ch;
//                 cin >> ch;
//                 r[i].push_back(ch);
//                 b[j].push_back(ch);
//             }
//         for(int i = 0; i < 8; i++)
//         {
//             if(r[i] == baseR) cntr++;
//             if(b[i] == baseB) cntb++;
//         }
//         if(cntr > cntb) cout << "R\n";
//         else cout << "B\n";
//     }
//     return 0;
// }
//更简单的，只需要判断 R 有没有成条即可，R 成条说明 B 不成条， R 不成条说明 B 成条
// #include <iostream>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int main()
// {
//     untie();
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int f = 0;
//         for(int i = 0; i < 8; i++)
//         {
//             string s;
//             cin >> s;
//             int cnt = 0;
//             for(int j = 0; j < 8; j++) cnt += (s[j] == 'R');
//             if(cnt == 8) f = 1;
//         }
//         if(f == 0) cout << "B\n";
//         else cout << "R\n";
//     }
//     return 0;
// }




























/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑寒期集训赛4↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓寒期集训赛5↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
/*
题目链接：https://vjudge.csgrandeur.cn/contest/536144

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>



using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}





int main()
{
    





    return 0;
}

*/




// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>



// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}


// int f[100][100][100];
// int w(int a, int b, int c)
// {
//     if(a <= 0 || b <= 0 || c <= 0) return 1;
//     if(a > 20 || b > 20 || c > 20) 
//     {
//         if(f[20][20][20]!=0) return f[20][20][20];
//         return w(20, 20, 20);
//     }
//     if(f[a][b][c] != 0) return f[a][b][c];
//     if(a < b && b < c) return (f[a][b][c-1]=w(a, b, c-1)) + (f[a][b-1][c-1]=w(a, b-1, c-1)) - (f[a][b-1][c]=w(a, b-1, c));
//     return (f[a-1][b][c]=w(a-1, b, c)) + (f[a-1][b-1][c]=w(a-1, b-1, c)) + (f[a-1][b][c-1]=w(a-1, b, c-1)) - (f[a-1][b-1][c-1]=w(a-1, b-1, c-1));
// }   
// int main()
// {
//     untie();
//     int a, b, c;
//     while(cin>>a>>b>>c, a!=-1 || b!=-1 || c!=-1)
//     {
//         printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
//     }
//     return 0;
// }







// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_set>



// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}

// #define pf() {printf("\
//                 ********\n\
//                ************\n\
//                ####....#.\n\
//              #..###.....##....\n\
//              ###.......######              ###            ###\n\
//                 ...........               #...#          #...#\n\
//                ##*#######                 #.#.#          #.#.#\n\
//             ####*******######             #.#.#          #.#.#\n\
//            ...#***.****.*###....          #...#          #...#\n\
//            ....**********##.....           ###            ###\n\
//            ....****    *****....\n\
//              ####        ####\n\
//            ######        ######\n\
// ##############################################################\n\
// #...#......#.##...#......#.##...#......#.##------------------#\n\
// ###########################################------------------#\n\
// #..#....#....##..#....#....##..#....#....#####################\n\
// ##########################################    #----------#\n\
// #.....#......##.....#......##.....#......#    #----------#\n\
// ##########################################    #----------#\n\
// #.#..#....#..##.#..#....#..##.#..#....#..#    #----------#\n\
// ##########################################    ############\n\
// ");}



// int main()
// {
    
//     pf();




//     return 0;
// }







// #include <iostream>
// #include <map>
// #include <vector>
// #include <queue>
// #include <set>
// using namespace std;
// int n, m, a, b;

// map<int, vector<int> > gra;
// set<int> ans;
// void bfs()
// {
//     queue<int> q;
//     ans.insert(a);
//     q.push(a);
//     while(q.size())
//     {
//         int ori = q.front(); q.pop();
//         for(int next : gra[ori])
//         {
//             if(!ans.count(next))
//             {
//                 ans.insert(next);
//                 q.push(next);
//             }
//         }
//     }
// }
// int main()
// {
//     while(cin >> n, n)
//     {
//         cin >> m;
//         for(int i = 0; i < m; i++)
//         {
//             cin >> a >> b;
//             gra[a].push_back(b);
//             gra[b].push_back(a);
//         }
//         if(m) bfs();
//         if(m) cout << (n - ans.size()) << '\n';
//         else cout << (n - 1) << '\n';
//         if(!ans.empty()) ans.clear();
//         gra.clear();
//     }
//     return 0;
// }









// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>



// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}



// int n;

// int main()
// {
//     untie();
//     cin >> n;
//     while(n--)
//     {
//         int m;
//         cin >> m;
//         if(m % 2 == 0) cout << "pb wins\n";
//         else cout << "zs wins\n";
//     }



//     return 0;
// }









// #include <cstdio>
// const int N = 1500;
// int ds[N];
// void init_set(int n)
// {
//     for(int i = 1; i <= n; i++)
//         ds[i] = i;
// }
// int find_set(int x)
// {
//     return x == ds[x] ? x : (ds[x] = find_set(ds[x]));
// }
// void merge_set(int x, int y)
// {
//     if((x = find_set(x)) != (y = find_set(y)))  ds[x] = ds[y];
// }
// int main()
// {
    
//     int n, m, a, b;
    
//     while(~scanf("%d", &n), n)
//     {
//         int res = -1;
//         scanf("%d%", &m);
//         init_set(n + 1);
//         for(int i = 1 ; i <= m ; i++)
//             scanf("%d%d", &a, &b), merge_set(a, b);
//         for(int i = 1 ; i <= n ; i++)
//             if(find_set(i) == i) res++;//自身为祖表示未联系，且减去必有的一个祖先
//         printf("%d\n", res);
//     }
//     return 0;
// }











// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>
// #include <string>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// #include <queue>


// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e5 + 10;


// int n, mp[N];
// bool vis[N];
// int ans = 0;

// void dfs(int i)
// {
    
// }
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         cin >> n;
//         ans = 0;
//         for(int i = 1; i <= n; i++) cin >> mp[i], vis[i] = 0;
//         for(int i = 1; i <= n; i++)
//         {
//             if(vis[i] == 0)
//             {
                
                
//             }
//         }
//         cout << ans << '\n';
//     }



//     return 0;
// }
































/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑寒期集训赛5↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓阶段赛1↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/


//https://soj.csgrandeur.cn/csgoj/contest/problemset?cid=1038




/*

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cmath>

using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

int main()
{


    return 0;
}

*/

//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 2e5 + 10;
// int n, q;
// map<int, int> mp;
// typedef pair<int, int> pii;
// set<pii> st;
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         if(x > y) swap(x, y);
//         if(!st.count(pii(x, y)))
//             st.insert(pii(x, y)), mp[x]++, mp[y]++;
//     }
//     cin >> q;
//     while(q--)
//     {
//         int x;
//         cin >> x;
//         if(mp.count(x)) cout << mp[x] << '\n';
//         else cout << "0\n";
//     }
//     return 0;
// }
//题解简洁写法:
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// map<int, set<int> > gra;//每个人编号 对应与其具有秘密关系的集合
// int main()
// {
//     untie();
//     int n, x, a, b;
//     cin >> n;
//     while(n--)
//     {
//         cin >> a >> b;
//         gra[a].insert(b);//双向地
//         gra[b].insert(a);
//     }
//     cin >> n;
//     while(n--)
//     {
//         int ans = 0;
//         cin >> x;
//         if(gra.count(x)) ans = gra[x].size();
//         cout << ans << '\n';
//     }
//     return 0;
// }




//B
//未完成
//线性dp！
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 150;
// int n, len, lent;
// string s0, s, nm;
// #define mk(str, i) make_pair(str, i)
// map<string, int> mp{mk("AA", 5),mk("AC", -1),mk("AG", -2),mk("AT", -1),mk("A-", -3),mk("CC", 5),mk("CG", -3),mk("CT", -2),mk("C-", -4),mk("GG", 5),mk("GT", -2),mk("G-", -2),mk("TT", 5),mk("T-", -1)};
// struct nd{
//     string name, dna;
//     int res;
// }q[N];
// int cal(string s, int len)
// {
//     for(int i = 0; i < len; i++)
//     {
//         for(int j = 0 ; j < len; j++)
//         {

//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n;
//     cin >> len >> s0;
//     for(int i = 0; i < n ; i++)
//     {
//         cin >> nm >> lent >> s;
//         q[i] = nd{nm, s, cal(s, lent)};
//     }

//     return 0;
// }




//C
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int t, sc;
// }arr[200];
// int dp[10005];
// int main()
// {
//     int t, m;
//     untie();
//     cin >> t >> m;
//     for(int i = 1; i <= m; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         arr[i] = nd{a - c, b};
//     }
//     for(int i = 1; i <= m; i++)
//         for(int j = t; j >= arr[i].t; j--)
//             dp[j] = max(dp[j], dp[j - arr[i].t] + arr[i].sc);
//     cout << dp[t];
//     return 0;
// }



//D
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e6 + 10;
// int n, m, cnt = 0;
// bool st[N];
// set<int> sum;
// int main()
// {
//     untie();
//     cin >> n >> m;
//     while(m--)
//     {
//         int x, y;
//         cin >> x >> y;
//         if(!st[x] && !st[y])
//             cnt++;
//         if(!st[x] || !st[y])
//             sum.insert(x), sum.insert(y);
//         st[x] = st[y] = 1;    
//     }
//     cout << (cnt + (n - sum.size())) << '\n';
//     return 0;
// }  
//并查集写法：
// #include <iostream>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e6 + 5;
// bool vis[N];
// int ds[N], n, m, res = 0;
// void init() { for(int i = 1; i <= n; i++) ds[i] = i, vis[i] = 0;}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// int main()
// {
//     untie();
//     cin >> n >> m;
//     init();
//     while(m--)
//     {
//         int x, y, fx, fy;
//         cin >> x >> y;
//         fx = find_set(x), fy = find_set(y);
//         if(vis[fx] && vis[fy]) continue;
//         if(fx == x) ds[x] = fy, vis[fy] = 1;
//         else if(fy = y) ds[y] = fx, vis[fx] = 1;
//     }
//     for(int i = 1; i <= n; i++)
//         res += find_set(i) == i;
//     cout << res << '\n';
//     return 0;
// }





//E
//简单bfs
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1024;
// int n, m, k, stx, sty, etx, ety, res = -1;
// bool mp[N][N];
// int b[N][N], dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// struct nd{
//     int x, y, times;
//     nd(int a, int b, int c) {x = a, y = b, times = c;}
// };
// void bfs()
// {
//     queue<nd> q;
//     q.push(nd(stx, sty, 0));
//     mp[stx][sty] = 1;
//     while(q.size())
//     {
//         nd tp = q.front(); q.pop();
//         int x = tp.x, y = tp.y, time = tp.times;
//         if(x == etx && y == ety) 
//         {
//             res = time;
//             return;
//         }
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + dir[i][0];
//             int ny = y + dir[i][1];
//             if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !mp[nx][ny] && time < b[nx][ny])
//             {
//                 q.push(nd(nx, ny, time + 1));
//                 mp[nx][ny] = 1;
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m >> k;
//     memset(b, 0x3F, sizeof b);//memset是一个字节一个字节地填充，对于4个字节的每个元素会变成0x3F3F3F3F = 1061109567;
//     while(k--)
//     {
//         int tm, x, y;
//         cin >> tm >> x >> y;
//         b[x][y] = min(b[x][y], tm);
//     }
//     cin >> stx >> sty >> etx >> ety;
//     bfs();    
//     cout << res;
//     return 0;
// }




//F
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 5;
// struct nd{
//     int id, h;  
// }ds[N];
// int n, m;
// int find_set(int x)
// {
//     return x == ds[x].id ? x : (ds[x].id = find_set(ds[x].id));
// }
// void merge_set(int x, int y, int hr)
// {
//     if((x = find_set(x)) != (y = find_set(y)))
//         ds[x].id = ds[y].id, ds[x].h = ds[y].h = max(ds[x].h, ds[y].h);
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n ; i++) ds[i] = nd{i, 0};
//     for(int i = 0; i < m; i++)
//     {
//         int x, y, hr;
//         cin >> x >> y >> hr;
//         merge_set(x, y, hr);
//     }
    
//     return 0;
// }







///G
//ceil(n / i) == floor((n - 1) / i) + 1;
//那么 sum(ceil(n / i)) == sum(floor((n - 1) / i) + 1) == sum(floor((n - 1) / i)) + n
//与求 sum(floor(n / i)) 同理来求 sum(floor((n - 1) / i))
// #include <iostream>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// long long n;
// int main()
// {
//     untie();
//     while(!(cin >> n).eof())
//     {
//         int L, R;
//         long long ans = n--;
//         for(L = 1; L <= n; L = R + 1)
//         {
//             R = n / (n / L);
//             ans += 1LL * (R - L + 1) * (n / L);
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }








//H
//多层差分
// #include <iostream>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 10;
// typedef pair<int, int> p;//<颜色c, 数量k>
// vector<p> b[N];
// int n, m, q[N];
// long long sum[N];
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1, x; i <= n; i++) 
//         cin >> x, q[i] = x;
//     while(m--)
//     {
//         int l, r, k, c;
//         cin >> l >> r >> k >> c;
//         b[l].push_back(p(c, k));
//         b[r + 1].push_back(p(c, ~k + 1));
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         for(auto x : b[i])
//             sum[x.first] += x.second;
//         cout << sum[q[i]] << ' ';
//     }
//     return 0;
// }







//I
//线段树
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 1e5 + 2;
// int n, m;
// ll p;
// ll a[N], b[N], s[N];
// ll qp(ll a, ll n)
// {
//     ll ans = 1;
//     a %= p;
//     while(n)
//     {
//         if(n & 1) ans = (ans * a) % p;
//         a = (a * a) % p;
//         n >>= 1;
//     }
//     return ans;
// }
// int main()
// {
//     untie();    
//     cin >> n >> m >> p;
//     for(int i = 1; i < n; i ++)
//     {
//         cin >> a[i];
//         b[i] = a[i] - a[i - 1];
//     }
//     int op;
//     while(m--)
//     {
//         cin >> op;
//         if(op == 1)
//         {
//             ll l, r, x, k;
//             cin >> l >> r >> x >> k;
//             ll cal = qp(x, k);
//             b[l] += cal;
//             b[r + 1] -= cal;
//         }
//         else if(op == 2) 
//         {
//             ll x, k;
//             cin >> x >> k;
//             b[x] += k;
//             b[x + 1] -= k;
//         }
//         else if(op == 3)
//         {
//             int l, r;
//             ll sum = 0, res = 0;
//             cin >>l >> r;
//             res = a[1];
//             for(int i = 1; i <= r; i++)
//             {
//                 sum += b[i];
//                 if(i >= l)
//                 {
//                     res = max(res, a[i] + sum);

//                 }
//             }
//         }
//         else if(op == 4)
//         {

//         }
//     }
//     return 0;
// }




//J
//Dijistra模板
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 1e5 + 2;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// int n, m, s;
// struct edge{
//     int from, to;
//     ll w;
// };
// struct nd{
//     int id;
//     ll ndis;
//     bool operator < (const nd &a)const{
//         return ndis > a.ndis;
//     }
// };
// vector<edge> e[N];
// ll dis[N];
// bool done[N];
// void dij()
// {
//     priority_queue<nd> que;
//     for(int i = 1; i <= n; i++) dis[i] = INF;
//     dis[s] = 0;
//     que.push(nd{s, dis[s]});
//     while(que.size())
//     {
//         nd u = que.top();
//         que.pop();
//         if(done[u.id]) continue;
//         done[u.id] = 1;
//         for(int i = 0; i < e[u.id].size(); i++)
//         {
//             edge y = e[u.id][i];
//             if(done[y.to]) continue;
//             if(dis[y.to] > y.w + u.ndis)
//             {
//                 dis[y.to] = y.w + u.ndis;
//                 que.push(nd{y.to, dis[y.to]});
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m >> s;
//     while(m--)
//     {
//         int u, v;
//         ll w;
//         cin >> u >> v >> w;
//         e[u].push_back(edge{u, v, w});
//         e[v].push_back(edge{v, u, w});
//     }
//     dij();
//     for(int i = 1; i <= n; i++)
//         printf(" %lld" + !(i - 1), dis[i]);
//     return 0;
// }



//K
// #include <cstdio>
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     double sum = 0;
//     for(int i = 1; i <= n; i++)
//         sum += 1.0 * n / i;
//     printf("%.6lf\n", sum);
//     return 0;
// }



//L
// #include <iostream>
// #include <set>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int flr[100005];
// set<int> vis;
// int main()
// {
//     untie();
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> flr[i];
//     int l = 1, r = 1, ans = 0;
//     while(r <= n)
//     {
//         if(!vis.count(flr[r])) vis.insert(flr[r++]);
//         else vis.erase(flr[l++]);
//         ans = max(ans, r - l);
//     }
//     cout << ans;
//     return 0;
// }






















/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑阶段赛1↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓第十七届中国计量大学程序设计竞赛↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/


//F
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

// string str = "The party began, the greasy uncle was playing cards, the fat otaku was eating, and the little beauty was drawing.At the party, people will play a game called Flag Scramble. The rule of this game is that the host speaks a sentence, and people find the letter that appears the most in the sentence. The first person who calls this letter wins. If your answer is wrong or someone else wins, you will be fined. You don't need to deal with many situations, just find the letter that appears most frequently in the statement of this problem and print it out, the letters are case insensitive.Very simple, right? Please remember to count carefully! Do not count wrong! This is the most straightforward question after all, but do not get a time penalty here, it is not worth it! In order for everyone to have a good experience, I really tried my best, and finally thought of such a question as a sign-in question, do not thank me too much, manual dog head.";
// map<char, int> mp;
// int main()
// {
//     untie();
//     cout << 'e';
//     return 0;
// }




//I
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int T;
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         int x;
//         cin >> x;
//         if(x >= 3) cout << "Yes\n";
//         else cout << "No\n";
//     }
//     return 0;
// }


//B
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int T;
// string a, b;
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         cin >> a >> b;
//         int cnta = 0, cntb = 0;
//         vector<int> v1, v2{0};//无0 和 有0
//         for(int i = 0; i < a.size(); i++)
//         {
//             if(cnta & 1)//反转
//             {
//                 if(a[i] == '1') a[i] = '0';
//                 else a[i] = '1';
//             }
//             if(a[i] == b[i]) continue;
//             v1.push_back(i + 1);
//             cnta++;
//         }
//         //固定 a = "00000···"
//         for(int i = 0; i < b.size(); i++)
//         {
//             if(cntb & 1)
//             {
//                 if(b[i] == '1') b[i] = '0';
//                 else b[i] = '1';
//             }
//             if(b[i] == '0') continue;
//             v2.push_back(i + 1);
//             cntb++;
//         }
//         if(v2.size() <= v1.size())//v2优先
//         {
//             for(int i = 0; i < v2.size(); i++) 
//                 cout << (" " + !i) << v2[i];
//         }
//         else
//         {
//             for(int i = 0; i < v1.size(); i++) 
//                 cout << (" " + !i) << v1[i];
//         }
//         cout << '\n';
//     }
//     return 0;
// }
//10001
//cnta = 1


//C
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// int T, n;
// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d", &n);
//         ll now = 0, res = n;//至少需要n分
//         while(n--)
//         {
//             ll l, r;
//             scanf("%lld%lld", &l, &r);
//             if(now >= l && now <= r) continue;
//             if(now < l) res += l - now, now = l;
//             else res += now - r, now = r;
//         }
//         printf("%lld\n", res);
//     }
//     return 0;
// }





//E
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int T, arr[100005];
// int main()
// {
//     untie();
//     cin >> T;
//     while(T--)
//     {
//         int n; cin >> n;
//         for(int i = 1; i <= n; i++) cin >> arr[i];
//         //最后一个结点上
//     }
//     return 0;
// }



//K
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// string s;
// int dy[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
// bool check(int pos)// ' ' - '0' < 0
// {
//     int l = pos, r = pos + 7;
//     int year = 0;
//     //前4位年份存储 + 判断回文
//     while(l <= r)
//     {
//         year = year * 10 + (s[l] - '0');
//         if(s[l] != s[r]) return 0;
//         l++, r--;
//     }
//     int month = (s[pos + 4] - '0') * 10 + (s[pos + 5] - '0');
//     int day = (s[pos + 6] - '0') * 10 + (s[pos + 7] - '0');
//     if(year < 1 || year > 9999) return 0;
//     if(month < 1 || month > 12) return 0;
//     if(day < 1 || day > 31) return 0;
//     //特判二月
//     if(month == 2)
//     {
//         if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return day <= 29;
//         else return day <= 28;
//     }

//     return day >= 1 && day <= dy[month];
// }
// int main()
// {
//     untie();
//     while(getline(cin, s))
//     {
//         if(s == "#") break;
//         int ans = 0;
        
//         s = "*" + s;
//         for(int i = 1; i + 7 <= s.size() - 1; i++)
//         {
//             if(check(i)) ans++;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }

//20222202
//12345678




//H
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 1e5 + 5;
// int T, n, m;
// int nb[N];

// int tree[N*4];
// bool vis[N*4];

// int ls(int p) { return p << 1;}//左子
// int rs(int p) { return p << 1 | 1;}//右子

// void pushup(int p)//最大值传递
// {
//     int pl = ls(p), pr = rs(p);
//     tree[p] = max(tree[pl] * vis[pl], tree[pr] * vis[pr]);//不存在记为 0
// }

// void build(int p, int pl, int pr)
// {
//     vis[p] = 1;
//     if(pl == pr)
//     {
//         tree[p] = nb[pl];
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     pushup(p);
// }

// void update(int L, int R, int p, int pl, int pr)//去除区间内元素（状态置为不存在即可）
// {
//     if(L <= pl && pr <= R)
//     {
//         vis[p] = 0;
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     //节点存在就深入访问
//     int nls = ls(p), nrs = rs(p);
//     if(L <= mid && vis[nls]) update(L, R, nls, pl, mid);
//     if(R > mid && vis[nrs]) update(L, R, nrs, mid + 1, pr); 
//     pushup(p);   
// }

// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d%d", &n, &m);
//         for(int i = 1; i <= n; i++)
//             scanf("%d", &nb[i]);
//         build(1, 1, n);
//         while(m--)
//         {
//             int l, r;
//             scanf("%d%d", &l, &r);
//             update(l, r, 1, 1, n);
//             //返回剩余全体区间最大值
//             printf("%d\n", tree[1] * vis[1]);
//         }
//     }
//     return 0;
// }





//D
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 5;
// int n;
// map<int, int> mp;
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int ans = -1;
//         cin >> n;
//         for(int i = 0; i < n; i++)
//         {
//             int x; 
//             cin >> x;
//             mp[x]++;
//         }
//         for(auto x : mp)
//         {
            
//         }
//         mp.clear();
//     }
//     return 0;
// }

//1 1 2 2
//
//2 2 2 6 6
//3 2
//2 2 6 6 6
//2 2 2 6 6 6

//2 2 2 2 6 6 6
//1 1 2 2 3 3

//1 1 1 2 2 3 3 3

//以偶数次到达最后一个盘子，





/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑第十七届中国计量大学程序设计竞赛↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓2021年GDCPC广东省大学生程序设计竞赛（正式赛）↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/


//题目：https://ac.nowcoder.com/acm/contest/50921?&headNav=www#question
//题解推荐：https://blog.csdn.net/qq_57404161/article/details/125115217?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-125115217-blog-124462818.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-125115217-blog-124462818.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=7


//A
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// int n, m, k;
// //1*1 1*2 .. 1*m
// //2*1 ...... 2*m
// //..
// //n*1
// //n个数列,由大到小排列,存各数列最大值，弹出 k-1 次最大值，每次弹出都放入该数列前一个值
// typedef pair<ll,int> p;
// priority_queue<p> q;
// int main()
// {
//     untie();
//     cin >> n >> m >> k;
//     for(int i = 1; i <= n; i++) q.push(p(1LL * i * m, i));
//     while(--k)
//     {
//         p tp = q.top(); q.pop();
//         tp.first -= 1LL * tp.second;
//         q.push(tp);
//     }
//     cout << q.top().first;
//     return 0;
// }


//G (思维题，较难)
//博弈论
//Alice 可以选择一个奇数并将其分成两个正数，或者删除一个等于1的数。
//Bob 可以选择一个偶数并将其分成两个正数。
//两人都是尽量使得自己剩余更多步骤
//Bob 分解偶数，最终分解的最小偶数是 2
//    若分解的是 2，变成两个 1，即Alice获利，Alice能多走两步
//    若分解非 2 的偶数，如 6，若分为 1 5 或 3 3，相当于送对面步数，只能偶分成偶，即 2 4，Bob多两步
//Alice 分解奇数，最小奇数为 1
//    若删除 1，即拖一回合
//    若分解非 1 的奇数，如 5，分为 1 4 或 2 3 都是一寄一偶，即双方各多一步
//对于Alice，期望产生更多的 2，这样自己步数会更多
//对于Bob，期望尽量不分解 2
//1 是最终必然产生的数，游戏过程变成：bob 尽量不分解 2，alice 拖足够多的回合直到 Bob 没有偶数可分。
//故Bob分解 x 时希望留下两个偶数即 x-2 和 2，Alice分解 x 时希望尽快堆叠 2 的数量使得能继续用 1 去拖，
//两人的最优决策都是把 x 拆成 x - 2 和 2
//那么统计序列中大于 2 的偶数能被分解的次数，这是 bob 的操作次数；统计序列中的奇数能被分解的次数，这是 alice 的操作次数。作比较即可

//未完成
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         int n;
//         ll bob = 0, alice = 0;
//         cin >> n;
//         for(int i = 1; i <= n; i++)
//         {
//             ll x;
//             cin >> x;
//             if(x & 1) alice += x / 2 + 1;
//         }
//     }
//     return 0;
// }




//J
//bfs
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// //[0, x]
// //314^2 < 1e5 , 315^2 > 1e5
// const int MAX_RICE = 314, N = 1e5 + 1;
// int square[MAX_RICE + 5], cost[N];
// bool vis[N];//记录走过的不能再走，先到的就是最少步数
// //两个决策，往回走，往前走
// void bfs()
// {
//     vis[0] = 1;
//     queue<int> q;
//     q.push(0);
//     while(!q.empty())
//     {
//         int t = q.front(); q.pop();
//         for(int i = 0; i <= MAX_RICE; i++)
//         {
//             int next = t + square[i];
//             if(next < N && !vis[next]) vis[next] = 1, cost[next] = cost[t] + 1, q.push(next);
//             next = t - square[i];
//             if(next >= 0 && !vis[next]) vis[next] = 1, cost[next] = cost[t] + 1, q.push(next);
//         }
//     }
// }
// int main()
// {
//     untie();
//     for(int i = 1; i <= MAX_RICE + 1; i++) square[i] = i * i;
//     bfs();
//     int q;
//     cin >> q;
//     while(q--)
//     {
//         int d;
//         cin >> d;
//         cout << cost[d] << '\n';
//     }
//     return 0;
// }

//dp
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// //[0, x]
// //314^2 < 1e5 , 315^2 > 1e5
// const int MAX_RICE = 314, N = 1e6 + 1, MAXDIS = 1e5;
// int dp[N];
// int square[N];
// int cnt = 0;
// int main()
// {
//     untie();
    
//     memset(dp, 0x3f, sizeof dp);
//     for(int i = 1; i * i <= MAXDIS; i++)
//     {
//         square[cnt++] = i * i;
//         dp[i * i] = 1;
//     }
//     dp[0] = 0;
//     for(int i = 0; i < cnt; i++)//完全背包，两种决策，正向和逆向走
//     {
//         int dx = square[i];
//         for(int j = dx; j <= MAXDIS; j++)          dp[j] = min(dp[j], dp[j - dx] + 1);
//         for(int j = MAXDIS; j >= 0; j--) dp[j] = min(dp[j], dp[j + dx] + 1);
//     }

//     int q;
//     cin >> q;
//     while(q--)
//     {
//         int d;
//         cin >> d;
//         cout << dp[d] << '\n';
//     }
//     return 0;
// }



//K
//二维线段树
//学不出来
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// typedef long long ll;
// const int N = 3e3 + 5;
// int n, m, last = 0;
// int nb[N];
// ll tree[N << 2];
// ll tag[N << 2];

// int ls(int p) { return p << 1;}//左子
// int rs(int p) { return p << 1 | 1;}//右子

// void pushup(int p)
// {
//     int pl = ls(p), pr = rs(p);
// }

// void build(int p, int pl, int pr)
// {
//     tag[p] = 0;
//     if(pl == pr)
//     {
//         tree[p] = nb[pl];
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     build(ls(p), pl, mid);
//     build(rs(p), mid + 1, pr);
//     pushup(p);
// }

// void addtag(int p, int pl, int pr, ll d)
// {
//     tag[p] += d;
//     tree[p] += d * (pr - pl + 1);
// }

// void pushdown(int p, int pl, int pr)
// {
//     if(tag[p])
//     {
//         int mid = (pl + pr) >> 1;
//         addtag(ls(p), pl, mid, tag[p]);
//         addtag(rs(p), mid + 1, pr, tag[p]);
//         tag[p] = 0;
//     }
// }

// void update(int L, int R, int p, int pl, int pr, ll d)
// {
//     if(L <= pl && pr <= R)
//     {
//         addtag(p, pl, pr, d);
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     if(L <= mid) update(L, R, ls(p), pl, mid, d);
//     if(R > mid) update(L, R, rs(p), mid + 1, pr, d); 
//     pushup(p);   
// }

// ll query(int L, int R, int p, int pl, int pr)
// {
//     if(L <= pl && pr <= R) return tree[p];
//     pushdown(p, pl, pr);
//     ll res = 0;
//     int mid = (pl + pr) >> 1;
//     if(L <= mid) res += query(L, R, ls(p), pl, mid);
//     if(R > mid) res += query(L, R, rs(p), mid + 1, pr);
//     return res;
// }

// int main()
// {
//     build(1, 1, N);
//     scanf("%d%d", &n, &m);
//     while(n--)
//     {
//         int l, r;
//         ll val;
//         scanf("%d%d%lld", &l, &r, &val);
//         update(l, r, 1, 1, N, val);
//     }
//     while(m--)
//     {
//         int op, l, r;
//         ll val;
//         scanf("%d", &op);
//         if(op == 1)
//         {
//             scanf("%d%d%lld", &l, &r, &val);
//             l ^= last, r ^= last, val ^= last;
//             update(l, r, 1, 1, N, val);
//         }
//         else
//         {
//             scanf("%d%d", &l, &r);
//             l ^= last, r ^= last;

//         }
        

//     }
//     return 0;
// }





//L
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <queue>
// #include <cctype>
// #include <cmath>

// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}

// int main()
// {
//     //p = 0.5
//     //x为轮数，统计输场，求E(x)
//     //x = 4
//     //  1 2 3
//     //1 1 0 0
//     //2 1 1 0
//     //3 1 1 1
//     //4 1 决胜
//     //
//     //x = 3
//     //  1 2 3
//     //1 1 0 0
//     //2 1 1 0
//     //3 2 1 0
//     //
//     //E(x) = sum(x * p) = 4 * 0.5 + 3 * 0.5;
//     float ex = 3.5;
//     printf("%.1f\n", ex); 
//     return 0;
// }







/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑2021年GDCPC广东省大学生程序设计竞赛（正式赛）↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






























/*
//模板
//并查集：
#include <cstdio>
#include <iostream>
using namespace std;
const int N = ;
int ds[N];
void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}



//二维前缀和
//存储公式：sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// 读取公式：res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
#include <iostream>
using namespace std;
const int N = ;
int arr[N][N];
int sum[N][N];
int main()
{       
    int x1,x2,y1,y2;//待求的范围
    //初始化数列
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            arr[i][j]=i+j;
    //前缀和操作(实际上可以边读取arr数列数，边进行求和操作)
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            sum[i][j] +=  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];//sum[0][0]=0
    while(cin>>x1>>y1>>x2>>y2)
    {
        int res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]; 
        //sum[2][2] = sum[1][2] + sum[2][1] - sum[1][1] + arr[2][2] 
        cout<< res <<endl;
    }
    return 0;
}



//二维差分
#include<iostream>
#include<cstdio>
using namespace std;
const int N = ;
int a[N][N], b[N][N];
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            insert(i, j, i, j, a[i][j]);      //构建差分数组
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);          //差分操作
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //转为二维前缀和
    return 0;
}



//快速幂
//base 底数；index 指数
//线性整数快速幂：
typedef long long ntype;
ntype mod = ;
ntype quick_pow(ll base, ntype index)
{
    ntype ans = 1;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base % mod;
        base = base * base % mod;
    }
    return ans;
}
//矩阵快速幂：
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//这里 N 指最大矩形边长，n 指实际矩形边长
ntype n, k;
struct matrix{
    ntype mat[N][N];
    matrix operator *(matrix &t){
        matrix ret;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                ntype sum = 0;
                for(int k = 0; k < n; k++) 
                    sum += mat[i][k] * t.mat[k][j] % mod;
                ret.mat[i][j] = sum % mod;
            }
        return ret;
    }
}orimat;
matrix mat_quick_pow(matrix base, ntype index)
{
    matrix ans = orimat;
    for(; index; index >>= 1)
    {
        if(index & 1) ans = ans * base;
        base = base * base;
    }
    return ans;
}
void init(){ for(int i = 0; i < N; i++) orimat.mat[i][i] = 1;}



*/





