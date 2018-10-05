#include<iostream>
#include<string>
#include<windows.h>
#include<ctime>
#include"gra.h"

using namespace std;
 
int main() {
	int q = 0;
	Osu elko;
	while(true) {
		elko.new_step();
		elko.pr_graf();
		cout <<"\nScore: "<< q;
		if (elko.check_step())q++;
		else break;
		if (elko.non_key_ind)q = 0;
	}
	cout << "\nGAME OVER!!!\n";
	system("pause");
	return 0;
}