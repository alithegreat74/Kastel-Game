#include <iostream>
#include <algorithm>
using namespace std;
void start(int num, int total[], int goal);
string change(int num);
int val(int number);
int rowcounterr(int row[]);
int main() {
	int numplayers;
	int totalpoints[6] = { 0,0,0,0,0,0 };
	cout << "Welcome to Kastel\nPlease enter the number of players who want to enter: ";
	cin >> numplayers;		//how many players are there

	if (numplayers < 2) {	//players cant be less than 2
		cout << "You can't play all by yourself. Go find some friends\n";
		return 0;
	}
	else if (numplayers > 6) {	//players cant be more thab 6
		cout << "There are too many of you to play this game. Do something else\n";
		return 0;
	}
	cout << "For how many points do you want to play the game? ";
	int goal;
	cin >> goal;
	cout << "Welcome everyone to our halloween game\nLets start the game\nEnter 1 to start the game: ";
	int choice;
	cin >> choice;
	while (choice != 1) {
		cout << "Your answer is not correct\nTry again: ";
		cin >> choice;
	}
	system("cls");
	start(numplayers, totalpoints, goal);
}
void start(int num, int total[], int goal) {
	int cardnum = 89;
	int cards[90] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74 };
	//there are 90 cards that from 0 to 29 are pumpkin card and from 30 to 59 are mummy card and from 60 to 89 are zombie cards
	random_shuffle(&cards[0], &cards[90]);	//shuffling the cards
	int decks[6][3];	//each player has 3 cards
	for (int i = 0; i < num; i++) {		//dealing the cards
		for (int j = 0; j < 3; j++) {
			decks[i][j] = cards[cardnum];
			cardnum -= 1;
		}
	}
	cout << "OK you all got your cards. Let's start the game for real\nEnter 1 to continue: ";
	int choice;
	cin >> choice;
	while (choice != 1) {
		cout << "Your answer is not correct\nTry again: ";
		cin >> choice;
	}
	system("cls");
	int row[6][6] = { {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}};
	int round = 0;
	int m;
	while (true) {
		for (int i = 0; i < num; i++) {
			cout << "player number " << i + 1 << " these are your cards\n";
			for (int p = 0; p < 3; p++) {
				cout << change(decks[i][p]) << " " << val(decks[i][p]) << " ";
			}
			cout << "\n";
			cout << "These are eache player's row: \n";
			int p = 0;
			for (int l = 0; l < num; l++) {
				p = 0;
				cout << "Player " << l + 1 << ": ";
				while (row[l][p] != 0) {
					cout << change(row[l][p]) << " " << val(row[l][p]) << " ";
					p++;
				}
				cout << "\n";
			}
			cout << "Player number " << i + 1 << " please make your move\nhere are the commands:\n1)Put in front of you\n2)put in front of someone else\nWhat is your command? ";
			int command;

			cin >> command;
			while (command != 1 && command != 2) {
				cout << command << " is not initiated\nTry again: ";
				cin >> command;
			}
			if (round == 0) {
				while (command == 2) {
					cout << "Everybody should put a card in front of themselves\ntry again: ";
					cin >> command;
				}
			}
		if (command == 1) {
			int rowcounter = rowcounterr(row[i]);
			cout << "Choose a card to be added to your row: ";
			int choice;
			cin >> choice;
			while (choice > 3 || choice < 1) {
				cout << choice << " is not initiated\nTry again: ";
				cin >> choice;
			}
			row[i][rowcounter] = decks[i][choice - 1];
			decks[i][choice - 1] = cards[cardnum];
			cardnum--;
			rowcounter++;
			for (int m = 0; m < rowcounter; m++) {
				for (int n = m + 1; n < rowcounter; n++) {
					if (row[i][m] == row[i][n]) {
						row[i][n] = row[i][rowcounter - 1];
						row[i][rowcounter - 1]=0;
					}
				}
			}
			cout << change(row[i][round]) << " " << val(row[i][round]) << " ";
			cout << "is added to you row\n" << "This is how your row looks like:\n";
			int o = 0;
			while (row[i][o] != 0) {
				cout << change(row[i][o]) << " " << val(row[i][o]) << " ";
				o++;
			}
			cout << "\nEnter 1 to continue: ";
			cin >> choice;
			while (choice != 1) {
				cout << choice << " is not initiated\ntry again: ";
				cin >> choice;
			}
			system("cls");
		}
		else if (command == 2) {
			cout << "Choose a player to add your card to: ";
			int player;
			cin >> player;
			player--;
			while (player > num || player < 0) {
				cout << player << " is not initiated\nTry again: ";
				cin >> player;
			}
			int rowcounter = rowcounterr(row[player]);
			cout << "Choose a card to add: ";
			int choice;
			cin >> choice;
			choice--;
			while (choice > 3 || choice < 0) {
				cout << choice << " is not initiated\nTry again: ";
				cin >> choice;
			}
			cout << "Choose which card do you want to cover: ";
			int cover;
			cin >> cover;
			cover--;
			while (cover > rowcounter || cover < 0) {
				cout << cover << " is not initiated\nTry again: ";
				cin >> cover;
			}
			while (change(row[player][cover]) != change(decks[i][choice])) {
				cout << "These cards are not in the same catagory\n1)Change the card you want to pick\n2)change the player\n3)change the card you want to cover \nEnter command: ";
				int scommand;
				cin >> scommand;
				if (scommand == 1) {
					cout << "Enter the card: ";
					cin >> choice;
					choice--;
				}
				else if (scommand == 2) {
					cout << "Enter the player number: ";
					cin >> player;
					player--;
				}
				else if (scommand == 3) {
					cout << "Enter the card you want to cover: ";
					cin >> cover;
					cover--;
				}
			}
			row[player][cover] = decks[i][choice];
			decks[i][choice - 1] = cards[cardnum];
			cardnum--;
			for (int m = 0; m < rowcounter; m++) {
				for (int n = m + 1; n < rowcounter; n++) {
					if (row[i][m] == row[i][n]) {
						row[i][n] = row[i][rowcounter - 1];
						row[i][rowcounter - 1] = 0;
					}
				}
			}
			cout << "the command is done\nHere are his cards: ";

			for (int b = 0; b < rowcounter; b++) {
				cout << change(row[player][b]) << " " << val(row[player][b]) << " ";
			}
			cout << "\nEnter 1 to continue: ";
			cin >> choice;
			while (choice != 1) {
				cout << choice << " is not initiated\ntry again: ";
				cin >> choice;
			}
			system("cls");
		}
	}
	bool Is_over = false;
	int check = 0;
	for (m = 0; m < 6; m++) {
		for (int p = 0; p < 6; p++) {
			if (row[m][p] != 0) {
				check++;
			}
		}
		if (check == 5) {
			Is_over = true;
			break;
		}
		check = 0;
	}
	if (Is_over == true) {
		break;
	}
	round++;
}
cout << "Player " << m + 1 << " finished this round with having 6 rows in front of him";
int points[6] = { 0,0,0,0,0,0 };
for (int i = 0; i < num; i++) {
	int j = 0;
	while (row[i][j] != 0) {
		if (row[i][j] < 30)
			points[i] += row[i][j] + 1;
		else if (row[i][j] < 60)
			points[i] += row[i][j] - 29;
		else if (row[i][j] < 90)
			points[i] += row[i][j] - 59;
		j++;
	}
}
int max = points[0];
for (int i = 0; i < num; i++) {
	if (points[i] > max)
		max = points[i];
}
for (int i = 0; i < num; i++) {
	cout << "Player " << i + 1 << " finished the game with " << points[i] << " points\n";
}
for (int i = 0; i < num; i++) {
	if (max == points[i]) {
		cout << "Player " << i + 1 << " won this round\n";
	}
}
bool gameover = false;
for (int i = 0; i < num; i++) {
	total[i] += points[i];
	if (total[i] >= goal) {
		gameover = true;
	}
}
max = total[0];
for (int i = 0; i < num; i++) {
	if (total[i] > max)
		max = total[i];
}
if (gameover == true) {
	for (int i = 0; i < num; i++) {
		if (total[i] == max) {
			cout << "Player " << i << " won the game with " << max << " points";
			break;
		}
	}
	cout << "Enter your command \n1)Play again\n2)Exit\n";
	int lastchoice;
	cin >> lastchoice;
	if (lastchoice == 1) {
		system("cls");
		main();
	}
	else if (lastchoice == 2) {
		exit(0);
	}
}
else {
	cout << "Enter 1 to continue to the next round: ";
	int next;
	cin >> next;
	while (next != 1) {
		cout << next << " is not initiated\nTry again: ";
		cin >> next;
	}
	start(num, total, goal);
}

}
string change(int num) {
	if (num < 30)
		return "pumpkin";
	else if (num < 60)
		return "zombie";
	else if (num < 90)
		return "mummy";
}
int val(int number) {
	if (number < 30 && number >= 0)
		return number + 1;
	else if (number < 60)
		return number - 29;
	else if (number < 90)
		return number - 59;
}
int rowcounterr(int row[]) {
	int p = 0;
	while (row[p] != 0) {
		p++;
	}
	return p;
}
