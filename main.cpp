/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1) Stationer's shop
5 properties:
    1) number of paper sizes for sale
    2) number of wrapping paper designs for sale
    3) amount of money spent on electricity per month
    4) amount of profit made per day
    5) number of employees
3 things it can do:
    1) make a photocopy
    2) take a passport photo
    3) wrap a gift
 */

struct StationersShop //                            1) define an empty struct for each of your 10 types.       
{
    //number of paper sizes for sale                    2) copied and commented-out plain-english property
    int numPaperSizesForsale = 15; //                   3) member variables with relevant data types.
    //number of wrapping paper designs for sale     
    int numWrappingPaperDesignsForsale = 20;     
    //amount of money spent on electricity per month    
    float monthElectricityBill = 150.2f;            
    //amount of profit made per day         
    float profitPerDay = 105.9f;               
    //number of employees              
    int numberOfEmployees = 10;               
    
    struct Paper //5)                                 Note that the nested type 'Paper' is related to the 'StationersShop' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool forPhotoPrinting = false;
        float thicnessInuM = 200.0f;        
        float priceInUsd = 0.1f;
        std::string sizeStandard = "A4";
        std::string manufacturer = "whixe";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void printDocument(std::string fileName, int numPagesPerSize, bool onesided = false); 
        //
        float printPhoto(int qualityIndex);
        //
        void moveToSellingOutbox(Paper paperB);
        //
    };

     //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float makeAPhotocopy(int amountOfPages, bool isBlackAndWhite = true , bool onesided = false);
    //1) returns the amount to be charged in USD
    float takePassportPhoto(int amountOfCopiesToBePrinted, std::string sizeStandard);
    //2) returns the amount to be charged in USD
    void wrapAGift(std::string wrappingPaperModel); 
    //3)

    //5) a member variable whose type is a UDT.
    Paper paperBeingSold;  

/*
Thing 2) Wallet
5 properties:
    1) number of slots
    2) number of credit cards
    3) amount of cash carried
    4) amount of weight
    5) color
3 things it can do:
    1) identify the owner
    2) pay lunch
    3) enter a building
 */

struct Wallet //                            1) define an empty struct for each of your 10 types.       
{
    //number of slots                    2) copied and commented-out plain-english property
    int numSlots = 7; //                   3) member variables with relevant data types.
    //number of credit cards    
    int numCreditCards = 4;     
    //amount of cash carried    
    float amountOfCashCarried = 250.0f;            
    //amount of weight         
    float weightIngrams = 150.5f;               
    //color              
    std::string color = "Brown";               
    
    struct CreditCard      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isInternational = true;
        float widthInCm = 200.0f;        
        float availableCreditInUsd = 1400.0f;
        std::string bank = "HSBC";
        std::string program = "flyingSilver";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        int identifyTheOwner(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);
        // returns the Owner national id
        void payLunch(std::string failureType, bool requiresTow = false);
        // returns the number of miles traveled
        int enterABuilding(bool includeUberLyftTrips);
        // returns the number of miles traveled
    };

    //sell a paper
    void sellAPaper(Paper paperA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //make a photocopy using a Paper
    void makeAPhotocopy(Paper paperB);
    
    //5) a member variable whose type is a UDT.
    Paper paperBeingSold;  

/*
Thing 3) Laptop
5 properties:
    1) color
    2) weight
    3) processor model
    4) screen size
    5) brand
3 things it can do:
    1) process docuemnts
    2) surf the web
    3) take a picture
 */

/*
Thing 4) Swiss Army Knife
5 properties:
    1) color
    2) amount of tools
    3) weight
    4) year of manufacturing
    5) market value
3 things it can do:
    1) cut food
    2) open a bottle
    3) unscrew 
 */

/*
Thing 5) Speakers
5 properties:
    1) Amount of devices (int)
    2) Size in cm (int)
    3) Maximum power in watts (double)
    4) Maximum decibels capacity (double)
    5) Number of wirings of the coil (int)
3 things it can do:
    1) Play audible sound
    2) Reduce external noise
    3) Play ultrasound
 */

/*
Thing 6) Cables
5 properties:
    1) Length in cm (int)
    2) Color (std::string)
    3) Amount of internal wires (int)
    4) External material (std::string)
    5) Internal wire thickness in um (int)
3 things it can do:
    1) Hold the device over user's head
    2) Transport audio signals
    3) Transport control signals
 */

/*
Thing 7) Bluetooth interface
5 properties:
    1) Bluetooth version (double)
    2) Transmission power in mW (double)
    3) Receiver sesitivity in dB (double)
    4) Distance coverage in meters (int)
    5) Data bandwith capacity in Mbps (float)
3 things it can do:
    1) Receive audio
    2) Send play signal
    3) Send battery level
 */

/*
Thing 8) Logic circuit
5 properties:
    1) width in cm (int)
    2) length in cm (int)
    3) thickness in mm (double)
    4) amount of integrated circuits (int)
    5) amount of leds (int)
3 things it can do:
    1) generate power audio for speakers
    2) generate voice information
    3) monitor battery charge
 */

/*
Thing 9) Buttons
5 properties:
    1) Amount (int)
    2) Color (std::string)
    3) Outdoor protection level IPXX (int)
    4) Material (std::string)
    5) Area in mm2 (double)
3 things it can do:
    1) Power on the device
    2) Change song
    3) Answer a call
 */

/*
Thing 10) Wireless headphone
5 properties:
    1) Speakers
    2) Cables
    3) Bluetooth interface
    4) Logic circuit
    5) Buttons
3 things it can do:
    1) Play sound
    2) Record sound
    3) Answer a call
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
