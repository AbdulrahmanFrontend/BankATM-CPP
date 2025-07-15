# ATM System - Project Documentation  

[![ATM System](https://img.icons8.com/color/96/000000/atm.png)](https://en.wikipedia.org/wiki/ATM)

## Table of Contents  
- [Overview](#overview)  
- [Features](#features)  
- [Requirements](#requirements)  
- [Installation](#installation)  
- [Usage](#usage)  
- [Data Models](#data-models)  
- [License](#license)  
- [Contributors](#contributors)  

## Overview  
A C++ based ATM simulation system that provides a console interface for basic banking operations including withdrawals, deposits, and balance inquiries. The system demonstrates file handling for data persistence and basic security through account authentication.

## Features  

### 🔒 Authentication  
- Secure login with account number and PIN verification  
- Input validation to prevent invalid entries  

### 💰 Transaction Services  
- **Quick Withdraw**: 8 predefined amounts (20-1000)  
- **Normal Withdraw**: Custom amounts (multiples of 5)  
- **Deposit**: Add funds to account  
- **Balance Check**: View current balance  
- **Logout**: Secure session termination  

### 📊 Data Management  
- Client data stored in `Clients.txt`  
- Real-time balance updates  
- Structured data format using `#//#` delimiter  

## Requirements  
- C++ compiler (GCC, Clang, or MSVC) supporting C++11  
- 5MB disk space  
- Command-line interface  

## Installation  
1. Clone the repository:
```bash
git clone https://github.com/AbdulrahmanFrontend/BankATM-CPP.git
```
2. Open in Visual Studio:
    - Double-click BankATM-CPP.sln, OR
    - In VS: File → Open → Project/Solution → Select .sln file
3. Build & Run:
    - Press Ctrl + F5 (Run without debug) or F5 (Debug mode)

Usage
1. Login Screen:
```text
-----------------------------------
        Login Screen
-----------------------------------
Enter Account Number: A123
Enter PIN Code: 1234
```
2. Main Menu:
```text
===================================
        ATM Main Menu
===================================
[1] Quick Withdraw    [2] Normal Withdraw
[3] Deposit           [4] Check Balance
[5] Logout
===================================
```
3. Follow on-screen prompts for transactions.

Data Models

Client Structure
```cpp
struct stClient {
    string accountNum;    // Format: A000
    string pinCode;       // 4-digit PIN
    string name;          // Client full name
    string phone;         // Contact number
    double accountBalance;// Current balance
    bool markForLogin;    // Session flag
};
```

Data Format

Records are stored line-by-line in Clients.txt:
```text
A123#//#1234#//#John Doe#//#555-1234#//#5000.00
```
License

MIT License - See [LICENSE](LICENSE) for details.

Contributors

[Abdulrahman](https://github.com/AbdulrahmanFrontend)

⚠️ Note: This is a simulation for educational purposes only. Not intended for real financial transactions.
