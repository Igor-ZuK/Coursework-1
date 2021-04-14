#include "files.h"

using namespace std;

//----------files----------!

bool file_is_empty(string file_path)
{
	// проверка файла на пустоту
	ifstream file(file_path);
	file.seekg(0, ios::end); // помещаем указатель в конец файла
	int file_size = file.tellg(); // если кол-во прочтённый данных == 0 - файл пуст
	if (file_size == 0)
	{
		file.close(); return true;
	}
	else
		file.close(); return false;
}

void readFileAccounts(vector <Account>& vec_of_accouts)
{
	// чтение из файла и запись в вектор структур аккаунты 
	ifstream fin(FILE_OF_ACCOUNTS, ios::in);
	if (!fin.is_open()) cout << "Файл не существует!";
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
	// запись вектора структур акканты в файл
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
	// запись Аккаунта в конец файла 
	ofstream fadd(FILE_OF_ACCOUNTS, ios::app); // Открыли файл для дозаписи
	fadd << endl;
	fadd << new_account.login << " "
		<< new_account.password << " "
		<< new_account.role << " "
		<< new_account.access;
	fadd.close();
}

int getCountOfStructuresInFile(string file_path)
{
	// функция подсчёта кол-ва структур в файле(1 объект - 1 строка)
	char buffer[100];
	int count_of_struct = 0;
	ifstream file(file_path, ios::in);
	if (file.is_open()) {
		while (file.getline(buffer, 100)) count_of_struct++;
	}
	else cout << "Ошибка открытия файла" << endl;
	file.close();
	return count_of_struct;
}

void readFileBoots(vector <Boots>& vec_of_boots)
{
	// чтение из файла и запись в вектор структур обуви 
	ifstream fin(FILE_OF_BOOTS, ios::in);
	if (!fin.is_open()) cout << "Файл не существует!";
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
	// запись вектора структур обуви в файл 
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
	// запись Обуви в конец файла 
	ofstream fadd(FILE_OF_BOOTS, ios::app); // Открыли файл для дозаписи
	fadd << endl;
	fadd << swapSpaceToDownSpace(new_boot_pair.title) << " " << swapSpaceToDownSpace(new_boot_pair.fabricator) <<
		" " << new_boot_pair.article << " " << new_boot_pair.price << " " << new_boot_pair.boot_size << " " << new_boot_pair.num_of_pairs << endl;
	fadd.close();
}

//----------files----------#