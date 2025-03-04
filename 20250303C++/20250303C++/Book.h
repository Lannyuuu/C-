#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book {
private:
	string title;
	string last;
	string first;
public:
	Book(const string ttl , const string lst,
		const string fst) : title(ttl), last(lst), first(fst) {};
	string getTitle() const { return title; }
	string getlast() const { return last; }
	string getfirst() const { return first; }
};
