// Helmiriitta Vikman 
// 22TIETOB
// Harjoitustyˆ ñ C++ perusteet ñ Hotellihuoneen varausohjelma


#include<iostream>
#include<string>
#include<iomanip>
#include <cstdlib> 
#include <ctime>   


using namespace std;

//Globaaleja vakioita:

//Hotellihuoneiden m‰‰r‰ yhteens‰
const int HUONEET_MAX = 300;


//Yhden hengen huoneiden osuus hotellihuoneiden m‰‰r‰st‰
const int YHDEN_H_HUONEET_MAARA = 150;


//Kahden hengen huoneiden osuus hotellihuoneiden m‰‰r‰st‰
const int KAHDEN_H_HUONEET_MAARA = 150;


//Yhden hengen huoneiden huonenumerot 1-150
const int YHDEN_H_HUONEET_NRO_MIN = 1;
const int YHDEN_H_HUONEET_NRO_MAX = 150;


//Kahden hengen huoneiden huonenumerot 151-300
const int KAHDEN_H_HUONEET_NRO_MIN = 151;
const int KAHDEN_H_HUONEET_NRO_MAX = 300;

const int VARAUSNUMERO_MIN = 10000;
const int VARAUSNUMERO_MAX = 99999;


//Hotellihuoneiden struct
struct Huone {

	string varaaja;             //Huoneen varaajan nimi etunimi+sukunimi
	int varausnumero;           //Huoneen varauksen varausnumero/tunnus
	int huoneNumero;            //Huoneen numero
	int yot;                    //Varattujen ˆiden m‰‰r‰
	int hinta;                  //varauksen hinta
	bool varattu = false;       //onko huone varattu vai vapaa
};


//Hotellihuoneet taulukossa
Huone huoneet[300];


//Tarkistaa onko Hotellissa vapaita yhden hengen huoneita
bool TarkistaVapaanaOlevat1HHuoneet() {

	for (int i = YHDEN_H_HUONEET_NRO_MIN; i <= YHDEN_H_HUONEET_NRO_MAX; i++) {  // MAX=150

		if (!huoneet[i].varattu) {
			return true;
		}
	}
	return false;
}


//Tarkistaa onko Hotellissa vapaita kahden hengen huoneita
bool TarkistaVapaanaOlevat2HHuoneet() {

	for (int i = KAHDEN_H_HUONEET_NRO_MIN; 1 <= KAHDEN_H_HUONEET_NRO_MAX; i++) {  //MIN=151 & MAX=300

		if (!huoneet[i].varattu) {
			return true;
		}
	}
	return false;
}


//Tulostaa vapaat yhden hengen huoneet
void TulostaVapaanaOlevat1HHuoneet() {

	for (int i = YHDEN_H_HUONEET_NRO_MIN; i <= YHDEN_H_HUONEET_NRO_MAX; i++) {

		if (!huoneet[i].varattu) {
			cout << "\nHuone  " << i;
		}
	}
}


//Tulostaa vapaat kahden hengen huoneet
void TulostaVapaanaOlevat2HHuoneet() {

	for (int i = KAHDEN_H_HUONEET_NRO_MIN; i <= KAHDEN_H_HUONEET_NRO_MAX; i++) {

		if (!huoneet[i].varattu) {
			cout << "\nHuone " << i;
		}
	}
}


//Arpoo yhden hengen huoneista huonenumeron
void ArvoYhdenHengenHuonenumero() {

	srand(time(NULL));

	int huonenumero;

	huonenumero = rand() % 150 + 1;

	if (!huoneet[huonenumero].varattu) {
		cout << "\n" << huonenumero;
	}

	while (huoneet[huonenumero].varattu) {

		srand(time(NULL));

		huonenumero = rand() % 150 + 1;

		if (!huoneet[huonenumero].varattu) {
			cout << "\n" << huonenumero;
		}
	}
	huoneet[huonenumero].varattu = true;
	huoneet[huonenumero].huoneNumero = huonenumero;
}


//Arpoo kahden hengen huoneista huonenumeron
void ArvoKahdenHengenHuonenumero() {

	srand(time(NULL));

	int huonenumero;

	huonenumero = rand() % 300 + 151;

	if (!huoneet[huonenumero].varattu) {
		cout << "\n" << huonenumero;
	}
	while (huoneet[huonenumero].varattu) {

		srand(time(NULL));

		huonenumero = rand() % 300 + 151;

		if (!huoneet[huonenumero].varattu) {
			cout << "\n" << huonenumero;
		}
	}
	huoneet[huonenumero].varattu = true;
	huoneet[huonenumero].huoneNumero = huonenumero;
}


//Arpoo varausnumeron mik‰ on v‰lilt‰ 10000-99999 & tarkistaa onko se k‰ytˆss‰, jos on niin arpoo uuden jne
void ArpooVarausnumeron(int huonenumero) {


	bool arvoUusi = true;
	bool Varausnumerofound = false;
	int varausnumero;

	srand(time(NULL));

	varausnumero = rand() % 99999 + 10000;

	while (arvoUusi) {

		varausnumero = rand() % 99999 + 10000;

		for (int i = YHDEN_H_HUONEET_NRO_MIN; i <= KAHDEN_H_HUONEET_NRO_MAX; i++) {

			if (huoneet[i].varausnumero == varausnumero) {
				Varausnumerofound = true;
				break;
			}
		}
		if (!Varausnumerofound) {
			arvoUusi = false;
			break;
		}
	}
	huoneet[huonenumero].varausnumero = varausnumero;
}

//Tulostaa varauksen tiedot
void TulostaaVarauksenTiedot(int huonenumero) {

	cout << "\n\n VARAUKSEN TIEDOT";
	cout << "\n\nVarausnumero:\n" << huoneet[huonenumero].varausnumero;
	cout << "\n\nVaraaja:\n" << huoneet[huonenumero].varaaja;
	cout << "\n\nHuonenumero:\n" << huoneet[huonenumero].huoneNumero;
	cout << "\n\nVarattujen ˆiden m‰‰r‰:\n" << huoneet[huonenumero].yot;
	cout << "\n\nVarauksen hinta alennuksen j‰lkeen:\n" << huoneet[huonenumero].hinta;
}


//Arpoo mahdollisen alennuksen & laskee hinnan
void LaskeeHinnanJohonArpooMahdollinenAlennus(int huonenumero) {

	srand(time(0));

	// Arpoo numeron v‰lilt‰ 0 ja 2
	int maara = rand() % 3;

	double alennuskerroin;

	//Arvottujen numeroiden merkitys
	switch (maara)
	{
		// Ei alennusta!
	case 0:
		alennuskerroin = 1.0;
		break;
		//10% alennus
	case 1:
		alennuskerroin = 0.90;
		break;
		//20% alennus
	case 2:
		alennuskerroin = 0.80;
		break;
	default:
		alennuskerroin = -1;
		break;
	}

	//Varauksen hinta kun huone on yhden hengen huone
	if (huonenumero <= YHDEN_H_HUONEET_NRO_MAX) {
		int hinta = (100 * huoneet[huonenumero].yot) * alennuskerroin;

		huoneet[huonenumero].hinta = hinta;
	}

	//Varauksen hinta kun huone on kahden hengen huone
	if (huonenumero >= KAHDEN_H_HUONEET_NRO_MIN) {
		int hinta = (150 * huoneet[huonenumero].yot) * alennuskerroin;

		huoneet[huonenumero].hinta = hinta;
	}
}


//P‰‰ohjelma alkaa
int main() {

	setlocale(LC_ALL, "fi_FI");

	int toiminto, huonekoko, huonenumeron_valinta, huonenumero = 0, hakutyyppi, haevarausnumero = 0;

	string nimihaku;

	bool LopetaOhjelma = false;

	cout << "\n\n HOTELLI HELMI";

	while (!LopetaOhjelma) {

		cout << "\n\nMit‰ haluaisit tehd‰?";
		cout << "\n1: Tee varaus";
		cout << "\n2: Lopeta\n";
		cin >> toiminto;

		switch (toiminto) {

		case 1:

			cout << "\n\n HUONEEN VARAUS";
			cout << "\n\nValitse huonekoko:";
			cout << "\n1: Yhden hengen huone 100 euroa/yˆ";
			cout << "\n2: Kahden hengen huone 150 euroa/yˆ\n";
			cin >> huonekoko;

			if (huonekoko == 1) {
				TarkistaVapaanaOlevat1HHuoneet();
			}
			if (huonekoko == 2) {
				TarkistaVapaanaOlevat2HHuoneet();
			}
			cout << "\nHuonenumeron valinta: ";
			cout << "\n1: Arvo huonenumero";
			cout << "\n2: Valitse huonenumero\n";
			cin >> huonenumeron_valinta;

			if (huonenumeron_valinta == 1) {

				if (huonekoko == 1) {
					ArvoYhdenHengenHuonenumero();
				}

				else if (huonekoko == 2) {
					ArvoKahdenHengenHuonenumero();
				}
			}

			if (huonenumeron_valinta == 2) {

				if (huonekoko == 1) {
					TulostaVapaanaOlevat1HHuoneet();

				}
				else if (huonekoko == 2) {
					TulostaVapaanaOlevat2HHuoneet();
				}
				cout << "\nAnna haluamasi huoneen numero:\n";
				cin >> huonenumero;

				huoneet[huonenumero].varattu = true;
				huoneet[huonenumero].huoneNumero = huonenumero;
			}
			cout << endl;

			cout << "\n\nVaraajan nimi (Etunimi Sukunimi): \n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, huoneet[huonenumero].varaaja);


			cout << "\n\n÷iden m‰‰r‰: \n";
			cin >> huoneet[huonenumero].yot;


			ArpooVarausnumeron(huonenumero);

			LaskeeHinnanJohonArpooMahdollinenAlennus(huonenumero);

			TulostaaVarauksenTiedot(huonenumero);

			cout << "\n\nVarauksesi on tallennettu!";
			cout << "\nPalataan Hotellin etusivulle...";
			cout << "\n\n HOTELLI HELMI" << endl;
			break;

		case 2:
			string lopetetaanko;
			cout << "\nHaluatko varmasti lopettaa? (joo/ei)\n";
			cin >> lopetetaanko;
			if (lopetetaanko == "joo") {
				LopetaOhjelma = true;
			}


		}
	}
	return 0;

}
