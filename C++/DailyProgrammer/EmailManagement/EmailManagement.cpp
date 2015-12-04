#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

void FixCaseSensitive(string &str){
	for(unsigned int i = 0;i<str.length();i++){
		str[i] = toupper(str[i]);
	}
}
//incase file needs to be read through more than once
void MoveToFileStart(fstream &file){
	file.clear();
	file.seekg(0, ios::beg);
}
//incase file marker isn't at the end of file before writing for whatever reason
void MoveToFileEnd(fstream &file){
	file.seekg(0, ios::end);
}
void WriteToFile(fstream &file, string first, string last, string email, string acc_name){
	MoveToFileEnd(file);
	file << "\n" << first << " " << last << " " << email << " " << acc_name;
}
void PrintFile(fstream &file){
	MoveToFileStart(file);
	string temp;
	while(!file.eof()){
		getline(file, temp);
		cout << temp << endl;
	}
}
bool SearchUsername(fstream &file, string username){
	string temp;
	size_t found;
	MoveToFileStart(file);
	while(!file.eof()){
		getline(file, temp);
		found = temp.find(username);
		if(found != string::npos){
			cout << "Username is taken" << endl;
			return false;
		}
	}
	return true;
}
bool SearchFirstName(fstream &file, string first){
	string temp;
	size_t found;
	MoveToFileStart(file);
	while(!file.eof()){
		getline(file, temp);
		found = temp.find(first);
		if(found != string::npos){
			cout << temp << endl;
			return false;
		}
	}
	return true;
}
bool SearchLastName(fstream &file, string last){
	string temp;
	size_t found;
	MoveToFileStart(file);
	while(!file.eof()){
		getline(file, temp);
		found = temp.find(last);
		if(found != string::npos){
			cout << temp << endl;
			return false;
		}
	}
	return true;
}
bool SearchEmail(fstream &file, string email){
	string temp;
	size_t found;
	MoveToFileStart(file);
	while(!file.eof()){
		getline(file, temp);
		found = temp.find(email);
		if(found != string::npos){
			cout << "Email is already in use" << endl;
			return false;
		}
	}
	return true;
}

bool CheckDomain(string Email_Address){
	string domain = "@dailypro.edu";
	size_t found = Email_Address.find(domain);
	//if domain isn't found in string, return false
	//if it is, check to make sure nothing follows it
	if(found != string::npos){
		Email_Address.replace(found, domain.length(), "@");
		if(Email_Address[Email_Address.length() - 1] != '@'){
			cout << "Email must end with \"@dailypro.edu\"" << endl;
			return false;
		}else return true;
	}else{
		cout << "Email did not contain \"@dailypro.edu\" domain" << endl;
		return false;
	}
}

bool CheckInput(string options[], string user_choice, int arr_size){
	bool valid = false;
	string temp;
	for(int i = 0;i<arr_size;i++){
		//use a temp variable to keep from altering original array
		temp = options[i];
		FixCaseSensitive(temp);
		if(user_choice == temp){
			valid = true;
			break;
		}
	}
	return valid;
}
void GetSearchInput(string options[], string &user_choice, int arr_size){
		do{
			cout << "[";
			for(int i = 0;i < arr_size;i++){
				if(i==0) cout << options[i];
				else cout << "/" << options[i];
			}
			cout << "]: ";
			getline(cin, user_choice);
			//takes string and makes all letters uppercase so that
			//user input doesn't have to be case sensitive
			FixCaseSensitive(user_choice);
		}while(!CheckInput(options, user_choice, arr_size));
}
void SearchFile(fstream &file, string choice){
	string search_value;
	if(choice == "FIRST"){
		cout << "Enter the name to search for: ";
		cin >> search_value;
		SearchFirstName(file, search_value);
	}
	else if(choice == "LAST"){
		cout << "Enter the name to search for: ";
		cin >> search_value;
		SearchLastName(file, search_value);
	}
	else if(choice == "EMAIL"){
		cout << "Enter the email to search for: ";
		cin >> search_value;
		if(CheckDomain(search_value))
			SearchEmail(file, search_value);
	}
	else{
		cout << "Enter the username to search for: ";
		cin >> search_value;
		SearchUsername(file, search_value);
	}
}
int main(){
	fstream accounts_file;
	accounts_file.open("accounts.txt");
	if(accounts_file.fail()){
		cout << "Error opening \"accounts.txt\"" << endl;
	}
	else{
		string choice = "blah";
		string Choice_Set_1[3] = {"search", "new", "print"};
		string Choice_Set_2[4] = {"first", "last", "email", "username"};
		cout << "Would you like to search for something, make a new account, or print the file contents?"
			 << endl;
		GetSearchInput(Choice_Set_1, choice, 3);
		//----------User chose search
		if(choice == "SEARCH"){
			cout << "What would you like to search by?" << endl;
			GetSearchInput(Choice_Set_2, choice, 4);
			SearchFile(accounts_file, choice);
		}

		//----------User chose new entry
		else if(choice == "NEW"){
			string fn, ln, email, username;
			cout << "Enter first name: " << endl;
			cin >> fn;
			cout << "Enter last name: " << endl;
			cin >> ln;
			cout << "Enter email address: " << endl;
			cin >> email;
			cout << "Enter username" << endl;
			cin >> username;
			if(SearchEmail(accounts_file, email) && SearchUsername(accounts_file, username) && CheckDomain(email)){
				cout << "Writing to file.." << endl;
				WriteToFile(accounts_file, fn, ln, email, username);
			}
		}
		//user chose to print file contents
		else PrintFile(accounts_file);
	}
	accounts_file.close();
	return 0;
}