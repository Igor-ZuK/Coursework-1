#include "utils.h"

using namespace std;

//----------UTILS-----------!

int input_number(const char* text, int length_limit, bool anti_zero_flag)
{
	// функция проверки на ввод только цифр(как положительных, так и отрицательных)

	const char BACKSPACE = 8; // символ, который соотвествует кнопки BACKSPACE
	const char RETURN = 13; // символ, который соотвествует вводу

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
	//функция ввода double
	double a;

	cout << text;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Тип введённого значения не соотвествует ожидаемуму\n";
		cout << ">";
	}
	return a;
}

string input_article()
{
	// функция ввода артикля обуви
	string current_article;
	articleMenu();
	switch (choiceMenuItem(1, 3))
	{
	case 1: current_article = "М"; break;
	case 2: current_article = "Ж"; break;
	case 3: current_article = "Д"; break;
	default: cout << "Некорректный ввод" << endl;
		break;
	}
	return current_article;
}

string create_login(vector <Account> vec_of_accouts)
{
	// функция создания уникального логина
	int num_of_matches;
	string login;
	while (1) {
		system("cls");
		num_of_matches = 0;

		cout << "Придумайте логин >"; cin >> login;
		for (int i = 0; i < vec_of_accouts.size(); ++i) {
			if (login == vec_of_accouts.at(i).login) num_of_matches++;
		}

		if (!num_of_matches) return login;
		cout << "[Пользователь с таким логином уже существует]" << endl;
		Sleep(1500);
	}
}

string generateHash(string password, string salt) {
	// функция генерации хеша с солью( по умолчанию salt = "OKPprog" )
	string hash = sha256(sha256(password + salt) + sha256(password));
	return hash;
}

string swapSpaceToDownSpace(string str, char check_char, char change_char)
{
	// функция замены ( по умолчанию заменяются пробелы на _ )  
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == check_char) {
			str[i] = change_char;
		}
	}
	return str;
}

string getPassword(const char* text, bool show_asterisk)
{
	/* функция получения пароля
	show_asterisk определяет выводить ли * или нет(по умолчанию true)*/
	const char BACKSPACE = 8; // символ, который соотвествует кнопки BACKSPACE
	const char RETURN = 13; // символ, который соотвествует вводу 

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
	if (password.length() < 4) // проверка длины пароля
	{
		/* если длина введённая пользователем меньше 4,
		вывод подсказки и рекурсивный запрос на получение нового пароля*/
		cout << "   [Длина не может быть меньше 4]";
		cout << "\n";
		return getPassword(text);
	}
	cout << endl;
	return password;
}

int choiceMenuItem(int left_limit, int right_limit)
{
	/* функция выбора элемента из меню
	left_limit и right_limit определяют диапозон для проверки*/
	int user_choice;
	cout << "\n>";
	while (1) {
		user_choice = input_number("", 1);

		if (user_choice >= left_limit and user_choice <= right_limit) return user_choice;
		cout << "\b \b";
	}
}

//----------UTILS-----------#