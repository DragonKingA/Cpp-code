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



//2.ˮ��(Ƕ��vis)
//�ʣ�vis��string��������������ĸ���л�������ASCII��ֵ
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


//������

//BFS���������������
//һ���Ƕ���ʵ�֣��� BFS = ����, ���㷨����ʹ�ö��н�������ǵݹ飨�ʺ�����һ����while(����Ϊ���в�Ϊ��)ѭ����
//���Խ���������⣨�/���·����

// 1.�����(BFSʵ��)
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
*/

//2.������(���·������)
/*Code
// ����d[N][N]��ʼ��Ϊ - 1��Ȼ��d[x][y]��ӣ�����bfsѭ�������߹̶�λ�ã�
// Ȼ����d[N][N]�������ܵ��ߡ���������̲���
// ��������С������
// https://blog.csdn.net/qq_64162685/article/details/124002779?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166930838716800184173076%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166930838716800184173076&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~baidu_landing_v2~default-1-124002779-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_controx1&utm_term=c%2B%2B%E9%A9%AC%E8%B5%B0%E6%97%A5BFS&spm=1018.2226.3001.4187
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
*/

//3.Find the multiple
//����ǰ�������ֻ����G++��,�ݹ�Ƶ������ʱ�����G++��
/*���з�
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
/*�����������ǰ��ȡȫ����������������������������ʱ�̣����ռ�����Ҳ����̫��
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
/**�������ݹ���ֹ�㣺��������ı��֪Ҫ�õ�������λ��Ϊ19λ����19�εݹ飬�ʿ��Ե��˵�20�ξ���ֹ�ݹ��߳�
//�ô���C++��G++�����ᳬʱ�������
// #include <iostream>
// using namespace std;
// bool fl;
// int n;
// void BFS(long long m, int x){
//     if(x>19 || fl);//flΪ�����ֹ�õݹ��߳�
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
// 			if(nx>=0&&nx<=100000&&!ocu[nx])//ע������˳�򣬽���Խ�����
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

//*5.Prime Path(���е���Ҫ�÷�)
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
// 		while(sz--)//*�������ص㣺ÿ��ѭ��������ԭ�ȶ����е�Ԫ��, ����֤��ǰ���Ԫ�ض�����һ���仯������
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
// 	return 0;//���������˶�û�о����Ҳ���
// }
// int main()
// {
// 	for(int n=1000;n<=9999;n++)//�������ӡ�������εݹ����ظ�����
// 	{
// 		prime[n]=1;
// 		for(int i=2;i<=sqrt(n);i++)//CE �� ����n/2
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

//*6.�Թ����⣨���ڶ�������һ����֧��Ϣ�Ĵ洢���������һ����֧�Ĺ��̣�
/*·���洢����(�ص�)����
ans[5][5]����ÿ�����Ӧ�Թ��ϵĵ㣬����ֵΪ�õ�ġ�ǰһ���㡱�������������������̬
������ĳ�Թ���
0, 1, 0, 0, 0,		[0,0] (1,0) (2,0) (3,0) (4,0)

0, 1, 0, 1, 0,		[0,1] (1,1) (2,1) (3,1) (4,1)

0, 0, 0, 0, 0,  --> [0,2] [1,2] [2,2] [3,2] [4,2]	��[x,y]��Ϊ���·���ϵĵ�

0, 1, 1, 1, 0,		(0,3) (1,3) (2,3) (3,3) [4,3]

0, 0, 0, 1, 0,		(0,4) (1,4) (2,4) (3,4) [4,4]
ans[5][5]�������·��ʾ��ͼ(ans[y][x]):
	0	   1	  2	     3	   4

0	*
	|
1 (0,0)
	|
2 (0,1)����(0,2)����(1,2)����(2,2)����(3,2)
								|
3							  (4,2)
								|
4							  (4,3)
�����ans[1][0] = (0,0) , ��Ϊ·���ϵ�(0,1)����һ������(0,0)
  ����ans[4][4] = (4,3) , ��Ϊ·�����յ�(4,4)����һ������(4,3)
�������ܽ�����һ��·�������֮��Ĺ�ϵ�����㽫·���ϵ����е��ӡ����
*/
/*AC
// #include <cstdio>
// #include <queue>
// using namespace std;
// int maze[5][5], dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
// struct node{
// 	int x,y;
// 	bool operator == (const node &n) const{//�еȺŵ����أ�ʹ�ṹ��֮����ֱ����==���е�
// 		return x==n.x && y==n.y;
// 	}
// }ans[5][5],BEGIN{0,0},END{4,4},te,ne;
// #define CHECK(x,y) (x>=0&&x<5&&y>=0&&y<5&&!maze[y][x])
// void Pri(node pt)//��Ϊ�������һ����(4,4)��ʼ��λ���·��������Ҫ�õݹ������ӡ
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
// 				ans[ny][nx]=te;//�ڸõ�λ�ô� ��һ�����������Ϣ
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

//7.Find a way(���̽�Ϊ���ӣ������ڸ������ڳ���)
/*��������:
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
//DFS����ʵ��
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
//AC:������iostreamҲ�ɣ����ᳬʱ(109ms)
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
/*�ݸ�
//�ݸ�1
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
//�ݸ�2
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
//�ݸ�3
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
/*����������
3 5 4
w1=0,w2=5;
w1=3,w2=2;
w1=0,w2=2;
w1=2,w2=0;
w1=2,w2=5;
w1=3,w2=4;(w2��������)
����һ��w==c����

7  5
w1=7,w2=1

�涨
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
/*��⣡������������
// #include <cstdio>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> P;
// P root[101][101];//����·��
// int vis[101][101],op[101][101],sign[101][101],a,b,c;
// void judge(int fl, int x){
//     if(fl==0) printf("FILL(%d)\n",x);
//     else if(fl==1) printf("DROP(%d)\n",x);
//     else printf("POUR(%d,%d)\n",x/10,x%10);    
// }
// void link(P p){
//     if(p == P()) return;//pΪP(0,0)ʱ����ֹ���
//     link(root[p.first][p.second]);
//     judge(op[p.first][p.second], sign[p.first][p.second]);
// }
// void BFS(){
//     queue<P> que;
//     que.push(P(0,0));//ֱ�Ӵ�����������Ϊ�տ�ʼ��ʡȥ����������鷳
//     vis[0][0]=1;
//     while(que.size()){
//         P s=que.front(); que.pop();
//         int x=s.first, y=s.second;
//         if(x==c || y==c){
//             printf("%d\n",vis[x][y]-1);
//             link(P(x,y));//·��
//             return;
//         }
//         int k=min(a-x,y), k1=min(b-y,x);
//         int st[6][2] = {{a,y},{x,b},{0,y},{x,0},{x+k,y-k},{x-k1,y+k1}};//6�ֿ��ܵĲ���
//         int oper[6] ={1,2,1,2,21,12};//����i
//         for(int i=0;i<6;i++){//0,1,2,3,4,5
//             int dx = st[i][0], dy = st[i][1];
//             if(!vis[dx][dy]){
//                 vis[dx][dy]=vis[x][y]+1;//�沽����ͬʱ�൱�ڴ���״̬
//                 root[dx][dy] = P(x,y); 
//                 sign[dx][dy] = oper[i];
//                 op[dx][dy] = i/2;//��6������ֳ�3����
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

//����������ʱ�����滻Judge()����
//�������ģ�� char oplist[3][22] = {"FILL(%d)\n", "DROP(%d)\n", "POUR(%d,%d)\n"};
//���ʱ����������д printf(oplist[�ڶ�ά���±�], ������1(Ӧ�õ���һ��%d) , ������2(Ӧ�õ��ڶ���%d) );

*/
/*��ͼ�ϲ���һ����Ԫ�ṹ������
// #include <cstdio>
// #include <iostream>
// #include <queue>
// using namespace std;
// typedef pair<int,int> P;
// struct node{
//     P now,last;
//     int op;//6�ֲ���
//     int type;//3�����
//     int cnt;//������״̬
//     bool operator ==(const node &n)const{
//         return (now==n.now&&last==n.last&&op==n.op&&type==n.type&&cnt==n.cnt);
//     }
// }root[101][101],BEGIN{P(0,0),P(0,0),0,0,0};//����·��
// int a,b,c;
// void judge(int fl, int x){
//     if(fl==0) printf("FILL(%d)\n",x);
//     else if(fl==1) printf("DROP(%d)\n",x);
//     else printf("POUR(%d,%d)\n",x/10,x%10);    
// }
// void link(node n){
//     if(n.now==P(0,0)&&n.last==P(0,0)&&n.op==0&&n.type==0&&n.cnt==0) return;;//pΪP(0,0)ʱ����ֹ���
//     link(root[n.last.first][n.last.second]);
//     judge(root[n.now.first][n.now.second].type, root[n.now.first][n.now.second].op);
// }
// void BFS(){
//     queue<node> que;
//     que.push(BEGIN);//ֱ�Ӵ�����������Ϊ�տ�ʼ��ʡȥ����������鷳
//     root[0][0]=BEGIN;
//     while(que.size()){
//         node s=que.front(); que.pop();
//         int x=s.last.first, y=s.last.second;
//         if(x==c || y==c){
//             printf("%d\n",root[x][y].cnt-1);
//             link(s);//·��
//             return;
//         }
//         int k=min(a-x,y), k1=min(b-y,x);
//         int st[6][2] = {{a,y},{x,b},{0,y},{x,0},{x+k,y-k},{x-k1,y+k1}};//6�ֿ��ܵĲ���
//         int oper[6] ={1,2,1,2,21,12};//����i
//         for(int i=0;i<6;i++){//0,1,2,3,4,5
//             int dx=st[i][0], dy=st[i][1];
//             if(!root[dx][dy].cnt){
//                 root[dx][dy].now=P(x,y);
//                 root[dx][dy].cnt=root[x][y].cnt+1;//�沽����ͬʱ�൱�ڴ���״̬
//                 root[dx][dy].last=P(dx,dy); 
//                 root[dx][dy].op = oper[i];
//                 root[dx][dy].type = i/2;//��6������ֳ�3����
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
/*���̵Ľṹ�巽��
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
    vis[0][0].op = -2; // �����⺬�壬ֻ�Ǳ�Ǹ�״̬�ѷ���
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

//3.*��������
// #include <iostream>
// #include <cstring>
// using namespace std;
// int n,k,cnt=0;
// bool d[10];//0�ޣ�1��
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
//     DFS(y+1, num);//*�ص�
//     /*
//         ��Ϊ����n>k�������������Ե�һ��Ϊ��ʼ����ʼ��������������������
//         3 1
//         # .
//         . #
//         # .
//         �İ���ʱ����һ���ж�����Ѿ���num==k�������������ͬ���ڶ��к͵�������Ȼ������Ϊ�µ���ʼ�������ж�Ҳ�����num==k�����������3��
//         �������Ƿ��½���ʼ�У������ж��Ƿ�y>=n���磬����ֹͣ���ɣ���ʱ�Ͳ�����ڵ������½��������ݹ�������
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


//��������
//������֦�����仯����
/*dfs�ļ�֦�ֶΣ�
�����Լ�֦����Ŀǰ״̬�����ⲻ��������������Ŀ�����Ƴ��������������������ⶼ��������ô�Ϳ��Խ��м�֦��
           ֱ�Ӱ������������������������ж�Ϊ�����У�ֱ�ӷ��ء�

�ų���Ч���ࣺ����������������ȫ��ͬ��Ч����ʱ��ֻѡ������һ��������

����˳���֦����ͬ������˳��ᵼ����������̬����ܴ���ôʱ�临�Ӷ���Ȼ����Ҳ�ܴ�
            ����˵��������һ����Сֵ���ǿ϶��Ǵ���С�Ľڵ㿪ʼ���������Ǵ����Ľڵ㿪ʼ������
            һ���������е����Դ��ڵ�����������Ժ�̰��˼���ϣ�����˳���֦��

�����Լ�֦����������û������ʱ�򣬵�ǰ��¼��״̬�Ѿ��ȵ�ǰ��������Ž���ӣ���û�б�Ҫ�ڼ���������ȥ�ˣ�
            ��Ϊ��·���Ѿ������ܳ�Ϊ���ǵ����Ž��ˡ�(���޶������������µ������پ����֦)
*/
//1.ѡ��
// #include <cstdio>
// int n, k, ans = 0, a[30];
// bool isprime(int x)
// {
//     for(int i = 2; i * i <= x; i++)
//         if(x % i == 0) return 0;
//     return x != 1;
// }
// //��ѭ����ԭ�������ѡ���������ظ�
// void dfs(int cnt, int sum, int st)//stΪ���һ��ѡ�����±�
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



//2.�ǳ�����
//4 1 3 -- 4 0 0
//s -> m -- 1 0 3
//m -> n -- 1 1 2
//n -> s -- 2 0 2
//���ƽ�ֺ󶼻������������������(���Ͽ���ƿһ����������)����������ȣ�������Ϊ 0
//��֪ s Ϊ���������֮һ����ô���� n Ϊ�ڶ����ӣ������ս��ƽ���� s, n ��
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



//3.����������
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
// map<string, bool> vis;//�� 9! ��״̬
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
//N <= 20 ������dfsö�ٲ���
//��������е�����A�飬�ټ��� ��������A�� �� ��ȥB�� �����
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
//     dfs(i + 1, sum);//����A��
//     //��ȥB�飬�����Cij
//     vis[i] = 1;
//     for(int j = 0; j < n; j++)
//     {
//         if(j != i)
//         {
//             if(vis[j]) sum -= mp[i][j];//���Ѿ��ƹ�ȥB��ĵ�j����ȥ��ʱ������Ȩֵmp[i][j]
//             else sum += mp[i][j];//i�ƹ�ȥ��j -> i ����Ȩֵ����Ȩ
//         }
//     }
//     dfs(i + 1, sum);//��ȥB�������ݹ�
//     vis[i] = 0;//����
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



//5.Tempter of the Bone(�����پ����Ż� + �򵥼�֦)
//Сͼ��dfs
//764ms�������ĸ��Ż�ȱһ������TLE
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
//     if(res) return;//�Ż�1
//     if(time == T)//�Ż�2
//     {
//         res |= mp[x][y] == 'D';
//         return;
//     }
//     if(mp[x][y] == 'D')//�Ż�3
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
//         //�����پ����Ż�
//         int mdis = abs(sx - ex) + abs(sy - ey);
//         if(T < mdis) cout << "NO\n";//�Ż�4
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
//�����Ż���6����-- 374ms
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
//     if(time + abs(x - ex) + abs(y - ey) > T)//����ǰ��̾���������ʱ�䳬��T����һ��������time==Tʱ�����·������
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
//         //�����پ����Ż�
//         int mdis = abs(sx - ex) + abs(sy - ey);
//         if(T < mdis || mdis % 2 != T % 2) cout << "NO\n";// �����پ������̲�����ż�Ա�Ȼ��ͬ
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



//***6.Сľ��
//n <= 65, dfs + ö��
//��С���ܳ��ȷ�Χ [max_len, sum]������ö�ٴ𰸼��ɣ����ȷ��������ĳ��ȼ���Сֵ
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int n, sum = 0, max_ = 0, min_ = 1e9;
// int num[100];//num[x] Ϊ ����Ϊx ��ľ���ĸ���
// //len:ÿ��ľ�����ȣ�now:����ƴ��һ����Ϊlen��ľ���Ľ��ȣ�cnt:Ҫƴ��cnt����Ϊlen��ľ���Ľ��ȣ�
// //last:���һ��ѡȡ��ľ������ -- ÿ�δ����ľ��ѡ�𣬲���������ѡȡ������ѡȡ�Ĵ���һ������
// bool dfs(int len, int now, int cnt, int last)
// {
//     if(cnt == 0) return 1;//ȫ��ƴ��
//     if(now == len) return dfs(len, 0, cnt - 1, max_);//ƴ��һ��������now��last �� ���������ƴ
//     for(int i = last; i >= min_; i--)//����ѡȡ
//     {
//         if(num[i] && now + i <= len)//�����жϷ�������������ֵ
//         {
//             --num[i];
//             if(dfs(len, now + i, cnt, i))//��չ����
//                 return 1;
//             ++num[i];//����
//             //����Ҫ�������Ż������ǻ��� ����ѡȡ�����������һ�� i �������ƴ�ӣ������Ľ����ʧ�ܵģ���ôǰ��ľ��������⣬������ѡ
//             //now == 0������������ƴľ���ĵ�һ�����ӣ����Һ���������ôƴ�����У���ô��ǰ��һ�����������ĵ�ȻҲ�Ͳ��С�
//             //          �������dfsû�з���1ʱ��˵�� ľ��i û�����ϣ���ʱ now ��Ϊ��ƴ����һ��ʱ��ʼ�� 0��
//             //now + i == len������������ƴľ�������һ�����ӣ���ʱ ľ��i ��Ȼ���ţ������Ŷ���ôƴҲ���У���ô���������İ�����ƴҲ���ɲ��С�
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
//     for(int len = max_; len <= sum; len++)//ö����С��
//     {
//         if(sum % len == 0 && dfs(len, 0, sum / len, max_))//�������� sum % len == 0�����ܹ�����
//         {
//             cout << len << '\n';
//             break;
//         }
//     }
//     return 0;
// } 



//7.����Ƕ�� (DAGͼ�ļ��仯����)
//·��������ÿ��������Ƕ������һ�����Σ������·���ĳ��ȡ�
//��ͼ��������Ƕ���������������󽨱ߣ�ȨֵΪ 1 
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



//8.��ѩ (DAGͼ�ļ��仯����)
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



//9.ʳ���� (DAGͼ�ļ��仯����)
//��ʳ��������(���Ϊ0)��ʼ�ѣ�����һ��Ҷ�ӽ��(����Ϊ0)�ͼ���һ��ʳ����
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e5 + 5;
// int n, m, res = 0;
// int f[N], indegree[N];//f[i] ��¼�� i Ϊ�����ʳ��������
// vector<int> gra[N];
// int dfs(int u)
// {
//     if(f[u]) return f[u];
//     if(!gra[u].size()) return 1;//û���ھӳ��ߣ�˵����Ҷ�ӽ��
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
//         if(!indegree[i] && gra[i].size())//size�Ƿ�Ϊ��(�൱�ڳ���)�жϵ����㣬�����㲻����
//             res += dfs(i);
//     cout << res;    
//     return 0;
// }



//10.Tian Ji -- The Horse Racing (����DP + ���仯����)
//����״̬dp[k][i][j] Ϊ�� k �ֱ���ʱ(�������kֻ�����ʱ)���ʣ����[i, j]��������[i, j]�����ٶ�λ��С��������
//̰�Ĳ��ԣ��������һ���䣨������Ӯ����������������ɾ�����С�������������Ӯ�ͱȣ���ƽ����������С���������Ž�
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e3 + 5;
// int n;
// int dp[N][N], a[N], b[N];
// bool cmp(int a, int b) {return a > b;}
// int dfs(int i, int j, int k)//����Ǯ��
// {
//     if(k == n + 1) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     if(a[i] > b[k])//��������Ӯ��Ӯ
//         return dp[i][j] = dfs(i + 1, j, k + 1) + 1;
//     else if(a[i] < b[k])//Ӯ���˾����������ڻ�
//         return dp[i][j] = dfs(i, j - 1, k + 1) - 1;
//     else//ƽ�־��������ѡ�� -- ѡ��ƽ�ֻ���������ȥ��
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
//Ҳ������˫ָ���










































































//N�ʺ�����(δ�޸�)
// #include <iostream>
// using namespace std;
// int n, k, cnt=0;
// int col[10]{};//��һ������û�з�
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

















































/*��.ǰ׺�� �� ���*/
/*�����:
1.ǰ׺����ָĳ���е�ǰn��ͣ����԰������Ϊ��ѧ�ϵ����е�ǰn���;
2.��ֿ��Կ���ǰ׺�͵������㡣�����ʹ��ǰ׺�����֣����Խ�ĳЩ���ӵ�����򵥻���
*/

//ǰ׺��
/*֪ʶ����
//һάǰ׺��
//������������an������ĳ���䷶Χ����ֵ���ʱ����ÿ�ζ�Ҫѭ������������������Ԫ�ز��Ӻͣ����ܻᵼ��ʱ�临�Ӷ� O(n*m) �� n*m �ܴ�ʱ����
//���������һ������S[i]�����δ洢ǰi��ͣ���S[1] = a1 , S[2] = S2 = a1 + a2 ,  S[3] = S3 = a1 + a2 + a3  (S[0] ������Ϊ 0)
//��ô�������е�ĳ��Χ[n,m] (n<=m)������ʱ,ֻ��Ҫ��� S[m] - S[n-1] (����S[n-1]�������,��ΪҪ���n��m�����Ͳ��ܼ�ȥ����n���S[n]) 
//�洢��ʽ��sum[i] = sum[i-1] + arr[i]
//��ȡ��ʽ��res = sum[m] - sum[n-1]
// #include <iostream>
// using namespace std;
// const int N = 1e8 + 1;
// int arr[N], sum[N];
// int main()
// {       
//     int n,m;//����ķ�Χ
//     //��ʼ������
//     for(int i=1;i<=N-1;i++) arr[i]=i;
//     //ǰ׺�Ͳ���(ʵ���Ͽ��Ա߶�ȡarr���������߽�����Ͳ���)
//     for(int i=1;i<=N-1;i++) 
//     {
//         sum[i] = sum[i-1] + arr[i];//sum[0]=0
//     }   
//     while(cin>>n>>m)
//         cout<<sum[m]-sum[n-1]<<endl;
//     return 0;
// }

//��άǰ׺��
//�洢��ʽ��sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// ��ȡ��ʽ��res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
// #include <iostream>
// using namespace std;
// const int N = 1e4 + 1;
// int arr[N][N];
// int sum[N][N];
// int main()
// {       
//     int x1,x2,y1,y2;//����ķ�Χ
//     //��ʼ������
//     for(int i=1;i<=N-1;i++) 
//         for(int j=1;j<=N-1;j++)
//             arr[i][j]=i+j;
//     //ǰ׺�Ͳ���(ʵ���Ͽ��Ա߶�ȡarr���������߽�����Ͳ���)
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


//1. P1115 ����Ӷκ�
// //ǰ׺�� + ����DP\̰��
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
//         //�����µ�ǰ׺�;���ѡ���ԣ�����һ��ǰ׺��С�ڶ�ȡ���������ǾʹӸ�����ʼ���¼���ǰ׺�ͣ������õ��ܸ���������е�ǰ׺������
//         //��ʱǰ׺��˼��ʵ���������������������У������Ƕ����塣
//         //�ð����ᱻ�ֳ�������������У�{2,-4} {3,-1,2,-4,3}
//         //�ֱ�õ�ǰ׺������ {2,-2} {3,2,4,0,3}
//         //���еڶ���ǰ׺�������е����ֵ 4 ����
//         res=max(res,sum[i]);//ȡ��ǰ׺�����������ֵ
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
//����ֻ���ҵ�һ����������������������ֱ������,���������Ǿ�������ʱ��(�볲ԭ��)�Ϳռ临�Ӷ�(ʹ��vector)��д��
// #include <iostream>
// #include <vector>
// using namespace std;
// int n,m,T;
// bool jud(vector<int> &s)
// {
//     if(n>=m) return true;//�볲ԭ��: n+1ֻ���ӷɻ�n������������һ���������в�����2ֻ�ĸ���
//     for(int i=1;i<=n;i++)//�ų�n>=m����ٱ���n<m���������ʱֻ��ֱ�ӵ���m���п��ܷ��ϣ�����ʱ�临�Ӷ�
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
//ԭ����д��:
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
�ٸ����ӣ���m=7��������Ϊ 2,4,6,3,5,5,6 ��
��������ĺ͵õ� 2,6,12,15,20,25,31����Щ������7��ʱ�����ֱ�Ϊ 2,6,5,1,6,4,3��
����������6������������ζ�Ž��ۣ�6+3+5=14 �ɱ�7����

֤����
������m���ͣ�Sn��,
a1,a1+a2,a1+a2+a3,����,a1+a2+a3+...+am
Ҫ֤������������һ���Ϳ��Ա�m����
1.����Щ������һ��Si���Ա�m������Si%m=0����ö�����֮��Si���Ա�m����
2.��Щ���е�ÿһ������m����һ��������������������1,2��������m-1 �е�һ������
��Ϊ��m���ͣ���ֻ��m-1�����������Ա�Ȼ�������ͳ���m����ͬ��������(�볲ԭ��)
��ˣ��������� k��l��k<l��ʹ��a1+a2+...+ak �� a1+a2+...+al����m����ͬ������r��
a1+a2+...+ak=b*m+r��a1+a2+...+al=c*m+r
��ʽ����� ak + ak+1 + ak+2 + ���� + al = (c-b)*m
���ö�����������֮�Ϳ��Ա�m����
*/

//3.Olympiad
/*AC
#include <iostream>
#include <set>
using namespace std;
int T,sum[100005],x1,x2;
bool jud(int x,set<int> &s)//�ж��Ƿ�Ϊ������
{
    if(!x) return 1;
    if(!s.count(x%10)) s.insert(x%10), jud(x/10,s);//û�ظ����ȷŽ����ϣ������´����أ����ҵݹ������������
    else return 0;//�Ѿ������Ԫ�أ�˵���ظ�
}
int main()
{
    //�ȴ��
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
/*���̣��Ե�������λ�������� ����д������λ���㣩
bool Judge(int x) {
    int flag = 0;
    for(; x; x /= 10) {
        if(flag >> x % 10 & 1) return false;
        flag |= 1 << x % 10;
    }
    return true;
}
flag�ö������ӽ�����ʼΪ 00 0000 0000 (ֻ��Ҫ����0~9����10��λ�ã���λ��0����)
��һ���� 343
�ȶԸ�λ3����
    �״��ж���Ч
    1 << x % 10 �� 1 << 3 --> 00 0000 1000
    Ȼ�� flag��00 0000 0000�� |= 00 0000 1000 �� 00 0000 1000 ���������Ϊ��ǲ���һ��1��
�ٶ�ʮλ��4����
    ���ж�:
        flag >> x % 10 �� flag>>4 ������  00 0000 0000�������1���׳���
        �漴 00 0000 0000 & 1 ����û���ظ�(����û�б���ǹ�)
    Ȼ�� flag��00 0000 1000�� |= 00 0001 0000 ����1<<4������������ǵõ� 00 0001 1000
���԰�λ��3����
    ���أ�
        flag >> 3 �� 00 0000 0011
        ��� 00 0000 0011 & 1 ��ʵ�����ǶԵ�λ�� ��λ�� 1�������ֵ�λҲΪ1����3�ѱ���ǣ����õ�1,���ж���Ϊ�ظ���
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


//5.����Ӿ���(����ǰ׺��)
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
/*д���Ż�
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


//6. P1719 ����Ȩ����
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
//DP���淽����
// #include<cstdio>
// int b[125][125];
// int main() {
// 	int n,ans=-1828805;//�������㣬��С����С�����ֵ 
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;++i) {
// 		for(int j=1;j<=n;++j) {
// 			int a;
// 			scanf("%d",&a);
// 			b[i][j]=b[i-1][j]+a;//ֻ������ÿһ�е�ǰ׺��
// 		}
// 	}
// // 0 -2 -7 0
// //  9 2 -6 2
// // -4 1 -4  1
// // -1 8  0 -2
// //ת��Ϊ��������ǰ׺��
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
// 		for(int j=0;j<i;++j) {//����˫��ѭ��ȫ����
// 			int sum=0;
// 			for(int k=1;k<=n;++k) {
// 				int tmp=b[i][k]-b[j][k];//ȡһ�������ǰ׺�� 
// 				if(sum<0)	sum=0;//С��0�ĺ����¼���
//                 sum+=tmp;
// 				if(sum>ans)	ans=sum;
// 			}
// 		}
// 	}
// 	printf("%d",ans);
// 	return 0;
// }




















//���
// ������飺
// ���ȸ���һ��ԭ����a[]��a[1], a[2], a[3],,,,,, a[n];
// Ȼ�����ǹ���һ������b[] �� b[1], b[2], b[3],,,,,, b[i];
// ʹ�� a[i] = b[1] + b[2] + b[3] + ,,,,,, + b[i]
// Ҳ����˵��a������b�����ǰ׺�����飬���������ǰ�b�������a����Ĳ�����顣���仰˵��ÿһ��a[i]����b�����д�ͷ��ʼ��һ������͡�
// ��;��
// ���������[l, r]�������ǰ�a�����е�[l, r] �����е�ÿһ����������c,�� a[l] + c , a[l + 1] + c , a[l + 2] + c ,,,,,, a[r] + c;
// ���ܸ�Ч�ض�һ����Χ�������и���\����,�����Ǳ�����������
// �㷨�ص�:
// ��a�����е�[l, r] �����е�ÿһ����������c,ֻ��Բ������b[]�� b[l] + = c, b[r+1] -= c 
// �� b[r+1] -= c ����ʹ�ø���������������ǰ���޸ĵ�Ӱ�죡����ֻ�޸�ĳһ�����ֵ

//һά���
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
//         b[i] = a[i] - a[i - 1];      //�����������
//     }
//     int l, r, c;
//     while(m--)
//     {
//         scanf("%d%d%d", &l, &r, &c);
//         b[l] += c;     //��ʾ��������[l, r]֮���ÿ��������c
//         b[r + 1] -= c;
//     }
//     for(int i = 1;i <= n; i++) 
//     {
//         b[i] += b[i - 1];  //��ǰ׺������
//         printf("%d ",b[i]);
//     }
//     return 0;
// }

//��ά���
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
//             insert(i, j, i, j, a[i][j]);      //�����������
//     while (q--)
//     {
//         int x1, y1, x2, y2, c;
//         cin >> x1 >> y1 >> x2 >> y2 >> c;
//         insert(x1, y1, x2, y2, c);
//     }
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//             b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //��άǰ׺��
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
/*AC ��һ����� �� ��ǰ׺�Ͳ�ѯ
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
// set<p> s;//���ܻ����ظ����䣬����
// int main()
// {
//     cin>>N>>I>>H>>R;
//     b[0]=H;//ÿͷţ�����߶ȶ�Ϊ��߸߶�
//     while(R--)
//     {
//         cin>>A>>B;
//         if(A>B) swap(A,B);
//         if(!s.count(p(A,B))) 
//         {
//             s.insert(p(A,B));
//             b[A+1]--,b[B]++;//����ţ֮��߶ȵ���Թ�ϵ
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


//3.Monitor(�������)
//С֪ʶ: cmathͷ�ļ����涨����y1,j0,j1,jn,y0,yn(�����ڱ�����������)��������Щ��������������ȫ�ֱ�����
/*AC
// #include <cstdio>
// #include <vector>
// using namespace std;
// typedef vector<int> vi;
// void bsum(int n,int m,bool op,vector<vi> &b)//1=ǰ׺��,0=תbool
// {
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//             if(op) b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
//             else b[i][j]=bool(b[i][j]);//��ʾ�ظ����� >1 ����Ϊ1, Ϊ0����Ϊ0
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
/*���̴��루��ά��� ת ��άǰ׺�� ������д����
#include<cstdio>
#include<algorithm>
#include<set>
int n, m, p, q;
int main() {
    int x1, y1, x2, y2; // С���ã�y1������ȫ�ֱ��������ֵĿ�
    while(scanf("%d%d", &n, &m) != EOF) {
        std::vector<std::vector<int> > a(n + 10, std::vector<int>(m + 10, 0));
        for(scanf("%d", &p); p --; ) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            a[x1][y1] ++;
            a[x1][y2 + 1] --;
            a[x2 + 1][y1] --;
            a[x2 + 1][y2 + 1] ++;
        }
        //���´�����⼴��(����Ը��㷨�����)
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                a[i][j] += a[i][j - 1];
            }
            for(int j = 1; j <= m; j ++) {
                a[i][j] += a[i - 1][j];
            }
        }
        //��д���ȶԺ�����ͣ���������ͣ��������ڶ�ά���ת��άǰ׺�ͼ��䷽�㣡��������
        //�����(��x=1,y=1��ͷ,x=0��y=0��ֵ��Ϊ0):
        //1 1 1 1
        //1 1 1 1
        //1 1 1 1
        //���ѭ��,��i=1ʱ
        //  �ڲ��һѭ������͸��У��õ�:
        //  1 2 3 4
        //  1 1 1 1
        //  1 1 1 1
        //  �ڲ�ڶ�ѭ�������и�����һ�е�ֵ�����ڴ�ʱ��һ��Ϊx=0��ֵ��Ϊ0��ѭ������󲻱�
        //���ѭ��,i=2
        //  �ڲ��һѭ������͸��У��õ���
        //  1 2 3 4
        //  1 2 3 4
        //  1 1 1 1
        //  �ڲ�ڶ�ѭ�������и�����һ�е�ֵ����
        //  1 2 3 4
        //  2 4 6 8
        //  1 1 1 1
        //���ѭ����i=3��ͬ��
        //  ��һѭ���õ���
        //  1 2 3 4
        //  2 4 6 8
        //  1 2 3 4
        //  �ڶ�ѭ���õ���
        //  1 2 3 4
        //  2 4 6 8
        //  3 6 9 12
        //���ÿ���������һ����Χ����ͣ�����άǰ׺��
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                a[i][j] = (!!a[i][j]) + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];    // ��bool����
            }//!!a[i][j] �൱�� bool(a[i][j])
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


//4.P3397 ��̺
// #include <cstdio>
// int b[1005][1005];//���鶨��ÿһά����һ��Ҫ���ٶ��5����Ȼ����Խ��
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


















/*��. �߾�������*/
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
//AC (�±������)
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
//     if(n1[0]=='0'||n2[0]=='0')//һ��Ϊ 0 ��ֱ����� 0 ���˳�����
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
//             res[i+j+1] += res[i+j] / 10;//ʮλ����λ����һ������λ��
//             res[i+j] %= 10;//�ڸ�λ���ֻ������λ��
//         }
//     }
//     for(int i = len1+len2-1; i >= 0; i--)
//     {
//         if(i == len1+len2-1 && res[i] == 0) continue;//��������̫С��δ������λ�������ڽ�������λ����ǰ����,�� 100000000 * 3
//         printf("%d", res[i]);
//     }
//     return 0;
// }






















/*��. */
//���ֲ���
// mid = (right + left) / 2 ��д���� (right + left) ���׳��ޣ�Ϊ�˱���������ӹ����ޣ���������д����
// mid = left + (right - left) / 2
// ���㷨��Ҫ����������ģ��ʳ��� sort() ��������
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int nums[100000];
// int binary_search(int nums[], int size, int target)
// {
//     int left = 0, right = size - 1;
//     while(left <= right)//ע����������Ϊ˫������ [left, right] ��left��right����ȡ��ֵ,��left==right�����Ҳ����ȡ��ֵ
//     {
//         int mid = left + (right - left) / 2;
//         if(nums[mid] < target) left = mid + 1;
//         else if(nums[mid] > target) right = mid - 1;
//         else 
//             return mid;//�ҵ��ͷ����±�
//     }
//     return -1;//û�ҵ������
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


//1. P2249 ����
//���ַ�(���б�ͨ) 0.3s 4.25mb
// #include <iostream>
// using namespace std;
// int nums[1000005],n,m;
// int bin_search(int tg)
// {
//     int lef = 1, rig = n + 1;//����ҿ�����
//     while(lef < rig)
//     {
//         int mid = lef + (rig - lef) / 2;
//         if(nums[mid] >= tg) rig = mid;//*������ tg ʱҲ����������ȥ��ֱ�� lef ָ��������Ŀ��ֵ
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
//set���� �� ����ӳ�� ��Ӧ��(��ҪO2�Ż����Һ�ʱ���� 1s,�ռ䳬��67mb)
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
//     multiset<int> ms;//multiset�����ظ����ݣ����������ظ�ֵ��Ч�ʸ���
//     unordered_map<int,int> mp;//����ʱ���������ܹʲ���map������map�ᳬʱ
//     cin >> n >> m;
//     for(register int i = 1; i <= n; i++) 
//     //��Ϊ�𰸱�Ŵ�1��ʼ����������Ҳ���±�1��ʼ��ʡȥһЩ�鷳 �� register int���ٶ��ѭ���ĺ�ʱ
//     {
//         int k;
//         cin >> k;
//         ms.insert(k);
//         if(mp[k]==0) mp[k] = i;//�������Ӧ�ı��
//     }
//     while(m--)
//     {
//         int target, res;
//         cin >> target;
//         res = *ms.lower_bound(target);//�ú������� >= target ��Ԫ�ص�ָ��λ�ã����Խ�����ֱ��ȡ����ֵ
//         if(res != target) cout<<-1<<' ';
//         else cout<< mp[res] << ' ';
//     }
//     return 0;
// }


//2. P1102 A-B ����
//ӳ�䷨
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
//         cin>>a[i];//����A
//         mp[a[i]]++;
//         a[i]-=C;//ת��B
//     }
//     for(register int i=0;i<N;i++)
//         ans += mp[a[i]];//A-B=C -> A-C=B,���ڲ�B�ж��ٸ����Σ����õ����ٶ�A-B=C
//     cout<<ans<<'\n';
//     return 0;
// }
//˫ָ�뷨
//ԭ��������������������һ����Ҳ������һ������������
//  ��ô������rig1�ҵ������������������rig2�ҵ��������������������ڴˣ�
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
//         while(rig1 <= N && a[rig1]-a[lef] < C) rig1++;//��� a[rig1]��������     
//         while(rig2 <= N && a[rig2]-a[lef] <= C) rig2++;//�ҿ���a[rig1<=i<rig2]��������       
//         if(a[rig1] - a[lef] == C && a[rig2-1] - a[lef] == C && rig2 >= 2)//rig2 >= 2˵������Ҫ��������
//             ans += rig2 - rig1;
//     }
//     cout<<ans<<'\n';
//     return 0;
// }






//���ֲ���
//������Ԫ��x��n/3����Ԫ�رȽϣ�Ȼ��x��2n/3����Ԫ�ؽ��бȽϡ��ȽϵĽ�������ҵ�x,���߽�������Χ��С��ԭ����n/3
//ÿ��������mid��������m1 = (2/3)*left + (1/3)rig ����ࣻm2 = (1/3)left + (2/3)rig ���Ҳ�
//ͬ���ģ���ֹ���޵�д����m1 = lef + (rig - lef) / 3 ��m2 = rig - (rig - lef) / 3;
//lef=0            m1            m2         rig=n-1
//��       x
//lef=0      rig=m1-1  
//��                                    x
//                             lef=m2+1     rig=n-1
//��                      x
//                lef=m1+1   rig=m2(��Ϊʱֱ����else,û����������nums[m2],��nums[m2]Ҳ����Ϊx�����Բ���1)
// #include <iostream>
// using namespace std;
// int nums[] = {1,2,3,4,5,6}, n=6;
// int third_search(int lef, int rig, int x)
// {
//     if(lef <= rig)//˫������
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





//1. ��ʯͷ
//����Ѱ��������̾��룬ʹ�ð��þ������ʯͷ���պð���M��
//�ɳ����ò�ּ�
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
//         if(dis[i] - dis[now] < x)//����С����������x��x������ϣ���Ŀ�����������ʯͷ����룩
//             cnt++;
//         else
//             now = i;//���ʯͷ���ܰ��ߣ�����˵����Ϊ���ڵ���x �������ǿ�������������ߣ����������������������ʯͷ�ľ���
//     return cnt <= M;
// }
// int main()
// {
//     scanf("%lld%d%d",&L,&N,&M);
//     for(int i = 1; i <= N; i++) scanf("%lld", &dis[i]);//һ��Ҫ��1��ʼ����Ϊdis[0]��ҪΪ0
//     dis[N+1] = L;
//     ll lef = 1, rig = L, ans = 0;
//     while(lef <= rig)
//     {
//         ll mid = lef + (rig - lef) / 2;
//         if(judge(mid)) 
//         {
//             ans = mid;//����ans�������Ž�
//             lef = mid + 1;//mid��ߵ�ʯͷ���жϹ���,�ٲ����ұ����޸���
//         }
//         else
//             rig = mid - 1;
//     }
//     printf("%lld", ans);
//     return 0;
// }



//2. Cable master(���� �� С������ ����)
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
���ⰸ����
4 10
0.01
0.01
0.02
0.01
��ֱ��������������0.01 ,ʵ��������0.005����������Ľ������Ӧ�����0.00
 */



//3. P2440 ľ�ļӹ�
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
��������ͣ�x + 0.5 ת ����
����ȡ�����ǣ�תint
����ȡ�����ǣ�x - eps + 1 ת ����
*/



//6. Monthly Expense (���� + ̰��)
// #include <cstdio>
// #include <algorithm>
// using namespace  std;
// int n, m, a[100005];
// bool judge(int x)
// {
//     int cnt = 0, sum = 0;
//     for(int i = 1;i <= n;i++)
//     {
//         if(sum + a[i] <= x) sum += a[i];//��װ���پ�װ����
//         else 
//         {
//             cnt++;
//             sum = a[i];//ֱ��װ������������
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
//             l = max(a[i], l);//�ų����ⰸ������С��������Ϊmax(a[i]) �����������Ϊ���к� �����û��ϵ��
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



//*7. Last Rook(����ʽ����)
// ����ת��Ϊ����������
// ����һ�в����� Rook��
// ����һ�в����� Rook��
// �ֱ���Ҷ��ִ𰸼��ɣ���󽫹�ָͬ��һ������
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
//     //������
//     while(x1 + 1 < x2)
//     {
//         int mid = (x1 + x2) >> 1;
//         if(IO(x1, mid - 1, 1, N) == mid - x1) x1 = mid;//������������£�����С��緶Χ
//         else x2 = mid;
//     }
//     //������
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
//ö�� + ����
//�����ص㣬���ݳ˻����������ѧ����������
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
//     //base��Ҫ�� __int128_t ���� ��ǰ�ж���������� n = 1e12, k = 1e11ʱ���
//     //�Ϸ���Χ base * k <= max ,  max = n
//     //���ɳ�����ʽ�����
//     for(int i = 1; i <= r; i++)
//     {
//         if(n / base < k) return n + 1; //��base����ʱ������k�ͻ��С
//         res += (base *= k);
//         if(res > n) return n + 1;
//     }
//     return res;
// }
// int main()
// {
//     while(~scanf("%lld", &n))
//     {
//         pair<ll, ll> ans(1, n - 1);//��ʼ��Ϊ�����Խϴ�� (r, k)��
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
//                 if(res < n - 1) k1 = mid + 1;//ע����ֽ�
//                 else k2 = mid - 1;
//             }
//         }
//         printf("%lld %lld\n", ans.R, ans.K);
//     }
//     return 0;
// }



//9. A-B ����
//����дҪ���ζ��֣�ֱ���ú���
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
//         //����ָ������Ľ��������֮��ľ���
//     }
//     printf("%lld", cnt);
//     return 0;
// }



//10. ���ַ�
//��ȫ����
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
//��������
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



//11. ����
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
//���ֺ���
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



//12. ���ɿ���
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
//     for(int i = 1; i <= n; i++) res += (s[i].first / x) * (s[i].second / x);//�ص�
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











/*��. ����ջ �� ��������*/
//����ջ��һ�������ջ������֮������ջ�ڵ�Ԫ�ض�����һ�������ԡ����ֲ�������ʱ�׳�
//���峡�����߸���ͬѧ���Կ�����߱��Լ�����ͬѧ������Ŀ��һ���������ڻ�����Լ���ͬѧ�󣬱��޷�������ǰ����
//         ���ȸ�������ͬѧ����ߣ�������ͬѧ�ܿ�����ͬѧ����֮�͡�
//����Ҫ���ĳ��ֵ���±���ŵȣ�����Ҫ�Ƚ������ֵ���������飬�����Ǹ�����ջ��Ҫ�ӽ���������ٿ����洢�𰸵�����
//ģ��:
//1.ֻҪ��ÿ���ӽ��֮�ͣ����������(�׸�Ԫ��Ϊ��ֹ�㣬��������һ��Ϊ 0 )
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
//2.��ÿ���ӽ���д洢�������������(���һ��Ԫ��Ϊ��ֹ�㣬һ���Ӧ������Ϊ 0)
// P5788 ��ģ�塿����ջ
//���ÿ������Ӧ��������ҵ���һ�����ڸ��������ı��(��1��ʼ��)
//������ 1 4 2 3 5, 1�������ȴ���������Ϊ4���±�Ϊ2����f(1)=2,ͬ��f(4)=5
//�ʴ� 2 5 4 5 0
//�����һ����Ϊ �׸��ϸ��� ����
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
//         while(!sta.empty() && a[sta.top()] <= a[i]) sta.pop();//�׳�ջ���ȵ�ǰ��С�ģ��л��ϸ���Ϊ��ǰ��
//         f[i] = sta.empty() ? 0 : sta.top();//��ջ˵��ǰ��û�нϸ���,���ò������е�������
//         sta.push(i);//��ѡ�ϸ��ߵ��±�,��������ᱻ�׳�
//     }
//     for(int i = 1; i <= n; i++) cout<<(" "+!(i-1))<<f[i];
//     return 0;
// }



//1.POJ2559 ֱ��ͼ�е�������
//����ģ�ⵥ��ջ(��ֱ��ʹ�� ջstack ��TLE)
//���㵥��ջʹ��ǰ�᣺�����θ߶ȴ������ҵ�������������ÿ�����εĸ߶ȳ����䵽�ұ߽�Ŀ�ȵõ�һ�������ȡ��Щ����е����ֵ��
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// const int MAXN = 1e5 + 10;
// struct nd{
//     ll h, x;//��¼���ε� �߶� �� ������
//     nd(){h = 0, x = 0;}//��ʼ��������ֵΪ 0
// }a[MAXN];//ģ�ⵥ��ջ
// int main()
// {
//     int n;
//     while(~scanf("%d", &n), n)
//     {
//         ll ans = 0, H;
//         int top = 0;//��ָ�� ģ��ָ��ջ��
//         for(int i = 1; i <= n; i++)
//         {
//             scanf("%lld", &H);
//             if(H >= a[top].h) a[++top].h = H, a[top].x = i;//�������䣨ʵ�����ǵ�������������ջ
//             else
//             {
//                 //�� ��Ϊ H �ľ��� Ϊ�ҽ磬��ջ�����μ��������ֱ����������Ϊ�ҽ磨��ջ���������㵥��������
//                 while(H < a[top].h)
//                 {
//                     ans = max(ans, a[top].h * (i - a[top - 1].x - 1));//�ϸ���������ϣ�top���ε�����ȻΪ(top-1)����
//                     top--;
//                 }
//                 //�ҽ���α���������壬��Ȼ��ջ
//                 a[++top].h = H, a[top].x = i;
//             } 
//         }
//         //�� i = n + 1 �ĸ߶�Ϊ 0 �ľ��� Ϊ�ҽ磬����ʣ��������
//         //��ʱ��ȼ���Ϊ L = a[top - 1].x ��R = n + 1���� width = (R - L - 1) = (n - a[top - 1].x) 
//         while(top) ans = max(ans, a[top].h * (n - a[top - 1].x)), top--;
//         printf("%lld\n", ans);
//     }    
//     return 0;
// }
//����
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
���谸��
     9
     3 4 2 1 2 3 5 2 3
i= 0 1 2 3 4 5 6 7 8 9 10 (����i=0��i=10��Ϊ��λ���ã���߶�����Ϊ0������С)
����������
*/



//2.����վ
//���ܲ�ͬ�Ĵ淨�����Ŀռ临�ӶȲ���
//��ṹ��(15.9 MB)
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
//stack �� id �ȽϺ�(11.5 MB)
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
//����������(11.7 MB)
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
//�𰸼��ǻ��ֳ����������
//���� 1 2 3 2 1 3
//��������� [1, 6] +1 ��[2, 4] +1 ��[3, 3] + 1��[6, 6] + 2
//��4��
//��ɽ�� 1 2 4 1��������3��(�������䳤��Ϊ3)�����������Ϊ 3����ֻҪ��� �������� ���ɣ���Ȼά��һ������ջ���ɽ������
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



//4.Patrik ���ֻ�ĵȴ�
//�Եȸ��������¼���ú��������
// #include <iostream>
// #include <stack>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// struct nd{
//     int h, s;//sΪ����֮ǰ�����ȸߵ��˵�����(�������Լ�)
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
//         if(!sta.empty()) ans++;//ջ��������Ԫ�أ�˵��ǰ���� x ���ڵ��˱����ߣ������
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










// �������� �� ������Ԫ��֮��Ĺ�ϵ���е����ԣ����ң����׺Ͷ�β�����Խ��г��Ӳ�����ֻ�ж�β���Խ�����Ӳ�������������˫�˶���dequeʵ�ֵġ�
// ���ڵ������У��������˵�����ֻ����һ�˲��� �����������з�����ʵ�����ǡ����ȼ����з�������һ���Ż�
// ��ͷ ----> ��β
// �ݼ����У�ά���ݼ��ԣ����ƻ��ݼ���Ԫ��X���򵯳���ͷ����С�� x ��Ԫ��
// �������У�ά�������ԣ����ƻ�������Ԫ��X���򵯳���ͷ���д��� x ��Ԫ��
// ��������ݼ����� ��ͷ �� ��β ��

//1.Sliding Window(��������)
// #include <cstdio>
// #include <queue>
// using namespace std;
// const int MAXN = 1e6 + 10;
// int arr[MAXN];
// int ans1[MAXN], ans2[MAXN];//�洢ÿ�����ڵ���ֵ
// deque<int> dq1, dq2;
// //dq1�ݼ����У���ȡ�������ֵ��dq2�������У���ȡ������Сֵ
// int main()
// {
//     int n, k, index1 = 0, index2 = 0;
//     scanf("%d%d", &n, &k);
//     for( int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     //ʹ�õ�һ������ȥ��ʼ����������
//     for( int i = 0; i < k; i++)
//     {
//         while(!dq1.empty() && arr[i] >= arr[dq1.back()]) dq1.pop_back();
//         while(!dq2.empty() && arr[i] <= arr[dq2.front()]) dq2.pop_front();//�ԳƲ�������
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
//         //�ж���ֵ�Ƿ��԰����ڴ����У����Ѳ��������
//         if(dq1.front() + k <= i) dq1.pop_front();
//         if(dq2.back() + k <= i) dq2.pop_back();
//         ans1[index1++] = arr[dq1.front()];
//         ans2[index2++] = arr[dq2.back()];
//     }
//     for( int i = 0; i < index2; i++) printf(" %d" + !i, ans2[i]);//��������Сֵ
//     printf("\n");
//     for( int i = 0; i < index1; i++) printf(" %d" + !i, ans1[i]);//���������ֵ
//     return 0;
// }
//����ģ��
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
//         if(i + 1 >= k) printf("%d ", a[q[hh]]);//ÿ��������ɲ�����������һ����ֵ
//     }
//     puts("");//puts�Զ�����
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
//��������
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
//         //�ӵ�һ����С��n��������ʼ����û�����10000�ڵ����������ʼ
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
//Ҳ����˫ָ��(��ȡ��)
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



//3.�е���
// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// deque<int> dq;//ά��ǰ׺�͵�����˫�˶��У����ȳ��� m ��pop��ͷ(���±귽���ȡǰ׺��)
// //max(ans) = max(sum[i] - min(sum[i - m]))������ dq.front() ��Ҫ�ǵ�ǰ��С��ǰ׺��
// int sum[500005], ans = -25e7;
// int main()
// {
//     untie();
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> sum[i], sum[i] += sum[i - 1];
//     dq.push_front(0);//��Ϊsum[0]����
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
















































/*��. ˫ָ��(��ȡ��)*/
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
//˫ָ��(���)
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
//˫ָ�� ������������û��1��
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
//��˫ָ�� �� 1s
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



//4.A-B ���� 
//A - C = B
//˫ָ��
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
//         if(r > 1 && a[l] - a[i] == c && a[r - 1] - a[i] == c) cnt += r - l;//1 2 3 ʱҪ���к������������ж�
//     }
//     printf("%lld", cnt);
//     return 0;
// }
//��������������



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
//         s[0].sum = s[0].id = 0;//ÿ�ζ��ó�ʼ��������
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
//δ���
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
//�����������β�����Խ�ͷ���γɱջ�����������Ե�����ջ�����ʱ�� tep ������ͷ����������ĺͣ�s += tep ������ɽӻ�
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
//         long long ans = 0;//��������� int �ػᳬ��
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
//(��ȡ + ̰��) || ����
//����ֻչʾǰ��
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
//         while(l < len)//���� ɾ������ �������ģ���ɳ�ȡ ʣ�����䣬�����������Ӷ�ΪO(n)
//         {
//             //̰�ģ�ʣ��������'0'�ĸ���(������'0'�Ĵ���) �� ɾ��������'1'�ĸ���(����ȥ'1'�Ĵ���) ���ʱΪ ���Ž�
//             while(r < len && mp['0'] != (tep - mp['1'])) mp[s[r++]]++;
//             ans = min(ans, max(mp['0'], tep - mp['1']));
//             mp[s[l++]]--;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }



//10.��1 Operation 2 
//(���� && ��ȡ) || (���� && ǰ׺��)
// pair<type1, type2> Ĭ�϶� first ���򣬵� first ��ͬʱ�Ŷ� second ����
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
//     //˼·���������� X �����������Ƚ�� X С�����⣬֮�������ֻ��Ҫ����ֵ����
//     int l = 1, r = 1;
//     for(int i = 1; i <= Q; i++)
//     {
//         while(r <= n && a[r] <= q[i].x) r++;//Ѱ�� x �� ai ��ֵ������ת�۵㣬����ת������
//         for(int j = l; j < r; j++)//�ر�أ�ת�������ڲ���
//         {
//             sum -= a[j] - tep;//��ȥ ǰ�� �Ļ���
//             sum += q[i].x - a[j];//ȡ ��ǰ�� �Ļ���
//         }
//         sum += (q[i].x - tep) * (l - 1);//�� ת��������� �Ĳ�ֵ
//         sum -= (q[i].x - tep) * (n - r + 1);//�� ת�������Ҳ� �Ĳ�ֵ
//         tep = q[i].x;
//         ans[q[i].id] = sum;
//         l = r;
//     }
//     for(int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
//     return 0;
// }
//���ַ����� ��ѵ��1



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
�������ڣ����������û�е�����
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


// #include <iostream>
// #include <set>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// int n;

// int main()
// {
//     untie();
//     cin >> n;
    

//     return 0;
// }









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
//         for(; l < len; l++)//ѡ��[l, r]������Ϻ� k ����ͬ��ĸ����ô���� x ����[r, len - 1]��ʹ����һ[l, x]��������,�ʸôδ𰸸��¼ӵ��� r �� r���� ����ĸ����
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



//15.���ʱ���
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
//         if(cnt[str[r]] == 1) ans1++, ans2 = r - l + 1;//�����µ��ʣ����ȸ��£�ans2ֱ�Ӹ���(��Ϊ���г������ȼ�����)
//         while(l <= r)//�ų����ñ��� �� �ظ��ģ��������̳���
//         {
//             if(!mp[str[l]]) l++;
//             else if(cnt[str[l]] > 1) cnt[str[l]]--, l++;
//             else break;//����ȷʵҪ���ģ��Ҵ�����Ψһ
//         }
//         ans2 = min(ans2, r - l + 1);
//     }
//     cout << ans1 << '\n' << ans2;
//     return 0;
// }


























/*��. ���۷ֿ�*/
//
//1.��������ȡ�����
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



//2.������������ȡ�����
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



//3.�Ȳ��������������ȡ��֮�����
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



//4.���۷ֿ�֮СС�ı�ͨ
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
//         //i > kʱ����ֵ��Ϊ k����ʱ (k / i) = 0 ���� l ѭ���� min(n, k) ����
//         for(int l = 1; l <= min(n, k); l = r + 1)
//         {
//             r = min(n, k / (k / l));//�� n < k ʱ���� 2 3���� l == n ʱ�����ܻᵼ�� r >= k����Ӧ�������� r <= n ��
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



//5.���Ը��ӵ����۷ֿ�
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
//             for(int i = 1; i <= m; i++)//�����ҵ�һ���Ҷ˵�
//             {
//                 r = min(1ll * r, n[i] / (n[i] / l));
//                 res = 1ll * (n[i] / l) * res % base;//�洢ʽ���Ҳ��۳˵Ľ��
//             }
//             ans = (ans + (fib[r] - fib[l - 1]) * res % base) % base;//fib�� L �� R ����� �� ���˵ĳ˻� �ķֿ飬˵�������������˽��Ϊ��ֵ
//         }
//         printf("%lld\n", (ans + base) % base);
//         //���ڼ���ȡ ���кͣ�ǰ׺�� ��ȡ��� ����õ���һ�� ���к� ��ֵ�ܿ��ܻ�Ϊ ��
//         //�������ڱ�����Զ� ���� ȡģ�Ի�õ� ��ֵ �������ȶ����� �������� �� ȡ�࣬���������ѧ���
//         // 4
//         // 44444 
//         // 55555
//         // 66666
//         // 77777
//         //�ð��������������ϴ�������ָ���
//     }
//     return 0;
// }







/*��. ����*/
/*
���÷��η����������һ����е��������£�
1.����Ĺ�ģ��С��һ���Ĺ�ģ�Ϳ��Խ����׵ؽ����
2.������Էֽ�Ϊ���ɸ���ģ��С��ģʽ��ͬ�������⣬����������������ӽṹ���ʡ�
3.�ϲ�����ֽ����������Ľ���Եõ�����Ľ⡣
4.�������ֽ���ĸ���������֮���Ƕ����ģ���������֮�䲻���ڹ����������⡣

��Ʋ��裺
1.���ֲ�������������⻮��Ϊk�������⣬������ʹ��k��������Ĺ�ģ������ͬ��
2.������������Ĺ�ģ����ĳ��Ԥ������ֵn0ʱ��������k���ݹ������ɡ�
3.��ϲ�����ϲ��Ѹ���������Ľ�������������Է����㷨��ʵ������������Ҫ���㷨����Ч�Ժܴ����������ϲ���ʵ�֡�

���η��Ĺؼ����㷨����ϲ�������Ӧ�������ϲ���Ŀǰû��ͳһ��ģʽ�������Ҫ�Ծ���������о���������Եó��ȽϺõĺϲ��㷨��
*/
/*
������
���İ��ӣ�
int PowMod(int a, int n, int mod)
{
    int ret = 1;
    for(; n; n >>= 1, a = 1LL * a * a % mod)
        if(n & 1) ret = 1LL * ret * a % mod;
    return ret;
}

*�ҵİ��ӣ�
//base ������index ָ��
//�������������ݣ�
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
//��������ݣ�
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//���� N ָ�����α߳���n ָʵ�ʾ��α߳�
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



//1.������
//���Կ�����
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
//����(matrix)������
//�Ѿ����������ɣ����ڿ��������㣬ֻ�����س˷����������ת��Ϊ���Ա��
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
//     //д�뵥λ���� A0 �������κξ��� X ��˵õ� X ����(A0 ��б�����¶Խ���λ�Ͼ�Ϊ1������Ϊ0)
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



//2.����Ӷκ�
//̰��\dp��
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
//         sum[i]=max(sum[i-1]+a[i],a[i]);//̰�ģ���ǰ�����ڸö�ǰ׺��ʱ��˵����ǰ׺�ͷ����Ž⣬����֮ȡ��ǰ���������¼���ǰ׺��
//         res=max(res,sum[i]);//ȡ��ǰ׺�����������ֵ
//     }
//     cout << res;
//     return 0;
// }
//���η���
//���÷��η���˼�룬��������һ��Ϊ�����ֱ���ȡ���������е�����Ӷκ͡�
//��Ȼ����ֶκ�Ҳ���ܿ�Խ���������У���Ϊ����Ҫ̽�ֵĵ��������
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
//         //���·������Ҷ�
//         lsum = subsum(l, mid);//�м�Ԫ�ػ���������
//         rsum = subsum(mid + 1, r);

//         //���¼����м��
//         for(int i = mid; i >= l; i--)//������������,�����м����������Ҫ�� mid �� l ��
//         {
//             sl_tmp += arr[i];
//             if(sl_tmp > sl) sl = sl_tmp;
//         }
//         for(int i = mid + 1; i <= r; i++)//������������,�����м����������Ҫ�� mid + 1 �� r ��
//         {
//             sr_tmp += arr[i];
//             if(sr_tmp > sr) sr = sr_tmp;
//         }
//         msum = sl + sr;//����֮�͵õ��м�κ�
        
//         //��������µĺ͵ıȽϣ�ȡ�����
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
�����㷨ʱ�临�Ӷȷ�����
1.���Ȱ�һ���ݹ�ĺ�������һ����㣬�����Ļ��ͷ�Ҷ�ӽ�㣨l==rʱΪҶ�ӽڵ㣩������������ӽڵ� -> log2n
2.���������Զ���L��R���з�����ʵ�������ϵ�λ�ã�ÿһ����౻����logn�Σ����logn�������ĸ߶ȣ�
3.������ͬһ��������ϵ�һ��λ�ý��ᱻһ���ڵ���� -> n
O(log2n * n) = O(nlogn)
*/

//3.��ŵ������
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



//*4.��������
// https://blog.csdn.net/weixin_44915226/article/details/119535259?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167176851016800222868521%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167176851016800222868521&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-5-119535259-null-null.142^v68^control,201^v4^add_ask,213^v2^t3_control1&utm_term=c%2B%2B%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F&spm=1018.2226.3001.4187
// #include <cstdio>
// #include <algorithm>
// int arr[100000], n;
// //1.���·������(��) -- �����������Ժ�����
// // int partition(int low, int high)
// // {
// //     int x = arr[low];//ȡ��һ��Ϊ��׼Ԫ�أ������������low����ʱΪ��λ����Ҳʹ�ú���lowָ���ǿ�λ
// //     while(low < high)
// //     {
// //         while(low < high && arr[high] >= x) high--;//highָ���ҵ���һ��С��x��Ԫ�أ�������xԭλ����
// //         arr[low] = arr[high];//��ʱhighָ������λ��Ϊ��λ
// //         while(low < high && arr[low] <= x) low++;//lowָ���ҵ���һ��С��x��Ԫ�أ�������highλ����
// //         arr[high] = arr[low];
// //     }
// //     arr[low] = x;//��󽫻�׼Ԫ������low�ϵĿ�λ
// //     return low;//�������ջ�׼λ
// // }
// // int quick_sort(int low, int high)
// // {
// //     if(low < high)
// //     {
// //         int xpos = partition(low, high);//ȡ��׼Ԫ��
// //         quick_sort(low, xpos - 1);//�Էָ�������������зֱ� �ٷָ�������
// //         quick_sort(xpos + 1, high);
// //     }
// // }
// //2.����(������ʽ�뷨1��ͬ) -> �������������������Ԫ�ؾ�ֱ�ӽ���,���ջ�׼Ԫ��������ָ���غ�λ
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
// //3.��϶���(����)
// void quick_sort(int l,int r)//Ӧ�ö���˼��
// {
//     int mid = arr[((l + r) >> 1)];//�м���
//     int i = l, j = r;
//     do{
//         while(arr[i] < mid) i++;//������벿�ֱ��м��������
//         while(arr[j] > mid) j--;//�����Ұ벿�ֱ��м���С����
//         if(i <= j)//�����һ�鲻����������������С�Ҵ󣩵���
//         {
//             std::swap(arr[i], arr[j]);//����
//             i++, j--;
//         }
//     }while(i <= j);//����ע��Ҫ��=
//     if(l < j) quick_sort(l, j);//�ݹ�������벿��
//     if(i < r) quick_sort(i, r);//�ݹ������Ұ벿��
// }
// int main()
// {
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     quick_sort(0, n - 1);
//     for(int i = 0; i < n; i++) printf(" %d" + !i, arr[i]);
//     return 0;
// }



//*5.�����(�鲢����)
//�鲢����ָ���ǽ�����˳�����кϲ���һ��˳�����еķ�����
// #include <cstdio>
// const int N = 5e5 + 5;
// int n, arr[N], tmp[N];
// long long cnt = 0;
// void merge(int l, int r)
// {
//     if(l >= r) return;
//     int mid = ((l + r) >> 1);
//     int posl = l, pos_tmp = l, posr = mid + 1;//posrָ���Ҳ������һ��Ԫ��
//     merge(l, mid);//�����������(�м�Ԫ�ع������)
//     merge(mid + 1, r);//�����Ҳ�����
//     while(posl <= mid && posr <= r)
//     {
//         if(arr[posl] <= arr[posr]) tmp[pos_tmp++] = arr[posl++];//����С��
//         else tmp[pos_tmp++] = arr[posr++], cnt += mid - posl + 1;
//     }
//     //��������ʣ��Ԫ�ض��ֱ����tmp�У���Ϊ���ջ���һ������һЩ�ϴ���û�����飩
//     while(posl <= mid) tmp[pos_tmp++] = arr[posl++];
//     while(posr <= r) tmp[pos_tmp++] = arr[posr++];
//     //��������������ԭ������
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
������ 8 3 2 6 7 1 5 4
�ݹ���ֻ����������ձ������һ��
[8 3]  [2 6]  [7 1]  [5 4]
�ֱ�����(����)
[3 8]  [2 6]  [1 7]  [4 5]
�����ϲ���������ָ�룬���� [3 8]  [2 6]����ָ�� l1 ָ�� 3 �� l2 ָ�� 2 ��С��һ���� l2 �������� �� l2++ ���õ�[2]��
                          ��ʱ3 < 6���õ�[2 3]����ʱ6 < 8�õ�[2 3 6]��Ȼ�����ѭ������ 8 �õ� [2 3 6 8]
��[2 3 6 8]  [1 4 5 7]
ͬ�����Ƶõ��������� [1 2 3 4 5 6 7 8]
*/



//6.Fractal
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// char map[1024][1024];//�����Ͻ�Ϊ���㣬����5������
// void setpic(int x, int y, int n)
// {
//     if(n == 1) 
//     {
//         map[x][y] = 'X';
//         return;
//     }
//     int k = (int)pow(3.0, n - 2);//������һ��degree��ͼ�γ���
//     setpic(x, y, n - 1);            //���Ͻ�
//     setpic(x + 2*k, y, n - 1);      //���Ͻ�
//     setpic(x + k, y + k, n - 1);    //�м�
//     setpic(x, y + 2*k, n - 1);      //���½�
//     setpic(x + 2*k, y + 2*k, n - 1);//���½�
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



//*7.�ܴ������ĵ�kС
//ʵ�����к���nth_element(a,a+k,a+len)  -> O(n)����������Ϊ���� k СԪ�ط���a[k]�ϣ�����֪��Ϊʲô��WA
// maxn ������Ϊ 1e7������O(nlogn)�������㷨(sort)�ᳬʱ(�ø��Ӷ��� 1s ֻ�ܲ��������� <= 1e6������)����Ѱ����һ�����Ӷ�O(n) ( <= 1e7)
//����������Ϊ O(n^2)������ʱ n ����������δ�ﵽȡģ�㣩������ƽ���������������Ϊ�� O(n)
// #include <cstdio>
// const int mod = 1e9 + 7, maxn = 5e7 + 5;
// int n, m, k, arr[maxn];
// int quick_search(int l, int r, int k)
// {
//     if(l >= r) return arr[l];
//     int low = l, high = r, x = arr[l];
//     while(low < high)
//     {
//         while(low < high && arr[high] >= x) high--;//���������ҵ�ȡģ����arr[0]��С��Ԫ��
//         arr[low] = arr[high];
//         while(low < high && arr[low] <= x) low++;
//         arr[high] = arr[low];
//     }
//     arr[low] = x;//����low���Ԫ�ؾ� <= x�����lowָ������ָ���(k - 1)λ��Ԫ�ؼ�Ϊans,��ʱlow - l == k - 1
//     if(low - l == k - 1) return arr[low];
//     //��low - l < k - 1˵����������СԪ�ز����������źõ�low��������䲢������Ѱ�õ�������������low�Ҳ�Ѱ��СԪ��
//     //��low - l > k - 1˵��low�������������֣������Ҳ����伴�ɣ��� (l, low] ��ʣ���k��  
//     if(low - l < k - 1) return quick_search(low + 1, r, k - 1 - (low - l));
//     else return quick_search(l, low, k);//�� k > ȡģ��ʱ�õ�
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
//nth_element��
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



//8.Fibonacci( ����ʽ -> O(logn) )
//1s������ maxn = 1e9����O(n) -> 1e7 ~ 1e8 �ʱ��뽵���� O(logn) ��⣬�����Ѹ�������
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



//9.��̺�����
//�������Ϊ�ĸ�������С����Ϊ 2 X 2 ���⣬������С������Ҫ̽���Ƿ��� ������(�����)����ȷ����̺��״
//Ψһ������ ֻ��������һ������������ Ψһ������ ȷ�����ĵ�̺(x, y)�ĶԽǷ�λ��
//�õ�(x, y)������ռ�õĵ����������������������(��Ϊ������)������ͨ�� 2X2 -> 4X4 -> n*n ���Ƶõ�
//��4x4���񣬸�ÿ��2��2�ĸ��Ӷ�����һ������㣬���м��Աߵ�3����ɫ���Ӷ�����ͬһ����ɫ��Ȼ���ٷֱ�������2��2�ĸ��Ӿ�����
//ע�⣬���м����մ�����ķ�����ǹ�������������
// #include <cstdio>
// int k, n = 1;
// #define pf(a, b, id) {printf("%d %d %d\n", a, b, id);}
// void dfs(int x1, int y1, int x2, int y2, int X, int Y)
// {
//     if(x2 - x1 + 1 == 2 && y2 - y1 + 1 == 2)//��ʱΪ��С���� 2x2 ���⣬���������λ�ü��������Ӧ����
//     {
//         if(X == x1 && Y == y1) pf(x2, y2, 1);//�����λ�������Ͻǣ��Խ�ʹ�õ�̺���� 1
//         if(X == x1 && Y == y2) pf(x2, y1, 2);//���Ͻ�
//         if(X == x2 && Y == y1) pf(x1, y2, 3);//���½�
//         if(X == x2 && Y == y2) pf(x1, y1, 4);//���½�
//         return;
//     }
//     int x = ((x2 - x1 + 1) >> 1) + (x1 - 1);//ȡ�е�(x, y)����
//     int y = ((y2 - y1 + 1) >> 1) + (y1 - 1);
//     //�ݹ����㷽λ����
//     if(X <= x && Y <= y)//����λ����������
//     {
//         pf(x + 1, y + 1, 1);
//         dfs(x1, y1, x, y, X, Y);//�����������ǹ���������
//         //��(x+1, y+1)��ĵ�̺����������������ֱ���������㣬��������������������ÿ�����������Ͻǵ������½ǵ��ѡ
//         dfs(x + 1, y1, x2, y, x + 1, y);//��������
//         dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);//��������
//         dfs(x1, y + 1, x, y2, x, y + 1);//��������
//     }
//     if(X <= x && Y > y)//����
//     {
//         pf(x + 1, y, 2);
//         dfs(x1, y + 1, x, y2, X, Y);//�������򣬹���������
//         dfs(x1, y1, x, y, x, y);//��������
//         dfs(x + 1, y1, x2, y, x + 1, y);//��������
//         dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);//��������
//     }
//     if(X > x && Y <= y)//����
//     {
//         pf(x, y + 1, 3);
//         dfs(x + 1, y1, x2, y, X, Y);//���£�������
//         dfs(x1, y1, x, y, x, y);//��������
//         dfs(x1, y + 1, x, y2, x, y + 1);//��������
//         dfs(x + 1, y + 1, x2, y2, x + 1, y + 1);//��������
//     }
//     if(X > x && Y > y)//����
//     {
//         pf(x, y, 4);
//         dfs(x + 1, y + 1, x2, y2, X, Y);//���£�������        
//         dfs(x1, y1, x, y, x, y);//��������
//         dfs(x1, y + 1, x, y2, x, y + 1);//��������
//         dfs(x + 1, y1, x2, y, x + 1, y);//��������
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




















/*ʮ. ���鼯 ���ȶ���*/
//���ģ�壺
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

//��Ȩֵ�Ż�ģ�壺
// #include <cstdio>
// #include <iostream>
// using namespace std;
// const int N = 1e4;
// int ds[N];
// void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
// int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}

//Ȩֵ�Ż�ģ�壺
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
//         d[x] += d[t];//Ȩֵ�������������Ҫ�󣬴˴��ԼӺ�ȨֵΪ��
//     }
//     return ds[x];
// }
// void merge_set(int x, int y)//�ϲ��������������Ҫ��
// {
//     int rootx = find_set(x), rooty = find_set(y);
//     if(rootx == rooty)
//     {

//     }
//     else
//     {

//     }
// }



//1.���鼯 ģ����
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
 


//2.�޸���·
//��Ȼsort�������Ͼ����������󣬹ʿ�������������
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
//     for(int i = 1; i <= m; i++)//n ����ׯֻ�� n - 1 ����ͨ����
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



//3.����(������)
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



//4.һ��У�˻�֮������(����Ԫ�ز�����ֵʱ�������ַ���)
// #include <iostream>
// #include <string>
// #include <unordered_map>//������Ϊ2e4����Ӧ���ᱻ������������map�������
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



//5.����
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
//     p1 = find_set(p1), p2 = find_set(p2);//��ʼp1,p2�ܿ��ܲ���Ϊ���ڵ㣬�����Һ�p1\p2�ĸ��ڵ�
//     for(int i = 0; i < N; i++)
//     {
//         int rt = find_set(i);
//         if(rt == p1) cnt1++;
//         else if(rt == p2) cnt2++;
//     }
//     printf("%d\n", cnt1 > cnt2 ? cnt2 : cnt1);
//     return 0;
// }



//6.����
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
//                 anc = str;//������
//                 break;
//             case '+':
//                 merge_strset(str, anc);
//                 break;
//             case '?':
//                 cout << str << " " << find_strset(str) << '\n';
//                 // cout << str << " " << ds[str] << '\n'; //*���������ﲻ��ֱ���� ds[str] �õ����ڵ�
//                 // ��Ϊ �߶�Ϊ 2 ���� �� ���������ڵ� �ϲ�ʱ���������Ѿ�ѹ�����ˣ����Ǻϲ���ȥ��߶ȱ��3��
//                 // ������һ������˵��������Ҳ�Ѿ�ѹ�����ˣ����Ǻϲ���û�н���ѹ���������������������Ҫ��ѯ�ſɵõ����ڵ�
//                 // ��˺ϲ�ʱ��ѹ�������� �߶�Ϊ1 �ĸ��ڵ� ���������ڵ������õ��߶�Ϊ2��ѹ�����������Ǹ߶�Ϊ3��δѹ����
//                 break;
//         }
//     }
//     return 0;
// }



//���¾�Ϊ���ȶ���
//7.�ϲ����� / [USACO06NOV] Fence Repair G
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
//     while(q.size() > 1)//ÿ��ȡ������С�Ѻϲ�����
//     {
//         int s = q.top(); q.pop();
//         s += q.top(); q.pop();
//         sum += s;
//         q.push(s);
//     }
//     printf("%d\n", sum);
//     return 0;
// }



//8.���籭
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



//9.���кϲ�
//��ѧ����
// i * j >= n �Ͳ�������ǰ n С�Ĵ�(��i��j����0��ʼ)
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
//���ȶ��з���
//�� N^2 ���Ϳ��� N ���������
// a[1] + b[1] -> a[1] + b[2] -> ... -> a[1] + b[N]
// a[2] + b[1] -> a[2] + b[2] -> ... -> a[2] + b[N]
// ...
// a[N] + b[1] -> a[N] + b[2] -> ... -> a[N] + b[N]
//ά��һ���ѣ����г�ʼ����N�����еĵ�һ��Ԫ��
//�� Сֵ�������� ��ÿ��ȡ�����е���Сֵ���������Сֵ�����ڵ�k�����У���ô���ͽ���k�����е���һ��Ԫ�ط������
//�������ܱ�֤ÿ��ȡ�õ���Сֵȷʵ�ǵ�ǰ������Сֵ
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
// priority_queue<pii, vector<pii>, greater<pii> > q;//������Ͳ��ᳬint����ʱ���ȶ����д���� N �������и��Ե���Сֵ
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
// //ά��һ���洢 ţ���ݽ���ʱ��� ��ջ��ʱ���Խ�磬Խ��ջ����Խ�����
// //�ڵ���ջ��ţʱ�����ܽ��ӣ����Դ�ʱ����˵�������ʱ����� ��ջ��ţ���ݺ�ʱ + ������ݺ�ʱ���� top + arr[i]
// //��ô����ջ������������ݵ�ţ����ʱ��㼴Ϊ��
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

























/*ʮһ. ��̬�滮*/
//����DP

//������Ŀ�����:https://github.com/CSGrandeur/s-1problem1day1ac/discussions/552
//1.Bone Collector(0/1 ��������)
//dp[i][j] ��ʾ ����Ϊ j �ı���װǰ i ����Ʒ������ֵ
//ֻ�����ֲ�����װ�벻װ�� i ����Ʒ
//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i])
//���ư棺
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
//             for(int j = 0; j <= v; j++)//j = 0 ��ʾ�ձ���
//             {
//                 if(vol[i] > j) dp[i][j] = dp[i - 1][j];//�� i ����Ʒװ���£�ֻ��������һ��״̬
//                 else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i]);//��װ��ȡ��������������
//             }
//         cout << dp[n][v] << '\n';
//     }
//     return 0;
// }
//���仯�棺
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
//����Ϊѹ���ռ�ļ��ɣ�
//*��������(�����м�ת��״̬��ֻ�����������������ת�Ʒ���)
//1.�������
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
//             for(int j = 0; j <= v; j++)//dp[i][] ֻ�� dp[i - 1][] �йأ���ֻ��Ҫ�������鸴�ü���
//             {
//                 //����Ҳ������������� vol[i]��ʡȥ�ж�
//                 if(vol[i] > j) dp[i & 1][j] = dp[(i & 1) ^ 1][j];//(i & 1) ^ 1 �� i & 1 �� 1 ���, i & 1 ��ʾ��״̬��(i & 1) ^ 1 ��ʾ��״̬
//                 else dp[i & 1][j] = max(dp[(i & 1) ^ 1][j], dp[(i & 1) ^ 1][j - vol[i]] + val[i]);
//             }
//         cout << dp[n & 1][v] << '\n';
//     }
//     return 0;
// }
//*2.���ҹ���(�ص������һά�������������ֹ�������õľ�״̬)
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
//             for(int j = v; j >= vol[i]; j--)// vol[i] > j ʱװ���£�������״̬��������
//                 dp[j] = max(dp[j], dp[j - vol[i]] + val[i]);
//         cout << dp[v] << '\n';
//     }
//     return 0;
// }



//2.Common Subsequence
//���������01 10 11
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
//     while(cin >> a >> b)//*����cin���Զ��ж��Ƿ񵽴�EOF�����Բ����� !(cin >> a >> b).eof() ���ж��Ƿ񵽴�EOF����WA��
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
//��ͬ��������ͬд������ʱ�� 32ms �Ż��� 0ms
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



//*3.Longest Ordered Subsequence(������� LIS - Longest  Increasing Subsequence - �����������)
//���淽�� - O(n^2)
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
//     for(int i = 1; i <= n; i++)//�� i ����Ϊ��������е����һ��Ԫ��
//     {
//         dp[i] = 1;
//         for(int j = 1; j < i; j++)
//             if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);//dp[j] + 1 ��ȡǰ j ��������м��ϵ� i ��Ԫ��
//         res = max(res, dp[i]);
//     }
//     cout << res;
//     return 0;
// }
//* ���� + ̰��(�������취) - O(nlogn) - ��д����� 4 ����ȽϺ� 
// ��������� cnt �������򼯺ϣ�����������,�õ��Ĳ���LIS,Ҳ����ʵ��������������У����� ��������Сֵ�����򼯺� -- �������,����� 4 ��
// ��Ȼ��LIS���� = ����������ȣ��������ݺܿ��ܲ���ͬ
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
//         if(x > lis[cnt]) lis[++cnt] = x;//�ϸ����, >
//         else *lower_bound(lis + 1, lis + 1 + cnt, x) = x;
//     }
//     cout << cnt;
//     return 0;
// }
//��״�����Ż� - O(nlogn)





//4.��������ϵͳ(LIS����)
//����ɢ��ͼ�����������������������������Ϊ k��������ϵͳ����Ҫ�� k �����������ٻ���һ������ϵͳ��ȡ��������������� 2 ������
//����֤������������� k����������ϵͳ���ٸ���
/*
�����������򼯺ϣ��� 9 8 389 207 155 300 299 170 158 65 --> {8}��{389��207��155��65}��{300��299��170��158} --> ��������
ÿ�����ϵ���СԪ���༯�������γ�һ�������� {8, 65, 158}��������Ԫ�ؼ��룬���������ж� �ӳ� �� ����������ͷ(���÷�����СԪ��)
��ô ��������ĳ��� �� ������ �������������е��ܸ������� LIS���� = ����������ȣ� �����ݲ�һ����ͬ
������̣�
��> {8} // ��ʼ״̬��a�����ֵ��[8], k=1
��> {8} ��{389} // ��8������������a�����ֵ��[8, 389], k=2
��> {8} ��{389��207} // ��8������������a�����ֵ��[8, 207], k=2
��> {8} ��{389��207��155} // ��8������������a�����ֵ��[8, 155], k=2
��> {8} ��{389��207��155} ��{300} // ��207��155������������a�����ֵ��[8, 155, 300], k=3
��> {8} ��{389��207��155} ��{300��299} // ��207��155������������a�����ֵ��[8, 155, 299], k=3
��> {8} ��{389��207��155} ��{300��299��177} // ��155������������a�����ֵ��[8, 155, 177], k=3
��> {8} ��{389��207��155} ��{300��299��177��158} // ��155������������a�����ֵ��[8, 155, 158], k=3
��> {8} ��{389��207��155�� 65} ��{300��299��177��158} // ��8������������a�����ֵ��[8, 65, 158], k=3
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
//���� + ̰��(д���������е㲻ͬ)
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
//         int x, len = 0;//��������ĳ��� - 1
//         vector<int> lis(n + 1, MAXH);//ά���õ��������(������������LIS)
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


//�߶��� -- O(nlogn) -- ���















//5.�༭����
//dp[i][j]����Ϊ�ַ���A 1~i�Ӵ�ת��Ϊ B 1~j�Ӵ������ٲ�����
//��Aת����B���ֶ�A����
//״̬ת�ƶ����� A ���ĵ� i ���ַ� ca �� B���ĵ� j ���ַ� cb
//ɾ��ca dp[i - 1][j] + 1 ; 
//����cbʹ�������Ӵ�β����ͬ����ʱ�൱��ɾ��cb������ j - 1 ״̬���� dp[i][j - 1] + 1
//��ca!=cb, �滻 ca Ϊ cb���൱��ͬʱɾ�� ca �� cb dp[i - 1][j - 1] + 1
//��ca==cb, dp[i - 1][j - 1]
/*���õĽ��
�ַ���A("xyzab")���ַ���B("axyzc")�������پ������ٲ��������԰�A���B��

���ǻ��Ǵ������ַ��������һ���ַ������켴'b'��'c'����Ȼ���߲���ͬ����ô�������������ִ���취��
(1)���ӣ���Aĩβ����һ��'c'����ôA�����"xyzabc"��B��Ȼ��"axyzc"�����ڴ�ʱĩβ�ַ���ͬ�ˣ���ô�ͱ���˱Ƚ�"xyzab"��"axyz"�ľ��룬��dp(xyzab,axyzc) = dp(xyzab,axyz) + 1��
   ����д�� dp(i,j) = dp(i,j - 1) + 1����ʾ�´αȽϵ��ַ���B�ĳ��ȼ�����1������1��ʾ��ǰ������һ���ַ��Ĳ�����

(2)ɾ����ɾ��Aĩβ���ַ�'b'������Aʣ�µĲ�����B�ľ��롣��dp(xyzab,axyzc) = dp(xyza,axyzc) + 1��
   ����д��dp(i,j) = dp(i - 1,j) + 1����ʾ�´αȽϵ��ַ���A�ĳ��ȼ�����1��

(3)�滻����Aĩβ���ַ��滻��'c'����������B��ĩβ�ַ�һ���ˣ���ô��������
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
//     for(int i = 1; i < alen; i++) dp[i][0] = i;//��ʼ���մ�״̬
//     for(int i = 1; i < blen; i++) dp[0][i] = i;
//     for(int i = 1; i < alen; i++)
//         for(int j = 1; j < blen; j++)
//             dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (a[i] != b[j]));
//     cout << dp[alen - 1][blen - 1];
//     return 0;
// }



//6.��ѩ
//ʵ���Ͽ��Լ��仯�������˴��� dp ���첻��
//���Ǳ���ʹ��dp�Ļ����ص����ڴ����޺�Ч�ԣ������������ݸ߶������ɵ͵���������⣬ʹ�øߵ�ֱ��ʹ�õ͵�������
//dp[i][j] ����Ϊ �� i ���� j ����ϸ��������
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



//7.��������ţ
//91�֣�TLEһ����
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
//dp[i] ����Ϊ����㵽 i ��ʱ�ɻ��������������
//������˵� x��ÿ��ȡһ��[x, y]����Ϊ���նΣ��ۻ� y - x + 1 ���ȣ������� 1 ~ (x - 1) �ε���γ���(last)����Ϊ��ǰ���״̬dp[y]
//״̬�洢��dp[y]ʹ��ֻ�е� x ���ڸô� y ʱ����ʹ�����ֵdp[y]����ʱ��� y �� x �������Ϊ��״̬
//last�洢ǰ������������ֵ
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
//��ȫ�������� -- ͬһ��Ʒ�����ظ�ʹ�û���˵�����޸�
//������Ƚ����⣬Ҫ�����װ������
//dp[i] ����Ϊ ����Ϊ i ʱ������������ֵ,���������ȫ��������װ���������޽�������ղ��� i (����Ϊ dp[i] < 0)������� dp[0] �Ľ���� 0
//ֻ��������Ч���״̬����ת�Ʋ�����ȷװ������
//�簸�� 918 102 1327 1733 ����dubug��ת�Ʒ��̼������
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
//     memset(dp, -2, sizeof dp);//��ʼ״̬Ϊ�޽⣬-16843010
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



//10.�ϳ�����
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
//     for(int i = 1; i <= n; i++)//�����ϸ�����������
//     {
//         dp1[i] = 1;
//         for(int j = 1; j < i; j++)
//             if(arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
//     }
//     for(int i = n; i >= 1; i--)//�Ҳ���ϸ��½�������
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




//��������
//�����Ž���https://github.com/CSGrandeur/s-1problem1day1ac/discussions/554

//1.Bone Collector
//01��������
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



//2.���Ĳ�ҩ
//��ȫ��������
/*
��ʽ�ϣ�����ֻ��Ҫ�� 01 ��������ġ�һά�ռ��Ż����ⷨ�еġ�����ά�ȡ���������ӡ��Ӵ�С ��Ϊ ��С���󡹾Ϳ��Խ����ȫ�������⡣
����������Ϊ���߽���״̬ת��ʱ�����˲�ͬ�ĸ��ӣ�
 01���� �������ǡ���һ�����Ϸ��ĸ��ӡ��͡���һ����ߵĸ��ӡ���
��ȫ���� �������ǡ���һ�����Ϸ��ĸ��ӡ��͡�������ߵĸ��ӡ���
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
//         for(int j = T[i]; j <= t; j++)//�����������װ�뱳�������ϱ�ɾ�״̬�����ã���ǰ��ļ������Ե��ӵ���״̬��С��������װ��󱳰���
//             dp[j] = max(dp[j], dp[j - T[i]] + val[i]);
//     cout << dp[t];
//     return 0;
// }



//3.����ɸѡ
//���ر������� -- һ����Ʒ����ѡ���������ͬ��Ʒ�в�ͬ��ѡ������

//һ����ת��Ϊ 01���� -- ö�� k ����Ʒ�������⿴�ɽ���һ����ռ�ÿռ�Ϊ k*Vi ����ֵΪ k*Wi ����Ʒ�ò�����
//���Ż�(������ߺ�ʱ922ms)
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

//�������Ż�(�����) -- һ����һ������ sum ����Ʒ����ֳ� x ����Ԫ������ x ����Ԫ��� 1 ~ sum ���е�ȡ������� (������ߺ�ʱ141ms) -- �Ż�Ч������
// �Ȱ� 2 �ı���������Ϊ x - 1 ���������ʣ��һ���������� x ��������
// �� sum = 25���ֳ� 1, 2, 4, 8, 10(10 < 2^4 = 16) �����Ԫ�������� 5 ��������������ϵõ� 1 ~ 25 ����������
// ���ر������� ��ת���ɶ� ÿ����Ʒ �� ÿ����Ԫ�� �� ѡ�벻ѡ���� 01��������
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int MAXN = 1e6 + 5;//����һ��Ҫ����
// int n, m, dp[MAXN];
// struct nd{
//     int v, w;
// }goods[MAXN];//�洢һ����Ʒ�ֳɵ����ɸ�01�������涨��[1, cnt]
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++)//����ÿ����Ʒ
//     {
//         int v, w, sum, cnt = 0;
//         cin >> v >> w >> sum;
//         //�����Ʊ���ö�ٲ��
//         for(int j = 1; j <= sum; j <<= 1)
//         {
//             goods[++cnt] = nd{v * j, w * j};
//             sum -= j;//��ȥ�Ѳ��
//         }
//         //���һ������ ����
//         if(sum) goods[++cnt] = nd{v * sum, w * sum};
//         //01���� -- ÿ����Ʒ�ֳ����ɸ� 01����
//         for(int k = 1; k <= cnt; k++)
//             for(int j = m; j >= goods[k].w; j--)//����
//                 dp[j] = max(dp[j], dp[j - goods[k].w] + goods[k].v);
//     }
//     cout << dp[m];
//     return 0;
// }
//���������Ż�(���ź�ʱ)











//������ת��Ϊ 01���� + ��ȫ���� (3.8s΢С�Ż���*�����������ֱ��������*)
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
//         if(sum * w >= W)//��ȫ����,���������Ϊ W �ı�����˵����ʱ v �����൱�ڿ�������ѡȡ�������õ��ĳ���
//         {
//             for(int j = w; j <= W; j++)
//                 dp[j] = max(dp[j], dp[j - w] + v);
//         }
//         else
//         {
//             for(int j = W; j >= w; j--)//01�����������������
//                 for(int k = 1; k <= sum && k * w <= j; k++)//�ò����˳��Ӱ����
//                     dp[j] = max(dp[j], dp[j - k * w] + k * v);
//         }
//     }
//     cout << dp[W];
//     return 0;
// }



//4.NASA��ʳ��ƻ�
// ��ά���õı�������
// ָ����ÿ����Ʒ���������ֲ�ͬ�Ŀռ�ķѣ�ѡ�������Ʒ����ͬʱ���������ִ��ۡ�
// ����ÿ�ִ��۶���һ���ɸ��������ֵ ��������������������ѡ����Ʒ���Եõ����ļ�ֵ��
// ����ÿ����Ʒֻ��ѡһ�Σ��������Ǹ� ��ά01��������
// ���� dp[i][j][k] Ϊ�������� i ����Ʒʱ��������� j������������ k �����·��ֵ
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
//��ʱ,"��ά����" ��������������һ�������ķ�ʽ�����ģ����ֻ��ȡ U ����Ʒ��
//����ʵ�������ÿ����Ʒ����һ�� "����" �ķ��ã�ÿ����Ʒ�ļ������þ�Ϊ 1�����Ը���������������Ϊ U��



//5.ͨ��֮���鱳��
//���鱳������ -- �����ϣ�����ÿ����Ʒ����� 01�������⣬�ֿ��Գ�Ϊ ����01��������
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
//     for(int i = 1; i <= ind; i++)//����
//         for(int j = m; j >= 0; j--)//01�������⣬���������������ۣ�
//             for(auto x : goods[i])//����������Ʒ����
//                 if(j >= x.w)
//                     dp[j] = max(dp[j], dp[j - x.w] + x.v);
//     cout << dp[m];
//     return 0;
// }



//6.������Ԥ�㷽��
// һ�������������ɸ�������Ϊ���鱳���е�һ����Ʒ�飬��Ϊ �������ķ��鱳������ -- �����Ա����ڸ���ѡ���ǰ������ѡ����
// ���ǿ��Խ�ÿ����������һ��01�������⣬���������Ǹ�һ������������ټ�Ǯ��ʱ��
// �Ϳ���֪����ʱ����������丽���ڶ�Ӧ�ļ�Ǯ���Ի�õ�����ֵ��
/*
������
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
//�ȴ�������ֵ״̬�����������м��븽�� (230 ms)
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
//     n /= 10;//���͸��Ӷ�
//     vector<nd> goods[m + 1];//goods[0]Ϊ�����飬1 ~ m Ϊ������
//     vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
//     for(int i = 1; i <= m; i++)
//     {
//         int v, p, q;
//         cin >> v >> p >> q;
//         goods[q].push_back(nd{v / 10, p, i}); 
//     }
//     //dp[i][j]��ʾ���� i ���������� j Ǯ��������ֵ
//     for(int i = 1; i <= m; i++)//*��������
//         for(auto x : goods[i])//������Ʒ(����)
//             for(int j = n; j >= x.v; j--)//��������
//                 dp[i][j] = max(dp[i][j], dp[i][j - x.v] + x.v * x.p * 10);
//     //��������������������ռ䣬������ֵ�ж��Ƿ�������
//     for(int i = 0; i < goods[0].size(); i++)
//     {
//         nd base = goods[0][i];
//         for(int j = n; j >= base.v; j--)//���������Ĵ���
//             for(int k = j - base.v; k >= 0; k--)//�������븽���Ĵ���
//                 dp[0][j] = max(dp[0][j], dp[0][j - base.v - k] + base.p * base.v * 10 + dp[base.pos][k]);
//     }
//     cout << dp[0][n];
//     return 0;
// }

//ʵ����Ҳ���Ե����� 5 �ֲ����� 01������д (38 ms)
//| 1.���� | 2.ֻ������ | 3.���� + ����1 | 4.���� + ����2 | 5.���� + ����1 + ����2 |
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// int n, m, v[65][3], p[65][3];//v[i][j] �� i ����Ʒ���� j = 0��Ϊ�������� j = 1, 2 Ϊ���� 1��2
// //��Ʒ��ֵ����Ϊ v * p��ֱ�ӽ�ԭֵ����p������
// int main()
// {
//     untie();
//     cin >> n >> m;
//     n /= 10;//���͸��Ӷ�
//     vector<int> dp(n + 1, 0);
//     for(int i = 1; i <= m; i++)
//     {
//         int a, b, grp;
//         cin >> a >> b >> grp;
//         if(grp) v[grp][2 - !v[grp][1]] = a / 10, p[grp][2 - !p[grp][1]] = a * b;//����1λ��δռ�þʹ���λ��1����ռ�þͻ����λ��2
//         else v[i][0] = a / 10, p[i][0] = a * b;
//     }
//     for(int i = 1; i <= m; i++)
//         for(int j = n; j >= v[i][0]; j--)
//         {
//             dp[j] = max(dp[j], dp[j - v[i][0]] + p[i][0]);//���1, 2
//             if(j >= v[i][0] + v[i][1]) dp[j] = max(dp[j], dp[j - v[i][0] - v[i][1]] + p[i][0] + p[i][1]);//3
//             if(j >= v[i][0] + v[i][2]) dp[j] = max(dp[j], dp[j - v[i][0] - v[i][2]] + p[i][0] + p[i][2]);//4
//             if(j >= v[i][0] + v[i][1] + v[i][2]) dp[j] = max(dp[j], dp[j - v[i][0] - v[i][1] - v[i][2]] + p[i][0] + p[i][1] + p[i][2]);//5
//         }
//     cout << dp[n];
//     return 0;
// }

//Ҳ������Ϊ����������α������� (���Ϊ 2)



//7.Bone Collector II
//��� k �Ž�(�� k ���ֵ)
// ��ԭ�� 01���� �Ļ������ڼ�һά��¼���ɣ��� dp[i][j][k] - �������� i ����Ʒ������������� j ʱ�ɵõĵ� k ���ֵ
// ��Ȼ���Թ�������һά��ʣ�� dp[j][k]
//a�����¼���� ��ѡ�� i ����Ʒ �� k ������ֵ
//b�����¼���� ѡ�� i ����Ʒ �� k ������ֵ
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
//                 //���a, b
//                 for(int m = 1; m <= k; m++)
//                 {
//                     a[m] = dp[j][m];
//                     b[m] = dp[j - vol[i]][m] + val[i];
//                 }
//                 //�ϲ�a, b ȡ�ϴ��ߴ��� dp
//                 for(int m = 1; m <= k && (a[ai] != -1 || b[bi] != -1); )//�൱�ڴ� 2*k ���������ȡǰ k ����
//                 {
//                     dp[j][m] = a[ai] > b[bi] ? a[ai++] : b[bi++];
//                     if(dp[j][m] != dp[j][m - 1])//���⣺���ֲ�ͬ�����õ���ͬ��ֵ������ͬһ���֣���ȥ���ظ������޸���������ȥ���þ伴��
//                         m++;//���ظ�˵���ý�ռ����Ч
//                 }
//             }
//         }
//         cout << dp[v][k] << "\n";
//     }
//     return 0;
// }



//8.Ͷ�ʵ����Ч��
//���似�ɽ���ʱ�ո��Ӷȣ����� a �� 1000 �ı������Ǿ�ȫ���� a /= 1000 ����
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



//9.ӣ��
//��ϱ�������
//��ʵ�����������������Ҷ������Ż����ر��� (55ms)
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
//         if(p == 0 || t * p >= T)//��ȫ����
//         {
//             for(int j = t; j <= T; j++)
//                 dp[j] = max(dp[j], dp[j - t] + c);
//         }
//         else if(p == 1)//01����
//         {
//             for(int j = T; j >= t; j--)
//                 dp[j] = max(dp[j], dp[j - t] + c);
//         }
//         else//���ر���
//         {
//             int cnt = 0;
//             for(int j = 1; j <= p; j <<= 1)
//             {
//                 arr[++cnt] = nd{t * j, c * j};
//                 p -= j;
//             }
//             if(p) arr[++cnt] = nd{t * p, c * p};
//             for(int k = 1; k <= cnt; k++)//תΪ01����
//                 for(int j = T; j >= arr[k].t; j--)
//                     dp[j] = max(dp[j], dp[j - arr[k].t] + arr[k].c);
//         }
//     }
//     cout << dp[T];
//     return 0;
// }

//ȫ��ת��Ϊ01�������ö������Ż�(77ms)
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
//         if(!p) p = T / t;//��ȫ���������޴�תΪ��Ч��������
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

//��ɵ��������Ż�



//10.ACboy needs your help
//���鱳��
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



//11.Acwing 12	������������巽��
//������������巽������Ҫ���ֵ�����С(̰��)







//״ѹdp
//1.P8687 [���ű� 2019 ʡ A] �ǹ�
//״ѹdp�������ÿ���ǹ�������ȡ�벻ȡ����״̬�����ö����ơ��� 0110 ��ʾ�ڶ��������ǹ�ȡ��������ȡ
//dp[i] ����Ϊ�õ���� i �������ٰ��������õ�ȫ���ǹ������Ϊ (1 << m) - 1 ��������ÿ����λ��Ϊ 1���ʴ�Ϊ dp[(1 << m) - 1]
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e6 + 10;
// int a[105];
// int dp[N];
// int main()
// {
//     int n, m ,k;
//     cin >> n >> m >> k;
//     memset(dp, -1, sizeof(dp));
//     for(int i = 1; i <= n; ++i)
//     {
//         int now = 0;
//         for(int j = 1; j <= k; ++j)
//         {
//             int t; cin >> t;
//             now |= (1 << (t - 1));
//         }
//         dp[now] = 1;//��ʼ���������һ��
//         a[i] = now;
//     }
//     for(int i = 1; i <= n; ++i)//����� i ��
//     {
//         for(int j = 0; j <= (1 << m) - 1; ++j)//ö���������
//         {
//             if(dp[j] == -1) continue;
//             int to = j | a[i];//������ i �����¸�״̬Ϊ to
//             if(dp[to] == -1) dp[to] = dp[j] + 1;//���δ����ϳ�������ϣ�ֱ�Ӵ���� j ���ϵ� i ��
//             else dp[to] = min(dp[to], dp[j] + 1);//�����Ϲ�����ȡ��С��
//         }
//     }
//     cout << dp[(1 << m) - 1];
//     return 0;
// }

















//��������dp ��ϰ
//1.P8707 [���ű� 2020 ʡ AB1] �߷���
// #include <iostream>
// using namespace std;
// const int N = 100;
// int dp[N][N];
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     dp[1][1] = 1;
//     for(int i = 1; i <= n; ++i)
//     {
//         for(int j = 1; j <= m; ++j)
//         {
//             if(i & 1) dp[i][j] += dp[i][j - 1];
//             if(j & 1) dp[i][j] += dp[i - 1][j];
//         }
//     }
//     cout << dp[n][m];
//     return 0;
// }



//2.P8786 [���ű� 2022 ʡ B] ��״�Ƽ�ǿ��
//��ʼ�о� 2 ��������ӱ���0 ���Ƽӱ�Ҳ�ǺϷ��ģ��������� 1 ����0 �����������Ϸ�������֪���һ���������ǻ�������ǡ�ðѾƺ��ꡣ
//�ʵ����� n �ε꣬m �λ�������һ·��������ͻ���˳���ж��ٲ�ͬ�Ŀ��ܡ�
//��֪�����Ĵ�С���Ϊ m���뻨����ͬ�������� dp[i][j][k] ״̬Ϊ������ i �ҵ�� j �仨��ʣ���� k ���Ƶķ�����
//������Ϊ����������һ�αض�����������������Ϊż��������һ�ο��������꣬Ҳ������������
//��Ϊ�涨���һ�������ı����ǻ���������ǰǡ��ʣ 1 ���ƣ���Ϊ dp[n][m - 1]����Ϊ dp[n][m][0] ���޷���֤���һ���������ǻ���
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 150, mod = 1e9 + 7;
// ll dp[N][N][N];
// int main()
// {
//     ll n, m;
//     cin >> n >> m;
//     dp[0][0][2] = 1;//��ʼ�� 2 ����
//     for(int i = 0; i <= n; ++i)//��������
//     {
//         for(int j = 0; j <= m; ++j)//��������
//         {
//             if(i == 0 && j == 0) continue;
//             for(int k = 0; k <= m; ++k)//��������
//             {
//                 if(k & 1) dp[i][j][k] = j ? dp[i][j - 1][k + 1] : 0;
//                 else dp[i][j][k] = (j ? dp[i][j - 1][k + 1] : 0) + (i ? dp[i - 1][j][k / 2] : 0);
//                 dp[i][j][k] %= mod;
//             }
//         }
//     }
//     cout << dp[n][m - 1][1] % mod;
//     return 0;
// }



//3.P8784 [���ű� 2022 ʡ B] ��ľ��w
//��һ�������СΪ 2 * n �Ļ��������� 2 * n �� 1 * 1 �Ŀ鹹�ɡ�����Ҫ�� I�ͻ�ľ �� L�ͻ�ľ ����������
//���ܹ��ж����ֲ�ͬ�Ĵ��䷽������ľ����������ת��
//�� dp[n][3]����ÿһ�е��������������� dp[i][0]��dp[i][1]��dp[i][2] ��ʾ�� i ����������������˵���»�ľ����ͬ���������ϸ񡢽����¸�ķ�����
//dp[i][0]��ת������״̬��dp[i][1] �� dp[i][2] ��������
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e7 + 10, mod = 1e9 + 7;
// int n;
// int dp[N][3];//�� long long ��ը�ռ�
// int main()
// {
//     cin >> n;
//     dp[0][0] = 1;//��ʼ����һ�ж���û���ʱ�ڶ�ά�� 0 ��ʾ���»�ľ����ͬ
//     for(int i = 1; i <= n; ++i)
//     {
//         //ע��� i - 2 Խ��
//         dp[i][0] = ((dp[i - 1][0] + (i >= 2 ? dp[i - 2][0] : 0)) % mod + (dp[i - 1][1] + dp[i - 1][2]) % mod) % mod;
//         dp[i][1] = (dp[i - 1][2] + (i >= 2 ? dp[i - 2][0] : 0)) % mod;
//         dp[i][2] = (dp[i - 1][1] + (i >= 2 ? dp[i - 2][0] : 0)) % mod;
//     }
//     cout << dp[n][0] % mod;
//     return 0;
// }



//4.P8725 [���ű� 2020 ʡ AB3] ����Ư��
#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    return 0;
}
















































/*ʮ��. ͼ�ۻ���, ��������, ��С������*/
/*
����:
���㣨Vertex����ͼG�е�����Ԫ�س�Ϊ���㡣һ���������������㡣

����ͼ����ͼG�е�ÿ���߶���û�з���ģ����ͼGΪ����ͼ��

����ͼ����ͼG�е�ÿ���߶����з���ģ����ͼG������ͼ��

����������ߡ��ߵ��յ㱻��Ϊ��ͷ����ʼ�㱻��Ϊ��β��

�ȣ�degree����һ������ĶȾ�����ö���������ıߵ���Ŀ��

���ȣ�����ͼ�У����������ӵĳ��ߵ�������

��ȣ�����ͼ�У����������ӵ���ߵ�������

��������һ��ֻ�е�һ�������һ�������ظ��ķǿ�·����

�����޻�ͼ���ֳ�DAGͼ����û�л�������ͼ��DAGͼ�Ƕ�̬�滮�ͼ��仯�����Ľṹ������

��ͼ��Subgraph������ͼ�в��ֽڵ��Լ���Щ�ڵ��ı���ɵ�ͼ��

��ͨͼ��Connected Graph������ͼG�е������������u��v�����u����v�໥�ɴ���ͼG����ͨͼ��

��ͨ������Connected Component�������ڵ�����ٴ���һ���߿�����ͨ��

��: �������޻���ͨͼ����������������ɵļ��ϳ�Ϊɭ�֡�����n�������n-1���ߵ���ͨͼ�������ĳ�Ҫ������
    ���һ��������ͨͼ��������·(��ͨͼ�в����ڻ�)����ô����һ������

��������������ͨͼȫ�����㲢��n-1���ߵ���ͨ��ͼ��

�ڽӾ���: ��ν������ʵ���Ƕ�ά���顣������n�������ͼ G=(V,E) ��˵�����ǿ�����һ�� n��n �ľ��� A ����ʾ G �и���������ڹ�ϵ
         ����� i �� �� j ֮����ڱ�(��)���� A[i][j] = 1������ A[i][j] = 0��һ��ͼ���ڽӾ�����Ψһ�ģ�����Ĵ�Сֻ�붥�����N�йء�

�ڽӱ��ڽӱ��˼���ǣ�����ͼ�е�ÿһ�����㣬��һ����������¼��������Щ���������������ڵĵ�ᶯ̬����ӣ����Զ���ÿ���㣬������Ҫ��vector����¼��

*/
//�ڽӾ��� gra[N][N]��gra[i][j]��ʾ��(i, j)��Ȩֵ����Ϊ��Ȩ�ߣ����� 1 ��ʾ�бߣ����� 0 ��ʾ�ޱ�

//*�ڽӱ�
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 +5;// N ����
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
//     cin >> n >> m;                                  //n���㣬m����
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         e[u].push_back(edge{u, v, w});
//     }
//     //�������ڵ�������ھ�
//     for(int u = 0; u <= n; u++)
//     {
//         if(e[u].empty()) continue;
//         cout << "node " << u << " 's neighbours: ";
//         // for(int i = 0; i < e[u].size(); i++)
//         for(auto v : e[u])
//         {
//             cout << v.to << " ";//��ͬ����ʽǰ���ǣ�����ᰴ����˳�����
//         }
//         cout << '\n';
//     }
//     return 0;
// }

//*��ʽǰ����
//1.�ڵ��ŷ�ΧΪ 0 ~ n - 1
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e3 + 5, M = 2e3 + 5;                 //NΪ���������MΪ������
// int n, m, head[N], cnt = 0;                         //head[u]ָ�� u ��һ���ھ���edge[]�еĴ洢λ�� �� ���� u �����һ����(��¼��˳��������), cnt��¼��ǰ�ɴ洢λ��
// struct node{
//     int from, to, next;                             //fromΪ�ߵ����(һ�㲻��Ҫ)��toΪ�ߵ��յ㣬nextΪ u ����һ���ھ�
//     int w;                                          //��Ȩ
// }edge[M];
// void init()
// {
//     for(int i = 0; i < N; i++) head[i] = -1;        //���ʼ��
//     for(int i = 0; i < M; i++) edge[i].next = -1;   //�߳�ʼ��
//     cnt = 0;
// }
// void addedge(int u, int v, int w)
// {
//     edge[cnt] = node{u, v, head[u], w};
//     //edge[cnt].next = head[u] ����¼��λ�ô��𣬶���ͬһ����� u�������Ǵ����¼���λ����������¼���λ���Ա��������ھ�
//     head[u] = cnt++;
// }
// int main()
// {
//     untie();
//     init();
//     cin >> n >> m;                                  //n���㣬m����
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         addedge(u, v, w);
//     }
//     //�������ڵ�������ھ�
//     for(int u = 0; u <= n; u++)
//     {
//         if(!~head[u]) continue;
//         cout << "node " << u << " 's neighbours: ";
//         for(int i = head[u]; ~i; i = edge[i].next)//~i = -(i + 1) �������൱�� i != -1
//             cout << edge[i].to << " ";
//         cout << '\n';
//     }
//     return 0;
// }
//2.�ڵ��ŷ�ΧΪ 1 ~ n������Ϳ����� 0 ��ʾ�գ������� -1��ʡȥ init() ����
//�򻯰�
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
//     //�������ڵ�������ھ�
//     for(int u = 0; u <= n; u++)
//     {
//         if(!head[u]) continue;
//         cout << "node " << u << " 's neighbours: ";
//         for(int i = head[u]; i; i = edge[i].next)//��Ϊ 0
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


//��������
/*
���
    ��һ�������޻�ͼ(Directed Acyclic Graph���DAG)G�������������ǽ�G�����ж����ų�һ���������У�
    ʹ��ͼ������һ�Զ���u��v������<u,v>��E(G)����u�����������г�����v֮ǰ��
    ͨ�����������������г�Ϊ�������˴���(Topological Order)�����У�����������С�
    �򵥵�˵����ĳ�������ϵ�һ��ƫ��õ��ü����ϵ�һ��ȫ�����������֮Ϊ��������
    ���ȣ�����ͼ�У����������ӵĳ��ߵ�������
    ��ȣ�����ͼ�У����������ӵ���ߵ�������
?�򵥵�˵����һ������ͼ�У������еĽڵ��������Ҫ��û��һ���ڵ�ָ����ǰ��Ľڵ㡣��ǰ����ͼ�������޻�ͼʱ�����������н⣬������л���
���򷽷���
    ����BFS��
        1.��ǰ���Ķ������ȣ������Ϊ 0 �ĵ㿪ʼ������
        2.�޺�̵Ķ������ȣ��ӳ���Ϊ 0 �ĵ����ƣ�����
    ����DFS��

��ǰ���Ķ������ȷ���ʵ�ֲ��裺
    1.��ͳ�����нڵ����ȣ����������Ϊ 0 �ĵ����
    2.������ʱ���Ϊ 0 �ĵ� u������ָ������нڵ����ȼ� 1��������� u
    3.һֱ�ظ��ò�����ֱ�����еĽڵ�ȫ�������
    4.�����󲻴������Ϊ0�Ľڵ㣬�Ǿ�˵���л�����������������Ҳ���Ǻܶ���Ŀ���޽�������

������������
1.�������������������һ�����Ԫ��Ϊ���б����С��Ԫ�أ���������� �ֵ�����С ����������
2.���������������������ȼ�Ҫ�󣩣�������ͼ��һ�����Ԫ��Ϊ���б������Ԫ�أ���������� �������ȼ�Ҫ�� ����������(�跭ת���) ���� �����ֵ���������
*/
//һ��д�� - ��(1 ~ n)
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <functional>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5;
// int indegree[N];//��¼ÿ��������
// int n, m;//n ���㣬 m ����
// queue<int> q;//��ʱ���Ϊ 0 �ĵ㼯
// //������ֵ�����С����������������У�����Ҫ���ȶ��� priority_queue<int> q;
// vector<int> edge[N], ans;//ans Ϊ��������
// void bfs()
// {
//     //��ʼ������ -- ���Ϊ 0 �ĵ�
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

//1.ȷ����������
//Ҫ�����ʱ���С�Ķ�����ǰ���� queue ����Ϊ ���ȶ��У����Ᵽ֤�������д��ڡ�
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



//*2.����
//*������������ + ���ȶ���
/*
//�Ϻõ���⣺https://blog.csdn.net/u012861385/article/details/38059515
������������ Ӧ���ڣ���Ŀ�ڻ�������������Ļ�������������һ��Ҫ�󣺱����С�Ľڵ�Ҫ��������ǰ�棻��������һ�������Ļ����ϣ���ŵڶ�С�Ľڵ�Ҫ��������ǰ�棻
                   ������ǰ���������Ļ����ϣ���ŵ���С�Ľڵ�Ҫ��������ǰ�桭���������ơ���ע�⣬����ֵ����������£������Ի�������
����Ҫ��**�������ֵ�����С**�����򽨱��������򽨱��ٵ������������ȷ�� ��ע���������б�֤���ڣ�
�簸��
5 4
1 4
4 2
5 3
3 2
���򽨱�Ĵ�Ϊ 1 4 5 3 2 �Ǵ���ģ�����ȷ��ӦΪ 1 5 3 4 2��
��Ϊʵ���ϴ���ͬ���ϵ����{1�� 5} {3�� 4} {2}������������� 1 5 3 4 2
�������򽨱�����ÿ��ȡ��С��ͷ���ܿ��ܻ�ȡ����ƽ�У�����ͬһ�㣩Ԫ�أ�������Υ���� ai �� bi �ȶ������ȼ���������̰���ǡ�Ŀ���ǳ���ġ�
������Լ����ƽ�е��������򣬶���������ƽ�е�·����С��ͷ����һ������ǰ�棬���Ǵ��β��һ�����ں��档��Ϊͷ�����ܵ�β����Լ��������β��û��Լ����
��ˣ������Ǵ�β���� 2 ��������ʱ������ {4��3}��ֻҪ����ÿ��ȡ���Ԫ�أ�����̰�ľ��ܱ�֤ƽ�й�ϵ�����ƻ���
ѡ�� 4 ������Ϊ 2 4������Ϊ{3��1}��ѡ�� 3 ������Ϊ 2 4 3������Ϊ{5�� 1}��������Ϊ 2 4 3 5 1
��������� 1 5 3 4 2
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
//             edge[v].push_back(u);//����ͼ
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




//ͼ�ۻ���
//1.ͼ�ı���
//����ͼ���ߵķ��򷴹��������Ӵ�С������
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



//2.�����ھ�
//Ѱ���Ƿ������Ϊ 0 ��Ψһ�㣬��������ھ���������
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





//��С������ Minimal Spanning Tree���б�Ȩ������ͼ���⣬���Եõ���ͨһ��ͼ�����ѵ���С����(��С��Ȩ��)��
/*
��һ��ͼ�� n ���㣬m ���ߣ�m >= n - 1��,��ͨһ��ͼ����Ҫ n - 1 ����
���
�������һ��������ͨͼ��������·(��ͨͼ�в����ڻ�)����ô����һ������
��������������ͼ�У���ͨ�Ҳ�����·�������ڻ�����һ����ͼ��������ȫ�� n ���� �� ���� n - 1 ���ߣ���Ϊһ����������
��С����������ͼ��ÿ���߶�����Ȩ��ʱ�����������ܴ��۾����������ÿ���ߵ�Ȩ�����֮�͡�
           ������ͨ����Ψһ�����ǳư���ȫ�� n ���㼰���� n - 1 ���ߣ������� ��СȨ��֮�� ��������Ϊ ��С��������MST����
������С������һ������ͼ��Ȩֵ��С�� n - 1 ���ߣ��ʿ���ʹ�� ̰�ķ� ����MST������ȫ�����Ű����ֲ����š�
���� ̰��˼�� ���㷨���������֣�
Kruskal�㷨��O(mlogm) -- �����ã�
    ִ�ж��󣺶� ͼ�����еı� ����̰��ѡ��
    ���ģ�ʹ�� ���鼯 �л�(O(m))��
    ʵ�ֹ��̣�
        1.�������еıߣ�����̱߿�ʼ
        2.ÿ��ѡ�б߼�����ʣ���Ȩֵ��С�ı�
        3.�жϸñ��Ƿ����ɻ��������ɻ������ Tree ��
        4.�ظ�����������ֱ�� Tree �ϰ������� n ���㣬������ n - 1 ������ͨ���е�
        5.cnt ͳ�Ʊ����Ƿ�Ϊ n - 1 �����Դ��ж��������ĺϷ���
    ����������򵥣��������鼯ʵ�֣����Ӷ���Ҫ��Դ��ʹ�� sort() �� m ���߽������򣬼� O(mlogm)
Prim�㷨��O(mlogn)
    ִ�ж��󣺶� �������ھ� ����̰��ѡ��
    ���ģ�������������BFS + ���ȶ��� O(mlogn)����״̬�����жϵ��Ƿ��Ѿ���MST�У�����������������ֹ�ɻ���
    ʵ�ֹ��̣�
        1.������� u ��ʼ������ Tree ��
        2.ÿ��ѡ�����ȶ����о��� Tree ������ھӵ� v�����뵽 Tree ��
        3.Ȼ�� v ��δ���������ھӵ㶼���������
        4.�ظ�����������ֱ�� Tree �ϰ������� n ���㣬������ n - 1 ������ͨ���е�
        5.cnt ͳ�ƶ������Ƿ�Ϊ n �����Դ��ж��������ĺϷ���
    �������������ǳ��ࣨ����ڵ�����ʱ�����ܷ������Ч�ԣ��ұ���ϸ���
*/
/*
//Kruskal�㷨ģ�壨���ã�
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
int ds[N];//���鼯�������ж� ��ȡ�ߵ������˵��Ƿ��Ѿ���ͨ �� �Ƿ�����ͬһ�����ϣ�������ȡ�ñ߻ᵼ�³ɻ����ʴ�ʱ��ȡ�ñߣ�
void init_set(){ for(int i = 1; i <= n; i++) ds[i] = i;}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
// void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];} //�ϲ��������赥��д
void kruskal()
{
    int ans = 0, cnt = 0;//ansΪȨֵ�ͣ�cnt��¼����MST����
    sort(edge + 1, edge + 1 + m);
    for(int i = 1; i <= m; i++)
    {
        if(cnt == n - 1) break;//С�Ż���MST���� n - 1 ����
        int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);//�жϵ� i ���ߵ����˵��Ƿ��Ѿ���ͨ
        if(e1 == e2) continue;//������ͨ��ʹ�øñ�
        else
        {
            ans += edge[i].w;
            ds[e1] = e2;//�ϲ�,�� ds[e1] = ds[e2] û������
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

//Prim�㷨ģ�� -- �����·��Dijkstra�㷨ʵ�ֹ������ƣ���������������Prim�㷨������µ�ǰ�������е㵽���ľ���
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
const int N = 5e3 + 5, M = 2e5 + 5;
int n, m;
struct edge{
    int to, w;//�ߵ��յ��Ȩֵ
};
struct node{
    int id, dis;//�յ�ı�� �� ���õ��Ȩֵ
    bool operator < (const node &x) const{ return dis > x.dis;}//ʹ���ȶ��еĶѶ�Ϊ��Сֵ
};
vector<edge> G[N];//�� G[u.id].to = v ����ʾ�� u -> v
bool vis[N];//��¼���Ƿ��Ѿ��� MST ��
void prim()
{
    //memset(vis, 0, sizeof vis);
    int s = 1;//������㿪ʼ�������ӵ� 1 ��ʼ
    int ans = 0, cnt = 0;//cnt��¼MST�ϵĶ�����
    priority_queue<node> q;
    q.push(node{s, 0});
    while(!q.empty())
    {
        node u = q.top(); q.pop();
        if(vis[u.id]) continue;//��ȥ����MST�ϵĵ㣬��ֹ�ɻ�
        vis[u.id] = 1;
        ans += u.dis;//�ۼ�Ȩֵ
        ++cnt;
        for(auto v : G[u.id])//������ u ���ھӵ� v
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
        G[v].push_back(edge{u, w});//˫���
    }
    prim();
    return 0;
}
*/


//1.��æ�Ķ���
//���⣺��֤���ݽ����е���ͨ�����������٣����Ȩֵ�ߵ�Ȩֵ����С��ѡ������Ȩֵ��С����ͼ��˫��ߡ�
//ת�壺����������ͨͼ���ʣ������뵽��������С��������Ҫ����� ���� �� ��󵥱�Ȩֵ����������С�������ش��ڣ�������ȷ��Ϊ n - 1
//���ݷ�����m >> n������ O(mlogn) ���� O(mlogm)��ѡ�� prim (43ms)����ʵ���ϸ��� n �� m ���Ƚ�С�������㷨��ʱ��û����
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 305, M = 1e5 + 5;
// int n, m;
// struct edge{
//     int to, w;//�ߵ��յ��Ȩֵ
// };
// struct node{
//     int id, dis;//�յ�ı�� �� ���õ��Ȩֵ
//     bool operator < (const node &x) const{ return dis > x.dis;}//ʹ���ȶ��еĶѶ�Ϊ��Сֵ
// };
// vector<edge> G[N];//�� G[u.id].to = v ����ʾ�� u -> v
// bool vis[N];//��¼���Ƿ��Ѿ��� MST ��
// void prim()
// {
//     int s = 1;
//     int res = 0;
//     priority_queue<node> q;
//     q.push(node{s, 0});
//     while(!q.empty())
//     {
//         node u = q.top(); q.pop();
//         if(vis[u.id]) continue;//��ȥ����MST�ϵĵ㣬��ֹ�ɻ�
//         vis[u.id] = 1;
//         res = max(res, u.dis);
//         for(auto v : G[u.id])//������ u ���ھӵ� v
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
//         G[v].push_back(edge{u, w});//˫���
//     }
//     prim();
//     return 0;
// }
//��ʵ�ʣ������� n �� m �ǱȽ�С�ģ���kruskal��Ȼ������(42ms)
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
//             ds[e1] = e2;//�ϲ�
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



//2.�ڴ������
//Ҫ��ȫ����ͨ��������С������ �� ���� k ������
// ˼·��ȫ��ͨ������ n �������С��������Ҫ�ֳ� k �����֣���ôȡ�� k - 1 ���ϴ�ıߣ�������ۼ�ȥ��Щ�ߣ��������մ�
//     ���� ��С������������� �� ����k������ ʱ����̰�ĵģ�����ֻ�蹹�쵽 n - k ���㼴�ɣ����ı߶����迼�ǣ���Ϊ�ᱻȥ��
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
//     int ans = 0, cnt = 0;//ansΪȨֵ�ͣ�cnt��¼����MST����
//     sort(edge + 1, edge + 1 + m);
//     for(int i = 1; i <= m; i++)
//     {
//         if(cnt == n - k) break;
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             ans += edge[i].w;
//             ds[e1] = e2;//�ϲ�
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



//3.������
//��С�������𰸱ش��ڵ���Ȩֵ a ����һ����㣬����ʵ�ʵ㵽�õ�ȨֵΪ a���Ҹõ��Ҫ���ʸ����ı������ n �� 
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 505, M = N * N;
// struct Edge{
//     int u, v, w;
//     bool operator < (const Edge &x) const{ return w < x.w;}
//     // Edge() = default; ���Ҳ���Խ���Զ��幹�캯�������޷����������
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
//         if(cnt == n) break;//�Զ����һ���㣬���յ����� n + 1 ���������ı������ n ��
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 == e2) continue;
//         else
//         {
//             ans += edge[i].w;
//             ds[e1] = e2;//�ϲ�
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
//             if(j > i && w) edge[++m] = Edge(i, j, w);//�Ż�Ϊ�������ٽ��ߣ�ֻ��Ҫ�� b ����ԭ�۱ߡ�����
//         }
//     }
//     for(int i = 1; i <= b; i++) edge[++m] = Edge(0, i, a);
//     kruskal();
//     return 0;
// }



//4.������
//�����൱���� ȫ���Ȩ �� ��С������Ȩֵ�� ֮��
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



//5.���仮��
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
//     //�ɻ���Ҳ����������ôʣ��ı߶��ǲ����ľ��룬����֮��ĵ�һ���߼�Ϊ��С��
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
//Prim���죿



//*6.Explorer
// �����ص����� ���ٱ�����Ҫ����С��������һ�������������� 4 ���㣬ͬ��������֮���ڵ� 2 ���� �Լ� ����һ���������ߣ��������봹������� 2 ���㡣
// 1.��Ϊ����أ�һ�����һ��ֱ���ϣ������ӷ������ӳ�䵽��һ�����ϣ���ֻ����������������
// 2.����Ҫ֪������㽨ͼҪ��ȫͼ��sort��������õ���С����������ȫͼ����Ϊû�취�ж��ĸ�������ȫ�����ţ����Ե�����ӳ�䷽��ֻ��3������ʱ�ͺ�˵��
// 3.�������������������е㹲�ߣ����Զ�����ABCD������AD �� ����AB,BC,CD û����������ͬһ������ֻ��Ҫ�������������Ϳ��Ծֲ�ȫ��ͨ����ʵ�־ֲ���С����������Ȼ�����߶�������
// 4.��ô����ֻʣ�������ߵ��໥��ϵ����һ����ͶӰ����һ�����ϣ������õ�Ϳ�������������ϵ�ľ��룬���ҷ���ֱ��봹������ĵ㣬��õ����Ӻ�
// 5.ÿ���㶼ʵ�������з����ϵ��������
// ��һ��������ı�������� 4 ��
// ˼·�������߽��㣨����ƽ����������ҳ���һ�����ϵ�һ����ӳ�䵽��һ���ߵķ��������ҳ�Ѱ��ӳ����������ķ���
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
//     int cnt = 0;//ansΪȨֵ�ͣ�cnt��¼���� MST �ı���
//     sort(edge + 1, edge + 1 + ind);
//     for(int i = 1; i <= ind; i++)
//     {
//         if(cnt == n + m - 1) break;
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
//         if(e1 != e2)
//         {
//             ans += sqrt(edge[i].w);
//             ds[e1] = e2;//�ϲ�
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
//     //������ͬһ��������������ı�
//     for(int i = 1; i < n; i++) edge[++ind] = Edge{i, i + 1, getdis(a[i], a[i + 1])};
//     for(int i = 1; i < m; i++) edge[++ind] = Edge{n + i, n + i + 1, getdis(b[i], b[i + 1])};
//     //�ٸ���ѡȡ����������ıߣ����ַ���ѡ�����ӵĲ����ߵ㣬������ֻ��Ҫ��������ıߣ�����ֱ��ѡȡ[l, r]�������߸����㣨�������жϵڶ�����������������
//     //��ͬ��ӳ�䷽��������һ���������ܱ�֤һ��ӳ�䷽���������������������������ַ���
//     for(int i = 1; i <= n; i++)//ֱ��ab ӳ�䵽 ֱ��cd ��
//     {
//         int l = 1, r = m;
//         while(l < r - 2)
//         {
//             int midl = (l * 2 + r) / 3, midr = (l + r * 2) / 3;
//             if(getdis(a[i], b[midl]) < getdis(a[i], b[midr])) r = midr;//���ֱƽ���Сֵ����
//             else l = midl;
//         }
//         for(int j = l; j <= r; j++) edge[++ind] = Edge{i, n + j, getdis(a[i], b[j])};
//     }
//     for(int i = 1; i <= m; i++)//ֱ��cd ӳ�䵽 ֱ��ab ��
//     {
//         int l = 1, r = n;
//         while(l < r - 2)
//         {
//             int midl = (l * 2 + r) / 3, midr = (l + r * 2) / 3;
//             if(getdis(b[i], a[midl]) < getdis(b[i], a[midr])) r = midr;//���ֱƽ���Сֵ����
//             else l = midl;
//         }
//         for(int j = l; j <= r; j++) edge[++ind] = Edge{n + i, j, getdis(b[i], a[j])};
//     }
//     kruskal();
//     return 0;
// }



//7.Heavy Transportation�������������
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// using namespace std;
// const int N = 1e3 + 5;
// struct Edge{
//     int u, v, w;
//     bool operator < (const Edge &x) const{ return w > x.w;}//�󶥶�
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
//         int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);//�жϵ� i ���ߵ����˵��Ƿ��Ѿ���ͨ
//         if(e1 != e2)
//         {
//             ds[e1] = e2;
//             //��������������ͨ1��n����һ�̾���������ˣ���ʱ����õı���Ȼ������·�α��е���С����
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
//             scanf("%d%d%d", &u, &v, &w);// All streets can be travelled in both directions.����ͼ
//             Edge x = {u, v, w};
//             edge.push_back(x);
//         }
//         printf("Scenario #%d:\n%d\n\n", k, kruskal());//Terminate the output for the scenario with a blank line.����֮���п���
//     }
//     return 0;
// }

























/*ʮ��. ���·������*/
/*
�����·�㷨Ӧ������
�������·������            ��Ȩ                    �㷨(���Ӷ�)
һ����㣬һ���յ�      �Ǹ����ޱ�Ȩ���ȨΪ1   A*�㷨(<O((m + n)logn))��˫�����(<O((m + n)logn))��̰����������(<O(m + n))      
һ����㵽�������е�    �ޱ�Ȩ���ȨΪ1         BFS(O(m + n))
                      �Ǹ���                 Dijkstra�㷨-���Ż����ȶ���(O((m + n)logn))
                      ������                 SPFA(<O(m*n)) 
���е��֮��           ������                 Floyd-Warshall(O(n^3))
*/



/*BFS һ����㵽�������е�, �ޱ�Ȩ���ȨΪ1*/
//1.���·����
//һ����㵽���������㣬�ұ�ȨΪ 1 (�ޱ�Ȩ) -- �ڽӱ� + BFS
//˼·����ȷ�����·���룬�߸��·������·��·������
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
//             if(!vis[to])//�̶����·����
//             {
//                 vis[to] = 1;
//                 dis[to] = dis[now] + 1;
//                 q.push(to);
//             }
//             if(dis[to] == dis[now] + 1)//���·�������ӣ��� now�� ��·����ȫ���ӵ� to�� ��
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
//         e[v].push_back(u); //����ͼ
//     }
//     bfs();
//     for(int i = 1; i <= n; i++)
//     {
//         if(i != 1 && dis[i] == INF) cout << "0\n";
//         else cout << cnt[i] % mod << "\n";
//     }
//     return 0;
// }











/*Floyd �㷨����Դ���·�����⣩ -- O(n^3) -- ������е��֮������·�� -- ����ѭ����ֻ������С��ģ�ĳ���ͼ(n < 300)
Ӧ�� ��̬�滮 ��˼·������ dp[k][i][j] Ϊ�ӵ�һ����������� k ����ʱ���ӵ� i ���� j ����̾���(��С��Ȩ��)
�Ӻ��� k - 1 �������ͼ��չ���� k �����ͼ����������kʹ�þ�����̣��򽫵� k ���뵽 i -> j ·���ϣ����� i -> k -> j
��ʱ distance(i -> k -> j) < distance(i -> j)���� k ��Ӧ�õ���״̬��
ת�Ʒ���Ϊ dp[k][i][j] = min(dp[k - 1][i][j], dp[k - 1][i][k] + dp[k - 1][k][j])
���ڵ�һά״ֻ̬��� k - 1 ��״̬�йأ��ʿ��Թ�����: dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

��̾���(�������е�Լ�ľ����С)��
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
        dp[u][v] = dp[v][u] = min(dp[u][v], w);//��ֹ���ر�
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



���ݱհ�(�������е�Լ�����ȹ�ϵ)��
    �ڽ��������У��������ɸ�Ԫ�غ����ɶԶ�Ԫ��ϵ���ҹ�ϵ���д����ԣ�����a �� b�й�ϵ��b��c�й�ϵ����ôa��c�ض��й�ϵ������
    ͨ���������Ƶ����������Ԫ��֮��Ĺ�ϵ"�����ⱻ��Ϊ���ݱհ���
    �����ڽӾ���d������ d[i, j] = 1 ��ʾ i �� j �й�ϵ��d[i, j] = 0��ʾ i �� j û�й�ϵ���ر�ģ�d[i, i]ʼ��Ϊ 1��
    ���Ĵ��룺
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] |= d[i][k] & d[k][j];
    bitset�Ż�(��n<500�Ż�������n<=1000)��

*/

//1.Cow Contest(���ݱհ�)
//����֪����һһͷ��ţ������������ţ֮���ʤ����ϵ���������ж��������Ƿ�ȷ�ϣ���������������
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 105;
// int n, m;
// bool dp[N][N];
// void floyd()
// {
//     for(int k = 1; k <= n; k++)//�������е����м��k��������k������ͨ i->k->j ��˵�� i �� j ��ͨ
//         for(int i = 1; i <= n; i++)
//             for(int j = 1; j <= n; j++)
//                 dp[i][j] |= dp[i][k] & dp[k][j];
//                 //�� if(dp[i][k] && dp[k][j]) dp[i][j] = 1;
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
//     //�ж��� i �Ƿ���ȷ���������� i ������n-1�����Ƿ񶼾�����ͨ��ϵ
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
//bitset�Ż�
// #include <iostream>
// #include <algorithm>
// #include <bitset>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 105;
// int n, m;
// bitset<N> dp[N];//N������ΪN�Ķ����ƣ����Զ�һ���������Ʋ�������ʡȥ�� j ��ѭ��
// void floyd()
// {
//     for(int k = 1; k <= n; k++)//�������е����м��k��������k������ͨ i->k->j ��˵�� i �� j ��ͨ
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
//     //�ж��� i �Ƿ���ȷ���������� i ������n-1�����Ƿ񶼾�����ͨ��ϵ
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
//*���⣺�������������ѽ⣬��һ���ڽӾ���(��������)����������ӵ� 1 �� ������ ���������ʱ�伯����ĵ����ֵ
//�ⷨ������ n <= 100 ���ñ���򵥵�floyd������
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








/*dijkstra�㷨����Դ���·�����⣩ -- BFS + ���ȶ��У�����õ��� ���s ������С�ĵ㣩
Ӧ�ó�����
    ϡ��ͼ��n �ϴ��� dijkstra + ���ȶ��У����ڻ�ȡ��̾���ĵ�  O((m + n)logn)
    ����ͼ��n^2 Լ���� m���������ȶ��У�ֱ�������нڵ����Ҿ�����̵ĵ�  O(n^2)


dijkstra + ���ȶ��� ��ģ��(ͼ����һ����������ܶ࣬��cstdio��ɸ���)

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
    int id; ll dis;//dis Ϊ�õ㵽���ľ���
    node(int a = 0, ll b = 0){ id = a, dis = b;}
    bool operator <(const node &x)const{ return dis > x.dis;}
};

int n, m, s = 1;//���s
int pre[N];//pre[i] ��¼ǰ���ڵ㼴 �� i ����һ����ı�ţ����ڴ�ӡ·��
ll dis[N];//��¼ ���нڵ� �� ���s �ľ���
bool vis[N];//��¼�Ƿ����ҵ� �ڵ�i �� ��̾���
vector<edge> e[N];

void print_path(int t)//�� �յ�n �ݹ��ӡ
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
        for(int i = 0; i < e[u.id].size(); i++)//�����ھ�
        {
            edge ne = e[u.id][i];
            if(!vis[ne.to] && dis[ne.to] > u.dis + ne.w)//�����ھӵ����̾���
            {
                dis[ne.to] = u.dis + ne.w;
                q.push(node(ne.to, dis[ne.to]));
                pre[ne.to] = u.id;
            }
        }
    }
    // print_path(n);//��ӡ·��
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
        // e[v].push_back(edge(u, w)); //˫���
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
//Ҫ���������Ǹ�����ͼ
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
//     int id; ll dis;//dis Ϊ�õ㵽���ľ���
//     bool operator <(const node &x)const{ return dis > x.dis;}
// };

// int n, m, s = 1;//���s
// ll dis[N];//��¼ ���нڵ� �� ���s �ľ���
// bool vis[N];//��¼�Ƿ����ҵ� �ڵ�i �� ��̾���
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
//         for(int i = 0; i < e[u.id].size(); i++)//�����ھ�
//         {
//             edge ne = e[u.id][i];
//             if(!vis[ne.to] && dis[ne.to] > u.dis + ne.w)//�����ھӵ����̾���
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
//         e[v].push_back(e2); //˫���
//     }
//     dijkstra();
//     printf("%lld", dis[n]);
//     return 0;
// }



//*2.Heavy Transportation
//���⣺ͼ���в�ͬ�����޶ȵ�·�Σ�һ��������·���ɲ�ͬ��·�����ӣ������������ܾ���������С�����޶ȵ�·�Σ�����·������ͨ
//      �� 1 ~ n ·�� ��·�ζ���ȡ����������Ӻ� ����С����·�ε����أ����ھӵ����������
//�·�����⣬��Ŀ�����⣬���÷����ȶ���д�������ڽӾ���洢����
//ʵ���ϸ���Ӧ����������������ʣ�������������ϰ Dijkstra�㷨�ı���д�����е����ƶ�̬�滮��
// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const int N = 1e3 + 5;
// int n, m, s = 1;//���s
// int dp[N];//dp[i] ����Ϊ �� ���1 �� ��i ·�ϵ���С����ֵ
// int gra[N][N];
// bool vis[N];
// void dijkstra()
// {
//     for(int i = 1; i <= n; i++) dp[i] = gra[1][i];//״̬��ʼ��Ϊֱ������µ�����ֵ���������Աȷ�ֱ���ĸ����ظ���
//     memset(vis, 0, sizeof(vis));
//     dp[1] = 0;
//     vis[1] = 1;
//     //��������������� n-1 �Σ���ȡǰ n - 1 ��ı�����ͨ n ����
//     for(int i = 1; i < n; i++)
//     {
//         int _max = -1, ne = 0;
//         for(int j = 1; j <= n; j++)//Ѱ��������ص��м��
//             if(!vis[j] && dp[j] > _max)
//                 _max = dp[j], ne = j;
//         vis[ne] = 1;
//         for(int j = 1; j <= n; j++)//����dp״̬��������� �м��ne �� ��ֱ��·����С����ֵ���󣬾�ȡ�÷�ֱ��·��
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
//         memset(gra, -1, sizeof(gra));//���·������ʼ��Ϊ����С�����ж� ��i �� ��j �Ƿ�Ϊ�ھ�
//         for(int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             scanf("%d%d%d", &u, &v, &w);// All streets can be travelled in both directions.����ͼ
//             gra[u][v] = gra[v][u] = w;// gra[u][v] = gra[v][u] = max(gra[u][v], w);//�������ر�
//         }
//         dijkstra();
//         printf("Scenario #%d:\n%d\n\n", k, dp[n]);//Terminate the output for the scenario with a blank line.����֮���п���
//     }
//     return 0;
// }
//ǰ���ǻ��ڽӱ� + ���ȶ���
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
//     int id, dis;//dis Ϊ�õ㵽���ľ���
//     bool operator <(const node &x)const{ return dis < x.dis;}
// };
// int n, m, s = 1;
// int dis[N];//��¼ ���нڵ� �� ���s �ľ���
// bool vis[N];//��¼�Ƿ����ҵ� �ڵ�i �� ��̾���
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
//         for(int i = 0; i < e[u.id].size(); i++)//�����ھ�
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
//             e[v].push_back(e2); //˫���
//         }
//         dijkstra();
//         printf("Scenario #%d:\n%d\n\n", k, dis[n]);//Terminate the output for the scenario with a blank line.����֮���п���
//     }
//     return 0;
// }



//*3.�����Ƹ��Dijkstra + ö���������䣩
//���⣺�ж�����Ʒ��ÿ����Ʒ���������ɼ����Ʒ(�Ը��ʹ��۹���ԭƷ)��Ѱ�� ���õ�һ����Ʒ��������ܼ�Ǯ�Ĺ��򷽰�
//      ���� �ܷ���i��Ʒ ������ �����ǰһ����Ʒj �� i��Ʒ�ĵ�λϵ���|p[i] - p[j]| <= limit ���ܹ���
//���������ڵ�һ����Ʒ�����Ǳع���ģ�Ҳ���ǹ�����յ㣬��ֱ�ӹ���(����ԭ��)��Ҳ�ɹ��������Ʒ�����е�ĳһ���Դ��湺��
//     ��ͼ�к��� ԭ��0��ÿ����Ʒ�ĵ����(��ȨΪ��Ʒ����ļ�Ǯ) �� ��Ʒ����������ϵ�ĵ����(��ȨΪ�Żݼ�)
//�ص㣺��Ȼ������·��ȫ������Ϊ p[i] - limit <= p[j] <= p[i] + limit������ֱ���Դ�Ϊ�������������⣬�漰���䳤�Ȳ��� limit ���� 2*limit
//      �����ڵ�λϵ����������������һ����·������������������� [p[i] - limit, p[j]] [p[i] - limit + 1, p[j] + 1] ������ [p[i], p[j] + limit]
//      ���Դ��ڶ�����ڲ�ͬ�ɳ����������·����ö�ٲ�ͬ���ɳ�����(����)���������õ��������·��ѡ����С���۵����·��
//      ��ÿ�����·�ض����� �յ�-��1����ô ������·����ȫ��Χ �ɼ�Ϊ ֻ����������·��ȫ��Χ [p[1] - limit, p[1] + limit]
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
//     return dis[1];//���ص����յ�1�ĵ�ǰ��С��ֵ
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
//79ms(���� N <= 100����ȫ�������ڽӾ��󣬽��dp˼������)
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
//     for(int i = 0; i <= n; i++)//�� ����ԭ��0 �� ��n �� n + 1 ���㣬Ҳ������ͼ��С��չ��ȫͼ��С
//     {
//         int ind = -1;
//         for(int j = 0; j <= n; j++)//Ѱ�ҵ�ǰδʹ�õ���̱ߣ�ͬʱҲ����ȷ����indΪ�յ�����·�Ƿ���ȷ��
//             if(!vis[j] && (ind == -1 || dis[j] < dis[ind])) ind = j;
//         vis[ind] = 1;//������ֱ��(��ʼ״̬)���ֱ��(�Ѿ�������)����indΪ�յ�����·��ʱ����ȷ��
//         for(int j = 1; j <= n; j++)//���������յ�����·��������״̬���жϽ���򲻽� 0��ind��ֱ����(�������յ�Ϊind�����·��)
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



//4.Frogger�����·�����·����Сֵ -- ���·����С���⣩
//���⣺�����·���·�ε���Сֵ�����1 �� �յ�2 ��Ψһȷ��
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
//     for(int i = 1; i <= n; i++)//��ͼ��չ
//     {
//         int ind = -1;
//         for(int j = 1; j <= n; j++)//���ִ����·��
//             if(!vis[j] && (ind == -1 || dis[j] < dis[ind])) ind = j;
//         vis[ind] = 1;
//         for(int j = 1; j <= n; j++)//�������·�����·�ε���Сֵ
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



//*5.ͨ���¸�����ĵ�· (���· + ���ִ� ��⼫��С����)
//���⣺�����з���Ѫ��������·���У�����һ����������շ� x���ó���������·���е���Сֵ
//˼·����dijkstraά��Ѫ�����ģ�����ʹ�����Ѫ����������������շ� x�����ڸ� x �Ķ���ֵ�ĳ��в��ߣ�������Ϻ�õ��ı�����Сֵ��
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
//     int id; ll dis;//dis Ϊ�õ㵽���ľ���
//     node(int a = 0, ll b = 0){ id = a, dis = b;}
//     bool operator <(const node &x)const{ return dis > x.dis;}
// };
// int n, m, blood, s = 1;//���s
// ll dis[N], cost[N];
// bool vis[N];
// vector<edge> e[N];
// bool dijkstra(ll mid)
// {
//     if(mid < cost[s]) return 0;//�Ż�������㶼�߲��ˣ��ͷ���
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
//                 if(ne.to == n) return dis[n] <= blood;//��n��
//                 q.push(node(ne.to, dis[ne.to]));
//             }
//         }
//     }
//     return 0;//�޷������ n
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
//         e[v].push_back(edge(u, w)); //˫���
//     }
//     while(l <= r)
//     {
//         ll mid = (l + r) >> 1;
//         if(dijkstra(mid)) r = mid - 1, ans = mid;
//         else l = mid + 1;
//     }
//     if(ans == -1) printf("AFK");//һ������������·����û��
//     else printf("%lld\n", ans);
//     return 0;
// }




















/* A*�㷨������㵥�յ����⣩ -- ̰����������(���ڹ��ۺ���h(i)) + BFS(Dijkstra) + ���ȶ���
�ص㣺��ʱ�������ȶ��еĲ��� ��㵽��ǰ��ľ��룬���� ��ǰ�㵽�յ�ľ��롣
      A*�㷨��ʵ�ֹؼ����� h���� ������Ƿ�������⡣


*/
















/*ʮ��. �߶�������״����*/
/*
//https://blog.csdn.net/weixin_45697774/article/details/104274713?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167533467316782428699964%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167533467316782428699964&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-104274713-null-null.142^v72^pc_new_rank,201^v4^add_ask&utm_term=%E7%BA%BF%E6%AE%B5%E6%A0%91&spm=1018.2226.3001.4187
�߶�����һ�ֻ��� ����˼�� �� ������(����)�������� ���� �Ͻ�����Ϣ��ͳ��(���� ������� ��ͨ�ýⷨ)��
����һЩ�������䣨�����߶Σ����޸ġ�ά������ O(N) ��ʱ�临�Ӷȱ�� O(logN)
�߶��� �������Ϊ ����˼�� + �������ṹ + Lazy-Tag���� 

1.�߶�����ÿһ���ڵ㶼����һ������
2.�߶������е�Ψһ���ڵ㣬���������������ͳ�Ʒ�Χ��[1��n]
3.�߶�����ÿ��Ҷ�ڵ㶼������Ϊ 1 ��Ԫ���� [x��x]
4.����ÿ���ڲ��ڵ� [l��r]��������ڵ��� [l, mid]���ҽڵ��� [mid, r]������ mid = (l + r) / 2(����ȡ��)
һ���߶��������ṹ�У���Ϣ�ͽڵ�Ĵ洢����Ϣ�ϲ�����Ϣ���¡������������޸ġ������ѯ��

�߶�����ÿ������ά���Լ��� ���ұ߽� �� �����ܺ�\���ֵ\��Сֵ�ȣ����赱ǰ�ڵ�ά��������Ϊ[L, R]��
�� mid = (L + R) / 2���������ӽڵ�ά��[L, mid]�����ӽڵ�ά��[mid + 1, R]��

�������� O(logn)��
    �߶������� build() ���ι��� ��pushup() (�������ϴ���������Ϣ)
    �����޸�        ��ֱ���޸�Ҷ�ӽڵ���Ԫ�ص�ֵ��Ȼ��������ϸ����߶���
    �����ѯ query()����ѯ[L, R]��Ϣ(��ֵ������͵�)���Ӹ��ڵ�����[1, n]��ʼ�ݹ飬��Ϊ[pl, pr]��ÿ�εݹ���������������
        [L, R] ��ȫ���� [pl, pr]��ֱ�ӷ��� ���p �������ֵ��
        [L, R] �� [pl, pr] �����ص�����ô�����������ص��Ĳ��֡��� L < pr�����ӽڵ����������ص���������ݹ����ӡ��� R > pl�������ݹ�����
    �����޸�update()���ñ������ tag[i] ͳ�Ƽ�¼�� ����i ���޸�(�ӳ��޸�)�������޸Ĳ���������ص����ͻʱ���ò����ӽڵ㴫�� pushdown() (�������´���)

*/

//�����޸� + �����ѯ ģ��
/*
//��ע��
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define il inline
const int N = 1e5 + 10;
ll n, m;
ll a[N];//Ԫ��ֵ���У����±�1��ʼ
ll tree[N << 2], tag[N << 2];
il ll ls(ll p) { return p << 1;}       //��λ���ӣ�p * 2
il ll rs(ll p) { return p << 1 | 1;}   //��λ���ӣ�p * 2 + 1
il void addtag(ll p, ll pl, ll pr, ll d) //����ͬʱ����tree
{
    tag[p] += d;//����p������d
    tree[p] += d * (pr - pl + 1);//[pl, pr]����p�ϵ�ÿ��ֵ���� d�����������
}
il void pushup(ll p) //���ϸ��±��Ϊ p �� ������ֵ��
{
    tree[p] = tree[ls(p)] + tree[rs(p)]; //�����
    // tree[p] = min(tree[ls(p)], tree[rs(p)]); //������ֵ
}
il void pushdown(ll p, ll pl, ll pr) //���ܸ���ʱ����tag��������
{
    if(tag[p])
    {
        ll mid = (pl + pr) >> 1;
        addtag(ls(p), pl, mid, tag[p]); //����������
        addtag(rs(p), mid + 1, pr, tag[p]); //����������
        tag[p] = 0; //���ߺ���������
    }
}
void build(ll p, ll pl, ll pr) //pΪ�ڵ��ţ�ָ������[pl, pr]
{
    tag[p] = 0;
    if(pl == pr) { tree[p] = a[pl]; return;} //Ҷ�ӽڵ�
    ll mid = (pl + pr) >> 1; //���ַ���
    build(ls(p), pl, mid); //����
    build(rs(p), mid + 1, pr); //����
    pushup(p); //�������ϴ�ֵ
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d) //�����޸ģ���[L, R]ÿ��Ԫ�ض����� d
{
    if(pl >= L && pr <= R) //��ȫ���������
    {
        addtag(p, pl, pr, d);
        return;
    }
    pushdown(p, pl, pr); //���ܸ���ʱ����tag��������
    ll mid = (pl + pr) >> 1;
    if(mid >= L) update(L, R, ls(p), pl, mid, d); //���ص���ݹ�������
    if(mid < R) update(L, R, rs(p), mid + 1, pr, d); // (mid + 1 <= R) ���ص���ݹ�������
    pushup(p); //�ݹ��������ϸ���
}
ll query(ll L, ll R, ll p, ll pl, ll pr) //��ѯ [L, R] �����
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
        scanf("%lld", &op);//������
        if(op == 1) //�����޸ģ���d
        {
            scanf("%lld%lld%lld", &L, &R, &d);
            update(L, R, 1, 1, n, d);
        }
        else //����Ͳ�ѯ
        {
            scanf("%lld%lld", &L, &R);
            printf("%lld\n", query(L, R, 1, 1, n));
        }
    }
    return 0;
}

//��ע�Ͱ�
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

//Ӧ�� ������(��Ƕ�)ʱ�����֮����л���Ӱ�죬������ͬ���ȼ��Ĵ���˳��û�취�����г�addtag()������
//�ṹ��ģ��
//��ע��
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
    ll sum;//Ҫ��ѯ��ֵ������͡�����˵�
    ll sum_tag, mul_tag;//lazy���(�������ڵĸ�ֵ�Ĳ���)����ֵ����ֵ��
    node(ll a = 0, ll b = 0, ll c = 0) {sum = a, sum_tag = b, mul_tag = c;}
}tree[N << 2];
ll n, m, mod;

il void push_up(ll p) //���� ��ѯֵ
{
    tree[p].sum = (tree[ls].sum + tree[rs].sum) % mod;
}
il void push_down_change(ll p, ll u, ll pl, ll pr) //����push_down()���޸����õ��������������ݷ��� u -> p
{
    //����ֵ����
    tree[p].sum = (tree[p].sum * tree[u].mul_tag % mod + (pr - pl + 1) * tree[u].sum_tag % mod) % mod;
    //��ǻ���
    tree[p].sum_tag = (tree[u].sum_tag + tree[p].sum_tag * tree[u].mul_tag % mod) % mod;
    tree[p].mul_tag = tree[p].mul_tag * tree[u].mul_tag % mod;
}
il void push_down(ll p, ll pl, ll pr) //��Ǵ������������� �� ������ѯֵ�ĸ���
{
    if(tree[p].sum_tag != 0 || tree[p].mul_tag != 1) //С�Ż������б�Ƕ�Ϊ��ʼֵʱ���贫��
    {
        //����ֵ���£��������б�ǣ���������ǰ���б��
        ll mid = (pl + pr) >> 1;
        push_down_change(ls, p, pl, mid);
        push_down_change(rs, p, mid + 1, pr);
        tree[p].sum_tag = 0, tree[p].mul_tag = 1;
    }
}
void build(ll p, ll pl, ll pr) //ֱ�Ӷ�ȡҶ�ӽ���ֵ��ʡȥԭ���пռ�(����ԭ����ֵ����)
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
    push_up(p);//�����ʼ��ѯֵ(����ֵ)
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d, ll op)
{
    if(L <= pl && R >= pr)
    {
        //��������ֵ �� ��ӱ��
        if(op == 1)//��ֵ����
        {
            tree[p].sum = tree[p].sum * d % mod;
            tree[p].sum_tag = tree[p].sum_tag * d % mod; //�����еĺͱ�ǲ���Ӱ��
            tree[p].mul_tag = tree[p].mul_tag * d % mod; 
        }
        else//��ֵ����
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

//��ע��(�����ٲ�����Ŀ ���в��� �Ĵ���)
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
    ll sum;//Ҫ��ѯ��ֵ������͡�����˵�
    ll sum_tag, mul_tag;//lazy���(�������ڵĸ�ֵ�Ĳ���)����ֵ����ֵ��
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

//1.P3374 ��״���� 1
//�߶���д��(855ms)
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



//2. P1816 �ҳ�
//���߶�������Сֵ���޸Ĵ��ݺ���push_up()����
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



//3.����
// ��ʼ����Ϊ 0�������赥������
// ���1 ʵ��lazy���״̬�л� �����䳤�� - ԭ�����Ƶ����� = �������Ƶ�����
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



//*4.�߶��� 2
//������ ����ͣ������ �Լ� ��ѯ�����
//�ص��������ά��lazy���ʵ�����ָ�ֵ��������Ȼ��Ҫ����ڶ������ʵ�������
//��[L, R]ÿ�������� k��ʵ���Ͼ��� tree[p] = tree[p] * k % p��p ������[L, R]�ı��
/*��������������Լӷ��ͳ˷�����Ϊ������
����Ҫ��ס��lazy��������� ��ǰ��� �� �������� �� �޸ģ���ǰ������޸������� ������ �ı��
���ȼ���ϵ���˷����ӷ����������ӱ��ʱ��Ҫע�� ����� �� �ͱ�� ��Ӱ��
�ͱ�� �� ����� �Ĺ�ϵ�Ƶ������������(��ѯ����ʲô) -- ��ѯ��
��ǰ����ֵ(�����Ѹı䣬������ָ��ʼ��ʱ������) X = al + ������ + ar���Ͳ��� �� �˲��� ���Ƕ�ԭ���и�ֵ���á�
��ͬ����£�
    ��ӱ��ʱ�ĸ��� update()��
        1.��ǰ�ޱ�� + ��� ��\�����: X' = al + ������ + ar + (r - l + 1) * d_sum �� X' = (al + ������ + ar) * d_mul

        2.ԭ�ͱ�� + �ͱ��: X' = (al + ������ + ar) + (r - l + 1) * d_sum + (r - l + 1) * d_sum' = (al + ������ + ar) + (r - l + 1) * (d_sum + d_sum') 
                            = X + (r - l + 1) * (d_sum + d_sum') -- �ͱ�Ǽ��ۺ�
          ԭ����� + ����ǣ�X' = X * d_mul * d_mul'

        3.ԭ�ͱ�� + ����ǣ�X' = (al + d_sum) * d_mul + (al+1 + d_sum) * d_mul ������ (ar + d_sum) * d_mul
                            = (al + ������ + ar) * d_mul + (r - l + 1) * d_sum * d_mul
                            = X * d_mul + (r - l + 1) * (d_sum * d_mul) -- �˴� �ºͱ�� = ԭ�ͱ�� * �»����
                            ���Խ��г˷�����ʱ������ ԭ�˷���� �ĸ��£�����Ҫ���� ԭ�ͱ��
          ԭ����� + �ͱ�ǣ�X' = (al * d_mul + d_sum) + (al+1 * d_mul + d_sum) ������ (ar * d_mul + d_sum) = (al + ������ + ar) * d_mul + (r - l + 1) * d_sum
                            = X * d_mul + (r - l + 1) * d_sum
                            ��� ��+�ͣ��κ�����£����мӺͲ���ʱ��ֻ��Ҫ���� ԭ�ͱ��
    ����ֵ���£���ǵĴ�������� push_down()��
        ����ǰ����ֵ(�� ԭ�ͱ�ǣ�ԭ�����) =  X * d_mul + (r - l + 1) * d_sum * d_mul = X * mul_tag + (r-l+1) * sum_tag������ X Ϊ ��ǰ����ֵ�ͣ�
        ������Щ��ǵĴ�����ͳһ�ģ�ͬʱ�ģ�����Ӱ��ģ��轫���ֱ�ǵĴ��ݺϲ���
            ��֪���˷�������´���ʱӰ����ӵ����б�ǣ���Ϊ �ͱ�� ʵ������ ԭ��Ҫ�ӵ�ֵd * ��ǰ������Զ����µ��۳�ֵ
            ���ԣ�����ǻ��ۣ�
                sum_tag = sum_tag' + sum_tag * mul_tag'��
                mul_tag = mul_tag * mul_tag'��
            ����ֵ����(�����±��)��
                X' = X * mul_tag' + (r - l + 1) * sum_tag'��
*/
//�ṹ��д��
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
//     ll sum;//Ҫ��ѯ��ֵ������͡�����˵�
//     ll sum_tag, mul_tag;//lazy���(�������ڵĸ�ֵ�Ĳ���)����ֵ����ֵ��
//     node(ll a = 0, ll b = 0, ll c = 0) {sum = a, sum_tag = b, mul_tag = c;}
// }tree[N << 2];
// ll n, m, mod;

// il void push_up(ll p) //���� ��ѯֵ
// {
//     tree[p].sum = (tree[ls].sum + tree[rs].sum) % mod;
// }
// il void push_down_change(ll p, ll u, ll pl, ll pr) //����push_down()���޸����õ��������������ݷ��� u -> p
// {
//     //����ֵ����
//     tree[p].sum = (tree[p].sum * tree[u].mul_tag % mod + (pr - pl + 1) * tree[u].sum_tag % mod) % mod;
//     //��ǻ���
//     tree[p].sum_tag = (tree[u].sum_tag + tree[p].sum_tag * tree[u].mul_tag % mod) % mod;
//     tree[p].mul_tag = tree[p].mul_tag * tree[u].mul_tag % mod;
// }
// il void push_down(ll p, ll pl, ll pr) //��Ǵ������������� �� ������ѯֵ�ĸ���
// {
//     if(tree[p].sum_tag != 0 || tree[p].mul_tag != 1) //С�Ż������б�Ƕ�Ϊ��ʼֵʱ���贫��
//     {
//         //����ֵ���£��������б�ǣ���������ǰ���б��
//         ll mid = (pl + pr) >> 1;
//         push_down_change(ls, p, pl, mid);
//         push_down_change(rs, p, mid + 1, pr);
//         tree[p].sum_tag = 0, tree[p].mul_tag = 1;
//     }
// }
// void build(ll p, ll pl, ll pr) //ֱ�Ӷ�ȡҶ�ӽ���ֵ��ʡȥԭ���пռ�(����ԭ����ֵ����)
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
//     push_up(p);//�����ʼ��ѯֵ(����ֵ)
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d, ll op)
// {
//     if(L <= pl && R >= pr)
//     {
//         //��������ֵ �� ��ӱ��
//         if(op == 1)//��ֵ����
//         {
//             tree[p].sum = tree[p].sum * d % mod;
//             tree[p].sum_tag = tree[p].sum_tag * d % mod; //�����еĺͱ�ǲ���Ӱ��
//             tree[p].mul_tag = tree[p].mul_tag * d % mod; 
//         }
//         else//��ֵ����
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
//�ǽṹ�壺
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
// il void addtag2(ll p, ll pl, ll pr, ll d)//�˷����Ӱ��ӷ����
// {
//     tag[p] = tag[p] * d % mod, tag2[p] = tag2[p] * d % mod, tree[p] = tree[p] * d % mod;
// }
// il void push(ll p, ll pl, ll pr, ll u) //��ֵʱͬʱ����ӷ��ͳ˷������Ҵ��ݼӷ����ʱ���ӷ������ԭ�˷����Ӱ��
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
//     tag[p] = 0, tag2[p] = 1;//�˷���ǳ�ʼ��Ϊ 1
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







//5.���ĵ�����
// �����޸Ĳ���Ϊ��Ԫ�ؼ�����Ӧ�ĵȲ������е�ֵ
// �����ԭ����[1, 6]-{0, 0, 0, 0, 0, 0} ���� [1, 6]-{1, 3, 5, 7, 9, 0}
// Ҫת��Ϊ�������ͬһ�����������뵽�乫��d����������ת��Ϊ���������� [1, 6]-{1, 2, 2, 2, 2, -9}
// ��ô�Ϳ���ά��һ���߶����������������ͣ���ѯĳ��x�ϵ�ֵ����[1, x]����ͣ�
// ��ÿ�θ��²�����������update()��1. tree[L] += k  2.tree��[L + 1, R]�϶���d  3. tree[R + 1] -= ĩ�� �� tree[R + 1] -= k + (R - L) * d
//�߶���(526ms)
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
//     for(int i = n; i >= 1; i--) a[i] = a[i] - a[i - 1];//�����������
//     build(1, 1, n);
//     while(m--)
//     {
//         ll q, L, R, k, d;
//         scanf("%lld", &q);
//         if(q == 1)
//         {
//             scanf("%lld%lld%lld%lld", &L, &R, &k, &d);
//             update(L, L, 1, 1, n, k);//���� L==R ʱ�ĵ����޸�
//             if(L != R) update(L + 1, R, 1, 1, n, d);
//             if(R < n) update(R + 1, R + 1, 1, 1, n, -(k + (R - L) * d));//��ȥĩ��
//         }else
//         {
//             scanf("%lld", &R);
//             printf("%lld\n", query(1, R, 1, 1, n));
//         }
//     }
//     return 0;
// }

//ʵ���ϱ��⾭��ת������ ���͡� ���⣬����ʹ����״�������(303ms)
//������״���鱾���ѯ����ԭ����ǰ׺�ͣ����ڱ�� ��ѯ��������ǰ׺�ͣ�����tree����ά�����ײ��
//�����±�     l-1  l   l+1    l+2   ������        r          r+1             r+2
//ԭ������ֵ    0   k   k+d    k+2d  ������    k+(r-l)*d       0               0
//һ�ײ����ֵ  0   k   d       d    ������        d       -(k+(r-l)*d)        0
//���ײ����ֵ  0   k   d-k     0    ������        0       -(k+(r-l+1)*d)  -(k+(r-l)*d)
//ʵ����tree[]�����һά��ֵ�ֵ
//*��û����⣡����������������������������������������������������������������������������������������������������������������������������������������
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
//         //������ײ�֣�����update()��ʼ��ǰ׺�ͺ�ʵ���ϱ��һ�ײ�֣�������
//         //�˴������
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
//             //��ӵ���һ�ײ�ֵ�ֵ�������ղ�ѯǰ׺�;���ĳԪ��ֵ
//             // update(L, k), update(L + 1, -k);//�����޸ģ����ڲ��������Ҫ�� L+1 �ϼ�ȥk
//             // update(L + 1, d), update(R + 1, -d);//�����޸ģ�[L + 1, R]��ÿ�������� d
//             // update(R + 1, -(k + (R - L) * d)), update(R + 2, k + (R - L) * d);//�����޸ģ�R+1 �ϼ�ȥĩ����ڲ��������Ҫ�� R+2 �ϼӻ�ĩ��
//             //������������ǰ����Ӻ�Ϊ��
//             update(L, k);
//             update(L + 1, d - k);
//             update(R + 1, -(k + (R - L + 1) * d));
//             update(R + 2, k + (R - L) * d);
//         }
//         else
//         {
//             scanf("%lld", &R);
//             printf("%lld\n", sum(R));//������[1, R] �� ԭ������R�ϵ�Ԫ��ֵ
//         }
//     }
//     return 0;
// }



//6.��ѧ����
//�������������������5e5����Ϊ����ģ�⣬���ǿ�������ըlong long���´��Ǵ��
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
// ʵ���ϣ���һ��ʱ����(1 ~ q)�Ͽ�����Ϊ��ͬʱ���ϲ�ͬ�� �ı�ֵm ���һ�����У���ʼʱֻ��һ�ξ�Ϊ 1 �����У�
// ���� ����1 �ĵ����޸ĺ�[1, q]������˾�������(��ǰ)��xֵ�����Կ���ά��һ���߶�����������ˣ�tree[1]�����ܳ�������ǰxֵ
// ���߶��������򵥣�ֻ�е����޸� -- ����1 ��ĳʱ����ֵ�޸�Ϊ m �� ����2 ��ĳʱ����ֵ�޸�Ϊ 1������ѯ����ֱ�Ӳ�ѯ[1, q]��ֵ����tree[1]
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



//***7.���в���
/*������ 01101011
            01101011
      0110           1011
   01      10     10      11
 0   1   1   0   1   0   1   1
push_up():
    1. 1�ĸ���sum�������������sum֮��
    2. ����1���������cnt��
        �� ����ӵ�cntr && �Ҷ��ӵ�cntl���� cnt = ���������������������1����cntr + �Ҷ�������������ҵ�����1����cntl
        ����һ��Ϊ0���޷����ӣ�ȡmax(�����cnt���Ҷ���cnt)
    3. ���ڷ�ת�����Ĵ��ڣ�����0�����������Ҳ��ͬ�ϴ洢�������� �Ƿ�����˷�ת ��������ȡ ����0 ���� ����1 �ĸ���
�������ȼ���ȡ���������޸���ֵ1��0������ (tag0 || tag1) == 1 ʱȡ������Ӧ�õ���������ϣ��������ȡ��������� nega_tagȡ��
����ʵ�ʲ��������м����׳���
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
//     ll sum, cnt[2], cntl[2], cntr[2];//Ҫ��ѯ��ֵ��1�ĸ���(��ɵó�0�ĸ���)������0\1��������������������0\1����cntl�����������0\1����cntr
//     ll set_tag, nega_tag;//lazy��ǣ�set_tag��ʼΪ-1����Ϊ0��1��˵����Ϊ0��1��nega_tag Ϊ1˵������ȡ������
//     ll len;//�ر�أ���һ�¸����䳤��
// }tree[N << 2];
// ll n, m;
// il void push_up(ll p)
// {
//     tree[p].sum = tree[ls].sum + tree[rs].sum;
//     for(int i = 0; i < 2; i++)
//     {
//         tree[p].cntl[i] = tree[ls].cntl[i];//�ȴ������ӵ�cntl����Ϊ��ǰ�����cntl
//         if(tree[ls].cntl[i] == tree[ls].len) tree[p].cntl[i] += tree[rs].cntl[i]; //���������ȫ1������ô��ǰ�����cntl���Լ����������ӵ�cntl
//         tree[p].cntr[i] = tree[rs].cntr[i];//ͬ��
//         if(tree[rs].cntr[i] == tree[rs].len) tree[p].cntr[i] += tree[ls].cntr[i];
//         //�������µ���cntl �� cntr�����ڸ���cnt
//         tree[p].cnt[i] = max(tree[ls].cntr[i] + tree[rs].cntl[i], max(tree[ls].cnt[i], tree[rs].cnt[i])); //�ϲ����м������� �� ���������Ӵ� �����ߵ����
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
//     if(tree[p].set_tag != -1) tree[p].set_tag ^= 1;//Ӱ����ֵ
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
//query2����д��Ҳ��
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



//8.������
//ǿ������ + �߶���
// ������Ȼ��Ҫ���߶���ά��������������ѵ�������ο����ж������������������и�ֵ�Ƿ��Ϊ 0
// ˼·������ֱ�ӱ���ȫ���������䣬1e5�����Ը��Ӷ�O(M) �����߶����Ĳ�ѯ���Ӷ� O(QlogN) -- ��ѯ���� O(M * Q * logN) �϶���TLE
//     ��ô�ص������ÿ�����������δ洢ĳ����Ϣ���Կ��ٶ�Ӧ����Щ������������й� -- vector<int>�洢���ӱ��
//     һ�����ӿ��ܶ�Ӧ�߶����Ķ�����䣬�����е�������ȫ0ʱ����ô�漰�ú��ӵ��������һ�� cnt[���ӱ��]--
//     ���漰������� 0 ���ú���ȫ����Ϊ 0 ʱ���ܼ��� lastans++
//     ÿ��update()����ʱ���жϵ�ǰҶ�ӽ���Ƿ�Ϊ0�����Ƿ��Ӧ����һ������
//     �޸Ĳ�����ֻ�� �����޸ġ� ��ѯ�������ޡ�
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
//     vector<ll> rel;//�������漰�ĺ���
// }tree[N << 2];
// ll n, m, q, lastans = 0;
// ll cnt[N];//cnt[���ӱ��] ��¼�����漰���߶����������
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
// void sign(ll L, ll R, ll p, ll pl, ll pr, ll id) //����漰����������߶������䣬idΪ����������
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
// void update(ll p, ll pl, ll pr, ll x) //�����޸�
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


//����Ϊkuanbin�ⵥ���߶���ר��
//9.�б�����
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



//11.A Simple Problem with Integers(�����)
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



//12.Balanced Lineup(���䵱ǰ��ֵ)
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
//ͬʱ��ѯ�����Сֵ��д��
// PII query(int now, int L, int R) {
//     // �ҵ���Ҫ�����䷵�������������ֵ����Сֵ�������ͺ����������жԱ� 
//     if (L <= root[now].l && root[now].r <= R) return PII(root[now].hei, root[now].low);
//     // �涨firstΪ���ֵ��secondΪ��Сֵ����ôû�ҵ��ͷ���һ������ֵ������ 
//     if (L > root[now].r || R < root[now].l) return PII(-1e9, 1e9);
//     // ����pushdown
//     // �ҵ��������������ֵ����Сֵ�ԣ�Ȼ��Ա� 
//     PII nhei = query(now << 1, L, R);
//     PII nlow = query(now << 1 | 1, L ,R); 
//     // �Ա�����������ֵ������������ֵ�����������Сֵ�����������Сֵ... 
//     return PII(max(nhei.first, nlow.first), min(nhei.second, nlow.second));
// }



//13.Just a Hook(����ֵ �� �����)
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



//*14.Mayor's posters ��һάȾɫ���� + ������ɢ������
// ��һ�����޳�����ƣ�����n����������õ�λ�ã������������ݵ�˳�����ǰ�����ܿ���������棨ע�⣬����һ����Ҳ�㣩��
// ����ת������ÿ����涼�Ƕ�����һ����ɫ�����ù���൱�ڸ�һ������Ⱦɫ����ĳ�������ж�������ɫ��
// ���� l, r <= 1e7����Ҫ��ɢ�����͸��Ӷȣ�����l��r������ɢ��Ϊ��֤����������ķ������ԣ���Ҫ��ɢʱ ���һ����
// ����������[1, 100],[1, 30],[50, 100]�����Ϊ3����������ɢ��õ�[1, 4],[1, 2],[3, 4]���´�Ϊ2�����Ӧ�ý���ɢ�����������һ����
// ��[1, 7],[1, 3],[5, 7]�����ܵõ���Ϊ3��
// unique() �ķ���ֵ��һ����ַָ��ȥ�غ����У�������в������ظ���ֵ���� ĩβ �� ��һ��Ԫ��
// v.erase(unique(v.begin(), v.end()), v.end()) ����ȥ�������к����ظ���Ԫ��
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
// void query(ll L, ll R, ll p, ll pl, ll pr)//�ص�
// {
//     if(tree[p]) //����p����ɫ�ͼ�¼
//     {
//         st.insert(tree[p]);
//         return;//����p����ɫ��˵���������¶�Ϊ�����ɫ���ʲ���������
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
//             if(v[i] - v[i - 1] > 1) // �������䲻����
//                 v.push_back(v[i - 1] + 1);
//         sort(v.begin(), v.end());
//         len = v.size();
//         for(int i = 1; i <= n; i++)
//         {
//             ll L = lower_bound(v.begin(), v.end(), que[i].first) - v.begin() + 1;//�ǵ�Ҫʹ���1��ʼ�����ü�1��
//             ll R = lower_bound(v.begin(), v.end(), que[i].second) - v.begin() + 1;
//             update(L, R, 1, 1, len, i);
//         }
//         query(1, len, 1, 1, len);
//         printf("%d\n", st.size());
//     }
//     return 0;
// }
//һά����άȾɫ���⽲�⣺https://blog.csdn.net/qq_45748404/article/details/119489831?ops_request_misc=&request_id=&biz_id=102&utm_term=Mayor%27s%20posters&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-3-119489831.142^v73^pc_search_v2,201^v4^add_ask,239^v2^insert_chatgpt&spm=1018.2226.3001.4187



//*15.Count the Colors��һάȾɫ���⣩
// ���⣺�ڳ���Ϊn���߶��ϣ�ÿ�β���������һ������Ⱦ����ɫc�����Ը���ǰ�����ɫ������������߶����ܿ�����������ɫ��
// l, r <= 8e3��������ɢ��
// �����ص����������ϵ��������(ע������[1,3][3,5]�����ɿ���[1,5]����[1,2][3,4]����������Ϊ��[2,3]�ֿ���)��
// ������Ϳɫ������������ǵ㣬Ⱦɫ����[a,b]�����ǰ�a��b�����е㶼Ⱦ��c�������䲻��ȡ�����䡣
// ��ֹ�����������ж�Ϊ��������Ҫ��һ��Ķ˵���������˵�+1 �� �Ҷ˵�-1����ֱ�����˵�ֵ��2����ʹ���������ּ����м�ֵ����Ϊ�������ֵ�����������ʵ��������
// �������ѡ���� ���ұ� ���䣬��Ⱦɫ����[l, r]��Ⱦɫ[l + 1, r]�ϵ�ÿ���㣬����һ����λ����[0, 1]������1Ⱦɫ��ͬ�ڽ�[0, 1]Ⱦɫ��
// ��Ⱦɫĳ���㣬��Ⱦɫ�õ��ǰһ�ε�λ���䡣
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
// ll tree[N << 2], ans[N], last = 0;//�ص㣺��¼�ϴ���������ɫ����˵�ϴ���������ɫ���䣬�����ų���������
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
//     if(tree[p] == d) return;//�Ż������Ѿ�Ⱦ��dɫ�����˳�
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
// void query(ll p, ll pl, ll pr)//����ÿ���߶�������
// {
//     if(tree[p])//����ɫ
//     {
//         if(tree[p] != last) 
//         {
//             ans[tree[p]]++;//����������ż���
//             last = tree[p];//����last
//         }
//         return;
//     }
//     if(pl == pr)//����Ҷ�ӽ�㶼��û��ɫ��˵����ɫ��Ƭ���Ѿ��������ˣ��Ǿͳ�ʼ��last
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



//16.Can you answer these queries? ������ת�� + update()���Ż���
//ע����Ŀ������֤ X <= Y������ÿ��ԭֵx��ȥƽ����ֵd = sqrt(x)����dҪ�������룬��ԭֵx������ȡ����ƽ����ֵ���õ�ÿ���޸� x = x - round(d) = ceil(d)
//���Ż���TLE:������[l,r]��ÿ���㶼��1ʱ��ȡƽ����ֵ����1��û�и��µı�Ҫ
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
// void update(ll L, ll R, ll p, ll pl, ll pr)//�����޸�
// {
//     if(tree[p] == pr - pl + 1) return;//*�Ż������������ÿ���㶼��1ʱ��û�и��µı�Ҫ
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



//17.Tunnel Warfare (����ϲ�����)
//���ֲ����������޸ġ��������1�ĸ��� �� ������һ�ε����޸�
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
// ll tree[N << 2], pre[N << 2], suf[N << 2];//�߶���ά���ӽڵ㣬pre��������ǰ׺�1�ĸ�����suf���������׺�1�ĸ���
// ll history[N];//���ڳ��ز�������¼��ׯ���ٵ���ʷ
// void push_up(ll p, ll len)//��������p��ǰ׺1�ͺ�׺1����
// {
//     //�ȴ��У����ж�����������ϲ����
//     pre[p] = pre[ls];
//     suf[p] = suf[rs];
//     //������������Ϊ1������Խ�ֵ�ϲ������������ǰ׺1�͡�����ͬ��
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
//     if(x <= mid)//��ѯ����������
//     {
//         //����ѯ���������ӵĺ�׺�1�����ڣ�ֱ�ӷ��������1�������������̽������
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
//                 history[++ind] = x;//���μ�¼�ƻ�����
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



//18.Hotel (����ϲ�)
//�����޸� + ͳ����������
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
//     ll sum, pre, suf;//ͳ�ƶ���Ϊ1������λ�ø���
//     ll tag;          //Ϊ0\1ʱ������Ϊ0\1
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
//     if(pl == pr && k == 1) return pl;//����
//     push_down(p, pl, pr);
//     //����˵�����С�����ѣ���->��->��
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



//*19. Assign the task (DFS�� �� ���ṹ ת��Ϊ �߶������䴦��)
// ���⣺����һ��������n����㣬ÿ��������һ����ɫ�����ԶԽ��������������������������Ⱦɫ �Լ� ��ѯĳ������ɫ
// dfs����ָ��ÿ���ڵ���dfs������ȱ����еĽ���ջ��ʱ�����С�
// �Ƚ�ͼ�������� dfs�� �� �� ���仯���������ÿ���ڵ�Ĺ�Ͻ���䣨�� ���øýڵ����� ��ʾ �Ըýڵ�Ϊ�������������Դ�ά������һ�������򵥸����ı仯
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
// ll in[N], out[N];//��¼�����dfs���Ͻ���ջ��ʱ��
// ll n, q, time = 0;//ʱ��
// ll indegree[N];//��¼��ȣ�����������
// vector<ll> G[N];
// void init()
// {
//     memset(indegree, 0, sizeof(indegree));
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
//         for(int i = 1; i < n; i++)//n����㽨һ�ŵ���������Ҫ n-1 ����
//         {
//             ll u, v;
//             scanf("%d%d", &v, &u);
//             G[u].push_back(v);
//             ++indegree[v];
//         }
//         //�洢dfsʱ������
//         for(int i = 1; i <= n; i++)
//         {
//             if(!indegree[i]) //����������һ�μ���
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



//20.Transformation (��϶����������)
// һ����Ϊn�����У�������[l,r]��4�ֲ�����ÿ������c��ÿ������c��ÿ������Ϊc����ѯÿ����p�η���������
// ˼·1���Բ�ѯ������p�η��ͣ���s[3]�ֱ����1�ε�3�η���ֵ������ʱ�����ȫƽ��ʽ����ȫ����ʽ
// ����(x + d)^3 = x^3 + 3 * x^2 * d + 3 * x * d^2 + d^3����չ������Ϊlen������õ�����(x + d)^3 = ��x^3 + 3 * d * ��(x^2) + 3 * d^2 * ��x + ��d^3
// ��tree[p].s[2] = tree[p].s[2] + 3 * d * tree[p].s[1] + 3 * d * d * tree[p].s[0] + len * d * d * d 
// (x + d)^2 = x^2 + 2*d*x + d^2��ͬ��
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
// }tree[N << 2];
// void addtag_sum(ll p, ll pl, ll pr, ll d)//ע��������͵ĸ����Ⱥ��ϵ
// {
//     ll len = pr - pl + 1;
//     tree[p].s[2] = mod(tree[p].s[2] + mod(3 * d * tree[p].s[1]) + mod(mod(3 * d * d) * tree[p].s[0]) + mod(mod(mod(len * d) * d) * d));
//     tree[p].s[1] = mod(tree[p].s[1] + mod(2 * d * tree[p].s[0]) + mod(mod(len * d) * d));
//     tree[p].s[0] = mod(tree[p].s[0] + mod(len * d));
//     tree[p].sum  = mod(tree[p].sum + d);
// }
// void addtag_mul(ll p, ll pl, ll pr, ll d)
// {
//     tree[p].s[2] = mod(mod(mod(tree[p].s[2] * d) * d) * d);
//     tree[p].s[1] = mod(mod(tree[p].s[1] * d) * d);
//     tree[p].s[0] = mod(tree[p].s[0] * d);
//     tree[p].sum  = mod(tree[p].sum * d);
//     tree[p].mul  = mod(tree[p].mul * d);
// }
// void addtag_set(ll p, ll pl, ll pr, ll d)
// {
//     ll len = pr - pl + 1;
//     tree[p].s[2] = mod(mod(mod(len * d) * d) * d);
//     tree[p].s[1] = mod(mod(len * d) * d);
//     tree[p].s[0] = mod(len * d);
//     tree[p].setx = d;
//     tree[p].mul = 1;//���´��ݸ�����Ϣ
//     tree[p].sum = 0;
// }
// void push_up(ll p)
// {
//     for(int i = 0; i < 3; i++) tree[p].s[i] = mod(tree[ls].s[i] + tree[rs].s[i]);
// }
// void push_down(ll p, ll pl, ll pr)//ע���Ǹ��µ��Ⱥ��ϵ�͸�����
// {
//     ll mid = pl + pr >> 1;
//     if(tree[p].setx != -1)//�����������
//     {
//         addtag_set(lc, tree[p].setx);
//         addtag_set(rc, tree[p].setx);
//         tree[p].setx = -1;
//     }

//     if(tree[p].mul != 1)
//     {
//         addtag_mul(lc, tree[p].mul);
//         addtag_mul(rc, tree[p].mul);
//         tree[p].mul = 1;
//     }
//     if(tree[p].sum)
//     {
//         addtag_sum(lc, tree[p].sum);
//         addtag_sum(rc, tree[p].sum);
//         tree[p].sum = 0;
//     }
//     // tree[p].sum = 0, tree[p].mul = 1, tree[p].setx = -1;
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p].s[0] = tree[p].s[1] = tree[p].s[2] = tree[p].sum = 0;
//     tree[p].mul = 1, tree[p].setx = -1;
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     build(lc);
//     build(rc);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll op, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
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
//     while(~scanf("%d%d", &n, &m))//while(~scanf("%d%d", &n, &m), n) ��WA
//     {
//         if(n + m == 0) break;
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



//*21.Vases and Flowers (�߶��� + ����)
// ����1����A��ʼ��ֻ�Կ�ƿ�廨������F�仨��ƿ������ʱֹͣ������2���൱���� ������� �� �������
// ����2ʵ�ּ򵥣�������1��Ҫ���� �߶����Ķ��ֽṹ ȥ �������� ��һ�� �� ���һ�� ��ƿ��λ��
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll int
// const int N = 5e4 + 5;
// ll n, m;
// ll tree[N << 2], tag[N << 2];
// void push_up(ll p) {tree[p] = tree[ls] + tree[rs];}
// void push_down(ll p, ll pl, ll pr)
// {
//     if(tag[p] != -1)
//     {
//         ll mid = pl + pr >> 1;
//         tree[ls] = tag[p] * (mid - pl + 1);
//         tree[rs] = tag[p] * (pr - mid);
//         tag[ls] = tag[rs] = tag[p];
//         tag[p] = -1;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = 0, tag[p] = -1;
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     build(lc);
//     build(rc);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         tree[p] = d * (pr - pl + 1);
//         tag[p] = d;
//         return;
//     }
//     push_down(p, pl, pr);
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
//     push_up(p);
// }
// ll query_sum(ll L, ll R, ll p, ll pl, ll pr)
// {
//     if(L <= pl && R >= pr) return tree[p];
//     push_down(p, pl, pr);
//     ll mid = pl + pr >> 1, res = 0;
//     if(L <= mid) res += query_sum(L, R, lc);
//     if(R > mid) res += query_sum(L, R, rc);
//     return res;
// }
// ll query_ind(ll st, ll cnt)//cntΪҪ�ҵڼ���0
// {
//     ll l = st, r = n, res = -1;
//     while(l <= r)
//     {
//         ll mid = l + r >> 1;
//         ll sum = mid - st + 1 - query_sum(st, mid, 1, 1, n);
//         if(sum >= cnt) res = mid, r = mid - 1;//������֣������Ҷ�
//         else l = mid + 1;
//     }
//     return res;
// }
// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%d%d", &n, &m);
//         build(1, 1, n);
//         while(m--)
//         {
//             ll op, a, b, posl, posr;
//             scanf("%d%d%d", &op, &a, &b);
//             ++a;
//             if(op == 1)
//             {
//                 posl = query_ind(a, 1);//��1���ջ�ƿλ��
//                 if(posl == -1)//���һ����û�о����
//                     printf("Can not put any one.\n");
//                 else
//                 {
//                     ll sum = n - posl + 1 - query_sum(posl, n, 1, 1, n);//�����жϸ��Ļ��ǲ��Ǳȿջ�ƿ��
//                     posr = query_ind(a, min(b, sum));//��b���ջ�ƿλ��
//                     printf("%d %d\n", posl - 1, posr - 1);
//                     update(posl, posr, 1, 1, n, 1);
//                 }
//             }
//             else
//             {
//                 ++b;
//                 printf("%d\n", query_sum(a, b, 1, 1, n));
//                 update(a, b, 1, 1, n, 0);
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }



//22.Լ�ᰲ�� (ͬʱά���������䣬������֮����е��򸲸ǹ�ϵ + ά����������г���)
// ά������ʱ������ DS��NS����Ҫ��¼����0����(�ǰ׺���������׺���� �� �������)
// tree[0][] -- DS
// tree[1][] -- NS
// DS T �� NS T ��Ҫ����һ�α���ǰ�ĳ�ΪT���������пռ䣬�� NS ���û�ҵ������ռ�� DS �Ŀռ䣻 STUDY!! L R ��ʾ���[L, R]����
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll int
// const int N = 1e5 + 5;
// struct nd{
//     ll pre, suf, cnt;//1�����пռ�
//     ll tag;
//     nd(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {pre = a, suf = b, cnt = c, tag = d;}
// }tree[2][N << 2];
// ll n, m, _;
// void addtag(ll p, ll pl, ll pr, ll ind, ll d)
// {
//     ll len = pr - pl + 1, x = d * len;
//     tree[ind][p] = nd(x, x, x, d);
// }
// void push_up(ll p, ll pl, ll pr, ll i)
// {
//     ll len = pr - pl + 1;
//     tree[i][p].pre = tree[i][ls].pre;
//     tree[i][p].suf = tree[i][rs].suf;
//     if(tree[i][p].pre == len - (len >> 1)) tree[i][p].pre += tree[i][rs].pre;
//     if(tree[i][p].suf == (len >> 1)) tree[i][p].suf += tree[i][ls].suf;
//     tree[i][p].cnt = max(max(tree[i][ls].cnt, tree[i][rs].cnt), tree[i][ls].suf + tree[i][rs].pre);
// }
// void push_down(ll p, ll pl, ll pr, ll i)
// {
//     ll mid = pl + pr >> 1;
//     if(tree[i][p].tag != -1)
//     {
//         addtag(lc, i, tree[i][p].tag);
//         addtag(rc, i, tree[i][p].tag);
//         tree[i][p].tag = -1;
//     }
// }
// void build(ll p, ll pl, ll pr)
// {
//     ll len = pr - pl + 1;
//     for(int i = 0; i < 2; i++) tree[i][p] = nd(len, len, len, -1);
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     build(lc);
//     build(rc);
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll ind, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         addtag(p, pl, pr, ind, d);
//         return;
//     }
//     push_down(p, pl, pr, ind);
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, lc, ind, d);
//     if(R > mid) update(L, R, rc, ind, d);
//     push_up(p, pl, pr, ind);
// }
// ll query(ll p, ll pl, ll pr, ll ind, ll d)
// {
//     if(pl == pr) return pl;
//     push_down(p, pl, pr, ind);
//     ll mid = pl + pr >> 1;
//     if(tree[ind][ls].cnt >= d) return query(lc, ind, d);
//     else if(tree[ind][ls].suf + tree[ind][rs].pre >= d) return mid - tree[ind][ls].suf + 1;
//     else return query(rc, ind, d);
// }
// int main()
// {
//     scanf("%d", &_);
//     for(int __ = 1; __ <= _; __++)
//     {
//         printf("Case %d:\n", __);
//         scanf("%d%d", &n, &m);
//         build(1, 1, n);
//         while(m--)
//         {
//             char op[5];
//             ll T, L, R, pos;
//             scanf("%s", &op);
//             if(op[0] == 'D')
//             {
//                 scanf("%d", &T);
//                 if(tree[0][1].cnt < T)//tree[0] ͬʱ��NS��DS����ռ�������Ӱ�죬�� DS ֻ����tree[0]
//                 {
//                     printf("fly with yourself\n");
//                     continue;   
//                 }
//                 //DS����ֻӰ��tree[0]
//                 pos = query(1, 1, n, 0, T);
//                 update(pos, pos + T - 1, 1, 1, n, 0, 0);
//                 printf("%d,let's fly\n", pos);
//             }
//             else if(op[0] == 'N')
//             {
//                 ll res;
//                 scanf("%d", &T);
//                 if(tree[1][1].cnt < T)
//                 {
//                     printf("wait for me\n");
//                     continue;
//                 }
//                 if(tree[0][1].cnt >= T)        //�������⿴DS�����Ƿ����㹻��������������
//                     res = query(1, 1, n, 0, T);
//                 else                           //�١�����DS����ռ�á���
//                     res = query(1, 1, n, 1, T);

//                 update(res, res + T - 1, 1, 1, n, 0, 0);
//                 update(res, res + T - 1, 1, 1, n, 1, 0);
//                 printf("%d,don't put my gezi\n", res);
//             }
//             else
//             {
//                 scanf("%d%d", &L, &R);
//                 update(L, R, 1, 1, n, 0, 1);
//                 update(L, R, 1, 1, n, 1, 1);
//                 printf("I am the hope of chinese chengxuyuan!!\n");
//             }
//         }
//     }
//     return 0;
// }



//*23.Picture (ɨ���� - �����ܳ���)
// ��n�����Σ���n�����κϲ�����ܳ��Ƕ��١�(���ݶ�������)
// �ص㣺�жϵ�ǰɨ�����Ƿ����г��������ǣ��������ܼ����ɨ����
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cmath>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define ll int
// const ll N = 1e4 + 5;//����һ��Ҫ������
// struct Line{
//     ll lx, rx, h, d;
//     Line(ll a = 0, ll b = 0, ll c = 0, ll dd = 0) {lx = a, rx = b, h = c, d = dd;}
//     bool operator <(const Line &m) const{ return h < m.h;}
// }line[N << 1];
// struct nd{
//     ll len;               //����Ч����
//     bool l_cover, r_cover;//����߶����Ҷ˵��Ƿ񱻸���
//     nd(ll s = 0, bool a = 0, bool b = 0) {len = s, l_cover = a, r_cover = b;}
// }tree[N << 2];
// ll n, ind = 0, ans = 0, last = 0;
// ll cnt[N << 2], num[N << 2], xx[N];//cnt��¼������߳����������num��¼�������ж������������߶��Լ�����ж��ٶ�����
// void push_up(ll p, ll pl, ll pr)
// {
//     if(cnt[p])            //����p��Ч������������p�ѱ���ȫ���ǣ����ʱ�����߶θ�����1��
//     {
//         tree[p] = nd(xx[pr] - xx[pl], 1, 1);
//         num[p] = 1;
//     }
//     else if(pl + 1 == pr)
//     {
//         tree[p] = nd(0, 0, 0);
//         num[p] = 0;       //����ǵ����Ϊ0����Ϊ���ߺ�Ҷ�ӽڵ��Ѿ��޷���������ȡ����Ч���ȣ�ӵ�е��߶�������ȻҲ����Ϊ0
//     }
//     else                  //���ϴ��ݸ����ԡ���Ч���� �� �����߶θ���
//     {
//         tree[p] = nd(tree[ls].len + tree[rs].len, tree[ls].l_cover, tree[rs].r_cover);
//         num[p] = num[ls] + num[rs];
//         if(tree[ls].r_cover && tree[rs].l_cover) num[p]--;//�������߶κϲ�
//     }
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         cnt[p] += d;
//         push_up(p, pl, pr);
//         return;
//     }
//     if(pl + 1 == pr) return;
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d);
//     if(R > mid) update(L, R, rs, mid, pr, d);

//     push_up(p, pl, pr);
//     // Ҳ���Էֳ���д    
//     // if(!cnt[p])
//     // {
//     //     tree[p] = nd(tree[ls].len + tree[rs].len, tree[ls].l_cover, tree[rs].r_cover);
//     //     num[p] = num[ls] + num[rs];
//     //     if(tree[ls].r_cover && tree[rs].l_cover) num[p]--;
//     // }
// }
// int main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)
//     {
//         ll x1, y1, x2, y2;
//         scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//         line[++ind] = Line(x1, x2, y1, 1);
//         xx[ind] = x1;
//         line[++ind] = Line(x1, x2, y2, -1);
//         xx[ind] = x2;
//     }
//     sort(line + 1, line + 1 + ind);
//     sort(xx + 1, xx + 1 + ind);
//     ll max_x = unique(xx + 1, xx + 1 + ind) - xx - 1;
//     for(int i = 1; i <= ind; i++)
//     {
//         ll L = lower_bound(xx + 1, xx + 1 + max_x, line[i].lx) - xx;
//         ll R = lower_bound(xx + 1, xx + 1 + max_x, line[i].rx) - xx;
//         update(L, R, 1, 1, max_x, line[i].d);
//         ans += 2 * num[1] * (line[i + 1].h - line[i].h);//�����߳�(2 * ���߶���num * ����)
//         ans += abs(tree[1].len - last);                 //�ױ߳�(��ȥ�˸��ǲ���)
//         last = tree[1].len;
//     }
//     printf("%d\n", ans);
//     return 0;
// }



//*24.���ǵ���� ��ɨ���߽��ף�
//д��1�����䴦��Ϊ[L, R - 1]���߶���Ҷ�ӽ��Ϊһ���㼴��[1, 1], [3, 3] -- ʵ���Ϸֱ��������[1, 2], [3, 4]
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define ll int
// #define db double
// const ll N = 1e5 + 5;
// ll n, T;
// ll cnt[N];
// db tree[N], tree2[N], xx[N];//tree[]ά��������Ч���ȣ�tree2[]ά�������ǵ���Ч����
// struct Line{
//     db lx, rx, h;
//     ll d;
//     Line(){}
//     Line(db a, db b, db c, ll dd) {lx = a, rx = b, h = c, d = dd;}
//     bool operator <(const Line &m) const{ return h < m.h;}
// }line[N];
// void push_up(ll p, ll pl, ll pr)
// {
//     if(cnt[p])
//         tree[p] = xx[pr + 1] - xx[pl];//ע��Ҫ�߶���������[1, 2]����ʵ������[1, 3]�����Ȱ�ʵ�����䳤����
//     else if(pl == pr)
//         tree[p] = 0;
//     else
//         tree[p] = tree[ls] + tree[rs];

//     if(cnt[p] > 1)
//         tree2[p] = xx[pr + 1] - xx[pl];
//     else if(pl == pr)
//         tree2[p] = 0;
//     else if(cnt[p] == 1)
//         tree2[p] = tree[ls] + tree[rs];
//     else
//         tree2[p] = tree2[ls] + tree2[rs];
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         cnt[p] += d;
//         push_up(p, pl, pr);
//         return;
//     }
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d);
//     if(R > mid) update(L, R, rs, mid + 1, pr, d);
//     push_up(p, pl, pr);
// }
// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         memset(cnt, 0, sizeof(cnt));
//         memset(tree, 0, sizeof(tree));
//         memset(tree2, 0, sizeof(tree2));
//         db ans = 0;
//         ll ind = 0;
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++)
//         {
//             db x1, y1, x2, y2;
//             scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//             line[++ind] = Line(x1, x2, y1, 1);
//             xx[ind] = x1;
//             line[++ind] = Line(x1, x2, y2, -1);
//             xx[ind] = x2;
//         }
//         sort(line + 1, line + 1 + ind);
//         sort(xx + 1, xx + 1 + ind);
//         ll num = unique(xx + 1, xx + 1 + ind) - xx - 1;
//         for(int i = 1; i <= ind; i++) 
//         {
//             ans += tree2[1] * (line[i].h - line[i - 1].h);
//             ll L = lower_bound(xx + 1, xx + 1 + num, line[i].lx) - xx;
//             ll R = lower_bound(xx + 1, xx + 1 + num, line[i].rx) - xx;
//             update(L, R - 1, 1, 1, num, line[i].d);
//         }
//         printf("%.2lf\n", ans);
//     }
//     return 0;
// }


//д��2�����߶���Ҷ�ӽ����Ϊ[pl, pl + 1]�����趨��С�����һ������Ϊ1��С����
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define ll int
// #define db double
// const ll N = 1e5 + 5;
// ll n, T;
// ll cnt[N];
// db tree[N], tree2[N], xx[N];//tree[]ά����Ч����len1(���ٸ��ǹ�һ��)��tree2[]ά�����ٱ��������ε���Ч����len2
// struct Line{
//     db lx, rx, h;
//     ll d;
//     Line(){}
//     Line(db a, db b, db c, ll dd) {lx = a, rx = b, h = c, d = dd;}
//     bool operator <(const Line &m) const{ return h < m.h;}
// }line[N];
// void push_up(ll p, ll pl, ll pr)
// {
//     //len1
//     if(cnt[p])
//         tree[p] = xx[pr] - xx[pl];
//     else if(pl + 1 == pr)
//         tree[p] = 0;
//     else
//         tree[p] = tree[ls] + tree[rs];
    
//     //����len2�ĸ�������������ۣ�
//     //����һ�� ���� �� ���� �� (cnt[p] += d)��
//     //1. ������p���ٹ���һ������ȫ���ǹ�����ʱ����ʱ cnt[p] >= 2��˵������p������Ч���ǳ���len2���� tree2[p] = xx[pr] - xx[pl]
//     //2. ������pû�ﵽ��Ч����Ҫ����ΪҶ�ӽ��(�����ǳ���Ϊ1����С����)ʱ��û�취��������ȡ���ȣ�ֻ�� tree2[p] = 0
//     //3. ������p(��Ҷ��)��һ������ȫ���ǹ�һ��ʱ����ʱcnt[p] == 1��˵�������ʸ����´���������ȡͬ�����������ǹ�һ�εĳ���len1���ⲿ�ּ������͸���������
//     //   �� tree2[p] = tree[ls] + tree[rs] 
//     //4. ������p(��Ҷ��)��û��һ������ȫ���ǹ�ʱ����ʱcnt[p] == 0��ע��ֻ��û��һ���Ը����꣬�������Դ�������len2��ȡ��Ч���ǳ���
//     //   �� tree2[p] = tree2[ls] + tree2[rs]
//     if(cnt[p] > 1)
//         tree2[p] = xx[pr] - xx[pl];//��len2�����ٸ�������ʱ ������Ч
//     else if(pl + 1 == pr)
//         tree2[p] = 0;
//     else if(cnt[p] == 1)//�ص�
//         tree2[p] = tree[ls] + tree[rs];
//     else
//         tree2[p] = tree2[ls] + tree2[rs];
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         cnt[p] += d;
//         push_up(p, pl, pr);
//         return;
//     }
//     if(pl + 1 == pr) return;
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d);
//     if(R > mid) update(L, R, rs, mid, pr, d);
//     push_up(p, pl, pr);
// }
// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         memset(cnt, 0, sizeof(cnt));
//         memset(tree, 0, sizeof(tree));
//         memset(tree2, 0, sizeof(tree2));
//         db ans = 0;
//         ll ind = 0;
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++)
//         {
//             db x1, y1, x2, y2;
//             scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//             line[++ind] = Line(x1, x2, y1, 1);
//             xx[ind] = x1;
//             line[++ind] = Line(x1, x2, y2, -1);
//             xx[ind] = x2;
//         }
//         sort(line + 1, line + 1 + ind);
//         sort(xx + 1, xx + 1 + ind);
//         ll num = unique(xx + 1, xx + 1 + ind) - xx - 1;
//         for(int i = 1; i <= ind; i++) 
//         {
//             ans += tree2[1] * (line[i].h - line[i - 1].h);
//             ll L = lower_bound(xx + 1, xx + 1 + num, line[i].lx) - xx;
//             ll R = lower_bound(xx + 1, xx + 1 + num, line[i].rx) - xx;
//             update(L, R, 1, 1, num, line[i].d);
//         }
//         printf("%.2f\n", ans);
//     }
//     return 0;
// }



//25.Atlantis ��ɨ���� - �����������
// ���⣺x-y����ϵ�������ɸ����Σ����ǵı߷ֱ�ƽ�����������ᣬ�����ǵ�������������������Ҫ���ظ��������ֻ����һ�Ρ�
// ע�⣺ɨ�������⡣����x, y��ʵ������Ҫ��ɢ�����������߶���ά������x�����䳤�ȣ��������伴�����㣬������[2, 2]�ȵ㲻�������壬�����߶�����Ҷ�ӽ��Ϊ����[pl, pl + 1]
// ����ԭ����������ɨ���ߣ�ֻҪ��û�������Ӧ�ĳ���ʱ������߳���һֱ��Ч��ָ���ڵ�ǰ�¾��εĵױ߳��ȣ���ÿ�λ�õ���ǰ������Ч����tree[1]�������¾��εĵױ߳���
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define ll int
// #define db double
// const int N = 1e3 + 5;
// ll n, cnt[N << 2];//cnt[p] ��¼��ǰ����p�����ǵĴ������������ڵ��޹ء����жϸ����䳤���Ƿ���Ч
// //һ���ڵ��������䱻���ǵĴ�������Ҫ�̳��丸�׵���Ϣ��ÿ�����һһ��Ӧһ���ȳ��ĳ��ߣ��ɸ���߲����ĸ��Ǵ���cntӦ�����Ӧ���ߵ��������ȥ��pushdown
// db tree[N << 2], X[N << 2];
// struct Line{
//     db lx, rx, y;
//     ll d;//1Ϊ��ߣ�-1Ϊ����
//     Line(db a = 0, db b = 0, db c = 0, ll dd = 0) {lx = a, rx = b, y = c, d = dd;}
//     bool operator <(const Line &x) const{ return y < x.y;}
// }line[N << 2];
// void push_up(ll p, ll pl, ll pr)
// {
//     if(cnt[p]) 
//         tree[p] = X[pr] - X[pl];
//     //����p������Чʱ
//     else if(pl + 1 == pr)//Ҷ�ӽ��û�취������ȡ��Ч���ȣ�������û����Ч�����Ŷ�ռ�ã���Ϊ0����
//         tree[p] = 0;
//     else
//         tree[p] = tree[ls] + tree[rs];//������ȡ��Ч���ȣ�����˵�������Ч����ռ������p�ˣ�
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         cnt[p] += d;
//         push_up(p, pl, pr);
//         return;
//     }
//     if(pl + 1 == pr) return;
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, ls, pl, mid, d);
//     if(R > mid) update(L, R, rs, mid, pr, d); //ע�����ﲻ�� mid + 1

//     if(!cnt[p]) tree[p] = tree[ls] + tree[rs];
//     //������pû����Ч����ʱ�Ŵ�ֵ����Ϊ������p�Ѿ���Ч��˵�����Ѿ�����ĸ��ǳ���pr-pl����ֱ�Ӵ�ֵ������ظ����������Ч�ĳ��ȡ�
//     //Ӧ������p�����ߵ���ʱ���Ű�������ֵ����������������˳��ġ�
//     push_up(p, pl, pr);
// }
// int main()
// {
//     int _ = 1;
//     while(~scanf("%d", &n))
//     {
//         if(!n) break;
//         memset(tree, 0, sizeof(tree));
//         memset(cnt, 0, sizeof(cnt));
//         db ans = 0;
//         ll ind = 0;
//         for(int i = 0; i < n; i++)
//         {
//             db x1, y1, x2, y2;
//             scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//             line[++ind] = Line(x1, x2, y1, 1);
//             X[ind] = x1;
//             line[++ind] = Line(x1, x2, y2, -1);
//             X[ind] = x2;
//         }
//         sort(X + 1, X + 1 + ind);
//         sort(line + 1, line + 1 + ind);
//         ll max_x = unique(X + 1, X + 1 + ind) - X - 1;
//         for(int i = 1; i <= ind; i++)
//         {
//             ans += tree[1] * (line[i].y - line[i - 1].y);//��һ���߲��������
//             ll L = lower_bound(X + 1, X + 1 + max_x, line[i].lx) - X;
//             ll R = lower_bound(X + 1, X + 1 + max_x, line[i].rx) - X;
//             update(L, R, 1, 1, max_x, line[i].d);
//         }
//         printf("Test case #%d\nTotal explored area: %.2lf\n\n", _++, ans);
//     }
//     return 0;
// }



//*26.Get The Treasury ����άɨ���� - ��������� + ö�٣�
// �ο���https://blog.csdn.net/qq_41280600/article/details/104094400
// ���⣺�����ɸ����壨�����壩���������غ����ε����֮�͡�
// ˼·��ά��x, y���������ö�� z (|z| < 500 ��Ϊ����)��ÿ��ö�ٶ��൱��Ѱ�Ҹ߶�Ϊ1�ľ��������ص����ֵ���� -- ���Ԫ��
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define ls (p << 1)
// #define rs (p << 1 | 1)
// #define lc ls, pl, mid
// #define rc rs, mid + 1, pr
// #define ll long long
// const ll N = 2e4 + 5;
// ll n, T, cnt[N << 2];
// ll xx[N], yy[N], zz[N];
// struct Line{
//     ll lx, rx, y, d;
//     ll z1, z2;//��������߶ȷ�Χ
//     Line(ll a = 0, ll b = 0, ll c = 0, ll dd = 0, ll e = 0, ll f = 0){ lx = a, rx = b, y = c, d = dd, z1 = e, z2 = f;}
//     bool operator <(const Line &m) const{ return y < m.y;}
// }line[N];
// struct nd{
//     ll len1, len2, len3;
//     nd(ll l1 = 0, ll l2 = 0, ll l3 = 0) {len1 = l1, len2 = l2, len3 = l3;}
// }tree[N << 2];
// void build(ll p, ll pl, ll pr)
// {
//     tree[p] = nd(0, 0, 0);
//     cnt[p] = 0;
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     build(lc);
//     build(rc);
// }
// void push_up(ll p, ll pl, ll pr)                                      //�ǵ� xx[pr + 1] - xx[pl]
// {
//     if(cnt[p]) tree[p].len1 = xx[pr + 1] - xx[pl];
//     else if(pl == pr) tree[p].len1 = 0;
//     else tree[p].len1 = tree[ls].len1 + tree[rs].len1;

//     if(cnt[p] >= 2) tree[p].len2 = xx[pr + 1] - xx[pl];
//     else if(pl == pr) tree[p].len2 = 0;
//     else if(cnt[p] == 1) tree[p].len2 = tree[ls].len1 + tree[rs].len1;//ֻ��һ�θ��ǣ���len1��
//     else tree[p].len2 = tree[ls].len2 + tree[rs].len2;

//     if(cnt[p] >= 3) tree[p].len3 = xx[pr + 1] - xx[pl];
//     else if(pl == pr) tree[p].len3 = 0;
//     else if(cnt[p] == 2) tree[p].len3 = tree[ls].len1 + tree[rs].len1;//ֻ��һ�θ��ǣ���len1��
//     else if(cnt[p] == 1) tree[p].len3 = tree[ls].len2 + tree[rs].len2;//�������θ��ǣ���len2��
//     else tree[p].len3 = tree[ls].len3 + tree[rs].len3;
    
// }
// void update(ll L, ll R, ll p, ll pl, ll pr, ll d)
// {
//     if(L <= pl && R >= pr)
//     {
//         cnt[p] += d;
//         push_up(p, pl, pr);
//         return;
//     }
//     if(pl == pr) return;
//     ll mid = pl + pr >> 1;
//     if(L <= mid) update(L, R, lc, d);
//     if(R > mid) update(L, R, rc, d);
//     push_up(p, pl, pr);
// }
// int main()
// {
//     scanf("%lld", &T);
//     for(int _ = 1; _ <= T; _++)
//     {
//         ll ind = 0, ans = 0;
//         scanf("%lld", &n);

//         for(int i = 1; i <= n; i++)
//         {
//             ll x1, y1, z1, x2, y2, z2;
//             scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &z1, &x2, &y2, &z2);
//             line[++ind] = Line(x1, x2, y1, 1, z1, z2);
//             xx[ind] = x1, zz[ind] = z1;
//             line[++ind] = Line(x1, x2, y2, -1, z1, z2);
//             xx[ind] = x2, zz[ind] = z2;
//         }

//         sort(xx + 1, xx + 1 + ind);
//         sort(line + 1, line + 1 + ind);
//         ll num_x = unique(xx + 1, xx + 1 + ind) - xx - 1;

//         for(int z = -500; z <= 500; z++)             //�����������Ԫ
//         {
//             build(1, 1, num_x);
//             ll area = 0, last = 0;                   //ɨ����������������
//             for(int i = 1; i <= ind; i++)            //���������������Ԫ���ڵľ����������"ɨ����"
//             {
//                 if(line[i].z1 <= z && z < line[i].z2)//һ����������Ԫ����Ϊ z2 - z1 ���������� [z1, z2)��������ǡ���Ǹþ�������
//                 {
//                     //���ﲻ��ֱ�� line[i].y - line[i-1].y����Ϊ�ʼһ��ɨ��line[i-1].y��һ������line[0].y ����һ��Ϊ0�����Ժܿ��ܼ�����
//                     //��Ҳ��û�ж� Z���� ��ɢ������ı׶�
//                     area += tree[1].len3 * (line[i].y - last);
//                     last = line[i].y;
//                     ll L = lower_bound(xx + 1, xx + 1 + num_x, line[i].lx) - xx;
//                     ll R = lower_bound(xx + 1, xx + 1 + num_x, line[i].rx) - xx;
//                     update(L, R - 1, 1, 1, num_x, line[i].d);
//                 }
//             }
//             ans += area;                             //�൱�ڼ�һ����Ϊ1�ľ������ ans += 1 * area
//         }
//         printf("Case %d: %lld\n", _, ans);
//     }
//     return 0;
// }


















//���⣺zkw�߶�����ʲô��


























































/*��״���飨Binary Indexed Tree, BIT��-- O(logn) -- һ���������Ķ������������м�������״�ṹ
���ڸ�Ч�� ��ѯ��ά�� ǰ׺�͡�ǰ׺���ȣ���ֻ��ά���������͡���
��״���������Լ��ı����Ч�������²���
    ��ѯǰ׺��sum:
        ��ѯ�Ĺ����� ÿ��ȥ����Ŷ��������� 1 ����λ������ ǰ7������ sum(7) = tree[7] + tree[6] + tree[4]��
        ��ϸ�أ����7 ������Ϊ 111��ȥ������ 1���� 110������λ�� tree[6]�����Ӹ�ֵ��
        Ȼ�� 110 ȥ������ 1���� 100����λ�� tree[4]���������ӣ���� 100 ȥ��1��Ϊ 0�����ѯ��ϡ�
    ά���������Զ�̬��������Ԫ��(�Ǿ�̬����):
        ά���Ĺ����� ÿ���ڱ�ŵĶ��������� 1 �ϼ� 1�������� 1 ��һλ�������統������Ԫ�� a3 ʱ�����˸���tree[3]��Ҫ����tree[4]��tree[8]��
        ��ϸ�أ����3 ������Ϊ 011������ 1 �ϼ� 1���� 100����λ��tree[4]����������£�
        Ȼ�� 100 ���� 1 ��λ�� 1000����λ��tree[8]������tree[16]��tree[32]�������Դ�����ֱ�� N��
    �����޸ģ� 
        update(ind, val)
    �����޸ģ�
        ���� ǰ׺�� �� ��� �����ʣ�Ҳ���Խ� �����޸� ��չΪ �����޸�
        ֻ��Ҫ�����䣺update(L, 1)��update(R + 1, -1)

ע�����
1.ȡ�����������һ�� 1 �ú��� lowbit()���践��ֵΪ m����ôtree[i] = Ai + Ai-1 + ������ + Ai-m+1���� tree[i] ��ֵΪ ����ai��ǰm�����ĺ͡�
2.�����޸ĺ�ÿ��Ԫ�� ai ����Ҫ�� sum(i) - sum(i - 1) ��ã�����ĳ�κ�Ҳ��һ�����������ֵ�����
3.ԭ����a[N]һ���ǲ���Ҫ�ģ���Ϊԭֵ��Ҫֱ�Ӹ��µ�tree��

��Ч����˵�����ֻ�������(��)�����Ƽ�д��״���飬���뾫���߶����Ŀռ临�Ӷȳ����ϴ�ռ�ÿռ�Ҳ���ࡣ����״����ͨ���ٶȸ��졣

ǰ׺��ģ�壺
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
            update(x, k);//�����޸�
            // update(x, k), update(y + 1, -k);//�����޸ģ�[L, R]��ÿ�������� k
        }
        else
        {
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", sum(y) - sum(x - 1));//������
        }
    }
    return 0;
}


*/



//1.P3374 ��״���� 1�������޸� + �����ѯ ģ�壩
//��״����д��(492ms�����Ը���)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 5e5 + 10;
// int n, m;
// int tree[N];
// void update(int x,int d)
// {
//     for(; x <= n; x += lowbit(x))
//         tree[x] += d;
// }
// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += tree[x];
//     return res;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++)
//     {
//         int x;
//         scanf("%d", &x);
//         update(i, x);
//     }
//     while(m--)
//     {
//         int op, x, y;
//         scanf("%d%d%d", &op, &x, &y);
//         if(op == 1) update(x, y);
//         else printf("%d\n", sum(y) - sum(x - 1));
//     }
//     return 0;
// }



//2. hdu 1166 �б�����
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 5e4 + 10;
// int n, T;
// int tree[N];
// char op[10];
// void update(int x,int d)
// {
//     for(; x <= n; x += lowbit(x))
//         tree[x] += d;
// }
// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += tree[x];
//     return res;
// }
// int main()
// {
//     scanf("%d", &T);
//     for(int _ = 1; _ <= T; ++_)
//     {
//         memset(tree, 0, sizeof(tree));//�ǵó�ʼ��

//         printf("Case %d:\n", _);
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++)
//         {
//             int d;
//             scanf("%d", &d);
//             update(i, d);
//         }
//         while(~scanf("%s", op))
//         {
//             if(op[0] == 'E') break;
//             int x, y;
//             scanf("%d%d", &x, &y);
//             if(op[0] == 'A') update(x, y);
//             else if(op[0] == 'S') update(x, -y);
//             else printf("%d\n", sum(y) - sum(x - 1));
//         }
//     }
//     return 0;
// }



//3.P3368 ��״���� 2�������޸� + �����޸� ģ�壩
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 5e5 + 10;
// int a[N], tree[N];
// int n, m;
// void update(int x, int d)
// {
//     for(; x <= n; x += lowbit(x))
//         tree[x] += d;
// }
// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += tree[x];
//     return res;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; ++i) 
//     {
//         scanf("%d", &a[i]);
//         update(i, a[i] - a[i - 1]);//������
//     }
//     while(m--)
//     {
//         int op, x, y;
//         ll k;
//         scanf("%d", &op);
//         if(op == 1)
//         {
//             scanf("%d%d%d", &x, &y, &k);
//             update(x, k);
//             update(y + 1, -k);
//         }
//         else//��ʱǰ׺�� [1, x] ��ԭ��ֵa[x]
//         {
//             scanf("%d", &x);
//             printf("%d\n", sum(x));
//         }
//     }
//     return 0;
// }



//4.�߶��� 1
//��״����д��(ά���������ڲ���������״����)��t1[N] -> ��b[i] �� t2[N] -> ��(i * b[i])
//https://www.luogu.com.cn/problem/solution/P3372
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e5 + 10;
// ll t1[N], t2[N];
// int n, m;
// void update(ll x, ll d)
// {

//     for(int i = x; i <= n; i += lowbit(i))
//     {
//         t1[i] += d;
//         t2[i] += x * d;
//     }
// }
// ll sum(ll x)//��ѯǰ׺�� ��a[1 .. x]
// {
//     ll res = 0;
//     for(int i = x; i > 0; i -= lowbit(i))
//     {
//         res += (x + 1) * t1[i] - t2[i];
//     }
//     return res;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     ll now, last = 0;
//     for(int i = 1; i <= n; ++i)
//     {
//         scanf("%lld", &now);
//         update(i, now - last);
//         //�൱��ÿ�ζ����� b[i] �� i * b[i],Ȼ��
//         //��     b[i] ���µ� t1[] �������йؽ��
//         //�� i * b[i] ���µ� t2[] �������йؽ��
//         last = now;
//     }
//     while(m--)
//     {
//         ll op, x, y, k;
//         scanf("%lld%lld%lld", &op, &x, &y);
//         if(op == 1) 
//         {
//             scanf("%lld", &k);
//             //ʵ��ά���Ķ��ǲ������ b[i]
//             update(x, k);
//             update(y + 1, -k);
//         }
//         else
//         {
//             printf("%lld\n", sum(y) - sum(x - 1));
//         }
//     }
//     return 0;
// }
//ע�⿪ long long ���������
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e5 + 10;
// ll t1[N], t2[N];
// int n, m;

// void update(ll x, ll d)
// {
//     for(int i = x; i <= n; i += lowbit(i))
//     {
//         t1[i] += d;    
//         t2[i] += x * d;
//     }
// }
// ll sum(ll x)//��ѯǰ׺�� ��a[1 .. x]
// {
//     ll res = 0;
//     for(int i = x; i > 0; i -= lowbit(i))
//     {
//         res += (x + 1) * t1[i] - t2[i];//�ǵø� t1[i] ���ϳ��� (x + 1)
//     }
//     return res;
// }

// int main()
// {
//     scanf("%d%d", &n, &m);
//     ll now, last = 0;
//     for(int i = 1; i <= n; ++i)
//     {
//         scanf("%lld", &now);
//         update(i, now - last);//������b[i]
//         last = now;
//     }
//     while(m--)
//     {
//         ll op, x, y, k;
//         scanf("%lld%lld%lld", &op, &x, &y);
//         if(op == 1) 
//         {
//             scanf("%lld", &k);
//             update(x, k);
//             update(y + 1, -k);
//         }
//         else
//         {
//             printf("%lld\n", sum(y) - sum(x - 1));
//         }
//     }
//     return 0;
// }



//5.P2357 ��Ĺ�ˣ������޸� + �����ѯ��
//������ �����ֵ������Ͳ�ѯ����Ԫ���޸ġ���Ԫ��ֵ��ѯ��������Ԫ���޸����ǿ���ֱ�ӽ��޸�ֵ������������ѯʱ�ټ����޸�ֵ
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 2e5 + 10;
// ll t1[N], t2[N];
// int n, m;

// void update(ll x, ll d)
// {
//     for(int i = x; i <= n; i += lowbit(i))
//     {
//         t1[i] += d;    
//         t2[i] += x * d;
//     }
// }
// ll sum(ll x)//��ѯǰ׺�� ��a[1 .. x]
// {
//     ll res = 0;
//     for(int i = x; i > 0; i -= lowbit(i))
//     {
//         res += (x + 1) * t1[i] - t2[i];//�ǵø� t1[i] ���ϳ��� (x + 1)
//     }
//     return res;
// }

// int main()
// {
//     scanf("%d%d", &n, &m);
//     ll now, last = 0;
//     for(int i = 1; i <= n; ++i)
//     {
//         scanf("%lld", &now);
//         update(i, now - last);//������b[i]
//         last = now;
//     }
//     ll fir = 0;//��Ԫ�ظı�ֵ������Բ��� 2 �� 3��
//     while(m--)
//     {
//         ll op, x, y, k;
//         scanf("%lld", &op);
//         if(op == 1) 
//         {
//             scanf("%lld%lld%lld", &x, &y, &k);
//             update(x, k);
//             update(y + 1, -k);
//         }
//         else if(op == 2) scanf("%lld", &k), fir += k;
//         else if(op == 3) scanf("%lld", &k), fir -= k;
//         else if(op == 4)
//         {
//             scanf("%lld%lld", &x, &y);
//             ll res = sum(y) - sum(x - 1);
//             if(x == 1) res += fir;//��������Ԫ�أ��ͼ����޸�ֵ
//             printf("%lld\n", res);
//         }
//         else printf("%lld\n", sum(1) + fir);//��ѯ��Ԫ�أ������޸�ֵ
//     }
//     return 0;
// }




//6.P1908 ����ԣ�һάƫ������ - ����� + ��ɢ����
// ˼·���԰��� {5 4 2 6 3 1}���ȿ� 5���������ұߵ�����{4 2 6 3 1}��{4 2 3 1} �����������ٿ� 6������{3 1}����������������� 3 ��ֻ�ܼ���{1}���ҷ�������
// ���⼴���ά���� i ��Ԫ�� x ���Ҳ����� [i + 1, n] ��С�� x �ĸ�����ÿ������һ���� x ʱ������ x �����±꣩������ cnt[x]++ ��cnt[x] ��ʾ x ��ǰ���ֵĴ���
// ���Ƿ������������ͳ�� cnt[x]����������� 2����ʱ cnt[5] = cnt[4] = 1���� 2 ֮ǰ�� 2 ���� 2 �������ans += 1 + 1���� ans += ��cnt[3 ... n]
// ʵ�֣��������ÿ���� x ��ͳ�ƺ�׺�� ��cnt[(x + 1) ... n] ��Ϊ����ά�������ǿ��Է����������������ÿ���� x ��ͳ��ǰ׺�͡�cnt[1 ... (x - 1)]��
// ת����ǰ׺�����⣬ά����״���鼴�ɡ�
// ���� cnt[x] �� x < 1e9 �����ұ���ֻ��֪��Ԫ�ؼ���Դ�С���ʿ�����ɢ������ʹ�ÿռ临�Ӷ�ת��Ϊ������������� - O(n) - n <= 5e5��
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 5e5 + 10;
// struct nd{
//     int id, val;
//     bool operator <(const nd &x) const{//��������
//         if(val == x.val) return id < x.id;//��ԭ˳���ȳ��֣����򿿺���֣������ֵ��С����ֹ��ɢ���������ͳ�Ƶ� ���ֵ �ԡ�
//         return val < x.val;
//     }
// }q[N];
// int n;
// int tree[N];
// int num[N];
// void update(int x, int d)
// {
//     for(; x <= n; x += lowbit(x))
//         tree[x] += d;
// }
// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += tree[x];
//     return res;
// }
// int main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%d", &q[i].val);
//         q[i].id = i;
//     }
//     //��ɢ������
//     sort(q + 1, q + 1 + n);
//     for(int i = 1; i <= n; i++) num[q[i].id] = i;//������
    
//     ll ans = 0;//����һ���ܶ࣬����
//     for(int i = n; i > 0; i--)//�������
//     {
//         ans += sum(num[i] - 1);
//         update(num[i], 1);
//     }
//     printf("%lld\n", ans);

//     return 0;
// }



//7.̰����½
//���串�����⣬Ҫ��ͳ������[L, R]�ڵĸ����������
// ����������������[1, 10]�ϲ�ѯ�漰[4 7]����������������и�������[1, 3] [2, 5] [3, 6] [5, 6] [9, 10]��
// 1 2 3 4 5 6 7 8 9 10
//       |=====|         ��ѯ����
// |---|                 0
//  |-----|             1
//    |-----|           1
//        |-|           1
//                |-|   0
// ans = 0 + 1 + 1 + 1 + 0 = 3
// �۲쵽��ѯ���� [L, R] ���Ҷ˵� R ֮ǰ������ [1, R] �ϵ�������˵����ĸ������䶼���ܸ��ǵ�[L, R]��ĳ����
// ���ʱ��Щ�Ҷ˵��� L ֮������ [L, n] �ϵĸ��������Ȼ�ܸ��ǵ� [L, R] ĳ����
// ���仰˵���Ҷ˵��� L ֮ǰ������ [1, L - 1] �ϵĸ��������Ȼ�����ܸ��ǵ� [L, R] ��ĳ��
// �����ǿ�������˵��� lsum(1, R) �����п��ܷ�������������������Լ������������Ҷ˵��� rsum(1, L - 1) �����������������������
// ���� ans = lsum(1, R) - rsum(1, L - 1) �õ������������������
// ˼·������ת��Ϊ�� ���Ҷ˵���� ��ǰ׺�ͣ��ɷֱ�ά��������״���� tl[]��tr[]
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e5 + 10;
// int n, m, tl[N], tr[N];//tl[]��¼��˵������tr[]��¼�Ҷ˵����
// void update(int *t, int x, int d)
// {
//     for(; x <= n; x += lowbit(x)) 
//         t[x] += d;
// }
// int sum(int *t, int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x)) res += t[x];
//     return res;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     while(m--)
//     {
//         int op, L, R;
//         scanf("%d%d%d", &op, &L, &R);
//         if(op == 1) 
//         {
//             update(tl, L, 1);//���ε����޸�
//             update(tr, R, 1);
//         }
//         else printf("%d\n", sum(tl, R) - sum(tr, L - 1));//ans = [1, R]����˵���� - [1, L - 1]���Ҷ˵����
//     }
//     return 0;
// }



//8. Mobile phones
//���� n * n ��С�����������򣬿ɸ���������һ�����ӻ����ֵ d�����άǰ׺�� sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
//��ά��״����
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1500;
// int n, op;
// int tree[N][N];

// void update(int x, int y, int d)
// {
//     for(int i = x; i <= n; i += lowbit(i))
//         for(int j = y; j <= n; j += lowbit(j))
//             tree[i][j] += d;
// }
// int sum(int x, int y)
// {
//     int res = 0;
//     for(int i = x; i > 0; i -= lowbit(i))
//         for(int j = y; j > 0; j -= lowbit(j))
//             res += tree[i][j];
//     return res;
// }

// int main()
// {
//     while(~scanf("%d", &op))
//     {
//         if(op == 3) break;
//         if(op == 0)
//         {
//             scanf("%d", &n);
//             memset(tree, 0, sizeof(tree));
//         }
//         else if(op == 1)
//         {
//             int x, y, d;
//             scanf("%d%d%d", &x, &y, &d);//�����Ŵ� 0 ��ʼ������ĳɴ� 1 ��ʼ
//             ++x, ++y;
//             update(x, y, d);
//         }
//         else
//         {
//             int x1, y1, x2, y2;
//             scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//             ++x1, ++y1, ++x2, ++y2;
//             printf("%d\n", sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1));
//         }
//     }
//     return 0;
// }



//9. P3531 LIT-Letters(һάƫ������ - �����)
//����ֻ���д�д��ĸ�������ַ��� S1 �� S2��ÿ�ο��Խ��� S1 ���������ַ��Ĵ����� S1 ��� S2 �����ٽ���������
//����Ҫ��һ������˳�� Ord1 �����һ������˳�� Ord2�����ǽ�Ŀ��˳�� Ord2 �ĸ��ַ�λ�ô��� rk[ch] = pos�������������� Ord1
//�� S1 = "CABC"��S2 = "CCAB" 
//���� S2 ����Ŀ��˳�� C C A B -> 1 2 3 4
//A: 3
//B: 4
//C: 1, 2
//��ǰ����˳��Ϊ C A B C -> 1 3 4 2
//������ 1 3 4 2 Ҫ�任������ 1 2 3 4�������������
//ÿ������Ӧ������Ը�����ʵ���Ǹ���ʵ�־ֲ�����Ĳ����������е�����Ը�����Ϊ��������ȫ����������Ĳ�����
// �� 5 3 7 6 2 1 4 -> 1 2 3 4 5 6 7������ؿ� 2 �ľֲ�����ṹΪ {1 2 4}�����轻������Ϊ 1
// 6 �ľֲ�����ṹΪ {1 2 4 6} ����Ҫ 3 ������Ԫ�ؽ��� ��ͬ��7 -> {1 2 4 6 7} -> 4�� ��3 -> {1 2 4 3} -> 3�� ������
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e6 + 10;

// int n, tree[N];
// int arr[N];//ʵ�ʲ�������
// char a[N], b[N];
// vector<int> id[30];//id[ch] ���ַ� ch �ı�ż�
// int pos[30];//pos[ch] ��Ӧ�ַ� ch ��ż� id[ch] ��ǰ��������λ��

// void update(int x, int d)
// {
//     for(; x <= n; x += lowbit(x)) 
//         tree[x] += d;
// }
// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x)) 
//         res += tree[x];
//     return res;
// }
// int main()
// {
//     scanf("%d%s%s", &n, a, b);
//     for(int i = 0; i < n; i++)
//     {
//         int ch = b[i] - 'A';//���ڿ��������ߵ����˳��ȡ S1 �� S2 �����ԣ��˴��� S2 Ϊ��
//         id[ch].push_back(i + 1);
//     }
//     for(int i = 0; i < n; i++)
//     {
//         int ch = a[i] - 'A';
//         arr[i] = id[ch][pos[ch]++];//���쵱ǰ˳������
//     }
//     long long ans = 0;
//     for(int i = n - 1; i >= 0; i--)//������Ը���
//     {
//         ans += sum(arr[i] - 1);
//         update(arr[i], 1);
//     }
//     printf("%lld\n", ans);
//     return 0;
// }



//10.������ Stars����άƫ������ģ���⣩
//
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 4e4 + 10;

// int n, tree[N];
// int cnt[N];

// void update(int x, int d)
// {
//     for(; x < N; x += lowbit(x)) 
//         tree[x] += d;
// }

// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x)) 
//         res += tree[x];
//     return res;
// }

// int main()
// {
//     scanf("%d", &n);
//     //���б�֤ y ����ظ������൱������ö�� y
//     for(int i = 0; i < n; i++)
//     {
//         int x, y, level;
//         scanf("%d%d", &x, &y);
//         ++x, ++y;
//         level = sum(x);
//         cnt[level]++;
//         update(x, 1);
//     }
//     for(int i = 0; i < n; i++) printf("%d\n", cnt[i]);
//     return 0;
// }











//11.P1637 ��Ԫ���������У���άƫ�����⣩
// �����뵽�Ȳ�ֳɶ�Ԫ����ԣ�ȡ�м�Ԫ�� Am Ϊ���գ�����ֽ�Ϊ���ض�Ԫ�����ԣ�Ai < Am (i < m) �� Am < Aj (m < j)������Ժ�ÿ����������� Ai��Am��Aj ���Ǵ�
// �ּ� lef[m] Ϊ Am ���С�� Am ��Ԫ�ظ�����rig[m] Ϊ Am �Ҳ���� Am ��Ԫ�ظ���
// ȡ�м�Ԫ�� a[i]�������ҺϷ�����������ԣ��� lef[i] * rig[i] �����������˷�ԭ��
// ��ö���м�Ԫ�� a[i], �������в�ͳ������������
// ����Ԫ��ֵ���Ϊ M <= 1e5���ǿɽ��ܵ������С���� M ����ﵽ 1e7 ~ 1e9��ֻ����ɢ���������ӶȽ��� O(n) ��n Ϊ��������
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 3e4 + 10, M = 1e5 + 10;

// int n, a[N], t1[M], t2[M];//t1[] -> lef[]��t2[] -> rig[]
// int lef[M], rig[M];
// int max_x = 0;

// void update(int *t, int x, int d)
// {
//     for(; x <= max_x; x += lowbit(x)) //ע��������״������±�ΪԪ��ֵ�����Ϊ max_x (max_x < M)
//         t[x] += d;
// }
// int sum(int *t, int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x)) 
//         res += t[x];
//     return res;
// }

// int main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++)
//     {
//         scanf("%d", &a[i]);
//         max_x = max(max_x, a[i]);
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         lef[i] = sum(t1, a[i] - 1);
//         update(t1, a[i], 1);
//     }
//     //rig[i] Ҫ�����м�Ԫ�� a[i] �Ҳ�� a[i] ������ĸ���
//     //����ʱ sum(a[i]) ������Ҳ�С�ڵ��� a[i] �����ĸ����������Ҳ����䳤�� (n - i) ��ȥ sum(a[i]) ��Ϊ�� a[i] ������ĸ���
//     for(int i = n; i >= 1; i--)
//     {
//         rig[i] = (n - i) - sum(t2, a[i]);//�˴������ȼ����ٲ��� a[i]����ֹ������м�Ԫ��
//         update(t2, a[i], 1);
//     }
//     //ö���м�Ԫ�أ�ͳ�ƴ�
//     long long ans = 0;
//     for(int i = 2; i < n; i++)
//     {
//         ans += 1LL * lef[i] * rig[i];
//     }
//     printf("%lld\n", ans);
//     return 0;
// }



//12. P5142 ���䷽��(���� + ��״����)
//������ n ����ʼֵ������ B�����ֲ������� x ������ֵΪ y����ѯ Bx ~ By �ķ���
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 1e5 + 10;
// const ll mod = 1e9 + 7;

// int n, m;
// ll t1[N], t2[N];

// ll quick_pow(ll base, ll index = mod - 2)//�����ݰ��ӣ�����Ĭ���� base^(mod - 2)
// {
//     ll ans = 1;
//     base %= mod;
//     for(; index; index >>= 1)
//     {
//         if(index & 1) ans = ans * base % mod;
//         base = base * base % mod;
//     }
//     return ans % mod;
// }

// void update(ll *t, int x, ll d)
// {
//     for(; x <= n; x += lowbit(x))
//         t[x] = (t[x] + d) % mod;//ע��ȡģ
// }

// ll sum(ll *t, int x)
// {
//     ll res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res = (res + t[x]) % mod;//ע��ȡģ
//     return res % mod;
// }

// int main()
// {
//     scanf("%d%d", &n, &m);
//     for(int i = 1; i <= n; i++)
//     {
//         ll x;
//         scanf("%lld", &x);
//         update(t1, i, x % mod);
//         update(t2, i, x * x % mod);
//     }
//     while(m--)
//     {
//         ll op, x, y;
//         scanf("%lld%lld%lld", &op, &x, &y);
//         if(op == 1)//���㸳ֵ
//         {
//             ll v1 = sum(t1, x) - sum(t1, x - 1);//��ǰ a[x]
//             ll v2 = sum(t2, x) - sum(t2, x - 1);//��ǰ a[x] * a[x]
//             //���²�ֵ����
//             update(t1, x, (y - v1) % mod);
//             update(t2, x, (y * y - v2) % mod);
//         }
//         else
//         {
//             ll s1 = (sum(t1, y) - sum(t1, x - 1)) % mod;//��ai
//             ll s2 = (sum(t2, y) - sum(t2, x - 1)) % mod;//��(ai ^ 2)ƽ����
//             ll k = quick_pow(y - x + 1);                // 1 / n   ����Ԫ������ȡģ��
//             ll ave = s1 * k % mod;                      //��ai / n  ƽ����
//             ll ans = s2 * k % mod -  ave * ave % mod;   //��(ai ^ 2) / n  -  (��ai) ^ 2
//             ans = (ans % mod + mod) % mod;              //����������㣬��ֹ���ָ���
//             printf("%lld\n", ans);
//         }
//     }
//     return 0;
// }



//13.P5094 [USACO04OPEN] MooFest G ��ǿ��
//����������Ȼ��ö��ÿ��ֵ��һ�����ֵ v_max��ͳ�� x ����ǰ��ĵ�(vi ��С�ڵ��� v_max)�Ĺ���
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 5e4 + 10;

// int n;
// ll maxx = 0;
// ll t1[N], t2[N];//t1[] ά��Ԫ�ظ����ͣ� t2[] ά��λ�ú�

// struct nd{
//     ll v, x;
//     bool operator <(const nd &nex) const{
//         return v < nex.v;
//     }
// }q[N];

// void update(ll *t, ll x, ll d)
// {
//     for(; x <= maxx; x += lowbit(x))//ע����״����Ĵ�С���� n
//         t[x] += d;
// }

// ll sum(ll *t, ll x)
// {
//     ll res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += t[x];
//     return res;
// }

// int main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++) 
//     {
//         scanf("%lld%lld", &q[i].v, &q[i].x);
//         maxx = max(maxx, q[i].x);
//     }
//     sort(q + 1, q + 1 + n);
//     ll ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         ll x = q[i].x, v = q[i].v;
//         ll cnt1 = sum(t1, x), sum1 = sum(t2, x);                                //�� xi С�������� [1, x] ����Ϣ
//         ll cnt2 = sum(t1, maxx) - sum(t1, x), sum2 = sum(t2, maxx) - sum(t2, x);//�� xi �������� (x, maxx) ����Ϣ

//         ans += v * (x * cnt1 - sum1) + v * (sum2 - x * cnt2);

//         update(t1, x, 1);//����Ԫ�ظ���
//         update(t2, x, x);//����Ԫ��λ��ֵ
//     }
//     printf("%lld\n", ans);
//     return 0;
// }



//14. P1972 [SDOI2009] HH����������άƫ�����⣩
// �ֿ�������״����ά�������ڶ���Ԫ�ظ����������ص�������θ�����ѯ���� [l, r] ��Ԫ�����أ����ȶ�����������Ԫ�ر������ؿ϶��ǲ��еġ�������ѯ������ [l, r] ʱ��
// ����֪������ [l, r] �ĸ�Ԫ���ظ������ vis[ a[l ... r] ] �ֱ��Ƿ�Ϊ 0��������ѯ���������ߴ洢���� r ��������
// ����Ϊ�Ҷ˵� r �����Ÿ�������Զ����ĵط���Ҳ���Ǵ�ʱ vis[] ��Ҫ��չ���ĵط���
// �������Ǿ������������ά�� vis[x]��
// ��������ָ�� p ��¼ vis[] ��չ����λ��
// �ֱ����������� [l, r]����λ�� p �ϵ��� x���� t[p] �����޸ļ� 1��ֵ�ĸ����� 1������¼ vis[x]���� vis[x] != 0 ��Ե�ʱ x ��λ�� t[last_p] �����޸ļ� 1������ֹ�ظ���
// ���������¼����Ϊ vis[x] = p�������� vis[x] ֵΪ x �ϴγ��ֵ�λ��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define lowbit(x) ((x) & -(x))
// const int N = 1e6 + 10;
// struct nd{
//     int id;//�����ѯ����ԭ���Ĳ�ѯ˳��
//     int l, r;
//     bool operator <(const nd &x) const{
//         return r < x.r;
//     }
// }q[N];

// int n, m;
// int a[N], ans[N];//a[]Ϊԭ���飬ans[id]��ʾ���Ϊ id ������Ĵ�
// int vis[N];      //vis[x] = p ����Ϊ Ԫ��ֵ x �ϴγ��ֵ�λ�� p
// int tree[N];

// void update(int x, int d)
// {
//     for(; x <= n; x += lowbit(x))
//         tree[x] += d;
// }

// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += tree[x];
//     return res;
// }

// int main()
// {
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//     scanf("%d", &m);
//     for(int i = 1; i <= m; i++)
//     {
//         scanf("%d%d", &q[i].l, &q[i].r);
//         q[i].id = i;
//     }
//     sort(q + 1, q + 1 + m);
//     int p = 1;
//     for(int i = 1; i <= m; i++)
//     {
//         //���� vis[1 ... r] �Լ� [1, r] ����Ԫ�ظ�����
//         for(; p <= q[i].r; p++)
//         {
//             if(vis[a[p]]) update(vis[a[p]], -1);//��Ԫ���Ѵ��ڣ���������һ��λ�õ�״̬����ֹ�ظ�
//             update(p, 1);                       //���µ�ǰԪ��ֵ״̬Ϊ"����"
//             vis[a[p]] = p;                      //��¼��ǰԪ��ֵλ�� p
//         }
//         ans[q[i].id] = sum(q[i].r) - sum(q[i].l - 1);        
//     }
//     for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
//     return 0;
// }



//15. P4113 [HEOI2012]�ɻ�����άƫ�����⣩
//HH������ �Ľ��װ�
//������ͬһ����������������������ͬ��Ԫ�ؼ�Ϊһ���������������
//Ҳ����˵���ز����Ƿ����ڵڶ����ظ�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll long long
// #define lowbit(x) ((x) & -(x))
// const int N = 2e6 + 10;

// struct nd{
//     int id;
//     int l, r;
//     bool operator <(const nd &ne) const{
//         return r < ne.r;
//     }
// }q[N];

// int n, c, m;
// int a[N], tree[N];
// int last1[N], last2[N];//last1[x] �� last2[x] �ֱ��ʾ x ���ϴγ��� �� �ϴγ��� ��λ��
// int ans[N];

// void update(int x, int d)
// {
//     for(; x <= n; x += lowbit(x))
//         tree[x] += d;
// }

// int sum(int x)
// {
//     int res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += tree[x];
//     return res;
// }

// int main()
// {
//     scanf("%d%d%d", &n, &c, &m);
//     for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
//     for(int i = 1; i <= m; i++)
//     {
//         scanf("%d%d", &q[i].l, &q[i].r);
//         q[i].id = i;
//     }
//     sort(q + 1, q + 1 + m);
//     int p = 1;
//     for(int i = 1; i <= m; i++)
//     {
//         for(; p <= q[i].r; p++)
//         {
//             if(!last1[a[p]]) last1[a[p]] = p;   //��һ�γ���
//             else
//             {
//                 if(!last2[a[p]])                //�ڶ��γ��֣�a[p] ��Ч
//                 {
//                     update(last1[a[p]], 1);     //�����ϴγ��ִ���������Ϊֻ��������˵� l <= last1[a[p]] ������Ч
//                     last2[a[p]] = p;
//                 }
//                 else                            //*�ص㣺�����γ��֣�����
//                 {
//                     update(last1[a[p]], -1);    //ȥ������ߵ��ظ�Ԫ�أ�Ȼ��״̬������
//                     update(last2[a[p]], 1);
//                     last1[a[p]] = last2[a[p]];  //����״̬һ��������
//                     last2[a[p]] = p;
//                 }
//             }
//         }
//         ans[q[i].id] = sum(q[i].r) - sum(q[i].l - 1);
//     }
//     for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
//     return 0;
// }




//   1 2 2 3 1 1
//l1 1 2
//l2         5

//2 2 3
//�� 0 1 0�����ѯ {2 3} ʱ��õ� 1���Ǵ����
//�� 1 0 0�����ѯ {2 2 3} ���� 1������ {2 3} �� 0
//����Ӧ�����ϴγ��ִ������1

//   2 2 2 2 3
//   0 1 0 0 0
//l1 1
//l2 2






























































/*ʮ��. ��ϣ�㷨(HASH)*/
//1. PTA ���չ�˾VIP�ͻ���ѯ (������ֵ��ϣ)
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - '0')
// const int M = 2e5;//ʹ�ÿ��Ŷ�ַ����ɢ�б�����㹻��
// //ʵ������������ڸ��Ŀռ��64MB������Ҫȡ��λ�������ϣֵ�Ļ���M�Ĵ�СӦ���ٶ���Ϊ1e6������2e5���������Ѿ�63MB�����ˣ�
// int n, m, k, P;
// struct node{
//     char arr[20]; //���֤�� [0, 17]
//     int pts;      //��̻���
//     node *next;   //ָ����һ����Ԫ��û����Ϊ NULL
// };
// typedef node* Hash;
// int cal(const char *s)//��ϣ�������֤�ţ��õ��±��ַ
// {
//     //���ݴ���ɢ�б��С������õ��� id Ϊ 1e5 �������ﹲѡ5λ����ѡ���һλ��ǰ��λ�����ں�λ��ܶ�
//     int id = num(s[5]) * 10000 + num(s[9]) * 1000 + num(s[13]) * 100 + num(s[15]) * 10 + num(s[16]);
//     if(s[17] == 'x') id = id * 10 + 10;//���⴦���ַ�λ
//     else id = id * 10 + num(s[17]);
//     return id;
// }
// int getprime(int N)
// {
//     int p = (N % 2) ? (N + 2) : (N + 1);
//     int i;
//     while(p < M)
//     {
//         for(i = (int)sqrt(N); i >= 2; --i)
//             if(p % i == 0) break;
//         if(i < 2) break;
//         else p += 2;
//     }
//     return p;
// }
// //ע�⣺��������ӷ��� �� ɢ�б��� �෴������
// //����ÿ�μ�����½�㶼���ɸ������ͷ����ԭ����head[ind]����һ���������½����
// Hash insert(const Hash h, char *s, int d) //��ϣ����Ĳ���
// {
//     Hash p = h;
//     while(p) // �� p != NULL
//     {
//         if(!strcmp(p -> arr, s))//�Ѵ��ڣ��������̻���
//         {
//             p -> pts += d;
//             return h;           //����ԭ����ͷ
//         }
//         p = p -> next;
//     }
//     //�в����ڣ����½��������
//     p = (Hash)malloc(sizeof(node));
//     strcpy(p -> arr, s);
//     p -> pts = d;
//     p -> next = h;
//     return p;
// }
// void check(const Hash h, char *s) //�жϸ����Ƿ�Ϊ��Ա
// {
//     Hash p = h;
//     while(p) 
//     {
//         if(!strcmp(p -> arr, s)) //���ʱ, strcmp() ���� 0
//         {
//             printf("%d\n", p -> pts);
//             return;
//         }
//         p = p -> next;
//     }
//     printf("No Info\n");
// }
// int main()
// {
//     scanf("%d%d", &n, &k);
//     P = getprime(n);
//     Hash *head = (Hash *)malloc(P * sizeof(Hash));//ͷ�巨��ָ�����飬�洢�������
//     for(int i = 0; i < P; i++) head[i] = NULL;    //��ʼ��ָ������
//     int ind, d;  //�±꣬���
//     char arr[20];//���֤��
//     while(n--)
//     {
//         scanf("%s%d", arr, &d);
//         if(d < k) d = k;//���⣺���̵���k����ĺ���Ҳ��k�����ۻ�
//         ind = cal(arr) % P;
//         head[ind] = insert(head[ind], arr, d);
//     }
//     scanf("%d", &m);
//     while(m--)
//     {
//         scanf("%s", arr);
//         ind = cal(arr) % P;
//         check(head[ind], arr);
//     }
//     return 0;
// }

//��ָ������д����
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - '0')
// const int M = 2e5;//ʹ�ÿ��Ŷ�ַ����ɢ�б�����㹻��
// int n, m, k, P;
// int head[M];
// int cnt = 0;      //vec[]��β��
// struct node{
//     char arr[20]; //���֤�� [0, 17]
//     int pts;      //��̻���
//     int next;     //ָ����һ����Ԫ
// }vec[M];
// typedef node* Hash;
// int cal(const char *s)//��ϣ�������֤�ţ��õ��±��ַ
// {
//     int id = num(s[5]) * 10000 + num(s[9]) * 1000 + num(s[13]) * 100 + num(s[15]) * 10 + num(s[16]);
//     if(s[17] == 'x') id = id * 10 + 10;
//     else id = id * 10 + num(s[17]);
//     return id;
// }
// int getprime(int N)
// {
//     int p = (N % 2) ? (N + 2) : (N + 1);
//     int i;
//     while(p < M)
//     {
//         for(i = (int)sqrt(N); i >= 2; --i)
//             if(p % i == 0) break;
//         if(i < 2) break;
//         else p += 2;
//     }
//     return p;
// }
// void insert(int id, char *s, int d) //��ϣ����Ĳ���
// {
//     for(int i = head[id]; ~i; i = vec[i].next)
//     {
//         if(!strcmp(vec[i].arr, s))//�Ѵ��ڣ��������̻���
//         {
//             vec[i].pts += d;
//             return;
//         }
//     }
//     //�в����ڣ����½��������
//     ++cnt;
//     strcpy(vec[cnt].arr, s);
//     vec[cnt].pts = d;
//     vec[cnt].next = head[id];//�½�㣨������ͷ��ָ��ԭ����ͷ���
//     head[id] = cnt;          //�½����Ϊ�����µ�ͷ���
// }
// void check(int id, char *s) //�жϸ����Ƿ�Ϊ��Ա
// {
//     for(int i = head[id]; ~i; i = vec[i].next)
//     {
//         if(!strcmp(vec[i].arr, s)) //���ʱ, strcmp() ���� 0
//         {
//             printf("%d\n", vec[i].pts);
//             return;
//         }
//     }
//     printf("No Info\n");
// }
// int main()
// {
//     int ind, d;  //�±꣬���
//     char arr[20];//���֤��
//     memset(head, -1, sizeof(head));
//     scanf("%d%d", &n, &k);
//     P = getprime(n);
//     while(n--)
//     {
//         scanf("%s%d", arr, &d);
//         if(d < k) d = k;//���⣺���̵���k����ĺ���Ҳ��k�����ۻ�
//         ind = cal(arr) % P;
//         insert(ind, arr, d);
//     }
//     scanf("%d", &m);
//     while(m--)
//     {
//         scanf("%s", arr);
//         ind = cal(arr) % P;
//         check(ind, arr);
//     }
//     return 0;
// }



//2.P3370 ��ģ�塿�ַ�����ϣ
//д��1����Ȼ�����158ms ������ set �ļ��٣�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// #include <unordered_set>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - '0')
// const int N = 1e4 + 5, M = 1505;
// ull base = 131;
// char s[M];
// unordered_set<ull> cnt;//���ߴ����ϣֵ��ǰ�������Աȹ�ϣֵ�Ƿ���ͬ
// ull cal(char *s)
// {
//     int len = strlen(s);
//     ull h = 0;
//     for(int i = 0; i < len; i++)
//         h = h * base + num(s[i]);
//     return h;
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s", s);
//         cnt.insert(cal(s));
//     }
//     printf("%d\n", cnt.size());
//     return 0;
// }

//д��2����Hash����609ms��
//������������С������ȡ 31������ P ȡ�� 1e9 ~ 1e10��ʹ�価����Ҫ����ȡģ�㼴�ɡ����⡱��ͻ��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - '0')
// const int N = 1e4 + 5, M = 1505;
// ll base = 31, P = 9999999929;
// char s[N][M];
// ll Hash[N];
// void print_prime(ll MIN, ll MAX)
// {
//     for(; MIN <= MAX; MIN++)
//     {
//         bool ok = 1;
//         for(ll i = (ll)sqrt(MIN); i >= 2; i--)
//         {
//             if(MIN % i == 0) 
//             {
//                 ok = 0;
//                 break;
//             }
//         }
//         if(ok) printf("%lld\n", MIN);
//     }
// }
// ll cal(char *s)
// {
//     ll len = strlen(s);
//     ll h = 0;
//     for(int i = 0; i < len; i++)
//         h = (h * base + num(s[i])) % P;
//     return h;
// }
// int main()
// {
//     // print_prime(9999999900LL, (ll)1e10);
//     ll ans = 1;
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s", s[i]);
//         Hash[i] = cal(s[i]);
//     }
//     sort(Hash, Hash + n);
//     for(int i = 1; i < n; i++)
//     {
//         if(Hash[i] != Hash[i - 1])
//             ans++;
//     }
//     printf("%d\n", ans);
//     return 0;
// }

//д��3��˫Hash����1070ms��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - '0')
// const int N = 1e4 + 5, M = 1505;
// ll base1 = 31, base2 = 131, P1 = 800000821, P2 = 9999999943;
// char s[M];
// struct nd{
//     ll h1, h2;
//     bool operator <(const nd &x) const{ return h1 < x.h1;}
// }Hash[N];
// ll cal(ll base, ll P, char *s)
// {
//     ll len = strlen(s);
//     ll h = 0;
//     for(int i = 0; i < len; i++)
//         h = (h * base + num(s[i])) % P;
//     return h;
// }
// int main()
// {
//     ll ans = 1;
//     int n;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%s", s);
//         Hash[i].h1 = cal(base1, P1, s);
//         Hash[i].h2 = cal(base2, P2, s);
//     }
//     sort(Hash, Hash + n);
//     for(int i = 1; i < n; i++)
//         if(Hash[i].h1 != Hash[i - 1].h1 || Hash[i].h2 != Hash[i - 1].h2)
//             ++ans;
//     printf("%d\n", ans);
//     return 0;
// }



//3.��ͬ��ѭ�����ַ�����ѭ���Ӵ���Ŀ��ע������Ĵ����֣�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// #include <unordered_set>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - 'a' + 1)//ע�����ﲻ���� x - 'a'�������"aaaaaa"���മ���й�ϣֵ��Ϊ0�����³���
// const int M = 2005;
// ull base = 31;
// char s[M];
// ull Hash[M], p[M];
// ull gethash(int L, int R)
// {
//     return Hash[R] - Hash[L - 1] * p[R - L + 1];
// }
// void init()
// {
//     Hash[0] = 0, p[0] = 1;
//     for(int i = 1; i < M; ++i) p[i] = p[i - 1] * base;//Ԥ������� base^i
// }
// int main()
// {
//     init();    
//     scanf("%s", s + 1);
//     int n = strlen(s + 1);
//     //����ǰ׺��ϣֵ
//     for(int i = 1; i <= n; i++) Hash[i] = Hash[i - 1] * base + num(s[i]);

//     //ö���Ӵ����ȣ��ж�ѭ����
//     unordered_set<ull> ans;
//     ull temp = 0;
//     for(int len = 1; 2 * len <= n; len++)
//         for(int L = 1; L + 2 * len - 1 <= n; L++)
//             if((temp = gethash(L, L + len - 1)) == gethash(L + len, L + 2 * len - 1))
//                 ans.insert(temp);
//     printf("%d\n", ans.size());
//     return 0;
// }



//3.Crazy Search��������ϣ��
//ע������� set ȥ�ػ� TLE������̫��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// #include <vector>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - 'a' + 1)
// const int M = 1e6 + 5;
// ull h = 0, p = 1, base = 31, P = 800000821;
// int len, n, m;
// char s[M];
// vector<ull> cnt;
// int main()
// {
//     scanf("%d%d", &len, &m);
//     scanf("%s", s + 1);
//     int n = strlen(s + 1);
//     //��ʼ����һ��������Ϊ���ף�ά������[l, r]�ڹ�ϣֵ h 
//     for(int i = 1; i <= len && i <= n; i++)//��ֹ len > n
//     {
//         h = h * base + num(s[i]);
//         p *= base;
//     }
//     if(len <= n) cnt.push_back(h);
//     //�����ƶ������������λ�ճ���λ��ȥ�����λ������λ�����ұߵ��ַ�
//     //��len = 3�� s1*base^2 + s2*base + s3,  p = base^3
//     for(int i = len + 1; i <= n; i++)
//     {
//         h = h * base + num(s[i]) - num(s[i - len]) * p;
//         cnt.push_back(h);
//     }
//     sort(cnt.begin(), cnt.end());
//     int num = unique(cnt.begin(), cnt.end()) - cnt.begin();
//     printf("%d\n", num);
//     return 0;
// }



//4.Barn Echoes G����ǰ׺��ϣӦ�ã�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// #include <vector>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - 'a' + 1)
// const int N = 1e2 + 5, M = 1e6;
// ull base = 31, P = 800000821;
// ull p[N] = {1}, h1[N], h2[N];
// int len1, len2, ans = 0;
// char s1[N], s2[N];
// inline ull gethash(const ull *h, int L, int R){ return h[R] - h[L - 1] * p[R - L + 1];}
// int main()
// {
//     for(int i = 1; i < N; i++) p[i] = p[i - 1] * base;
//     scanf("%s %s", s1 + 1, s2 + 1);
//     len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
//     for(int i = 1; i <= len1; i++) h1[i] = h1[i - 1] * base + num(s1[i]);
//     for(int i = 1; i <= len2; i++) h2[i] = h2[i - 1] * base + num(s2[i]);
//     for(int len = 1; len <= min(len1, len2); len++)
//         if(h1[len] == gethash(h2, len2 - len + 1, len2) || gethash(h1, len1 - len + 1, len1) == h2[len])
//             ans = max(ans, len);
//     printf("%d\n", ans);
//     return 0;
// }



//5.Three Friends����[L,R]�Ӵ�ɾȥ����һ���ַ���Ĺ�ϣֵ��
//ö��Ҫɾ�����ַ�������ǰ�롢ǡ�����м䡢�ں������
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - ' ' + 1)
// const ll N = 2e6 + 10;
// ull base = 131;
// ll n;
// string s;
// ull h[N], p[N];
// map<ull, bool> vis;//��ֹ�ҵ��ظ���
// ull gethash(int L, int R)
// {
//     return h[R] - h[L - 1] * p[R - L + 1];
// }
// int main()
// {
//     untie();
//     cin >> n >> s;
//     s = ' ' + s;
//     if(!(n & 1))
//     {
//         cout << "NOT POSSIBLE\n";
//         return 0;
//     }
//     ll mid = n + 1 >> 1, pos = 0, cnt = 0;
//     p[0] = 1;
//     for(int i = 1; i <= n; i++) h[i] = h[i - 1] * base + num(s[i]), p[i] = p[i - 1] * base;
    
//     ull tl, tr;
//     //ǰ��
//     for(int i = 1; i <= mid - 1; i++)
//     {
//         tl = gethash(1, i - 1) * p[mid - i] + gethash(i + 1, mid), tr = gethash(mid + 1, n);
//         if(tl == tr && !vis[tl])
//         {
//             vis[tl] = 1;
//             ++cnt;
//             pos = i;
//         }
//     }
//     //�� i = mid
//     tl = gethash(1, mid - 1), tr = gethash(mid + 1, n);
//     if(tl == tr && !vis[tl])
//     {
//         vis[tl] = 1;
//         ++cnt;
//         pos = mid;
//     }
//     //���
//     for(int i = mid + 1; i <= n; i++)
//     {
//         tl = gethash(1, mid - 1), tr = gethash(mid, i - 1) * p[n - i] + gethash(i + 1, n);
//         if(tl == tr && !vis[tl])
//         {
//             vis[tl] = 1;
//             ++cnt;
//             pos = i;
//         }
//     }
//     if(cnt == 1) cout << (pos <= mid ? s.substr(mid + 1) : s.substr(1, mid - 1));
//     else cout << (cnt > 1 ? "NOT UNIQUE" : "NOT POSSIBLE");
//     return 0;
// }



//6. Compress Words
//���ݿ�����Ȼ�������WA����Ҫȡ�෨
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - '0' + 1)
// const ll N = 1e6 + 10;
// ull base = 13131, P = 9999999943;
// int n;
// string s = "", ans = "";
// int main()
// {
//     untie();
//     cin >> n;
//     cin >> ans;
//     for(int i = 1; i < n; i++)
//     {
//         cin >> s;
//         ull hl = 0, hr = 0, p = 1;
//         int ind = 0, len1 = ans.size(), len2 = s.size();
//         for(int i = 0; i < min(len1, len2); i++)//ֱ��ö���ظ������ȣ��ɶ���?
//         {
//             //�涨�Ҳ�Ϊhashֵ��ͷ
//             hl = (hl * base + num(ans[len1 - i - 1])) % P;
//             hr = (hr + num(s[i]) * p) % P;
//             p = p * base % P;
//             if(hl == hr) ind = i + 1;
//         }
//         for(int i = ind; i < len2; i++)     //ȡ���ظ���������
//             ans += s[i];
//     }
//     cout << ans << '\n';
//     return 0;
// }



//7.Long Long Message
//��������ظ�����mid��ÿ���ù�������ȡ�����г�Ϊmid���Ӵ��Ĺ�ϣֵ������ͬ����������Ҹ���
//����һ����map��set���ػ����������TLE���������С�����ֻᵼ��Hash��ͻ��ֻ���˶�����Σ��� ���� + ���� ����
//�涨 len1 <= len2
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// #include <string>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll long long
// #define ull unsigned long long
// #define num(x) ((x) - 'a' + 1)
// const ll N = 1e5 + 10;
// ull base = 131, P = 9999999943;
// int n, len1, len2;
// ull h1[N], h2[N], p[N];
// string s1 = "", s2 = "";
// void init(int n) //��ʼ��ǰ׺��ϣ
// {
//     p[0] = 1;
//     for(int i = 1; i <= n; i++) p[i] = p[i - 1] * base;
//     for(int i = 1; i <= len1; i++) h1[i] = h1[i - 1] * base + num(s1[i]);
//     for(int i = 1; i <= len2; i++) h2[i] = h2[i - 1] * base + num(s2[i]);
// }
// ull gethash(const ull *h, int L, int R)
// {
//     return h[R] - h[L - 1] * p[R - L + 1];
// }
// bool check(int len)
// {
//     vector<ull> v;
//     for(int l = 1, r = len; r <= len1; l++, r++) v.push_back(gethash(h1, l, r));
//     sort(v.begin(), v.end());
//     for(int l = 1, r = len; r <= len2; l++, r++)
//         if(binary_search(v.begin(), v.end(), gethash(h2, l, r)))
//             return 1;
//     return 0;
// }
// int main()
// {
//     untie();

//     cin >> s1 >> s2;
//     len1 = s1.size(), len2 = s2.size();
//     if(len1 > len2) swap(s1, s2), swap(len1, len2);
//     s1 = "{" + s1, s2 = "{" + s2;

//     init(len2);

//     int l = 0, r = min(len1, len2), ans = 0;
//     while(l <= r)
//     {
//         int mid = l + r >> 1;
//         if(check(mid)) l = mid + 1, ans = max(ans, mid);
//         else r = mid - 1;
//     }
//     cout << ans;
//     return 0;
// }
















/*ʮ��. �ֵ���(TrieTree)*/
//1. P2580 ����������ĵ�����ʼ��(ģ��)
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6;

// int n, m, cnt = 1;//���0 �������ڵ�
// string s;

// struct nd{
//     int son[26];//��ĸch���� son[ch - 'a] �� 0
//     int num;    //ͳ�����ǰ׺���ִ���
//     bool repeat;//���ǰ׺�Ƿ��ظ�
//     bool isend; //��β��ǣ��������������ýڵ��Ƿ���һ�������ĵ���
// }tree[N];

// void Insert(string s)
// {
//     int p = 0;//�Ӹ���㿪ʼ��
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])        //���������� ���ڵ� -> id ��ʾ��ǰ׺�������
//             tree[p].son[id] = cnt++;//����ָ����һ�����пռ䣬�ӳ���
//         p = tree[p].son[id];        //��ȡ������һ����㣬���Ÿ�����
//         //ע�����ﴦ���������һ���������ݣ������� 0 -> 1 ��ʾ�ַ�'a'��'a'���ڽ��1��ǰ׺���������ǽ��0��ǰ׺
//         tree[p].num++;              //ǰ׺���ִ�������
//     }
//     tree[p].isend = 1;              //��β���
// }

// int Find(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])//���жϣ���ǰ׺������
//             return 0;
//         p = tree[p].son[id];
//     }
//     //��ʱ p Ϊ�����յ㣬����p��ǰ׺�Ĵ����Լ�Ϊ�������ʵĴ�����
//     if(!tree[p].isend) return 0;
//     if(tree[p].repeat) return 2;//�ظ�
//     tree[p].repeat = 1;
//     return 1;
// }

// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         cin >> s;
//         Insert(s);
//     }
//     cin >> m;
//     for(int i = 0; i < m; i++)
//     {
//         cin >> s;
//         int res = Find(s);
//         if(res == 1) cout << "OK\n";
//         else if(res == 2) cout << "REPEAT\n";
//         else cout << "WRONG\n";
//     }
//     return 0;
// }



//2.Secret Message G��ͳ��ǰ׺���⣩
//���⣺���������ַ���s1����ѯ�������ַ���s2�����ж���s1��ƥ��s2��ƥ�����������ȡ���� ��С�� �ɵ��� �ϴ��ߵ�ǰ׺����ʵ���������ǰ׺��һ��������
//��s2���ȴ���s1ʱ����s2���ȳ����ֵ�������ƥ���Ӵ��ĳ��ȣ��϶���������s2�ͽ�����ѯѭ����ֻ��ͳ��cnt���ж��ٸ�s1��������s2���ϵ�
//��s2����С�ڵ���s1ʱ����ʱs2����������Ϊs1��ǰ׺��ͳ��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6;
// int n, m, cnt = 1;
// char s[N];
// struct nd{
//     int son[2];
//     int num;    //ͳ�����ǰ׺���ִ���
//     int cnt;    //ͳ�Ƶ��ʵĳ��ִ���
//     //����һ������������һ�����ʣ������βʱ������ num �� cnt ���ظ���������Ϊ��ʱǰ׺����һ��������
// }tree[N];
// void Insert(char *s, int len)
// {
//     int p = 0;
//     for(int i = 0; i < len; i++)
//     {
//         int id = s[i] - '0';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//         tree[p].num++;
//     }
//     tree[p].cnt++;
// }
// int Find(char *s, int len)
// {
//     int p = 0, res = 0;
//     bool ok = 0;
//     for(int i = 0; i < len; i++)
//     {
//         int id = s[i] - '0';
//         if(!tree[p].son[id])//���жϣ���û�б���������s2 > s1
//         {
//             ok = 1;
//             break;
//         }
//         p = tree[p].son[id];
//         res += tree[p].cnt;//��ʱs2 >= s1������s1�������ʵĳ��ִ���������� s2 == s1�����������ظ������ˣ�
//     }
//     if(!ok)//s2 <= s1
//     {
//         //ֱ�Ӽ����ж��ٵ�����s2Ϊǰ׺������ȥ�ظ�������s2 == s1ʱ����cnt
//         res += tree[p].num - tree[p].cnt;
//     }
//     return res;
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     int x;
//     while(n--)
//     {
//         cin >> x;
//         for(int i = 0; i < x; i++) cin >> s[i];
//         Insert(s, x);
//     }
//     while(m--)
//     {
//         cin >> x;
//         for(int i = 0; i < x; i++) cin >> s[i];
//         cout << Find(s, x) << '\n';
//     }
//     return 0;
// }



//3.Shortest Prefixes
//���⣺��n���ַ���s�����ÿ���ַ��������Ψһǰ׺s0����s0���ҽ���s��ǰ׺�������������κε��ʵ�ǰ׺����s0����Ϊs��
//      ��Ŀ���������s0==sʱs0���������������ʵ�ǰ׺�Ļ��������s0��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6;
// int n, m, cnt = 1;
// string s[1005];
// struct nd{
//     int son[26];
//     int num;    //ͳ�����ǰ׺���ִ���
// }tree[N];
// void Insert(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//         tree[p].num++;
//     }
// }
// string Find(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         p = tree[p].son[id];
//         if(tree[p].num == 1)
//         {
//             return s.substr(0, i + 1);
//         }
//     }
//     return s;
// }
// int main()
// {
//     untie();
//     int ind = 0;
//     while(cin >> s[++ind])
//     {
//         Insert(s[ind]);
//     }
//     for(int i = 1; i <= ind; i++)
//     {
//         cout << s[i] << ' ' << Find(s[i]) << '\n';
//     }
//     return 0;
// }



//4.Phone List������ + �ֵ�����
//���⣺�� T ���ַ����飬ÿ���� n ���ַ������ж����� n ���ַ��� s �Ƿ�����أ��� s ����������һ�����ַ�������ǰ׺��
//      �� 9135 �� 91125 ����� �����ַ����飬��Ϊ 91 �����ǵĹ���ǰ׺
//˼·����ǵ���ǰ׺����Ϊֻ�б� s �̵��ִ��ſ��ܳ�Ϊ s ��ǰ׺�����Կ����ɶ̵������򣬱߲�����ж�֮ǰ����Ķ��ִ��Ƿ�Ϊǰ׺ ���ɡ�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e5 + 10;
// int n, m, cnt = 1;
// string s[10005];
// struct nd{
//     int son[10];
//     int num;    //ͳ��ǰ׺���ִ���
// }tree[N];
// bool Insert(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - '0';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//         tree[p].num++;
//     }
//     return tree[p].num > 1;//�����������б���ִ�
// }
// bool cmp(const string &s1, const string &s2) { return s1.size() > s2.size();}
// void Solve()
// {
//     cnt = 1;
//     memset(tree, 0, sizeof(tree));//�ǵó�ʼ��
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> s[i];
//     sort(s, s + n, cmp);
//     for(int i = 0; i < n; i++)
//     {
//         if(Insert(s[i]))
//         {
//             cout << "NO\n";
//             return;
//         }
//     }
//     cout << "YES\n";
// }
// int main()
// {
//     untie();
//     int T;
//     cin >> T;
//     while(T--) Solve();
//     return 0;
// }



//5.ȫ�ļ������򵥲��ң�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <set>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6;
// int n, m, cnt = 1;
// string text, t;
// vector<int> ans;
// bool vis[N];
// struct nd{
//     int son[10];
//     int id;     //�ؼ��ֱ��
// }tree[N];
// void Insert(string s, int id)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - '0';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//     }
//     tree[p].id = id;
// }
// int Find(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - '0';
//         p = tree[p].son[id];
//         if(!p) break;                           //��β����һ�����pΪ��
//         if(tree[p].id != 0) return tree[p].id;  //�ҵ�
//     }
//     return 0;                                   //û�ҵ�
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) cin >> t, text += t;//����������ֹ�ؼ��ֿ��д���
//     for(int i = 1; i <= m; i++)
//     {
//         string tt;
//         cin >> tt >> tt >> tt >> t;
//         Insert(t, i);
//     }
//     for(int i = 0; i < text.size(); i++)
//     {
//         int res = Find(text.substr(i));//ö��Ѱ�ң��ؼ��ֳ��Ȳ�������������ʱ�����ж������鷳���ɴ�ֱ��ȫȡ��
//         if(res && !vis[res])
//         {
//             vis[res] = 1;
//             ans.push_back(res);
//         }
//     }
//     if(ans.empty()) cout << "No key can be found !\n";
//     else
//     {
//         cout << "Found key:";
//         for(int i = 0; i < ans.size(); i++) cout << " [Key No. " << ans[i] << "]";
//         cout << '\n';
//     }
//     return 0;
// }



//6.�Ķ����
//MLE
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <set>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6;
// int n, m, cnt = 1;
// string t;
// struct nd{
//     int son[26];
//     // vector<int> ids;     //���
//     set<int> ids;
// }tree[N];
// void Insert(string s, int id)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//     }
//     tree[p].ids.insert(id);
// }
// void Find(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         p = tree[p].son[id];
//         if(!p) break;
//     }
//     bool tmp = 0;
//     for(auto id : tree[p].ids)
//     {
//         if(tmp) cout << " ";
//         cout << id;
//         tmp = 1;
//     }
// }
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//     {
//         int num; cin >> num;
//         while(num--)
//         {
//             cin >> t;
//             Insert(t, i);
//         }
//     }
//     cin >> m;
//     while(m--)
//     {
//         cin >> t;
//         Find(t);
//         cout << '\n';
//     }
//     return 0;
// }
//���� n = 1000 �����ݿ��ռ䣬bool ans[N][1001] ��MLE������Ϊ 1001 ��� WA
//AC
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <bitset>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 5e5 + 10;
// int n, m, cnt = 1;
// string t;
// struct nd{
//     int son[26];
// }tree[N];
// bitset<1001> ans[N];//ans[p][id] = 1����ʾ���� p �ڵ� id ���Ǵ��ڵģ�����id��Ϣ�����㣬������ʡ�ռ�
// void Insert(string s, int id)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//     }
//     ans[p][id] = 1;
// }
// void Find(string s)
// {
//     int p = 0, ok = 1;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         p = tree[p].son[id];
//         if(!p) 
//         {
//             ok = 0;
//             break;
//         }
//     }
//     if(!ok) return;
//     for(int i = 1; i <= n; i++)
//         if(ans[p][i]) cout << i << " ";
// }
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//     {
//         int num; cin >> num;
//         while(num--)
//         {
//             cin >> t;
//             Insert(t, i);
//         }
//     }
//     cin >> m;
//     while(m--)
//     {
//         cin >> t;
//         Find(t);
//         cout << '\n';
//     }
//     return 0;
// }



//7.Hat��s Words�����ʴ������⣩
//���⣺�ں����ɸ����ʵ��ֵ����У����ֵ���������С������������������ʴ������ɵġ����ʣ��� a��ahat��hat �� ahat ���� a �� hat �Ĵ���
//˼·������ÿ�����ʣ�ö�����зֽ�������жϷֽ���������Ӵ��Ƿ񶼴��ڣ���������
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <bitset>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 5e5 + 10;
// int cnt = 1, ind = 0;
// string s[N];
// struct nd{
//     int son[26];
//     bool isend;
// }tree[N];
// void Insert(string s)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//     }
//     tree[p].isend = 1;
// }
// bool Find(string s)
// {
//     int p = 0, ok = 1;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         p = tree[p].son[id];
//         if(!p) return 0;
//     }
//     return tree[p].isend;
// }
// int main()
// {
//     untie();
//     while(cin >> s[++ind]) Insert(s[ind]);
//     for(int i = 1; i <= ind; i++)
//         for(int len = 1; len < s[i].size(); len++)        
//             if(Find(s[i].substr(0, len)) && Find(s[i].substr(len)))
//             {
//                 cout << s[i] << '\n';
//                 break;//��ֹ�ظ����ͬһ���ַ���
//             }
//     return 0;
// }



//8.Spy Syndrome 2
//���⣺����һ���ַ��� s���Լ� m �����ʣ��� s ����ԭ�侭�� ��д��Сд����ת��ɾ���ո� ת���ģ���Ҫ��� m �����ʺ� s �Ƴ�ԭ�� s0��
//˼·������Ҫƥ����ı� s ������ģ��� m ������ȡСд����ת���ٴ����ֵ�����
//������ "ancestorandan" �� �赹��󵥴�Ϊ"an"��"and"��"ancestor"���޷�ֱ��O(n)�����Ƴ� an ��λ��������������Ҫ dfs ����ÿ�����ʵĹ�����������з���  
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <cctype>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6 + 10;
// int n, m, cnt = 1;
// string str, s[N];
// vector<int> ans;
// struct nd{
//     int son[26];
//     int id;
// }tree[N];
// void Insert(string s, int ind)
// {
//     int p = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         int id = s[i] - 'a';
//         if(!tree[p].son[id])
//             tree[p].son[id] = cnt++;
//         p = tree[p].son[id];
//     }
//     tree[p].id = ind;
// }
// bool dfs(int now)//������Ϊ n ���ı� s
// {
//     if(now == n) 
//     {
//         for(auto i : ans)
//             cout << s[i] << " ";
//         return 1;
//     }
//     int p = 0;
//     for(int i = now; i < str.size(); i++)
//     {
//         int id = str[i] - 'a';
//         p = tree[p].son[id];
//         if(!p) break;
//         if(tree[p].id)//��������ƥ�䵥�ʾ���������
//         {
//             ans.push_back(tree[p].id);
//             if(dfs(i + 1)) return 1;
//             ans.pop_back();//�ܵ�����˵���������У�����
//         }
//     }
//     return 0;
// }
// int main()
// {
//     untie();
//     cin >> n >> str >> m;
//     for(int i = 1; i <= m; i++)
//     {
//         cin >> s[i];
//         string t = s[i];
//         reverse(t.begin(), t.end());
//         for(auto &ch : t)//תСд����ת�����ֵ�����
//             if(isupper(ch)) ch += 'a' - 'A';
//         Insert(t, i);
//     }
//     dfs(0);     
//     return 0;
// }



//*9.The xor-longest Path��01-Trie + ������ͣ�
// ���� ���壺S(u, v) Ϊ ��������б�Ȩ�����ֵ���� 4 ����䣨����u������v���� 3 ���� w1��w2��w3���� S(u, v) = w1 ^ w2 ^ w3���� ���͡� �ĺ��������������ǡ�����ϡ�
// ���⣺
//      �����Ȩ�� G(u, v)�������·��Ϊ ����·����������Ȩֵ�����ֵԽ��·��Խ��������������·�������ֵ�͵����ֵ max{S(u, v)}��
//      ���������򳤶�Ϊ����֮�� ���б�Ȩֵ����� �õ���ֵ��
// ������
//      ���� (a xor b) xor (b xor c) = a xor c �� b xor b = 0���������������� S1��S2�����Ƕ�����һ������·�� S0��
//      �ֱ�ȡ�����Ե� S0���� S1 ^ S2 = (S1' ^ S0) ^ (S2' ^ S0) = S1' ^ S2'����ֱ�� S1 ^ S2 ����ȡ�����Ǽ�����Ĳ��� S1' ^ S2'
// ˼·��
//      ��ô���ǿ��Զ��岢Ԥ���� S(0, u) �� S(0, v)�������׼���� S(u, v) = S(0, u) ^ S(0, v)
//      ��֪������Ȩ����Ȼ��������ͨ��������ֻ��Ҫ���� ����u �� ���ڵ㣨��Ϊ0���� ���� dis[u]������ȡ�� S(u, v) = dis[u] ^ dis[v]
//      ��Ϊ����ͼ��������������ѣ��� dfs ��� ���ڵ� ������������ i ��·�����Ȩֵ�� dis[i]�������������ɻ���dfs������ֻҪ��ֹԭ·���ؾ��У����ջ�ֹͣ��Ҷ�ӽ��
//      ̰��˼�� - ��ѯʱ��ѡ������·����ѡ������ֻ��ѡ��ͬ����������ĳλ���� 1�������� 0��ʹ�����ֵ��󣩡�
//��vector�ڽӱ�治�� C++ ���� G++ ����TLE
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <cctype>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e5 + 10;
// int n, m, cnt = 1, ans = 0;
// int tree[N << 5][2], dis[N];
// struct Edge{
//     int to, w;
//     Edge(int a = 0, int b = 0) {to = a, w = b;}
// };
// vector<Edge> G[N];
// void init()
// {
//     cnt = 1;
//     ans = 0;
//     for(int i = 0; i <= n; i++) G[i].clear();
//     memset(tree, 0, sizeof(tree));
//     memset(dis, 0, sizeof(dis));
// }
// void dfs(int u, int father)
// {
//     for(int i = 0; i < G[u].size(); i++)
//     {
//         int v = G[u][i].to;
//         if(v == father) continue;
//         dis[v] = dis[u] ^ G[u][i].w;
//         dfs(v, u);
//     }
// }
// void Insert(int x)
// {
//     int p = 0;
//     for(int i = 31; i >= 0; --i)//��Ϊ���wΪ2^31���ʿɶ�Ϊ31λ�����ƣ��Ӹ�λ����λ�������ֵӰ��������������򷽰�
//     {
//         int id = (x >> i) & 1;//ȡ�� i ��λ
//         if(!tree[p][id]) tree[p][id] = cnt++;
//         p = tree[p][id];
//     }
// }
// int Find(int x)
// {
//     int p = 0, res = 0;
//     for(int i = 31; i >= 0; --i)
//     {
//         int id = (x >> i) & 1;                                   //��� i ���Ϊ 32������� 1 << i ��Խ��
//         if(tree[p][id ^ 1]) p = tree[p][id ^ 1], res += (1 << i);//��������ͬ�����ߣ�ʹ�����ֵ�ڵ�iλΪ1
//         else p = tree[p][id];
//         if(!p) break;
//     }
//     return res;
// }
// int main()
// {
//     untie();
//     while(cin >> n)
//     {
//         init();
//         for(int i = 1; i < n; i++)
//         {
//             int u, v, w;
//             cin >> u >> v >> w;
//             ++u, ++v;
//             G[u].push_back(Edge(v, w));
//             G[v].push_back(Edge(u, w));
//         }
//         dfs(1, 1);//�����Ϊ1
//         for(int i = 1; i <= n; i++) Insert(dis[i]);//��������·������
//         //Find()Ѱ��һ���� dis[i] �������ǿ����һ��·�������������ͬ��λ��0����ͬ�ű�1
//         for(int i = 1; i <= n; i++) ans = max(ans, Find(dis[i]));
//         cout << ans << '\n';
//     }
//     return 0;
// }
//��ʽǰ���� �� bin[i]Ԥ���� ���٣�G++ �ɹ�
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <cctype>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e5 + 10;
// int n, m, cnt = 1, ans = 0;
// int tree[N << 5][2], dis[N];
// int head[N], bin[50];
// struct Edge{
//     int to, w, next;
//     Edge(int a = 0, int b = 0, int c = 0) {to = a, w = b, next = c;}
// }edge[N << 2];
// void init()
// {
//     cnt = 1;
//     ans = 0;
//     memset(head, 0, sizeof(head));
//     memset(tree, 0, sizeof(tree));
//     memset(dis, 0, sizeof(dis));
// }
// void addedge(int u, int v, int w)
// {
//     edge[cnt] = Edge(v, w, head[u]);
//     head[u] = cnt++;
// }
// void dfs(int u, int father)
// {
//     for(int i = head[u]; i; i = edge[i].next)//��Ŵ� 1 ��ʼ
//     {
//         int v = edge[i].to;
//         if(v == father) continue;
//         dis[v] = dis[u] ^ edge[i].w;
//         dfs(v, u);
//     }
// }
// void Insert(int x)
// {
//     int p = 0;
//     for(int i = 31; i >= 0; --i)//��Ϊ���wΪ2^31���ʿɶ�Ϊ31λ�����ƣ��Ӹ�λ����λ�������ֵӰ��������������򷽰�
//     {
//         bool id = x & bin[i];//ȡ�� i ��λ��ת bool���൱�� id = (x & bin[i]) != 0
//         if(!tree[p][id]) tree[p][id] = cnt++;
//         p = tree[p][id];
//     }
// }
// int Find(int x)
// {
//     int p = 0, res = 0;
//     for(int i = 31; i >= 0; --i)//��� i ���Ϊ 32�� bin[i] = 1 << i ��Խ��
//     {
//         bool id = x & bin[i];            
//         if(tree[p][id ^ 1]) p = tree[p][id ^ 1], res += bin[i];//��������ͬ�����ߣ�ʹ�����ֵ�ڵ�iλΪ1
//         else p = tree[p][id];
//         if(!p) break;//������ʵ����Ҫ�������϶��ֲ����һ�����
//     }
//     return res;
// }
// int main()
// {
//     bin[0] = 1;
//     for(int i = 1; i <= 32; i++) bin[i] = bin[i - 1] << 1;
//     untie();
//     while(cin >> n)
//     {
//         init();

//         for(int i = 1; i < n; i++)
//         {
//             int u, v, w;
//             cin >> u >> v >> w;
//             ++u, ++v;
//             addedge(u, v, w);
//             addedge(v, u, w);
//         }
        
//         dfs(1, 1);//�����Ϊ1

//         for(int i = 1; i <= n; i++) Insert(dis[i]);//���� ���е�i �� ��� ������
//         for(int i = 1; i <= n; i++) ans = max(ans, Find(dis[i]));
//         cout << ans << '\n';
//     }
//     return 0;
// }



//10.Consecutive Sum������С���ͣ�
//�ص㣺���� ��С���� ʱ�������Լ����Լ����Ϊ 0���ʺ������������Լ�Ȼ��ֻ�õ� 0
//���������� dis[i] ֮���ټ��� dis[i]�������ǿ��԰��������������� C(n, 2)��ÿ����չ�ֵ���
//�� 1 2 3 4 5��dis[1] �� 0 -> dis[2] �� {1} �� -> dis[3] �� {1 2} �� -> dis[4] �� {1 2 3} �� -> dis[5] �� {1 2 3 4}�����Ժ��������������
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int N = 5e4 + 100;
// int n, T, cnt, mmin, mmax;
// int dis[N], bin[N], trie[N << 5][9];//dis[i] �� a0 ~ ai ������
// void init()
// {
//     cnt = 1, mmin = 2e9, mmax = 0;
//     memset(trie, 0, sizeof(trie));
// }
// void Insert(int x)
// {
//     int p = 0;
//     for(int i = 31; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         if(!trie[p][id]) trie[p][id] = cnt++;
//         p = trie[p][id];
//     }
// }
// int Find_xor_min(int x)
// {
//     int p = 0, res = 0;
//     for(int i = 31; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         if(trie[p][id]) p = trie[p][id];
//         else p = trie[p][id ^ 1], res += bin[i];
//         if(!p) break;//��ʵҲ��ͬ�жϣ���Ϊ��Ȼ�� p != 0�������Ҫ�ߵ�·���ֲ��߲�ͨ����ô�ͻص�ԭ·��ԭ·��Ȼ���ڣ�
//     }
//     return res;
// }
// int Find_xor_max(int x)
// {
//     int p = 0, res = 0;
//     for(int i = 31; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         if(trie[p][id ^ 1]) p = trie[p][id ^ 1], res += bin[i];
//         else p = trie[p][id];
//         if(!p) break;
//     }
//     return res;
// }
// int main()
// {
//     bin[0] = 1;
//     for(int i = 1; i <= 31; ++i) bin[i] = bin[i - 1] << 1;
//     scanf("%d", &T);
//     for(int _ = 1; _ <= T; ++_)
//     {
//         init();
        
//         scanf("%d", &n);
//         for(int i = 1; i <= n; i++) 
//         {
//             scanf("%d", &dis[i]);
//             dis[i] ^= dis[i - 1];
//         }
//         Insert(0);//����������ֵ�������� dis[i] �������Լ��� 0 ����������� 0 ���õ��Լ������ֵ
//         for(int i = 1; i <= n; i++) 
//         {
//             // cout << i << ": " << Find_xor_max(dis[i]) << " " << Find_xor_min(dis[i]) << '\n';
//             mmin = min(mmin, Find_xor_min(dis[i]));
//             mmax = max(mmax, Find_xor_max(dis[i]));
//             Insert(dis[i]);
//         }
//         printf("Case %d: %d %d\n", _, mmax, mmin);
//     }
//     return 0;
// }




//11.Problem C���ֵ����������
//���ֲ��������뵥�ʡ�ɾ������ǰ׺Ϊs�ĵ��ʡ���ѯǰ׺Ϊs�ĵ����Ƿ����
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 1e5 + 10;
// struct nd{
//     int son[26];
//     int num;    //ǰ׺���ִ���
//     void init()
//     {
//         num = 0;
//         memset(son, 0, sizeof(son));
//     }
// }trie[N << 5];
// int ind = 1;
// char s[100];
// void Insert(char *s)
// {
//     int len = strlen(s), p = 0;
//     for(int i = 0; i < len; i++)
//     {
//         int id = s[i] - 'a';
//         if(!trie[p].son[id]) trie[p].son[id] = ind++;
//         p = trie[p].son[id];
//         trie[p].num++;
//     }
// }
// int Find(char *s)
// {
//     int len = strlen(s), p = 0;
//     for(int i = 0; i < len; i++)
//     {
//         int id = s[i] - 'a';
//         p = trie[p].son[id];
//         if(!p) return 0;
//     }
//     return trie[p].num;
// }
// void Delete(char *s)//d Ϊɾȥǰ׺�ĳ��ִ�������Ӧ�侭����ÿ���ַ��϶�Ҫ��ȥd
// {
//     int d = Find(s);
//     if(!d) return;  //��ֹ���Del���Ȳ��Ƿ����
//     int len = strlen(s), p = 0;
//     for(int i = 0; i < len; i++)
//     {
//         int id = s[i] - 'a';
//         p = trie[p].son[id];
//         if(!p) return;
//         trie[p].num -= d;//ɾ�����
//     }
//     trie[p].init();
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     while(n--)
//     {
//         char op[10];
//         cin >> op >> s;
//         if(op[0] == 'i') Insert(s);
//         else if(op[0] == 'd') Delete(s);
//         else cout << (!Find(s) ? "No\n" : "Yes\n");
//     }
//     return 0;
// }



//12.Choosing The Commander
// ���⣺
//      ʿ����ѡָ�ӹ� j������ Pj �� Lj�������ҽ��� Pi ^ Pj < Lj ������ʿ�� i �� j �𾴣�
//      �����ֲ���������ʿ�� Pi��ɾ��ʿ�� Pi��ѡָ�ӹ٣����� Pj �� Lj����ͳ���ж���ʿ��������
// ˼·��
//      �������в����ɾ������������ѯ�ʲ����������� Pi����̰�ĵ����� Lj ��ÿһλ x�����Ӹ�λ��ʼ��
//      �ٸ����ӣ����� 1010110�����ǴӸ�λ 1 ��ʼ���Ƿ��б� 1010110 С���������Ը�λ��Ϊ 0 ���������ԣ���� 0��������ô�Ҷ��Ҳ����� 0 С�ģ�
//      ����ע�⣬����Ҫ�ҵ��� Pi �� Pj ���Ľ����
// ���ۣ�
//      ����λ x Ϊ 1���� Pi ^ Pj �л�������������λ�����Ϊ 0 ��ʹ�� Pi ^ Pj < Lj ��ֻҪ��λС�ڣ��س�����������ͬ��λ��ͬ�����num��
//      Ȼ���ʱ�Ը� x ����������ʿ�� Pj �Ѿ�ȫ�����ϣ���ô���� Pj �͵��л�����������ʿ������Ȼ��ֻ���ظ��������
//      ����λ x Ϊ 0���򲻿����ҵõ������ Lj С��������ֻ������ pi ��·�ߣ���ʱ�ֲ��� Pi ^ Pj == Lj��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 1e5 + 10, MAXL = 2e9;
// struct nd{
//     int son[2];
//     int num;   //ǰ׺���ִ���
// }trie[N << 5];
// int q, cnt = 1, bin[50];
// void Insert(int x)
// {
//     int p = 0;
//     for(int i = 30; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         if(!trie[p].son[id]) trie[p].son[id] = cnt++;
//         p = trie[p].son[id];
//         ++trie[p].num;
//     }
// }
// void Delete(int x)
// {
//     int p = 0;
//     for(int i = 30; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         p = trie[p].son[id];
//         --trie[p].num;
//     }
// }
// int Search(int x, int lim)//x Ϊ������ָ�ӹ� Pj
// {
//     int p = 0, res = 0;
//     for(int i = 30; i >= 0; --i)//��������ʿ�� Pi
//     {
//         bool id = x & bin[i];
//         bool limx = lim & bin[i];
//         if(limx)
//         {
//             //������λ��ͬ��ʿ��
//             res += trie[trie[p].son[id]].num;//�ص㣺Ҫ������һ����Ϊ��ǰ��Ӧ����������һ�����
//             p = trie[p].son[id ^ 1];         //����ѡ��һ�������֣���������������С��������ʿ��
//         }
//         else
//         {
//             p = trie[p].son[id];             //limx = 0 ֻ�ܲ�ԭ·���˺� Pi ^ Pj <= lim��������С�ڵĿ����ԣ�����Ϊ��һ��·�Ǻ�Ϊ Pi ^ Pj > lim ��
//         }
//         if(!p) break;//���� trie[p].son[] = 0 ����Ч·�����������ֹ�ٻص����ڵ� 0
//     }
//     return res;
// }
// int main()
// {
//     bin[0] = 1;
//     for(int i = 1; i <= 30; ++i) bin[i] = bin[i - 1] << 1;

//     scanf("%d", &q);
//     while(q--)
//     {
//         int op, p, l;
//         scanf("%d%d", &op, &p);
//         if(op == 1) Insert(p);
//         else if(op == 2) Delete(p);
//         else
//         {
//             scanf("%d", &l);
//             printf("%d\n", Search(p, l));
//         }
//     }
//     return 0;
// }



//13.Chip Factory
// ��Ŀ��ά�� max{ ( Si + Sj ) ^ Sk } = max{ sum ^ Sk } (i != j != k���� sum Ϊ ����֮��)
// ˼·����������ֵ������ Sk������ k != i != j ������ǰҪ���ֵ�����ɾ��һ�� Si �� Sj��ǿ����һ�μ��ɣ������ܻ�������������±겻һ���Ϳ����ˣ����������ٲ���һ�λ���
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 5e3 + 10;

// struct nd{
//     int son[2];
//     int num;
// }trie[N << 5];
// int T, n, cnt = 1;
// int s[N], bin[50];

// void init()
// {
//     cnt = 1;
//     memset(trie, 0, sizeof(trie));
// }

// void Insert(int x)
// {
//     int p = 0;
//     for(int i = 30; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         if(!trie[p].son[id]) trie[p].son[id] = cnt++;
//         p = trie[p].son[id];
//         ++trie[p].num;
//     }
// }

// void Delete(int x)
// {
//     int p = 0;
//     for(int i = 30; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         p = trie[p].son[id];
//         --trie[p].num;
//     }
// }

// int Find_xor_max(int x)
// {
//     int p = 0, res = 0;
//     for(int i = 30; i >= 0; --i)
//     {
//         bool id = x & bin[i];
//         if(trie[trie[p].son[id ^ 1]].num)//�鵱ǰǰ׺��������Ҫ����һ�������
//         {
//             res |= bin[i];               //���������ֵ
//             p = trie[p].son[id ^ 1];
//         }
//         else
//             p = trie[p].son[id];
//         if(!p) break;
//     }
//     return res;
// }

// int main()
// {
//     bin[0] = 1;
//     for(int i = 1; i <= 31; ++i) bin[i] = bin[i - 1] << 1;

//     scanf("%d", &T);
//     while(T--)
//     {
//         init();

//         scanf("%d", &n);
//         for(int i = 0; i < n; i++) scanf("%d", &s[i]), Insert(s[i]);

//         int mmax = 0;
//         for(int i = 0; i < n; i++)//��������ö�� s[i] + s[j] ���
//         {
//             Delete(s[i]);
//             for(int j = i + 1; j < n; j++)
//             {
//                 Delete(s[j]);
//                 mmax = max(mmax, Find_xor_max(s[i] + s[j]));
//                 Insert(s[j]);
//             }
//             Insert(s[i]);
//         }
//         printf("%d\n", mmax);
//     }
//     return 0;
// }













/*ʮ��. KMP�ַ���ƥ���㷨*/
//ģ�� KMP�ַ���ƥ��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6 + 10;

// int lps[N];//���� lps[i] ��ָ p[0] ~ p[i] ��lps
// string s, p;

// void getlps(string p)
// {
//     int plen = p.size();
//     lps[0] = 0;//���ַ�û����ǰ��׺������Ϊ����
//     for(int i = 1; i < plen; i++)
//     {
//         int j = lps[i - 1];
//         while(j > 0 && p[i] != p[j]) j = lps[j - 1];
//         if(p[i] == p[j]) ++j;//�����ַ��� s[j] ��Ⱦ�����
//         lps[i] = j;
//     }
// }

// void kmp(string s, string p)
// {
//     getlps(p);//Ԥ���� lps[i]
//     int slen = s.size(), plen = p.size();
//     int j = 0;
//     for(int i = 0; i < slen; i++)//��������ƥ��
//     {
//         while(j > 0 && s[i] != p[j]) j = lps[j - 1];
//         if(s[i] == p[j]) ++j;
//         if(j == plen) cout << i - plen + 2 << '\n';//�� P ��ȫƥ�� S'����� S ��ƥ����ʼλ��
//     }
//     //��� lps[i]
//     for(int i = 0; i < plen; i++) cout << lps[i] << ' ';
// }

// int main()
// {
//     untie();
//     cin >> s >> p;
//     kmp(s, p);
//     return 0;
// }



//1.Wow! Such Doge! (hdu-4847)
// �������������е���doge(��Сд������)�ĳ��ִ���
// ����"doge"���ַ���ͬ��lps ��Ϊ 0��ֱ��ƥ�伴��
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6 + 10;

// int ans = 0;
// string s, p[20] = {"doge","Doge","dOge","doGe", "dogE", "DOge", "DOGe", "DOGE","DOgE","DoGE","DoGe","DogE","dOGE","dOgE","dOGe","doGE"};

// void kmp(string s, string p)
// {
//     int slen = s.size(), plen = p.size();
//     for(int i = 0, j = 0; i < slen; i++)//��������ƥ��
//     {
//         while(j > 0 && s[i] != p[j]) j = 0;
//         if(s[i] == p[j]) ++j;
//         if(j == plen) ++ans;//P ��ȫƥ�� S'
//     }
// }

// int main()
// {
//     untie();
//     while(cin >> s)
//     {
//         for(int i = 0; i < 16; ++i)
//             kmp(s, p[i]);
//     }
//     cout << ans << '\n';
//     return 0;
// }



//2.Compress Words (cf1200E)��ǰ��׺ƥ�䣩
//�������ʺϲ�ʱҪ��ɾ���ڶ������������һ�����ʺ�׺�غϵ�ǰ׺
//�ص㣺����Ƶ������ string��� size()����������Ӱ��Ч�ʣ���TLE
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6 + 10;

// int lps[N];
// int n, slen = 0, ind = 0;
// string s, p;

// void getlps(int plen)
// {
//     lps[0] = 0;
//     for(int i = 1; i < plen; i++)
//     {
//         int j = lps[i - 1];
//         while(j && p[i] != p[j]) j = lps[j - 1];
//         if(p[i] == p[j]) ++j;
//         lps[i] = j;
//     }
// }

// int kmp(int plen)
// {
//     int res = 0;
//     getlps(plen);
//     for(int i = ind, j = 0; i < slen; i++)
//     {
//         while(j && s[i] != p[j]) j = lps[j - 1];
//         if(s[i] == p[j]) ++j;
//         res = j;
//     }
//     return res;
// }

// int main()
// {
//     untie();
//     cin >> n;
//     cin >> s;
//     n--;
//     ind = 0;
//     slen = s.size();
//     while(n--)
//     {
//         cin >> p;//����ģ��
//         int plen = p.size();
//         ind = max(0, slen - plen);//�����жϵĺ�׺����[slen - plen, slen - 1]��ģp������ͬ �� ģP�ȵ�ǰS������ ind = 0
//         int res = kmp(plen);//�ƥ��ǰ��׺����
//         s += p.substr(res);//��������
//         slen += plen - res;
//     }
//     cout << s;
//     return 0;
// }



//3.�ǰ׺ Longest Prefix��KMP + DP��
//kmpƥ����ü����и�Ԫ�����ַ��� S �еĳ���λ�ã����� dp ����ǰ׺
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <cstring>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 2e5 + 10;

// int lps[N], dp[N];
// vector<string> v;
// vector<int> id[N];
// string s, x;

// void getlps(string p, int plen)
// {
//     lps[0] = 0;
//     for(int i = 1; i < plen; i++)
//     {
//         int j = lps[i - 1];
//         while(j && p[i] != p[j]) j = lps[j - 1];
//         if(p[i] == p[j]) ++j;
//         lps[i] = j;
//     }
// }

// void kmp(string s, string p)
// {
//     int slen = s.size(), plen = p.size();
//     getlps(p, plen);
//     for(int i = 0, j = 0; i < slen; i++)
//     {
//         while(j && s[i] != p[j]) j = lps[j - 1];
//         if(s[i] == p[j]) ++j;
//         if(j == plen) id[i + 1].push_back(plen);
//     }
// }

// int main()
// {
//     untie();
//     while(cin >> s)
//     {
//         if(s[0] == '.') break;
//         v.push_back(s);
//     }
//     s = "";
//     while(cin >> x) s += x;//�����ж���
//     int slen = s.size();
//     for(auto str : v) kmp(s, str);
//     dp[0] = 1;//�����Ƕ���Щ plen ������ɵ�ǰ���� i ��Ϊ������״̬��
//     for(int i = 1; i <= slen; i++)//ö�ٵ���� i ���ַ� s[i - 1] ʱ(ö�ٳ���)
//         for(int j = 0; j < id[i].size(); j++)//ö�ٿ�ѡ��ķ���
//             if(dp[i - id[i][j]]) dp[i] = 1;//�ɴ���һ��״̬���ӳ�
//     int res = 0;
//     for(int i = 1; i <= slen; i++) 
//         if(dp[i]) res = max(res, i);//��ɴ��ܵ���������
//     cout << res;
//     return 0;
// }



//4.Radio Transmission ���ߴ��䣨���ѭ�������⣩
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int N = 1e6 + 10;
// int lps[N];
// char s[N];
// void getlps(char *s, int len)
// {
//     for(int i = 1; i < len; i++)
//     {
//         int j = lps[i - 1];
//         while(j && s[i] != s[j]) j = lps[j - 1];
//         if(s[i] == s[j]) ++j;
//         lps[i] = j;
//     }
// }
// int main()
// {
//     int n;
//     scanf("%d%s", &n, s);
//     getlps(s, n);
//     printf("%d\n", n - lps[n - 1]);//���� lps[n - 1] ���� s[0] ~ s[n - 1] ������Ϊ n ��ǰ׺�� lps���ȡ�
//     return 0;
// }



//5.Period�����ѭ�������⣩
//���� S ������ǰ׺ s���������Լ������� s �������ɸ����������ѭ���� k ��ɣ������ s �ĳ��� �� ���ѭ������ s �еĸ���
// #include <cstdio>
// #include <algorithm>
// #include <string>
// #include <iostream>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6 + 10;

// int n, lps[N];
// string s;

// void getlps(int slen)
// {
//     for(int i = 1; i < slen; i++)
//     {
//         int j = lps[i - 1];
//         while(j && s[i] != s[j]) j = lps[j - 1];
//         if(s[i] == s[j]) ++j;
//         lps[i] = j;

//         int len = i + 1, k = len - lps[i];
//         if(lps[i] && len % k == 0) 
//             cout << len << ' ' << len / k << '\n';
//     }
    
// }

// int main()
// {
//     untie();
//     int T = 1;
//     while(cin >> n)
//     {
//         if(!n) break;
//         cin >> s;
//         int slen = s.size();
//         cout << "Test case #" << T++ << '\n';
//         getlps(slen);
//         cout << '\n';
//     }
//     return 0;
// }



//6.Theme Section��ǰ��׺���⣩
//�����൱���� �ַ���s �� lps Ȼ��õ�����ǰ��׺�ĳ��� k�����ж� s ����׺ k �Ƿ���ڣ���ǰ׺ k �����ں�׺ k ǰ������������� k
// #include <cstdio>
// #include <algorithm>
// #include <string>
// #include <iostream>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 1e6 + 10;

// int t, lps[N];
// string s;

// int getlps(int slen)
// {
//     for(int i = 1; i < slen; i++)
//     {
//         int j = lps[i - 1];
//         while(j && s[i] != s[j]) j = lps[j - 1];
//         if(s[i] == s[j]) ++j;
//         lps[i] = j;                    
//     }
//     return lps[slen - 1];
// }

// int main()
// {
//     untie();
//     cin >> t;
//     while(t--)
//     {
//         cin >> s;
//         int slen = s.size();
//         int k = getlps(slen), ok = 0;
//         k = min(slen / 2, k);//ǰ��׺���Ȳ����� s ���ȵ�һ�룬�� "aaa" �� lps = 2����ʵ��ǰ��׺����Ϊ 1
//         if(!k) 
//         {
//             cout << "0\n";
//             continue;
//         }
//         for(int i = k; i < slen - k; i++)
//         {
//             if(lps[i] == k)
//             {
//                 ok = 1;
//                 break;
//             }
//         }
//         if(ok) cout << k << '\n';
//         else cout << "0\n";
//     }
//     return 0;
// }



//7.hdu 2328 Corporate Identity��������Ӵ����� - KMP + ������
//�� n ���ַ�����������Ӵ��������ֵ�����С��
//��Ȼ���󹫹��Ӵ� lcs����ô������ȡ��һ���ַ��� p ��Ϊģʽ������ö���������к�׺���� lps
//�����൱�ڰ��������п��ܵĹ����Ӵ����
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <string>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 4e3 + 10, M = 210;

// int n, plen, lps[M];
// string s[N], p;

// void getlps(int st)
// {
//     for(int i = 1; i + st < plen; i++)
//     {
//         int j = lps[i - 1];
//         while(j && p[i + st] != p[j + st]) j = lps[j - 1];
//         if(p[i + st] == p[j + st]) ++j;
//         lps[i] = j;
//     }
// }
// int kmp(string s, int st)
// {
//     int res = 0, slen = s.size();
//     for(int i = 0, j = 0; i < slen; i++)
//     {
//         while(j && s[i] != p[j + st]) j = lps[j - 1];
//         if(s[i] == p[j + st]) ++j;
//         res = max(res, j);
//     }
//     return res;
// }
// int Solve(int st)
// {
//     int len = M;
//     getlps(st);
//     for(int i = 0; i < n; i++) len = min(len, kmp(s[i], st));//ģ����׺�������ִ��������ƥ�䳤�ȵ���Сֵ�����ǹ����ƥ�䳤�ȡ�
//     return len;
// }
// bool cmp(int st_now, int st_last, int len)//�ֵ���Ƚ�
// {
//     for(int i = 0; i < len; i++)
//         if(p[i + st_now] != p[i + st_last])
//             return p[i + st_now] < p[i + st_last];
//     return 0;
// }

// int main()
// {
//     untie();
//     while(cin >> n)
//     {
//         if(!n) break;
//         cin >> p;//ģʽ��
//         n--;
//         plen = p.size();
//         int ind = 0, len = 0;//������Ӵ��� p ��λ�� ind ���䳤�� len
//         for(int i = 0; i < n; i++) cin >> s[i];
//         for(int i = 0; i < plen; i++)//ȡ p �ĺ�׺��ÿ����׺��ǰ׺lps����������ö�ٵ������Ӵ����
//         {
//             int res = Solve(i);
//             if(res > len || (res == len && cmp(i, ind, len)))//���������ֵ����Ⱥ�
//             {
//                 len = res, ind = i;
//                 // cout << "TEXT : " << len << " " << ind << '\n';
//             }
//         }
//         if(!len) 
//         {
//             cout << "IDENTITY LOST\n";
//             continue;
//         }
//         for(int i = ind; i < ind + len; i++) cout << p[i];
//         cout << '\n';
//     }
//     return 0;
// }



//8.����԰
//
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// #include <cstring>
// using namespace std;
// const int N = 1e6 + 10, mod = 1e9 + 7;

// int T, lps[N];
// int cnt[N];
// char s[N];

// void getlps(int len)
// {
//     cnt[1] = 1, lps[0] = 0;
//     for(int i = 1; i < len; i++)
//     {
//         int j = lps[i - 1];
//         while(j && s[i] != s[j]) j = lps[j - 1];
//         if(s[i] == s[j]) ++j;
//         lps[i] = j;
//         cnt[i + 1] = cnt[j] + 1;
//     }
// }

// int main()
// {
//     scanf("%d", &T);
//     while(T--)
//     {
//         scanf("%s", s);
//         int len = strlen(s);
//         long long res = 1;
//         getlps(len);
//         int j = 0;
//         for(int i = 1; i < len; i++)
//         {
//             // int j = lps[i - 1]; ��������д�� TLE
//             while(j && s[i] != s[j]) j = lps[j - 1];
//             if(s[i] == s[j]) ++j;
//             while(j > (i + 1) / 2) j = lps[j - 1];//ֻ��ȡ���ص��Ĵγ���
//             res = res * (cnt[j] + 1ll) % mod;
//         }
//         printf("%lld\n", res);
//     }
//     return 0;
// }








































































/*��ѧԭ��Ӧ��*/

//�����پ���(�������⳵����)
//d(i,j)=|x1-x2|+|y1-y2|
/*
Ӧ��1����ӡ���Ĺ���ͼ��
//���ӡһ������
// ��n=5ʱ����" * ���ŵĵط��Ǿ������ĵ������پ���С��2�ĵط���
// ��n=7ʱ���С� * " �ŵĵط��Ǿ������ĵ������پ���С��3�ĵط���
// �ҵ����ĵ���n�Ĺ�ϵ�����ĵ���n��ʾΪ��n/2��n/2�����������ĵ����С��n/2�ĵ���" * "��ʾ�������ط��ÿո��ʾ��
// ���һ�У�һ��ָi��һ��ѭ��������л��С�
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;//nΪ����
    int cx = n/2, cy = n/2;//���ĵ�(cx,cy)
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

Ӧ��2�������ļ�֦���Ż�
����ͼ�����ߵĹ����У��޶�������ʱ�� limit
��֪���s(sx, sy) �� �յ�e(ex, ey)
�������پ��� mdis = |sx - ex| + |sy - ey|;
����ǰ��
    ��� limit < mdis �� mdis % 2 != limit % 2 �����ͼ�޽�
    �����ԣ������پ��� �� ��̲���(�����ٲ���) ��ż�Ա�Ȼ��ͬ��
�����У�
    ����������ǰ��(x, y)�����Ѿ���������ʱ�� step���Կ����õ�ǰ�����յ�������پ����֦
    ��� step + |x - ex| + |y - ey| > limit ���·���޽�
*/


























/*���ű�ѵ��*/
//1.��������Σ���������� + �Ȳ�������� + ö�� + ���֣�
//�����м��б��(б�����µ�����)Ϊ��㣬����������ö��б�У��ݼ�Ѱ�ң��������к�
/*
ԭ������������������������
                    1
                  1   1
                1   2   1
              1   3   3   1
            1   4   6   4   1
          1   5  10   10  5   1
        1   6  15  20   15  6   1
���������жԳ��ԣ�Ҫ�ҵ�һ������ֻ����벿�ּ���
                    1
                  1   
                1   2   
              1   3   
            1   4   6   
          1   5  10   
        1   6  15  20   
      1   7   21 35
�۲�б�У�б�����£���ͬһб���ϵ������е��������ԣ���ȥ��0б�е� 1 1 ������ 1�⣬Ϊ�ϸ������
��k��б��(�� 2 ����һб�� Ϊ ��һ��)�ĵ�һ��Ԫ��Ϊ C(k, 2*k)��Ҳ�Ǹú��е����ֵ

���ڵ�16б�о����ҵ�1e9���ϵ�ֵ��б����������С������ ö��
���ұ�б���ҵ�һ��ֵ��������б����ͬһ��ֵ�����ҵ���λ��ҪС����ֵ 6����2б�бȵ�1б���ҵ�λ�ø�ǰ���� ����ö��

���ڵ��������ǿ��� ���� ���������ֵ��
*/
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <cmath>
// #include <cctype>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll long long
// const ll N = 1e9;
// ll n;
// ll cal(int x, int y)//��x�� ��y��
// {
//     ll res = 1;
//     for(ll i = x, j = 1; j <= y; --i, ++j)
//     {
//         res = res * i / j;
//         if(res > n) return res;//����
//     }
//     return res;
// }
// int main()
// {
//     untie();
//     cin >> n;
//     if(n == 1)
//     {
//         cout << "1";
//         return 0;
//     }
//     for(int k = 20; k; k--)//����ö��б�У������֪��ൽ k = 16
//     {
//         ll l = 0, r = N;
//         while(l < r)
//         {
//             ll mid = l + r >> 1;
//             if(cal(mid, k) < n) l = mid + 1;
//             else r = mid;
//         }
//         if(cal(l, k) == n)
//         {
//             cout << (l + 1) * l / 2 + k + 1;
//             return 0;
//         }
//     }
//     return 0;
// }



//2.ʱ����ʾ(��ģ��)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <cmath>
// #include <cctype>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll long long
// const ll N = 1e9;
// ll n;

// int main()
// {
//     scanf("%lld", &n);
//     n /= 1000;
//     ll h = n / 3600;
//     h %= 24;
//     n %= 3600;
//     ll m = n / 60;
//     n %= 60;
//     printf("0%lld:" + (h > 9), h);
//     printf("0%lld:" + (m > 9), m);
//     printf("0%lld" + (n > 9), n);
//     return 0;
// }



//3.˫������
//��ûд��
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <cmath>
// #include <cctype>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll int
// const ll N = 1e5 + 5;
// struct nd{
//     ll x, y;
//     nd(ll a = 0, ll b = 0) {x = a, y = b;}
// }arr[N];
// ll n, m;
// ll ans[N];
// ll top = 0;
// int main()
// {
//     scanf("%d%d", &n, &m);
//     ll k = n;
//     for(int i = 0; i < m; i++)
//     {
//         ll x, y;
//         cin >> x >> y;



//     }


//     return 0;
// }



//4.��������
//��ûд��




//*5.������� (����dp)
//����dp[i][j]Ϊ�������� i ����,�Ƿ������ j ֵ�ķ�������(���jֵ������ԭֵ �� ��ֵ �� ��ֵ)
//����ѡ��,ֻҪ����һ�ֿ���,˵��jֵ����
//��i����ѡ(������ѡҲ����� j) | ѡ��i������ǰ�������ͬ��(����) | ѡ��i������ǰ����������(���)
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <cmath>
// #include <cctype>
// #include <set>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll int
// const ll N = 1e2 + 5, M = 2e5 + 10;//max_sum = 1e5,������w[i]�ᳬ��1e5
// int w[N];
// bool dp[N][M];
// int main()
// {
//     int n, sum = 0, ans = 0;
//     cin >> n;
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> w[i];    
//         sum += w[i];
//     }
//     dp[0][0] = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = 0; j <= sum; j++)
//         {
//             dp[i][j] = dp[i - 1][j] || dp[i - 1][j + w[i]] || dp[i - 1][abs(j - w[i])];
//         }
//     }
//     for(int i = 1; i <= sum; i++)//�Ϸ�������,������ 0
//         ans += dp[n][i];
//     cout << ans << '\n';
//     return 0;
// }



//6.��������
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <cmath>
// #include <cctype>
// #include <set>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll int
// string str;
// int num;
// int months[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
// bool check1(int date)//�ж����ںϷ�
// {
//     int yy = date / 10000, mm = date / 100 % 100, dd = date % 100;
//     months[2] = 28;
//     if(mm >= 1 && mm <= 12 && dd > 0)
//     {
//         if((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0)) months[2] = 29;
//         return dd <= months[mm];
//     }
//     return 0;
// }
// bool check2(string s)//�ж�ABABBABA��
// {
//     return s[1] != s[2] && s[1] == s[3] && s[3] == s[6] && s[6] == s[8] && s[2] == s[4] && s[4] == s[5] && s[5] == s[7];
// }
// int main()
// {
//     untie();
//     cin >> str;
//     num = stoi(str.substr(0, 4).c_str()) + 1;
//     bool ok = 1;
//     while(num < 10000)
//     {
//         int yy = num, mm = num % 10 * 10 + num / 10 % 10, dd = num / 1000 + num / 100 % 10 * 10;
//         int now = yy * 10000 + mm * 100 + dd;//num * 10000 + (num / 1000) + (num / 100 % 10 * 10) + (num / 10 % 10 * 100) + num % 10 * 1000
//         string t = ' ' + to_string(now);
//         if(check1(now))
//         {
//             if(ok) printf("%d%02d%02d\n", yy, mm, dd), ok = 0;
//             if(check2(t)) 
//             {
//                 printf("%d%02d%02d\n", yy, mm, dd);
//                 break;
//             }
//         }
//         ++num;
//     }
//     return 0;
// }



//7.�ɼ�����
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int n, minx = 1e9, maxx = 0;
//     double sum = 0;
//     scanf("%d", &n);
//     for(int i = 0; i < n; i++)
//     {
//         int x;
//         scanf("%d", &x);
//         minx = min(minx, x);
//         maxx = max(maxx, x);
//         sum += x;
//     }
//     sum /= (1.0 * n);
//     sum = (int)(sum * 100 + 0.5) / 100.0;
//     printf("%d\n%d\n%.2lf", maxx, minx, sum);
//     return 0;
// }



//8.ƽ���з�(ƽ�漸��֪ʶ)
//������Ľ������ num��ÿ���߹��� num + 1 ������
// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;
// #define pt pair<double, double>
// #define kk first
// #define bb second
// const int N = 1e3 + 10;
// int n, ans = 1;//��ʼΪ 1 ��ƽ��
// set<pt> lines;
// vector<pt> line;
// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         pt x;
//         cin >> x.kk >> x.bb;
//         lines.insert(x);//ȥ��
//     }
//     for(auto li : lines) line.push_back(li);//ȥ�غ�Ż�����
//     for(int i = 0; i < line.size(); i++)
//     {
//         set<pt> crs;//����
//         for(int j = 0; j < i; j++)
//         {
//             double k1 = line[i].kk, k2 = line[j].kk, b1 = line[i].bb, b2 = line[j].bb;
//             if(k1 == k2) continue;//ƽ��
//             //�㽻��
//             double x = -(b1 - b2) / (k1 - k2), y = k1 * x + b1;
//             crs.insert(pt(x, y));
//         }
//         ans += crs.size() + 1;
//     }
//     cout << ans;
//     return 0;
// }



//9. X ���Ƽ���
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define ll long long
// const int N = 1e5 + 10, mod = 1e9 + 7;
// ll a[N], b[N], c[N], numa = 0, numb = 0;
// int main()
// {
//     int n;
//     int ma, mb;
//     cin >> n >> ma;
//     for(int i = ma; i > 0; i--) cin >> a[i];
//     cin >> mb;
//     for(int i = mb; i > 0; i--) cin >> b[i];
//     c[0] = 1;
//     for(int i = 1; i <= max(ma, mb); i++)
//     {
//         ll x = max(a[i], b[i]);
//         c[i] = (x ? (x + 1) : 2);
//         c[i] = c[i] * c[i - 1] % mod;
//     }
//     for(int i = 1; i <= ma; i++) numa = (numa + a[i] * c[i - 1] % mod) % mod;
//     for(int i = 1; i <= mb; i++) numb = (numb + b[i] * c[i - 1] % mod) % mod;
//     cout << ((numa - numb) % mod + mod) % mod << '\n';//A-B�������Ϊ��������Ϊȡģ��ܿ����� B > A
//     return 0;
// }



//10. ˢ��ͳ��
// #include <iostream>
// using namespace std;
// #define ll long long
// ll a, b, n;
// ll cnt = 0;
// int main()
// {
//     cin >> a >> b >> n;
//     cnt += n / (5LL * a + 2LL * b) * 7LL;
//     n %= 5LL * a + 2LL * b;
//     for(int i = 1; n > 0 && i <= 7; i++)// д i < 7 �� WA
//     {
//         if(i <= 5) n -= a;
//         else n -= b;
//         cnt++;
//     }
//     cout << cnt; 
//     return 0;
// }



//11.�޼���ľ
// #include <iostream>
// using namespace std;
// int n;
// int main()
// {
//     cin >> n;
//     for(int i = 1; i <= n / 2; ++i) cout << ((n - i) << 1) << '\n';   
//     for(int i = n / 2; i < n; ++i) cout << (i << 1) << '\n';   
//     return 0;
// }



//*12.ͳ���Ӿ��󣨶�άǰ׺�� + ˫ָ�뽵ά��
//ά������ǰ׺�ͣ�ö�����½磬��ȡ���ҽ磨ö���ҽ磬������磩�������Ϳ�ѡ��һ�����η�Χ
// #include <cstdio>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 510;
// int n, m, k, a[N][N];
// int main()
// {
//     untie();
//     long long ans = 0;
//     cin >> n >> m >> k;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= m; j++)
//             cin >> a[i][j], a[i][j] += a[i - 1][j];//����ǰ׺��
//     for(int i = 1; i <= n; i++)//ö���Ͻ�
//     {
//         for(int j = i; j <= n; j++)//ö���½�
//         {
//             int sum = 0;
//             for(int r = 1, l = 1; r <= m; ++r)//ö���ҽ磬�������
//             {
//                 sum += a[j][r] - a[i - 1][r];//���ϵ� r �У����½�Ϊ[i, j] ��ֵ
//                 while(sum > k)
//                 {
//                     sum -= a[j][l] - a[i - 1][l];//���� k����������磬ȥ���� l �У����½�Ϊ[i, j]����ֵ
//                     ++l;
//                 }
//                 ans += r - l + 1;//�����½緶Χ�ڣ����ڸ����ҽ緶Χ�ڣ������������Ӿ�����
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }



//13.��ľ�������� dp��
//ÿһ�з�����������1 ����������2 ���ϸ�3 ���¸�
//1��ת������״̬
//2��ת������״̬
//3��ת������״̬
// #include <cstdio>
// using namespace std;
// #define ll long long
// const int N = 10000010, mod = 1000000007;
// ll dp[N][3];
// int n;
// int main()
// {
//     scanf("%d", &n);
//     dp[0][0] = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % mod + (dp[i - 1][2] + (i >= 2 ? dp[i - 2][0] : 0)) % mod) % mod;
//         dp[i][1] = (dp[i - 1][2] + (i >= 2 ? dp[i - 2][0] : 0)) % mod;
//         dp[i][2] = (dp[i - 1][1] + (i >= 2 ? dp[i - 2][0] : 0)) % mod;
//     }
//     printf("%lld", dp[n][0] % mod);
//     return 0;
// }



//14.ɨ�ף�map + dfs��
//r <= 10������ö��ÿ�����׻���ı�ը��Χ�ϵ�ÿ������㣬���� dfs ö��ÿ�� �����׻�� ���� ����ը�� ������ը�� �ı�ը��Χ�����ݱ�ը
// #include <cstdio>
// #include <cmath>
// #include <algorithm>
// #include <iostream>
// #include <map>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define p pair<int, int>
// const int N = 5e4 + 10;
// int n, m, ans = 0;
// map<p, p > mp;//mp[������] = (�뾶����������
// void dfs(int x, int y, int r)//�Է��ֵ�ÿ��ը����Ҫ��������������ԣ�
// {
//     //ö�����׻��Բ�����򣬷���ը���ͼ�����ɾȥը����
//     for(int dx = -r; dx <= r; ++dx)//ö���� (x, y) �ľ���
//     {
//         for(int dy = -r; x + dx >= 0 && dy <= r; ++dy)//ע��߽��ж� �� ��Բ�ľ���С�ڵ���ŷ����þ���
//         {
//             if(y + dy < 0 || dx * dx + dy * dy > r * r) continue;
//             p now = make_pair(x + dx, y + dy);
//             auto it = mp.find(now);
//             if(it != mp.end())//���õ����ը������ִ�в���
//             {
//                 p boom = it -> second;
//                 ans += boom.second;
//                 mp.erase(it);
//                 dfs(now.first, now.second, boom.first);//ը������ �� ��ը�뾶
//             }
//         }
//     }
// }
// int main()
// {
//     untie();
//     cin >> n >> m;
//     int x, y, r;   
//     for(int i = 0; i < n; i++)//����
//     {
//         cin >> x >> y >> r;
//         p now = make_pair(x, y);
//         if(!mp.count(now)) mp[now] = make_pair(r, 1);
//         else//��ͬ���ȡ���뾶�������Ӹ���
//         {
//             mp[now].first = max(mp[now].first, r);
//             ++mp[now].second;
//         }
//     }
//     //ö�����׻��
//     while(m--)
//     {
//         cin >> x >> y >> r;
//         dfs(x, y, r);
//     }
//     cout << ans;
//     return 0;
// }



//*15.��״�Ƽ�ǿ�棨dp��
//dp[i][j][k] ��ʾ�߹��� i ���ꡢj �� �� �� ʣ�� k ����
//����Ҫ���߹� m �仨���ʣ�� 0����ǡ������ m ���ƣ����� k <= m
//Ҫ�����һ���������ǻ� ��ǡ�ú���ƣ������Ѿ��߹��� n ���� �� m - 1 �仨 ��ʣ�� 1 ���ƣ��ʴ�Ϊ dp[n][m - 1][1]
//��֪���� *2 �� ���� -1����֪��ʣ���������ƣ��ϴα�ֻ�����������������ż������������������ϴ������� �� �ϴ�������
// #include <iostream>
// using namespace std;
// #define ll long long
// const int N = 110, mod = 1000000007;
// int n, m;
// ll dp[N][N][N];
// int main()
// {
//     cin >> n >> m;
//     dp[0][0][2] = 1;//��ʼ�� 2 ����
//     for(int i = 0; i <= n; ++i)
//         for(int j = 0; j <= m; ++j)
//             for(int k = 0; k <= m; ++k)
//             {
//                 if(k & 1) dp[i][j][k] += j ? dp[i][j - 1][k + 1] : 0;
//                 else dp[i][j][k] += (i ? dp[i - 1][j][k / 2] : 0) + (j ? dp[i][j - 1][k + 1] : 0);
//                 dp[i][j][k] %= mod;
//             }
//     cout << dp[n][m - 1][1] % mod;
//     return 0;
// }



//16.������
//��ĿҪ�����ݸ���������ʽ��һ�����������ӣ���ȫ�������߶�Ϊ 1 ��Ҫ�����ٴ�����
//��ô���ڵ��������ӣ����ҽ������ߵ������������غϵĲ��֣����ܺϲ����ִ�����
//��һ���ϸߵ�����A �� ���ڵ�һ���ϰ�������B������ A ����һ���Ĵ��������� B ��A �� B ���Թ��ô���������������ʱ�����ظ�������
//�ֿ����� set ��¼��һ�����ӵ��������̣���ÿ��������Ľ����ֵ������ô��������ǰ����ʱ��ÿ�ο�Ѱ���Ƿ����غϵ������������Բ���������
// #include <cstdio>
// #include <iostream>
// #include <cmath>
// #include <set>
// using namespace std;
// #define ll long long
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// const int N = 2e5 + 100;
// int n;
// ll ans = 0;
// set<ll> last;//��һ�����ӵ���������
// int main()
// {
//     untie();
//     cin >> n;
//     for(int i = 0; i < n; ++i)
//     {
//         ll x;
//         cin >> x;
//         set<ll> now;//��ǰ���ӱ������Ĺ��̣������Լ���
//         while(x > 1)
//         {
//             now.insert(x);
//             if(!last.count(x)) ++ans;//���ظ��ͼ���
//             x = sqrtl(x / 2 + 1);//ע�� h >= 1e18��Ҫ�� long long �Ͷ�Ӧ�� sqrtl() ����
//         }
//         last = now;//����״̬
//     }
//     cout << ans << '\n';
//     return 0;
// }







//17. ��Ƭ������⣩
//��ö�ٵ�ĳ���� n����ƴ�� n �����һλ��ʱǡ�����꿨Ƭ������� n����Ϊÿ�μ������Ǽ��� n �ϲ��Ϸ������������� n - 1���� n ���Ϸ���
// #include <iostream>
// using namespace std;
// int num[15];
// bool check()
// {
//     for(int i = 0; i < 10; ++i)
//         if(num[i] <= 0) return 1;
//     return 0;
// }
// int main()
// {
//     fill(num, num + 10, 2021);
//     int n = 1;
//     while(1)
//     {
//         int t = n;
//         while(t)
//         {
//             if(t > 9 && check())//�������һλ��
//             {
//                 cout << n - 1;
//                 return 0;
//             }
//             --num[t % 10];
//             t /= 10;
//         }
//         if(check())//�����һλ�� ƴ���˲������꣬˵���� n �Ϸ�
//         {
//             cout << n;
//             return 0;
//         }
//         ++n;
//     }
//     return 0;
// }




//18. ֱ�ߣ�����⣩
//��ÿ��ֱ�ߵ���Ϣ��б�� �� �ؾࣩ�����ؼ��ɣ�����Ϊ�˱��� double �����Ĳ�׼ȷ���أ����⽫ k �������� b �ϣ���ɶ������
//�� b ���ù�ʽ��ȡ(�� k �ش���ĳ��ֱ�߷����У��õ�û�� k ������ʽ�ӣ��������)
//b = (x1 * y2 - x2 * y1) / (x1 - x2)
// #include <iostream>
// #include <algorithm>
// #include <map>
// #include <set>
// using namespace std;
// #define pdd pair<double, double>
// int n = 20, m = 21;
// set<pdd> mp;
// int main()
// {
//     for(int i = 1; i <= n; ++i)
//     {
//         for(int j = 1; j <= m; ++j)
//         {
//             for(int x = i + 1; x <= n; ++x)
//             {
//                 for(int y = 1; y <= m; ++y)
//                 {
//                     if(y == j) continue;
//                     double k = 1.0 * (y - j) / (x - i);
//                     double b = 1.0 * (i * y - j * x) / (x - i);
//                     mp.insert(make_pair(k, b));
//                 }
//             }
//         }
//     }
//     cout << (n + m + (long long)mp.size());
//     return 0;
// }



//19. ����ڷ�
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// ll n;
// int main()
// {
//     cin >> n;
    
//     return 0;
// }









































// .�Ӵ���ֵ
//�˷�ԭ��������ӱ�ɶ���˷��ͣ�
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// const int N = 1e5 + 10, M = 140;
// #define ll long long
// string s;
// ll pre[N], nex[N];
// int id[M];
// int main()
// {
//     cin >> s;
//     int n = s.size();
//     s = ' ' + s;
//     for(int i = 1; i <= n; i++)
//     {

//     }
    
//     return 0;
// }
































//.�ִ�����
//������������������������������������������������������������������������������������������������������������������
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <cstdlib>
// #include <cctype>
// #include <cmath>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false); cout.tie(0);}
// #define ll int


// int main()
// {
//     untie();
//     int n;
//     cin >> n;
    
//     return 0;
// }





































/*�������������������������������������������������������������������������������������������������������������������������������������������㷨��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//������





//�ṹ�����������
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



//*��
/*
https://blog.csdn.net/qq_43762191/article/details/107280503?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166927609816800182199745%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166927609816800182199745&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-107280503-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_controx1&utm_term=%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91&spm=1018.2226.3001.4187
*/

//��ϣ�㷨
/*
����������������и������ִ����������Ը���Ϊ�±꣬����Ԫ��Ϊ��������¼�����ܻ���������С�������������ʱ��������й�ϣӳ�䴦��֮��Ҫ�������ӳ��õ�ԭ��
https://blog.csdn.net/qq_38609781/article/details/84836583?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166927649216782425154549%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166927649216782425154549&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-84836583-null-null.142^v66^control,201^v3^add_ask,213^v2^t3_controx1&utm_term=%E5%93%88%E5%B8%8C%E6%98%A0%E5%B0%84&spm=1018.2226.3001.4187
*/
















//С֪ʶ

/*~scanf(...)
//1. ������Ϊ�����ʾ
//2. ~ ��λȡ��
//3. scanf() ������ȷ��ȡ���ĸ�������ȡ���󷵻�-1
//4. -1�Ĳ���Ϊȫ1��ȡ�����ȫ0���˳�ѭ��
//5. ~scanf() == (scanf() != EOF)
//6.scanf�Ķ�ȡ�ٶ� Զ���� cin :
	��ͬ������һ������cin�ı���ʱ���Լ��scanf��3~4�������ԣ���ʹ�ô������ݵ�ʱ��cin�������ٶ�����Ҫ����scanf��
	������scanf �� cin ��ʱ��Ч���ϲ��ܴ��ԭ���ǣ�
	��scanfԪ�ص����������Ѿ���֪�ˣ�����������ȥ����Ԫ�����ͣ�scanf��Ҫ�Լ�д��ʽ����һ�ָ�ʽ�����롣
	����cin Ԫ�������ɻ����Լ����ң�cin���ַ������룬��Ҫ�ȴ��뻺���������롣
*/


/* ios::sync_with_stdio(false)
�ÿ��Խ�cin��scanf��Ч����ƥ�С�
Ĭ�ϵ�ʱ��cin��stdin���Ǳ���ͬ���ģ�Ҳ����˵�����ַ������Ի��ã������ص����ļ�ָ����ң�
ͬʱcout��stdoutҲһ�������߻��ò������˳����ҡ�
����Ϊ��������Ե����ԣ�����cin��������Ŀ�����ʹ�øþ���Խ���������ԣ�ȡ��cin��stdin��ͬ����
*/

/* cin.tie(0) �� cout.tie(0)
tie()
tie�ǽ�����stream�󶨵ĺ������ղ����Ļ����ص�ǰ�������ָ�롣
��Ĭ�ϵ������cin�󶨵���cout��ÿ��ִ�� << ��������ʱ��Ҫ����flush������������IO����������ͨ��tie(0)��0��ʾNULL�������cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
ACMӦ��
��ACM������������ݼ�������� cin TLE���������ʱ��󲿷�����Ϊ����cin��Ч�ʲ���scanf�Ĵ�������������C���Ժ�C++���Ե�ִ��Ч�ʲ�����������ۡ���ʵ��������˵����ֻ��C++Ϊ�˼��ݶ���ȡ�ı��ش�ʩ�����ǿ�����IO֮ǰ��stdio����󶨣���������֮��Ҫע�ⲻҪͬʱ����cout��printf֮�ࡣ
��Ĭ�ϵ������cin�󶨵���cout��ÿ��ִ�� << ��������ʱ��Ҫ����flush������������IO����������ͨ��tie(0)��0��ʾNULL�������cin��cout�İ󶨣���һ���ӿ�ִ��Ч�ʡ�
ԭ����cin��cout֮����Ч�ʵͣ�����Ϊ�Ȱ�Ҫ����Ķ������뻺�����������������Ч�ʽ��ͣ�����δ������������iostream������ ������棬���Խ�ʡ���ʱ�䣬ʹЧ����scanf��printf����޼�.
˵���ˣ���������ϾͿ������C++�����������ִ��Ч��ʹ�ú�C����޼�
*/

/*���ϣ�cin,coutʹ��ǰ��С���ɣ������ȡ��������¹�����ʱ������
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

��1��2����Ժϳ�Ϊ��
cin.tie(0)->sync_with_stdio(false);
*/

/*register int
���е� register ��ʾ�����ʹ�� cpu�ڲ��Ĵ��� �ı���
ƽʱ��int�ǰѱ��������ڴ��У�������浽�Ĵ����п��Լӿ�����Ķ�д�ٶ�
������
    ѭ��1e8�Σ�ʹ����ͨ��int��������ʱ 0.5032s
    ��ʹ��register int����ʱ 0.1375s
    ������Ϊ����
��;��
    ���ڽ϶�ι涨 i ��Χ��ѭ���У�������ڶ��ѭ����
*/





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*����������������������������������������������������������������������������������������������������������������������������������������������1��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://soj.csgrandeur.cn/csgoj/contest/problem?cid=1035&pid=D
������ӣ�https://soj.csgrandeur.cn/index/answer/detail?nid=1045
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



//B. ����ʲô����
//WA û�취�����ж��s0�����
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
//AC ֱ�ӱ������ң���s0������������븴��
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



//C. ������ת����Ϊһƥ�������⵵��
// ��Ϊֻ�������·��ƶ������跽��2x?+?y?=?dis1,?x?+?2y?=?dis2���ϲ����̿ɵ� 3(x + y) = dis1 + dis2 = ����������پ���(ʵ����·��)��
// ʵ����������ÿ���ж������� 3 ������(·���Ͽ�)����������پ������������������Բ���%3==0˵�������ߵõ��ģ�
// ����ֻҪ�յ������֮�������پ�����Ա�3�������Ϳ��Դﵽ��
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
//         Mdis = (x+y-1-1);//(x,y)���(1,1)�������پ���
//         if(Mdis%3==0 && x>Mdis/3 && y>Mdis/3)//�ұ�������������ֻ���������·��������پ���
//             res++;
//     }
//     cout<<res<<endl;
//     return 0;
// }



//D. ��У֮���������
//dp״̬��dp[n][m][2]�����ĺ�������ǰi���ڣ�����j�����ͣ�0/1��ʾ��i���Ƿ�������͡�
//�ڵ�i���ʱ�������һ����ˣ�����Ͳ��ܳԣ������һ��û�гԣ�����Ϳ��Գԡ�(��һ�����ֻ�ܳ�һ��)
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int a[2005],f[2005][1005][2],n,m,res=0;
// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>a[i];//�ȴ����Ҹ���
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=m;j++)
//         {
//             f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]);//��ʾ��i�첻�ԣ����ۼ�֮ǰ�Գ������Ҹ��ȣ������첻�Ժ��ܹ����Ҹ���
//             f[i][j][1] = f[i-1][j-1][0] + a[i];//��ʾ��i��ԣ��ۼ�����������֮����Ҹ��� ���� ����������Ҹ��ȣ���������˺��ܹ����Ҹ���
//         }
//     cout<<max(f[n][m][0], f[n][m][1])<<endl;//ȡ������Ϊ�����Ľ���������
//     return 0;
// }



//E. �������ս
//�ṹ����������
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
//     //��������ʹ�� 43ms -> 25ms����������Ŀ�������ָ�����
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



//F. ɾ����·
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



/*����������������������������������������������������������������������������������������������������������������������������������������������1��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*����������������������������������������������������������������������������������������������������������������������������������������������2��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://soj.csgrandeur.cn/csgoj/contest/problem?cid=1036&pid=A
������ӣ�
*/

//A.  ȱʧ������
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



//B. ������
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



//C. ȡ��
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



//F. ��ľ��(�������±�泤�ȣ��������������Խ������ǰ��Խ�̣���һ����ѡ��4����ã����ܾ�����ѡ)
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



//G. ��ſ��˼ά����Ҫ��
// ����һ���ᣬ������һ���㣬�������4���㣬�ұ���2���㣬�Ѹõ������ƶ�һ��㣬��Ҫ�ƶ�̫�࣬����������������㡣
//�����ƶ���d��λ���룬��õ㵽���4����ľ��������d���õ㶼�ұ�2����ľ��������d,���ܵ���˵������֮�ͼ�����2d��
//����������ĵ���˵������һ��ĵ������һ�࣬��ô�����м�������ʱ��һ��ͽ���˺ܶ���롣
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



//H. ���Ϻ���
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



/*����������������������������������������������������������������������������������������������������������������������������������������������2��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*������������������������������������������������������������������������������������������������������������������������������������������ӭ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://soj.csgrandeur.cn/csgoj/problemset/problem?pid=1449
������ӣ�https://soj.csgrandeur.cn/index/answer/detail?nid=1046
*/
//A. ������
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



//B. ��ʯð��
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
//         b[i] = y - x;//������0����ζ����y��ʯ��׬
//         sum += x;
//     }
//     sort(b, b + n, greater<ll>() );
//     for(int i = 0; i < k; i++)
//         sum += b[i];
//     printf("%lld", sum);
//     return 0;
// }



//C. ������2048��(˫ָ��-��������)
// #include <iostream>
// using namespace std;
// int arr[110][110];
// int n;
// void up()
// {
//     //�ӵ�һ��(u=1)�͵ڶ���(d=2)��ʼ�������Ժϲ��ͺϲ����Һϲ����u++���ϲ�����ʱ++u������tֵ������dҲ�����ҷ����
//     //������������� 0 4 2 2 0 ��������ĸ�����
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
����Ϊx�ᣬ����Ϊy��
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



//������D. ������Ϸ 
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
//�ҹ��ɹ�ϵ
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
//���ڸı��ƴ�С�Ĳ��������Ժ���b[1]����
//ֻѡi = 2 ~ n�Ĳ������ۣ���˳�Ź��ɵõ����



//E. Joshua������꣡
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



//F. ���˵�����ϵͳ
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



//G. ����ա�һ�£����֪��
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



//H. �Ҳ��빤��!
//������Ϊ 36 ��������ݸ�ֽ����������ֹ���
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



//I. zwc��ô�죿
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



//J. СAϲ�����ǹ�
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



//K. �����
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// const int MAXN = 2e5 + 10;
// ll a[MAXN];
// int n, m;
// bool check(ll x)
// {
//     //����ѡ�������ֻ������� m ������˵��������ĳ�����ڿ��У��������и�����(>=x)������ȥ l �������䣬������ȥ r ��������
//     ll cnt = 0, sum = 0;
//     if(!x) return 1;//0������
//     for(int i = 0; i < n; ++i)
//     {
//         if(a[i] >= x) cnt++;//��ˣ�ÿ�����϶�����ѡ����һ�ֻ�
//         else sum += a[i];
//     }
//     cnt += sum / x;//�����ܺͷָ�������������ÿ�������ֵܷ��Ļ�����������cnt��Ϊһ�����Ļ�������
//     return cnt >= m;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for(int i = 0; i < n; i++)  scanf("%lld", &a[i]);
//     ll l = 0, r = 0x7fffffffffffffff, ans = 0;
//     while(l <= r)
//     {
//         ll mid = l + (r - l) / 2;//���������ֲ���
//         if(check(mid)) l = mid + 1, ans = mid;//���մ���mid
//         else r = mid - 1;
//     }
//     printf("%lld", ans);
//     return 0;
// }
//����,��� >= m ����һ��
// 3 3
// 3 2 1 
// 1
//1 1 1
//1 1
//1
//����һ��Ϊ���֣���1��

// 5 4
// 4 3 2 2 1
//1 1 1 1
//1 1 1
//1 1
//1 1
//1
//��һ���������㣬2��

//2 2
//3 3
//1 1 1
//1 1 1
//���о����㣬3��



//L. Ҫ�ǲ��ѣ�Ҳͦ�򵥵�
//TLE (����������˫��ѭ������ʱ�临�Ӷ�����ΪO(n*n),���ʱΪ2000*2000*9=36e6,��ʵ�ʲ�������25e6,�ʳ�ʱ)
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

//��Ҫʹ�� ��̬�滮








/*������������������������������������������������������������������������������������������������������������������������������������������ӭ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*�������������������������������������������������������������������������������������������������������������������������������ڶ��������ƾ�������������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://soj.csgrandeur.cn/csgoj/problemset#search=%E6%B7%B1%E5%9C%B3%E6%8A%80%E6%9C%AF%E5%A4%A7%E5%AD%A6%E7%AC%AC%E4%BA%8C%E5%B1%8A%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1%E7%AB%9E%E8%B5%9B

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



//2.��������
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



//3.������
//δ���
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



//4.����о�
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



//5.ͽ�ֲ���׵�ǰ��
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



//6.�ǿ�ָ�ӹٵ�����
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

//     //�����������취�Ż��������Կռ任ʱ��

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



//��Ʒ����
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
























/*�������������������������������������������������������������������������������������������������������������������������������ڶ��������ƾ���������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*������������������������������������������������������������������������������������������������������������������������������SZTU Monthly 2020 Oct����������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://soj.csgrandeur.cn/csgoj/problemset#search=SZTU%20Monthly%202020%20Oct.
������ӣ�https://soj.csgrandeur.cn/index/answer/detail?nid=1003
*/
//1.����
// #include <cstdio>
// int main()
// {
//     int N; scanf("%d",&N);
//     printf((N%4==0&&N%100!=0)||N%400==0 ? "%d is a leap year." : "%d is not a leap year.", N);
//     return 0;
// }



//2.zjbѧ����Ҫ�棡
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



//3.�����
//̰�� ������1������1����7
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
//���д��������ࣩ
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


//4.�أ��ʣ���
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
//���
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



//5.��֮���ǲ�̫�ɰ�
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



//6.ǮǮ��steam��Ϸ
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
����struct���� ?
struct node
{
    ll val;
    int id;
    node(){}
    node(ll _val, int _id){val = _val; id = _id;}
}num[maxn];
*/



//7.ʳ�õ���
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



//8.�ԻԷ��˿���
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
//11011010100 ���۴���ʼ�����Ǵ��ҿ�ʼ������8��
//��⣺��ʵֻ�ÿ���ǰ״̬�Ƿ��֮ǰ��ͬ�ͺ���
// #include<iostream>
// #include<cstring>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     int m = s.size(), k = m - 1;//s.size�����ַ���s�ĳ���
//     for(int i = 1;i < m; ++i)
//         if(s[i] == s[i - 1]) k--;
//     if(s[m - 1] == '0') k++; //�ж����һλ
//     cout << k;
//     return 0;
// }



//9.��ʥ�ڴ���ս
//�����׼Ϊ �ܼ�ֵ���� �ȱ�ѡ���������е����Ų���
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



//10.�ڶ�����Ѱ�������Ƿ�����ʲô
//947ms���չ������Ż��㷨
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
//���: λ����
//����ȫ�������ϣ�����ÿ���ӽڵ���˵�������ų��� 2 �Ϳ��Եõ��丸�ڵ�ı��
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



//11.��������
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
//         if(!arr[i]) continue;//����0
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
//0 < x <= a ��
//�����������������k��С��
//x == 0
//x > a



//*12.�ҵ��ഺ��ɽ�����Ȼ������(����ջ)
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
//AC �ݼ�ջ
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















/*������������������������������������������������������������������������������������������������������������������������������SZTU Monthly 2020 Oct������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*���������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��1����������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://vjudge.net/contest/534933

*/


//Count Distinct Integers 
// unique��������ɾ�����������е��ظ�Ԫ�ء�
// ע�⣺
//  �����ɾ���������delete�����ǽ��ظ���Ԫ�طŵ�����ĩβ
//  unique�����ķ���ֵ��ȥ��֮���β��ַ
//  һ��Ҫ�ȶ������������ſ���ʹ��unique����
// д����˳������³��� int len = unique(arr, arr+10) - arr;
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
//ԭ����д��
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
//ͦ���ģ������������辫��
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



//��1 Operation 2 (���� + ǰ׺��)
//����
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
//����
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
//     //���������N�Ķ�������15��1���� 2^60 - 1
//     //�� i ö�ٳ����� N �Ķ������Ӽ�
//     for(ll i = (1ll << 60) - 1; i >= 0; i--)//0 Ҳ�Ǵ�
//     {
//         i &= N;//ȡ�Ӽ�
//         ans.push_back(i);
//     }
//     reverse(ans.begin(), ans.end());//����������ö�ٴ�����Ӽ�����ת�����
//     for(auto x : ans) cout << x << '\n';
//     return 0;
// }
/*
���˼·��
�� & ȡ T �� U �Ľ�����
T = {A,B,C}: 0111
U = {B,D}:   1010
T �� U = {B}: 0111 & 1010 = 0010 
ö�����а����� T �� U
�� N = 11 �������Ʊ�ʾΪ 1011
imax = 0111 1111 1111 1111
��Ȼ��ʱ i �� N ������Ϊ N (i �� N = N) 
���� i ��ͬʱ(i--)���ظ�����ȡ�Ӽ�����
���    i    i & N  
1     imax   1011  �����裺�������½���i--��ȡ�Ӽ������Ӽ���
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
//��ѧ���Ľⷨ :)
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
//         sort(s.begin(), s.end());//���ַ�������ͳһ���ֵ����������ֵ�������������жϼ���
//         if(s == "Timru") cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }











/*���������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��1������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////











/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*���������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��2����������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://vjudge.csgrandeur.cn/contest/535123

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
//���ⷽ������
//1. (map || set) && vector
//2. (map || set) && list
//3. (map || set) && string (Ҫһ�������ſո�)
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



//����ը�� 
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
//         arr[a+1][b+1] += val;//��(1,1)��ʼ
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




/*���������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��2������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*���������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��3����������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://vjudge.csgrandeur.cn/contest/535422

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



//���ĳɼ�
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



//EKO / ���� 
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






/*���������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��3������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*�������������������������������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��4����������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://vjudge.csgrandeur.cn/contest/535668

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



//* �����· 
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
// //��Ӹ�����С�ӿ϶��������ӵ�ʱ�����꣬�����������
// //0 4 3 2 5 3 5 0 ������� 0 ������⣩
// //��С����Ϊ��һ���ӣ��� 4��(����)
// //4 �����С�ӻ�������ʱ˳�����꣬
// //�� 5 Ҳ�����ǰ���С��һ���5 - 2 = 3��
// //���� 5 ������ֻ��Ҫ�� 3 ��Ϳ�����
// //5 ����� 3 ��ȻҲ��˳�㱻��
// //3 ����� 5 Ҳ����� 3 ����ƽ������������ֻ��Ҫ�� 5 - 3 = 2 ���������һ����� 5
// //�ܺ�Ϊ 4 + 3 + 2 = 9 ��
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



//*Ladder Takahashi ��ͼ�ۻ�����
//Ҫѧϰͼ�ۣ���ѧ�ڽӾ���ͼ�����������
//��ͼ(�ص�) �� ����
// #include <iostream>
// #include <map>
// #include <vector>
// #include <queue>
// #include <set>
// using namespace std;
// int n, a, b;
// map<int, vector<int> > gra;//��һ�Զ࣬����������·��
// set<int> ans;
// //1.���ü��ϲ��ظ��ԣ���ֹ�������ԭ·���� �� ·���ظ�
// //2.���������ԣ��洢��·���ܵ���ĸ߶ȣ����ȡ����β��������߼���
// void bfs()
// {
//     queue<int> q;
//     q.push(1);
//     while(q.size())
//     {
//         int ori = q.front(); q.pop();//ȡһ�����
//         for(int next : gra[ori])//��������������·��
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
//         gra[b].push_back(a);//������˫����е�
//     }
//     ans.insert(1);//�����ܵ��� 1
//     bfs();
//     cout << *ans.rbegin();//��������
//     return 0;
// }



//Stripes 
//BFS�ⷨ�����鷳
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
//��˫�����
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
//���򵥵ģ�ֻ��Ҫ�ж� R ��û�г������ɣ�R ����˵�� B �������� R ������˵�� B ����
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




























/*�����������������������������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��4������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*�������������������������������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��5����������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/*
��Ŀ���ӣ�https://vjudge.csgrandeur.cn/contest/536144

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
//             if(find_set(i) == i) res++;//����Ϊ���ʾδ��ϵ���Ҽ�ȥ���е�һ������
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
































/*�����������������������������������������������������������������������������������������������������������������������������������������������������ڼ�ѵ��5������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*�����������������������������������������������������������������������������������������������������������������������������������������������������׶���1����������������������������������������������������������������������������������������������������������������������������������������������������������������������*/


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
//�����д��:
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
// map<int, set<int> > gra;//ÿ���˱�� ��Ӧ����������ܹ�ϵ�ļ���
// int main()
// {
//     untie();
//     int n, x, a, b;
//     cin >> n;
//     while(n--)
//     {
//         cin >> a >> b;
//         gra[a].insert(b);//˫���
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
//δ���
//����dp��
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
//���鼯д����
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
//��bfs
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
//     memset(b, 0x3F, sizeof b);//memset��һ���ֽ�һ���ֽڵ���䣬����4���ֽڵ�ÿ��Ԫ�ػ���0x3F3F3F3F = 1061109567;
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
//��ô sum(ceil(n / i)) == sum(floor((n - 1) / i) + 1) == sum(floor((n - 1) / i)) + n
//���� sum(floor(n / i)) ͬ������ sum(floor((n - 1) / i))
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
//�����
// #include <iostream>
// #include <vector>
// using namespace std;
// #define untie() {cin.tie(0)->sync_with_stdio(false), cout.tie(0);}
// const int N = 1e5 + 10;
// typedef pair<int, int> p;//<��ɫc, ����k>
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
//�߶���
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
//Dijistraģ��
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






















/*���������������������������������������������������������������������������������������������������������������������������������������������������׶���1������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*��������������������������������������������������������������������������������������������������������������������������������ʮ�߽��й�������ѧ������ƾ�������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/


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
//         vector<int> v1, v2{0};//��0 �� ��0
//         for(int i = 0; i < a.size(); i++)
//         {
//             if(cnta & 1)//��ת
//             {
//                 if(a[i] == '1') a[i] = '0';
//                 else a[i] = '1';
//             }
//             if(a[i] == b[i]) continue;
//             v1.push_back(i + 1);
//             cnta++;
//         }
//         //�̶� a = "00000������"
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
//         if(v2.size() <= v1.size())//v2����
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
//         ll now = 0, res = n;//������Ҫn��
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
//         //���һ�������
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
//     //ǰ4λ��ݴ洢 + �жϻ���
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
//     //���ж���
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

// int ls(int p) { return p << 1;}//����
// int rs(int p) { return p << 1 | 1;}//����

// void pushup(int p)//���ֵ����
// {
//     int pl = ls(p), pr = rs(p);
//     tree[p] = max(tree[pl] * vis[pl], tree[pr] * vis[pr]);//�����ڼ�Ϊ 0
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

// void update(int L, int R, int p, int pl, int pr)//ȥ��������Ԫ�أ�״̬��Ϊ�����ڼ��ɣ�
// {
//     if(L <= pl && pr <= R)
//     {
//         vis[p] = 0;
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     //�ڵ���ھ��������
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
//             //����ʣ��ȫ���������ֵ
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

//��ż���ε������һ�����ӣ�





/*��������������������������������������������������������������������������������������������������������������������������������ʮ�߽��й�������ѧ������ƾ���������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*������������������������������������������������������������������������������������������������������������������������������2021��GDCPC�㶫ʡ��ѧ��������ƾ�������ʽ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/


//��Ŀ��https://ac.nowcoder.com/acm/contest/50921?&headNav=www#question
//����Ƽ���https://blog.csdn.net/qq_57404161/article/details/125115217?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-125115217-blog-124462818.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-125115217-blog-124462818.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=7


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
// //n������,�ɴ�С����,����������ֵ������ k-1 �����ֵ��ÿ�ε��������������ǰһ��ֵ
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


//G (˼ά�⣬����)
//������
//Alice ����ѡ��һ������������ֳ���������������ɾ��һ������1������
//Bob ����ѡ��һ��ż��������ֳ�����������
//���˶��Ǿ���ʹ���Լ�ʣ����ಽ��
//Bob �ֽ�ż�������շֽ����Сż���� 2
//    ���ֽ���� 2��������� 1����Alice������Alice�ܶ�������
//    ���ֽ�� 2 ��ż������ 6������Ϊ 1 5 �� 3 3���൱���Ͷ��沽����ֻ��ż�ֳ�ż���� 2 4��Bob������
//Alice �ֽ���������С����Ϊ 1
//    ��ɾ�� 1������һ�غ�
//    ���ֽ�� 1 ���������� 5����Ϊ 1 4 �� 2 3 ����һ��һż����˫������һ��
//����Alice��������������� 2�������Լ����������
//����Bob�������������ֽ� 2
//1 �����ձ�Ȼ������������Ϸ���̱�ɣ�bob �������ֽ� 2��alice ���㹻��Ļغ�ֱ�� Bob û��ż���ɷ֡�
//��Bob�ֽ� x ʱϣ����������ż���� x-2 �� 2��Alice�ֽ� x ʱϣ������ѵ� 2 ������ʹ���ܼ����� 1 ȥ�ϣ�
//���˵����ž��߶��ǰ� x ��� x - 2 �� 2
//��ôͳ�������д��� 2 ��ż���ܱ��ֽ�Ĵ��������� bob �Ĳ���������ͳ�������е������ܱ��ֽ�Ĵ��������� alice �Ĳ������������Ƚϼ���

//δ���
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
// bool vis[N];//��¼�߹��Ĳ������ߣ��ȵ��ľ������ٲ���
// //�������ߣ������ߣ���ǰ��
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
//     for(int i = 0; i < cnt; i++)//��ȫ���������־��ߣ������������
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
//��ά�߶���
//ѧ������
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

// int ls(int p) { return p << 1;}//����
// int rs(int p) { return p << 1 | 1;}//����

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
//     //xΪ������ͳ���䳡����E(x)
//     //x = 4
//     //  1 2 3
//     //1 1 0 0
//     //2 1 1 0
//     //3 1 1 1
//     //4 1 ��ʤ
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







/*������������������������������������������������������������������������������������������������������������������������������2021��GDCPC�㶫ʡ��ѧ��������ƾ�������ʽ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






























/*
//ģ��
//���鼯��
#include <cstdio>
#include <iostream>
using namespace std;
const int N = ;
int ds[N];
void init_set(int n){ for(int i = 1; i <= n; ds[i] = i, i++);}
int find_set(int x){ return x == ds[x] ? x : (ds[x] = find_set(ds[x]));}
void merge_set(int x, int y){ if((x = find_set(x)) != (y = find_set(y))) ds[x] = ds[y];}



//��άǰ׺��
//�洢��ʽ��sum[i][j] =  sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j]
// ��ȡ��ʽ��res = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
#include <iostream>
using namespace std;
const int N = ;
int arr[N][N];
int sum[N][N];
int main()
{       
    int x1,x2,y1,y2;//����ķ�Χ
    //��ʼ������
    for(int i=1;i<=N-1;i++) 
        for(int j=1;j<=N-1;j++)
            arr[i][j]=i+j;
    //ǰ׺�Ͳ���(ʵ���Ͽ��Ա߶�ȡarr���������߽�����Ͳ���)
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



//��ά���
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
            insert(i, j, i, j, a[i][j]);      //�����������
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);          //��ֲ���
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];  //תΪ��άǰ׺��
    return 0;
}



//������
//base ������index ָ��
//�������������ݣ�
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
//��������ݣ�
#include <cstdio>
typedef long long ntype;
const ntype mod = , N = ;//���� N ָ�����α߳���n ָʵ�ʾ��α߳�
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





