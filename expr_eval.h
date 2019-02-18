#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H

#include <string>
#include <iostream>
#include "mystack.h"

using namespace std;

class expr_eval{
  private:
        // Declare which ever necessary variables and methods
	//string expr;
	mystack<char>* oper = new mystack<char>();
	double unknown;
  public:
        double eval(string, double);
	string exprConvert();
	void setX(double);
	bool hasX = 0;
	string expr;
};

#endif
