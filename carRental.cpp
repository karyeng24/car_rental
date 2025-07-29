//Group75
//Group Member 1:	LIEW REN YI
//Student ID:		2300434
//Group Member 2:	FOO KAR YENG
//Student ID:		2300422
//Group Member 3:	NG CHENG XUEN
//Student ID:		2105147

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<windows.h> //deco purpose
#include<chrono> //deco purpose
#include<thread> //deco purpose
#include<conio.h> //deco purpose

using namespace std;

//admin
void adminMenu(); //menu module
void addCar(); //add module
bool checkPlateNumber(string plateNumber); //check module
void deleteCar(); //delete module
void viewCarAvailable(); //view module
void viewOnRoad(); //view module
void carReturn(); //return module
void viewTransactionHistory(string cusName); //search module


//customer
void customerLogin();//login module
void cusMenu(); //menu module
void viewCarAvailableCus(); // view module
void customerSelectCar(); //select and payment module
void viewInvoiceHistoryCus(); // search module
void tnc();//view module


//animation purpose
void fullScreen(); // deco purpose
void gotoxy(int x, int y); // deco purpose
void loadingAnimation(int duration); // deco purpose
void art(); // deco purpose
void loading(); // deco purpose

struct carType {
	string plateNo = "";
	string brand = "";
	string model = "";
	string colour = "";
	int carCapacity;
	int ratePerDay;
	char transmission;
	string avail = "";
}; //struct car

int main() {
	ifstream inFileAdminlogin;
	ofstream outFileLogin("CustomerLogin.txt", ios::app);
	string storedUsername, storedPassword, username, password;
	char mainChoice, cusChoice, quit;
	string usernameCus, passwordCus, passwordCon;
	bool found = false;

	fullScreen();
	art();
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN); //convert words in console into yellow colour

	cout << setw(85) << "Welcome to Benson Car Rental & Co.!" << endl;
	cout << setw(91) << "- Verify yourself as Admin (A) or Customer (C) -" << endl;
	cout << setw(73) << "Quit (Q) ?" << endl;
	cout << endl;
	cout << setw(69) << ">>>  "; //main menu design
	cin >> mainChoice;
	loadingAnimation(10); //loading animation
	if (mainChoice == 'A' || mainChoice == 'a') {
		system("CLS");

		inFileAdminlogin.open("AdminLogin.txt"); //login module
		if (inFileAdminlogin.is_open()) {
			do
			{
				art();
				cout << setw(69) << "Username: ";
				cin >> username;
				inFileAdminlogin >> storedUsername;
				cout << setw(69) << "Password: ";
				cin >> password;
				inFileAdminlogin >> storedPassword;
				inFileAdminlogin.ignore();
				if (username == storedUsername && password == storedPassword)
				{
					cout << endl;
					cout << endl;
					cout << setw(75) << " - Access Granted -" << endl;
					loading();
					gotoxy(50, 29);
					cout << "You will be directed to Admin Menu." << endl;
					gotoxy(52, 30);
					system("PAUSE");
					system("CLS");
					adminMenu();
				}
				else
				{
					cout << setw(75) << "- Access Denied -" << endl;
					loading();
					gotoxy(50, 29);
					cout << "You will be directed back to Main Menu." << endl;
					gotoxy(52, 30);
					system("PAUSE");
					system("CLS");
					main();

				}
			} while (username != storedUsername && password != storedPassword);
		}
		else
		{
			art();
			cout << setw(70) << "Username & Password are not created!" << endl;
			loading();
			cout << setw(70) << "Tips: Create a AdminLogin.txt!" << endl;
			gotoxy(45, 29);
			cout << "You will be directed back to Main Menu." << endl;
			gotoxy(52, 30);
			system("PAUSE");
			system("CLS");
			main();
		}
		inFileAdminlogin.close();
		system("CLS");
	}
	else if (mainChoice == 'C' || mainChoice == 'c') {
		system("CLS");
		art();
		cout << setw(87) << "====================================" << endl;
		cout << setw(87) << " Greetings to our beloved customer! " << endl;
		cout << setw(87) << "====================================" << endl;
		cout << setw(80) << "1. Register New Account" << endl;
		cout << setw(73) << "2. Login " << endl;
		cout << setw(79) << "3. Back to Main Menu." << endl;

		cout << endl;
		cout << setw(69) << ">>>  ";
		cin >> cusChoice;

		switch (cusChoice) {
		case '1': {
			system("CLS");
			art();
			cout << setw(83) << "- Please create a new Benson Account -" << endl;
			cout << setw(83) << "=======================================" << endl;
			cout << setw(66) << "Enter your username: ";
			cin >> usernameCus;
			system("CLS");
			do {
				art();
				cout << setw(83) << "- Please create a new Benson Account -" << endl;
				cout << setw(83) << "=======================================" << endl;
				cout << setw(66) << "Enter your username: " << usernameCus << endl;
				cout << setw(66) << "Enter your password: ";
				cin >> passwordCus;
				cout << setw(66) << "Confirm your password: ";
				cin >> passwordCon;

				if (passwordCus == passwordCon) {
					break;
				}
				else {
					gotoxy(52, 23);
					cout << "Password is not the same, please re-confirm password again" << endl;
					gotoxy(52, 30);
					system("PAUSE");
					system("CLS");
				}
			} while (passwordCus != passwordCon);

			if (outFileLogin.is_open()) {
				outFileLogin << usernameCus << " " << passwordCus << endl;
				outFileLogin.close();
				cout << setw(90) << "Account created successfully. Please log in to continue." << endl;
				gotoxy(52, 30);
				system("PAUSE");
				system("CLS");
				customerLogin();
			}
			else {
				cout << setw(90) << "Error: Unable to create account. Please try again." << endl;
				gotoxy(50, 29);
				cout << "You will be directed back to Main Menu." << endl;
				gotoxy(52, 30);
				system("PAUSE");
				system("CLS");
				main();
			}
		}
		case '2': {
			system("CLS");
			customerLogin();
		}
		case '3': {
			system("CLS");
			main();
		}
		default: {
			main();
		}
		}
	}
	else if (mainChoice == 'Q' || mainChoice == 'q') {
		system("CLS");
		art();
		cout << setw(77) << "Are you sure (Y/N)?";
		cout << endl;
		cout << setw(69) << ">>>  ";
		cin >> quit;
		if (quit == 'Y' || quit == 'y') {
			cout << setw(95) << "Thank you for choosing Benson Car Rental Rental & Co.!" << endl;
			gotoxy(52, 20);
			system("PAUSE");
			exit(0);
		}
		else if (quit == 'N' || quit == 'n') {
			system("CLS");
			main();
		}
		else {
			system("CLS");
			main();
		}
	}
	else {
		system("CLS");
		cout << setw(53) << "Please choose again..." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		main();
	}

	return 0;
}

void fullScreen() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD flags;
	CONSOLE_SCREEN_BUFFER_INFO info;

	// Get the current console screen buffer info
	GetConsoleScreenBufferInfo(console, &info);

	// Set the console display mode to full screen
	flags = info.dwSize.X == GetSystemMetrics(SM_CXSCREEN) && info.dwSize.Y == GetSystemMetrics(SM_CYSCREEN) ? 0 : CONSOLE_FULLSCREEN_MODE;
	SetConsoleDisplayMode(console, flags, NULL);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void loadingAnimation(int duration) {
	int counter = 0;
	string animation = "|/-\\";
	while (counter < duration) {
		gotoxy(60, 14);
		cout << "Initializing " << animation[counter % 4] << "\r";
		this_thread::sleep_for(chrono::milliseconds(100));
		counter++;
		system("CLS");
	}
	art();
	gotoxy(62, 14);
	cout << "Complete!" << endl;
	loading();
	system("CLS");
}
void art()
{
	ifstream inFileArt("Art.txt");
	string Lines = "";
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
	if (inFileArt)
	{
		while (inFileArt.good())
		{
			string TempLine;
			getline(inFileArt, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}
		cout << Lines;
	}
	inFileArt.close();
}
void loading() {
	for (int i = 0; i < 3; i++) {
		cout.flush(); // Flush the output stream
		std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Sleep for 500 milliseconds
	}
}


void adminMenu() {

	char choice;
	art();
	cout << right << setw(73) << "A. Add New Car." << endl;
	cout << right << setw(73) << "B. View Available Car." << endl;
	cout << right << setw(73) << "C. Delete Car." << endl;
	cout << right << setw(73) << "D. View On Road Car." << endl;
	cout << right << setw(73) << "E. View Rental History." << endl;
	cout << right << setw(73) << "F. Check IN / Check OUT Record." << endl;
	cout << right << setw(73) << "G. Back to Main Menu." << endl; //menu design

	cout << setw(67) << " >>>  ";
	cin >> choice;  // prompt admin to choose
	system("CLS"); //clear screen
	do {
		switch (choice) {
		case'A':
		case'a':
		{
			cin.ignore();
			addCar();
			break;
		}
		case'B':
		case'b':
		{
			cin.ignore();
			viewCarAvailable();
			break;
		}
		case 'C':
		case'c':
		{
			cin.ignore();
			deleteCar();
			break;
		}
		case 'D':
		case'd':
		{
			cin.ignore();
			viewOnRoad();
			break;
		}
		case'E':
		case'e':
		{
			string cusName = "";
			system("CLS");
			art();
			cin.ignore();
			cout << endl;
			cout << setw(85) << "Enter Customer Full Name to search transactions: "; //search through transaction history by input their Full Name
			getline(cin, cusName);
			viewTransactionHistory(cusName);
			break;
		}
		case'F':
		case'f':
		{
			cin.ignore();
			carReturn();
			break;
		}
		case'G':
		case'g':
		{
			main();
			break;
		}
		default:
		{
			system("CLS");
			cout << setw(60) << "Please choose again from (A - G)!" << endl;
			break;
		}
		}
	} while (choice > 'G' || choice > 'g');
}

void addCar() {
	system("CLS");
	ofstream outFileCar;
	char contUpdate;
	carType car;
	outFileCar.open("BensonCar.txt", ios::app); //open text file in append mode
	if (outFileCar.is_open()) {
		do {
			art();
			cout << setw(70) << "Car Plate Number: ";
			getline(cin, car.plateNo);
			if (checkPlateNumber(car.plateNo)) {
				cout << "\n\t\t\t\t\tThe car with plate number " << car.plateNo << " already exists." << endl;
				cout << "\t\t\t\t\t Please try again with a different plate number." << endl;
				gotoxy(52, 30);
				system("PAUSE");
				system("CLS");
				addCar();
			}
			cout << setw(70) << "Car Brand: "; //add car information
			getline(cin, car.brand);
			cout << setw(70) << "Car Model: ";
			getline(cin, car.model);
			cout << setw(70) << "Car Colour: ";
			cin >> car.colour;
			cout << setw(70) << "Car Capacity: ";
			cin >> car.carCapacity;
			cout << setw(70) << "Rate Per Day: ";
			cin >> car.ratePerDay;
			cout << setw(70) << "Transmission (Auto 'A' /Manual 'M'): ";
			cin >> car.transmission;
			cin.ignore();
			cout << setw(70) << "Availability: ";
			getline(cin, car.avail);

			outFileCar << car.plateNo << endl;	//write information in text file
			outFileCar << car.brand << endl;
			outFileCar << car.model << endl;
			outFileCar << car.colour << endl;
			outFileCar << car.carCapacity << endl;
			outFileCar << car.ratePerDay << endl;
			outFileCar << car.transmission << endl;
			outFileCar << car.avail << endl;

			cout << setw(70) << "Continue update? (Y/N): ";
			cin >> contUpdate;
			cin.ignore();
			system("CLS");
		} while (contUpdate == 'Y' || contUpdate == 'y'); //do while loop
		outFileCar.close();
		gotoxy(45, 29);
		cout << "You will be directed back to Admin Menu." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
	}
	else {
		art();;
		cout << setw(75) << "Unable to open file." << endl;
		loading();
		gotoxy(52, 30); //set position x and y
		system("PAUSE");
		system("CLS");
	}
	adminMenu(); //direct back to Admin Menu
}

bool checkPlateNumber(string plateNumber) { //check plate number while adding cars information to prevent duplication
	ifstream inFileCar;
	inFileCar.open("BensonCar.txt");
	string tempPlateNo;

	while (getline(inFileCar, tempPlateNo)) {
		if (tempPlateNo == plateNumber) {
			inFileCar.close();
			return true;
		}
		// ignore the remaining fields
		getline(inFileCar, tempPlateNo); // brand
		getline(inFileCar, tempPlateNo); // model
		getline(inFileCar, tempPlateNo); // colour
		getline(inFileCar, tempPlateNo); // capacity
		getline(inFileCar, tempPlateNo); // rate
		getline(inFileCar, tempPlateNo); // transmission
		getline(inFileCar, tempPlateNo); // availability
	}
	inFileCar.close();
	return false;
}

void viewCarAvailable() { //only available cars is displayed here
	ifstream inFileCar;
	inFileCar.open("BensonCar.txt");

	if (inFileCar.is_open()) {
		art();
		string a, b, c, d, e, f, g, h;
		cout << "\t\t=======================================================================================================" << endl;
		cout << "\t\tPlate Number  Brand        Model        Capacity     Colour    Rate Per Day  Transmission  Availability" << endl;
		cout << "\t\t=======================================================================================================" << endl;

		while (getline(inFileCar, a)) {
			getline(inFileCar, b);
			getline(inFileCar, c);
			getline(inFileCar, d);
			getline(inFileCar, e);
			getline(inFileCar, f);
			getline(inFileCar, g);
			getline(inFileCar, h);
			cout << "\t\t" << left << setw(14) << a << left << setw(13) << b << left << setw(13) << c << left << setw(13) << d << left << setw(13) << e << left << setw(13) << f << left << setw(14) << g << left << setw(15) << h << endl;

		}
		cout << "\t\t=======================================================================================================" << endl;
		inFileCar.close();
		gotoxy(45, 29);
		cout << "You will be directed back to Admin Menu." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
	}
	else {
		art();
		cout << setw(75) << "Unable to open file." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		loading();
		system("CLS");
	}

	adminMenu();
}

void deleteCar() { //delete cars using plate numbers
	ifstream inFileCar;
	ofstream outFileTemp;
	string carPlateNo, carPlateNoTemp, carBrand, carModel, carColour, carCapacity, carRate, carTransmission, carAvail;
	bool found = false;
	char confirm, choice;

	inFileCar.open("BensonCar.txt");
	outFileTemp.open("Temp.txt", ios::app);

	if (inFileCar.is_open() && outFileTemp.is_open()) {
		art();
		cout << "\t\t\t\t\t\tEnter Car Plate Number to be Deleted: ";
		getline(cin, carPlateNo);

		while (inFileCar >> carPlateNoTemp >> carBrand >> carModel >> carColour >> carCapacity >> carRate >> carTransmission >> carAvail) {
			if (carPlateNo != carPlateNoTemp) {
				outFileTemp << carPlateNoTemp << endl;
				outFileTemp << carBrand << endl;
				outFileTemp << carModel << endl;
				outFileTemp << carColour << endl;
				outFileTemp << carCapacity << endl;
				outFileTemp << carRate << endl;
				outFileTemp << carTransmission << endl;
				outFileTemp << carAvail << endl;
			}
			else {
				found = true;
				cout << "\n\t\t\t\t\tThe car with the following information will be deleted:" << endl; // display cars information to be deleted
				cout << "\n\t\t\t\t\tPlate Number: " << carPlateNoTemp << endl;
				cout << "\t\t\t\t\tBrand: " << carBrand << endl;
				cout << "\t\t\t\t\tModel: " << carModel << endl;
				cout << "\t\t\t\t\tColour: " << carColour << endl;
				cout << "\t\t\t\t\tCapacity: " << carCapacity << endl;
				cout << "\t\t\t\t\tRate Per Day: " << carRate << endl;
				cout << "\t\t\t\t\tTransmission: " << carTransmission << endl;
				cout << "\t\t\t\t\tAvailability: " << carAvail << endl;
				cout << "\n\t\t\t\t\tAre you sure you want to delete this car? (Y/N): ";

				cin >> confirm;
				cin.ignore();
				if (confirm == 'Y' || confirm == 'y') {
					cout << "\t\t\t\t\tCar successfully deleted." << endl;
				}
				else {
					outFileTemp << carPlateNoTemp << endl;
					outFileTemp << carBrand << endl;
					outFileTemp << carModel << endl;
					outFileTemp << carColour << endl;
					outFileTemp << carCapacity << endl;
					outFileTemp << carRate << endl;
					outFileTemp << carTransmission << endl;
					outFileTemp << carAvail << endl;
					cout << "\t\t\t\t\tDeletion Cancelled." << endl;

				}
			}
		}
		inFileCar.close();
		outFileTemp.close();
		remove("BensonCar.txt");
		rename("Temp.txt", "BensonCar.txt");
		if (!found) {
			cout << "\t\t\t\t\t\tCar with plate number \"" << carPlateNo << "\" not found." << endl; //prompt admin to input again when car plate number is not found
		}
		gotoxy(45, 29);
		cout << "You will be directed back to Admin Menu." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
	}
	else {
		art();
		cout << setw(75) << "Unable to open file." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
	}
	adminMenu();
}

void viewOnRoad() { //able to view cars which is on road operation
	ifstream inFile("OnRoad.txt");
	if (inFile.is_open()) {
		art();
		cout << "\t\t=======================================================================================================" << endl;
		cout << "\t\tPlate Number  Brand        Model        Capacity     Colour    Rate Per Day  Transmission  Availability" << endl;
		cout << "\t\t=======================================================================================================" << endl;

		string plateNo, brand, model, carCapacity, colour, ratePerDay, transmission, avail;
		while (getline(inFile, plateNo)) {
			getline(inFile, brand);
			getline(inFile, model);
			getline(inFile, carCapacity);
			getline(inFile, colour);
			getline(inFile, ratePerDay);
			getline(inFile, transmission);
			getline(inFile, avail);
			cout << "\t\t" << left << setw(14) << plateNo << left << setw(13) << brand << left << setw(13) << model << left << setw(13) << carCapacity << left << setw(13) << colour << left << setw(13) << ratePerDay << left << setw(14) << transmission << left << setw(15) << avail << endl;
		}

		cout << "\t\t=======================================================================================================" << endl;
		inFile.close();
	}
	else {
		art();
		cout << setw(75) << "Unable to open file." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		loading();
		system("CLS");
	}

	gotoxy(45, 29);
	cout << "You will be directed back to Admin Menu." << endl;
	gotoxy(52, 30);
	system("PAUSE");
	system("CLS");
	adminMenu();
}

void carReturn() { //only admin confirms the return of cars and set back the availability into 'YES'
	string plateNumber;
	bool foundCar = false;
	ifstream inFile("OnRoad.txt");
	ofstream outFile("Temp.txt");
	string line;
	ifstream inFileCar("BensonCar.txt");
	ofstream outFileCar("TempCar.txt");
	string plateNum, brand, model, capacity, colour, ratePerDay, transmission, availability;
	art();
	// Get the plate number of the car being returned
	cout << "\t\t\t\t\tEnter the plate number of the car being returned: ";
	cin >> plateNumber;

	if (inFile.is_open() && outFile.is_open()) {
		while (getline(inFile, line)) {
			if (line == plateNumber) {
				foundCar = true;

				// Update the availability of the car to "YES" in the Temp.txt file
				outFile << line << endl;
				for (int i = 0; i < 6; i++) {
					getline(inFile, line);
					outFile << line << endl;
				}
				outFile << "YES" << endl; // Update the availability of the car to "YES" in the BensonCar.txt file

				while (getline(inFileCar, plateNum)) {
					getline(inFileCar, brand);
					getline(inFileCar, model);
					getline(inFileCar, capacity);
					getline(inFileCar, colour);
					inFileCar >> ratePerDay;
					getline(inFileCar, transmission);
					getline(inFileCar, availability);

					if (plateNum == plateNumber) {
						outFileCar << plateNum << endl;
						outFileCar << brand << endl;
						outFileCar << model << endl;
						outFileCar << capacity << endl;
						outFileCar << colour << endl;
						outFileCar << ratePerDay << endl;
						outFileCar << transmission << endl;
						outFileCar << "YES" << endl;
					}
					else {
						outFileCar << plateNum << endl;
						outFileCar << brand << endl;
						outFileCar << model << endl;
						outFileCar << capacity << endl;
						outFileCar << colour << endl;
						outFileCar << ratePerDay << endl;
						outFileCar << transmission << endl;
						outFileCar << availability << endl;
					}
				}
				inFileCar.close();
				outFileCar.close();

				// Replace the BensonCar.txt file with the TempCar.txt file
				remove("BensonCar.txt");
				rename("TempCar.txt", "BensonCar.txt");
			}
			else {
				// Write the car's information back to the Temp.txt file
				outFile << line << endl;
				for (int i = 0; i < 6; i++) {
					getline(inFile, line);
					outFile << line << endl;
				}
				getline(inFile, line);
				outFile << line << endl;
			}
		}
		inFile.close();
		outFile.close();

		// If the car was found and updated, replace the OnRoad.txt file with the Temp.txt file
		if (foundCar) {
			remove("OnRoad.txt");
			rename("Temp.txt", "OnRoad.txt");
			cout << "\t\t\t\tCar with plate number " << plateNumber << " has been returned and is now available for rent." << endl;
			gotoxy(45, 29);
			cout << "You will be directed back to Admin Menu." << endl;
			gotoxy(52, 30);
			system("PAUSE");
			system("CLS");
			adminMenu();
		}
		else {
			cout << "\t\t\t\tError: car with plate number " << plateNumber << " was not found in the rental system." << endl;
			gotoxy(45, 29);
			cout << "You will be directed back to Admin Menu." << endl;
			gotoxy(52, 30);
			system("PAUSE");
			system("CLS");
			adminMenu();
		}
	}
	else {
		cout << "\t\t\t\t\tError: could not open file(s)." << endl;
		gotoxy(45, 29);
		cout << "You will be directed back to Admin Menu." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
		adminMenu();
	}
}

void viewTransactionHistory(string cusName) { //admin able to search through transactions history in text file to prevent any emergencies
	ifstream inFileBank("OnlineBanking.txt");
	bool found = false;
	string line;
	cout << "\t\t\t\t" << "=============================================================" << endl;
	if (inFileBank.is_open()) {

		while (getline(inFileBank, line)) {
			if (line.find("Customer Name: " + cusName) != string::npos) {
				found = true;
				cout << "\t\t\t\t\t" << line << endl;
				for (int i = 0; i < 6; i++) {
					getline(inFileBank, line);
					cout << "\t\t\t\t\t" << line << endl;
				}
				cout << "\t\t\t\t" << "=============================================================" << endl;
			}
		}

		inFileBank.close();
		if (!found) {
			cout << "\t\t\t\tNo transaction history found for " << cusName << endl;
		}
		gotoxy(52, 00);
		system("PAUSE");
		system("CLS");
		adminMenu();
	}
	else {
		cout << "\t\t\t\tUnable to open file." << endl;
	}
	gotoxy(52, 30);
	system("PAUSE");
	system("CLS");
	adminMenu();
}

void customerLogin() { //customer login menu
	art();
	ifstream inFileLogin("CustomerLogin.txt");
	string usernameCus, passwordCus, storedUsernameCus, storedPasswordCus;
	bool found = false;

	cin.ignore();
	cout << setw(83) << "Please enter your username here:" << endl; //username and password is needed
	cout << setw(69) << "Username: ";
	cin >> usernameCus;
	cout << setw(69) << "Password: ";
	cin >> passwordCus;

	if (inFileLogin.is_open()) {
		while (inFileLogin >> storedUsernameCus >> storedPasswordCus) {
			if (usernameCus == storedUsernameCus && passwordCus == storedPasswordCus) {
				found = true;
				loadingAnimation(10);
				art();
				cout << endl;
				cout << endl;
				cout << endl;
				cout << setw(74) << "Login successful. Welcome, " << usernameCus << "!" << endl;
				gotoxy(52, 30);
				system("PAUSE");
				cusMenu();
			}
		}
		inFileLogin.close();
	}
	if (!found) {
		cout << setw(74) << "Invalid login details. Please try again." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
		customerLogin();
	}
}

void cusMenu() { //allows customers to proceed rental procedure
	system("CLS");
	char choice;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN); // deco purpose
	art();
	cout << right << setw(73) << "1. View available car." << endl; //done
	cout << right << setw(73) << "2. Select your favourite car to rent." << endl;
	cout << right << setw(73) << "3. Invoice History" << endl;
	cout << right << setw(73) << "4. Terms & Conditions." << endl;
	cout << right << setw(73) << "5. Log Off." << endl;

	cout << setw(67) << " >>>  ";
	cin >> choice;
	system("CLS");
	do {
		switch (choice) {
		case'1':
		{
			cin.ignore();
			viewCarAvailableCus();
			break;
		}
		case'2':
		{
			cin.ignore();
			customerSelectCar();
			break;
		}
		case '3':
		{
			cin.ignore();
			viewInvoiceHistoryCus();
			break;
		}
		case'4':
		{
			tnc();
			break;
		}
		case'5':
		{
			system("CLS");
			main();
		}
		default:
		{
			system("CLS");
			cout << setw(60) << "Please choose again from (1 - 5)!" << endl;
			break;
		}
		}
	} while (choice > 5);
}

void viewCarAvailableCus() {//allows customer to view cars availability 
	ifstream inFileCar;
	inFileCar.open("BensonCar.txt");

	if (inFileCar.is_open()) {
		art();
		string a, b, c, d, e, f, g, h;
		cout << "\t\t=======================================================================================================" << endl;
		cout << "\t\tPlate Number  Brand        Model        Capacity     Colour    Rate Per Day  Transmission  Availability" << endl;
		cout << "\t\t=======================================================================================================" << endl;

		while (getline(inFileCar, a)) {
			getline(inFileCar, b);
			getline(inFileCar, c);
			getline(inFileCar, d);
			getline(inFileCar, e);
			getline(inFileCar, f);
			getline(inFileCar, g);
			getline(inFileCar, h);
			cout << "\t\t" << left << setw(14) << a << left << setw(13) << b << left << setw(13) << c << left << setw(13) << d << left << setw(13) << e << left << setw(13) << f << left << setw(14) << g << left << setw(15) << h << endl;

		}
		cout << "\t\t=======================================================================================================" << endl;
		inFileCar.close();
		gotoxy(45, 29);
		cout << "You will be directed back to Customer Menu." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
	}
	else {
		art();
		cout << setw(75) << "Unable to open file." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		loading();
		system("CLS");
	}
	cusMenu();
}

void customerSelectCar() { //allows customers to select their designated car to rent and proceed to payment page
	ifstream inFileCar("BensonCar.txt");
	ofstream outFileCar("OnRoad.txt", ios::app);
	string selectedPlateNumber, plateNumber, brand, model, capacity, colour, ratePerDay, transmission, availability;
	bool carFound = false;
	int rentalDuration, rentalFee;

	if (inFileCar.is_open() && outFileCar.is_open()) {
		art();
		cout << "\t\t=======================================================================================================" << endl;
		cout << "\t\tPlate Number  Brand        Model        Capacity     Colour    Rate Per Day  Transmission  Availability" << endl;
		cout << "\t\t=======================================================================================================" << endl;

		while (getline(inFileCar, plateNumber)) {
			getline(inFileCar, brand);
			getline(inFileCar, model);
			getline(inFileCar, capacity);
			getline(inFileCar, colour);
			getline(inFileCar, ratePerDay);
			getline(inFileCar, transmission);
			getline(inFileCar, availability);
			if (availability == "YES") {
				cout << "\t\t" << left << setw(14) << plateNumber << left << setw(13) << brand << left << setw(13) << model << left << setw(13) << capacity << left << setw(13) << colour << left << setw(13) << ratePerDay << left << setw(14) << transmission << left << setw(15) << availability << endl;
			}
		}
		string cusName, ic, phoneNo;
		cout << "\n\t\tPlease enter the plate number of the car you would like to rent: ";
		cin >> selectedPlateNumber;
		cout << "\t\tEnter your Full Name: ";
		cin.ignore();
		getline(cin, cusName);
		cout << "\t\tEnter your IC number: ";
		getline(cin, ic);
		cout << "\t\tEnter your phone number: ";
		getline(cin, phoneNo);
		cout << "\t\tPlease enter the rental duration (in days): ";
		cin >> rentalDuration;

		inFileCar.clear();
		inFileCar.seekg(0, ios::beg); // reset the file position indicator to the beginning of the input file, so that subsequent reads from the file will start from the beginning rather than the current position.

		ofstream tempFile("temp.txt"); //opens temp file to overwrite original file after delete
		while (getline(inFileCar, plateNumber)) {
			getline(inFileCar, brand);
			getline(inFileCar, model);
			getline(inFileCar, capacity);
			getline(inFileCar, colour);
			getline(inFileCar, ratePerDay);
			getline(inFileCar, transmission);
			getline(inFileCar, availability);

			if (plateNumber == selectedPlateNumber && availability == "YES") {
				carFound = true;
				rentalFee = stoi(ratePerDay) * rentalDuration; // calculate rental fee
				outFileCar << plateNumber << endl;
				outFileCar << brand << endl;
				outFileCar << model << endl;
				outFileCar << capacity << endl;
				outFileCar << colour << endl;
				outFileCar << ratePerDay << endl;
				outFileCar << transmission << endl;
				outFileCar << "ON ROAD" << endl;

			}
			tempFile << plateNumber << endl;
			tempFile << brand << endl;
			tempFile << model << endl;
			tempFile << capacity << endl;
			tempFile << colour << endl;
			tempFile << ratePerDay << endl;
			tempFile << transmission << endl;
			tempFile << availability << endl;
		}

		inFileCar.close();
		outFileCar.close();
		tempFile.close();

		if (carFound) {
			remove("BensonCar.txt");
			rename("temp.txt", "BensonCar.txt");
			cout << "\t\tCar selected successfully!" << endl;
			gotoxy(52, 30);
			system("PAUSE");
			system("CLS");
			art();

			// Display a receipt for the customer
			cout << "\t\t\t\t\t    B E N S O N   C A R   R E N T A L   S Y S T E M" << endl;
			cout << "\t\t\t\t\t=============================================================" << endl;
			cout << "\t\t\t\t\t                      OFFICIAL RECEIPT                       " << endl;
			cout << "\t\t\t\t\t=============================================================" << endl;
			cout << "\t\t\t\t\tCustomer Name: " << cusName << endl;
			cout << "\t\t\t\t\tIC Number: " << ic << endl;
			cout << "\t\t\t\t\tPhone Number: " << phoneNo << endl;
			cout << "\t\t\t\t\tPlate Number: " << selectedPlateNumber << endl;
			cout << "\t\t\t\t\tRental Duration: " << rentalDuration << " day(s)" << endl;
			cout << "\t\t\t\t\tRate Per Day: RM" << ratePerDay << endl;
			cout << "\t\t\t\t\tTotal Amount: RM" << rentalFee << endl;
			cout << "\t\t\t\t\t=============================================================" << endl;

			string cardNumber, expirationDate, cvv;
			double amountPaid, balance;
			// Get the customer's name and payment information
			do {
				system("CLS");
				art();
				cout << "\t\t\t\t\t    B E N S O N   C A R   R E N T A L   S Y S T E M" << endl;
				cout << "\t\t\t\t\t=============================================================" << endl;
				cout << "\t\t\t\t\t                      OFFICIAL RECEIPT                       " << endl;
				cout << "\t\t\t\t\t=============================================================" << endl;
				cout << "\t\t\t\t\tCustomer Name: " << cusName << endl;
				cout << "\t\t\t\t\tIC Number: " << ic << endl;
				cout << "\t\t\t\t\tPhone Number: " << phoneNo << endl;
				cout << "\t\t\t\t\tPlate Number: " << selectedPlateNumber << endl;
				cout << "\t\t\t\t\tRental Duration: " << rentalDuration << " day(s)" << endl;
				cout << "\t\t\t\t\tRate Per Day: RM" << ratePerDay << endl;
				cout << "\t\t\t\t\tTotal Amount: RM" << rentalFee << endl;
				cout << "\t\t\t\t\t=============================================================" << endl;
				cin.ignore();
				cout << "\t\t\t\t\tEnter your card number: ";
				getline(cin, cardNumber);
				cout << "\t\t\t\t\tEnter the expiration date (MM/YY): ";
				getline(cin, expirationDate);
				cout << "\t\t\t\t\tEnter the CVV: ";
				getline(cin, cvv);
				cout << "\t\t\t\t\tEnter the amount paid: RM";
				cin >> amountPaid;

				if (amountPaid == rentalFee) {
					cout << endl;
					cout << "\t\t\t\t\tTRANSACTION SUCCESSFUL" << endl;
					cout << "\t\t\t\t\t>>>>> Enjoy your trip!" << endl;
					gotoxy(52, 00);
					system("PAUSE");
					system("CLS");
				}
				else if (amountPaid > rentalFee) {
					balance = rentalFee - amountPaid;
					cout << endl;
					cout << "\t\t\t\t\t!!! ATTENTION !!!" << endl;
					cout << "\t\t\t\t\tYou have paid more than the rental fee!" << endl;
					cout << "\t\t\t\t\tThe balance RM" << balance << "will be transferred back to your bank account in 3 working days!" << endl;
					loading();
					cout << "\t\t\t\t\tTRANSACTION SUCCESSFUL" << endl;
					cout << "\t\t\t\t\t>>>>> Enjoy your trip!" << endl;
					gotoxy(52, 00);
					system("PAUSE");
					system("CLS");
				}
				else {
					balance = amountPaid - rentalFee;
					system("CLS");
					art();
					cout << endl;
					cout << "\t\t\t\t\t!!! ATTENTION !!!" << endl;
					cout << "\t\t\t\t\tYou have paid less than the rental fee!" << endl;
					cout << "\t\t\t\t\tThe balance RM" << balance << "is needed to transfer into Benson Car Rental & Co." << endl;
					loading();
					cout << "\t\t\t\t\tTRANSACTION UNSUCCESSFUL" << endl;
					cout << "\t\t\t\t\t>>>>> Directing back to payment page..." << endl;
					gotoxy(52, 00);
					system("PAUSE");
					system("CLS");
				}
			} while (amountPaid < rentalFee);

			ofstream outFileBank("OnlineBanking.txt", ios::app);
			if (outFileBank.is_open()) {
				outFileBank << "Customer Name: " << cusName << endl;
				outFileBank << "Phone Number: " << phoneNo << endl;
				outFileBank << "Card Number: " << cardNumber << endl;
				outFileBank << "Expiration Date: " << expirationDate << endl;
				outFileBank << "CVV: " << cvv << endl;
				outFileBank << "Amount Paid: $" << amountPaid << endl;
				outFileBank << "Car Rental: " << plateNumber << " (" << brand << " " << model << ")" << endl;
				outFileBank << "=============================================================" << endl;
				outFileBank << endl;
				outFileBank.close();
			}
			else {
				gotoxy(52, 20);
				cout << "Error: could not open file." << endl;
			}
		}
		else {
			gotoxy(50, 20);
			cout << "Invalid input or car unavailable." << endl;
		}
		gotoxy(52, 30);
		system("PAUSE");
		system("CLS");
	}
	else {
		art();
		gotoxy(52, 20);
		cout << setw(75) << "Unable to open file(s)." << endl;
		gotoxy(52, 30);
		system("PAUSE");
		loading();
		system("CLS");
	}
	cusMenu();
}

void viewInvoiceHistoryCus() { //allows customers to search their transactions by keying in their Full Name
	system("CLS");
	art();
	ifstream inFile("OnlineBanking.txt");
	string name, line;
	cout << "\t\t\t\t\tEnter your Full Name: ";
	getline(cin, name);

	if (inFile.is_open()) {

		bool found = false;
		cout << "\t\t\t\t=============================================================" << endl;
		while (getline(inFile, line)) {
			if (line.find("Customer Name: " + name) != string::npos) {
				found = true;
				cout << "\t\t\t\t\t" << line << endl;
				while (getline(inFile, line) && line != "=============================================================") {
					cout << "\t\t\t\t\t" << line << endl;
				}
				cout << "\t\t\t\t=============================================================" << endl;
			}
		}

		inFile.close();
		if (!found) {
			cout << "\t\t\t\tNo invoice history found for customer " << name << endl;
		}
	}
	else {
		cout << "\t\t\t\tUnable to open file" << endl;
	}
	gotoxy(52, 30);
	system("PAUSE");
	system("CLS");
	cusMenu();
}

void tnc() { //view T&C
	char tnc;
	art();
	cout << "                                        > T E R M S  &  C O N D I T I O N S  A P P L I E D <" << endl;
	cout << "          =============================================================================================================" << endl;
	cout << "            1. Age Limit: Customers must be at least 21 years of age to rent a car. In some cases, there may be a   " << endl;
	cout << "               surcharge for drivers under 25." << endl;
	cout << "            2. Valid Driver's License: Customers must have a valid driver's license that has been held for a minimum" << endl;
	cout << "               period, usually one or two years." << endl;
	cout << "            3. Payment: Customers are required to pay for the rental at the time of pickup. They may also be        " << endl;
	cout << "               required to leave a deposit, which is refundable upon return of the car." << endl;
	cout << "            4. Insurance: Car rental companies usually offer insurance options to customers. Customers are advised  " << endl;
	cout << "               to carefully review their insurance options and choose the one that best suits their needs." << endl;
	cout << "            5. Fuel: Customers are expected to return the car with the same amount of fuel that was in the tank     " << endl;
	cout << "               they received it. In some cases, the car rental company may offer a pre-paid fuel option." << endl;
	cout << "            6. Late Return: Customers are expected to return the car on time. Late returns may result in extra charges." << endl;
	cout << "            7. Additional Drivers: Additional drivers may be added to the rental agreement for an additional fee.   " << endl;
	cout << "            8. Mileage Limit: Customers may be limited to a certain number of miles per day or per rental.          " << endl;
	cout << "               Additional miles may be charged at a higher rate." << endl;
	cout << "            9. Use of the Vehicle: Customers are expected to use the vehicle in a responsible manner and follow all " << endl;
	cout << "               traffic laws. They may not use the car for racing, off-roading, or other dangerous activities." << endl;
	cout << "            10.Condition of the Vehicle: Customers are responsible for returning the car in the same condition as   " << endl;
	cout << "               it was received. Any damage to the car may result in additional charges." << endl;
	cout << "          =============================================================================================================" << endl;

	cout << "                                               Please agree to T&C before proceeding (A)" << endl;
	cout << "                                                               >>>>>  ";
	cin >> tnc;
	cout << "                                                       - THANK YOU FOR YOUR TIME -" << endl;
	gotoxy(52, 00);
	system("PAUSE");
	system("CLS");
	cusMenu();
}

