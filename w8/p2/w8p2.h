/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define MAX 3
#define GRAM 64
#define CONVERT 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    double price;
    int Cal_Per_Ser;
    double lbs;
};

struct ReportData
{
    int sku;
    double price;
    int Cal_Per_Ser;
    int g;
    double lbs;
    double kg;
    double total;
    double cp_serv;
    double cp_cal;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* tst);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* tst);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int product);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int cat_food);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void  displayCatFoodData(const int sku, const double* price, const int Cal_Per_Ser, const double* lbs);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* newlbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalGrams, double* result);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total, double* result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* Cal_Per_Ser, const double* price, double* costpcal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapestOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
