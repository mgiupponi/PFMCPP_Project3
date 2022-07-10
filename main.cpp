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
        void printDocument(std::string fileName, float zoomPercentage, bool onesided = false); 
        //
        float printPhoto(int qualityIndex);
        //Returns the seconds it took to print the photo
        bool moveToSellingOutbox(Paper paperB);
        //Returns if theres space on the selling outbox
    };

     //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float makeAPhotocopy(Paper paperA, bool isBlackAndWhite = true , bool onesided = false);
    //1) returns the amount to be charged in USD
    float takePassportPhoto(Paper paperB, std::string sizeStandard);
    //2) returns the amount to be charged in USD
    void wrapAGift(std::string wrappingPaperModel); 
    //3)

    //5) a member variable whose type is a UDT.
    Paper paperToBeUsed;  
};

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
        void payLunch(std::string failureType, bool useCash = false);
        // returns the number of miles traveled
        int enterABuilding(bool includeUberLyftTrips);
        // returns the number of miles traveled
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    std::string identifyTheOwner(CreditCard creditCardA);
    // returns the Owner name and surname
    bool payLunch(CreditCard creditCardB, float tipPercentage = 10.0);
    // returns if payment was accepted using this credit card
    bool enterABuilding(float walletOrientationToUseInDegrees = 0.0f);
    // Returns if access token was accepted
    
    //5) a member variable whose type is a UDT.
    CreditCard creditCardSelected;
};

/*
Thing 3) Laptop
5 properties:
    1) color
    2) weight
    3) processor model
    4) screen size
    5) brand
3 things it can do:
    1) read document
    2) surf the web
    3) take a picture
 */

struct Laptop //                            1) define an empty struct for each of your 10 types.       
{
    //color                   2) copied and commented-out plain-english property
    std::string color = "Black";  //                   3) member variables with relevant data types.
    //weight    
    float weightIngrams = 150.5f;     
    //processor model    
    std::string processorModel = "Corei3";              
    //screen size         
    int screenSizeInInches = 17;               
    //brand              
    std::string brand = "Lenovo";               
    
    struct File      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isReadOnly = false;
        float sizeInBytes = 2000.0f;        
        std::string fullPath = "/root/file.jpg";
        std::string fileType = "image";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        int identifyTheOwner(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);
        // returns the Owner national id
        void payLunch(std::string failureType, bool useCash = false);
        // returns the number of miles traveled
        int enterABuilding(bool includeUberLyftTrips);
        // returns the number of miles traveled
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    std::string readDocuemnt(File inputFile);
    // returns file plain text conversion
    float surfTheWeb(std::string url = "www.google.com", bool incognitoMode = false);
    // returns nanoseconds required to display the web page
    void TakeAPicture(File outputFile, float lidOrientationInDegrees = 55.0f);
    //
    
    //5) a member variable whose type is a UDT.
    File fileBeingProcessed;
};

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

struct SwissArmyKnife //                            1) define an empty struct for each of your 10 types.       
{
    //color                   2) copied and commented-out plain-english property
    std::string color = "Red";  //                   3) member variables with relevant data types.
    //amount of tools   
    int amountOfTools = 8;     
    //weight   
    float weightInGrams= 40.0f;              
    //year of manufacturing         
    int manufactureYear = 2019;               
    //market value              
    float marketValueInUsd = 75.0f;               
    
    struct Tool      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isEdgy = true;
        float lentghInCm = 10.0f;
        float thicknessInMm = 1.0f;   
        std::string toolName = "knife1";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        bool rotate(float degreesToMove, double speedInMmPerSecond = 2.0);
        // returns true if open or close limit reached
        float fullyOpen(double speedInMmPerSecond = 2.0);
        // returns seconds taken to open the tool
        float fullyClose(double speedInMmPerSecond = 2.0);
        // returns seconds taken to close the tool
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float cutFood(Tool toolA, float pressureToApply);
    // returns secondsTaken to cut the food
    bool openABottle(double speedInDegreesPerSecond, bool isACorkLid = false);
    // returns if gas was expeled
    void unscrew(Tool toolB);
    //
    
    //5) a member variable whose type is a UDT.
    Tool toolBeingUsed;
};

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

struct Speakers //                            1) define an empty struct for each of your 10 types.       
{
    //Amount of devices                   2) copied and commented-out plain-english property
    int amountOfDevices = 4;  //                   3) member variables with relevant data types.
    //Size in cm   
    int sizeInCm = 1;     
    //Maximum power in watts (double)   
    double maxPowerWatts= 5.0;              
    //Maximum decibels capacity (double)         
    double maxDecibPower = 70;               
    //Number of wirings of the coil (int)            
    int numberOfcoilwirings = 200;               
    
    struct SoundFile      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        float sampleRateInKhz = 44.0f;
        float soundLengthInMs = 3000.0f;   
        std::string fileFormat = "wav";
        std::string filePath = "/root/ding.wav";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        bool verifyIfIsUltrasound();
        // returns true if contains frequencies exceeding 20Khz
        float compressFile(int compressionLevel = 3);
        // returns compression ratio achieved
        void applyBandPassFilter(double freqA, double freqB);
        // 
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float playAudibleSound(SoundFile soundFileA, double level = 6.0);
    // returns seconds taken to play the sound
    bool activateNoiseReduction(int duration);
    // returns if noise reduction already active
    float playUltraSound(SoundFile soundFileB, double level);
    // returns seconds taken to play the sound
    
    //5) a member variable whose type is a UDT.
    SoundFile soundFileBeingPlayed;
};

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

struct Cables //                            1) define an empty struct for each of your 10 types.       
{
    //Length in cm                   2) copied and commented-out plain-english property
    int lengthInCm = 8;  //                   3) member variables with relevant data types.
    //Color   
    std::string color = "Red";     
    //Amount of internal wires (int)   
    int amountOfinternalWires= 5;              
    //External material (std::string)       
    std::string externalMatrerial = "Plastic";               
    //Internal wire thickness in um (int)            
    int numberOfcoilwirings = 200;               
    
    struct Wire      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        float thicknessInUm = 500.0f;
        float resistancePerMeterInOhms = 3.0f;   
        std::string material = "copper";
        std::string isolation = "plastic";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        double sendAudioSignal(std::string voltageSignalFile = "boom.v");
        // returns power in watts consumed
        float applyVoltage(float voltageLevel, double durationInMicroSeconds);
        // returns resulting current
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
        // 
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    double holdDeviceOverUsersHead();
    // returns weight in grams over user head
    float transportAudioSignals(Wire wireA, std::string audioFile = "boom.wav");
    // returns microseconds taken to send the audio
    float transportControlSignals(Wire wireB, int binaryCode = 1100101010 );
    // returns microseconds taken to send the code
    
    //5) a member variable whose type is a UDT.
    Wire wireSelectedForSignal;
};

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

struct BluetoothInterface //                            1) define an empty struct for each of your 10 types.       
{
    //Bluetooth version                   2) copied and commented-out plain-english property
    double bluetoothVersion = 2.0;  //                   3) member variables with relevant data types.
    //Transmission power in mW (double)  
    double transmissionPowerInMw = 300;     
    //Receiver sesitivity in dB (double)   
    double receiverSensitivityInDb= 5.0;              
    //Distance coverage in meters (int)      
    int distanceCoverageInMeters = 10;               
    //Data bandwith capacity in Mbps (float)          
    float dataBwCapacityInMbps = 20.0f;               
    
    struct WirelessChannel      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        float centerFrequencyInGhz = 2.7f;
        float frequencyWidthInGhz = 0.01f;
        double channelCapacityInMbps = 20;
        std::string channelName = "23";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        bool testIfChannelAvailable();
        // returns true if channel is in silence
        int listenChannel(float sensitivityInDb, double durationInMicroSeconds);
        // returns binary code being received
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
        // 
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float receiveAudio(WirelessChannel wirelessChannelC, double rxAmplification);
    // returns average level of audio signal
    double sendPlaySignal(WirelessChannel wirelessChannelA);
    // returns microseconds taken to send the audio
    double sendBatteryLevel(WirelessChannel wirelessChannelB, bool reCheckBattery = true );
    // returns batery charge in percentage
    
    //5) a member variable whose type is a UDT.
    WirelessChannel wirelessChannelSelected;
};

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

struct LogicCircuit //                            1) define an empty struct for each of your 10 types.       
{
    //width in cm (int)                  2) copied and commented-out plain-english property
    double bluetoothVersion = 2.0;  //                   3) member variables with relevant data types.
    //length in cm (int) 
    double transmissionPowerInMw = 300;     
    //thickness in mm (double)  
    double receiverSensitivityInDb= 5.0;              
    //amount of integrated circuits (int)    
    int distanceCoverageInMeters = 10;               
    //amount of leds (int)        
    float dataBwCapacityInMbps = 20.0f;               
    
    struct BusChannel      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        int amountOfWires = 5;
        int amountOfdigitalwires = 2;
        double maxVoltage = 5;
        std::string busSource = "bluetoothAudioReceiver";
        std::string busDestination = "centralCircuit";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        bool testIfBusAvailable();
        // returns true if bus is in silence
        int readDigitalBus(int wireNumber, bool stopWhenAllzeros = true);
        // returns binary code being received
        void sendAudioSignal(int wireNumber, std::string audioCode);
        // 
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float generatePowerAudioForSpeakers(BusChannel txSpeakersChannel, BusChannel rxBluetoothBus, float amplificationLevel = 10.0f);
    // returns average level of audio signal
    void generateVoiceInformation(BusChannel busChannel, std::string stringToSend = "Power On");
    //
    double monitorBatteryCharge(BusChannel batteryBusToRead);
    // returns batery charge in percentage
    
    //5) a member variable whose type is a UDT.
    BusChannel busChannelBeingUsed;
};

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

struct Buttons //                            1) define an empty struct for each of your 10 types.       
{
    //Amount (int)                  2) copied and commented-out plain-english property
    int Amount = 3;  //                   3) member variables with relevant data types.
    //Color
    std::string color = "Black";     
    //Outdoor protection level IPXX  
    int IPProtection = 57;              
    //Material (std::string)   
    std::string material = "silicone";               
    //Area in mm2 (double)       
    double areaInMm = 20.0f;               
    
    struct CircuitSwitch      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        int amountOfWires = 5;
        int amountOfdigitalwires = 2;
        double maxVoltage = 5;
        std::string busSource = "bluetoothAudioReceiver";
        std::string busDestination = "centralCircuit";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        bool testIfBusAvailable();
        // returns true if bus is in silence
        int readDigitalBus(int wireNumber, bool stopWhenAllzeros = true);
        // returns binary code being received
        void sendAudioSignal(int wireNumber, std::string audioCode);
        // 
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    float powerOnTheDevice(CircuitSwitch circuitSwitchA, BusChannel rxBluetoothBus, float amplificationLevel = 10.0f);
    // returns average level of audio signal
    void changeSong(CircuitSwitch circuitSwitchB, std::string stringToSend = "Power On");
    //
    double answerACall(CircuitSwitch circuitSwitchB);
    // returns batery charge in percentage
    
    //5) a member variable whose type is a UDT.
    CircuitSwitch circuitSwitchBeingUsed;
};

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
