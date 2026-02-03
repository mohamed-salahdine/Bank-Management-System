# Bank Management System (Console)

Simple console-based Bank Management System written in C++ (Visual Studio solution).

## Overview

This project is a small console application for managing clients, users, currencies and transfers. The solution file is `ConsoleApplication1.sln` and the main source files are under the `ConsoleApplication1/` directory.

## Requirements

- Microsoft Visual Studio (2017/2019/2022) or any C++ compiler supporting C++11.

## Build & Run

1. Open the solution: `ConsoleApplication1.sln` in Visual Studio.
2. Build the solution (`Build -> Build Solution`).
3. Run from Visual Studio or run the generated executable in the build output folder (for example `x64\Debug\ConsoleApplication1.exe`).

Alternatively, build from command line with MSBuild:

```powershell
msbuild ConsoleApplication1.sln /p:Configuration=Debug
```

## Data files

The application reads/writes several text files located in the `ConsoleApplication1/` folder (for example: `Users.txt`, `Currencies.txt`, `TransferLog.txt`). Keep backups before editing.

## Notes

- Sensitive info (e.g. usernames/passwords) appears in repository files — treat accordingly.

## Usage examples

Basic steps to build and run locally (Debug, x64):

```powershell
msbuild ConsoleApplication1.sln /p:Configuration=Debug /p:Platform=x64
.
Start-Process x64\Debug\ConsoleApplication1.exe
```

Example: create a new client and deposit

1. Run the app.
2. From the main menu select `1` (Clients) -> `1` (Add New Client).
3. Enter client details as prompted (name, ID, initial balance).
4. From main menu select `2` (Transactions) -> `1` (Deposit) and follow prompts.

Example: find a user

1. From the main menu select `4` (Users) -> `2` (Find User).
2. Enter the username or partial name when prompted.