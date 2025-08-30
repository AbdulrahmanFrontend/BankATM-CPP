#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
void pauseSystem() {
#ifdef _WIN32
  system("pause");
#else
  cout << "Press Enter to continue...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();
#endif
}
string readString(string message) {
  string word;
  cout << message;
  getline(cin >> ws, word);
  return word;
}
struct stClient {
  string accountNum;
  string pinCode;
  string name;
  string phone;
  double accountBalance;
  bool markForLogin = 0;
};
const string clientsFileName = "Clients.txt";
vector<string> splitString(string s1, string delim) {
  vector<string> vString;
  short pos = s1.find(delim);
  string sWord;                      // define a string variable
  while (pos != std::string::npos) { // use find() function to get the position
                                     // of the delimiters
    sWord = s1.substr(0, pos);       // store the word
    if (sWord != "")
      vString.push_back(sWord);
    s1.erase(
        0,
        pos + delim.length()); // erase() until position and move to next word.
    pos = s1.find(delim);
  }
  if (s1 != "")
    vString.push_back(s1); // it adds last word of the string.
  return vString;
}
stClient convertLineToRecord(string line, string separator = "#//#") {
  stClient client;
  vector<string> vClientData;
  vClientData = splitString(line, separator);
  client.accountNum = vClientData[0];
  client.pinCode = vClientData[1];
  client.name = vClientData[2];
  client.phone = vClientData[3];
  client.accountBalance = stod(vClientData[4]); // cast string to double
  return client;
}
vector<stClient> loadClientsDataFromFile() {
  vector<stClient> vClients;
  fstream myFile;
  myFile.open(clientsFileName, ios::in); // read Mode
  if (myFile.is_open()) {
    string line;
    stClient client;
    while (getline(myFile, line)) {
      client = convertLineToRecord(line);
      vClients.push_back(client);
    }
    myFile.close();
  }
  return vClients;
}
stClient currentClient;
bool findClientByAccountNumAndPinCode(string accountNum, string pinCode) {
  vector<stClient> vClients = loadClientsDataFromFile();
  for (stClient c : vClients)
    if (c.accountNum == accountNum && c.pinCode == pinCode) {
      currentClient = c;
      return 1;
    }
  return 0;
}
enum enATMMainMenuOptions {
  eQuickWithdraw = 1,
  eNormalWithdraw,
  eDeposit,
  eCheckBalance,
  eLogout
};
void showScreenTitle(string screenTitle) {
  clearScreen();
  cout << "===========================================\n";
  cout << "\t\t" << screenTitle << " screen\n";
  cout << "===========================================\n";
}
void showATMMainMenu();
void goBackToATMMainMenu() {
  pauseSystem();
  showATMMainMenu();
}
enum enQuickWithdrawOption {
  eTen = 1,
  eFifty,
  eOneHundred,
  eTwoHundreds,
  eFourHundreds,
  eSixHundreds,
  eEightHundreds,
  eOneThousand,
  eExit
};
double readNum(string message) {
  double num;
  cout << message;
  cin >> num;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\nInvalid number, enter a valid one: ";
    cin >> num;
  }
  return num;
}
void performQuickWithdrawOption(enQuickWithdrawOption quickWithdrawOption);
string convertRecordToLine(stClient client, string separator = "#//#") {
  string sClientRecord = "";
  sClientRecord += client.accountNum + separator;
  sClientRecord += client.pinCode + separator;
  sClientRecord += client.name + separator;
  sClientRecord += client.phone + separator;
  sClientRecord += to_string(client.accountBalance);
  return sClientRecord;
}
void saveClientsDataToFile(vector<stClient> vClients) {
  fstream myFile;
  myFile.open(clientsFileName, ios::out); // overwrite
  string dataLine;
  if (myFile.is_open()) {
    for (stClient c : vClients)
      if (!c.markForLogin) {
        dataLine = convertRecordToLine(
            c); // we only write records that are not marked for delete.
        myFile << dataLine << endl;
      }
    myFile.close();
  }
}
void depositAccountToClientByAccountNumber(double depositedAmount,
                                           bool quick = 1) {
  if (quick && -1 * depositedAmount > currentClient.accountBalance) {
    performQuickWithdrawOption((enQuickWithdrawOption) short(
        readNum("Amount exceeds the balance, you can't withdraw up to: " +
                to_string(currentClient.accountBalance) +
                ".\nPlease, enter another value is less to withdraw: ")));
    return;
  }
  vector<stClient> vClients = loadClientsDataFromFile();
  char answer;
  cout << "\n\nAre you sure you want to perform this transaction (y / n)?\n";
  cin >> answer;
  if (tolower(answer) == 'y') {
    for (stClient &c : vClients)
      if (c.accountNum == currentClient.accountNum) {
        c.accountBalance += depositedAmount;
        currentClient.accountBalance = c.accountBalance;
        cout << "\n\nDone successfully, new balance: " << c.accountBalance
             << ".\n";
        break;
      }
    saveClientsDataToFile(vClients);
  }
  goBackToATMMainMenu();
}
void showQuickWithdrawScreen();
void performQuickWithdrawOption(enQuickWithdrawOption quickWithdrawOption) {
  switch (quickWithdrawOption) {
  case enQuickWithdrawOption::eTen:
    depositAccountToClientByAccountNumber(-20);
    break;
  case enQuickWithdrawOption::eFifty:
    depositAccountToClientByAccountNumber(-50);
    break;
  case enQuickWithdrawOption::eOneHundred:
    depositAccountToClientByAccountNumber(-100);
    break;
  case enQuickWithdrawOption::eTwoHundreds:
    depositAccountToClientByAccountNumber(-200);
    break;
  case enQuickWithdrawOption::eFourHundreds:
    depositAccountToClientByAccountNumber(-400);
    break;
  case enQuickWithdrawOption::eSixHundreds:
    depositAccountToClientByAccountNumber(-600);
    break;
  case enQuickWithdrawOption::eEightHundreds:
    depositAccountToClientByAccountNumber(-800);
    break;
  case enQuickWithdrawOption::eOneThousand:
    depositAccountToClientByAccountNumber(-1000);
    break;
  case enQuickWithdrawOption::eExit:
    showATMMainMenu();
    break;
  default:
    showQuickWithdrawScreen();
  }
}
void showQuickWithdrawScreen() {
  showScreenTitle("Quick withdraw");
  cout << "\t[1] 20         [2] 50\n";
  cout << "\t[3] 100        [4] 200\n";
  cout << "\t[5] 200        [6] 600\n";
  cout << "\t[7] 800        [8] 1000\n";
  cout << "\t[9]Exit\n";
  cout << "===========================================\n";
  cout << "Your balance is " << currentClient.accountBalance << ".\n\n";
  if (currentClient.accountBalance < 20) {
    goBackToATMMainMenu();
    return;
  }
  performQuickWithdrawOption((enQuickWithdrawOption) short(
      readNum("Choose what to withdraw [1 to 8]: ")));
}
void showNormalWithdrawScreen() {
  showScreenTitle("Normal withdraw");
  cout << "Your balance is " << currentClient.accountBalance << ".\n\n";
  if (currentClient.accountBalance == 0) {
    goBackToATMMainMenu();
    return;
  }
  double withdrawAmount;
  do {
    withdrawAmount = readNum("\n\nPlease, enter an amount multiple of 5's: ");
    while (abs(withdrawAmount) > currentClient.accountBalance)
      withdrawAmount =
          readNum("Amount exceeds the balance, you can't withdraw up to: " +
                  to_string(currentClient.accountBalance) +
                  ".\nPlease, enter another value is less to withdraw: ");
  } while (int(withdrawAmount) % 5 != 0);
  depositAccountToClientByAccountNumber(withdrawAmount * (-1), 0);
}
void showDepositScreen() {
  showScreenTitle("Deposit");
  cout << "Your balance is " << currentClient.accountBalance << ".\n\n";
  double depositedAmount = readNum("\n\nPlease, enter deposit amount: ");
  depositAccountToClientByAccountNumber(depositedAmount, 0);
}
void checkBalance() {
  showScreenTitle("Check balance");
  cout << "Your balance is " << currentClient.accountBalance << ".\n\n";
  goBackToATMMainMenu();
}
void showLoginScreen();
void performATMMainMenuOption(enATMMainMenuOptions ATMMainMenuOption) {
  switch (ATMMainMenuOption) {
  case enATMMainMenuOptions::eQuickWithdraw:
    showQuickWithdrawScreen();
    break;
  case enATMMainMenuOptions::eNormalWithdraw:
    showNormalWithdrawScreen();
    break;
  case enATMMainMenuOptions::eDeposit:
    showDepositScreen();
    break;
  case enATMMainMenuOptions::eCheckBalance:
    checkBalance();
    break;
  case enATMMainMenuOptions::eLogout:
    showLoginScreen();
    break;
  default:
    showATMMainMenu();
  }
}
void showATMMainMenu() {
  clearScreen();
  cout << "===========================================\n";
  cout << "\t\tATM Main menu screen\n";
  cout << "===========================================\n";
  cout << "\t[1] Quick withdraw.\n";
  cout << "\t[2] Normal withdraw.\n";
  cout << "\t[3] Deposit.\n";
  cout << "\t[4] Check balance.\n";
  cout << "\t[5] Logout.\n";
  cout << "===========================================\n";
  performATMMainMenuOption((enATMMainMenuOptions) short(
      readNum("Choose what you want to do [1 to 5]: ")));
}
void showLoginScreen() {
  string accountNum, pinCode;
  bool loginFailed = 1;
  do {
    clearScreen();
    cout << "\n-----------------------------------\n";
    cout << "\tLogin screen";
    cout << "\n-----------------------------------\n";
    if (!loginFailed)
      cout << "Invalid account number/pin code!\n";
    accountNum = readString("Please, enter the account number: ");
    pinCode = readString("Please, enter the pin code: ");
    loginFailed = findClientByAccountNumAndPinCode(accountNum, pinCode);
  } while (!loginFailed);
  showATMMainMenu();
}
int main() {
  showLoginScreen();
  pauseSystem();
  return 0;
}