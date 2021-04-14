#include "admin_func.h"

using namespace std;


//---------------ADMIN_FUNC----------------------!

void addBoots(vector<Boots>& vec_of_boots)
{
	showBootsData(vec_of_boots);

	cout << "\n\n1 | Добавить\n0 - Выйти" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		Boots new_boot_pair;
		rewind(stdin); // очистка потока ввода
		cout << "\n\n\nВведите название >"; getline(cin, new_boot_pair.title, '\n');
		rewind(stdin); // очистка потока ввода
		cout << "\nВведите изготовителя >"; getline(cin, new_boot_pair.fabricator, '\n');
		rewind(stdin); // очистка потока ввода
		new_boot_pair.article = input_article();
		new_boot_pair.boot_size = input_number("\nВведите размер >", 2);
		new_boot_pair.price = input_number("\nВведите цену >", 6);
		new_boot_pair.num_of_pairs = input_number("\nВведите кол-во пар >", 3);
		vec_of_boots.push_back(new_boot_pair);
		writeEndFileBoots(new_boot_pair);

		showBootsData(vec_of_boots);
		Sleep(500);
	}
	break;
	case 0: return;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}

}

void delBoots(vector<Boots>& vec_of_boots)
{
	showBootsData(vec_of_boots);

	cout << "\n\n1 | Удалить\n0 - Выйти" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int number_of_deleted_item = input_number("\nВведите номер удаляемой записи >");
		number_of_deleted_item--; // отсчёт начинается с 1
		// проверка на корректность
		if (number_of_deleted_item >= 0 && number_of_deleted_item < vec_of_boots.size()) {
			vec_of_boots.erase(vec_of_boots.begin() + number_of_deleted_item);
			writeFileBoots(vec_of_boots);
		}
		else cout << "Введён некоректный номер удаляемой записи" << endl;

		showBootsData(vec_of_boots);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

void editBootsInterface(vector<Boots>& vec_of_boots, int number_of_change)
{
	// меню изменения полей Обуви
	string update_str;
	int user_choice = choiceMenuItem(0, 6);

	system("cls");
	switch (user_choice)
	{
	case 1: cout << "\n\nВведите новое название >"; rewind(stdin); getline(cin, update_str, '\n');
		rewind(stdin);
		vec_of_boots.at(number_of_change).title = swapSpaceToDownSpace(update_str);
		system("pause");
		break;
	case 2: cout << "Укажите изготовителя >"; rewind(stdin); getline(cin, update_str, '\n');
		rewind(stdin);
		vec_of_boots.at(number_of_change).fabricator = swapSpaceToDownSpace(update_str);
		system("pause");
		break;
	case 3: vec_of_boots.at(number_of_change).article = input_article();
		system("pause");
		break;
	case 4: vec_of_boots.at(number_of_change).price = input_double("Укажите цену обуви за пару >");
		system("pause");
		break;
	case 5: vec_of_boots.at(number_of_change).boot_size = input_number("Введите размер обуви >", 2);
		system("pause");
		break;
	case 6: vec_of_boots.at(number_of_change).num_of_pairs = input_number("Укажите кол-во пар на складе >", 3);
		system("pause");
		break;
	default:
		break;
	}
}

void editBoots(vector<Boots>& vec_of_boots)
{
	// функция редактирования полей Обуви
	showBootsData(vec_of_boots);

	cout << "\n\n1 | Изменить\n0 - Выйти" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int number_of_change = input_number("\n\n\t\t\tВведите номер изменяемой записи >");
		number_of_change--; // отсчёт начинается с 1

		system("cls");
		// проверка на корректность
		if (number_of_change >= 0 && number_of_change < vec_of_boots.size()) {
			editBootsMenu();
			editBootsInterface(vec_of_boots, number_of_change);
		}
		else cout << "Введён некорректный номер удаляемой записи" << endl;

		showBootsData(vec_of_boots);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

void addAccount(vector<Account>& vec_of_accounts)
{
	// функция добавления аккаунта
	showAccountsTableTitle();
	showAccountsData(vec_of_accounts);

	cout << "\n\n1 | Добавить\n0 | Выйти" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int kod;
		Account new_account;

		cout << endl;
		new_account.login = create_login(vec_of_accounts);
		new_account.password = generateHash(getPassword("Введите пароль >"));
		cout << "> Укажите роль <" << endl;
		cout << "0 | Пользователь\n1 | Администратор" << endl;
		kod = input_number(">", 1);
		switch (kod)
		{
		case 0: new_account.role = kod; break;
		case 1: new_account.role = kod; break;
		default:
			cout << "Введено некорректное значение!\nПрисвоена роль Пользователя" << endl;
			new_account.role = 0;
			break;
		}
		new_account.access = 1;
		vec_of_accounts.push_back(new_account);
		writeEndFileAccounts(new_account);

		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

void delAccount(vector<Account>& vec_of_accounts)
{
	// функция удаления аккаунта
	showAccountsData(vec_of_accounts);

	cout << "\n\n1 | Удалить\n0 | Выйти" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int number_of_deleted_item = input_number("\nВведите номер удаляемой записи >");
		number_of_deleted_item--; // отсчёт начинается с 1
		// проверка на корректность
		if (number_of_deleted_item >= 0 && number_of_deleted_item < vec_of_accounts.size()) {
			vec_of_accounts.erase(vec_of_accounts.begin() + number_of_deleted_item);
			writeFileAccounts(vec_of_accounts);
		}
		else cout << "Введён некоректный номер удаляемой записи" << endl;

		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

void changeUserRole(vector<Account>& vec_of_accounts, int number_of_change)
{
	// функция изменения роли аккаунта(Админ либо Пользователь)
	userRoleMenu();

	switch (choiceMenuItem(0, 2))
	{
	case 0: vec_of_accounts.at(number_of_change).role = 0; return;
	case 1: vec_of_accounts.at(number_of_change).role = 1; return;
	default:
		break;
	}
}

void editAccountsInterface(vector<Account>& vec_of_accounts, int number_of_change)
{
	// меню редактирования полей аккаунта
	int user_choice = choiceMenuItem(0, 4);

	system("cls");
	switch (user_choice)
	{
	case 1: cout << "\nВведите новый логин >"; cin >> vec_of_accounts.at(number_of_change).login;
		system("pause");
		break;
	case 2: vec_of_accounts.at(number_of_change).password = getPassword("Введите новый пароль >");
		system("pause");
		break;
	case 3:
		changeUserRole(vec_of_accounts, number_of_change);
		system("pause");
		break;
	case 4:
		userAccessMenu();
		vec_of_accounts.at(number_of_change).access = choiceMenuItem(1, 2);
		system("pause");
		break;
	case 0: return;
	default:
		break;
	}
}

void editAccount(vector<Account>& vec_of_accounts)
{
	// функция редактирования полей аккаунта
	showAccountsTableTitle();
	showAccountsData(vec_of_accounts);

	cout << "\n\n1 | Изменить\n0 | Выйти" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);

		int number_of_change = input_number("\nВведите номер изменяемой записи >");
		number_of_change--; // отсчёт начинается с 1

		// проверка на корректность 
		if (number_of_change >= 0 && number_of_change < vec_of_accounts.size()) {
			editAccountsMenu();
			editAccountsInterface(vec_of_accounts, number_of_change);
		}
		else cout << "Введён некорректный номер удаляемой записи" << endl;

		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

void showAccountsInterface(vector<Account>& vec_of_accounts)
{
	// функция вывода всех аккаунтов из БД, сортировка, поиск определённого 
	while (1) {
		showAccountsData(vec_of_accounts);
		displayAccountsViewMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: searchAccountsInterface(vec_of_accounts); break;
		case 2:	sortAccountsInterface(vec_of_accounts); break;
		case 0: return;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

void cancelRequestForReg(vector<Account>& vec_of_accounts)
{
	// функция отклонения запроса на регистрацию

	showAccountsForReg(vec_of_accounts);
	int id = input_number("\nВведите ID отклоняемого запроса | 0 - Назад\n>");

	if (id == 0) return;

	system("cls");
	showAccountsTableTitle();

	id--; // отсчёт начинается с 1

	consoleOutAccount(vec_of_accounts.at(id), id); // вывод отклоняемого аккаунта

	cout << "> Вы действительно хотите отклонить данный запрос? Отменить это действие будет невозможно <" << endl;
	cout << "1 | Да\n2 | Нет";
	switch (choiceMenuItem(1, 2))
	{
	case 1:
	{
		// проверка на корректность
		if (id > 0 && id < vec_of_accounts.size()) {
			vec_of_accounts.erase(vec_of_accounts.begin() + id);
			writeFileAccounts(vec_of_accounts);
		}
		else cout << "Введено недопустимое значение" << endl;
		// обратная связь с пользователем
		cout << "\n> Запрос на регистрацию отклонён <" << endl;
		system("pause");
	}
	break;
	case 2: break;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

void acceptRequestForReg(vector<Account>& vec_of_accounts)
{
	// функция подтверждения регистрации

	showAccountsForReg(vec_of_accounts);

	int id = input_number("\nВведите ID принимаемого запроса | 0 - Назад\n>");
	if (id == 0) return;

	id--; // отсчёт начинается с 1
	system("cls");
	showAccountsTableTitle();
	consoleOutAccount(vec_of_accounts.at(id), id);

	// обратная свзяь с админом
	cout << "\n\n> Вы действительно хотите принять данный запрос? Отменить это действие будет невозможно <" << endl;
	cout << "1 | Да\n2 | Нет";
	switch (choiceMenuItem(1, 2))
	{
	case 1:
	{
		// проверка на ввод
		if (id > 0 && id < vec_of_accounts.size()) {
			vec_of_accounts.at(id).access = 1; // изменяем доступ с "Ожидает" на "Полный"
			writeFileAccounts(vec_of_accounts); // перезаписываем БД
		}
		else cout << "Введено недопустимое значение" << endl;

		// обратная связь с пользователем
		system("cls");
		cout << "> Пользователь зарегистрирован <";
		Sleep(500);
	}
	break;
	case 2: break;
	default:
		cout << "Некорректный ввод" << endl;
		break;
	}
}

//---------------ADMIN_FUNC----------------------#
