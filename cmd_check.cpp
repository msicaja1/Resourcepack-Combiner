#include <iostream>
#include <fstream>
using namespace std;

class cmdCompiler
{
    private:
    ifstream ifs;
    ofstream ofs;
    int lines;

    public:

    // Get the number of lines in the JSON file for reading
    void cmdLineCount() {
        //Initialize lines to 0
        lines = 0;
        string temp;
        ifs.open("check.txt");

        while (!ifs.eof()) {
            getline(ifs, temp);
            lines++;
        }

        ifs.close();
        cout << lines << endl;
    }

    void cmdGetter() {
        int i, j;
        string lineCheck, cmd;

        // Open the JSON file
	    ifs.open("check.txt");

        // Prepare to write onto temp file
        ofs.open("cmd_temp.txt");

        if (!ofs) { // Error for opening file
            cerr << "File open error\n";
            exit(0);
        }

        else {
            // Loop to get the custom model data
            for (i = 0; i < lines; ++i) {
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
};

int main()
{
    cmdCompiler cmd1;

    cmd1.cmdLineCount();
    cmd1.cmdGetter();
}