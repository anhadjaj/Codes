#include<iostream>
using namespace std;
int main()
{
                cout<< endl;
				cout<< endl;
				cout<< endl;
				cout<< "The rules of the game are very simple: "<<endl;
				cout<< "1. For entering the coorinates remove the () and the , and just write the two numbers with space in between."<<endl;
				cout<< "For example: Input (1,2) as 1 2 "<<endl;
				cout<< "2. NO CHEATING."<<endl;

				cout<< endl;
				cout<< endl;

				string namep1, namep2;
				char charp1, charp2;
				cout<< "Hi, Player 1, Please enter your name here: ";
				cin>> namep1;
				cout<< "Hey, "<< namep1 << " please choose (X/O): ";
				cin >> charp1;
				if(charp1 == 'X')
				{
					charp2 = 'O';
				}
				else
				{
					charp2 = 'X';
				}

				cout<< "Hi, Player 2, Please enter your name here: ";
				cin>> namep2;


				char arr[3][3];
				for(int i = 0; i<3; i++)
				{
					for(int j = 0; j<3; j++)
					{
						arr[i][j] =  '?';
					}
					cout<< endl;
				}

				for(int i = 0; i<3; i++)
				{
					for(int j= 0; j<3; j++)
					{
						cout<< arr[i][j]<<"          ";
					}
					for(int z = 0; z<6; z++)
					{
						if(i == 2)
						{
							continue;
						}
						cout<< endl;
					}
				}
				cout<< endl;
				cout<< endl;
				cout<< endl;

				bool checkArr[3][3];
				for(int i = 0; i<3; i++)
				{
					for(int j = 0; j<3; j++)
					{
						checkArr[i][j] = false;
					}
				}

				int x1, y1; // x;
				int x2, y2; // o;
				int i = 1;
				bool isWin = false;
				char Winner;
				while(true)
				{
					cout<< namep1<< ", please enter the x and y coordinate to put a "<< charp1 << ": ";
					cin>> x1>> y1;
					if(checkArr[x1-1][y1-1] == true)
					{
						int &x = x1;
						int &y = y1;
						cout<< "-->That place already has a character. Please try agian: ";
						cin>> x>> y;
					}
					checkArr[x1-1][y1-1] = true;
					arr[x1-1][y1-1] = charp1;

						for(int i = 0; i<3; i++)
						{
							for(int j= 0; j<3; j++)
							{
								cout<< arr[i][j]<<"          ";
							}
							for(int z = 0; z<6; z++)
							{
								if(i == 2)
								{
									continue;
								}
								cout<< endl;
							}
						}
						cout<< endl;
						cout<< endl;
						
						
							if((arr[0][0] == charp1 && arr[0][1] == charp1 && arr[0][2] == charp1) || (arr[1][0] == charp1 && arr[1][1] == charp1 && arr[1][2] == charp1) || (arr[2][0] == charp1 && arr[2][1] == charp1 && arr[2][2] == charp1))
							{
								isWin = true;
								Winner = charp1;
							}

							if((arr[0][0] == charp1 && arr[1][0] == charp1 && arr[2][0] == charp1) || (arr[0][1] == charp1 && arr[1][1] == charp1 && arr[2][1] == charp1) || (arr[0][2] == charp1 && arr[1][2] == charp1 && arr[2][2] == charp1))
							{
								isWin = true;
								Winner = charp1;
							}
							if((arr[0][0] == charp1 && arr[1][1] == charp1 && arr[2][2] == charp1) || (arr[2][0] == charp1 && arr[1][1] == charp1 && arr[0][2] == charp1))
							{
								isWin = true;
								Winner = charp1;
							}
					if(isWin == true)
					{
						break;
					}
					cout<< namep2<< ", please enter the x and y coordinate to put a "<< charp2<<": ";
					cin>> x2>> y2;
					if(checkArr[x2-1][y2-1] == true)
					{
						int &x = x2;
						int &y = y2;
						cout<< "-->That place already has a character. Please try agian: ";
						cin>> x>> y;
					}
					checkArr[x2-1][y2-1] = true;
					arr[x2-1][y2-1] = charp2;

					for(int i = 0; i<3; i++)
					{
						for(int j= 0; j<3; j++)
						{
							cout<< arr[i][j]<<"          ";
						}
						for(int z = 0; z<6; z++)
						{
							if(i == 2)
							{
								continue;
							}
							cout<< endl;
						}
					}

					cout<< endl;
					cout<<endl;
						if((arr[0][0] == charp2 && arr[0][1] == charp2 && arr[0][2] == charp2) || (arr[1][0] == charp2 && arr[1][1] == charp2 && arr[1][2] == charp2) || (arr[2][0] == charp2 && arr[2][1] == charp2 && arr[2][2] == charp2))
							{
								isWin = true;
								Winner = charp2;
							}

							if((arr[0][0] == charp2 && arr[1][0] == charp2 && arr[2][0] == charp2) || (arr[0][1] == charp2 && arr[1][1] == charp2 && arr[2][1] == charp2) || (arr[0][2] == charp2 && arr[1][2] == charp2 && arr[2][2] == charp2))
							{
								isWin = true;
								Winner = charp2;
							}
							if((arr[0][0] == charp2 && arr[1][1] == charp2 && arr[2][2] == charp2) || (arr[2][0] == charp2 && arr[1][1] == charp2 && arr[0][2] == charp2))
							{
								isWin = true;
								Winner = charp2;
							}
					if(isWin == true)
					{
						break;
					}
					//while ends;
				}

				cout<< endl;
				cout<< endl;
				cout<< endl;
				cout<< endl;
				cout<< endl;
				cout<< "//// FINAL GRID ////"<<endl;
				cout<< endl;
				cout<< endl;
				for(int i = 0; i<3; i++)
				{
					for(int j= 0; j<3; j++)
					{
						cout<< arr[i][j]<<"          ";
					}
					for(int z = 0; z<6; z++)
					{
						if(i == 2)
						{
							continue;
						}
						cout<< endl;
					}
				}
				cout<< endl;
				cout<< endl;
				cout<< endl;
				cout<< endl;

				cout<< "-->>> According the the above result the winner is: ";
				if(Winner == charp1)
				{
					cout<< namep1<<endl;
				}
				else if(Winner == charp2)
				{
					cout<< namep2<<endl;
				}
				cout<< endl;
				cout<< endl;
				cout<< endl;
    return 0;
}