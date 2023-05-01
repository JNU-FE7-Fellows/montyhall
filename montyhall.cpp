#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
 
using namespace std;
 
int main()
{    int count = 0;
    srand((unsigned int)time(NULL));   
    for(int n = 0; n < 10000; n ++)
    {
        vector<int> choices;
        choices.push_back(0);
        choices.push_back(0);
        choices.push_back(1);
        
        random_shuffle(choices.begin(), choices.end());
    
    }
    // cout << count << endl;
    return 0;
}
