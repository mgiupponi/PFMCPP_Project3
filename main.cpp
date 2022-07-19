/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct StationersShop      
{
    StationersShop(); 
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

StationersShop::StationersShop()
{
    std::cout << "StationersShop being constructed!" << std::endl;
}

float StationersShop::makeAPhotocopy(Paper paperA, bool isBlackAndWhite, bool onesided)
{    
    float price = paperA.priceInUsd;
    if (isBlackAndWhite == false)
    {
         price = price * 2;
    }
    if (onesided == false)
    {
         price = price * 2;
    }
    std::cout << "Making a photocopy!" << std::endl;
    return price;
}

float StationersShop::takePassportPhoto(Paper paperB, std::string sizeStandard)
{    
    float price = paperB.priceInUsd;
    if (sizeStandard.length() > 2)
    {
         price = price * 2;
    }
    return price;
}

void StationersShop::wrapAGift(std::string wrappingPaperModel)
{    
    std::cout << wrappingPaperModel.size();
}

struct Wallet     
{
    Wallet();
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

Wallet::Wallet()
{
    std::cout << "Wallet being constructed!" << std::endl;
}

std::string Wallet::identifyTheOwner(CreditCard creditCardA)
{    
    return std::to_string(creditCardA.cardNumber);
    std::cout << "Owner being identified!" << std::endl;
}

bool Wallet::payLunch(CreditCard creditCardB, float tipPercentage)
{    
    if (creditCardB.availableCreditInUsd*tipPercentage > 50)
    {
         return true;
    }
    return false;
}

bool Wallet::enterABuilding(float walletOrientationToUseInDegrees)
{    
    if (walletOrientationToUseInDegrees > 45)
    {
         return true;
    }
    return false;
}

struct Laptop   
{
    Laptop();
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

Laptop::Laptop()
{
    std::cout << "Laptop being constructed!" << std::endl;
}

std::string Laptop::readDocument(File inputFile)
{    
    std::cout << "Starting to read document!" << std::endl;
    return inputFile.fullPath;
}

float Laptop::surfTheWeb(std::string url, bool incognitoMode)
{    
    float output = url.length();
    if (incognitoMode)
    {
         output *= 2;
    }
    return output;
}

void Laptop::TakeAPicture(File outputFile, float lidOrientationInDegrees)
{    
    if (lidOrientationInDegrees > 5)
        outputFile.fullPath.size();
}

struct SwissArmyKnife      
{
    SwissArmyKnife();
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

SwissArmyKnife::SwissArmyKnife()
{
    std::cout << "SwissArmyKnife being constructed!" << std::endl;
}

float SwissArmyKnife::cutFood(Tool toolA, float pressureToApply)
{    
    float output = toolA.thicknessInMm - pressureToApply;
    std::cout << "I will cut food!" << std::endl;
    return output;
}
bool SwissArmyKnife::openABottle(double speedInDegreesPerSecond, bool isACorkLid)
{    
    if (speedInDegreesPerSecond > 20)
    {
         return false;
    } 
    else if (isACorkLid)
    {
        return true;
    }
    return false;
}
void SwissArmyKnife::unscrew(Tool toolB)
{    
    std::to_string(toolB.lentghInCm);
}

struct Speakers    
{
    Speakers();
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
    float playUltraSound(SoundFile soundFileB, float level);
    
    SoundFile soundFileBeingPlayed;
};

Speakers::Speakers()
{
    std::cout << "Speakers being constructed!" << std::endl;
}

float Speakers::playAudibleSound(SoundFile soundFileA, double level)
{    
    float output = soundFileA.soundLengthInMs * static_cast<float>(level);
    std::cout << "Audio is going to be played!" << std::endl;
    return output;
}

bool Speakers::activateNoiseReduction(int duration)
{    
    if (duration > 50)
    {
         return false;
    }
    return true;
}

float Speakers::playUltraSound(SoundFile soundFileB, float level)
{  
    float output = soundFileB.soundLengthInMs + level;
    return output;
}

struct Cables      
{
    Cables();
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
    float transportControlSignals(Wire wireB, int binaryCode = 1100101010);
    
    Wire wireSelectedForSignal;
};

Cables::Cables()
{
    std::cout << "Cables being constructed!" << std::endl;
}

double Cables::holdDeviceOverUsersHead()
{    
    double output = 10.0;
    return output;
}
float Cables::transportAudioSignals(Wire wireA, std::string audioFile)
{    
    float output = wireA.resistancePerMeterInOhms + audioFile.length();
    std::cout << "Audio signal being transported!" << std::endl;
    return output;
}
float Cables::transportControlSignals(Wire wireB, int binaryCode)
{    
    float output = wireB.resistancePerMeterInOhms + binaryCode;
    return output;
}

struct BluetoothInterface      
{
    BluetoothInterface();
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

    float receiveAudio(WirelessChannel wirelessChannelC, float rxAmplification);
    float sendPlaySignal(WirelessChannel wirelessChannelA);
    float sendBatteryLevel(WirelessChannel wirelessChannelB, bool reCheckBattery = true );
    
    WirelessChannel wirelessChannelSelected;
};

BluetoothInterface::BluetoothInterface()
{
    std::cout << "BluetoothInterface being constructed!" << std::endl;
}

float BluetoothInterface::receiveAudio(WirelessChannel wirelessChannelC, float rxAmplification)
{    
    float output = wirelessChannelC.centerFrequencyInGhz + rxAmplification;
    std::cout << "Receving audio trough the bluetooth interface!" << std::endl;
    return output;
}
float BluetoothInterface::sendPlaySignal(WirelessChannel wirelessChannelA)
{    
    float output = wirelessChannelA.centerFrequencyInGhz;
    return output;
}
float BluetoothInterface::sendBatteryLevel(WirelessChannel wirelessChannelB, bool reCheckBattery)
{    
    float output = wirelessChannelB.centerFrequencyInGhz;
    if (reCheckBattery)
    {
        return output = output * 2;
    }
    return output;
}

struct LogicCircuit    
{
    LogicCircuit();
    double bluetoothVersion = 2.0;
    double transmissionPowerInMw = 300;     
    double receiverSensitivityInDb= 5.0;              
    int distanceCoverageInMeters = 10;                      
    float dataBwCapacityInMbps = 20.0f;               
    
    struct BusChannel      
    {
        int amountOfWires = 5;
        int amountOfdigitalwires = 2;
        float maxVoltage = 5.0f;
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

LogicCircuit::LogicCircuit()
{
    std::cout << "LogicCircuit being constructed!" << std::endl;
}

float LogicCircuit::generatePowerAudioForSpeakers(BusChannel txSpeakersChannel, BusChannel rxBluetoothBus, float amplificationLevel)
{    
    float output = txSpeakersChannel.maxVoltage * rxBluetoothBus.amountOfdigitalwires * amplificationLevel;
    return output;
}
void LogicCircuit::generateVoiceInformation(BusChannel busChannel, std::string stringToSend)
{    
    busChannel.busSource.length();
    std::cout << "Generating voice information!" << std::endl;
    stringToSend.length();
}
double LogicCircuit::monitorBatteryCharge(BusChannel batteryBusToRead)
{    
    double output = batteryBusToRead.amountOfdigitalwires;
    return output;
}

struct Buttons   
{
    Buttons();
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

Buttons::Buttons()
{
    std::cout << "Buttons being constructed!" << std::endl;
}

bool Buttons::powerOnTheDevice(CircuitSwitch circuitSwitchA, double amountOfSecondsPressed)
{    
    if (circuitSwitchA.amountOfPins + amountOfSecondsPressed> 20)
        return false;
    std::cout << "Powering the device on" << std::endl;
    return true;
}
void Buttons::changeSong(CircuitSwitch circuitSwitchB, int amountOfClicks)
{
    if (amountOfClicks > 20)
        circuitSwitchB.placementOntheCircuit.length();
}
std::string Buttons::answerACall(CircuitSwitch circuitSwitchB)
{
    return circuitSwitchB.placementOntheCircuit;
}

struct WirelessHeadphone       
{
    WirelessHeadphone();
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

WirelessHeadphone::WirelessHeadphone()
{
    std::cout << "WirelessHeadphone being constructed!" << std::endl;
}

bool WirelessHeadphone::playSound(RemoteDevice remoteDeviceA, double audioLevel)
{    
    if (remoteDeviceA.receivedPowerInDb + audioLevel > 20)
        return false;
    std::cout << "Playing sound!" << std::endl;
    return true;
}
double WirelessHeadphone::recordSound(RemoteDevice remoteDeviceB, int amountOfClicks)
{    
    double output = remoteDeviceB.receivedPowerInDb * amountOfClicks;
    return output;
}
std::string WirelessHeadphone::answerACall(RemoteDevice remoteDeviceB)
{
    return remoteDeviceB.deviceName;
}


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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
