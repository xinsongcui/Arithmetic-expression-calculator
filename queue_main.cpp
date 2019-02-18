#include<iostream>
#include "myqueue.h"
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
		myqueue<int>* queue = new myqueue<int>();
		while(!cin.eof()){
			if(oper == "enqueue"){
				cin >> type;
				int num = stoi(type,&sz);
				queue->enqueue(num);
			}
			else if(oper == "dequeue"){
				int x = queue->dequeue();
				if(x == 0){
					cout << "error" << endl;
				}
				else cout << x << endl;
			}
			else if(oper == "empty"){
				cout << queue->empty() << endl;
			}
			else if(oper == "front"){
				int a = queue->front();
				if(a!=0)cout << a << endl;
				else cout << "error" << endl;
			}
			else if(oper == "size"){
				cout << queue->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	else if(type == "double"){
		myqueue<double>* queue = new myqueue<double>();
		while(!cin.eof()){
			if(oper == "enqueue"){
				cin >> type;
				double num = atof(type.c_str());
				queue->enqueue(num);
			}
			else if(oper == "dequeue"){
				double x = queue->dequeue();
				if(x != 0){
					cout << x << endl;
				}
				else cout << "error" << endl;
			}
			else if(oper == "empty"){
				cout << queue->empty() << endl;
			}
			else if(oper == "front"){
				double b = queue->front();
				if(b!=0)cout << b << endl;
				else cout << "error" << endl;
			}
			else if(oper == "size"){
				cout << queue->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	else if(type == "char"){
		myqueue<char>* queue = new myqueue<char>();
		while(!cin.eof()){
			if(oper == "enqueue"){
				cin >> type;
				char num = type[0];
				queue->enqueue(num);
			}
			else if(oper == "dequeue"){
				char x = queue->dequeue();
				if(x==0)cout << "error" << endl;
				
					else cout << x << endl;
				
			}
			else if(oper == "empty"){
				cout << queue->empty() << endl;
			}
			else if(oper == "front"){
				char c = queue->front();
				if(c==0)cout << "error" << endl;
				else cout << c << endl;
			}
			else if(oper == "size"){
				cout << queue->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	else if(type == "string"){
		myqueue<string>* queue = new myqueue<string>();
		while(!cin.eof()){
			if(oper == "enqueue"){
				cin >> type;
				string num = type;
				queue->enqueue(num);
			}
			else if(oper == "dequeue"){
				string x = queue->dequeue();
				if(queue->empty())cout << "error" << endl;
					else cout << x << endl;
				
			}
			else if(oper == "empty"){
				cout << queue->empty() << endl;
			}
			else if(oper == "front"){
				string d = queue->front();
				if(queue->empty())cout << "error" << endl;
				else cout << d << endl;
			}
			else if(oper == "size"){
				cout << queue->size() << endl;
			}
			cin >> oper;
		}
		cout << endl;
	}
	return 0;
}
