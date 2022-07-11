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
        //
        void printDocument(std::string fileName, float zoomPercentage, bool onesided = false); 
        //Returns the seconds it took to print the photo
        float printPhoto(int qualityIndex);
        //Returns if theres space on the selling outbox
        bool moveToSellingOutbox(Paper paperB);
        
    };

     //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    //1) returns the amount to be charged in USD
    float makeAPhotocopy(Paper paperA, bool isBlackAndWhite = true , bool onesided = false);
    //2) returns the amount to be charged in USD
    float takePassportPhoto(Paper paperB, std::string sizeStandard);
    //3)
    void wrapAGift(std::string wrappingPaperModel); 


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
        double cardNumber = 23344331776;
        float availableCreditInUsd = 1400.0f;
        std::string bank = "HSBC";
        std::string program = "flyingSilver";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        // returns the transaction id
        int payInPOS(bool useChip = true);
        // returns the provider platform
        std::string payOnline(std::string url, bool requiresToken = false);
        // returns the available credit of the card
        float getAvailableCredit();
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns the Owner name and surname
    std::string identifyTheOwner(CreditCard creditCardA);
    // returns if payment was accepted using this credit card
    bool payLunch(CreditCard creditCardB, float tipPercentage = 10.0);
    // Returns if access token was accepted
    bool enterABuilding(float walletOrientationToUseInDegrees = 0.0f);
    
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
        // returns file content in plain text
        std::string readFile(int startPosition, int endPosition);
        // replace file with content
        void replaceFile(std::string content);
        // returns if file was successfully deleted
        bool deleteFile(bool askForConfirmation);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.

    // returns file plain text conversion
    std::string readDocument(File inputFile);
    // returns nanoseconds required to display the web page
    float surfTheWeb(std::string url = "www.google.com", bool incognitoMode = false);
    //
    void TakeAPicture(File outputFile, float lidOrientationInDegrees = 55.0f);
    
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
        // returns true if open or close limit reached
        bool rotate(float degreesToMove, double speedInMmPerSecond = 2.0);
        // returns seconds taken to open the tool
        float fullyOpen(double speedInMmPerSecond = 2.0);
        // returns seconds taken to close the tool
        float fullyClose(double speedInMmPerSecond = 2.0);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns secondsTaken to cut the food
    float cutFood(Tool toolA, float pressureToApply);
    // returns if gas was expeled
    bool openABottle(double speedInDegreesPerSecond, bool isACorkLid = false);
    //
    void unscrew(Tool toolB);
    
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
        // returns true if contains frequencies exceeding 20Khz
        bool verifyIfIsUltrasound();
        // returns compression ratio achieved
        float compressFile(int compressionLevel = 3);
        // 
        void applyBandPassFilter(double freqA, double freqB);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns seconds taken to play the sound
    float playAudibleSound(SoundFile soundFileA, double level = 6.0);
    // returns if noise reduction already active
    bool activateNoiseReduction(int duration);
    // returns seconds taken to play the sound
    float playUltraSound(SoundFile soundFileB, double level);
    
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
        // returns power in watts consumed
        double sendAudioSignal(std::string voltageSignalFile = "boom.v");
        // returns resulting current
        float applyVoltage(float voltageLevel, double durationInMicroSeconds);
        //
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns weight in grams over user head
    double holdDeviceOverUsersHead();
    // returns microseconds taken to send the audio
    float transportAudioSignals(Wire wireA, std::string audioFile = "boom.wav");
    // returns microseconds taken to send the code
    float transportControlSignals(Wire wireB, int binaryCode = 1100101010 );
    
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
        // returns true if channel is in silence
        bool testIfChannelAvailable();
        // returns binary code being received
        int listenChannel(float sensitivityInDb, double durationInMicroSeconds);
        //
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns average level of audio signal
    float receiveAudio(WirelessChannel wirelessChannelC, double rxAmplification);
    // returns microseconds taken to send the audio
    double sendPlaySignal(WirelessChannel wirelessChannelA);
    // returns batery charge in percentage
    double sendBatteryLevel(WirelessChannel wirelessChannelB, bool reCheckBattery = true );
    
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
        // returns true if bus is in silence
        bool testIfBusAvailable();
        // returns binary code being received
        int readDigitalBus(int wireNumber, bool stopWhenAllzeros = true);
        //
        void sendAudioSignal(int wireNumber, std::string audioCode);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns average level of audio signal
    float generatePowerAudioForSpeakers(BusChannel txSpeakersChannel, BusChannel rxBluetoothBus, float amplificationLevel = 10.0f);
    //
    void generateVoiceInformation(BusChannel busChannel, std::string stringToSend = "Power On");
    // returns batery charge in percentage
    double monitorBatteryCharge(BusChannel batteryBusToRead);
    
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
    double areaInMm = 20.0;               
    
    struct CircuitSwitch      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool normallyOpen = true;
        int amountOfPins = 2;
        double lengthInMm = 7;
        double widthInMm = 7;
        std::string placementOntheCircuit = "powerModule";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        // returns true if bus is in silence
        bool testIfBusAvailable();
        // returns true if action was completed successfully
        bool pressSwitch(float timePressingInMilliseconds = 200, float pressureApplied = 5.0f);
        // 
        void sendAudioSignal(int wireNumber, std::string audioCode);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns true if device was successfully turned on
    bool powerOnTheDevice(CircuitSwitch circuitSwitchA, double amountOfSecondsPressed = 2);
    //
    void changeSong(CircuitSwitch circuitSwitchB, int amountOfClicks = 1 );
    // returns incoming calling number
    std::string answerACall(CircuitSwitch circuitSwitchB);
    
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

struct WirelessHeadphone //                            1) define an empty struct for each of your 10 types.       
{
    //Speakers                        2) copied and commented-out plain-english property
    Speakers speakers;  //                   3) member variables with relevant data types.
    //Cables
    Cables cables;     
    //Bluetooth interface 
    BluetoothInterface bluetoothInterface;              
    //Logic circuit   
    LogicCircuit logicCircuit;               
    //Buttons      
    Buttons buttons;       

    struct RemoteDevice      
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool callsEnabled = false;
        double receivedPowerInDb = 20;
        std::string remoteOS = "Windows10";
        std::string deviceName = "MartinPC";
        std::string MACAddress = "0f:de:12:3f:8a:01";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        // returns true if ping successful
        bool pingDevice(int numberOfPings = 4, double millisencodsBetweenPings = 1000);
        // returns data received
        std::string listenDevice(int subChannelId = 2, bool isCtlChannel = false);
        //
        void sendAudioSignal(std::string audioCode);
    };

    //3) a member function.  it has multiple arguments, some with default values.
    //the parameter names are related to the work the function will perform.
    // returns true if sound was successfully played
    bool playSound(RemoteDevice remoteDeviceA, double audioLevel = 2);
    // returns sound length in milliseconds
    double recordSound(RemoteDevice remoteDeviceB, int amountOfClicks = 1 );
    // returns audio data from remote device
    std::string answerACall(RemoteDevice remoteDeviceB);
    
    //5) a member variable whose type is a UDT.
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
