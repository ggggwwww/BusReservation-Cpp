#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include "forbus.h"
#include "Bus.h"

using namespace std;

int main() {
	int i;

	while (1) {
		cout << "\n1.���� ���� ����\n2.����\n3.���� Ȯ��\n4.�̿� ������ ����\n5.����\n\n";
		cin >> i;
		if (!cin)
			IsEnteredNum(i);
		else {
			switch (i) {
			case 1:
				bus[o].Install();
				break;
			case 2:
				bus[o].Reservate();
				break;
			case 3:
				bus[o].ShowInform();
				break;
			case 4:
				bus[o].Available();
				break;
			case 5:
				cout << "\n\n*****�����մϴ�.*****";
				exit(0);
			}
		}

	}
	return 0;
} 