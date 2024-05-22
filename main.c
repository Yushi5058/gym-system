#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char fullName[100], address[200], joinDate[15];
  float membershipFee;
  int age, isPremium, programId;
} members;

typedef struct {
  char fullName[100], address[200], email[25], position[25], schedule[25];
  int salary, number;
} employees;

typedef struct {
  char name[100], description[300], buyDate[15], state[50], location[100];
} equipments;

typedef struct {
  char name[100], description[200], duration[25], schedule[25];
  int cost;
} program;

typedef struct {
  char monday[25], tuesday[25], wednesday[25], thursday[25], friday[25],
      saturday[25], Sunday[25];
} schedules;

void membersAdd(int *pMembersSize, members **pMembersData);
void membersSearch(int *pMembersSize, members **pMembersData);
int membersSearchDelete(int *pMembersSize, members **pMembersData, int *pX);
void membersDelete(int *pMembersSize, members **pMembersData);
int membersSearchModify(int *pMembersSize, members **pMembersData, int *pX);
void membersModify(int *pMembersSize, members **pMembersData);
void membersprogram(int *pProgramSize, program **pProgramData,
                    members **pMembersData, int *pMembersSize);
void case1(int *pMembersSize, members **pMembersData, int *pProgramSize,
           program **pProgramData);
;

void employeesAdd(int *pEmployeesSize, employees **pEmployeesData);
void employeesSearch(int *pEmployeesSize, employees **pEmployeesData);
int employeesSearchDelete(int *pEmployeesSize, employees **pEmployeesData,
                          int *pX);
void employeesDelete(int *pEmployeesSize, employees **pEmployeesData);
int employeesSearchModify(int *pEmployeesSize, employees **pEmployeesData,
                          int *pX);
void employeesModify(int *pEmployeesSize, employees **pEmployeesData);
void case2(int *pEmployeesSize, employees **pEmployeesData);
void equipmentsAdd(int *pEquipmentsSize, equipments **pEquipmentsData);

void equipmentsSearch(int *pEquipmentsSize, equipments **pEquipmentsData);
int equipmentsSearchDelete(int *pEquipmentsSize, equipments **pEquipmentsData,
                           int *pX);
void equipmentsDelete(int *pEquipmentsSize, equipments **pEquipmentsData);
int equipmentsSearchModify(int *pEquipmentsSize, equipments **pEquipmentsData,
                           int *pX);
void equipmentsModify(int *pEquipmentsSize, equipments **pEquipmentsData);
void case3(int *pEquipmentsSize, equipments **pEquipmentsData);

void programsAdd(int *pProgramSize, program **pProgramData);
void programsSearch(int *pProgramSize, program **pProgramData);
int programsSearchDelete(int *pProgramSize, program **pProgramData, int *pX);
void programsDelete(int *pProgramSize, program **pProgramData);
int programsSearchModify(int *pProgramSize, program **pProgramData, int *pX);
void programsModify(int *pProgramSize, program **pProgramData);
void case4(int *pProgramSize, program **pProgramData);

void scheduleAdd(schedules *pSchedules);
void scheduleShow(schedules *pSchedules);
void scheduleModify(schedules *pSchedules);
void case5(schedules *schedules);

int main() {

  int choice1;
  char end;
  members *membersData = (members *)malloc(sizeof(members));
  int membersSize = 0;
  employees *employeesData = (employees *)malloc(sizeof(employees));
  int employeesSize = 0;
  equipments *equipmentsData = (equipments *)malloc(sizeof(equipments));
  int equipmentsSize = 0;
  program *programData = (program *)malloc(sizeof(program));
  int programSize = 0;
  schedules schedules;
  int scheduleCheck = 0;

  do {
    printf("[1] Members\n[2] Employees\n[3] Equipments\n[4] "
           "Programs\n[5] Schedule\n[6] Payments\nEnter your choice: ");
    char free;
    if (scanf(" %d", &choice1) == 1) {

    } else {
      scanf(" %s", &free);
    }

    switch (choice1) {
    case 1:
      case1(&membersSize, &membersData, &programSize, &programData);
      break;
    case 2:
      case2(&employeesSize, &employeesData);
      break;
    case 3:
      case3(&equipmentsSize, &equipmentsData);
      break;
    case 4:
      case4(&programSize, &programData);
      break;
    case 5:
      if (scheduleCheck) {
        case5(&schedules);
      } else {
        scheduleAdd(&schedules);
        scheduleCheck = 1;
      }
      break;
    case 6:

      break;
    default:
      printf("Please enter a number between 1 and 6 !\n");
      break;
    }

    do {
      printf("Do you want to continue ?(y/n) : ");
      scanf(" %s", &end);
      if (end != 'y' && end != 'n') {
        printf("Please just enter either 'y' or 'n' !\n");
      }
    } while (end != 'y' && end != 'n');
  } while (end == 'y');
  free(membersData);
  free(employeesData);
  free(equipmentsData);
  free(programData);
  return 0;
}

void membersprogram(int *pProgramSize, program **pProgramData,
                    members **pMembersData, int *pMembersSize) {
  char end, *valName;
  int val;
  printf("Choose the plan from these choices: \n");
  for (int i = 0; i < *pProgramSize; i++) {
    printf(" [%d] %s\n", i + 1, (*pProgramData)[i].name);
  }
  do {
    scanf(" %d", &val);
  } while (val <= 0 || val > *pProgramSize);
  val--;
  printf("Name: %s\n", (*pProgramData)[val].name);
  printf("Description : %s\n", (*pProgramData)[val].description);
  printf("Duration : %s\n", (*pProgramData)[val].duration);
  printf("Cost : %d\n", (*pProgramData)[val].cost);
  printf("Program's schedule: %s\n", (*pProgramData)[val].schedule);

  do {
    printf("Do you want to confirm ? (y/n)\n");
    scanf("%s", &end);
  } while (end != 'y' && end != 'n');

  if (end == 'y') {
    (*pMembersData)[*pMembersSize - 1].programId = val;
    (*pMembersData)[*pMembersSize - 1].membershipFee =
        (*pProgramData)[val].cost;
    if ((*pMembersData)[*pMembersSize - 1].isPremium) {
      (*pMembersData)[*pMembersSize - 1].isPremium += (15 / 100);
    }
  } else {
    membersprogram(pProgramSize, pProgramData, pMembersData, pMembersSize);
  }
}

void membersAdd(int *pMembersSize, members **pMembersData) {
  (*pMembersSize)++;
  *pMembersData =
      (members *)realloc(*pMembersData, sizeof(members) * (*pMembersSize));
  printf("Enter the name: ");
  scanf(" %[^\n]s", (*pMembersData)[*pMembersSize - 1].fullName);
  printf("Enter the age: ");
  scanf(" %d", &(*pMembersData)[*pMembersSize - 1].age);
  printf("Enter the address: ");
  scanf(" %[^\n]s", (*pMembersData)[*pMembersSize - 1].address);
  printf("Enter the tier (1 = premium, 0 = regular) : ");
  scanf(" %d", &(*pMembersData)[*pMembersSize - 1].isPremium);
  printf("Enter the join date (MM/DD/YYYY) : ");
  scanf(" %[^\n]s", (*pMembersData)[*pMembersSize - 1].joinDate);
}

void membersSearch(int *pMembersSize, members **pMembersData) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the member's name to search: ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pMembersSize; i++) {
    if (strcmp((*pMembersData)[i].fullName, nameSearch) == 0) {
      printf("Result :\n");
      printf("Age : %d\n", (*pMembersData)[i].age);
      printf("Address : %s\n", (*pMembersData)[i].address);
      printf("Tier : %s\n",
             (*pMembersData)[i].isPremium ? "Premium" : "Regular");
      printf("Program N°: %d\n", (*pMembersData)[i].programId);
      printf("Monthly payment : %.2f Dh\n", (*pMembersData)[i].membershipFee);
      printf("Join date : (MM/DD/YYYY) %s\n", (*pMembersData)[i].joinDate);
      isFound = 1;
    }
  }
  if (!isFound) {
    printf("Member not found\n");
  }
}

int membersSearchDelete(int *pMembersSize, members **pMembersData, int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the member's name to delete : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pMembersSize; i++) {
    if (strcmp((*pMembersData)[i].fullName, nameSearch) == 0) {
      *pX = i;
      isFound = 1;
    }
    if (!isFound) {
      printf("Member not found!\n");
    } else {
      printf("Member found!\n");
    }
  }
  return isFound;
}

void membersDelete(int *pMembersSize, members **pMembersData) {
  int x;
  if (membersSearchDelete(pMembersSize, pMembersData, &x)) {
    for (int i = x + 1; i < *pMembersSize; i++) {
      (*pMembersData)[i - 1] = (*pMembersData)[i];
    }
    (*pMembersSize)--;
    *pMembersData =
        (members *)realloc(*pMembersData, sizeof(members) * (*pMembersSize));
    printf("Member deleted!\n");
  }
}

int membersSearchModify(int *pMembersSize, members **pMembersData, int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the member's name to modify: ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pMembersSize; i++) {
    if (strcmp((*pMembersData)[i].fullName, nameSearch) == 0) {

      printf("Result :\n");
      printf("Age : %d\n", (*pMembersData)[i].age);
      printf("Address : %s\n", (*pMembersData)[i].address);
      printf("Tier : %s\n",
             (*pMembersData)[i].isPremium ? "Premium" : "Regular");
      printf("Join date : (MM/DD/YYYY) %s\n", (*pMembersData)[i].joinDate);
      isFound = 1;
      *pX = i;
    }
    if (!isFound) {
      printf("Member not found\n");
    }
  }
  return isFound;
}

void membersModify(int *pMembersSize, members **pMembersData) {
  int x, choice1;
  if (membersSearchModify(pMembersSize, pMembersData, &x)) {
    printf("[1] Name\n[2] Age\n[3] Address\n[4] Tier\n[5] Join date "
           "\nEnter your choice: ");
    char free;
    if (scanf(" %d", &choice1) == 1) {

    } else {
      scanf(" %s", &free);
    }
    switch (choice1) {
    case 1:
      printf("Enter the new name : ");
      scanf(" %[^\n]s", ((*pMembersData)[x].fullName));
      break;
    case 2:
      printf("Enter the new age : ");
      scanf(" %d", &((*pMembersData)[x].age));
      break;
    case 3:
      printf("Enter the new address : ");
      scanf(" %[^\n]s", ((*pMembersData)[x].address));
      break;
    case 4:
      printf("Enter the new tier : ");
      scanf(" %d", &((*pMembersData)[x].isPremium));
      break;
    case 5:
      printf("Enter the new join date : (MM/DD/YYYY) ");
      scanf(" %[^\n]s", ((*pMembersData)[x].joinDate));
      break;
    default:
      printf("Please enter a number between 1 and 5 !\n");
      break;
    }
  }
}

void case1(int *pMembersSize, members **pMembersData, int *pProgramSize,
           program **pProgramData) {
  int choice2;
  printf("[1] Search\n[2] Add\n[3] Delete\n[4] Modify\nEnter "
         "your choice: ");
  char free;
  if (scanf(" %d", &choice2) == 1) {

  } else {
    scanf(" %s", &free);
  }
  switch (choice2) {
  case 1:
    membersSearch(pMembersSize, pMembersData);
    break;
  case 2:
    membersAdd(pMembersSize, pMembersData);
    membersprogram(pProgramSize, pProgramData, pMembersData, pMembersSize);
    break;
  case 3:
    membersDelete(pMembersSize, pMembersData);
    break;
  case 4:
    membersModify(pMembersSize, pMembersData);
    break;
  default:
    printf("Please enter a number between 1 and 4 !\n");
    break;
  }
}

void employeesAdd(int *pEmployeesSize, employees **pEmployeesData) {
  (*pEmployeesSize)++;
  *pEmployeesData = (employees *)realloc(*pEmployeesData,
                                         sizeof(employees) * (*pEmployeesSize));
  printf("Enter the name : ");
  scanf(" %[^\n]s", ((*pEmployeesData)[*pEmployeesSize - 1].fullName));
  printf("Enter the address : ");
  scanf(" %[^\n]s", ((*pEmployeesData)[*pEmployeesSize - 1].address));
  printf("Enter the email : ");
  scanf(" %[^\n]s", ((*pEmployeesData)[*pEmployeesSize - 1].email));
  printf("Enter the telephone's number :  ");
  scanf(" %d", &((*pEmployeesData)[*pEmployeesSize - 1].number));
  printf("Enter the position : ");
  scanf(" %[^\n]s", ((*pEmployeesData)[*pEmployeesSize - 1].position));
  printf("Enter the salary : ");
  scanf(" %d", &((*pEmployeesData)[*pEmployeesSize - 1].salary));
  printf("Enter the work's schedule : ");
  scanf(" %[^\n]s", ((*pEmployeesData)[*pEmployeesSize - 1].schedule));
}

void employeesSearch(int *pEmployeesSize, employees **pEmployeesData) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the employee's name to search : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pEmployeesSize; i++) {
    if (strcmp((*pEmployeesData)[i].fullName, nameSearch) == 0) {
      printf("Result :\n");
      printf("Address : %s\n", (*pEmployeesData)[i].address);
      printf("Email : %s\n", (*pEmployeesData)[i].email);
      printf("Telephone's number : %d\n", (*pEmployeesData)[i].number);
      printf("Position : %s\n", (*pEmployeesData)[i].position);
      printf("Salary : %d\n", (*pEmployeesData)[i].salary);
      printf("Work's schedule : %s\n", (*pEmployeesData)[i].schedule);
      isFound = 1;
    }
  }
  if (!isFound) {
    printf("Employee not found\n");
  }
}

int employeesSearchDelete(int *pEmployeesSize, employees **pEmployeesData,
                          int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the employee's name to delete : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pEmployeesSize; i++) {
    if (strcmp((*pEmployeesData)[i].fullName, nameSearch) == 0) {
      *pX = i;
      isFound = 1;
    }
    if (!isFound) {
      printf("Empoyee found !\n");
    } else {
      printf("Employee not found !\n");
    }
  }
  return isFound;
}

void employeesDelete(int *pEmployeesSize, employees **pEmployeesData) {
  int x;
  if (employeesSearchDelete(pEmployeesSize, pEmployeesData, &x)) {
    for (int i = x + 1; i < *pEmployeesSize; i++) {
      (*pEmployeesData)[i - 1] = (*pEmployeesData)[i];
    }
    (*pEmployeesSize)--;
    *pEmployeesData = (employees *)realloc(
        *pEmployeesData, sizeof(employees) * (*pEmployeesSize));
    printf("Employee deleted !\n");
  }
}

int employeesSearchModify(int *pEmployeesSize, employees **pEmployeesData,
                          int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the employee's name to modify : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pEmployeesSize; i++) {
    if (strcmp((*pEmployeesData)[i].fullName, nameSearch) == 0) {
      printf("Result :\n");
      printf("Address : %s\n", (*pEmployeesData)[i].address);
      printf("Email : %s\n", (*pEmployeesData)[i].email);
      printf("Telephone's number : %d\n", (*pEmployeesData)[i].number);
      printf("Position : %s\n", (*pEmployeesData)[i].position);
      printf("Salary : %d\n", (*pEmployeesData)[i].salary);
      printf("Work's schedule : %s\n", (*pEmployeesData)[i].schedule);
      isFound = 1;
      *pX = i;
    }
    if (!isFound) {
      printf("Employee not found\n");
    }
  }
  return isFound;
}

void employeesModify(int *pEmployeesSize, employees **pEmployeesData) {
  int x, choice1;
  if (employeesSearchModify(pEmployeesSize, pEmployeesData, &x)) {
    printf("[1] Name\n[2] Address\n[3] Email\n[4] Telephone's number\n[5] "
           "Position\n[6] Salary\n[7] Schedule\nEnter your choice: ");
    char free;
    if (scanf(" %d", &choice1) == 1) {

    } else {
      scanf(" %s", &free);
    }
    switch (choice1) {
    case 1:
      printf("Enter the new name : ");
      scanf(" %[^\n]s", (*pEmployeesData)[x].fullName);
      break;
    case 2:
      printf("Enter the new address : ");
      scanf(" %[^\n]s", (*pEmployeesData)[x].address);
      break;
    case 3:
      printf("Enter the new email : ");
      scanf(" %[^\n]s", (*pEmployeesData)[x].email);
      break;
    case 4:
      printf("Enter the new telephone's number : ");
      scanf(" %d", &((*pEmployeesData)[x].number));
      break;
    case 5:
      printf("Enter the new position : ");
      scanf(" %[^\n]s", (*pEmployeesData)[x].position);
      break;
    case 6:
      printf("Enter the new salary : ");
      scanf(" %d", &(*pEmployeesData)[x].salary);
      break;
    case 7:
      printf("Enter the new schedule : ");
      scanf(" %[^\n]s", (*pEmployeesData)[x].schedule);
      break;
    default:
      printf("Please enter un number between 1 and 7 !\n");
      break;
    }
  }
}

void case2(int *pEmployeesSize, employees **pEmployeesData) {
  int choice2;
  printf("[1] Search\n[2] Add\n[3] Delete\n[4] Modify\nEnter "
         "your choice: ");
  char free;
  if (scanf(" %d", &choice2) == 1) {

  } else {
    scanf(" %s", &free);
  }
  switch (choice2) {
  case 1:
    employeesSearch(pEmployeesSize, pEmployeesData);
    break;
  case 2:
    employeesAdd(pEmployeesSize, pEmployeesData);
    break;
  case 3:
    employeesDelete(pEmployeesSize, pEmployeesData);
    break;
  case 4:
    employeesModify(pEmployeesSize, pEmployeesData);
    break;
  default:
    printf("Please enter a number between 1 and 4 !\n");
    break;
  }
}

void equipmentsAdd(int *pEquipmentsSize, equipments **pEquipmentsData) {
  (*pEquipmentsSize)++;
  *pEquipmentsData = (equipments *)realloc(
      *pEquipmentsData, sizeof(equipments) * (*pEquipmentsSize));
  printf("Enter the equipment's name: ");
  scanf(" %[^\n]s", ((*pEquipmentsData)[*pEquipmentsSize - 1].name));
  printf("Enter the description : ");
  scanf(" %[^\n]s", ((*pEquipmentsData)[*pEquipmentsSize - 1].description));
  printf("Enter the buy date (MM/DD/YYYY) : ");
  scanf(" %[^\n]s", ((*pEquipmentsData)[*pEquipmentsSize - 1].buyDate));
  printf("Enter the state : ");
  scanf(" %[^\n]s", ((*pEquipmentsData)[*pEquipmentsSize - 1].state));
  printf("Enter the location :");
  scanf(" %[^\n]s", ((*pEquipmentsData)[*pEquipmentsSize - 1].location));
}

void equipmentsSearch(int *pEquipmentsSize, equipments **pEquipmentsData) {
  char nameSearch[100];
  int k = 0, isFound = 0;
  printf("Enter the equipment's name to search : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pEquipmentsSize; i++) {
    if (strcmp((*pEquipmentsData)[i].name, nameSearch) == 0) {
      printf("Result :\n");
      printf("Description : %s\n", (*pEquipmentsData)[i].description);
      printf("Buy date : (MM/DD/YYYY) %s\n", (*pEquipmentsData)[i].buyDate);
      printf("State : %s\n", (*pEquipmentsData)[i].state);
      printf("Location : %s\n", (*pEquipmentsData)[i].location);
      isFound = 1;
    }
  }
  if (!isFound) {
    printf("Equipment not found\n");
  }
}

int equipmentsSearchDelete(int *pEquipmentsSize, equipments **pEquipmentsData,
                           int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the equipment's name to delete : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pEquipmentsSize; i++) {
    if (strcmp((*pEquipmentsData)[i].name, nameSearch) == 0) {
      *pX = i;
      isFound = 1;
    }
    if (!isFound) {
      printf("Equipment not found !\n");
    } else {
      printf("Equipment found !\n");
    }
  }
  return isFound;
}

void equipmentsDelete(int *pEquipmentsSize, equipments **pEquipmentsData) {
  int x;
  if (equipmentsSearchDelete(pEquipmentsSize, pEquipmentsData, &x)) {
    for (int i = x + 1; i < *pEquipmentsSize; i++) {
      (*pEquipmentsData)[i - 1] = (*pEquipmentsData)[i];
    }
    (*pEquipmentsSize)--;
    *pEquipmentsData = (equipments *)realloc(
        *pEquipmentsData, sizeof(equipments) * (*pEquipmentsSize));
    printf("Equipment deleted !\n");
  }
}

int equipmentsSearchModify(int *pEquipmentsSize, equipments **pEquipmentsData,
                           int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the equipment's name to modify : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pEquipmentsSize; i++) {
    if (strcmp((*pEquipmentsData)[i].name, nameSearch) == 0) {
      printf("Result :\n");
      printf("Description : %s\n", (*pEquipmentsData)[i].description);
      printf("Buy date : (MM/DD/YYYY) %s\n", (*pEquipmentsData)[i].buyDate);
      printf("State : %s\n", (*pEquipmentsData)[i].state);
      printf("Location : %s\n", (*pEquipmentsData)[i].location);
      isFound = 1;
      *pX = i;
    }
    if (!isFound) {
      printf("Equipment not found\n");
    }
  }
  return isFound;
}

void equipmentsModify(int *pEquipmentsSize, equipments **pEquipmentsData) {
  int x, choice1;
  if (equipmentsSearchModify(pEquipmentsSize, pEquipmentsData, &x)) {
    printf("[1] Name\n[2] Description\n[3] Buy date\n[4] State\n[5] "
           "Location\nEnter your choice: ");
    char free;
    if (scanf(" %d", &choice1) == 1) {

    } else {
      scanf(" %s", &free);
    }
    switch (choice1) {
    case 1:
      printf("Enter the new name : ");
      scanf(" %[^\n]s", ((*pEquipmentsData)[x].name));
      break;
    case 2:
      printf("Enter the new description : ");
      scanf(" %[^\n]s", ((*pEquipmentsData)[x].description));
      break;
    case 3:
      printf("Enter the new buy date (MM/DD/YYYY) : ");
      scanf(" %[^\n]s", ((*pEquipmentsData)[x].buyDate));
      break;
    case 4:
      printf("Enter the new state : ");
      scanf(" %[^\n]s", ((*pEquipmentsData)[x].state));
      break;
    case 5:
      printf("Enter the new location : ");
      scanf(" %[^\n]s", ((*pEquipmentsData)[x].location));
      break;
    default:
      printf("Please enter a number between 1 and 5 !\n");
      break;
    }
  }
}

void case3(int *pEquipmentsSize, equipments **pEquipmentsData) {
  int choice2;
  printf("[1] Search\n[2] Add\n[3] Delete\n[4] "
         "Modify\nEnter your choice: ");
  char free;
  if (scanf(" %d", &choice2) == 1) {

  } else {
    scanf(" %s", &free);
  }
  switch (choice2) {
  case 1:
    equipmentsSearch(pEquipmentsSize, pEquipmentsData);
    break;
  case 2:
    equipmentsAdd(pEquipmentsSize, pEquipmentsData);
    break;
  case 3:
    equipmentsDelete(pEquipmentsSize, pEquipmentsData);
    break;
  case 4:
    equipmentsModify(pEquipmentsSize, pEquipmentsData);
    break;
  default:
    printf("Please enter a number between 1 and 4 !\n");

    break;
  }
}

void programsAdd(int *pProgramSize, program **pProgramData) {
  (*pProgramSize)++;
  *pProgramData =
      (program *)realloc(*pProgramData, sizeof(program) * (*pProgramSize));
  printf("Enter the program's name : ");
  scanf(" %[^\n]s", (*pProgramData)[*pProgramSize - 1].name);
  printf("Enter the description : ");
  scanf(" %[^\n]s", (*pProgramData)[*pProgramSize - 1].description);
  printf("Enter the duration : ");
  scanf(" %[^\n]s", (*pProgramData)[*pProgramSize - 1].duration);
  printf("Enter the schedule : ");
  scanf(" %[^\n]s", (*pProgramData)[*pProgramSize - 1].schedule);
  printf("Enter the cost : ");
  scanf(" %d", &((*pProgramData)[*pProgramSize - 1].cost));
}

void programsSearch(int *pProgramSize, program **pProgramData) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the program's name to search : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pProgramSize; i++) {
    if (strcmp((*pProgramData)[i].name, nameSearch) == 0) {
      printf("Result :\n");
      printf("Description : %s\n", (*pProgramData)[i].description);
      printf("Duration : %s\n", (*pProgramData)[i].duration);
      printf("Cost : %d\n", (*pProgramData)[i].cost);
      printf("Program's schedule : %s\n", (*pProgramData)[i].schedule);
      isFound = 1;
    }
  }
  if (!isFound) {
    printf("Program not found\n");
  }
}

int programsSearchDelete(int *pProgramSize, program **pProgramData, int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the program's name to delete : ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pProgramSize; i++) {
    if (strcmp((*pProgramData)[i].name, nameSearch) == 0) {
      *pX = i;
      isFound = 1;
    }
    if (!isFound) {
      printf("Program not found !\n");
    } else {
      printf("Program found !\n");
    }
  }
  return isFound;
}

void programsDelete(int *pProgramSize, program **pProgramData) {
  int x;
  if (programsSearchDelete(pProgramSize, pProgramData, &x)) {
    for (int i = x + 1; i < *pProgramSize; i++) {
      (*pProgramData)[i - 1] = (*pProgramData)[i];
    }
    (*pProgramSize)--;
    *pProgramData =
        (program *)realloc(*pProgramData, sizeof(program) * (*pProgramSize));
    printf("Program deleted !\n");
  }
}

int programsSearchModify(int *pProgramSize, program **pProgramData, int *pX) {
  char nameSearch[100];
  int isFound = 0;
  printf("Enter the program's name to modify: ");
  scanf(" %[^\n]s", nameSearch);

  for (int i = 0; i < *pProgramSize; i++) {
    if (strcmp((*pProgramData)[i].name, nameSearch) == 0) {

      printf("Result :\n");
      printf("Description : %s\n", (*pProgramData)[i].description);
      printf("Duration : %s\n", (*pProgramData)[i].duration);
      printf("Cost : %d\n", (*pProgramData)[i].cost);
      printf("Program's schedule: %s\n", (*pProgramData)[i].schedule);
      isFound = 1;
      *pX = i;
    }
    if (!isFound) {
      printf("Program not found\n");
    }
  }
  return isFound;
}

void programsModify(int *pProgramSize, program **pProgramData) {
  int x, choice1;
  if (programsSearchModify(pProgramSize, pProgramData, &x)) {
    printf("[1] Name\n[2] Description\n[3] Duration\n[4] Cost\n[5] Schedule\n "
           "Entrez votre choix: ");
    char free;
    if (scanf(" %d", &choice1) == 1) {

    } else {
      scanf(" %s", &free);
    }
    switch (choice1) {
    case 1:
      printf("Enter the new program's name : ");
      scanf(" %[^\n]s", (*pProgramData)[x].name);
      break;
    case 2:
      printf("Enter the new description : ");
      scanf(" %[^\n]s", (*pProgramData)[x].description);
      break;
    case 3:
      printf("Enter the new duration : ");
      scanf(" %[^\n]s", (*pProgramData)[x].duration);
      break;
    case 4:
      printf("Enter the new cost : ");
      scanf(" %d", &((*pProgramData)[x].cost));
      break;
    case 5:
      printf("Entrez the new schedule : ");
      scanf(" %[^\n]s", (*pProgramData)[x].schedule);
      break;

    default:
      printf("Please enter a number between 1 and 5 !\n");
      break;
    }
  }
}

void case4(int *pProgramSize, program **pProgramData) {
  int choice2;
  printf("[1] Search\n[2] Add\n[3] Delete\n[4] Modify\nEnter "
         "your choice: ");
  char free;
  if (scanf(" %d", &choice2) == 1) {

  } else {
    scanf(" %s", &free);
  }
  switch (choice2) {
  case 1:
    programsSearch(pProgramSize, pProgramData);
    break;
  case 2:
    programsAdd(pProgramSize, pProgramData);
    break;
  case 3:
    programsDelete(pProgramSize, pProgramData);
    break;
  case 4:
    programsModify(pProgramSize, pProgramData);
    break;
  default:
    printf("Please enter a number between 1 and 4!\n");
    break;
  }
}

void scheduleAdd(schedules *pSchedules) {
  printf("Monday : ");
  scanf(" %[^\n]s", (pSchedules->monday));
  printf("Tuesday : ");
  scanf(" %[^\n]s", (pSchedules->tuesday));
  printf("Wednesday : ");
  scanf(" %[^\n]s", (pSchedules->wednesday));
  printf("Thursday : ");
  scanf(" %[^\n]s", (pSchedules->thursday));
  printf("Friday : ");
  scanf(" %[^\n]s", (pSchedules->friday));
  printf("Saturday : ");
  scanf(" %[^\n]s", (pSchedules->saturday));
  printf("Sunday : ");
  scanf(" %[^\n]s", (pSchedules->Sunday));
}

void scheduleShow(schedules *pSchedules) {
  printf("Monday : %s\n", pSchedules->monday);
  printf("Tuesday : %s\n", pSchedules->tuesday);
  printf("wednesday : %s\n", pSchedules->wednesday);
  printf("Thursday : %s\n", pSchedules->thursday);
  printf("Friday : %s\n", pSchedules->friday);
  printf("Saturday : %s\n", pSchedules->saturday);
  printf("Sunday : %s\n", pSchedules->Sunday);
}

void scheduleModify(schedules *pSchedules) {
  int choice1;
  printf(
      "[1] Monday\n[2] Tuesday\n[3] Wednesday\n[4] Thursday\n[5] Friday\n[6] "
      "Saturday\n[7] Sunday\nEnter your choice: ");
  char free;
  if (scanf(" %d", &choice1) == 1) {

  } else {
    scanf(" %s", &free);
  }
  switch (choice1) {
  case 1:
    printf("Enter the new schedule for monday : ");
    scanf(" %[^\n]s", (pSchedules->monday));
    break;
  case 2:
    printf("Enter the new schedule for tuesday : ");
    scanf(" %[^\n]s", (pSchedules->tuesday));
    break;
  case 3:
    printf("Enter the new schedule for wednesday : ");
    scanf(" %[^\n]s", (pSchedules->wednesday));
    break;
  case 4:
    printf("Enter the new schedule for thursday : ");
    scanf(" %[^\n]s", (pSchedules->thursday));
    break;
  case 5:
    printf("Enter the new schedule for friday : ");
    scanf(" %[^\n]s", (pSchedules->friday));
    break;
  case 6:
    printf("Enter the new schedule for saturday : ");
    scanf(" %[^\n]s", (pSchedules->saturday));
    break;
  case 7:
    printf("Enter the new schedule for sunday : ");
    scanf(" %[^\n]s", (pSchedules->Sunday));
    break;

  default:
    printf("Please enter a number between 1 and 7 !\n");
    break;
  }
}

void case5(schedules *schedules) {
  int choice2;
  printf("[1] Show\n[2] Modify\nEnter your choice: ");
  char free;
  if (scanf(" %d", &choice2) == 1) {

  } else {
    scanf(" %s", &free);
  }
  switch (choice2) {
  case 1:
    scheduleShow(schedules);
    break;
  case 2:
    scheduleModify(schedules);
    break;
  default:
    printf("Please enter a number between 1 and 2 !\n");
    break;
  }
}
