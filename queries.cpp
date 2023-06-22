// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;

    head = newNode;
}

int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print_original(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_reverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void insert_any_position(Node *&head, Node *&tail, int position, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;

        return;
    }
    Node *temp = head;
    cout << temp->prev->val << endl;
    for (int i = 1; i <= position - 1; i++)
    {
        temp = temp->next;
    }

    // 10 20 100 30 40
    newNode->next = temp->next; // 100->30
    temp->next = newNode;       // 20->100

    newNode->next->prev = newNode; // 100<-30
    newNode->prev = temp;          // 20<-100
}
int main()
{

    int input;
    Node *head = NULL;
    Node *tail = NULL;

    cin >> input;

    // for (int i = 0; i < input; i++)
    // {
    //     int pos;
    //     int value;
    //     cin >> pos;
    //     cin >> value;

    //     if (pos == 0)
    //     {
    //         insert_head(head, tail, value);
    //     }
    //     else if (pos >= size(head))
    //     {
    //         cout << "Invalid" << endl;
    //     }
    //     else
    //     {
    //         insert_any_position(head, pos, value);
    //     }
    //     print_original(head);
    //     print_reverse(tail);
    // }

    for (int i = 1; i <= input; i++)
    {
        int pos;
        int value;
        cin >> pos;
        cin >> value;

        insert_any_position(head, tail, pos, value);
        print_original(head);
        // print_reverse(tail);
    }

    return 0;
}