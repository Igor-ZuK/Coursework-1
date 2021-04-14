#pragma once

#ifndef CORE_H
#define CORE_H

#include "admin_func.h"

using namespace std;

//---------------CORE_FUNC-----------------------!

void userMode(vector<Boots> vec_of_boots);

void checkRegistrationList(vector<Account>& vec_of_accounts);

void adminMode(vector<Account>& vec_of_accounts, vector<Boots>& vec_of_boots);

int auth(vector<Account> vec_of_accouts);

bool repeatRequest(const char* text);

void login(vector <Account>& vec_of_accouts, vector <Boots>& vec_of_boots);

void registration(vector<Account>& vec_of_accounts);

void core(vector<Account>& vec_of_accounts, vector<Boots>& vec_of_boots);

//---------------CORE_FUNC-----------------------#
#endif