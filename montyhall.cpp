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
            choices.push_back(0);
            choices.push_back(0);
            choices.push_back(1);
            random_shuffle(choices.begin(), choices.end());
            int choice = rand() % 3;
            for (int i = 0; i < 3; i++) {
                if (choices[i] == 0 && choice != i)
                {
                    choices.erase(choices.begin() + i);
                    break;
                }
            }
            random_shuffle(choices.begin(), choices.end());
            choice = 1 - min(choice, 1);
            count += choices[choice];
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