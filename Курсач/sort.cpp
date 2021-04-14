#include "sort.h"

using namespace std;

//----SORT-------!

void sortBootsByPriceUpDown(vector<Boots>& vec_of_boots)
{
	// сортировка по возрастанию
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootsByPriceUpDownComparator);
}

void sortBootsByPriceDownUp(vector<Boots>& vec_of_boots)
{
	// сортировка по убыванию цены
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootsByPriceDownUpComparator);
}

void sortBootByBootsSize(vector<Boots>& vec_of_boots)
{
	// сортировка по размеру обуви
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootByBootsSizeComparator);
}

void sortBootByArticle(vector<Boots>& vec_of_boots)
{
	// сортировка по Артиклю
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootByArticleComparator);
}

void sortBootByABC(vector<Boots>& vec_of_boots)
{
	// сортировка по алфавиту
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootByABCComparator);
}

void sortBootsInterface(vector<Boots>& vec_of_boots)
{
	// меню сортировки Обуви
	while (1) {
		displayBootsSortMenu();
		switch (choiceMenuItem(0, 5))
		{
		case 1: sortBootsByPriceUpDown(vec_of_boots); return;
		case 2: sortBootsByPriceDownUp(vec_of_boots); return;
		case 3: sortBootByBootsSize(vec_of_boots); return;
		case 4: sortBootByArticle(vec_of_boots); return;
		case 5: sortBootByABC(vec_of_boots); return;
		case 0: return;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

void sortAccountByLogin(vector<Account>& vec_of_boots)
{
	// сортировка по логину
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortAccountByLoginComparator);
}

void sortAccountByRole(vector<Account>& vec_of_boots)
{
	// сортировка по роли
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortAccountByRoleComparator);
}

void sortAccountsInterface(vector<Account>& vec_of_accounts)
{
	// меню сортировки аккаунтов
	while (1) {
		displayAccountSortMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: sortAccountByLogin(vec_of_accounts); return;;
		case 2: sortAccountByRole(vec_of_accounts); return;
		case 0: return;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

//----SORT-------#
