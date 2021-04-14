#include "console_output.h"

using namespace std;

//----------CONSOLE_OUTPUT-------!

void showBootsTableTitle()
{
	// заголовок таблицы Обуви
	system("cls");
	cout << "____________________________________________________________________________________________________________________" << endl;
	cout << "|  #  |              Наименование              |     Изготовитель     | Артикул |    Цена    | Размер | Кол-во пар |" << endl;
	cout << "|_____|________________________________________|______________________|_________|____________|________|____________|" << endl;
}

void consoleOutBoot(Boots boot, int i)
{
	// вывод одной пары обуви
	cout << "|" << setw(3) << i + 1 << setw(3)
		<< "|" << setw(25) << swapSpaceToDownSpace(boot.title, '_', ' ') << setw(16)
		<< "|" << setw(12) << swapSpaceToDownSpace(boot.fabricator, '_', ' ') << setw(11)
		<< "|" << setw(5) << boot.article << setw(5)
		<< "|" << setw(8) << boot.price << setw(5)
		<< "|" << setw(5) << boot.boot_size << setw(4)
		<< "|" << setw(7) << boot.num_of_pairs << setw(6)
		<< "|" << endl;
	cout << "|_____|________________________________________|__________"
		<< "____________|_________|____________|________|____________|" << endl;
}

void showBootsData(vector<Boots> vec_of_boots)
{
	// вывод всей обуви
	system("cls");
	showBootsTableTitle();
	for (int i = 0; i < vec_of_boots.size(); ++i) {
		consoleOutBoot(vec_of_boots.at(i), i);
	}
}

void showAccountsTableTitle()
{
	// заголовок таблицы аккаунтов
	system("cls");
	cout << "_________________________________________________________________________________________________________________________________________" << endl;
	cout << "|  ID  |          Логин         |                        Пароль(Хеш + Соль)                      |         Роль       |      Доступ     |" << endl;
	cout << "|______|________________________|________________________________________________________________|____________________|_________________|" << endl;
}

void consoleOutAccount(Account account, int i)
{
	// вывод аккаунта в консоль
	string role_as_str, access_as_str;

	if (account.role == 1)
	{
		role_as_str = "Администратор";
	}
	else
	{
		role_as_str = "Пользователь";
	}

	if (account.access == 1) {
		access_as_str = "Полный";
	}
	else if (account.access == 2) access_as_str = "Заблокирован";
	else role_as_str = "Ожидает";

	// рисуем таблицу
	cout << "|" << setw(3) << i + 1 << setw(4)
		<< "|" << setw(15) << account.login << setw(10)
		<< "|" << setw(1) << account.password << setw(1)
		<< "|" << setw(15) << role_as_str << setw(6)
		<< "|" << setw(13) << access_as_str << setw(5)
		<< "|" << endl;
	cout << "|______|________________________|__________________________"
		<< "______________________________________|____________________|_________________|" << endl;
}

void showAccountsData(vector<Account> vec_of_accounts)
{
	// вывод аккаунтов в векторе, которые уже прошли регистрацию
	showAccountsTableTitle();
	for (int i = 0; i < vec_of_accounts.size(); ++i) {
		if (vec_of_accounts.at(i).access != 0) consoleOutAccount(vec_of_accounts.at(i), i);
	}
}

int showAccountsForReg(vector<Account> vec_of_accounts)
{
	// вывод запросов на регистрацию и их кол-ва 
	int count_of_id = 0;
	showAccountsTableTitle();
	for (int i = 0; i < vec_of_accounts.size(); ++i) {
		if (vec_of_accounts.at(i).access == 0) {
			consoleOutAccount(vec_of_accounts.at(i), i);
			count_of_id++;
		}
	}
	return count_of_id;
}

//----------CONSOLE_OUTPUT-------#