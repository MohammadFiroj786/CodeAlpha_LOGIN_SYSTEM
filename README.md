# 🔐 Login & Registration System (C++)

A clean, modular, and file-based **User Authentication System** implemented in C++.  
This project demonstrates secure user management techniques using basic file handling operations.

---

## 🧾 Overview

This application provides a lightweight login system capable of:

- Registering new users
- Validating credentials
- Updating passwords
- Displaying registered users (Admin mode)

It uses a simple text file (`users.txt`) as persistent storage, making it ideal for learning and demonstration purposes.

---

## ✨ Key Features

### ✅ User Registration
- Validates username  
- Prevents duplicate entries  
- Saves new users to file  

### ✅ Secure Login
- Maximum of **3 login attempts**  
- Validates username–password pair  
- Displays user-friendly error messages  

### ✅ Password Management
- Verifies existing password  
- Safely updates password using a temporary file  

### ✅ Admin Tools
- Displays all registered usernames  

---

## 📁 Data Storage Structure

**File:** `users.txt`  

---

## 🛠️ Technologies Used

- C++
- File Handling (`fstream`)
- Input Validation
- Basic Authentication Logic

---

## ▶️ Running the Program

### Compile:

g++ main.cpp -o login_app


📌 Notes
🚫 Passwords are stored in plain text (for demonstration only)

✅ In real systems, always use hashing (SHA-256, bcrypt)

✅ Avoid storing credentials in plain .txt files

👨‍💻 Author
Mohammad Firoj
Intern @ CodeAlpha

