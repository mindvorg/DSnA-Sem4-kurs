// kurs sem 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"list.h"
#include<fstream>
#include"edge.h"
#include"parsing.h"
#include"FordFalkerson.h"
using namespace std;
int main()
{
    string fileName = "input.txt";
    List<Edge> list1;
    List<string> list2;
    parse(&list1, &list2,fileName);
    int countStr = countCities(&list2);
    int countEdg = list1.getSize();


    inizializeCity(&list1, &list2);

   auto result= fordFalkerson(&list1, &list2);
   cout << "max flow is " << result;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
