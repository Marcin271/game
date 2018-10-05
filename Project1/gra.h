#pragma once
#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class Osu
{
	int graf_len=15;
	vector<int>graf_pos;
	vector<string>graf;

public:
	bool non_key_ind = false;
	Osu();
	~Osu();
	void cl_graf();
	void pr_graf();
	void new_step();
	int check_key();
	bool check_step();
};

