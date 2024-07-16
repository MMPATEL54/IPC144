/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Manan Manojkumar Patel
Student ID#: 141782227
Email      : mmpatel54@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patients[], int maxRecords, int formatType) 
{
    int i = 0;
    int recordsfound = 0; //records flag
    displayPatientTableHeader();
    for (i = 0; i < maxRecords; i++)
    {
        if (patients[i].patientNumber != 0) 
        {
            recordsfound++;
            displayPatientData(&patients[i], formatType);
        }
    }
    if (recordsfound == 0) 
    {
        printf("*** No records found ***");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patients[], int maxRecords)
{
    int Op = -1;
    while (Op != 0) 
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        Op = inputIntRange(0, 2);
        printf("\n");

        if (Op == 1)
        {
            searchPatientByPatientNumber(patients, maxRecords);
            suspend();
        }
        else if (Op == 2) 
        {
            searchPatientByPhoneNumber(patients, maxRecords);
            clearInputBuffer();
            suspend();
        }
    }
}
// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patients[], int maxRecords)
{
    int i = 0;

    for (i = 0; i < maxRecords && patients[i].patientNumber != 0; i++);

    if (i == maxRecords) 
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patients[i].patientNumber = nextPatientNumber(patients, maxRecords);
        inputPatient(&patients[i]);
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patients[], int maxRecords)
{
    int patNum;
    int patIn;
    printf("Enter the patient number: ");
    patNum = inputIntPositive();
    patIn = findPatientIndexByPatientNum(patNum, patients, maxRecords);
    printf("\n");
    if (patIn != -1)
    {
        menuPatientEdit(&patients[patIn]);
    }
    else 
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patients[], int maxRecords) 
{
    int patNum, patIn, opt;

    printf("Enter the patient number: ");
    patNum = inputIntPositive();
    patIn = findPatientIndexByPatientNum(patNum, patients, maxRecords);
    printf("\n");

    if (patIn == -1) 
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        displayPatientData(&patients[patIn], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        opt = inputCharOption("yn");

        if (opt == 'y') 
        {
            patients[patIn].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else if (opt == 'n')
        {
            printf("Operation aborted.\n\n");
        }
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments

void viewAllAppointments(struct ClinicData* data) 
{
    int i, j, size = 0;
    int calculateSizeOfAppointmentArray(const struct Appointment* appointments, int maxAppointments);

    size = calculateSizeOfAppointmentArray(data->appointments, data->maxAppointments);

    sortingAppointment(data->appointments, size);

    if (data) 
{
        displayScheduleTableHeader(&data->appointments->date, ALL);
        for (i = 0; i < data->maxAppointments; i++) {
            for (j = 0; j < data->maxPatient; j++) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], ALL);
                    break;
                }
            }
        } putchar('\n');
    }
    else 
{
        printf("*** No records found ***\n\n");
    }
}

// View appointment schedule for the user input date
// Todo:

void viewAppointmentSchedule(struct ClinicData* data) 
{
    int i, j, size = 0;
    int calculateSizeOfAppointmentArray(const struct Appointment* appointments, int maxAppointments);
    struct Date userInput = { '\0' };

    checkLeapYear(&userInput);
    putchar('\n');
    size = calculateSizeOfAppointmentArray(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&userInput, NOT_ALL);
    for (i = 0; i < size; i++) 
{
        if (userInput.year == data->appointments[i].date.year && userInput.month == data->appointments[i].date.month && userInput.day == data->appointments[i].date.day) {
            for (j = 0; j < size; j++) 


{
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
{
                    displayScheduleData(&data->patients[j], &data->appointments[i], NOT_ALL);
                }
            }
        }
    } putchar('\n');
}


// Add an appointment record to the appointment array
// Todo:

void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient) {
    int i, size = 0, value = 1;
    int calculateSizeOfAppointmentArray(const struct Appointment* appointments, int maxAppointments);

    size = calculateSizeOfAppointmentArray(appointments, maxAppointments);

    if (maxAppointments > size) 
{
        printf("Patient Number: ");
        scanf(" %d", &appointments[size].patientNumber);
        clearInputBuffer();
        if (findPatientIndexByPatientNum(appointments[size].patientNumber, patients, maxPatient) != -1) 
{
            do 
{
                int dupe = 0;
                checkLeapYear(&appointments[size].date);
                do 
{
                    printf("Hour (0-23)  : ");
                    appointments[size].time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    appointments[size].time.min = inputIntRange(0, 59);

                    for (i = 0; i < size; i++) 
{
                        if (appointments[size].date.year == appointments[i].date.year &&
                            appointments[size].date.month == appointments[i].date.month &&
                            appointments[size].time.hour == appointments[i].time.hour &&
                            appointments[size].time.min == appointments[i].time.min) 
{

                            printf("\nERROR: Appointment timeslot is not available!\n\n");
                            dupe = 1;
                        }
                    } if (dupe == 0) 
{
                        if (appointments[size].time.hour >= BEGIN_HOUR && appointments[size].time.hour <= END_HOUR) 
{
                            if (appointments[size].time.min >= BEGIN_MINUTE && appointments[size].time.min <= END_MINUTE) 
{
                                printf("\n*** Appointment scheduled! ***\n\n");
                                value = 0;
                                break;
                            }
                            else 
{
                                printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", INTERVAL_MINUTE);
                            }
                        }
                        else 
{
                            printf("ERROR: Time must be between 10:00 and 14:00 in %d minute intervals.\n\n", INTERVAL_MINUTE);
                        }
                    }
                } while (dupe == 0);
            } while (value == 1);
        }
        else 
{
            printf("\nERROR: Patient record not found!\n\n");
        }
    }
}



// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient) 
{
    int i, index;
    char selection;

    struct Appointment removeAppointment = { 0 };
    int size = 0;

    size = calculateSizeOfAppointmentArray(appointments, maxAppointments);
    sortingAppointment(appointments, size);
    printf("Patient Number: ");
    scanf(" %d", &removeAppointment.patientNumber);
    clearInputBuffer();
    index = findPatientIndexByPatientNum(removeAppointment.patientNumber, patients, maxPatient);
    if (index != -1) 
{
        checkLeapYear(&removeAppointment.date);
        putchar('\n');
        displayPatientData(&patients[index], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf(" %c", &selection);
        clearInputBuffer();
        if (selection == 'y') 
{
            for (i = 0; i < maxAppointments; i++) 
{
                if (removeAppointment.patientNumber == appointments[i].patientNumber && removeAppointment.date.day ==
                    appointments[i].date.day && removeAppointment.date.month == appointments[i].date.month &&
                    removeAppointment.date.year == appointments[i].date.year) 
{
                    index = i;
                    break;
                }
            }
            appointments[index].patientNumber = 0;
            appointments[index].date.day = 0;
            appointments[index].date.month = 0;
            appointments[index].date.year = 0;
            appointments[index].time.hour = 0;
            appointments[index].time.min = 0;
            printf("\nAppointment record has been removed!\n\n");
        }
        else 
{
            printf("Operation aborted.\n\n");
        }
    }
    else 
{
        printf("ERROR: Patient record not found!\n\n");
    }
}

// calculate the size of the appointment array
int calculateSizeOfAppointmentArray(const struct Appointment* appointments, int maxAppointment) 
{
    int i, size = 0;

    for (i = 0; i < maxAppointment; i++) 
{
        if (appointments[i].date.day != 0) 
{
            size++;
        }
    } return size;
}

// check leap year
void checkLeapYear(struct Date* userInput) 
{

    printf("Year        : ");
    scanf(" %d", &userInput->year);
    clearInputBuffer();
    printf("Month (1-12): ");
    userInput->month = inputIntRange(0, 12);

    switch (userInput->month) 
{
    case 1:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(0, 31);
        break;
    case 2:
        if (userInput->year % 400 == 0 || userInput->year % 100 == 0 || userInput->year % 4 == 0) 
{
            printf("Day (1-29)  : ");
            userInput->day = inputIntRange(1, 29);
        }
        else 
{
            printf("Day (1-28)  : ");
            userInput->day = inputIntRange(1, 28);
            if (userInput->day < 1 || userInput->day > 28) 
{
                printf("ERROR! Day must be between 1 and 28 inclusive: ");
            }
        }
        break;
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Day (1-31)  : ");
        userInput->day = inputIntRange(1, 31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Day (1-30)  : ");
        userInput->day = inputIntRange(1, 30);
        break;
    default:
        inputIntRange(1, 12);
        break;
    }
}

//sorting selection
void sortingAppointment(struct Appointment* appointments, int size) 
{
    int i, j;
    struct Appointment temp;

    for (i = size - 1; i > 0; i--) 
{
        for (j = 0; j < i; j++) 
{
            // Sorting by year
            if (appointments[j].date.year > appointments[j + 1].date.year) 
{
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            // Sorting by day
            else if (appointments[j].date.year == appointments[j + 1].date.year &&
                appointments[j].date.day > appointments[j + 1].date.day) 
{
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            // Sorting by hour
            else if (appointments[j].date.year == appointments[j + 1].date.year &&
                appointments[j].date.day == appointments[j + 1].date.day &&
                appointments[j].time.hour > appointments[j + 1].time.hour) 
{
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
            // Sorting by minute
            else if (appointments[j].date.year == appointments[j + 1].date.year &&
                appointments[j].date.day == appointments[j + 1].date.day &&
                appointments[j].time.hour == appointments[j + 1].time.hour &&
                appointments[j].time.min > appointments[j + 1].time.min) 
{
                temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patients[], int maxRecords)
{
    int PatIn;
    int PatNum;

    printf("Search by patient number: ");
    PatNum = inputIntPositive();
    PatIn = findPatientIndexByPatientNum(PatNum, patients, maxRecords);
    printf("\n");
    if (PatIn != -1)
    {
        displayPatientData(&patients[PatIn], FMT_FORM);
        printf("\n");
    }
    else
    {
        printf("*** No records found ***\n\n");
    }
}
// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patients[], int maxRecords) 
{
    char Num[PHONE_LEN + 1] = { 0 };
    int i = 0, flag1 = 0;
    printf("Search by phone number: ");
    inputCString(Num, PHONE_LEN, PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < maxRecords; i++)
    {
        if (strcmp(Num, patients[i].phone.number) == 0)
        {
            displayPatientData(&patients[i], FMT_TABLE);
            flag1 = 1;
        }
    }
    if (flag1 == 0) 
    {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patients[], int maxRecords) 
{
    int i = 0;
    int higNum = patients[i].patientNumber;
    for (i = 1; i < maxRecords; i++)
    {
        if (higNum < patients[i].patientNumber)
        {
            higNum = patients[i].patientNumber;
        }
    }
    return higNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patients[], int maxRecords)
{
    int i;

    for (i = 0; i < maxRecords; i++)
    {
        if (patientNumber == patients[i].patientNumber) 
        {
            return i;
        }
    }
    return -1;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////


// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) 
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n\n");
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int Sel;
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n");
    printf("Selection: ");
    Sel = inputIntRange(1, 4);
    printf("\n");
    if (Sel == 4)
    {
        strcpy(phone->description, "TBD");
        phone->number[0] = 0;
    }
    else {
        if (Sel == 1)
            strcpy(phone->description, "CELL");
        if (Sel == 2)
            strcpy(phone->description, "HOME");
        if (Sel == 3)
            strcpy(phone->description, "WORK");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        putchar('\n');
        clearInputBuffer();
    }
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) 
{
    FILE* fp = fopen(datafile, "r");
    int i = 0;
    int records = 0;
    if (fp != NULL) 
{
        for (i = 0; i < max; i++) 
{
            if (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number)) 
{
                records++;
            }
        } fclose(fp);
    }
 return records;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) 
{
    FILE* fp = fopen(datafile, "r");
    int i = 0;
    int records = 0;
    if (fp != NULL) 
{
        for (i = 0; i < max; i++) 
{
            if (fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day,
                &appoints[i].time.hour, &appoints[i].time.min) > 0) 
{
                records++;
            }
        } fclose(fp);
    }
 return records;
}