#include <iostream>
#include <fstream>
using namespace std;

class cmdCompiler
{
    private:
    ifstream ifs;
    ofstream ofs;
    int lines;
    //int cmdCollection[];

    public:

    // Get the number of lines in the JSON file for reading
    void cmdLineCount(string jsonName) {
        //Initialize lines to 0
        lines = 0;
        string temp;
        ifs.open(jsonName);

        while (!ifs.eof()) {
            getline(ifs, temp);
            lines++;
        }

        ifs.close();
        //cout << lines << endl;
    }

    void cmdGetter(string jsonName, int cmdCollection[]) {
        int i, j, cmdVal, collectionSize;
        int k = -1;
        string lineCheck;
        string cmd = "";
        string cmdWord = "custom_model_data";

        // Open the JSON file
	    ifs.open(jsonName);


        // Loop to get the custom model data
        for (i = 0; i < lines; ++i) {
            getline(ifs, lineCheck); // Get the currect line for reading

            if (lineCheck.find(cmdWord) != std::string::npos) { // if statement to make sure custom model data is the only thing copied
                ++k; // increments value of k for correct array placement
                for (j = 0; j < lineCheck.length(); ++j) { // Inner loop to read line character by character
                    if (lineCheck[j] == '}') { // Stop reading once first } is read, as cmd is already obtained
                            break;
                    }

                    if (lineCheck[j] >= '0' && lineCheck[j] <= '9') { // Copy the cmd digit by digit into cmd string
                        cmd += lineCheck[j];
                    }
                }
                cmdVal = stoi(cmd); // Convert string value to int
                cmdCollection[k] = cmdVal;
                cmd = ""; // Reset value of cmd string for next iteration
                ++collectionSize; // increment collectionSize to get size of array
            }
        }

        for (i = 0; i < collectionSize; ++i) {
            cout << cmdCollection[i] << endl;
        }
    }
};

int main()
{
    cmdCompiler cmd1, cmd2;
    string jsonName1, jsonName2;
    int cmdCollection1[5000], cmdCollection2[5000];

    cout << "Type the names of the JSON file you want to compile: ";
    cin >> jsonName1;
    cin >> jsonName2;


    jsonName1 += ".json";
    jsonName2 += ".json";

    cmd1.cmdLineCount(jsonName1);
    cmd1.cmdGetter(jsonName1, cmdCollection1);

    cout << "----------END-------------" << endl;

    cmd2.cmdLineCount(jsonName2);
    cmd2.cmdGetter(jsonName2, cmdCollection2);
}