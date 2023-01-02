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
//问题转换为两个子问题
// ·哪一列不包含 Rook？
// ·哪一行不包含 Rook？
//分别查找二分答案即可，最后将共同指向一个坐标
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
//3 + 2 + 1 =6
//3 2 1
//2









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
//















































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
//     while(l * l <= n)
//     {
//         while(l <= r && sum < n) ++r, sum += r * r;
//         if(sum == n) v.push_back(pii(r, r - l));
//         l++;
//         sum -= l * l;
//         if(l == r) break;
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
//https://blog.csdn.net/weixin_44915226/article/details/119535259?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167176851016800222868521%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167176851016800222868521&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-5-119535259-null-null.142^v68^control,201^v4^add_ask,213^v2^t3_control1&utm_term=c%2B%2B%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F&spm=1018.2226.3001.4187
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
//                  cout << ' ';
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
#include <queue>


using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
const int N = 1e5 + 10;


int n, mp[N];
bool vis[N];
int ans = 0;

void dfs(int i)
{
    
}
int main()
{
    untie();
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        ans = 0;
        for(int i = 1; i <= n; i++) cin >> mp[i], vis[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                
                
            }
        }
        cout << ans << '\n';
    }



    return 0;
}
































/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑寒期集训赛5↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
