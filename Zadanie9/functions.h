#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

struct Node {
	Node* next[100];

	vector <tuple<string, string, string>> info;

	Node() {
		for (int i = 0; i < 100; i++)
			next[i] = nullptr;

	}
};

struct Node2 {
	string number;
	string brand;
	string name;
	string surname;
};

void add_node(string s, string brand, string name, string surname, Node* root);
Node* is_found(string s, Node* root);
void print_node(Node* v);

tuple<string, string, string, string> linear_search(vector <Node2*>& vec, string s);
size_t barrier_search(vector <Node2*>& vec, Node2* s);