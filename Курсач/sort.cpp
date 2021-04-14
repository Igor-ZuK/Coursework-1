#include "sort.h"

using namespace std;

//----SORT-------!

void sortBootsByPriceUpDown(vector<Boots>& vec_of_boots)
{
	// ���������� �� �����������
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootsByPriceUpDownComparator);
}

void sortBootsByPriceDownUp(vector<Boots>& vec_of_boots)
{
	// ���������� �� �������� ����
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootsByPriceDownUpComparator);
}

void sortBootByBootsSize(vector<Boots>& vec_of_boots)
{
	// ���������� �� ������� �����
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootByBootsSizeComparator);
}

void sortBootByArticle(vector<Boots>& vec_of_boots)
{
	// ���������� �� �������
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootByArticleComparator);
}

void sortBootByABC(vector<Boots>& vec_of_boots)
{
	// ���������� �� ��������
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortBootByABCComparator);
}

void sortBootsInterface(vector<Boots>& vec_of_boots)
{
	// ���� ���������� �����
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
			cout << "������������ ����" << endl;
			break;
		}
	}
}

void sortAccountByLogin(vector<Account>& vec_of_boots)
{
	// ���������� �� ������
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortAccountByLoginComparator);
}

void sortAccountByRole(vector<Account>& vec_of_boots)
{
	// ���������� �� ����
	sort(vec_of_boots.begin(), vec_of_boots.end(), sortAccountByRoleComparator);
}

void sortAccountsInterface(vector<Account>& vec_of_accounts)
{
	// ���� ���������� ���������
	while (1) {
		displayAccountSortMenu();
		switch (choiceMenuItem(0, 2))
		{
		case 1: sortAccountByLogin(vec_of_accounts); return;;
		case 2: sortAccountByRole(vec_of_accounts); return;
		case 0: return;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

//----SORT-------#
