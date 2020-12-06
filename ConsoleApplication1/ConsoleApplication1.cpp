#include <iostream>
#include <Windows.h>
using namespace std;

void sizeOfData() {

	cout << "Sizes of defferent simple types of data: \n\n";
	cout << "short int:\t" << sizeof(short int) << " bytes" << endl;
	cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
	cout << "long int:\t" << sizeof(long int) << " bytes" << endl;
	cout << "long long int:\t" << sizeof(long long int) << " bytes" << endl;
	cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
	cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
	cout << "long double:\t" << sizeof(long double) << " bytes" << endl;
	cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
	cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;
}

void intToBin() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n Pls input some int number \n";
	unsigned int mask = 1 << 31;
	int num;
	cin >> num;
	cout << "decimal " << num << " in binary = ";
	for (int i = 1; i <= 32; i++) {
		if (num & mask) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		if (i == 1) {
			cout << " ";
		}
		mask >>= 1;
	}
}

void floatToBin() {

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n Pls input some float number \n";

	unsigned int mask = 1 << 31;
	union unums{
		int num_i;
		float num_f;
	};

	unums number;
	float numFloat;
	cin >> numFloat;
	number.num_f = numFloat;

	cout << "float " << number.num_f << " in binary = ";
	for (int i = 1; i <= 32; i++) {
		if (number.num_i & mask) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		if (((i/1) == 1) || (((i/9) == 1) && ((i%9)==0))) cout << " ";
		mask >>= 1;
	}

}

void doubleToBin() {

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n Pls input some Double number \n";
	unsigned long long int mask = 1;
	mask <<= 63;
	union unums {
		long long int num_l;
		double num_d;
	};

	unums number;
	double numDouble;
	cin >> numDouble;
	number.num_d = numDouble;
	cout << "double " << number.num_d << " in binary = ";

	for (int i = 1; i <= 64; i++) {
	
		if (number.num_l & mask) {
			cout << 1;
		}
		else {
			cout << 0;
		}

		if (((i / 1) == 1) || (((i / 12) == 1) && ((i % 12) == 0))) {
			cout << " ";
		}
		mask >>= 1;
	}
}


int main()
{
	bool chose2 = true;
	int chose;

	while (chose2) {
		system("cls");
		cout << "Just chose number of what do you need and it's will be completed,\n any different number will finish this program" << endl;
		cout << "1. Get Sizes of different types of data" << endl
			<< "2. Convert int to binary" << endl
			<< "3. Convert float to binary" << endl
			<< "4. Convert double to binary" << endl;

		cin >> chose;
		switch (chose) {
		case 1: sizeOfData();
			cout << "\nPress 0 to finish program \nPress 1 to go back to menu" << endl;
			cin >> chose2;
			break;
		case 2: intToBin();
			cout << "\nPress 0 to finish program \nPress 1 to go back to menu" << endl;
			cin >> chose2;
			break;
		case 3: floatToBin();
			cout << "\nPress 0 to finish program \nPress 1 to go back to menu" << endl;
			cin >> chose2;
			break;
		case 4: doubleToBin();
			cout << "\nPress 0 to finish program \nPress 1 to go back to menu" << endl;
			cin >> chose2;
			break;
		default: return 0;
		}
	}
}