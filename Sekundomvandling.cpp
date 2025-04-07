#include <iostream>

using namespace std;

void* ptr = setlocale(LC_ALL, "Swedish_Sweden"); //Ändrar lokal till svenska

void convertSeconds(long long seconds) {
    const int Seconds_In_Minute = 60;//Antal sekundrar på en minut
    const int Seconds_In_Hour = Seconds_In_Minute * 60;//Antal sekunder på en timme
    const int Seconds_In_Day = Seconds_In_Minute * 24;//24 timmar på en dag
    const int Seconds_In_Year = Seconds_In_Day * 365; //Om det inte är skottår


    if (seconds <= 0) { //Kontrollerar att angivet tal är större än noll och felmeddelar
        cout << "OBS! Talet du angav var mindre än noll." << endl; 
    }
    else {
        //Konverterar sekunder till år,dagar,timmar, minuter och sekunder

        int years = seconds / Seconds_In_Year;
        seconds %= Seconds_In_Year;

        int days = seconds / Seconds_In_Day;
        seconds %= Seconds_In_Day;

        int hours = seconds / Seconds_In_Hour;
        seconds %= Seconds_In_Hour;

        int minutes = seconds / Seconds_In_Minute;
        seconds %= Seconds_In_Minute; //Kvarvarande sekundr

        //Skriver ut de omvandlade sekundrarna
        cout << "Konverterad tid: " <<
            years << " år, " <<
            days << " dagar, " <<
            hours << " timmar, " <<
            minutes << " minuter, " <<
            seconds << " sekunder." << endl;

    }
}

int main() {
    int long long seconds; // Variabel för att lagra användarens inmatning (antal sekunder)

    cout << "Ange sekunders: " << endl; // Ber användaren ange ett antal sekundrar att konvertera
    cin >> seconds;


    convertSeconds(seconds);//Anropar funktionen som gör omvandlingen och skirver ut resultatet

    return 0;
}
