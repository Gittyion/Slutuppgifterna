#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

void* ptr = setlocale(LC_ALL, "Swedish_Sweden"); //Ändrar lokal till svenska

//Antal valutor för valutakoden
const int ANTAL_VALUTOR = 4;

// Array som innehåller valutakoder (för att matcha mot filen)
string valutaKoder[ANTAL_VALUTOR] = { "USD", "EUR", "GBP", "THB" };

// Array som sparar valutakurser som läses in från filen
double valutaKurser[ANTAL_VALUTOR];


//funktion som läser in valutakurser
bool lasValutaKurser(const string& filnamn) {
	ifstream fil(filnamn); //Öppnar filen vid inläsning
	if (!fil) {
		cout << "Kunde inte öppna filen " << filnamn <<" !" << endl; //Felmeddelande om filen inte kunde öppnas 
		return false;//Stänger av programmet

     // Läser in valutakod samt kurs och sparar i arrays
	} for (int i = 0; i < ANTAL_VALUTOR; i++) {
	fil >> valutaKoder[i] >> valutaKurser[i];

	} fil.close();//Stänger filen
	return true; // Returnerar sant
}

//Funktion som skriver ut de olika valutan att omvandla till(anropas vid main funktionen)
void valutaMenu() {
	cout << "Välj valuta för omvandling från SEK: " << endl;
	cout << " 1. USD (Amerikanska dollar)" << endl;
	cout << " 2. EUR (Euro) " << endl;
	cout << " 3. GBP (Brittiska pund) " << endl;
	cout << " 4. THB (Thailändska baht) " << endl;
	
}

// Funktion för att omvandla SEK till en annan valuta
void valutaOmvandlare(int val, double sek) {
    if (val < 1 || val > ANTAL_VALUTOR) { // Felmeddelande om valet är mer eller mindre än 4 
        cout << "Fel: Ogiltigt val!" << endl;
        return;
    }
    int index = val - 1; //tar användarens val -1 för tillrätta för valutakoder[ANTAL_VALUTOR]
    double resultat = sek * valutaKurser[index]; //Omvandlar användarens givan tal till annan valuta
    cout << sek << " SEK motsvarar " << resultat << " " << valutaKoder[index] << endl; // Skriver ut användarens angivna antal och motsvarande valutan
}

int main() {

    string filnamn = "Valutakurser.txt"; // Anger filnamn till "Valutakurser.txt"

    //Försöker läsa in filen
   if (!lasValutaKurser(filnamn)) {
       cout << "Inga valutakurser kunde läsas in. Avslutar programmet." << endl; //Felmeddelande om filen inte kunde läsas in och avslutar progammet direkt
       return 1;
    }

    valutaMenu(); //Anropar menyn 

    int val;
    cout << "Ange ditt val (1-4): "; //Ber användaren att välja vilken valuta som ska omvandlas till
    cin >> val;

    double sek;
    cout << "Ange belopp i SEK: ";//Ber användaren att ange ett belopp (SEK) som ska omvandlas
    cin >> sek;

    valutaOmvandlare(val, sek); //Anropar funktionen som omvandlar det givna antalet och skriver ut det och motsvarande valutan

    return 0;
}
