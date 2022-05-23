#pragma once
#include <string>
#ifndef Edge_H
using namespace std;
class Edge
{
public:
	string from;
	string to;
	int costTo;
	int costBack=-1;
	int indexFrom = -1;
	int indexTo = -1;
	Edge(string from, string to, int cost1, int IndFrom, int IndTo)
	{
		this->from = from;
		this->to = to;
		this->costTo = cost1;
		this->indexFrom = IndFrom;
		this->indexTo = IndTo;
	}

	Edge()
	{
		this->from = "";
		this->to = "";
		this->costTo = 0;
		this->indexFrom = -1;
		this->indexTo = -1;
	}

};
#endif // !Edge_H
