#pragma once

#ifndef SORT_H
#define SORT_H

#include "comparators.h"

using namespace std;

//----SORT-------!

void sortBootsByPriceUpDown(vector<Boots>& vec_of_boots);

void sortBootsByPriceDownUp(vector<Boots>& vec_of_boots);

void sortBootByBootsSize(vector<Boots>& vec_of_boots);

void sortBootByArticle(vector<Boots>& vec_of_boots);

void sortBootByABC(vector<Boots>& vec_of_boots);

void sortBootsInterface(vector<Boots>& vec_of_boots);

void sortAccountByLogin(vector<Account>& vec_of_boots);

void sortAccountByRole(vector<Account>& vec_of_boots);

void sortAccountsInterface(vector<Account>& vec_of_accounts);

//----SORT-------#

#endif