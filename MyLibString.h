#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;
namespace MyLibString {

	enum enWatetoCountLetters {
		SmalLetter=0,CapitalLatter=1,All
	};

	string Tabe(int n) {
		string tab = "";
		for (int i = 1;i <= n;i++) {
			tab += "\t";

		}
		return tab;
	}

	void PrintFirstLetterOfEachWord(string s) {
		bool Firstletter = true;
		for (int i = 0;i < s.length();i++) {


			if (s[i] != ' ' && Firstletter == true) {

				cout << s[i] << " " << endl;
			}

			Firstletter = (s[i] == ' ' ? true : false);
		}

	}

	string ReadString() {
		cout << "Pless Enter the text >>";
		string s;
		getline(cin, s);
		return s;

	}
	string ReadString(string mesag) {
		cout << mesag <<">>";
		string s;
		getline(cin >> ws, s);
		return s;

	}


	void PrintString(string s) {
		cout << s << endl;
	}




	string UpperFirstLetterOfEachWord(string s) {

		bool Firstletter = true;
		for (int i = 0;i < s.length();i++) {


			if (s[i] != ' ' && Firstletter == true) {
				s[i] = toupper(s[i]);

			}

			Firstletter = (s[i] == ' ' ? true : false);
		}
		return s;

	}


	string LowerFirstLetterOfEachWord(string s) {

		bool Firstletter = true;
		for (int i = 0;i < s.length();i++) {


			if (s[i] != ' ' && Firstletter == true) {
				s[i] = tolower(s[i]);

			}

			Firstletter = (s[i] == ' ' ? true : false);
		}
		return s;

	}

	string LowerAllString(string s) {
		for (short i = 0;i < s.length();i++) {
		
			if (s[i] != ' ') {
				s[i]= tolower(s[i]);
			}

		}
		return s;
	}


	string UpperAllString(string s) {
		for (short i = 0;i < s.length();i++) {

			if (s[i] != ' ') {
				s[i] = toupper(s[i]);
			}

		}
		return s;
	}
	char ReadChar(){
		cout << "Plees Enter letter >> ";
		char c;
		cin >> c;
		return c;
	}

	char InvertLetterCase(char letter){
	
		return islower(letter) ? toupper(letter) : tolower(letter);
	}

	bool ValidatLetterUpper(char letter) {

		return isupper(letter);
	}


	string InvertAllStringLettersCase(string s){
	
		for (short i = 0; i < s.length();i++ ) {
		
			s[i] = InvertLetterCase(s[i]);
		
		}

		return s;
	}

	int	CountCapitalLetters(string s) {

		char count = 0;
		for (short i = 0; i < s.length();i++) {
			if (ValidatLetterUpper(s[i])) {
				count++;
			}
		}
		return count;
	}
   int	CountSmallLetters(string s){
   
	   char count = 0;
	   for (short i = 0; i < s.length();i++) {
		   if (!ValidatLetterUpper(s[i]) &&  s[i]!=' ') {
			   count++;
		   }
	   }
	   return count;
   
   }



  int CountLetters(string s, enWatetoCountLetters enwatCount= enWatetoCountLetters::All){
	  
	  if (enwatCount == enWatetoCountLetters::All)return s.length();


	  int count = 0;

	  for (short i = 0; i < s.length();i++) {
		  if ( enwatCount == enWatetoCountLetters::SmalLetter && islower(s[i]) )
			  count++;

		  if (isupper(s[i]) && enwatCount == enWatetoCountLetters::CapitalLatter)
			  count++;
		  
	  }


	  return count;
  }

  int CountLetter(string s,char let, bool MatchCase =true){

	  short count = 0;
	  for (short i = 0; i < s.length();i++) {

		  if (MatchCase) {
			
			  if (s[i] == let)count++;

		  }else
			  if (tolower(s[i]) == tolower(let)) {
				  count++;
			  }

	  
	  }
	  return count;
  
  }

  bool IsVawel(char c){
	  c = tolower(c);
	  return(c=='a' || c=='u' || c=='e' || c== 'i' || c== 'o');
  
  }

  int CountVawelCase(string s){
	  short count = 0;
	  for (short i = 0; i < s.length();i++) {
		  if (IsVawel(s[i]))count++;
	  }
	  return count;
  }

  void PrintVawels(string s) {
	  
	  for (short i = 0; i < s.length();i++) {
		  if (IsVawel(s[i]))cout << s[i] << " ";
	  }
	
  }

  void PrintEachWordInStrin(string s) {
	  bool empty = false;
	  for (short i = 0; i < s.length();i++) {
		  if (s[i] != ' ' && empty == false)cout << s[i];
		  else
			  cout << endl;

		  empty = (s[i] == ' '? true :false);
	  }

  }


  void PrintEachWordInStrinS(string s) {
	  string empty = " ";
	  short po = 0;

	  while ((po = s.find(empty)) != std::string::npos) {
		   
		  string world = s.substr(0,po );
		  if (world != "") {
			  cout << world << endl;
		  }

		  s.erase(0, po + empty.length());

	  }

	  if (s != "") {
		  cout << s << endl;
	  }

  }
  short CountWords(string s) {

	  string empty = " ";
	  short po = 0;
	  short count = 0;
	  string world;
	  while ((po = s.find(empty)) != std::string::npos) {

		   world = s.substr(0, po);
		  if (world != "") {
			  count++;
		  }

		  s.erase(0, po + empty.length());

	  }

	  if (s != "") {
		  count++;
	  }

	  return count;
  }

  vector<string> SplitString(string s,string sp) {

	  vector<string> vWorld;

	 
	  short po = 0;
	  string world;

	  while((po = s.find(sp)) != std::string::npos){
	  
		  world = s.substr(0,po);
		  if (world != "") {
			  vWorld.push_back(world);
		  }

		  s.erase(0,po + sp.length());



	  }

	  if (s != "") {
		  vWorld.push_back(s);
	  }

	  return vWorld;
  }

  string TrimLeft(string s){
	 
	  for (short i = 0; i < s.length();i++) {
		  if (s[i] != ' ') return s.substr(i,s.length() -1);
		 
	  }
	  return "";
  }


  string TrimRight(string s) {

	  for (short i = s.length() - 1; i>=0;i--) {
		  if (s[i] != ' ') return s.substr(0,i+1);

	  }
	  return "";
  }

  string Trim(string s) {
	  return TrimLeft(TrimRight(s));
  }



  string JoinString(vector<string> vWorld, string Dlim) {

	  string world = "";
	 for(string &s: vWorld){
		 world +=s + Dlim;
	 }

	  return world.substr(0,world.length() - Dlim.length());
  }


  string JoinString(string arrWorld[100],short len, string Dlim) {

	  string world = "";
	  for (short i = 0;i < len;i++) {
		  world += arrWorld[i] + Dlim;
	  }

	  return world.substr(0, world.length() - Dlim.length());
  }

  string RevercesWorldInString(string s){


	 vector<string> vWorld = SplitString(s," ");
	 string w = "";

	 vector<string>::iterator iter = vWorld.end();
	 while(iter != vWorld.begin()){
	 
		 --iter;
		 w += *iter + " ";
	 }

	 

	 return Trim(w);
  }

  enum enWathToMatchCase {
	  MatchCase = 0,NotMatchCase=1,AllMatch=2
  };

  string  ReplaceWordInStringUsingBuiltInFunction(string s, string Wold, string Wnew) {
     
	  short po = s.find(Wold);

	  while(po != std::string::npos){
	  
		  s = s.replace(po, Wold.length(), Wnew);
		  po = s.find(Wold);
	  
	  }
	  return s;
     
  }

  vector<string> UpdateStringVector(vector<string>& vstring, string Wold, string Wnew,bool matchcas){
	 
	  for(string &s:vstring){

		  if (matchcas) {
			  if (s == Wold){
				  s = Wnew;
			  }
		  }
		  else {
			  if(LowerAllString(s) == LowerAllString(Wold)){
				  s = Wnew;
			  }

		  }
	

	  }
	  return vstring;
  
  }

  string  ReplaceWordInStringUsingSplitString(string s, string Wold, string Wnew,bool Matchcase=true) {

	  vector<string>vstring = SplitString(s, " ");
	
	  if (MatchCase) {
		 
		 return  JoinString(UpdateStringVector(vstring, Wold, Wnew, Matchcase)," ");
	  }
	  else {
		  return JoinString(UpdateStringVector(vstring, Wold, Wnew, Matchcase), " ");
	      }
  
  
  }
	
  bool IsPunctuations(char c) {
	  return ispunct(c);

  }


  string  RemovePunctuationsFromString(string s) {
	  string w = "";
	  for (short i = 0;i < s.length();i++) {
	  
	  if(!IsPunctuations(s[i])) {
	  
		  w += s[i];
	  }
	

	  }

	  return w;

  }


  }


      

        