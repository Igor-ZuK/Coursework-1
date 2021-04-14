#pragma once

#ifndef ADMIN_FUNC_H
#define ADMIN_FUNC_H

#include "files.h"

using namespace std;

//---------------ADMIN_FUNC----------------------!

void addBoots(vector<Boots>& vec_of_boots);

void delBoots(vector<Boots>& vec_of_boots);

void editBoots(vector<Boots>& vec_of_boots);

void addAccount(vector<Account>& vec_of_accounts);

void delAccount(vector<Account>& vec_of_accounts);

void changeUserRole(vector<Account>& vec_of_accounts, int number_of_change);

void editAccountsInterface(vector<Account>& vec_of_accounts, int number_of_change);

void editAccount(vector<Account>& vec_of_accounts);

void showAccountsInterface(vector<Account>& vec_of_accounts);

void cancelRequestForReg(vector<Account>& vec_of_accounts);

void acceptRequestForReg(vector<Account>& vec_of_accounts);

//---------------ADMIN_FUNC----------------------#

#endif