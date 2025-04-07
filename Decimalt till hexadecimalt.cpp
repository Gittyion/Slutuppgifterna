#include <iostream>

using namespace std;

// Funktionen omvandlar angivet positivt heltal till motsvarande hexadecimalt
string convertDecimal(int MyNum) {


    if (MyNum == 0) return "0"; // Specialla ifall angivet siffra är noll

    string hexResult = "";// Sträng som lagrar det slutgiltiga hexadecimala värdet
    char hexDigits[] = "0123456789ABCDEF"; // Lista på hexadecimal tecken (0 - f)

    // Så länge talet är större än noll, fortsätter den konvertera
    while (MyNum > 0) {
        int remainder = MyNum % 16; // Ta på redan resterna
        hexResult = hexDigits[remainder] + hexResult; // Lägger till motsvarande hexa - tecken i början av resultatet
        MyNum /= 16; // Dividerar talet med 16 för att förflytta det ett steg


    }
    return hexResult; // Returnerar det färdiga resultatet
}

int main() {
    int MyNumber;
    cout << "Ange ett tal: " << endl; // Ber användaren att ange ett tal till att omvandla
    cin >> MyNumber;


    if (MyNumber < 0) { // Om talet är mindre än noll, felmeddelar den 
        cout << "Angivet tal ska vara ett positivt heltal." << endl;// Skriver ut felmeddelanet
    }
    else {// Skriver ut det motsvarande hexadecimalt
        string MyValue = convertDecimal(MyNumber);
        cout << "Hexadecimalt: " << MyValue << endl;

    }
    return 0;
}
