#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <Windows.h>
#include <typeinfo>
#include <stdlib.h>
#include <typeinfo>
#include <fstream>
#include <io.h>
#include "forbus.h"

using namespace std;

static int o = 0;
int bus_order;

class Bus {
private:
	char bus_no[1000], driver[100], arrivalT[50], departT[50], from[100], to[100];

	class seat {
	public:
		char name[100];

	}seat[32];

public:
	void Install();
	void Reservate();
	void ShowInform();
	void Available();
}bus[1000];

char const* txt = ".txt";
void Bus::Install() {
	ofstream fout;
	int length;

	while (1) {
		cout << "\n���� ��ȣ: ";
		cin >> bus_order;
		string s = to_string(bus_order);
		char const* num_char = s.c_str();
		char const* num_txt = strcat((char*)num_char, txt);
		if (!cin)
			IsEnteredNum(bus_order);
		else if (*bus[bus_order].bus_no != NULL) {
			cout << "\n�̹� �ִ� ���� ��ȣ �Դϴ�!\n";
			continue;
		}
		else if (bus_order > 999 || bus_order < 1) {
			cout << "\n��ȿ ���� �ʰ�!\n";
			continue;
		}
		else {
			if (access(num_txt, 0) != 0) {
				//ofstream fout(num_txt);
				fout.open(num_txt);
				fout << bus_order;

				cout << "\n������ �̸�: ";
				cin >> bus[bus_order].driver;
				fout << bus[bus_order].driver;
				
				cout << "\n��� �ð�: ";
				cin >> bus[bus_order].departT;	
				fout << bus[bus_order].departT;

				cout << "\n���� �ð�: ";
				cin >> bus[bus_order].arrivalT;		
				fout << bus[bus_order].arrivalT;

				cout << "\n�����: ";
				cin >> bus[bus_order].from;	
				fout << bus[bus_order].from;

				cout << "\n������: ";
				cin >> bus[bus_order].to;			
				fout << bus[bus_order].to;

				fout.close();
				break;
			}
			else {
				cout << "�̹� �ִ� ���� �Դϴ�." << endl;
				break;
			}
			
		}
	}

}

void Bus::Reservate() {
	int seat;
	int bus_order;
	char userName[10];
	char null[4] = " ";
	ofstream fout;
	static char const* numtxt;
	while (1) {
		cout << "\n���� ��ȣ: ";
		cin >> bus_order;
		string s = to_string(bus_order);
		char const* num_char = s.c_str();
		char const* num_txt = strcat((char*)num_char, txt);
		fout.open(numtxt);
		numtxt = num_txt;
		if (!cin)
			IsEnteredNum(bus_order);
		else if (bus_order > 1000 || bus_order < 1)
			cout << "��ȿ ���� �ʰ�!(* 1~999������ ��ȣ�� �Է°���. *)";
		else {
			/*if (strcmp(bus[bus_order].bus_no, num_char) != 0)
				cout << "��ġ�ϴ� ��ȣ ����!\n";*/
			if(access(num_txt, 0) != 0)
				cout << "��ġ�ϴ� ��ȣ ����!";
			else
				break;
		}

	}

	while (1) {
		cout << "\n�¼� ��ȣ: ";
		cin >> seat;
		if (!cin)
			IsEnteredNum(seat);
		else if (seat > 32) {
			cout << "������ �¼� �� ���� Ů�ϴ�!\n";
			continue;
		}
		else if (*bus[bus_order].seat[seat].name != NULL) {
			cout << "�̹� �ٸ� �̿밴�� �ֽ��ϴ�!\n";
			continue;
		}
		else
			break;
	}


	while (1) {
		cout << "\n������ �̸�: ";
		cin >> userName;
		if (userName == null) {//������ �Է����� ���
			cout << "������ �ȵ˴ϴ�!\n";
			continue;
		}
		else {
			strcpy(bus[bus_order].seat[seat].name, userName);
			
			fout << userName;
			break;
		}
	}

	fout.close();
}

void Bus::ShowInform() {
	while (1) {
		cout << "\n���� ��ȣ: ";
		cin >> bus_order;
		string s = to_string(bus_order);
		char const* num_char = s.c_str();
		if (!cin)
			IsEnteredNum(bus_order);
		else if (bus_order >= 1000 || bus_order < 1) {
			cout << "��ȿ ���� �ʰ�!\n";
			continue;
		}
		else if (strcmp(bus[bus_order].bus_no, num_char) != 0) {
			cout << "�ش� ������ �������� �ʽ��ϴ�!\n";
			break;
		}
		else {
			printf("\n���� ��ȣ: %s ������: %s ��߽ð�: %s �����ð�: %s\n�����: %s ������: %s\n",
				bus[bus_order].bus_no, bus[bus_order].driver, bus[bus_order].departT,
				bus[bus_order].arrivalT, bus[bus_order].from, bus[bus_order].to);
			for (int i = 1; i <= 32; i++) {
				if (i == 32)
					printf("%d. %s\n ", i, bus[bus_order].seat[i].name);
				else
					printf("%d. %s ", i, bus[bus_order].seat[i].name);
			}
			break;
		}
	}
}

void Bus::Available() {//���Ե� ��ȣ�� ���
	for (bus_order = 0; bus_order < 1000; bus_order++) {
		string s = to_string(bus_order);
		char const* num_char = s.c_str();

		if (strcmp(bus[bus_order].bus_no, num_char) != 0) {
			continue;
		}
		else if (strcmp(bus[bus_order].bus_no, num_char) == 0) {
			cout << bus[bus_order].bus_no << "�� ";
		}
		else {
			cout << "� ������ �����ϴ�!\n";
			break;
		}

	}
}