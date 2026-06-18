#pragma once
#pragma once

#include<iostream>
using namespace std;
namespace MyLiSeting {





	enum  enbackColor {
		red = 1,
		yelow = 2,
		green = 3,
		balck = 4,

	};



	void cotrrolColor(enbackColor colors) {

		switch (colors) {

		case enbackColor::yelow:
			system("color E0");//->خلفية صفراء ونص أسود التعادل 
			break;
		case enbackColor::green:
			system("color 2F");//// الفوز اخضر

			break;
		case enbackColor::red:
			system("color 4F");// خسارة احمر 
			cout << "\a";
			break;
		case  enbackColor::balck:
			system("color 07");//خلفيه افتراضي 
			break;

		}
	}

	void ClearScreen() {
		system("cls");
		cotrrolColor(enbackColor::balck);

	}


}