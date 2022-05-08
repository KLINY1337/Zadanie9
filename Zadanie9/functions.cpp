#include "functions.h"
#include <tuple>

void add_node(string s, string brand, string name, string surname, Node* root) {

	Node* current_vertex = root;

	for (int i = 0; i < s.size(); i++) {

		if (current_vertex->next[s[i] - '0'] == nullptr)
			current_vertex->next[s[i]- '0'] = new Node();

		current_vertex = current_vertex->next[s[i] - '0'];
	}

	current_vertex->info.push_back(make_tuple(brand, name, surname));
}

Node* is_found(string s, Node* root) {
	Node* current_vertex = root;
	for (int i = 0; i < s.size(); i++) {
		current_vertex = current_vertex->next[s[i] - '0'];
		if (current_vertex == nullptr) return nullptr;
	}

	return current_vertex;
}


void print_node(Node* v) {
	for (int i = 0; i < v->info.size(); i++) {
		cout << get<0>(v->info[i]) << " ";
		cout << get<1>(v->info[i]) << " ";
		cout << get<2>(v->info[i]) << "\n";
	}
}

tuple<string,string,string,string> linear_search(vector <Node2*>& vec, string s) {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i]->number == s) return (make_tuple(vec[i]->number, vec[i]->brand, vec[i]->name, vec[i]->surname));
	return (make_tuple("", "", "", ""));
}

size_t barrier_search(vector <Node2*>& vec, Node2* s) {
	auto last = vec[vec.size() - 1];
	vec[vec.size() - 1] = s;
	size_t i = 0;
	for (i=0;vec[i]->number!=s->number;++i){}
	vec[vec.size() - 1] = last;
	if (i != (vec.size() - 1) || s == last) return i;
	return -1;
}


//int main() {
//	root = new Node();
//
//	add_node("arab777", "ford", "Oleg", "Tinkoff");
//	add_node("arab777", "toyota", "Nikita", "4el");
//	Node* nadofind = is_found("arab777");
//	print_node(nadofind);
//
//	vector <Node2*> vec;
//
//
//	Node2* root2 = new Node2();
//	root2->number = "arab777";
//	root2->brand = "ford";
//	root2->name = "nikita";
//	root2->surname = "Tinkoff";
//	vec.push_back(root2);
//	auto t=linear_search(vec, "arab777");
//
//	cout << get<1>(t)<<" " << get<2>(t)<<" " << get<3>(t);
//
//	Node2* root3 = new Node2();
//	root2->number = "arab777";
//	root2->brand = "ford";
//	root2->name = "nikita";
//	root2->surname = "Tinkoff";
//	vec.push_back(root2);
//	auto i = barrier_search(vec, root2);
//
//	cout << vec[i]->brand << " " << vec[i]->name << " " << vec[i]->surname;
//}
