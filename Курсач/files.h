#pragma once

#ifndef FILES_H
#define FILES_H

#include <string>
#include <fstream>
#include "search_func.h"

using namespace std;

string const FILE_OF_ACCOUNTS = "accounts.txt";
string const FILE_OF_BOOTS = "boots.txt";

//----------files----------!

bool file_is_empty(string file_path);

void readFileAccounts(vector <Account>& vec_of_accouts);

void writeFileAccounts(vector<Account> vec_of_accounts);

void writeEndFileAccounts(Account new_account);

int getCountOfStructuresInFile(string file_path);

void readFileBoots(vector <Boots>& vec_of_boots);

void writeFileBoots(vector <Boots> vec_of_boots);

void writeEndFileBoots(Boots new_boot_pair);

//----------files----------#
#endif