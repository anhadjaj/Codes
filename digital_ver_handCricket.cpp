#include<iostream>
using namespace std;
int main()
{
                string user_toss, user_choice;
				bool user_win_toss = false, batting = false;
				int score = 0, score2 = 0;

				string tossList[] = {"heads", "tails"};
				string game_list[] = {"bat", "bowl"};

				cout << "Enter your call for the toss here: ";
				cin >> user_toss;

				srand(time(0));
				string toss_result = tossList[rand() % 2];
				cout << "It was a " << toss_result << endl;

				if (user_toss == toss_result) {
					cout << "You win the toss." << endl;
					user_win_toss = true;
					cout << "Enter whether you want to bat or bowl first: ";
					cin >> user_choice;
				}

				if (!user_win_toss) {
					int random_choice = rand() % 2;
					user_choice = game_list[random_choice];
					cout << "The computer decided to put you to: " << user_choice << " first." << endl;
				}

				if (user_choice == "bat") {
					batting = true;
					while (true) {
						int comp_response = rand() % 10 + 1;
						int hum_response;
						cout << "Enter your run response here: ";
						cin >> hum_response;

						if (comp_response == hum_response) {
							break;
						}

						cout << "Computer response was: " << comp_response << endl;
						score += hum_response;
					}
					cout << "------->Computer Bowled you." << endl;
					cout << "------->You made " << score << " and set a target of " << score + 1 << endl;
					if (score == 0) {
						cout << "------->The computer Ducked You." << endl;
					}
				} else if (user_choice == "bowl") {
					while (true) {
						int comp_response = rand() % 10 + 1;
						int hum_response;
						cout << "Enter your bowl response here: ";
						cin >> hum_response;

						if (comp_response == hum_response) {
							break;
						}

						cout << "Computer response was: " << comp_response << endl;
						score += comp_response;
					}
					cout << "------->You bowled the computer." << endl;
					cout << "------->The computer scored: " << score << " and your target is: " << score + 1 << endl;
					if (score == 0) {
						cout << "------->You Ducked the computer." << endl;
					}
				}

				// 2nd innings
				score2 = 0;

				if (user_choice == "bat") {
					user_choice = "bowl";
					while (true) {
						int comp_response = rand() % 10 + 1;
						int hum_response;
						cout << "Enter your bowl response here: ";
						cin >> hum_response;

						if (comp_response == hum_response) {
							break;
						}

						cout << "Computer response was: " << comp_response << endl;
						score2 += comp_response;

						if (score2 > score) {
							break;
						}
					}
					if (score2 == 0) {
						cout << "------->You Ducked the computer." << endl;
					}
				} else if (user_choice == "bowl") {
					user_choice = "bat";
					while (true) {
						int comp_response = rand() % 10 + 1;
						int hum_response;
						cout << "Enter your run response here: ";
						cin >> hum_response;

						if (comp_response == hum_response) {
							break;
						}

						cout << "Computer response was: " << comp_response << endl;
						score2 += hum_response;

						if (score2 == 0) {
							cout << "------->The computer Ducked you." << endl;
						}

						if (score2 > score) {
							break;
						}
					}
				}

				if (score == score2) {
					cout << "------->Its a draw." << endl;
				} else if (score > score2) {
					if (batting) {
						cout << "------->You Won." << endl;
					} else {
						cout << "------->Computer Won." << endl;
					}
				} else if (score2 > score) {
					if (batting) {
						cout << "------->Computer Won." << endl;
					} else {
						cout << "------->You Won." << endl;
					}
				}

    return 0;
}