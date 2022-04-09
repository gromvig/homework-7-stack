#include<iostream>
#include<string>
#include<stack>
#include<stdlib.h>
using namespace std;
struct elem {
	int value;
	int num;
	elem* next = nullptr;
};
void push(elem*& stack, int value, int num)
{
	elem* newel = new elem;
	newel->value = value;
	newel->num = num;
	if (!stack)
	{
		stack = newel;
	}
	else
	{
		newel->next = stack;
		stack = newel;
	}
}
bool pop(elem*& stack, int& value, int& num)
{
	if (!stack) return false;
	elem* rem = stack;
	value = stack->value;
	num = stack->num;
	stack = stack->next;
	delete rem;
	return true;
}
void clear(elem*& stack)
{
	while (stack)
	{
		elem* rem = stack;
		stack = stack->next;
		delete rem;
	}
}
void output(char* math, int i) {
	printf("ошибочная скобка под номером - %d\n", i + 1);
	for (int j = 0; math[j]; j++) {
		if (j == i) {
			cout << "\x1b[31m" << math[j] << "\x1b[0m";
		}
		else {
			cout << math[j];
		}
	}
}


int main() {
	setlocale(LC_ALL, "Rus");
	elem* stack = nullptr;
	char* math = new char;
	char close;
	int value;
	int num;
	int errnum;
	cout << "Введите математическое выражение:\n";
	cin >> math;
	for (int i = 0; math[i]; i++) {
		if (math[i] == '(' || math[i] == '[' || math[i] == '{' || math[i] == '<') {
			push(stack, math[i], i);
		}
		else if (math[i] == ')' || math[i] == ']' || math[i] == '}' || math[i] == '>') {
			close = math[i];
			if (!pop(stack, value, num)) {
				output(math, i);
				exit(0);
			}
			if ((value == '(' && close != ')') || (value == '[' && close != ']') || (value == '{' && close != '}') || (value == '<' && close != '>')) {
				output(math, i);
				exit(0);
			}
		}
	}
	if (!pop(stack, value, num)) {
		cout << "Cтрока содержит корректное выражение";
	}
	else {
		output(math, num);
	}
	clear(stack);
}
