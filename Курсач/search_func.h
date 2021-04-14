#pragma once

#ifndef SEARCH_FUNC_H
#define SEARCH_FUNC_H

#include <string>
#include "sort.h"

using namespace std;


//----------SEARCH_FUNC----------!

void searchByPrice(vector<Boots> vec_of_boots);

void searchByBootsSize(vector<Boots> vec_of_boots);

void searchByArticle(vector<Boots> vec_of_boots);

void searchByTask(vector<Boots> vec_of_boots);

void searchBootsInterface(vector<Boots> vec_of_boots);

void searchAccountByLogin(vector<Account> vec_of_accounts);

void searchAccountByRole(vector<Account> vec_of_accounts);

void searchAccountsInterface(vector<Account> vec_of_accounts);

//----------SEARCH_FUNC----------#
#endif