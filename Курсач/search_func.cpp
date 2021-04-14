#include "search_func.h"

using namespace std;

//----------SEARCH_FUNC----------!

void searchByPrice(vector<Boots> vec_of_boots)
{
	/* поиск обуви по цене
	Вводится диапозон цены*/
	system("cls");
	double bottom_price, top_price;
	cout << "> Введите диапозон цен <" << endl;
	bottom_price = input_number("> Нижняя граница цены < | >", 6);
	top_price = input_number("\n> Верхняя граница цены < | >", 6);

	if (bottom_price <= top_price) {
		showBootsTableTitle();
		for (int i = 0; i < vec_of_boots.size(); ++i) {
			if (vec_of_boots.at(i).price >= bottom_price && vec_of_boots.at(i).price <= top_price) {
				consoleOutBoot(vec_of_boots.at(i), i);
			}
		}
		system("pause");
	}
}

void searchByBootsSize(vector<Boots> vec_of_boots)
{
	// поиск обуви по размеру
	system("cls");
	int current_boot_size = input_number("> Введите необходимый размер < | >", 2);

	showBootsTableTitle();
	for (int i = 0; i < vec_of_boots.size(); ++i) {
		if (vec_of_boots.at(i).boot_size == current_boot_size) {
			consoleOutBoot(vec_of_boots.at(i), i);
		}
	}
	system("pause");
}

void searchByArticle(vector<Boots> vec_of_boots)
{
	// поиск Обуви по артиклю
	system("cls");
	string current_article = input_article();
	showBootsTableTitle();
	for (int i = 0; i < vec_of_boots.size(); ++i) {
		if (vec_of_boots.at(i).article == current_article) {
			consoleOutBoot(vec_of_boots.at(i), i);
		}
	}
	system("pause");
}

void searchByTask(vector<Boots> vec_of_boots)
{
	// выполнение индивидуального задания
	system("cls");
	string current_article = input_article();
	int current_size = input_number("\n> Введите необходимый размер < | >", 2);

	system("cls");
	showBootsTableTitle();
	for (int i = 0; i < vec_of_boots.size(); ++i) {
		if (vec_of_boots.at(i).article == current_article && vec_of_boots.at(i).boot_size == current_size) {
			consoleOutBoot(vec_of_boots.at(i), i);
		}
	}
	// обратная связь с пользователем
	cout << "\n\n> По вашему запросу нашлось <";
	cout << "\n\n> Нажмите, чтобы продолжить <";
	if (_getch()) return;
}

void searchBootsInterface(vector<Boots> vec_of_boots)
{
	// меню поиска Обуви
	while (1) {
		displayBootsSearchMenu();
		switch (choiceMenuItem(0, 4))
		{
		case 1: searchByPrice(vec_of_boots); break;
		case 2: searchByBootsSize(vec_of_boots); break;
		case 3: searchByArticle(vec_of_boots); break;
		case 4: searchByTask(vec_of_boots); break;
		case 0: return;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

void searchAccountByLogin(vector<Account> vec_of_accounts)
{
	// поиск аккаунта по его логину
	system("cls");
	string current_login;
	cout << "> Введите логин для поиска < | >"; cin >> current_login;
	showAccountsTableTitle();
	for (int i = 0; i < vec_of_accounts.size(); ++i) {
		if (vec_of_accounts.at(i).login == current_login) {
			consoleOutAccount(vec_of_accounts.at(i), i);
		}
	}
	system("pause");
}

void searchAccountByRole(vector<Account> vec_of_accounts)
{
	// поиск аккаунта по роли(Админ, Пользователь)
	while (1) {
		system("cls");
		userRoleMenu();
		int current_role = choiceMenuItem(0, 2);
		showAccountsTableTitle();
		for (int i = 0; i < vec_of_accounts.size(); ++i) {
			if (vec_of_accounts.at(i).role == current_role) {
				consoleOutAccount(vec_of_accounts.at(i), i);
			}
		}
	}
	system("pause");
}

void searchAccountsInterface(vector<Account> vec_of_accounts)
{
	// меню поиска Аккаунта
	while (1) {
		displayAccountSearchMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: searchAccountByLogin(vec_of_accounts); return;
		case 2: searchAccountByRole(vec_of_accounts); return;
		case 0: return;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

//----------SEARCH_FUNC----------#