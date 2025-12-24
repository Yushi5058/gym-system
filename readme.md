# Gym Management System

A console-based Gym Management System developed as an academic project. This application helps gym administrators manage members, employees, equipment, fitness programs, and weekly schedules efficiently.

## Features

### Members Management
- Add new members with personal details
- Search members by name
- Modify member information
- Delete members from the system
- Membership tiers: Premium and Regular
- Assign fitness programs to members

### Employees Management
- Add new employees with contact and work details
- Search employees by name
- Update employee information
- Remove employees from the system
- Track position, salary, and work schedules

### Equipment Management
- Add new equipment with descriptions
- Search equipment by name
- Update equipment details
- Delete equipment records
- Track purchase date, condition state, and location

### Programs Management
- Create fitness programs with details
- Search programs by name
- Modify program information
- Delete programs from the system
- Define duration, cost, and schedule for each program

### Schedule Management
- Define weekly gym schedules
- View current schedules
- Modify schedules for each day of the week

## Getting Started

### Requirements
- A C compiler (GCC, Clang, or any standard C compiler)
- Terminal or command line interface

### Compilation

```bash
gcc main.c -o gym-system
```

### Running the Program

```bash
./gym-system
```

## Usage

1. Upon launching the program, you will see the main menu:
   - [1] Members
   - [2] Employees
   - [3] Equipments
   - [4] Programs
   - [5] Schedule
   - [6] Payments

2. Select a category by entering the corresponding number

3. For each category, you can:
   - [1] Search - Find records by name
   - [2] Add - Create new records
   - [3] Delete - Remove records
   - [4] Modify - Update existing records

4. After each operation, choose whether to continue (y/n)

## Data Structures

The application uses the following structs to organize data:

- **members**: Stores member name, age, address, join date, membership fee, premium status, and assigned program
- **employees**: Stores employee name, address, email, position, salary, phone number, and schedule
- **equipments**: Stores equipment name, description, purchase date, condition state, and location
- **programs**: Stores program name, description, duration, cost, and schedule
- **schedules**: Stores weekly schedule for each day

## Project Structure

- `main.c` - Contains all source code including main function and all management modules

## Technical Details

- Language: C
- Memory Management: Dynamic allocation using `malloc` and `realloc`
- Input/Output: Console-based with `scanf` and `printf`
- String Handling: Standard library string functions for comparison and manipulation

## Authors

Developed as a team project for academic purposes.

## License

This project is created for educational purposes.
