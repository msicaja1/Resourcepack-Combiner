#include <iostream>
using namespace std;

int main()
{
    string word = "{ \"predicate\": {\"custom_model_data\": 5853}, \"model\": \"item/items/blunt\"}";

    /*
    string word;

    cout << "Enter phrase with number: ";
    cin >> word; */

    int i;

    for (i = 0; i < word.length(); ++i) {
        if (word[i] >= '0' && word[i] <= '9') {
            cout << word[i] << " ";
        }
    }

    cout << endl;

}