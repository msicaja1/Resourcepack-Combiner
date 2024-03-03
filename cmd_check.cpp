#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs;
	ifs.open("check.txt");

    int i, cmd;
    string lineCheck;

    for (i = 0; i < 16; ++i) {
        getline(ifs, lineCheck);
        cout << lineCheck << endl;
    }
}