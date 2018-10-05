#include "gra.h"

using namespace std;

Osu::Osu()
{
	srand(time(NULL));
	this->cl_graf();
	this->pr_graf();
	
}

Osu::~Osu()
{
}

void Osu::cl_graf() {
	graf.clear();
	graf_pos.clear();
	for (int i = 0; i < graf_len; i++) {
			graf.push_back("| | | | |");
			graf_pos.push_back(0);
		}
}

void Osu::pr_graf() {
	system("cls");
	for (int i = graf_len - 1; i >= 0;i--) {
		if (i == 0)cout << "+++"+graf[i]+"+++";
		else cout <<"   "+graf[i] << endl;
		
	}
}

void Osu::new_step() {
	switch (rand() % 4) {
	case 0: graf.push_back("|o| | | |");
		graf_pos.push_back(1);
		break;
	case 1: graf.push_back("| |o| | |");
		graf_pos.push_back(2);
		break;
	case 2: graf.push_back("| | |o| |");
		graf_pos.push_back(3);
		break;
	case 3: graf.push_back("| | | |o|");
		graf_pos.push_back(4);
		break;
	default:graf.push_back("| | | | |");
		graf_pos.push_back(5);
		break;
	}
	 graf.erase(graf.begin());
	 graf_pos.erase(graf_pos.begin());
	 if (graf_pos[0] == 0)non_key_ind = true;
	 else non_key_ind = false;
}

int Osu::check_key() {
	double czas;
	int a = 0;
	clock_t start=clock();
	while (true) {
		if (GetKeyState('Z') & 0x8000)a = 1;
		if (GetKeyState('X') & 0x8000)a = 2;
		if (GetKeyState('N') & 0x8000)a = 3;
		if (GetKeyState('M') & 0x8000)a = 4;
		if (((double)(clock() - start) / CLOCKS_PER_SEC)>0.5)return a;
	}
}

bool Osu::check_step() {
	if (graf_pos[0] == check_key() || (non_key_ind)) return 1;
	else return 0;
}