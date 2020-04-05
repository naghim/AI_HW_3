#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int DeepLimit = 6;
int TimeLimit = 1;

int tick;

//const int ROWS = 5;
//const int COLUMNS = 6;

class STATE {
public:
	int fields[5][6];
	STATE() {
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 6; ++j)
				fields[i][j] = -1;
	}
};

void WRITE(const STATE& s) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (s.fields[i][j] < 0)
				cout << "[ ] ";
			else if (s.fields[i][j] % 2 == 1)
				cout << "[0] ";
			else
				cout << "[1] ";
		}
		cout << endl;
	}
}

bool won(const STATE& s) {
	for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) {
		if (s.fields[i + 1][j + 1] % 2 == s.fields[i][j] % 2 && s.fields[i + 1][j + 1] >= 0 &&
			s.fields[i + 2][j + 2] % 2 == s.fields[i][j] % 2 && s.fields[i + 2][j + 2] >= 0 &&
			s.fields[i + 3][j + 3] % 2 == s.fields[i][j] % 2 && s.fields[i + 3][j + 3] >= 0 &&
			s.fields[i][j] >= 0) {
			return true;
		}    ///Atlosan jobb-le

		if (s.fields[i + 1][2 + j] % 2 == s.fields[i][3 + j] % 2 && s.fields[i + 1][2 + j] >= 0 &&
			s.fields[i + 2][1 + j] % 2 == s.fields[i][3 + j] % 2 && s.fields[i + 2][1 + j] >= 0 &&
			s.fields[i + 3][j] % 2 == s.fields[i][3 + j] % 2 && s.fields[i + 3][j] >= 0 &&
			s.fields[i][3 + j] >= 0) {
			return true;
		}  ///Atlosan bal-le
	}
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 3; ++j)
		if (s.fields[i][j + 1] % 2 == s.fields[i][j] % 2 && s.fields[i][j + 1] >= 0 &&
			s.fields[i][j + 2] % 2 == s.fields[i][j] % 2 && s.fields[i][j + 2] >= 0 &&
			s.fields[i][j + 3] % 2 == s.fields[i][j] % 2 && s.fields[i][j + 3] >= 0 &&
			s.fields[i][j] >= 0) {
			return true;
		}   ///vizszintes

	for (int i = 0; i < 2; ++i) for (int j = 0; j < 6; ++j)
		if (s.fields[i + 1][j] % 2 == s.fields[i][j] % 2 && s.fields[i + 1][j] >= 0 &&
			s.fields[i + 2][j] % 2 == s.fields[i][j] % 2 && s.fields[i + 2][j] >= 0 &&
			s.fields[i + 3][j] % 2 == s.fields[i][j] % 2 && s.fields[i + 3][j] >= 0 &&
			s.fields[i][j] >= 0)
		{
			return true;    ///fuggoleges
		}
	return false;
}

bool is_termival(const STATE& s) {   ///int
	bool res = true;    ///Betelt a palya
	for (int j = 0; j < 6; ++j) if (s.fields[0][j] < 0) res = false;
	if (res)
	{
		return true;    ///maxV
	}
	if (won(s)) {
		return true;///maxV
	}
	else return false;  ///0
}
vector<STATE> children(const STATE& s) {
	vector<STATE> res;
	int maxV = -1;
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 6; ++j)
		if (s.fields[i][j] > maxV) maxV = s.fields[i][j];
	maxV++;
	for (int j = 0; j < 6; ++j)
		if (s.fields[0][j] < 0) {
			res.push_back(s);
			for (int i = 4; i >= 0; --i)
				if (res.back().fields[i][j] < 0) {
					res.back().fields[i][j] = maxV; break;
				}
		}
	return res;
}

int myTrick(int a, int b, int c, int d) {

	int sum = (a < 0 ? 1 : (a % 2)) + (b < 0 ? 1 : (b % 2)) + (c < 0 ? 1 : (c % 2)) + (d < 0 ? 1 : (d % 2)) + (a < 0 ? 0 : (a % 2)) + (b < 0 ? 0 : (b % 2)) + (c < 0 ? 0 : (c % 2)) + (d < 0 ? 0 : (d % 2));

	switch (sum) {
	case 0: return -9876543;
	case 1: return -98765;
	case 2: return -987;
	case 3: return -9;
	case 4: return 0;
	case 5: return 9;
	case 6: return 987;
	case 7: return 98765;
	case 8: return 9876543;
	default: return 0;  ///csak formaisag, ez a sor nem kell
	}

}

int heuristic_eval(const STATE& s) {
	int maxV = -1;
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 6; ++j)
		if (s.fields[i][j] > maxV) maxV = s.fields[i][j];


	maxV = (maxV % 2 ? 1 : -1);

	int score = 0;

	for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) {
		score += myTrick(s.fields[i][j], s.fields[i + 1][j + 1], s.fields[i + 2][j + 2], s.fields[i + 3][j + 3]); ///Atlosan jobb-le
		score += myTrick(s.fields[i][3 + j], s.fields[i + 1][2 + j], s.fields[i + 2][1 + j], s.fields[i + 3][j]); ///Atlosan bal-le
	}
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 3; ++j)
		score += myTrick(s.fields[i][j], s.fields[i][j + 1], s.fields[i][j + 2], s.fields[i][j + 3]); ///vizszintes

	for (int i = 0; i < 2; ++i) for (int j = 0; j < 6; ++j)
		score += myTrick(s.fields[i][j], s.fields[i + 1][j], s.fields[i + 2][j], s.fields[i + 3][j]); ///fuggoleges

	return maxV * score; ///Az maxV ebben az esetben a "colort" helyettesiti
}

int alphabeta(STATE s, int depth, int alpha, int beta) {
	if (depth == 0 || is_termival(s) || clock() >= tick + 1000 * TimeLimit)
	{
		return heuristic_eval(s);
	}
	int value;
	int maxV = -1;
	for (int i = 0; i < 5; ++i) for (int j = 0; j < 6; ++j)
		if (s.fields[i][j] > maxV) maxV = s.fields[i][j];


	if (maxV % 2 == 0) {
		for (STATE child : children(s)) {
			alpha = max(alpha, alphabeta(child, depth - 1, alpha, beta));
			if (alpha >= beta) return alpha;
		}

		return alpha;
	}

	else {
		value = beta;
		for (STATE child : children(s)) {
			beta = min(beta, alphabeta(child, depth - 1, alpha, beta));
			if (alpha >= beta) return beta;
		}

		return beta;
	}
}

void AI(STATE& s) {
	int tmp = 0, tuti = 0;
	STATE step;
	vector<STATE> lehetosegek = children(s);
	tick = clock();
	for (STATE child : lehetosegek) {
		tmp = alphabeta(child, DeepLimit, -987654321, 987654321);
		if (tmp > tuti) { tuti = tmp; step = child; }
	}
	s = step;
}

void HUMAN(STATE& s) {
	int oszlop;

	cout << "oszlop: ";
	cin >> oszlop;
	while (s.fields[0][oszlop] >= 0) cin >> oszlop;

	int maxV = -1;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 6; ++j)
			if (s.fields[i][j] > maxV) maxV = s.fields[i][j];
	maxV++;

	int tmp = 4;
	while (s.fields[tmp][oszlop] >= 0) tmp--;
	s.fields[tmp][oszlop] = maxV;
}

int main(int argc, char* argv[]) {
	try {
		for (int i = 1; i < argc; i++) {
			if (string(argv[i]) == "-d") DeepLimit = stoi(string(argv[++i]));
			if (string(argv[i]) == "-t") TimeLimit = stoi(string(argv[++i]));
		}
	}
	catch (...) {}

	STATE s;
	while (true) {
		AI(s);
		WRITE(s);
		if (is_termival(s)) break;

		HUMAN(s);
		WRITE(s);
		if (is_termival(s)) break;
	}
	cout << "END";
	cin >> DeepLimit;

	return 0;
}
