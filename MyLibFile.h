#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
namespace MyLibFile {
	void PrintFileContent(string filename) {
		fstream myfile;
		myfile.open(filename, ios::in);

		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				cout << line << endl;

			}
			myfile.close();
		}



	}


	void ClearFile(string filename) {
		fstream myfile;
		myfile.open(filename, ios::out);

		if (myfile.is_open()) {

			myfile.clear();
		}
		myfile.close();
	}


	void LoadDataFromFileToVector(string filename,vector<string>& vData){
		fstream myfile;
		myfile.open(filename, ios::in);

		if (myfile.is_open()) {
			string line;
			while (getline(myfile, line)) {
				
				vData.push_back(line);
			}
			myfile.close();
		}
	
	}



	void SaveLineToFile(string filename, string line) {
		fstream myfile;
		myfile.open(filename,ios::out | ios::app);

		if(myfile.is_open()){
		
			myfile << line << endl;
		
		}
		myfile.close();

	}

	void UpdateRecordClientToFile(string filename, string line) {
		fstream myfile;
		myfile.open(filename, ios::out);

		if (myfile.is_open()) {
			
				myfile << line <<endl;
			
		}
		myfile.close();
	}

  

    void DeleteRecordFromfile(string filename  , string recorddata) {
			vector<string>vdata;
			LoadDataFromFileToVector(filename,vdata);
				for (string &data : vdata) {

				if(data == recorddata){
					data = "";
				}

				}

			
				


		}


}