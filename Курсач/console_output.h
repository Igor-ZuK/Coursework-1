#pragma once

#ifndef CONSOLE_OUTPUT_H
#define CONSOLE_OUTPUT_H

#include <iomanip>
#include "utils.h"

using namespace std;

//----------CONSOLE_OUTPUT-------!

void showBootsTableTitle();

void consoleOutBoot(Boots boot, int i);

void showBootsData(vector<Boots> vec_of_boots);

void showAccountsTableTitle();

void consoleOutAccount(Account account, int i);

void showAccountsData(vector<Account> vec_of_accounts);

int showAccountsForReg(vector<Account> vec_of_accounts);

//----------CONSOLE_OUTPUT-------#
#endif