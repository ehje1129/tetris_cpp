#include <iostream>
#include <conio.h>
#include <windows.h>

int getKey(){
    if (_kbhit()) {
		return _getch();
	}
	return -1;
}

class StartingPage {
public:
    StartingPage() {
        using namespace std;
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
        while (getKey()<0) ;
        system("cls");
    }
};

class GameBoard {
public:
    GameBoard() {
        using namespace std;
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "�������������\n";
        for (int i=0; i<30; i++){
            cout << "\t\t"; cout << "��                    ��\n";
        }
        cout << "\t\t"; cout << "�������������\n";
        while (getKey()<0) ;
    }
};

int main(){
    using namespace std;
    system("mode con cols=100 lines=40 | title ��Ʈ����");
    StartingPage();
    GameBoard();
    cout << "Hellow world!";
    getchar();
}