#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <typeinfo>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void IsEnteredNum(int n) {
	cout << "숫자만 입력가능합니다!";
	cin.clear();
	cin.ignore(13, '\n');
}

