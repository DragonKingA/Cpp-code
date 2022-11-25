/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*�������������������������������������������������������������������������������������������������������������������������������������������㷨��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/

/*һ.STL*/
/*
������ѡ��:
1. �������Ҫ��Ч���漴��ȡ�������ں������ɾ����Ч�ʣ�ʹ��vector
2. �������Ҫ�����Ĳ����ɾ�������������漴��ȡ����Ӧʹ��list
3. �������Ҫ�漴��ȡ�����ҹ����������ݵĲ����ɾ������Ӧʹ��deque��
*/


//set
//������
//�����޷�����ȫ�ǿո����
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
//                 if(st.size() == 0) continue;//���������ո��ǰ���ո�
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
//1.�򵥲���ջ,����ȳ�
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

//2.���˽ڵ�����
//�������ȳ�����ջ������
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
/*stack����
                    { 1 }
            { }             {1��2}
        {2}               {1}       {1��2��3}
    {2��3} { }          { }  {1,3}       {1��2}
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
//     int index;//��¼���ջ����str���ĸ��ַ�, 0 ~ (n-1)
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
//         node t{0, "", {1}}; //����vec��ʼ����һ��Ԫ��
//         t.sta.push(str[0]);
//         vector<node> vec[2*n]{{t}};//�洢ջ״̬����һ��ջֱ����������ʼ���д洢
//         /*
//             t.index=0;
//             t.ans="";
//             t.InOut.push_back(1);
//             vec[0].push_back(t);
//         */
//         for(int i = 0 ; i < 2*n ; i++)//ȫ����
//         {
//             for(auto j : vec[i])
//             {
//                 node temp1 = j, temp2 = j;
//                 if(j.index < n-1)
//                 {
//                     //��ջ��������ջ״̬
//                     temp1.sta.push(str[j.index + 1]);
//                     temp1.InOut.push_back(1);
//                     temp1.index++;
//                     vec[i+1].push_back(temp1);
//                 }
//                 if(!j.sta.empty())
//                 {
//                     //��ջ��������ջ״̬
//                     temp2.ans += temp2.sta.top();
//                     temp2.InOut.push_back(0);
//                     temp2.sta.pop();
//                     vec[i+1].push_back(temp2);
//                 }
//                 //�������Ƿ��д𰸳���
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
// #include <map>
// using namespace std;
// struct node{
//     int index;
//     string ans;
//     vector<bool> InOut;
//     stack<char> sta;
// };
// multimap<string, node> mmp;
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
//             while (!stk.empty() && stk.top() == b[j])//�˴��ص�
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

//4.�������ʽ(������������Ϊ��)
/*
����׺���ʽ (3 + 4) * 5 - 6 Ϊ��
�������ʽ��Ϊ��
1.ǰ׺�������ʽ:������λ�ڲ�����֮ǰ���� - * + 3 4 5 6
  ʹ��ջԭ��(��ʵ�ݹ鷨��������˳��������ɽ��������ֱ����ջ���Ѵ���)���������󣬶���ֵ��ѹջ��Ȼ�����ζ�ȡ�������ջ������Ԫ�ص����������ٰѽ����ջ
2.��׺�������ʽ���������ı��ʽ��
3.��׺(��)�������ʽ:������λ�ڲ�����֮���� 3 4 + 5 * 6 -
*/
//ǰ׺�������ʽ(����õݹ�ʵ��)
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
//��׺(��)�������ʽ(�����ջʵ��)
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
//             for( ; isdigit(s[i]) ; temp += s[i++]);//�������־ͽ�ȡ����
//             if(!temp.empty())   sta.push(stoi(temp));
//             char x = s[i];//��ʱһ��Ϊ�ո�
//             if(ispunct(x))
//             {
//                 int n1 = sta.top(); sta.pop();
//                 int n2 = sta.top(); sta.pop();
//                 switch(x)
//                 {
//                     case '+': sta.push(n2 + n1); break;
//                     case '-': sta.push(n2 - n1); break;
//                     case '*': sta.push(n2 * n1); break;
//                     case '/': sta.push(n2 / n1); break;//Ĭ��n1 != 0
//                 }
//             }
//         }
//         cout << s << " at the result of " << sta.top() << endl;
//     }
//     return 0;
// }
/*
תΪ��׺���ʽ(������Ҫ�ڶ���ջ������ʽ)������������ã�
    string exp = "";//������ʽ
    exp += "(" + to_string(n2) + x + to_string(n1) + ")";
    exp += "(" + to_string(n2) + x + to_string(n1) + ")";
    exp += to_string(n2) + x + to_string(n1);
    exp += to_string(n2) + x + to_string(n1);
*/




                






//queue
//1.�򵥲�������,�Ƚ��ȳ�
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
//���ȶ�����������������������ȼ�
//��������ط�ʽ������������
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
//     int x, dx;//��λ��ǰ,dxС�ĳ���
//     //�ṹ�������������д����
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




//map
// 1.Let the Balloon Rise
// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;
// int main()
// {
//     int T;
//     while((cin >> T) && T)
//     {
//         map<string, int> mp;
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

//2.ˮ��(Ƕ��map)
//�ʣ�map��string��������������ĸ���л�������ASCII��ֵ
// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;
// int main()
// {
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         map<string, map<string, int> > mp;
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
1.��vector�Ĳ�ͬ
ͷ�ڵ��ǰ��Ԫ��ָ���򱣴����������βԪ�ص��׵�ַ��list��β�ڵ�ĺ��Ԫ��ָ�����򱣴���ͷ�ڵ���׵�ַ��������listʵ���Ͼ͹�����һ��˫��ѭ������
����listԪ�ؽڵ㲢��Ҫ����һ���������ڴ��У���Ȼ��list���ǲ�֧�ֿ��������ȡ�ģ�
��˶��ڵ�������ֻ��ͨ����++����--���������������ƶ������/ǰ���ڵ�Ԫ�ش��������ܶԵ���������+n��-n�Ĳ�������㣬����vector�Ȳ�ͬ�ĵط���
2.�ص�
list�������ݽṹ�е�˫������(����sgi stlԴ����)����������ڴ�ռ��ǲ������ģ�ͨ��ָ�����������ݵķ��ʣ�
����ص�ʹ�������漴��ȡ��ķǳ�û��Ч�ʣ������û���ṩ[]�����������ء�������������ص㣬�������Ժܺõ�Ч��֧������ط���ɾ���Ͳ��롣
*/






















/*��.��������*/

//ȫ�������⣨���л���Ԫ��С�ڵ���10��ʱ���к�ʱ��1���ڣ�
//1.STL��
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

//2.�ݹ鷨
// #include <iostream>
// using namespace std;
// #define Swap(a, b) {int temp = a; a = b; b = temp;}
// //�꺯��Swap��STL��swap��������Ч�ʸ���(������ͨ��̬������˵)
// int cnt = 0;
// int datas[10] = {1,2,3,4,5,6,7,8,9,10};
// int Perm(int begin, int end)
// {
    
//     if(begin == end) cnt++;
//     else
//     {
//         for(int i=begin;i<=end;i++)
//         {
//             Swap(datas[begin], datas[i]);//�ѹ̶���(beginλ���ϵ���)������������������һ��λ��
//             Perm(begin+1, end);//�л��̶�������
//             Swap(datas[begin], datas[i]);//�ָ���������һ�ν���
//         }
//     }    
// }
// int main()
// {
//     Perm(0, 9);//��ʾ������0��9��10��Ԫ��ȫ���У����Ըĳ���������
//     cout << "cnt = " << cnt << endl;// 10! = 3628800
//     return 0;
// }





//�Ӽ�����������
/*
�ö����������:���󼯺�{a1, a2, a3}���Ӽ�������֪��Ԫ�ظ���Ϊ n �ļ������Ӽ�����Ϊ 2^n �������ռ���
���ѷ��� n -> 2^n �Ĺ�ϵ�� ������λ -> ����������С ���,����3λ�����Ʊ�ʾ�ü��ϣ�ÿλ��Ϊ1��ȡ��Ԫ�أ�Ϊ0��ȡ��Ԫ��
�� a1 a2 a3 -> 1 1 1 ,  ��  a2 a3 -> 0 1 1 ;  a1 -> 1 0 0 �����д� 0 0 0(�ռ�) �� 1 1 1(ԭ����) ��8�����

*/
// #include <iostream>
// using namespace std;
// void print_subset(int n, const string *s, int k)
// {
//     for(int i = 0 ; i < (1<<n) ; i++)//2^n�����
//     {
//         //ͳ��1�ĸ���,ʹ����ֻ����� k ��Ԫ�ص��Ӽ�
//         int cnt = 0, kk = i;
//         while(kk)
//         {
//             kk = kk & (kk-1);//�þ�������ʹ��������kk�����һ��1���0,��ÿʹ��һ�� 1 �ĸ����ͼ���һ��
//             cnt++;
//         }
//         if(cnt == k)
//         {
//             for(int j = 0 , ifpunct = 0 ; j < n ; j++)//��i�ö���������⣬����i�Ķ���������ÿһλ���ö�����λ�ϵ�1��Ӧȡ����s[j]�ϵ�Ԫ��
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
//     print_subset(len, str, 2);//��ӡ����Ԫ�ظ���Ϊk�����Ӽ�
//     //�÷�����ӡ�����Ӽ��Ĵ����������ĿҪ���������
//     return 0;
// }






//BFS���������������
//һ���Ƕ���ʵ�֣��� BFS = ����, ���㷨����ʹ�ö��н�������ǵݹ飨�ʺ�����һ����while(����Ϊ���в�Ϊ��)ѭ����
//���Խ���������⣨�/���·����
// 1.�����(BFSʵ��)
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
//     while(!que.empty())//�����ǵݹ�
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

//2.������(���·������)
/*
����d[N][N]��ʼ��Ϊ - 1��Ȼ��d[x][y]��ӣ�����bfsѭ�������߹̶�λ�ã�
Ȼ����d[N][N]�������ܵ��ߡ���������̲���
��������С������
https://blog.csdn.net/qq_64162685/article/details/124002779?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166930838716800184173076%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166930838716800184173076&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-124002779-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_control1&utm_term=c%2B%2B%E9%A9%AC%E8%B5%B0%E6%97%A5BFS&spm=1018.2226.3001.4187
*/
// #include<bits/stdc++.h>
// using namespace std;
// typedef pair<int, int>PII;//�������
// queue<PII>q;
// const int N = 1010;
// int n, m, l;
// int d[N][N];
// int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
// int dy[8] = { 1,-1,2,-2,2,-2,1,-1 }; //8��λ��
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
//                 d[tx][ty] = d[x][y] + 1;//������1
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
//     memset(d, -1, sizeof(d));//��ʼ��Ϊ-1
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









//DFS���������������
//һ���ǵݹ�ʵ�֣���ʱ��ͬһ������������BFS��
//�������ڽ��ȫ·��������
//1.�����(DFSʵ��)
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

//2.������
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
// int dir[8][2] = {{-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}};//˳ʱ��
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
//             board[ny][nx] = 1;//���� ���� ��״̬
//             DFS(nx, ny, cnt+1);//������ĩ��
//             board[ny][nx] = 0;//�ָ�״̬(��������ĩ��ʱ����һ�������Ұ�ĩ��״̬�ָ�Ϊ δ�ߵ�)
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






























/*�������������������������������������������������������������������������������������������������������������������������������������������㷨��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//������













































/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//*��
/*
https://blog.csdn.net/qq_43762191/article/details/107280503?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166927609816800182199745%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166927609816800182199745&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-107280503-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_control1&utm_term=%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91&spm=1018.2226.3001.4187
*/





//��ϣ�㷨
/*
����������������и������ִ����������Ը���Ϊ�±꣬����Ԫ��Ϊ��������¼�����ܻ���������С�������������ʱ��������й�ϣӳ�䴦��֮��Ҫ�������ӳ��õ�ԭ��
https://blog.csdn.net/qq_38609781/article/details/84836583?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166927649216782425154549%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166927649216782425154549&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-84836583-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_control1&utm_term=%E5%93%88%E5%B8%8C%E6%98%A0%E5%B0%84&spm=1018.2226.3001.4187
*/