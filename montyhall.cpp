#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    int count = 0;
    cout << "기존의 문을 그대로 선택할 것이라면 1, 옮긴다면 0" << '\n';
    bool doorChange = 0;
    cin >> doorChange;
    srand((unsigned int)time(NULL));
    if (doorChange == 0) {
        for (int n = 0; n < 10000; n++)
        {
            vector<int> choices;
            int newChoice;
            int goatDoor;
            choices.push_back(0);
            choices.push_back(0);
            choices.push_back(1);
            random_shuffle(choices.begin(), choices.end());
            int choice = rand() % 3;
            for (int i = 0; i < 3; i++) {
                if (choices[i] == 0 && choice != i)
                {
                    goatDoor = i;
                    break;
                }
            }
            if((goatDoor == 0 && choice == 1) || (goatDoor == 1 && choice == 0)) newChoice = 2;
            else if((goatDoor == 2 && choice == 1) || (goatDoor == 1 && choice == 2)) newChoice = 0;
            else if((goatDoor == 2 && choice == 0) || (goatDoor == 0 && choice == 2)) newChoice = 1;
            count += choices[newChoice];
            choices.clear();
        }
        cout << "스포츠카를 선택할 확률은 " << (double)count / 100 << "% 입니다.";
    }
    else {
        for (int n = 0; n < 10000; n++)
        {
            vector<int> choices;
            choices.push_back(0);
            choices.push_back(0);
            choices.push_back(1);
            random_shuffle(choices.begin(), choices.end());
            int choice = rand() % 3;
            choice = 1 - min(choice, 1);
            count += choices[choice];
            choices.clear();
        }
        cout << "스포츠카를 선택할 확률은 " << (double)count / 100 << "% 입니다.";
    }
    return 0;
}