#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    int count = 0;
    srand((unsigned int)time(NULL));
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
        choice = 1 - min(choice, 1);
        count += choices[choice];
        choices.clear();
    }
    cout << count << endl;
    return 0;
}