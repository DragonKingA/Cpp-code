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
    vector<int> v1, v2;                               // ����δ���壬����̬����
    vector<int> vlen(100, 0);                         // ����Ϊ100������Ԫ�س�ʼֵΪ0����ʱ����������
    vector<int> vlist{1, 2, 3, 4, 5};                 // �б��ʼ��
    vector<int> v_t(vlist);                           // ������ʼ����v_t��vlist��ͬ��Ҫ��������ͬ���ܿ���
    vector<int> v_t2(vlist.begin(), vlist.end());     // ���俽����ʼ�����ڹ涨�����ڿ������˾����ڵ�ͬ�Ͼ�
    vector<int> num[len1];                            // ��ά���飬һά����Ϊlen(�����԰���len��һά����)����ά���ȶ�̬�仯
    vector<vector<int> > numd(len1);                   // ͬ��
    vector<vector<int> > numd_(len1, vector(len2, 0)); // �Զ������������ͬ����ͨ��ά���飬����ÿ��Ԫ�ر���ʼ��Ϊ0

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


    // �� ��(v1.begin() + i)��Ԫ��ǰ ���� �ڶ���������ֵ
    for (int i = 0; i < 10; i++)
    {
        v1.insert(v1.begin() + i, i + 1);
    }


    for (int i = 0, j = 0; i < len1; i++)
    {
        while (j < len2 + i) // ��������
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


    //����
    vector<int> vlist1{20,30,1,3,4,1,9,21,20,399,50,12};
    sort(vlist1.begin(), vlist1.end());
    for(int &x : vlist1) cout << x << " ";
    cout << endl;
    //��ת����
    reverse(vlist1.begin(), vlist1.end());//����ѡ��������в��ַ�ת
    vlist1.pop_back();//����ĩβԪ�� 1
    for(int &x : vlist1) cout << x << " ";
    cout << endl;


//set , multiset
    //set ���ϣ����ظ�������
    set<int> s1;
    












    return 0;
}
