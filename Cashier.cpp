/****************************************************************

File: Cashier

Description: After stating 3 items by name, price, and quantity,
and tax, the program will show how all of these units convert out
and reveal the full price. After that, the user will enter the
money recieved to calculate how much change to be given in fewest
bills and coins.

Author: Katherine Vickstrom and Joshua Andrus


Class: CSCI 110-10

Date: August 30, 2015

I hereby certify that this program is entirely my own work.

*****************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	string item1, item2, item3; //These are the items
	double price1, price2, price3 = 0.0; //How much they cost
	int quantity1, quantity2, quantity3 = 0; //How many you are getting
	double taxRate = 0.0; //set the tax on the items 
	double taxValue = 0.0; //how much the tax equals
	double total1, total2, total3 = 0.0; //The total for one group of items
	double totalPrice = 0.0; //Total of all items before tax
	double totalWithTax = 0.0; // Total of all items after tax

	double moneyPaid, moneyChange = 0.0;
	int cents, changeBills, changeCoins;
	int bill100, bill50, bill20, bill10, bill5, bill1 = 0;
	int coinQuarter, coinDime, coinNickel, coinPenny = 0;

	cout << "------------------- Welcome to our store ----------------" << endl;
	cout << endl;

	//This will ask the user to enter in what they are shopping for
	cout << "What is being purchased? "; getline(cin, item1);
		cout << "How much does a " << item1 << " cost? $"; cin >> price1;
		cout << "How many " << item1 << "s are being purchased? "; cin >> quantity1;
		cout << endl; cin.ignore(); // endl is enter for organizing. cin.ignore prevents a command skip.
	cout << "What is being purchased? "; getline(cin, item2);
		cout << "How much does a " << item2 << " cost? $"; cin >> price2;
		cout << "How many " << item2 << "s are being purchased? "; cin >> quantity2;
		cout << endl; cin.ignore();
	cout << "What is being purchased? "; getline(cin, item3);
		cout << "How much does a " << item3 << " cost? $"; cin >> price3;
		cout << "How many " << item3 << "s are being purchased? "; cin >> quantity3;
		cout << endl;
	cout << "What's the current tax rate (%)? "; cin >> taxRate;
	cout << endl;
	
	//These calculate the totals for the products
	total1 = price1 * quantity1;
	total2 = price2 * quantity2;
	total3 = price3 * quantity3;
	totalPrice = total1 + total2 + total3;
	taxRate = taxRate / 100;
	taxValue = taxRate * totalPrice;
	totalWithTax = totalPrice + taxValue;

	cout << "---------------------- Cost Summary ---------------------" << endl;
	cout << endl;
	cout << left << setw(15) << "Item";
		cout << "     ";
		cout << right << setw(10) << "Unit Price";
		cout << "  ";
		cout << right << setw(10) << "Quantity";
		cout << "     ";
		cout << right << setw(10) << "Cost";
		cout << endl; //This is one line
	cout << left << setw(15) << "------";
		cout << "    ";
		cout << right << setw(11) << "-----------";
		cout << " ";
		cout << right << setw(11) << "-----------";
		cout << "    ";
		cout << right << setw(11) << "-----------";
		cout << endl;
	cout << left << setw(15) << item1;
		cout << "    $";
		cout << right << setw(10) << price1;
		cout << "  ";
		cout << right << setw(10) << quantity1;
		cout << "    $";
		cout << right << setw(10) << total1;
		cout << endl;
	cout << left << setw(15) << item2;
		cout << "    $";
		cout << right << setw(10) << price2;
		cout << "  ";
		cout << right << setw(10) << quantity2;
		cout << "    $";
		cout << right << setw(10) << total2;
		cout << endl;
	cout << left << setw(15) << item3;
		cout << "    $";
		cout << right << setw(10) << price3;
		cout << "  ";
		cout << right << setw(10) << quantity3;
		cout << "    $";
		cout << right << setw(10) << total3;
		cout << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << left << "Total before tax:";
		cout << right << setfill(' ') << setw(30) << "$";
		cout << right << setw(10) << totalPrice << endl;
	cout << left << "Tax:";
		cout << right << setfill(' ') << setw(43) << "$";
		cout << right << setw(10) << taxValue << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << left << "Total cost:";
		cout << right << setfill(' ') << setw(36) << "$";
		cout << right << setw(10) << totalWithTax << endl;

	//Now that the total has been calculated, its time to get the change and denominations
	cout << endl;
	cout << "Inform the customer on how much the total is." << endl;
	cout << "How much did the customer give you? $"; cin >> moneyPaid;
	cout << endl;

	while (moneyPaid < totalWithTax) {
		cout << "The ammount paid was innsufficient." << endl;
		cout << "Please inform the customer and enter the new amount: $";
		cin >> moneyPaid;
	}
	cout << endl;
	cout << "Calculating change..." << endl;

	moneyChange = moneyPaid - totalWithTax;

	cout << endl;
	cout << "---------------------" << endl;
	cout << left << "Change:   $";
	cout << right << setw(10) << moneyChange << endl;
	cout << "---------------------" << endl;
	cout << endl;

	cents = moneyChange * 100;
	changeBills = cents / 100;
	changeCoins = cents % 100;

	bill100 = changeBills / 100; //Takes out how many 100 bills in the change
		changeBills %= 100;			//Shows how much of it still remains.
	bill50 = changeBills / 50;
		changeBills %= 50;
	bill20 = changeBills / 20;
		changeBills %= 20;
	bill10 = changeBills / 10;
		changeBills %= 10;
	bill5 = changeBills / 5;
		changeBills %= 5;
	bill1 = changeBills;

	coinQuarter = changeCoins / 25;
		changeCoins %= 25;
	coinDime = changeCoins / 10;
		changeCoins %= 10;
	coinNickel = changeCoins / 5;
		changeCoins %= 5;
	coinPenny = changeCoins;

	cout << endl;
	cout << "Denominations..." << endl;
	cout << left << "$100 bills:";
		cout << right << setw(10) << bill100 << endl;
	cout << left << "$50 bills: ";
		cout << right << setw(10) << bill50 << endl;
	cout << left << "$20 bills: ";
		cout << right << setw(10) << bill20 << endl;
	cout << left << "$10 bills: ";
		cout << right << setw(10) << bill10 << endl;
	cout << left << "$5 bills:  ";
		cout << right << setw(10) << bill5 << endl;
	cout << left << "$1 bills:  ";
		cout << right << setw(10) << bill1 << endl;
	cout << left << "Quarters:  ";
		cout << right << setw(10) << coinQuarter << endl;
	cout << left << "Dimes:     ";
		cout << right << setw(10) << coinDime << endl;
	cout << left << "Nickels:   ";
		cout << right << setw(10) << coinNickel << endl;
	cout << left << "Pennies:   ";
		cout << right << setw(10) << coinPenny << endl;

	cout << endl;
	cout << endl;


		return 0;

}