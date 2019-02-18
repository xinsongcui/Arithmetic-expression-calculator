
#include <iostream>
#include "mystack.h"
#include <string>
#include <stdlib.h>

using namespace std;


int main(){
	int flag;
	string type;
	string oper;
	cin >> type;
	std::string::size_type sz;
	if(type == "int"){
		mystack<int>* stack = new mystack<int>();
		while(!cin.eof()){
			if(oper == "push"){
				cin >> type;
				int num = stoi(type,&sz);
				stack->push(num);
			}
			else if(oper == "pop"){
				if(stack->empty())cout << "error" << endl;
    				else {int x = stack->pop();
			
				 cout << x << endl;
				}
			}
			else if(oper == "empty"){
				cout << stack->empty() << endl;
			}
			else if(oper == "top"){
				if(stack->empty())cout << "error" << endl;
				else {
					int a = stack->top();
					cout << a << endl;
				}
			}
			else if(oper == "size"){
				cout << stack->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	else if(type == "double"){
		mystack<double>* stack = new mystack<double>();
		while(!cin.eof()){
			if(oper == "push"){
				cin >> type;
				double num = atof(type.c_str());
				stack->push(num);
			}
			else if(oper == "pop"){
				if(stack->empty())cout << "error" << endl;
				else
				{
				double x = stack->pop();
			 	cout << x << endl;
				}
			}
			else if(oper == "empty"){
				cout << stack->empty() << endl;
			}
			else if(oper == "top"){
				if(stack->empty())cout << "error" << endl;
				else{ 
					double b = stack->top();
					if(b!=0)cout << b << endl;
				}
			}
			else if(oper == "size"){
				cout << stack->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	else if(type == "char"){
		mystack<char>* stack = new mystack<char>();
		while(!cin.eof()){
			if(oper == "push"){
				cin >> type;
				char num = type[0];
				stack->push(num);
			}
			else if(oper == "pop"){
				char x = stack->pop();
				if(stack->empty())cout << "error" << endl;
					else cout << x << endl;
				
			}
			else if(oper == "empty"){
				cout << stack->empty() << endl;
			}
			else if(oper == "top"){
				if(stack->empty())cout << "error" << endl;
				else {
					char c = stack->top();
					cout << c << endl;
				}
			}
			else if(oper == "size"){
				cout << stack->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	else if(type == "string"){
		mystack<string>* stack = new mystack<string>();
		while(!cin.eof()){
			if(oper == "push"){
				cin >> type;
				string num = type;
				stack->push(num);
			}
			else if(oper == "pop"){
				string x = stack->pop();
				if(stack->empty())cout << "error" << endl;
					else cout << x << endl;
				
				
			}
			else if(oper == "empty"){
				cout << stack->empty() << endl;
			}
			else if(oper == "top"){
				if(stack->empty())cout << "error" << endl;
				else{
					string d = stack->top();
					cout << d << endl;
				}
			}
			else if(oper == "size"){
				cout << stack->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	return 0;
}
