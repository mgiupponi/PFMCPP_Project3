/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


struct StationersShop      
{
    //StationersShop(); 
    int numPaperSizesForsale = 15;    
    int numWrappingPaperDesignsForsale = 20;        
    float monthElectricityBill;            
    float profitPerDay;               
    int numberOfEmployees;

    StationersShop() : monthElectricityBill( 138.2f ), profitPerDay( 138.2f ), numberOfEmployees( 10 ) { }
    
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

/*
StationersShop::StationersShop()
{
    std::cout << "StationersShop being constructed!" << std::endl;
}
*/

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
    std::cout << "StationersShop::makeAPhotocopy(...) monthElectricityBill:" << monthElectricityBill << " numberOfEmployees: " << numberOfEmployees << std::endl;
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
    int numSlots;  
    int numCreditCards = 4;     
    float amountOfCashCarried = 250.0f;            
    float weightIngrams = 150.5f;               
    std::string color = "Brown";

    Wallet() : numSlots( 7 ), color( "Brown" ) { }
    
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

/*
Wallet::Wallet()
{
    std::cout << "Wallet being constructed!" << std::endl;
}
*/

std::string Wallet::identifyTheOwner(CreditCard creditCardA)
{   
    std::cout << "Owner being identified!" << std::endl;
    return std::to_string(creditCardA.cardNumber);
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
    std::string color;
    float weightIngrams = 150.5f;     
    std::string processorModel = "Corei3";              
    int screenSizeInInches;               
    std::string brand = "Lenovo";

    Laptop() : color( "Black" ), screenSizeInInches( 17 ) { }
    
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

/*
Laptop::Laptop()
{
    std::cout << "Laptop being constructed!" << std::endl;
}
*/

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
    std::string color = "Red";
    int amountOfTools;     
    float weightInGrams= 40.0f;              
    int manufactureYear;               
    float marketValueInUsd = 75.0f;

    SwissArmyKnife() : amountOfTools( 8 ), manufactureYear( 2019 ) { }
    
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

/*
SwissArmyKnife::SwissArmyKnife()
{
    std::cout << "SwissArmyKnife being constructed!" << std::endl;
}
*/

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
    int amountOfDevices = 4; 
    int sizeInCm = 1;     
    double maxPowerWatts;              
    double maxDecibPower = 70;               
    int numberOfcoilwirings;

    Speakers() : maxPowerWatts( 5.0 ), numberOfcoilwirings( 200 ) { }
    
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

/*
Speakers::Speakers()
{
    std::cout << "Speakers being constructed!" << std::endl;
}
*/

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
    int lengthInCm;
    std::string color;     
    int amountOfinternalWires= 5;              
    std::string externalMatrerial = "Plastic";               

    Cables() : lengthInCm( 5 ), color( "Red" ) { }
    
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

/*
Cables::Cables()
{
    std::cout << "Cables being constructed!" << std::endl;
}
*/

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
    double bluetoothVersion;
    double transmissionPowerInMw = 300;     
    double receiverSensitivityInDb;              
    int distanceCoverageInMeters = 10;               
    float dataBwCapacityInMbps = 20.0f;

    BluetoothInterface() : bluetoothVersion( 2.0 ), receiverSensitivityInDb( 5.0 ) { }
    
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

/*
BluetoothInterface::BluetoothInterface()
{
    std::cout << "BluetoothInterface being constructed!" << std::endl;
}
*/

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
    double maxInputVoltage = 7.0;
    double widthInCm;     
    double lengthInCm;              
    int amountOfLayers = 4;                      
    float inputImpedance = 80.0f;

    LogicCircuit() : widthInCm( 2.0 ), lengthInCm( 5.0 ) { }
    
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

/*
LogicCircuit::LogicCircuit()
{
    std::cout << "LogicCircuit being constructed!" << std::endl;
}
*/

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

/*
Buttons::Buttons()
{
    std::cout << "Buttons being constructed!" << std::endl;
}
*/

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

/*
WirelessHeadphone::WirelessHeadphone()
{
    std::cout << "WirelessHeadphone being constructed!" << std::endl;
}
*/

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
    
    StationersShop stationersShop1;
    StationersShop::Paper paper1;
    std::cout << stationersShop1.makeAPhotocopy(paper1, true , false) << std::endl;
    std::cout << stationersShop1.takePassportPhoto(paper1, "A4") << std::endl;
    stationersShop1.wrapAGift("arrows");
    Wallet wallet1;
    Wallet::CreditCard creditCard1;
    std::cout << wallet1.identifyTheOwner(creditCard1) << std::endl;
    std::cout << wallet1.payLunch(creditCard1, 10.0f) << std::endl;
    wallet1.enterABuilding(10.0f);
    Laptop laptop1;
    Laptop::File file1;
    laptop1.readDocument(file1);
    laptop1.surfTheWeb("www.amazon.com", true);
    laptop1.TakeAPicture(file1, 23.0f);
    std::cout << laptop1.processorModel << std::endl;
    std::cout << laptop1.brand << std::endl;
    SwissArmyKnife swissArmyKnife1;
    SwissArmyKnife::Tool tool1;
    swissArmyKnife1.cutFood(tool1, 0.234f);
    swissArmyKnife1.openABottle(5.0, false);
    swissArmyKnife1.unscrew(tool1);
    std::cout << swissArmyKnife1.color << std::endl;
    std::cout << swissArmyKnife1.manufactureYear << std::endl;
    Speakers speakers1;
    Speakers::SoundFile soundFile1;
    speakers1.playAudibleSound(soundFile1, 3.0);
    speakers1.activateNoiseReduction(2);
    speakers1.playUltraSound(soundFile1, 1.2f);
    Cables cables1;
    Cables::Wire wire1;
    cables1.holdDeviceOverUsersHead();
    cables1.transportAudioSignals(wire1, "clap.wav");
    cables1.transportControlSignals(wire1, 100101110);
    BluetoothInterface BluetoothInterface1;
    BluetoothInterface::WirelessChannel wirelessChannel1;
    BluetoothInterface1.receiveAudio(wirelessChannel1, 2.0f);
    BluetoothInterface1.sendPlaySignal(wirelessChannel1);
    BluetoothInterface1.sendBatteryLevel(wirelessChannel1, true);
    LogicCircuit logicCircuit1;
    LogicCircuit::BusChannel busChannel1;
    logicCircuit1.generatePowerAudioForSpeakers(busChannel1, busChannel1, 30.0f);
    logicCircuit1.generateVoiceInformation(busChannel1, "Power On");
    logicCircuit1.monitorBatteryCharge(busChannel1);
    Buttons buttons1;
    Buttons::CircuitSwitch circuitSwitch1;
    buttons1.powerOnTheDevice(circuitSwitch1, 2);
    buttons1.changeSong(circuitSwitch1, 2);
    buttons1.answerACall(circuitSwitch1);
    WirelessHeadphone wirelessHeadphone1;
    WirelessHeadphone::RemoteDevice remoteDevice1;
    wirelessHeadphone1.playSound(remoteDevice1, 1.2);
    wirelessHeadphone1.recordSound(remoteDevice1, 1);
    wirelessHeadphone1.answerACall(remoteDevice1);
    
    std::cout << "good to go!" << std::endl;
}
