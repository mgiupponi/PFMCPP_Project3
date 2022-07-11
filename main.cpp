 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

struct StationersShop      
{
    int numPaperSizesForsale = 15;    
    int numWrappingPaperDesignsForsale = 20;        
    float monthElectricityBill = 150.2f;            
    float profitPerDay = 105.9f;               
    int numberOfEmployees = 10;               
    
    struct Paper
    {
        bool forPhotoPrinting = false;
        float thicnessInuM = 200.0f;        
        float priceInUsd = 0.1f;
        std::string sizeStandard = "A4";
        std::string manufacturer = "whixe";

        void printDocument(std::string fileName, float zoomPercentage, bool onesided = false); 
        float printPhoto(int qualityIndex);
        bool moveToSellingOutbox(Paper paperB);
        
    };

    float makeAPhotocopy(Paper paperA, bool isBlackAndWhite = true , bool onesided = false);
    float takePassportPhoto(Paper paperB, std::string sizeStandard);
    void wrapAGift(std::string wrappingPaperModel); 

    Paper paperToBeUsed;  
};


struct Wallet     
{
    int numSlots = 7;  
    int numCreditCards = 4;     
    float amountOfCashCarried = 250.0f;            
    float weightIngrams = 150.5f;               
    std::string color = "Brown";               
    
    struct CreditCard      
    {
        bool isInternational = true;
        float widthInCm = 200.0f;
        double cardNumber = 23344331776;
        float availableCreditInUsd = 1400.0f;
        std::string bank = "HSBC";
        std::string program = "flyingSilver";

        int payInPOS(bool useChip = true);
        std::string payOnline(std::string url, bool requiresToken = false);
        float getAvailableCredit();
    };

    std::string identifyTheOwner(CreditCard creditCardA);
    bool payLunch(CreditCard creditCardB, float tipPercentage = 10.0);
    bool enterABuilding(float walletOrientationToUseInDegrees = 0.0f);
    
    CreditCard creditCardSelected;
};

struct Laptop   
{
    std::string color = "Black";
    float weightIngrams = 150.5f;     
    std::string processorModel = "Corei3";              
    int screenSizeInInches = 17;               
    std::string brand = "Lenovo";               
    
    struct File      
    {
        bool isReadOnly = false;
        float sizeInBytes = 2000.0f;        
        std::string fullPath = "/root/file.jpg";
        std::string fileType = "image";

        std::string readFile(int startPosition, int endPosition);
        void replaceFile(std::string content);
        bool deleteFile(bool askForConfirmation);
    };

    std::string readDocument(File inputFile);
    float surfTheWeb(std::string url = "www.google.com", bool incognitoMode = false);
    void TakeAPicture(File outputFile, float lidOrientationInDegrees = 55.0f);

    File fileBeingProcessed;
};

struct SwissArmyKnife      
{
    std::string color = "Red";
    int amountOfTools = 8;     
    float weightInGrams= 40.0f;              
    int manufactureYear = 2019;               
    float marketValueInUsd = 75.0f;               
    
    struct Tool      
    {
        bool isEdgy = true;
        float lentghInCm = 10.0f;
        float thicknessInMm = 1.0f;   
        std::string toolName = "knife1";

        bool rotate(float degreesToMove, double speedInMmPerSecond = 2.0);
        float fullyOpen(double speedInMmPerSecond = 2.0);
        float fullyClose(double speedInMmPerSecond = 2.0);
    };

    float cutFood(Tool toolA, float pressureToApply);
    bool openABottle(double speedInDegreesPerSecond, bool isACorkLid = false);
    void unscrew(Tool toolB);
    Tool toolBeingUsed;
};

struct Speakers    
{
    int amountOfDevices = 4; 
    int sizeInCm = 1;     
    double maxPowerWatts= 5.0;              
    double maxDecibPower = 70;               
    int numberOfcoilwirings = 200;               
    
    struct SoundFile      
    {
        float sampleRateInKhz = 44.0f;
        float soundLengthInMs = 3000.0f;   
        std::string fileFormat = "wav";
        std::string filePath = "/root/ding.wav";

        bool verifyIfIsUltrasound();
        float compressFile(int compressionLevel = 3);
        void applyBandPassFilter(double freqA, double freqB);
    };

    float playAudibleSound(SoundFile soundFileA, double level = 6.0);
    bool activateNoiseReduction(int duration);
    float playUltraSound(SoundFile soundFileB, double level);
    
    SoundFile soundFileBeingPlayed;
};

struct Cables      
{
    int lengthInCm = 8;
    std::string color = "Red";     
    int amountOfinternalWires= 5;              
    std::string externalMatrerial = "Plastic";               
    int numberOfcoilwirings = 200;               
    
    struct Wire      
    {
        float thicknessInUm = 500.0f;
        float resistancePerMeterInOhms = 3.0f;   
        std::string material = "copper";
        std::string isolation = "plastic";

        double sendAudioSignal(std::string voltageSignalFile = "boom.v");
        float applyVoltage(float voltageLevel, double durationInMicroSeconds);
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
    };

    double holdDeviceOverUsersHead();
    float transportAudioSignals(Wire wireA, std::string audioFile = "boom.wav");
    float transportControlSignals(Wire wireB, int binaryCode = 1100101010 );
    
    Wire wireSelectedForSignal;
};

struct BluetoothInterface      
{
    double bluetoothVersion = 2.0;
    double transmissionPowerInMw = 300;     
    double receiverSensitivityInDb= 5.0;              
    int distanceCoverageInMeters = 10;               
    float dataBwCapacityInMbps = 20.0f;               
    
    struct WirelessChannel      
    {
        float centerFrequencyInGhz = 2.7f;
        float frequencyWidthInGhz = 0.01f;
        double channelCapacityInMbps = 20;
        std::string channelName = "23";

        bool testIfChannelAvailable();
        int listenChannel(float sensitivityInDb, double durationInMicroSeconds);
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
    };

    float receiveAudio(WirelessChannel wirelessChannelC, double rxAmplification);
    double sendPlaySignal(WirelessChannel wirelessChannelA);
    double sendBatteryLevel(WirelessChannel wirelessChannelB, bool reCheckBattery = true );
    
    WirelessChannel wirelessChannelSelected;
};

struct LogicCircuit    
{
    double bluetoothVersion = 2.0;
    double transmissionPowerInMw = 300;     
    double receiverSensitivityInDb= 5.0;              
    int distanceCoverageInMeters = 10;                      
    float dataBwCapacityInMbps = 20.0f;               
    
    struct BusChannel      
    {
        int amountOfWires = 5;
        int amountOfdigitalwires = 2;
        double maxVoltage = 5;
        std::string busSource = "bluetoothAudioReceiver";
        std::string busDestination = "centralCircuit";

        bool testIfBusAvailable();
        int readDigitalBus(int wireNumber, bool stopWhenAllzeros = true);
        void sendAudioSignal(int wireNumber, std::string audioCode);
    };

    float generatePowerAudioForSpeakers(BusChannel txSpeakersChannel, BusChannel rxBluetoothBus, float amplificationLevel = 10.0f);
    void generateVoiceInformation(BusChannel busChannel, std::string stringToSend = "Power On");
    double monitorBatteryCharge(BusChannel batteryBusToRead);
    
    BusChannel busChannelBeingUsed;
};

struct Buttons   
{
    int Amount = 3;
    std::string color = "Black";     
    int IPProtection = 57;              
    std::string material = "silicone";               
    double areaInMm = 20.0;               
    
    struct CircuitSwitch      
    {
        bool normallyOpen = true;
        int amountOfPins = 2;
        double lengthInMm = 7;
        double widthInMm = 7;
        std::string placementOntheCircuit = "powerModule";

        bool testIfBusAvailable();
        bool pressSwitch(float timePressingInMilliseconds = 200, float pressureApplied = 5.0f);
        void sendAudioSignal(int wireNumber, std::string audioCode);
    };

    bool powerOnTheDevice(CircuitSwitch circuitSwitchA, double amountOfSecondsPressed = 2);
    void changeSong(CircuitSwitch circuitSwitchB, int amountOfClicks = 1 );
    std::string answerACall(CircuitSwitch circuitSwitchB);
    
    CircuitSwitch circuitSwitchBeingUsed;
};

struct WirelessHeadphone       
{
    Speakers speakers;
    Cables cables;     
    BluetoothInterface bluetoothInterface;              
    LogicCircuit logicCircuit;               
    Buttons buttons;       

    struct RemoteDevice      
    {
        bool callsEnabled = false;
        double receivedPowerInDb = 20;
        std::string remoteOS = "Windows10";
        std::string deviceName = "MartinPC";
        std::string MACAddress = "0f:de:12:3f:8a:01";

        bool pingDevice(int numberOfPings = 4, double millisencodsBetweenPings = 1000);
        std::string listenDevice(int subChannelId = 2, bool isCtlChannel = false);
        void sendAudioSignal(std::string audioCode);
    };

    bool playSound(RemoteDevice remoteDeviceA, double audioLevel = 2);
    double recordSound(RemoteDevice remoteDeviceB, int amountOfClicks = 1 );
    std::string answerACall(RemoteDevice remoteDeviceB);
    
    RemoteDevice remoteDeviceBeingUsed;
};

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
