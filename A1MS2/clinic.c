/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>

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
            printf("<<< Feature not yet available >>>\n\n");
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


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
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