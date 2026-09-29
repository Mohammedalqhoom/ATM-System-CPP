#include<iostream>
#include<iomanip>
#include<string>
#include"MyLibMath.h";
#include"MyLibFile.h";
#include"MyLibString.h";
#include"MyLiSeting.h";
using namespace std;



struct sClient
{
	string nameClint;
	string numberacount;
	string PinCode;
	string PhonClint;
	int AcountBaliance;
	bool MarkForDelete = false;
};
void MainueList();
void Login();
void WithWardClient();
void GoBackMainMinue();
 sClient LoginClient;
const string clientFile = "FileClint.txt";



sClient ConvertLinetoRecord(string stLine) {

	vector<string> clint = MyLibString::SplitString(stLine, "#\\#");
	sClient stclint;
	stclint.numberacount = clint[0];
	stclint.PinCode = clint[1];
	stclint.nameClint = clint[2];
	stclint.PhonClint = clint[3];
	stclint.AcountBaliance = stod(clint[4]);



	return stclint;

}
enum enChoiceTransactions {
	enQuickWithdraw = 1,
	enNormalWithdraw = 2,
	enDeposit = 3,
	enCkeckBalance = 4,
	enExite = 5

};
short ReadNormalWithdraw() {

	short choice;
	cout << "\nShoces what to do you want to do? [1 to 8] ?";
	cin >> choice;
	return choice;
}
void LoadDataUserFromFileToVector(string filename, vector<sClient>& vData) {
	fstream myfile;

	myfile.open(filename, ios::in);

	if (myfile.is_open()) {
		string line;
		while (getline(myfile, line)) {

			vData.push_back(ConvertLinetoRecord(line));
		}
		myfile.close();
	}

}
bool FindClientByAccountNumber(string AccountNamber, string Paidcode) {
	vector<sClient> vclient;
	LoadDataUserFromFileToVector(clientFile, vclient);
	for (sClient& clien : vclient) {
		if (clien.numberacount == AccountNamber && clien.PinCode == Paidcode) {

			LoginClient = clien;
			return true;
		}
	}

	return false;
}

string ConvertClinttoString(sClient stclint) {

	string line = stclint.numberacount + "#\\#" + stclint.PinCode + "#\\#" + stclint.nameClint + "#\\#" + stclint.PhonClint + "#\\#" + to_string(stclint.AcountBaliance);
	return line;
}

void BalanceClient() {
	cout << "\nYour Balance Is " << to_string(LoginClient.AcountBaliance) << endl;
}
void SaveVectirClientToFile(string filename, vector<sClient>& vclientUpdate) {
	MyLibFile::ClearFile(filename);

	for (sClient& line : vclientUpdate) {

		MyLibFile::SaveLineToFile(filename, ConvertClinttoString(line));
	}

}




double UpdateBalences(double AcountBaliance, double Diposit) {
	return (AcountBaliance + Diposit);
}

void DipositBalencesToClientAcuentNumber(double Diposit, vector<sClient>& vclient) {
	

	LoadDataUserFromFileToVector(clientFile, vclient);
	for (sClient& line : vclient) {
		if (line.numberacount == LoginClient.numberacount) {
			line.AcountBaliance = UpdateBalences(line.AcountBaliance, Diposit);
			LoginClient.AcountBaliance = line.AcountBaliance;
			break;
		}


	}




}

//int ChoiceNormale()
short ReadQuickwithdrawOption() {
	short choice =0;

	while (choice < 1 || choice > 9) {
		cout << "Choice  > Choice WithWard From [1] To [8] :";
		cin >> choice;

	}
	return choice;
}

int getQuickWithDrawamuent(short quick){
	int array[] = { 20,50,100,200,400,600,800,1000 };
	return array[quick -1];
}

void WidthOrBositev(int Withdraw) {
	vector<sClient> vclient;
	DipositBalencesToClientAcuentNumber(Withdraw, vclient);
	SaveVectirClientToFile(clientFile, vclient);
	BalanceClient();


}

void perforQuickwithDrawOption(short QuickWith) {

	if (QuickWith == 9)return;

	int WithDrawBalence = getQuickWithDrawamuent(QuickWith);
	if (WithDrawBalence > LoginClient.AcountBaliance) {
		cout << "\nThe amuent exced you balence ,mack anuther choice.\n";
		cout << "Press AnyKey Your Continue.";
		system("pause>0");
		GoBackMainMinue();
		return;
	}

	WidthOrBositev(WithDrawBalence*-1);
}






short ReadMainMunue() {

	short choice;
	cout << "\nShoces what to do you want to do? [1 to 5] ?";
	cin >> choice;
	return choice;
}

void GoBackMainMinue() {
	cout << "\n press any key to go back to main Muenu\n";
	system("pause>0");
	MyLiSeting::ClearScreen();
	MainueList();
}






void QuickWithdrawScreen() {
	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "QuickWithdraw Screen !!";
	cout << "\n======================================================\n";
	cout <<"\n" << MyLibString::Tabe(1) << "[1] 20" << MyLibString::Tabe(2) << "[2] 50" << endl;
	cout <<"\n" << MyLibString::Tabe(1) << "[3] 100" << MyLibString::Tabe(2) << "[4] 200" << endl;
	cout <<"\n" << MyLibString::Tabe(1) << "[5] 400" << MyLibString::Tabe(2) << "[6] 600" << endl;
	cout << "\n" << MyLibString::Tabe(1) << "[7] 800" << MyLibString::Tabe(2) << "[8] 1000" << endl;
	cout << "\n" << MyLibString::Tabe(1) << "[9] Exit!"<< endl;
	cout << "\n======================================================\n";
	BalanceClient();
	
	perforQuickwithDrawOption(ReadQuickwithdrawOption());


}


void ShowQuickWithdrawScreen() {


	QuickWithdrawScreen();


	
}
bool ValidateMultibleOfNumber(int amuent){
	return (amuent % 5 == 0);
}
short ReadWithDrawamuent() {
	short amuent;
	amuent = MathNumber::readnumber("\nEnter an amuent multibe of,5 ?");
	while (!ValidateMultibleOfNumber(amuent)) {
		amuent = MathNumber::readnumber("\nEnter an amuent multibe of,5 ?");
	}
	return amuent;
}




void perForNurmalwithDrawOption() {


	int WithDrawBalence = ReadWithDrawamuent();
		if (WithDrawBalence > LoginClient.AcountBaliance) {
			cout << "\nThe amuent exced you balence ,mack anuther choice.\n";
			cout << "Press AnyKey Your Continue.";
			system("pause>0");
			GoBackMainMinue();
			return;
		}

	WidthOrBositev(WithDrawBalence * -1);
}


int ReadDipositamuent() {
	int Diposit = 0;
	while (Diposit <= 0 ) {
		Diposit = MathNumber::readnumber("\nEnter a positev amuent :");
	}

	return Diposit;
}


void perFormDipositAmuent() {


	int Dipositamuent = ReadDipositamuent();


	WidthOrBositev(Dipositamuent);
}



void ShowNormalWithdrawScreen() {

	cout << "\n============================================";
	cout << "\n" << MyLibString::Tabe(1) << "NormalWithdraw Screen !!";
	cout << "\n=============================================\n";
	perForNurmalwithDrawOption();
}

void ShowDepositScreen() {

	cout << "\n============================================";
	cout << "\n" << MyLibString::Tabe(1) << "Deposit Screen !!";
	cout << "\n=============================================\n";
	perFormDipositAmuent();
}


void ShowCkeckBalanceScreen() {

	cout << "\n============================================";
	cout << "\n" << MyLibString::Tabe(1) << "CkeckBalance Screen !!";
	cout << "\n=============================================\n";
	BalanceClient();
}




void ChoiceProcessAtmsystem(enChoiceTransactions enChoice) {

	switch (enChoice) {
	case enChoiceTransactions::enQuickWithdraw:
		MyLiSeting::ClearScreen();
		ShowQuickWithdrawScreen();
		GoBackMainMinue();
		break;
	case enChoiceTransactions::enNormalWithdraw:
		MyLiSeting::ClearScreen();

		ShowNormalWithdrawScreen();
		GoBackMainMinue();
		break;
	case enChoiceTransactions::enDeposit:
		MyLiSeting::ClearScreen();
		ShowDepositScreen();
		GoBackMainMinue();
		break;
	case enChoiceTransactions::enCkeckBalance:
		MyLiSeting::ClearScreen();
		ShowCkeckBalanceScreen();
		GoBackMainMinue();
		break;
	case enChoiceTransactions::enExite:

		MyLiSeting::ClearScreen();
		Login();
		break;
	}



}


void MainueList() {
	MyLiSeting::ClearScreen();
	cout << "\n======================================================";

	cout << "\n" << MyLibString::Tabe(2) << "ATM Main Menue Screen!";
	cout << "\n======================================================\n";

	cout << MyLibString::Tabe(2) << "[ 1 ] Quick Withdraw" << endl;
	cout << MyLibString::Tabe(2) << "[ 2 ] Normal Withdraw." << endl;
	cout << MyLibString::Tabe(2) << "[ 3 ] Deposit." << endl;
	cout << MyLibString::Tabe(2) << "[ 4 ] Ckeck Balance." << endl;
	cout << MyLibString::Tabe(2) << "[ 5 ] Logout." << endl;

	cout << "\n======================================================";

	ChoiceProcessAtmsystem((enChoiceTransactions)ReadMainMunue());

}



void LoginScreeen(){
	MyLiSeting::ClearScreen();
	cout << "\n======================================================";
	cout << "\n" << MyLibString::Tabe(2) << "Login Screen !!";
	cout << "\n======================================================\n";

}






void Login() {

	string AccountNamber, Paidcode;


	bool LoadFalid = false;

	do {
		LoginScreeen();
		if (LoadFalid) {

			cout << "Invalid / Account Namber / paidcode !\n";
		}
		cout << "Enter AccountNamber:";
		getline(cin >> ws, AccountNamber);
		cout << "Enter Paidcode:";
		getline(cin >> ws, Paidcode);

		LoadFalid = !FindClientByAccountNumber(AccountNamber, Paidcode);

	} while (LoadFalid);

	MainueList();

}




int main() {

	Login();
	system("pause>0");


	return 0;
}