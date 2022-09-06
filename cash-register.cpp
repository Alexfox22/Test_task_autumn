#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> product_info;
	unordered_map<int, string*> batch_code;
	unordered_map<string, string*> name;

	string current_string;
	ifstream file;
	file.open("\\data\products.csv");

	while (getline(file, current_string))
	{
		product_info.push_back(current_string);
	}
	for (int i = 0; i < product_info.size(); i++)
	{
		batch_code[stoi(product_info[i].substr(0, product_info[i].find(';')))] = &product_info[i];
		int dist = distance(product_info[i].cbegin(), find(next(find(product_info[i].cbegin(), product_info[i].cend(), ';')), product_info[i].cend(), ';')) - product_info[i].find(";") - 1;
		name[product_info[i].substr(product_info[i].find(';') + 1, dist)] = &product_info[i];
	}

	string type;
	cout << "1. Batch" << endl << "2. Name" << endl;
	cin >> type;
	switch (stoi(type))
	{
	case 1: {
		cin >> type;
		cout << *(batch_code[stoi(type)]); }
	case 2: {
		cin >> type;
		cout << type;
		cout << *(name[type]); }
	}

	return 0;
}