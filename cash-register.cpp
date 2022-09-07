#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int get_batch(string& line)		//returns batch code from data
{
	return stoi(line.substr(0, line.find(';')));
}

string get_name(string& line)		//returns name from data
{
	int dist = line.find(';', line.find(';') + 1) - line.find(';') - 1;
	return line.substr(line.find(';') + 1, dist);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> product_info;
	unordered_map<int, string*> batch_indexed_map;		//map for batch code search;
	unordered_map<string, string*> name_indexed_map;		//map for name search;

	string current_string;
	ifstream file;
	file.open("\\data\\products.csv");
	if (!file.is_open())
		cerr << "\n\n\t\tFile not open!";
	else {
		
		while (getline(file, current_string))		//read data from file to vector
		{
			product_info.push_back(current_string);
		}

		for (auto& product : product_info)		//fill maps for search
		{
			batch_indexed_map[get_batch(product)] = &product;
			name_indexed_map[get_name(product)] = &product;
		}
	}
	//string type = "134123123";
	//cout << *(batch_indexed_map[stoi(type)]);		//find by batch code
	//cout << *(name_indexed_map[type]);		//find by name

	return 0;
}