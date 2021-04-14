#include "comparators.h"

using namespace std;

//----COMPARATORS-----!

bool sortBootsByPriceUpDownComparator(Boots boot_a, Boots boot_b)	//по убыванию
{
	return boot_a.price > boot_b.price;
}

bool sortBootsByPriceDownUpComparator(Boots boot_a, Boots boot_b)
{
	return boot_a.price < boot_b.price;
}

bool sortBootByBootsSizeComparator(Boots boot_a, Boots boot_b)
{
	return boot_a.boot_size > boot_b.boot_size;
}

bool sortBootByArticleComparator(Boots boot_a, Boots boot_b)
{
	return boot_a.article > boot_b.article;
}

bool sortBootByABCComparator(Boots boot_a, Boots boot_b)
{
	return boot_a.title < boot_b.title;
}

bool sortAccountByLoginComparator(Account account_a, Account account_b)
{
	return account_a.login < account_b.login;
}

bool sortAccountByRoleComparator(Account account_a, Account account_b)
{
	return account_a.role >= account_b.role;
}

//----COMPARATORS-----#