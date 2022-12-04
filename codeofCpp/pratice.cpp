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

//一级差分
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

//二级差分
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

/*
 1001
90999
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int res[800];
int main()
{
    string a,b;
    cin>>a>>b;
    if(a.size()<b.size()) swap(a,b);
    int len1=a.size(), len2=b.size();
    for(int i=0;i<len1;i++) a[i]=a[i]-'0';
    for(int i=0;i<len2;i++) b[i]=b[i]-'0';
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<len2;i++)
    {
        res[i]=a[i]+b[i];
        res[i+1]+=a[i]/10;
        res[i]%=10;
    }
    // for(int i=0;i<=len1;i++)
    // {
    //     if(i<)
    // }
    // cout<<a;
    return 0;
}


























































/*数学原理应用*/

//曼哈顿距离(又名出租车距离)
//d(i,j)=|x1-x2|+|y1-y2|
//打印一个菱形
/*
当n=5时，有" * “号的地方是距离中心点曼哈顿距离小于2的地方；
当n=7时，有” * " 号的地方是距离中心点曼哈顿距离小于3的地方。
找到中心点与n的关系：中心点用n表示为（n/2，n/2），将与中心点距离小于n/2的点用" * "表示，其他地方用空格表示，
完成一行（一行指i的一次循环）后进行换行。
*/
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;//n为奇数
//     int cx = n/2, cy = n/2;//中心点(cx,cy)
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             if(abs(i-cx) + abs(j-cy) <= n/2)
//                  cout << '*' ;
//             else
//                cout << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }

























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










