/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()

struct StationersShop      
{
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
    float chargeCustomer(std::string customerName, float maxCredit, int numItems);
    float sendItems(std::string customerAddress, float weightPerItem, int numItems);

    Paper paperToBeUsed;  
};

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

float StationersShop::chargeCustomer(std::string customerName, float maxCredit, int numItems)
{    
    float totalPrice = 0.0f;
    auto paper = StationersShop::Paper();
    while ( totalPrice < maxCredit ) 
    {
        paper.priceInUsd = ( maxCredit / numItems ) * 0.95f - paper.priceInUsd * 0.2f;
        totalPrice += paper.priceInUsd * 1.2f;
        std::cout << "chargeCustomer customerName:" << customerName << " totalPrice: " << totalPrice << std::endl;
    }
    return totalPrice;
}


float StationersShop::sendItems(std::string customerAddress, float weightPerItem, int numItems)
{   
    float shippingCost = 0.0f;
    auto paper = StationersShop::Paper();
    int i = 0;
    while ( i < numItems ) 
    {
        paper.thicnessInuM = ( paper.thicnessInuM ) * 0.95f + paper.thicnessInuM * 0.2f;
        shippingCost += paper.thicnessInuM * 0.8f + weightPerItem;
        std::cout << "sendItems customerAddress:" << customerAddress << " shippingCost: " << shippingCost << std::endl;
        ++i;
    }
    return shippingCost;
}


struct Wallet     
{
    int numSlots;  
    int numCreditCards = 4;     
    float amountOfCashCarried = 250.0f;            
    float weightInGrams = 150.5f;               
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
    float creditAuthorization(CreditCard creditCardB, float pricePerItem, int numItems);
    float creditCardBalance(CreditCard creditCardB, int maxEntries);
    
    CreditCard creditCardSelected;
};

std::string Wallet::identifyTheOwner(CreditCard creditCardA)
{   
    std::cout << "Owner being identified!" << std::endl;
    std::cout << "Wallet::identifyTheOwner(...) numSlots:" << numSlots << " numCreditCards: " << numCreditCards << std::endl;
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

float Wallet::creditAuthorization(CreditCard creditCardB, float pricePerItem, int numItems)
{    
    float amountReserved = 0.0f;
    for (int i = 0; i < numItems; ++i)
    {
        creditCardB.availableCreditInUsd = ( creditCardB.availableCreditInUsd ) * 0.7f + pricePerItem;
        amountReserved += creditCardB.availableCreditInUsd * 1.01f;
        std::cout << "creditAuthorization cardNumber:" << creditCardB.cardNumber << " availableCreditInUsd: " << creditCardB.availableCreditInUsd << std::endl;
    }
    return amountReserved;
}

float Wallet::creditCardBalance(CreditCard creditCardB, int maxEntries)
{    
    float finalBalance = 0.0f;
    for (int i = 0; i < maxEntries; ++i) 
    {
        creditCardB.availableCreditInUsd *= 0.9f;
        finalBalance += creditCardB.availableCreditInUsd * 1.05f;
        std::cout << "creditCardBalance cardNumber:" << creditCardB.cardNumber << " finalBalance: " << finalBalance << std::endl;
    }
    return finalBalance;
}

struct Laptop   
{
    std::string color;
    float weightInGrams = 150.5f;     
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
    float defragmentFile(File inputFile, float precision);
    float zoomFile(File inputFile, float zoomPercentage);

    File fileBeingProcessed;
};

std::string Laptop::readDocument(File inputFile)
{    
    std::cout << "Starting to read document!" << std::endl;
    std::cout << "Laptop::readDocument(...) color:" << color << " weightInGrams: " << weightInGrams << std::endl;
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

float Laptop::defragmentFile(File inputFile, float precision)
{    
    float achievedPrecision = 0.0f;
    while ( achievedPrecision < precision ) 
    {
        inputFile.sizeInBytes *= 0.8f;
        achievedPrecision += 2.0f ;
        std::cout << "defragmentFile fullPath:" << inputFile.fullPath << " achievedPrecision: " << achievedPrecision << std::endl;
    }
    return achievedPrecision;
}

float Laptop::zoomFile(File inputFile, float zoomPercentage)
{    
    float currentZoom = 100.0f;
    while ( currentZoom < zoomPercentage ) { FIXME
        inputFile.sizeInBytes *= 1.1f;
        currentZoom += inputFile.sizeInBytes * 0.02f;
        std::cout << "zoomFile fullPath:" << inputFile.fullPath << " sizeInBytes: " << inputFile.sizeInBytes << std::endl;
    }
    return currentZoom;
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
    float megaPressure(Tool toolA, float pressure);
    float reflectSun(Tool toolA, float lightIntensity);

    Tool toolBeingUsed;
};

float SwissArmyKnife::cutFood(Tool toolA, float pressureToApply)
{    
    float output = toolA.thicknessInMm - pressureToApply;
    std::cout << "I will cut food!" << std::endl;
    std::cout << "SwissArmyKnife::cutFood(...) color:" << color << " amountOfTools: " << amountOfTools << std::endl;
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

float SwissArmyKnife::megaPressure(Tool toolA, float pressure)
{    
    float currentPessure = 0.0f;
    while ( currentPessure < pressure ) { FIXME
        toolA.thicknessInMm *= 1.2f;
        currentPessure += 2.0f ;
        std::cout << "megaPressure toolName:" << toolA.toolName << " thicknessInMm: " << toolA.thicknessInMm << std::endl;
    }
    return currentPessure;
}

float SwissArmyKnife::reflectSun(Tool toolA, float lightIntensity)
{    
    float lengthIncrease = 0.0f;
    while ( lengthIncrease < lightIntensity ) { FIXME
        toolA.lentghInCm *= 1.2f;
        lengthIncrease += 2.0f ;
        std::cout << "reflectSun toolName:" << toolA.toolName << " lentghInCm: " << toolA.lentghInCm << std::endl;
    }
    return lengthIncrease;
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
    float compensateNoise(SoundFile soundFileA, float intensity);
    float forceZero(SoundFile soundFileA, float maxWatts);
    
    SoundFile soundFileBeingPlayed;
};

float Speakers::playAudibleSound(SoundFile soundFileA, double level)
{    
    float output = soundFileA.soundLengthInMs * static_cast<float>(level);
    std::cout << "Audio is going to be played!" << std::endl;
    std::cout << "Speakers::playAudibleSound(...) maxPowerWatts:" << maxPowerWatts << " maxDecibPower: " << maxDecibPower << std::endl;
    return output;
}

bool Speakers::activateNoiseReduction(int duration)
{    
    if (duration > 50)
    {
         return false; FIXME
    }
    return true;
}

float Speakers::playUltraSound(SoundFile soundFileB, float level)
{  
    float output = soundFileB.soundLengthInMs + level;
    return output;
}

float Speakers::compensateNoise(SoundFile soundFileA, float intensity)
{    
    float currentIntensity = 0.0f;
    while ( currentIntensity < intensity ) { FIXME
        soundFileA.soundLengthInMs *= 1.8f;
        currentIntensity += 2.5f ;
        std::cout << "compensateNoise filePath:" << soundFileA.filePath << " soundLengthInMs: " << soundFileA.soundLengthInMs << std::endl;
    }
    return currentIntensity;
}

float Speakers::forceZero(SoundFile soundFileA, float maxWatts)
{    
    float currentWatts = 0.0f;
    while ( currentWatts < maxWatts ) { FIXME
        soundFileA.soundLengthInMs *= 1.4f;
        currentWatts += 4.0f ;
        std::cout << "forceZero filePath:" << soundFileA.filePath << " soundLengthInMs: " << soundFileA.soundLengthInMs << std::endl;
    }
    return currentWatts;
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
    float sendSquareWave(Wire wireA, int maxVoltage);
    float resetToGround(Wire wireA, int timeMillis);

    Wire wireSelectedForSignal;
};

double Cables::holdDeviceOverUsersHead()
{    
    double output = 10.0;
    return output;
}
float Cables::transportAudioSignals(Wire wireA, std::string audioFile)
{    
    float output = wireA.resistancePerMeterInOhms + audioFile.length();
    std::cout << "Audio signal being transported!" << std::endl;
    std::cout << "Cables::transportAudioSignals(...) lengthInCm:" << lengthInCm << " amountOfinternalWires: " << amountOfinternalWires << std::endl;
    return output;
}
float Cables::transportControlSignals(Wire wireB, int binaryCode)
{    
    float output = wireB.resistancePerMeterInOhms + binaryCode;
    return output;
}

float Cables::sendSquareWave(Wire wireA, int maxVoltage)
{    
    float currentVoltage = 0.0f;
    for (int i = 0; i < maxVoltage; ++i) 
    {
        wireA.resistancePerMeterInOhms *= 0.9f;
        currentVoltage += 1.05f;
        std::cout << "sendSquareWave material:" << wireA.material << " resistancePerMeterInOhms: " << wireA.resistancePerMeterInOhms << std::endl;
    }
    return currentVoltage;
}
float Cables::resetToGround(Wire wireA, int timeMillis)
{    
    float currentPower = 0.8f;
    for (int i = 0; i < timeMillis; ++i) { FIXME
        wireA.thicknessInUm *= 0.7f;
        currentPower *= 1.2f;
        std::cout << "resetToGround material:" << wireA.material << " currentPower: " << currentPower << std::endl;
    }
    return currentPower;
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
        float channelCapacityInMbps = 20.0f;
        std::string channelName = "23";

        bool testIfChannelAvailable();
        int listenChannel(float sensitivityInDb, double durationInMicroSeconds);
        void sendBinaryCode(double frequency, int binaryCode = 1100101010);
    };

    float receiveAudio(WirelessChannel wirelessChannelC, float rxAmplification);
    float sendPlaySignal(WirelessChannel wirelessChannelA);
    float sendBatteryLevel(WirelessChannel wirelessChannelB, bool reCheckBattery = true );
    float restartConnection(WirelessChannel wirelessChannelA, int retries);

    WirelessChannel wirelessChannelSelected;
};

float BluetoothInterface::receiveAudio(WirelessChannel wirelessChannelC, float rxAmplification)
{    
    float output = wirelessChannelC.centerFrequencyInGhz + rxAmplification;
    std::cout << "Receving audio trough the bluetooth interface!" << std::endl;
    std::cout << "BluetoothInterface::receiveAudio(...) bluetoothVersion:" << bluetoothVersion << " transmissionPowerInMw: " << transmissionPowerInMw << std::endl;
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

float BluetoothInterface::restartConnection(WirelessChannel wirelessChannelA, int retries)
{    
    float receivedPower = 0.3f;
    for (int i = 0; i < retries; ++i)
    {
        wirelessChannelA.channelCapacityInMbps *= 0.9f;
        receivedPower *= 1.32f;
        std::cout << "restartConnection channelName:" << wirelessChannelA.channelName << " channelCapacityInMbps: " << wirelessChannelA.channelCapacityInMbps << std::endl;
    }
    return receivedPower;
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
    float resetChips(BusChannel busChannel, int speed);

    BusChannel busChannelBeingUsed;
};

float LogicCircuit::generatePowerAudioForSpeakers(BusChannel txSpeakersChannel, BusChannel rxBluetoothBus, float amplificationLevel)
{    
    float output = txSpeakersChannel.maxVoltage * rxBluetoothBus.amountOfdigitalwires * amplificationLevel;
    return output;
}
void LogicCircuit::generateVoiceInformation(BusChannel busChannel, std::string stringToSend)
{    
    busChannel.busSource.length();
    std::cout << "Generating voice information!" << std::endl;
    std::cout << "LogicCircuit::generateVoiceInformation(...) maxInputVoltage:" << maxInputVoltage << " widthInCm: " << widthInCm << std::endl;
    stringToSend.length();
}
double LogicCircuit::monitorBatteryCharge(BusChannel batteryBusToRead)
{    
    double output = batteryBusToRead.amountOfdigitalwires;
    return output;
}

float LogicCircuit::resetChips(BusChannel busChannel, int speed)
{    
    float currentSpeed = 0.3f;
    for (int i = 0; i < speed; ++i) 
    {
        busChannel.maxVoltage *= 0.9f;
        currentSpeed *= 1.32f;
        std::cout << "resetChips busDestination:" << busChannel.busDestination << " maxVoltage: " << busChannel.maxVoltage << std::endl;
    }
    return currentSpeed;
}

struct Buttons   
{
    int Amount;
    std::string color;     
    int IPProtection = 57;              
    std::string material = "silicone";               
    double areaInMm = 20.0;

    Buttons() : Amount( 3 ), color( "Black" ) { }
    
    struct CircuitSwitch      
    {
        bool normallyOpen = true;
        int amountOfPins = 2;
        float lengthInMm = 7.0f;
        double widthInMm = 7;
        std::string placementOntheCircuit = "powerModule";

        bool testIfBusAvailable();
        bool pressSwitch(float timePressingInMilliseconds = 200, float pressureApplied = 5.0f);
        void sendAudioSignal(int wireNumber, std::string audioCode);
    };

    bool powerOnTheDevice(CircuitSwitch circuitSwitchA, double amountOfSecondsPressed = 2);
    void changeSong(CircuitSwitch circuitSwitchB, int amountOfClicks = 1 );
    std::string answerACall(CircuitSwitch circuitSwitchB);
    float factoryReset(CircuitSwitch circuitSwitchA, int flashErases);

    CircuitSwitch circuitSwitchBeingUsed;
};

bool Buttons::powerOnTheDevice(CircuitSwitch circuitSwitchA, double amountOfSecondsPressed)
{    
    if (circuitSwitchA.amountOfPins + amountOfSecondsPressed> 20) FIXME
        return false;
    std::cout << "Powering the device on" << std::endl;
    std::cout << "Buttons::powerOnTheDevice(...) color:" << color << " material: " << material << std::endl;
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

float Buttons::factoryReset(CircuitSwitch circuitSwitchA, int flashErases)
{    
    float remainingCharge = 0.3f;
    for (int i = 0; i < flashErases; ++i) 
    {
        circuitSwitchA.lengthInMm *= 0.9f;
        remainingCharge /= 1.32f;
        std::cout << "factoryReset lengthInMm:" << circuitSwitchA.lengthInMm << " remainingCharge: " << remainingCharge << std::endl;
    }
    return remainingCharge;
}


struct WirelessHeadphone       
{
    Speakers speakers;
    Cables cables;     
    BluetoothInterface bluetoothInterface;              
    LogicCircuit logicCircuit;               
    Buttons buttons;

    WirelessHeadphone() : speakers( Speakers() ), bluetoothInterface( BluetoothInterface() ) { }

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
    float muteMic(RemoteDevice remoteDeviceA, int retries);

    RemoteDevice remoteDeviceBeingUsed;
};

bool WirelessHeadphone::playSound(RemoteDevice remoteDeviceA, double audioLevel)
{    
    if (remoteDeviceA.receivedPowerInDb + audioLevel > 20)
        return false;
    std::cout << "Playing sound!" << std::endl;
    std::cout << "WirelessHeadphone::playSound(...) speakers.amountOfDevices:" << speakers.amountOfDevices << " cables.color: " << cables.color << std::endl;
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

float WirelessHeadphone::muteMic(RemoteDevice remoteDeviceA, int retries)
{    
    float bitsReceived = 0.3f;
    for (int i = 0; i < retries; ++i)
    {
        remoteDeviceA.receivedPowerInDb *= 0.23;
        bitsReceived *= 1.32f;
        std::cout << "muteMic receivedPowerInDb:" << remoteDeviceA.receivedPowerInDb << " bitsReceived: " << bitsReceived << std::endl;
    }
    return bitsReceived;
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
    stationersShop1.chargeCustomer("Pepe", 120.0f, 5);
    stationersShop1.sendItems("282 zabala street", 12.0f, 3);
    
    Wallet wallet1;
    Wallet::CreditCard creditCard1;
    std::cout << wallet1.identifyTheOwner(creditCard1) << std::endl;
    std::cout << wallet1.payLunch(creditCard1, 10.0f) << std::endl;
    wallet1.enterABuilding(10.0f);
    wallet1.creditAuthorization(creditCard1, 15.2f, 9);
    wallet1.creditCardBalance(creditCard1, 8);
    
    Laptop laptop1;
    Laptop::File file1;
    laptop1.readDocument(file1);
    laptop1.surfTheWeb("www.amazon.com", true);
    laptop1.TakeAPicture(file1, 23.0f);
    std::cout << laptop1.processorModel << std::endl;
    std::cout << laptop1.brand << std::endl;
    laptop1.defragmentFile(file1, 8);
    laptop1.zoomFile(file1, 200.0f);
    
    SwissArmyKnife swissArmyKnife1;
    SwissArmyKnife::Tool tool1;
    swissArmyKnife1.cutFood(tool1, 0.234f);
    swissArmyKnife1.openABottle(5.0, false);
    swissArmyKnife1.unscrew(tool1);
    std::cout << swissArmyKnife1.color << std::endl;
    std::cout << swissArmyKnife1.manufactureYear << std::endl;
    swissArmyKnife1.megaPressure(tool1, 15.0f);
    swissArmyKnife1.reflectSun(tool1, 8.2f);
    
    Speakers speakers1;
    Speakers::SoundFile soundFile1;
    speakers1.playAudibleSound(soundFile1, 3.0);
    speakers1.activateNoiseReduction(2);
    speakers1.playUltraSound(soundFile1, 1.2f);
    speakers1.compensateNoise(soundFile1, 12.0f);
    speakers1.forceZero(soundFile1, 5.6f);
    
    Cables cables1;
    Cables::Wire wire1;
    cables1.holdDeviceOverUsersHead();
    cables1.transportAudioSignals(wire1, "clap.wav");
    cables1.transportControlSignals(wire1, 100101110);
    cables1.sendSquareWave(wire1, 5);
    cables1.resetToGround(wire1, 7);
    
    BluetoothInterface BluetoothInterface1;
    BluetoothInterface::WirelessChannel wirelessChannel1;
    BluetoothInterface1.receiveAudio(wirelessChannel1, 2.0f);
    BluetoothInterface1.sendPlaySignal(wirelessChannel1);
    BluetoothInterface1.sendBatteryLevel(wirelessChannel1, true);
    BluetoothInterface1.restartConnection(wirelessChannel1, 5);
    
    LogicCircuit logicCircuit1;
    LogicCircuit::BusChannel busChannel1;
    logicCircuit1.generatePowerAudioForSpeakers(busChannel1, busChannel1, 30.0f);
    logicCircuit1.generateVoiceInformation(busChannel1, "Power On");
    logicCircuit1.monitorBatteryCharge(busChannel1);
    logicCircuit1.resetChips(busChannel1, 7);
    
    Buttons buttons1;
    Buttons::CircuitSwitch circuitSwitch1;
    buttons1.powerOnTheDevice(circuitSwitch1, 2);
    buttons1.changeSong(circuitSwitch1, 2);
    buttons1.answerACall(circuitSwitch1);
    buttons1.factoryReset(circuitSwitch1, 4);
    
    WirelessHeadphone wirelessHeadphone1;
    WirelessHeadphone::RemoteDevice remoteDevice1;
    wirelessHeadphone1.playSound(remoteDevice1, 1.2);
    wirelessHeadphone1.recordSound(remoteDevice1, 1);
    wirelessHeadphone1.answerACall(remoteDevice1);
    wirelessHeadphone1.muteMic(remoteDevice1, 6);
    
    std::cout << "good to go!" << std::endl;
}
