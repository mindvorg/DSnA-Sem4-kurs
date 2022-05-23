#pragma once
#ifndef Parsing_H
#include<iostream>
#include"List.h"
#include"Edge.h"
#include<fstream>

using namespace std;
void parse(List<Edge>* listEdg, List<string>* listStr, string filename)
{
	fstream file;
	file.open(filename, ios_base::in);
	if (file.bad())
	{
		cout << "some problems with input file";
	}
	else
	{
		string line;
		string subline;
		int position = 0;
		while (getline(file, line))
		{
			Edge edge1;
			Edge edge2;

			subline = line;
			position = line.find(' ');
			subline.resize(position);
			listStr->pushBack(subline);
			edge1.from = subline;
			edge2.to = subline;
			line.erase(0, position + 1);

			subline = line;
			position = line.find(' ');
			subline.resize(position);
			listStr->pushBack(subline);
			edge1.to = subline;
			edge2.from = subline;
			line.erase(0, position + 1);

			subline = line; 
			subline.resize(position);
			if (subline != "N/A")
			{
				edge1.costTo = stoi(subline);
				listEdg->pushBack(edge1);
			}

				edge2.costTo = -1;

		}


	}
	file.close();
}

int countCities(List<string>* list)
{
	if (list->getSize() != 0)
	{
		int size = list->getSize();
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if ((*list)[i] == (*list)[j])
				{
					list->remove(j);
					size--;
					j--;
				}
			}
		}
		return list->getSize();
	}
	else return -1;

}

void inizializeCity(List<Edge>* listEdg, List<string>* listStr)
{
	int sizeEdg = listEdg->getSize();
	int sizeStr = listStr->getSize();
	for (int i = 0; i < sizeEdg; i++)
	{
		for (int j = 0; j < sizeStr; j++)
		{
			if ((*listEdg)[i].from == (*listStr)[j])
				(*listEdg)[i].indexFrom = j;

			if ((*listEdg)[i].to == (*listStr)[j])
				(*listEdg)[i].indexTo = j;
		}

	}

}
#endif // !Parsing_H