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

//һ�����
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

//�������
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


























































/*��ѧԭ��Ӧ��*/

//�����پ���(�������⳵����)
//d(i,j)=|x1-x2|+|y1-y2|
//��ӡһ������
/*
��n=5ʱ����" * ���ŵĵط��Ǿ������ĵ������پ���С��2�ĵط���
��n=7ʱ���С� * " �ŵĵط��Ǿ������ĵ������پ���С��3�ĵط���
�ҵ����ĵ���n�Ĺ�ϵ�����ĵ���n��ʾΪ��n/2��n/2�����������ĵ����С��n/2�ĵ���" * "��ʾ�������ط��ÿո��ʾ��
���һ�У�һ��ָi��һ��ѭ��������л��С�
*/
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;//nΪ����
//     int cx = n/2, cy = n/2;//���ĵ�(cx,cy)
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










