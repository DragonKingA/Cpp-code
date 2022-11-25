#include <iostream>
#include <vector>
#include <array>
#include <set>

#include <algorithm>
using namespace std;

int main()
{   
//vector , array
    int len1 = 1, len2 = 1;
    // cin >> len1 >> len2;
    vector<int> v1, v2;                               // 长度未定义，即动态数组
    vector<int> vlen(100, 0);                         // 长度为100，所有元素初始值为0，此时与数组无异
    vector<int> vlist{1, 2, 3, 4, 5};                 // 列表初始化
    vector<int> v_t(vlist);                           // 拷贝初始化，v_t与vlist相同，要求类型相同才能拷贝
    vector<int> v_t2(vlist.begin(), vlist.end());     // 区间拷贝初始化，在规定区间内拷贝，此句现在等同上句
    vector<int> num[len1];                            // 二维数组，一维定长为len(即可以包含len个一维数组)，二维长度动态变化
    vector<vector<int> > numd(len1);                   // 同上
    vector<vector<int> > numd_(len1, vector(len2, 0)); // 自定义行列数后等同于普通二维数组，并且每个元素被初始化为0

    array<int, 100> a1, a2;
    v1.push_back(100);
    v2 = v1;
    cout << v2[0] << " " << endl;

    int k = 0;
    for (int &x : a1)
    {
        x = k++;
        cout << x << " ";
    }
    cout << endl;


    // 在 第(v1.begin() + i)个元素前 插入 第二个参数的值
    for (int i = 0; i < 10; i++)
    {
        v1.insert(v1.begin() + i, i + 1);
    }


    for (int i = 0, j = 0; i < len1; i++)
    {
        while (j < len2 + i) // 列数会变大
            num[i].push_back(i + (++j) + 1);
        j = 0;
    }
    for (int i = 0; i < len1; i++)
    {
        for (int &x : num[i])
            cout << x << " ";
        cout << "num[" << i << "] account of elements is " << num[i].size() << endl;
    }
    

    for (int i = 0, j = 0; i < len1; i++)
    {
        while (j < len2 + i)
            numd[i].push_back(i + (++j) + 1);
        j = 0;
    }
    for (int i = 0; i < len1; i++)
    {
        for (int &x : numd[i])
            cout << x << " ";
        cout << "numd[" << i << "] account of elements is " << numd[i].size() << endl;
    }
    cout << endl;


    //排序
    vector<int> vlist1{20,30,1,3,4,1,9,21,20,399,50,12};
    sort(vlist1.begin(), vlist1.end());
    for(int &x : vlist1) cout << x << " ";
    cout << endl;
    //翻转数组
    reverse(vlist1.begin(), vlist1.end());//可以选定区间进行部分翻转
    vlist1.pop_back();//舍弃末尾元素 1
    for(int &x : vlist1) cout << x << " ";
    cout << endl;


//set , multiset
    //set 集合，不重复且有序
    set<int> s1;
    












    return 0;
}
