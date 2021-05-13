#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include "forbus.h"
#include "Bus.h"

using namespace std;

int main() {
	int i;

	while (1) {
		cout << "\n1.버스 정보 기입\n2.예약\n3.정보 확인\n4.이용 가능한 버스\n5.종료\n\n";
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
				cout << "\n\n*****종료합니다.*****";
				exit(0);
			}
		}

	}
	return 0;
} 