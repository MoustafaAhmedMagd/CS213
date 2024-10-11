#include<iostream>
#include<fstream>
#include<filesystem>
#include<sstream>
#include <string>
#include<utility>
#include <unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
void play_again();

// Name: Mostafa Ahmed Magd Ali 
// Id: 20230551 
// Assignment 1 
// Task 1 
// Problem_Set 2 
// Number of the problem: 2

string processWord(const string& word) {
	unordered_map<string, string> replacements = {
		{"him", "him or her"},
		{"her", "her or him"},
		{"hers", "hers or his"},
		{"his", "his or hers"},
		{"he", "he or she"},
		{"she", "she or he"},
		{"Him", "Him or her"},
		{"Her", "Her or him"},
		{"herself", "herself or himself"},
		{"himself", "himself or herself"},
		{"He", "He or she"},
		{"She", "She or he"}
	};

	string baseWord = word;
	string specialChars = "";

	// Separate special characters
	while (!baseWord.empty() && ispunct(baseWord.back()) ) {
		specialChars = baseWord.back() + specialChars;
		baseWord.pop_back();
	}

	// Check for replacement
	if (replacements.find(baseWord) != replacements.end()) {
		return replacements[baseWord] + specialChars;
	}
	return word;
}
void problem2() {
		string sentence;
		cout << "Please enter any sentence to make it male and female: ";
		getline(cin, sentence);
		stringstream sentence_copy(sentence);
		string word_detect;

		while (sentence_copy >> word_detect) {
			cout << processWord(word_detect) << " ";
		}
	play_again();
}



// Name: Mostafa Ahmed Magd Ali 
// Id: 20230551 
// Assignment 1 
// Task 1 
// Problem_Set 2 
// Number of the problem: 5
vector<pair<int, string>> vector_players;
void play();
void processing(int&);
void problem5() {
    cout << "Hi, the program will provide many options: " << "\n";
    play();
	play_again();
}
void play() {
	int choice;
	cout << "1) Add new player: press 1 to choose it " << "\n";
	cout << "2) Print top 10 names and scores sorted with the highest score first: press 2 to choose it  " << "\n";
	cout << "3) You can also check your favourite player to see if they are in the top 10 or not: press 3 to choose it " << "\n";
	cout << "4) Go to the main menu and exit this service: press 4 to choose it " << "\n\n";

	cout << "Please enter your choice: ";
	cin >> choice;
	cout << "\n";
	processing(choice);
}
void processing(int& choice)
{
	pair<int, string> Player;
	if (choice == 1)
	{
		cout << "Please enter the score followed by the name of the player: ";
		cin >> Player.first >> Player.second;
		if (vector_players.size() < 10) {
			vector_players.emplace_back(Player);
		}
		else
		{
			if (vector_players.back().first < Player.first)
			{
				vector_players.pop_back();
				vector_players.emplace_back(Player);
			}
		}
		if (vector_players.size() >= 2)
		{
			sort(vector_players.begin(), vector_players.end(), greater<>());
		}
		play();
	}
	else if (choice == 2)
	{
		for (const auto& x : vector_players)
		{
			cout << x.second << " " << x.first << "\n";
		}
		play();
	}
	else if (choice == 3)
	{
		string player_name;
		cout << "Please enter the name of the player you want to look for: ";
		cin >> player_name;
		for (const auto& x : vector_players)
		{
			if (x.second == player_name)
			{
				cout << x.second << " " << x.first << "\n";
				play();
			}
		}
		cout << "There is no such player in the top 10 players" << "\n";
		play();
	}
	else
	{
		cout << "Goodbye!" << "\n";
	}
}


// Name: Mostafa Ahmed Magd Ali 
// Id: 20230551 
// Assignment 1 
// Task 1 
// Problem_Set 2 
// Number of the problem: 8
int validty_checker(int what_I_check) {
	while (true)
	{
		if (what_I_check <= 0)
		{
			cout << "Not valid value !!! Please enter the number of the stars in the longest row: "; cin >> what_I_check; cout << "\n";
		}
		else
		{
			break;
		}
	}
	return what_I_check;
}
int validty_checker2(int what_I_check) {
	while (true)
	{
		if (what_I_check < 0)
		{
			cout << "Not valid value !!! Please enter the number of the stars in the longest row: "; cin >> what_I_check; cout << "\n";
		}
		else
		{
			break;
		}
	}
	return what_I_check;
}
int log(int operations) {
	static int counter1 = 0;
	if (operations!=1)
	{
		operations = log(operations / 2);
		counter1++;
	}


	return counter1;
}
void print_struct_space(int space) {
	for (int i = 0; i < space; i++)
	{
		cout << " ";
	}
}
void print_line(int astric){
	for (int i = 0; i < astric; i++)
	{
		cout << "* ";
	}
	cout << "\n";
}
void print_specific_line(int astric, int column) {
	for (int i = 0; i < column; i++)
	{
		cout << " ";
	}
	for (int i = 0; i < astric; i++)
	{
		cout << "* ";
	}
	cout << "\n";
}
void recursion_ans(int operations, int spaces) {
	static int counter = operations+(operations-2);
	static int final_counter = counter + counter - 1;
	static int counter_copy = (final_counter / 2) + 1; if (counter_copy % 2 != 0)counter_copy -= 1;
	static int counter_spaces = 0;
	static int counter_astric_power = 2;
	static int astrics_num = (int)pow(2, counter_astric_power);
	if (final_counter>=1)
	{
		if (final_counter % 2 == 1)
		{
			print_struct_space(counter_spaces+spaces);
			cout << "*"<<"\n";
			print_struct_space(counter_spaces + spaces);
			cout << "* *" << "\n";
			print_struct_space(counter_spaces + spaces);
			cout << "  *" << "\n";

		}
		else {
			if ((final_counter)==(counter_copy))
			{
				print_specific_line(astrics_num,spaces);
				counter_spaces += 4;
				counter_astric_power--;
				astrics_num = (int)pow(2, counter_astric_power);
			}
			else if ((final_counter ) < (counter_copy))
			{
				print_struct_space(counter_spaces + spaces);
				print_line(astrics_num);
				counter_spaces += 4;
				counter_astric_power--;
				astrics_num = (int)pow(2, counter_astric_power);
			}
			else {
				print_struct_space(counter_spaces + spaces);
				print_line(astrics_num);
				counter_spaces += 4;
				counter_astric_power++;
				astrics_num = (int)pow(2, counter_astric_power);
			}

		}
		final_counter--;
		counter--;
		recursion_ans(operations,spaces);

	}
}
void problem8() {
	int the_number_of_the_longest_star_line;
	int which_column_longest_star_line_start_with;
	cout << "Please enter the number of the stars in the longest row: ";  cin >> the_number_of_the_longest_star_line; cout << "\n";
	the_number_of_the_longest_star_line = validty_checker(the_number_of_the_longest_star_line);
	cout << "Please enter which column that longest row will start with: "; cin >> which_column_longest_star_line_start_with; cout << "\n";
	which_column_longest_star_line_start_with = validty_checker2(which_column_longest_star_line_start_with);
	if (the_number_of_the_longest_star_line==2)
	{
		print_struct_space(which_column_longest_star_line_start_with);
		cout << "*" << "\n";
		print_struct_space(which_column_longest_star_line_start_with);
		cout << "* *" << "\n";
		print_struct_space(which_column_longest_star_line_start_with);
		cout << "  *" << "\n";
	}
	else if(the_number_of_the_longest_star_line==1){
		print_struct_space(which_column_longest_star_line_start_with);
		cout << "*" << "\n";
	}
	else
	{
	the_number_of_the_longest_star_line = log(the_number_of_the_longest_star_line);
	if (the_number_of_the_longest_star_line==0)
	{
		cout << "sdjfis";
	}
	else { recursion_ans(the_number_of_the_longest_star_line, which_column_longest_star_line_start_with); }
	}

	play_again();
}



// Name: Mostafa Ahmed Magd Ali 
// Id: 20230551 
// Assignment 1 
// Task 1 
// Problem_Set 2 
// Number of the problem: 11
bool is_file_opened(string&, string&,ifstream&, ifstream&);
void compare(ifstream&, ifstream& , int&);
void processing(ifstream&, ifstream&, int&, int&, string&, string&, string&, string&, istringstream&, istringstream&);
void again(string& , string&);
void engage(string& file1,string& file2) {
	again(file1,file2);
}
void problem11() 
{
	string file1, file2;
	cout << "Hi my dear user hope your day is great, This service is very good if you want to compare between two files" << "\n" <<
		" and you genuinly have two options first is to compare them by word if you search about consice comparison and" << "\n" <<
		" the second is to compare them by word this will be less persice which will ignore any space or special characters in the comparison."
		<< "\n\n" << "please my dear user take a look on this important note: the program can not compare any file with no txt extension" << "\n" << " beacause of some format issues ." << "\n\n" <<
		"we hope to fix this later" << "\n\n";
	cout << "please input the name of the first file: "; getline(cin, file1);
	cout << "please enter the name of the second one : "; getline(cin, file2);
	again(file1, file2);
	play_again();

}
bool is_file_opened(string& file1, string &file2, ifstream& File1, ifstream& File2) {
	bool flag1 = false;
	bool flag2 = false;
	File1.open(file1);
	if (File1.is_open()) flag1 = true;
	while (flag1==false) {
		cout << "sorry but there is no file with that name or directory or format for the first file" << "\n\n" << "please enter the name of the first file with the path and extension again: ";
		getline(cin,file1);
		File1.open(file1);
		if (File1.is_open()) flag1=true;
	}
	cout << "\n";
	File2.open(file2);
	if (File2.is_open()) flag2 = true;
	while (flag2 == false) {
		cout <<"sorry but there is no file with that name or directory or format for the second file" << "\n\n" << "please enter the name of the second file with the path and extension again: ";
		getline(cin, file2);
		File2.open(file2);
		if (File2.is_open()) flag2= true;
	}
	return 1;
}
void compare(ifstream& File1, ifstream& File2, int& choice) {
	string word_file1, word_file2, line_file1, line_file2;
	int line_counter=1;
	istringstream iss_file1, iss_file2;	
	processing( File1,   File2, choice,  line_counter, word_file1,  word_file2, line_file1,  line_file2,  iss_file1,  iss_file2);

}
void processing(ifstream& File1, ifstream& File2, int& choice, int& line_counter, string& word_file1, string& word_file2, string& line_file1, string& line_file2, istringstream& iss_file1, istringstream& iss_file2) {
	while (getline(File1, line_file1) && getline(File2, line_file2)) {
		iss_file1.clear();
		iss_file2.clear();
		iss_file1.str(line_file1);
		iss_file2.str(line_file2);

		if (choice == 2) {
			for (size_t i = 0; i < line_file1.length() && i < line_file2.length(); ++i) {
				if (line_file1[i] != line_file2[i]) {
					cout << "Line " << line_counter << ": First file character: " << line_file1[i] << " Second file character: " << line_file2[i] << "\n";
				}
			}
		}

		if (choice == 1) {
			while (iss_file1 >> word_file1 && iss_file2 >> word_file2) {
				if (word_file1 != word_file2) {
					cout << "Line " << line_counter << ": First file word: " << word_file1 << " Second file word: " << word_file2 << "\n";
				}
			}
		}
		line_counter++;
	}
}
void again(string& file1, string& file2) {
	int choice, again;
	ifstream File1;
	ifstream File2;
	is_file_opened(file1, file2, File1, File2);
	cout << "The two files are opened successfully" << "\n";
	cout << "would you like to compare the files word by word press 1 if no press 2 and we will consider 2 as char by char: "; cin >> choice;
	cout << "\n";
	compare(File1, File2, choice);
	cout << "do you want to comapar the any another files press 1 if yes 0 if no: "; cin >> again;
	cout << "\n";

	if (again == 1)
	{
		cout << "Ok that is good do you want totally new two txt files or change specific one press 1 if all 0 if specific one: "; cin >> again;
		cout << "\n";

		if (again == 1)
		{
			cout << "please input the new name of the first file: "; getline(cin, file1);
			cout << "please enter the new name of the second one : "; getline(cin, file2);
			engage(file1,file2);
		}
		else if(again ==0){
			cout << "which one do you want to change press 1 for the first one and 2 and for the second one: "; cin >> again;
			if (again==1)
			{
				cout << "please input the new name of the first file: "; getline(cin, file1);
				engage(file1, file2);
			}
			else if (again == 2) {
				cout << "please enter the new name of the second one : "; getline(cin, file2);
				engage(file1, file2);
			}
			else {
				problem11();
			}
		}
		else {
			problem11();
		}
	}
	else {
		File1.close();
		File2.close();
	}
}



void play_again() {
	int choice;
	cout << "\n\n" << "1) Convert any text from male to male and female text" << "\n";
	cout << "2) Make you to 10 players list" << "\n";
	cout << "3) Fractial pattern and fancy world" << "\n";
	cout << "4) Files comparison" << "\n";
	cout << "5) Enough and exit the program" << "\n";
	cout << "Please enter your choice: "; cin >> choice; cin.ignore();
	cout << "\n";
	if (choice == 1)
	{
		problem2();
	}
	else if (choice == 2)
	{
		problem5();

	}
	else if (choice == 3)
	{
		problem8();
	}
	else if (choice==4)
	{
		problem11();
	}
	else if (choice==5)
	{
	}
}
int main() {
	cout << "Hi my dear user welcome to your program that contains four services that can provide it to you: " << "\n\n";
	cout << "So here is the list that contains the four services, please choose one of them by pressing on their number beside each one" << "\n";
	play_again();
	return 0;
}
