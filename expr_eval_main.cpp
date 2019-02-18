#include <iostream>
#include <string>
#include "expr_eval.h"
#include <cmath>
#include <iomanip> 

#define PI 3.1415926535

using namespace std;

void expr_eval::setX(double a){
	unknown = a;
}
string expr_eval::exprConvert(){
	string s;
	hasX = 0;
	for(size_t i = 0; i<expr.length(); i++){
		if(expr[i]>='0'&&expr[i]<='9'){
			s = s+expr[i];
			if(expr[i+1]=='.'){
				s = s+'.';
				i++;
			}
			else
			if((expr[i+1]<'0')||(expr[i+1]>'9')){
				
				s = s+' ';
			}
		}
		else if(expr[i]=='s'||expr[i]=='c'||expr[i]=='t'||expr[i]=='l'){
			
			//while((oper->top()=='s'||oper->top()=='c'||oper->top()=='t'||oper->top()=='l'||oper->top()=='+'||oper->top()=='-'||oper->top()=='*'||oper->top()=='/'||oper->top()=='^')&&
//(oper->top()!='(')){
	
			while((oper->top()=='s'||oper->top()=='c'||oper->top()=='t'||oper->top()=='l')&&(oper->top()!='(')){				
				s = s+oper->top();
				oper->pop();
			}
			oper->push(expr[i]);
			//i++;
			i=i+2;
		}
		else if(expr[i]=='+'||expr[i]=='-'){

//			while((oper->top()=='+'||oper->top()=='-'||oper->top()=='*'||oper->top()=='/'||oper->top()=='^')&&(oper->top()!='(')){

			while((oper->top()=='+'||oper->top()=='-'||oper->top()=='*'||oper->top()=='/'||oper->top()=='^'||oper->top()=='s'||oper->top()=='c'||oper->top()=='t'||oper->top()=='l')&&(oper->top()!='(')){
				s = s+oper->top();
				oper->pop();
			}
			oper->push(expr[i]);
		}
		else if(expr[i]=='*'||expr[i]=='/'){

			while((oper->top()=='*'||oper->top()=='/'||oper->top()=='^'||oper->top()=='s'||oper->top()=='c'||oper->top()=='t'||oper->top()=='l')&&(oper->top()!='(')){
				s = s+oper->top();
				oper->pop();
			}
			oper->push(expr[i]);
		}
		else if(expr[i]=='^'){
			while((oper->top()=='s'||oper->top()=='c'||oper->top()=='t'||oper->top()=='l')&&(oper->top()!='(')){
				s = s+oper->top();
				oper->pop();
			}
			oper->push(expr[i]);
		}
		else if(expr[i]=='('){
			oper->push(expr[i]);
		}
		else if(expr[i]==')'){
			while(oper->top()!='('){
				s = s+oper->top();
				oper->pop();
			}
			oper->pop();
		}
		else if(expr[i]=='x'){
			s = s+expr[i];
			hasX = 1;
		}

	}
	while(!oper->empty()){
		s = s+oper->top();
		oper->pop();
	}
	//cout << s << endl;
	return s;
}

double expr_eval::eval(string s,double b){
	
	mystack<double>* num = new mystack<double>();
	for(size_t i=0; i<s.length(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			string temp;
			temp = temp+s[i];
			while(s[i+1]!=' '){
				temp = temp+s[i+1];
				i++;
			}
			double value = atof(temp.c_str());
			//cout << value << endl;
			num->push((double)value);
		}
		else if(s[i]=='x'){
			double x = unknown;
			num->push(x);
		}
		else if(s[i]=='*'){
			double x;
			double y;
			x = num->top();
			num->pop();
			y = num->top();
			num->pop();
			num->push(x*y);
		}
		else if(s[i]=='-'){
			double x;
			double y;
			x = num->top();
			num->pop();
			y = num->top();
			num->pop();
			num->push(y-x);
		}
		else if(s[i]=='+'){
			double x;
			double y;
			x = num->top();
			num->pop();
			y = num->top();
			num->pop();
			num->push(x+y);
		}
		else if(s[i]=='/'){
			double x; 
			double y;
			x = num->top();
			num->pop();
			y = num->top();
			num->pop();
			if(y!=0){
				num->push(y/x);
			}
		}
		else if(s[i]=='s'){
			double x;
			x = num->top();
			num->pop();
			double rad = sin(x*PI/180);
			num->push(rad);
		}
		else if(s[i]=='c'){
			double x;
			x = num->top();
			num->pop();
			double rad = cos(x*PI/180);
			num->push(rad);
		}
		else if(s[i]=='t'){
			double x;
			x = num->top();
			num->pop();
			double rad = tan(x*PI/180);
			num->push(rad);
		}
		else if(s[i]=='l'){
			double x;
			x = num->top();
			num->pop();
			num->push(log10(x));
		}
		else if(s[i]=='^'){
			double x;
			x = num->top();
			num->pop();
			double y;
			y = num->top();
			num->pop();
			num->push(pow(y,x));
		}
	}
	return num->top();
}
int main(){
	expr_eval* a = new expr_eval();
  	string s1;
	string s2;
	while(cin >> s1){
		a->expr = s1;
		s2 = a->exprConvert();
		if(a->hasX == 1){
			double temp;
			cin >> temp;
			a->setX(temp);
		}
		double result = a->eval(s2,1);
		cout << setprecision(2) << fixed << result << endl;
	}
	cout << endl;
	return 0;
}
