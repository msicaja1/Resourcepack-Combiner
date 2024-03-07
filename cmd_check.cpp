#include <iostream>
#include <fstream>
using namespace std;

class cmdCompiler
{
    private:
    ifstream ifs;
    ofstream ofs;
    int lines;
    int cmdCollection[];

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

    void cmdGetter(string jsonName) {
        int i, j, cmdVal, collectionSize;
        int k = -1;
        string lineCheck;
        string cmd = "";
        string cmdWord = "custom_model_data";

        // Open the JSON file
	    ifs.open("carrot_on_a_stick.json");


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
    cmdCompiler cmd1;
    string jsonName;

    cout << "Type the name of the JSON file you want to compile: ";
    cin >> jsonName;

    jsonName += ".json";

    cmd1.cmdLineCount(jsonName);
    cmd1.cmdGetter(jsonName);
}