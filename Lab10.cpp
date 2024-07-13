#include "fraction.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    cout << "Lab10" << endl;

    // Input/output files
    ifstream fin("input-1.txt");
    ofstream fout("output.txt");

    // Throw error if can't open input file
    if (!fin) {
        cerr << "Error opening input file!";
        system("pause");
        return 1;
    }

    while (fin.good()) {
        // Read in two fractions and the operator to perform
        Fraction fract1, fract2;
        char oper;
        fin >> fract1 >> oper >> fract2;

        // Print out original functions read in
        fout << fract1 << " " << oper << " " << fract2 << " = ";

        // Do math on them
        switch (oper) {
        case '+':
            fout << fract1 + fract2 << endl;
            break;

        case '-':
            fout << fract1 - fract2 << endl;
            break;

        case '*':
            fout << fract1 * fract2 << endl;
            break;

        case '/':
            fout << fract1 / fract2 << endl;
            break;

        case '=':
            if (fract1 == fract2)
                fout << "True" << endl;
            else
                fout << "False" << endl;
            break;

        default:
            cerr << "Unknown operator: " << oper << endl;
            break;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
