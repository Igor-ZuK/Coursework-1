#include "core.h"

using namespace std;

//---------------CORE_FUNC-----------------------!

void userMode(vector<Boots> vec_of_boots)
{
	// ������ ������������. ������������ ����� ������ ������������� ������
	while (1) {
		showBootsData(vec_of_boots);
		displayBootsViewListMenu();
		switch (choiceMenuItem(0, 3))
		{
		case 1: searchBootsInterface(vec_of_boots); break;
		case 2:	sortBootsInterface(vec_of_boots); break;
		case 3: searchByTask(vec_of_boots); break;
		case 0: return;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

void checkRegistrationList(vector<Account>& vec_of_accounts)
{
	// �������� �������� �� �����������
	while (true) {
		int count_of_id = showAccountsForReg(vec_of_accounts);
		/* ������� showAccountsForReg ���������� ���-�� �������� �� �����������
		���� ���-�� �������� == 0, ���������� ������ � ������� �� �������*/
		if (count_of_id == 0) {
			cout << "\n\n\n\n\n\n\t\t\t\t������� �� ����������� �����������\n\n\t\t\t\t������� ����� �������, ����� ����������" << endl;
			if (_getch()) return;
		}
		regMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: acceptRequestForReg(vec_of_accounts); break;
		case 2: cancelRequestForReg(vec_of_accounts); break;
		case 0: return;
		default:
			cout << "������� ����������� ��������" << endl;
			break;
		}
	}
}

void adminMode(vector<Account>& vec_of_accounts, vector<Boots>& vec_of_boots)
{
	// ������ ��������������. (accout.role == 1)
	// ������������� ����� ������������ CRUD �������
	while (1) {
		adminMenu();
		switch (choiceMenuItem(0, 9))
		{
		case 1: userMode(vec_of_boots); break;
		case 2: addBoots(vec_of_boots); break;
		case 3: delBoots(vec_of_boots); break;
		case 4: editBoots(vec_of_boots); break;
		case 5: showAccountsInterface(vec_of_accounts); break;
		case 6: addAccount(vec_of_accounts); break;
		case 7: delAccount(vec_of_accounts); break;
		case 8: editAccount(vec_of_accounts); break;
		case 9: checkRegistrationList(vec_of_accounts); break;
		case 0: return;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

int auth(vector<Account> vec_of_accouts)
{
	string current_login;
	string current_password;
	int current_role = -1;
	int i = 0;
	cout << "������� ����� - "; cin >> current_login;
	current_password = generateHash(getPassword("������� ������ - "));

	/*��������, ���������� �� ����� ������������ � ��
	���� ����������, �� current_role ���������� �� ��������������*/
	while (i < vec_of_accouts.size() && current_role == -1) {
		if (vec_of_accouts.at(i).login == current_login && vec_of_accouts.at(i).password == current_password && vec_of_accouts.at(i).access == 1) {
			current_role = vec_of_accouts.at(i).role;
		}
		i++;
	}
	// �������� ����� � �������������
	cout << "\n����������� ����" << endl;
	Sleep(500);
	return current_role;
}

bool repeatRequest(const char* text)
{
	// text ������ ��������� 1 - ������������� ��������
	system("cls");
	int user_choice = input_number(text, 1);
	system("cls");
	if (user_choice == 1) return true;
	return false;
}

void login(vector <Account>& vec_of_accouts, vector <Boots>& vec_of_boots)
{
	// ���������, �� ����� �� ������������ �������� ������
	if (!repeatRequest("> ����������� <\n\n����������\n1 | ��\n>")) return;

	while (1) {
		switch (auth(vec_of_accouts))
		{
		case 0: userMode(vec_of_boots); return;
		case 1: adminMode(vec_of_accouts, vec_of_boots); return;
		default:
			if (repeatRequest("����� ������������ �� ������\n��������� �����������?\n1 | ��\n>")) return login(vec_of_accouts, vec_of_boots);
			return;
		}
	}
}

void registration(vector<Account>& vec_of_accounts)
{
	// ���������, �� ����� �� ������������ �������� ������
	if (!repeatRequest("> ����������� <\n\n����������\n1 | ��\n>")) return;

	Account new_account;
	string verify_password;

	// ���� ������������ ������ ���������� �����������, �� ������ ������ ������
	while (1) {
		system("cls");

		new_account.login = create_login(vec_of_accounts);
		new_account.password = generateHash(getPassword("������� ������ >"));
		verify_password = generateHash(getPassword("������� ������ ��� ��� >"));

		// ������ �������, ����� ��������� ���������
		if (new_account.password == verify_password) break;
		cout << "[������ �� ������������ ���� �����]" << endl;
		Sleep(1000);
	}
	// ���������� ���� "������������" � ������� "�������"
	new_account.role = 0;
	new_account.access = 0;
	vec_of_accounts.push_back(new_account);
	writeEndFileAccounts(new_account); // ������ � ����

	// �������� ����� � �������������
	system("cls");
	cout << "> ��� ������ �� ����������� ��������� �� ������������ <" << endl;
	cout << "\n> ������� ����� �������, ����� ���������� <" << endl;
	if (_getch()) return;
}

void core(vector<Account>& vec_of_accounts, vector<Boots>& vec_of_boots)
{
	system("cls");
	while (1) {
		mainMenu();
		switch (choiceMenuItem(0, 3))
		{
		case 0: return;
		case 1:	login(vec_of_accounts, vec_of_boots); break;
		case 2:	registration(vec_of_accounts); break;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

//---------------CORE_FUNC-----------------------#

