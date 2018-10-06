#include<iostream>
#include<string>
#include<windows.h>
#include<ctime>
#include"gra.h"

using namespace std;
 
int main() {
	cout << "How to play:\nWhen 'o' is in \nthe marked area\npress 'q' or 'w' \nor 'o' or 'p'\n\nPress space to start game!";
		while (true) {
			if (GetKeyState(VK_SPACE) /*& 0x8000*/)break;
		}
	while (true) {
		int q = 0;
		Osu elko;
		while (true) {
			if (GetKeyState('E') & 0x8000)return 0;
			elko.new_step();
			elko.pr_graf();
			cout << "\nScore: " << q << "\nHold e to exit game!";
			if (elko.check_step())q++;
			else break;
			if (elko.non_key_ind)q = 0;
		}
		cout << "\nGAME OVER!!!\nDo you want restart? (y/n)\n";
		while (true) {
			if (GetKeyState('N') & 0x8000)return 0;
			else if (GetKeyState('Y') & 0x8000)break;
		}
	}
	return 0;
}