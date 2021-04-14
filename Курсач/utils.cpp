#include "utils.h"

using namespace std;

//----------UTILS-----------!

int input_number(const char* text, int length_limit, bool anti_zero_flag)
{
	// ������� �������� �� ���� ������ ����(��� �������������, ��� � �������������)

	const char BACKSPACE = 8; // ������, ������� ������������ ������ BACKSPACE
	const char RETURN = 13; // ������, ������� ������������ �����

	string s;
	char ch;
	cout << text;
	while (1) {
		ch = _getch();
		if (anti_zero_flag && s.length() == 0 && ch == '0') continue;
		if (ch == RETURN && s.length() != 0) break;
		if (ch == BACKSPACE && s.length() != 0) {
			cout << "\b \b";
			s.resize(s.length() - 1);
		}
		if (!(ch >= '0' && ch <= '9')) continue;
		if (s.length() < length_limit) {
			cout << ch;
			s += ch;
		}
	}
	return stoi(s);
}

double input_double(const char* text)
{
	//������� ����� double
	double a;

	cout << text;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "��� ��������� �������� �� ������������ ����������\n";
		cout << ">";
	}
	return a;
}

string input_article()
{
	// ������� ����� ������� �����
	string current_article;
	articleMenu();
	switch (choiceMenuItem(1, 3))
	{
	case 1: current_article = "�"; break;
	case 2: current_article = "�"; break;
	case 3: current_article = "�"; break;
	default: cout << "������������ ����" << endl;
		break;
	}
	return current_article;
}

string create_login(vector <Account> vec_of_accouts)
{
	// ������� �������� ����������� ������
	int num_of_matches;
	string login;
	while (1) {
		system("cls");
		num_of_matches = 0;

		cout << "���������� ����� >"; cin >> login;
		for (int i = 0; i < vec_of_accouts.size(); ++i) {
			if (login == vec_of_accouts.at(i).login) num_of_matches++;
		}

		if (!num_of_matches) return login;
		cout << "[������������ � ����� ������� ��� ����������]" << endl;
		Sleep(1500);
	}
}

string generateHash(string password, string salt) {
	// ������� ��������� ���� � �����( �� ��������� salt = "OKPprog" )
	string hash = sha256(sha256(password + salt) + sha256(password));
	return hash;
}

string swapSpaceToDownSpace(string str, char check_char, char change_char)
{
	// ������� ������ ( �� ��������� ���������� ������� �� _ )  
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == check_char) {
			str[i] = change_char;
		}
	}
	return str;
}

string getPassword(const char* text, bool show_asterisk)
{
	/* ������� ��������� ������
	show_asterisk ���������� �������� �� * ��� ���(�� ��������� true)*/
	const char BACKSPACE = 8; // ������, ������� ������������ ������ BACKSPACE
	const char RETURN = 13; // ������, ������� ������������ ����� 

	string password;
	char ch = 0;

	cout << text;

	while ((ch = _getch()) != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (password.length() != 0)
			{
				if (show_asterisk)
					cout << "\b \b";
				password.resize(password.length() - 1);
			}
		}
		else if (ch == 0 || ch == 224) // handle escape sequences
		{
			_getch(); // ignore non printable chars
			continue;
		}
		else
		{
			password += ch;
			if (show_asterisk)
				cout << '*';
		}
	}
	if (password.length() < 4) // �������� ����� ������
	{
		/* ���� ����� �������� ������������� ������ 4,
		����� ��������� � ����������� ������ �� ��������� ������ ������*/
		cout << "   [����� �� ����� ���� ������ 4]";
		cout << "\n";
		return getPassword(text);
	}
	cout << endl;
	return password;
}

int choiceMenuItem(int left_limit, int right_limit)
{
	/* ������� ������ �������� �� ����
	left_limit � right_limit ���������� �������� ��� ��������*/
	int user_choice;
	cout << "\n>";
	while (1) {
		user_choice = input_number("", 1);

		if (user_choice >= left_limit and user_choice <= right_limit) return user_choice;
		cout << "\b \b";
	}
}

//----------UTILS-----------#