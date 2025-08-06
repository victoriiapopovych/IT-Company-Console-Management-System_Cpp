# 👩‍💻 Course Project: IT Company Management Console System

This project is a console-based menu application designed for an IT company, supporting three types of users: Developer, Project Manager, and System Administrator. Each role has access to its own set of features after login.

---

## 🔐 Authorization

- On launch, the user enters their login and password
- Passwords are stored in the user profile and are individual
- After successful authentication, access to the role-specific menu is granted

---

## 👨‍💻 Developer Role

Available features:
- View Profile
- Book Workspace
- SysAdmin Team 
- Report Working Time
- Logout

### Profile includes:
- User Info
- Projects
- Level (Trainee, Middle, Senior)
- Skills
- Location
- Type of Work (Remote, Office, Hybrid)
- Benefit Package
- Devices

### Booking workspace:
- Calendar-based selection
- Choose day type: Working Day, Sick Leave, Vacation, Day Off
- If "Working Day" selected → enter working hours (if >8 → shows “Overtime”)
- For remote/hybrid workers: choose city, street, and desk

---

## 📋 Project Manager Role

Includes all developer features, plus:
- View/Edit Working Time of Employees
- View/Change Projects
- Modify Benefit Package

---

## 🛠️ System Administrator Role

Includes all developer features, plus:
- Edit Any User Profile
- Access to Control Panel (View/Delete Users)
- Manage Device Requests (Approve/Reject)

---

## 🧰 Tech Stack

- Language: C++
- Environment: Console Application
- OOP principles, menu-driven interface, user input validation

