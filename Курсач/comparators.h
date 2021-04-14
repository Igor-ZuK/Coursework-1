#pragma once

#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <algorithm>
#include <string>
#include "console_output.h"

using namespace std;

//----COMPARATORS-----!

bool sortBootsByPriceUpDownComparator(Boots boot_a, Boots boot_b);

bool sortBootsByPriceDownUpComparator(Boots boot_a, Boots boot_b);

bool sortBootByBootsSizeComparator(Boots boot_a, Boots boot_b);

bool sortBootByArticleComparator(Boots boot_a, Boots boot_b);

bool sortBootByABCComparator(Boots boot_a, Boots boot_b);

bool sortAccountByLoginComparator(Account account_a, Account account_b);

bool sortAccountByRoleComparator(Account account_a, Account account_b);

//----COMPARATORS-----#
#endif