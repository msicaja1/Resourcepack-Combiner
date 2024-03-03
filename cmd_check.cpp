#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int i, j;
    string lineCheck, cmd;

    // Open the JSON file
    ifstream ifs;
	ifs.open("check.txt");

    // Prepare to write onto temp file
    ofstream ofs;
    ofs.open("cmd_temp.txt");

    if (!ofs) { // Error for opening file
        cerr << "File open error\n";
        exit(0);
    }

    else {
        // Loop to get the custom model data
        for (i = 0; i < 17; ++i) {
            getline(ifs, lineCheck); // Get the currect line for reading
            for (j = 0; j < lineCheck.length(); ++j) { // Inner loop to read line character by character
                if (lineCheck[j] == '}') { // Stop reading once first } is read, as cmd is already obtained
                        break;
                }

                if (lineCheck[j] >= '0' && lineCheck[j] <= '9') { // Get the cmd and copy into temp file
                    cmd = lineCheck[j];
                    ofs << cmd;
                }
            }
            ofs << endl;
        }
    }
}