#include "admin_func.h"

using namespace std;


//---------------ADMIN_FUNC----------------------!

void addBoots(vector<Boots>& vec_of_boots)
{
	showBootsData(vec_of_boots);

	cout << "\n\n1 | ��������\n0 - �����" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		Boots new_boot_pair;
		rewind(stdin); // ������� ������ �����
		cout << "\n\n\n������� �������� >"; getline(cin, new_boot_pair.title, '\n');
		rewind(stdin); // ������� ������ �����
		cout << "\n������� ������������ >"; getline(cin, new_boot_pair.fabricator, '\n');
		rewind(stdin); // ������� ������ �����
		new_boot_pair.article = input_article();
		new_boot_pair.boot_size = input_number("\n������� ������ >", 2);
		new_boot_pair.price = input_number("\n������� ���� >", 6);
		new_boot_pair.num_of_pairs = input_number("\n������� ���-�� ��� >", 3);
		vec_of_boots.push_back(new_boot_pair);
		writeEndFileBoots(new_boot_pair);

		showBootsData(vec_of_boots);
		Sleep(500);
	}
	break;
	case 0: return;
	default:
		cout << "������������ ����" << endl;
		break;
	}

}

void delBoots(vector<Boots>& vec_of_boots)
{
	showBootsData(vec_of_boots);

	cout << "\n\n1 | �������\n0 - �����" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int number_of_deleted_item = input_number("\n������� ����� ��������� ������ >");
		number_of_deleted_item--; // ������ ���������� � 1
		// �������� �� ������������
		if (number_of_deleted_item >= 0 && number_of_deleted_item < vec_of_boots.size()) {
			vec_of_boots.erase(vec_of_boots.begin() + number_of_deleted_item);
			writeFileBoots(vec_of_boots);
		}
		else cout << "����� ����������� ����� ��������� ������" << endl;

		showBootsData(vec_of_boots);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}

void editBootsInterface(vector<Boots>& vec_of_boots, int number_of_change)
{
	// ���� ��������� ����� �����
	string update_str;
	int user_choice = choiceMenuItem(0, 6);

	system("cls");
	switch (user_choice)
	{
	case 1: cout << "\n\n������� ����� �������� >"; rewind(stdin); getline(cin, update_str, '\n');
		rewind(stdin);
		vec_of_boots.at(number_of_change).title = swapSpaceToDownSpace(update_str);
		system("pause");
		break;
	case 2: cout << "������� ������������ >"; rewind(stdin); getline(cin, update_str, '\n');
		rewind(stdin);
		vec_of_boots.at(number_of_change).fabricator = swapSpaceToDownSpace(update_str);
		system("pause");
		break;
	case 3: vec_of_boots.at(number_of_change).article = input_article();
		system("pause");
		break;
	case 4: vec_of_boots.at(number_of_change).price = input_double("������� ���� ����� �� ���� >");
		system("pause");
		break;
	case 5: vec_of_boots.at(number_of_change).boot_size = input_number("������� ������ ����� >", 2);
		system("pause");
		break;
	case 6: vec_of_boots.at(number_of_change).num_of_pairs = input_number("������� ���-�� ��� �� ������ >", 3);
		system("pause");
		break;
	default:
		break;
	}
}

void editBoots(vector<Boots>& vec_of_boots)
{
	// ������� �������������� ����� �����
	showBootsData(vec_of_boots);

	cout << "\n\n1 | ��������\n0 - �����" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int number_of_change = input_number("\n\n\t\t\t������� ����� ���������� ������ >");
		number_of_change--; // ������ ���������� � 1

		system("cls");
		// �������� �� ������������
		if (number_of_change >= 0 && number_of_change < vec_of_boots.size()) {
			editBootsMenu();
			editBootsInterface(vec_of_boots, number_of_change);
		}
		else cout << "����� ������������ ����� ��������� ������" << endl;

		showBootsData(vec_of_boots);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}

void addAccount(vector<Account>& vec_of_accounts)
{
	// ������� ���������� ��������
	showAccountsTableTitle();
	showAccountsData(vec_of_accounts);

	cout << "\n\n1 | ��������\n0 | �����" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int kod;
		Account new_account;

		cout << endl;
		new_account.login = create_login(vec_of_accounts);
		new_account.password = generateHash(getPassword("������� ������ >"));
		cout << "> ������� ���� <" << endl;
		cout << "0 | ������������\n1 | �������������" << endl;
		kod = input_number(">", 1);
		switch (kod)
		{
		case 0: new_account.role = kod; break;
		case 1: new_account.role = kod; break;
		default:
			cout << "������� ������������ ��������!\n��������� ���� ������������" << endl;
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
		cout << "������������ ����" << endl;
		break;
	}
}

void delAccount(vector<Account>& vec_of_accounts)
{
	// ������� �������� ��������
	showAccountsData(vec_of_accounts);

	cout << "\n\n1 | �������\n0 | �����" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		int number_of_deleted_item = input_number("\n������� ����� ��������� ������ >");
		number_of_deleted_item--; // ������ ���������� � 1
		// �������� �� ������������
		if (number_of_deleted_item >= 0 && number_of_deleted_item < vec_of_accounts.size()) {
			vec_of_accounts.erase(vec_of_accounts.begin() + number_of_deleted_item);
			writeFileAccounts(vec_of_accounts);
		}
		else cout << "����� ����������� ����� ��������� ������" << endl;

		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}

void changeUserRole(vector<Account>& vec_of_accounts, int number_of_change)
{
	// ������� ��������� ���� ��������(����� ���� ������������)
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
	// ���� �������������� ����� ��������
	int user_choice = choiceMenuItem(0, 4);

	system("cls");
	switch (user_choice)
	{
	case 1: cout << "\n������� ����� ����� >"; cin >> vec_of_accounts.at(number_of_change).login;
		system("pause");
		break;
	case 2: vec_of_accounts.at(number_of_change).password = getPassword("������� ����� ������ >");
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
	// ������� �������������� ����� ��������
	showAccountsTableTitle();
	showAccountsData(vec_of_accounts);

	cout << "\n\n1 | ��������\n0 | �����" << endl;
	switch (choiceMenuItem(0, 1))
	{
	case 1:
	{
		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);

		int number_of_change = input_number("\n������� ����� ���������� ������ >");
		number_of_change--; // ������ ���������� � 1

		// �������� �� ������������ 
		if (number_of_change >= 0 && number_of_change < vec_of_accounts.size()) {
			editAccountsMenu();
			editAccountsInterface(vec_of_accounts, number_of_change);
		}
		else cout << "����� ������������ ����� ��������� ������" << endl;

		system("cls");
		showAccountsTableTitle();
		showAccountsData(vec_of_accounts);
		system("pause");
	}
	break;
	case 0: return;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}

void showAccountsInterface(vector<Account>& vec_of_accounts)
{
	// ������� ������ ���� ��������� �� ��, ����������, ����� ������������ 
	while (1) {
		showAccountsData(vec_of_accounts);
		displayAccountsViewMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: searchAccountsInterface(vec_of_accounts); break;
		case 2:	sortAccountsInterface(vec_of_accounts); break;
		case 0: return;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

void cancelRequestForReg(vector<Account>& vec_of_accounts)
{
	// ������� ���������� ������� �� �����������

	showAccountsForReg(vec_of_accounts);
	int id = input_number("\n������� ID ������������ ������� | 0 - �����\n>");

	if (id == 0) return;

	system("cls");
	showAccountsTableTitle();

	id--; // ������ ���������� � 1

	consoleOutAccount(vec_of_accounts.at(id), id); // ����� ������������ ��������

	cout << "> �� ������������� ������ ��������� ������ ������? �������� ��� �������� ����� ���������� <" << endl;
	cout << "1 | ��\n2 | ���";
	switch (choiceMenuItem(1, 2))
	{
	case 1:
	{
		// �������� �� ������������
		if (id > 0 && id < vec_of_accounts.size()) {
			vec_of_accounts.erase(vec_of_accounts.begin() + id);
			writeFileAccounts(vec_of_accounts);
		}
		else cout << "������� ������������ ��������" << endl;
		// �������� ����� � �������������
		cout << "\n> ������ �� ����������� ������� <" << endl;
		system("pause");
	}
	break;
	case 2: break;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}

void acceptRequestForReg(vector<Account>& vec_of_accounts)
{
	// ������� ������������� �����������

	showAccountsForReg(vec_of_accounts);

	int id = input_number("\n������� ID ������������ ������� | 0 - �����\n>");
	if (id == 0) return;

	id--; // ������ ���������� � 1
	system("cls");
	showAccountsTableTitle();
	consoleOutAccount(vec_of_accounts.at(id), id);

	// �������� ����� � �������
	cout << "\n\n> �� ������������� ������ ������� ������ ������? �������� ��� �������� ����� ���������� <" << endl;
	cout << "1 | ��\n2 | ���";
	switch (choiceMenuItem(1, 2))
	{
	case 1:
	{
		// �������� �� ����
		if (id > 0 && id < vec_of_accounts.size()) {
			vec_of_accounts.at(id).access = 1; // �������� ������ � "�������" �� "������"
			writeFileAccounts(vec_of_accounts); // �������������� ��
		}
		else cout << "������� ������������ ��������" << endl;

		// �������� ����� � �������������
		system("cls");
		cout << "> ������������ ��������������� <";
		Sleep(500);
	}
	break;
	case 2: break;
	default:
		cout << "������������ ����" << endl;
		break;
	}
}

//---------------ADMIN_FUNC----------------------#
