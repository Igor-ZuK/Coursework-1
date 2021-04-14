#include "files.h"

using namespace std;

//----------files----------!

bool file_is_empty(string file_path)
{
	// �������� ����� �� �������
	ifstream file(file_path);
	file.seekg(0, ios::end); // �������� ��������� � ����� �����
	int file_size = file.tellg(); // ���� ���-�� ��������� ������ == 0 - ���� ����
	if (file_size == 0)
	{
		file.close(); return true;
	}
	else
		file.close(); return false;
}

void readFileAccounts(vector <Account>& vec_of_accouts)
{
	// ������ �� ����� � ������ � ������ �������� �������� 
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	if (!fin.is_open()) cout << "���� �� ����������!";
	else
	{
		Account temp;
		while (!fin.eof())
		{
			fin >> temp.login
				>> temp.password
				>> temp.role
				>> temp.access;
			vec_of_accouts.push_back(temp);
		}
	}
	fin.close();
}

void writeFileAccounts(vector<Account> vec_of_accounts)
{
	// ������ ������� �������� ������� � ����
	fstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (int i = 0; i < vec_of_accounts.size(); ++i) {
		fout << vec_of_accounts.at(i).login << " "
			<< vec_of_accounts.at(i).password << " "
			<< vec_of_accounts.at(i).role << " "
			<< vec_of_accounts.at(i).access;
		if (i < vec_of_accounts.size() - 1) fout << endl;
	}
	fout.close();
}

void writeEndFileAccounts(Account new_account)
{
	// ������ �������� � ����� ����� 
	ofstream fadd(FILE_OF_ACCOUNTS, ios::app); // ������� ���� ��� ��������
	fadd << endl;
	fadd << new_account.login << " "
		<< new_account.password << " "
		<< new_account.role << " "
		<< new_account.access;
	fadd.close();
}

int getCountOfStructuresInFile(string file_path)
{
	// ������� �������� ���-�� �������� � �����(1 ������ - 1 ������)
	char buffer[100];
	int count_of_struct = 0;
	ifstream file(file_path, ios::in);
	if (file.is_open()) {
		while (file.getline(buffer, 100)) count_of_struct++;
	}
	else cout << "������ �������� �����" << endl;
	file.close();
	return count_of_struct;
}

void readFileBoots(vector <Boots>& vec_of_boots)
{
	// ������ �� ����� � ������ � ������ �������� ����� 
	ifstream fin(FILE_OF_BOOTS, ios::in);
	if (!fin.is_open()) cout << "���� �� ����������!";
	else
	{
		Boots temp;
		while (!fin.eof())
		{
			fin >> temp.title
				>> temp.fabricator
				>> temp.article
				>> temp.price
				>> temp.boot_size
				>> temp.num_of_pairs;
			vec_of_boots.push_back(temp);
		}
	}
	fin.close();
}

void writeFileBoots(vector <Boots> vec_of_boots)
{
	// ������ ������� �������� ����� � ���� 
	fstream fout(FILE_OF_BOOTS, ios::out);
	for (int i = 0; i < vec_of_boots.size(); ++i) {
		fout << swapSpaceToDownSpace(vec_of_boots.at(i).title) << " " << swapSpaceToDownSpace(vec_of_boots.at(i).fabricator) <<
			" " << vec_of_boots.at(i).article << " " << vec_of_boots.at(i).price << " " << vec_of_boots.at(i).boot_size << " " << vec_of_boots.at(i).num_of_pairs;
		if (i < vec_of_boots.size() - 1) fout << endl;
	}
	fout.close();
}

void writeEndFileBoots(Boots new_boot_pair)
{
	// ������ ����� � ����� ����� 
	ofstream fadd(FILE_OF_BOOTS, ios::app); // ������� ���� ��� ��������
	fadd << endl;
	fadd << swapSpaceToDownSpace(new_boot_pair.title) << " " << swapSpaceToDownSpace(new_boot_pair.fabricator) <<
		" " << new_boot_pair.article << " " << new_boot_pair.price << " " << new_boot_pair.boot_size << " " << new_boot_pair.num_of_pairs << endl;
	fadd.close();
}

//----------files----------#