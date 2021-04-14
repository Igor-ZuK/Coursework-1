#include "search_func.h"

using namespace std;

//----------SEARCH_FUNC----------!

void searchByPrice(vector<Boots> vec_of_boots)
{
	/* ����� ����� �� ����
	�������� �������� ����*/
	system("cls");
	double bottom_price, top_price;
	cout << "> ������� �������� ��� <" << endl;
	bottom_price = input_number("> ������ ������� ���� < | >", 6);
	top_price = input_number("\n> ������� ������� ���� < | >", 6);

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
	// ����� ����� �� �������
	system("cls");
	int current_boot_size = input_number("> ������� ����������� ������ < | >", 2);

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
	// ����� ����� �� �������
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
	// ���������� ��������������� �������
	system("cls");
	string current_article = input_article();
	int current_size = input_number("\n> ������� ����������� ������ < | >", 2);

	system("cls");
	showBootsTableTitle();
	for (int i = 0; i < vec_of_boots.size(); ++i) {
		if (vec_of_boots.at(i).article == current_article && vec_of_boots.at(i).boot_size == current_size) {
			consoleOutBoot(vec_of_boots.at(i), i);
		}
	}
	// �������� ����� � �������������
	cout << "\n\n> �� ������ ������� ������� <";
	cout << "\n\n> �������, ����� ���������� <";
	if (_getch()) return;
}

void searchBootsInterface(vector<Boots> vec_of_boots)
{
	// ���� ������ �����
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
			cout << "������������ ����" << endl;
			break;
		}
	}
}

void searchAccountByLogin(vector<Account> vec_of_accounts)
{
	// ����� �������� �� ��� ������
	system("cls");
	string current_login;
	cout << "> ������� ����� ��� ������ < | >"; cin >> current_login;
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
	// ����� �������� �� ����(�����, ������������)
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
	// ���� ������ ��������
	while (1) {
		displayAccountSearchMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: searchAccountByLogin(vec_of_accounts); return;
		case 2: searchAccountByRole(vec_of_accounts); return;
		case 0: return;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

//----------SEARCH_FUNC----------#