#include <iostream>
#include <thread>
//#include <chrono>
#include "OwnWayList.h"

using namespace std;


void go_thread(OwnWayList& que, bool safty)
{
    for (int i = 1; i < N + 1; ++i)
    {
        if (safty)
            que.insertIntoMiddle(i, i);
        else
            que.unsave_insertIntoMiddle(i, i);
    }
}

void test(bool safly)
{
    OwnWayList que;

    que.addFirstNode(-1); // �� ������� ������� ������� ������ �� ������

    thread t1(go_thread, ref(que), safly);
    thread t2(go_thread, ref(que), safly);


    t1.join();
    t2.join();


    que.printer(); // �����������

    // ��������, ��� ������ ����� �� 1 �� N ���������� 2 ����
    if (que.two_occurrences()) cout << "Good!" << endl;
    else cout << "Bad!" << endl;
}

int main()
{
    // ��������� ��������� � ������� ������������������� ������ �������
    test(false);

    // ��������� ��������� � ������� ����������������� ������ �������
    test(true);

    return 0;
}


