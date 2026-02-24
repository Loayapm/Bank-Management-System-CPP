# Bank Management System (C++ Console Application)

## 📌 Overview

This project is a **console-based Bank Management System** developed in **C++** to practice and apply **Object-Oriented Programming (OOP)** concepts in a realistic scenario.

The system simulates real banking operations such as client management, user authentication, permissions, transactions, currency exchange, and logging.  
All data is persisted using **text files**, without relying on a database.

---

## 🎯 Project Objectives

- Apply core **C++ OOP principles** in a large-scale project
- Design a modular and maintainable console application
- Practice file handling and data persistence
- Implement role-based access control and logging
- Simulate real-world banking workflows

---

## 🧱 OOP Concepts Used

- Classes and Objects  
- Encapsulation  
- Inheritance  
- Polymorphism  
- Abstraction  
- Separation of concerns (Models / Managers / Screens)  
- Header–Source file structure (`.h` / `.cpp`)  

---

## ⚙️ Main Features

### 👥 Client Management
- Add, update, delete, find, and list clients  
- Deposit and withdraw money  
- Display total balances  

### 👤 User & Permission System
- Secure login system  
- Role-based permissions  
- Grant, revoke, clear, and list permissions  
- User activity tracking  

### 💱 Currency System
- List and search currencies  
- Update currency values  
- Currency exchange and calculator  

### 💸 Transactions
- Money transfers between clients  
- Transaction history  
- Transfer logs  

### 🧾 Logging & Security
- Login and transaction logging  
- Password hashing  
- Session management  

### 🖥 Console Interface
- Screen-based navigation system  
- Input validation  
- Colored console output  

---

## 📊 Feature Summary Table

| Module | Description |
|------|------------|
| Client Management | Create, update, delete, and manage bank clients |
| User Management | Login system with role-based permissions |
| Transactions | Deposit, withdraw, and transfer funds |
| Currency Exchange | Currency conversion and calculator |
| Logging | Login logs and transaction history |
| Security | Password hashing and permission checks |

---

```markdown
## 🗂 Project Structure (Simplified)

Bank-Management-System-CPP/  
│  
├── Source Files (.cpp)  
├── Header Files (.h)  
├── README.md  
├── LICENSE  
├── .gitignore  
├── Bank.vcxproj  
└── Bank.vcxproj.filters
```

---

## 💾 Data Storage

- Uses **text files** for persistent storage
- Data is loaded and saved during runtime
- No external database is required

---

## 🛠 Technologies Used

- **Language:** C++  
- **Paradigm:** Object-Oriented Programming (OOP)  
- **IDE:** Visual Studio  
- **Application Type:** Console Application  

---

## ▶️ How to Run the Project

1. Open the project using **Visual Studio**
2. Build the solution
3. Run the application
4. Follow the on-screen menu options

---

## 📚 What I Learned

- Designing large console applications
- Structuring software using OOP principles
- Managing complexity through modular design
- Implementing permission-based access control
- File handling and logging mechanisms
- Using Git and GitHub for version control

---

## 🚀 Possible Future Improvements

- Replace text files with a database
- Improve error handling
- Add unit testing
- Create a graphical user interface (GUI)

---
## 🔐 Security Note (Educational Purpose)

This project was developed **strictly for educational purposes**.

Password hashing is implemented using `std::hash` combined with a salt to demonstrate the **concept** of hashing and credential protection.  
However, this approach is **not secure** and **must not** be used in real-world or production systems.

In real applications, secure cryptographic algorithms such as **bcrypt**, **PBKDF2**, **Argon2**, or **scrypt** should be used, along with proper key stretching and security practices.

This implementation exists solely to support learning objectives related to OOP design and system structure.

## 👤 Author

**Luay Mahmoud**  
Computer Science Student  
C++ / Object-Oriented Programming Project
