# ATM Banking System 🏦

A console-based ATM simulation system built with C++ that provides secure banking operations with a user-friendly interface.

## ✨ Features

### 🔐 Secure Authentication

- **Account Number & PIN Code** verification
- **Secure login system** with error handling
- **Session management** for logged-in users

### 💰 Banking Operations

- **Quick Withdraw**: Pre-defined amount options (20, 50, 100, 200, 400, 600, 800, 1000)
- **Normal Withdraw**: Custom amount input (multiples of 5 only)
- **Deposit**: Add funds to account
- **Balance Check**: View current account balance
- **Real-time balance updates** after each transaction

### 🖥️ User Interface

- **Clean console interface** with clear screen transitions
- **Formatted menu system** with intuitive navigation
- **Cross-platform support** (Windows & Linux/macOS)
- **Input validation** for all user entries

## 🚀 Getting Started

### Prerequisites

- C++ compiler (g++, clang++, or MSVC)
- C++11 or higher standard

### Compilation

```bash
g++ BankATM-CPP.cpp -o atm-system -std=c++11
```

### Execution

```bash
./atm-system
```

## 📁 File Structure

```text
atm-banking-system/
│
├── BankATM-CPP.cpp          # Main source code
├── Clients.txt              # Client database file
└── README.md               # Documentation
```

## 📊 Data Format

**Clients.txt Format**

```text
AccountNumber#//#PINCode#//#FullName#//#PhoneNumber#//#Balance
```

**Example Client Entry**

```text
12345#//#1111#//#John Doe#//#555-1234#//#1000.00
67890#//#2222#//#Jane Smith#//#555-5678#//#500.00
```

## 🎮 How to Use

**1. Login**

- Enter your account number
- Enter your 4-digit PIN code
- System validates credentials against Clients.txt

**2. Main Menu Options**

- [1] Quick Withdraw: Choose from pre-set amounts
- [2] Normal Withdraw: Enter custom amount (multiples of 5)
- [3] Deposit: Add money to your account
- [4] Check Balance: View current balance
- [5] Logout: End session and return to login

**3. Transaction Flow**

1. Select transaction type
2. Confirm transaction details
3. View updated balance
4. Return to main menu

## 🔧 Technical Features

**Cross-Platform Support**

```cpp
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
```

**Input Validation**

- Numeric input validation with error recovery
- Balance checking before withdrawals
- Amount validation (multiples of 5 for normal withdraw)
  **File Operations**
- Data persistence through text file storage
- Real-time updates to client balances
- Error handling for file operations

## 🛡️ Security Features

- PIN code protection
- Balance validation before transactions
- Transaction confirmation prompts
- No hardcoded credentials - all data externalized

## 📋 Menu Structure

**Quick Withdraw Options**

```text
[1] 20        [2] 50
[3] 100       [4] 200
[5] 400       [6] 600
[7] 800       [8] 1000
[9] Exit
```

**Main Menu**

```text
[1] Quick withdraw
[2] Normal withdraw
[3] Deposit
[4] Check balance
[5] Logout
```

## 🐛 Error Handling

- **Invalid login attempts** with clear error messages
- **Insufficient funds** prevention
- **Invalid amount** validation
- **File access errors** handling
- **Input validation** for all user entries

## 🚦 Usage Example

```text
===========================================
        Login screen
===========================================
Please, enter the account number: 12345
Please, enter the pin code: 1111

===========================================
        ATM Main menu screen
===========================================
[1] Quick withdraw.
[2] Normal withdraw.
[3] Deposit.
[4] Check balance.
[5] Logout.
===========================================
Choose what you want to do [1 to 5]: 1
```

## 🔄 Transaction Process

1. **Authentication** → Verify account number and PIN
2. **Menu Navigation** → Choose transaction type
3. **Amount Selection** → Enter or select amount
4. **Confirmation** → Confirm transaction details
5. **Execution** → Process transaction and update balance
6. **Feedback** → Show results and new balance

## 📝 Setup Instructions

1. **Create Clients.txt file** with client data
2. **Compile the program** with C++11 or higher
3. **Run the executable** and login with valid credentials
4. **Perform transactions** through the menu system

## 🎯 Sample Client Data

**Create Clients.txt with format:**

```text
1001#//#1234#//#Alice Johnson#//#555-1001#//#1500.00
1002#//#5678#//#Bob Williams#//#555-1002#//#2500.50
1003#//#9012#//#Carol Davis#//#555-1003#//#800.75
```

## ⚠️ Important Notes

- Ensure Clients.txt exists in the same directory
- File must have proper read/write permissions
- All amounts are validated before processing
- System uses console interface only

## 🤝 Contributing

1. Fork the repository
2. Create feature branch
3. Commit changes
4. Submit pull request

## 📄 License

This project is open source and available under the [MIT](LICENSE) License.
