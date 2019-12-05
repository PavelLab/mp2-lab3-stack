#pragma once
#include "TStack.h"
#include <string>

class TCalculator {
	std::string expr;       //выражение
	std::string postfix;    //выражение в постфиксной записи
	TStack<char> st_c;
	TStack<double> st_d;
public:
	TCalculator() {};
	TCalculator(const TCalculator &a);
	~TCalculator() {};

	void Setexpr(std::string s);     //установить строку(выражение)
	std::string GetExpr();           //вернуть строку(выражение)
	std::string GetPostfix();        //вернуть выражение в постфиксной записи
	bool check();               //проверка правильности написания скобок в выражении
	int prior(char c);          //возвращает приоритет операции с
	void ToPostfix();           //переводит выражение в постфиксную запись
	double calc();              //считает значение выражения postfix
};


TCalculator::TCalculator(const TCalculator &a) : st_c(a.st_c), st_d(a.st_d), expr(a.expr), postfix(a.postfix)
{
}/*-------------------------------------------------------------------------*/


void TCalculator::Setexpr(std::string s){
	expr = s;
}/*-------------------------------------------------------------------------*/

std::string TCalculator::GetExpr() {
	return expr;
}/*-------------------------------------------------------------------------*/


std::string TCalculator::GetPostfix() {
	return postfix;
}/*-------------------------------------------------------------------------*/


bool TCalculator::check() {
	st_c.clear();
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '(') st_c.push(expr[i]);
		if (expr[i] == ')') {
			if (st_c.isempty()) return false;
			st_c.pop();
		}
	}
	return st_c.isempty();
}/*-------------------------------------------------------------------------*/

int TCalculator::prior(char c) {
	if (c == '(') return 0;
	if (c == '+'||c=='-') return 1;
	if (c == '*' || c == '/' || c == ':') return 2;
}/*-------------------------------------------------------------------------*/

void TCalculator::ToPostfix() {
	std::string str = "(";
	str += expr;
	str += ")";
	st_c.clear();
	postfix = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st_c.push(str[i]);
		if (str[i] >= '0'&&str[i] <= '9' || str[i] == '.') postfix += str[i];
		if (str[i] == ')') {
			char tmp = st_c.pop();
			while (tmp != '(') {
				postfix += tmp;
				tmp = st_c.pop();
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ':') {
			postfix += " ";
			char tmp = st_c.pop();
			while (prior(str[i]) <= prior(tmp)) {
				postfix += tmp;
				tmp = st_c.pop();
			}
			st_c.push(tmp);
			st_c.push(str[i]);
		}
	}
}


double TCalculator::calc() {
	char *tmp; double res;
	st_d.clear();
	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] >= '0'&& postfix[i] <= '9') {
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st_d.push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == ':') {
			double op1, op2;
			op2 = st_d.pop();
			op1 = st_d.pop();
			switch (postfix[i])
			{
			case '+': res = op1 + op2;
				break;
			case '-': res = op1 - op2;
				break;
			case '*': res = op1 * op2;
				break;
			case (':'):
			case ('/'): res = op1 / op2;
				break;
			default:
				break;
			}
			st_d.push(res);
		}
	}
	if (st_d.isempty()) throw "Wrong data";
	res = st_d.pop();
	if (!st_d.isempty()) throw "Wrong data";
	return res;
}