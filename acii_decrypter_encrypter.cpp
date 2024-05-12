#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void helper(string path);

int main()
{
	cout << "\n~ The path to the \".txt\" file: ";
	string path;
	cin >> path;
	helper(path);
	cin.get():
	return 0;
}
void helper(string path)
{
	ifstream in(path.c_str());
	if (!in)
	{
		cerr << "\n!!! Error opening file, the path is incorrect. Try again\n";
		main();
		return;
	}
	char ch;
	cout << "\n~ Encrypt or decrypt? (e | d): ";
	cin >> ch;
	string name;
	if (ch == 'e') {
		name = path.substr(0, path.find_last_of('.')) + "_encrypted.txt";
		ofstream out(name.c_str());
		char ch;
		while (in >> noskipws >> ch)
		{
			out << int(ch) << ' ';
		}
		out.close();
	}
	else if (ch == 'd')
	{
		name = path.substr(0, path.find_last_of('.')) + "_decrypted.txt";
		ofstream out(name.c_str());
		int i;
		while (in >> i)
		{
			out << char(i);
		}
		out.close();
	}
	else
	{
		cerr << "\n!!! Please type \"e\" to encrypt or \"d\" to decrypt selected file\n";
		helper(path);
		return;
	}
	cout << "\n~ You processed file is here: " << name << endl;
}
