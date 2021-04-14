
/*Сведения об ассортименте обуви в магазине включают: артикул, наименова-
ние, цена, изготовитель, размер, количество пар. Артикул начинается с буквы 
Ж – для женской обуви, М – для мужской, Д – для детской.
Индивидуальное задание: вывести список обуви артикула х и размера y (x, y
вводятся с клавиатуры).

Общее для всех вариантов задание: реализовать авторизацию для входа в си-
стему, функционал администратора и функционал пользователя (см. более по-
дробно в функциональных требованиях к курсовой работе, подраздел 1.2).*/

#include "core.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("mode 140, 40");

	vector<Account> vec_of_accounts;
	vec_of_accounts.reserve(getCountOfStructuresInFile(FILE_OF_ACCOUNTS));
	readFileAccounts(vec_of_accounts);

	vector<Boots> vec_of_boots;
	vec_of_boots.reserve(getCountOfStructuresInFile(FILE_OF_BOOTS));
	readFileBoots(vec_of_boots);

	core(vec_of_accounts, vec_of_boots);
	writeFileAccounts(vec_of_accounts);
	writeFileBoots(vec_of_boots);
}
