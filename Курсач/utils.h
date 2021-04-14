#pragma once

#include <iostream>
#include <conio.h>
#include <vector>
#include "menu.h"
#include "sha256.h"

#ifndef UTILS_H
#define UTILS_H

using namespace std;

struct Account
{
	string login;
	string password;
	int role;
	int access;
};

struct Boots
{
	string article;
	string title;
	double price;
	string fabricator;
	int boot_size;
	int num_of_pairs;
};

//----------UTILS-----------!

int input_number(const char* text, int length_limit = 5, bool anti_zero_flag = false); // функция проверки на ввод только цифр(как положительных, так и отрицательных)

double input_double(const char* text);

string input_article();

string create_login(vector <Account> vec_of_accouts);

string generateHash(string password, string salt = "OKPprog");

string swapSpaceToDownSpace(string str, char check_char = ' ', char change_char = '_');

string getPassword(const char* text, bool show_asterisk = true);

int choiceMenuItem(int left_limit, int right_limit);

//----------UTILS-----------#
#endif