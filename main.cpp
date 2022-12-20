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
#include <ctime>
#include <cmath>

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

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Limb
    {
        int position = 0;

        int stepSize();

        void stepForward();
    };

    Limb leftFoot, rightFoot;

    void run( int howFast, bool startWithLeftFoot);
};

int Person::Limb::stepSize()
{
    return 1;
}

void Person::Limb::stepForward()
{
   position += stepSize();
}


void Person::run( int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}


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


struct Cat
{
    int numLimbs = 3;
    int numTails = 1;
    float ageYears = 3.6f;
    std::string colour = "orange";
    float weightKg = 4.1f;
    int cutenessLevel= 50;

    void meow(int loudnessDB);

    bool catchAnimal(std::string animalSpecies); 

    float throwUpFurBall(); 
};

void Cat::meow(int loudnessDB)
{
    if (loudnessDB < 30)
    {
        cutenessLevel += 10;
    }
    else
    {
        cutenessLevel -= loudnessDB;        
    }
}

bool Cat::catchAnimal(std::string animalSpecies)
{
    if (animalSpecies == "Fly")
    {
        cutenessLevel += 10;
        return true;
    }
    else
    {
        cutenessLevel -= 10;
        return false;
    }
}

float Cat::throwUpFurBall()
{
    cutenessLevel -= 50;
    return weightKg * 4;
}

struct VendingMachine
{
    bool isOn = true;
    float interiorTemperatureCelsius = 10.2f;
    float targetTemperatureCelsius = 8.5f;
    float cashCollectedEuros = 123.54f;
    int itemSelected = 13;

    struct ItemDispenser
    {
        std::string name = "KitKat";
        std::string flavour = "Original";
        int inventory = 5;
        float priceEuros = 2.5f;
        int itemNumber = 13;
        bool isDisabled = false;

        bool distributeItems(int numberOfItems); 

        void stockUp(int itemsAdded); 

        void disable(std::string cause); 
    };

    float chargeCustomerEuros(ItemDispenser item, int numberOfItems); 

    bool dispenseItem(ItemDispenser itemDispenser, int numberOfItems); 

    bool refrigerate();
};

bool VendingMachine::ItemDispenser::distributeItems(int numberOfItems)
{
    if (inventory >= numberOfItems)
    {
        inventory -= numberOfItems;
        return true;
    }
    else 
    {
        if (inventory == 0)
        {
            disable("Empty");        
        }
        return false;
    }    
}

void VendingMachine::ItemDispenser::stockUp(int itemsAdded)
{
    inventory += itemsAdded;
}

void VendingMachine::ItemDispenser::disable(std::string cause)
{
    if (cause == "Empty") 
    {
        name = "";
        flavour = "";
    }
}

float VendingMachine::chargeCustomerEuros(ItemDispenser item, int numberOfItems)
{
    float priceCharged = 0.0f;
    for (int i = 0; i < numberOfItems; i++)
    {
        priceCharged += item.priceEuros;        
    }
    return priceCharged;
}

bool VendingMachine::dispenseItem(ItemDispenser itemDispenser, int numberOfItems)
{
    itemDispenser.distributeItems(numberOfItems);
    return itemDispenser.isDisabled;
}

bool VendingMachine::refrigerate()
{
    return interiorTemperatureCelsius > targetTemperatureCelsius;
}

struct Computer
{
    int numCPUCores = 6;
    float CPUFrequencyGHz = 3.4f;
    int memoryMB = 32;
    int powerNeededW = 430;
    std::string operatingSystem = "Solaris";

    struct Drive 
    {
        std::string brand = "Seagate";
        float capacityGB = 2000.0f;
        int standardRpm = 7200;
        float readSpeedMBs = 101.1f;
        float writeSpeedMs = 74.2f;

        int readData(int address); 
        
        bool writeData(int address, int data); 

        bool parkHeads(); 
    };

    bool bootUp(Drive systemDrive); 

    bool runProgram(Drive programDrive, std::string path); 

    bool crash();    
};

int Computer::Drive::readData(int address)
{
    return address * rand();
}

bool Computer::Drive::writeData(int address, int data)
{
    return ((rand() * address * data) % 1000000) != 0; // Very bad harddrive!
}

bool Computer::Drive::parkHeads()
{
    return (rand() % 1000000) != 0;
}

bool Computer::bootUp(Drive systemDrive)
{
    return systemDrive.readData(rand()) != 0;
}

bool Computer::runProgram(Drive programDrive, std::string path)
{
    std::cout << "Running " << path << "on " << programDrive.brand << std::endl;
    return true;
}

bool Computer::crash()
{
    if (operatingSystem == "Solaris") 
    {
        return false;
    }
    else
    {
        return (rand() % 1000000) == 0;
    }
}

struct Motorcycle
{
    std::string brand = "Harley Davidson";
    std::string model = "2022 Heritage Classic";
    std::string colour = "Pink";
    int enginePowerHp = 101;
    int numCylinders = 2;
    float speedKilometerPerHour = 0.0f; 

    void accelerate(float acceleration); 

    void decelerate(float deceleration);

    bool makeWheelie(); 
};

void Motorcycle::accelerate(float acceleration)
{
    speedKilometerPerHour += acceleration;
}

void Motorcycle::decelerate(float deceleration) 
{
    speedKilometerPerHour -= deceleration;
    if (speedKilometerPerHour < 0)
    {
        speedKilometerPerHour = 0;
    }
}

bool Motorcycle::makeWheelie() 
{
    return speedKilometerPerHour > 20;
}

struct Turntable
{
    float platterRpm = 32.9f;
    float tonearmCounterweightGrams = 160.0f;
    double motorVoltageVolts = 9.2345;
    float stylusMovementMicrometers = 2.5f;
    float speedSelection = 33.0f;

    void changeSpeedSelection(bool isIncreased); 

    void rotatePlatter(); 

    int grooveAmplitude();
};

void Turntable::changeSpeedSelection(bool isIncreased)
{
    if (isIncreased)
    {
        speedSelection = 45.0f;
    }
    else
    {
        speedSelection = 33.0f;
    }
}

void Turntable::rotatePlatter()
{
    float speedDifference = platterRpm - speedSelection;
    if (std::abs(speedDifference) > 0.5f)
    {
        platterRpm -= 0.1f*(speedDifference);
    }
}

int grooveAmplitude()
{
    return rand(); 
}


struct CassetteDeck
{
    bool isCompartmentOpen = false;
    float tapeSpeedCmPerSecond = 4.76f;
    float reelSpeed;
    float speedCoefficient = 1.124f;
    double playHeadCurrentMilliAmps = 0.83;
    std::string controlButtonPressed = "Play";
    int counter = 354;
    bool isForward = true;
    
    int readMagneticInformation(); 

    void rotateReel(); 

    void reverseDirection(); 
};

int CassetteDeck::readMagneticInformation()
{
    return rand();
}

void CassetteDeck::rotateReel()
{
    if(!isForward)
    {
        speedCoefficient = -speedCoefficient;
    }
    
    reelSpeed = tapeSpeedCmPerSecond * speedCoefficient;
}

void CassetteDeck::reverseDirection()
{
    isForward = !isForward;
}

struct Amplifier
{
    float volumeButtonValue = 11.1f;
    float maxVolume = 100.0f;
    double inputSignalVoltageVolts = 0.0;
    double speakerOutputVoltageVolts = 0.0;
    std::string sourceSelected = "turntable";
    std::string equalizerPreset = "jazz";

    void changeVolume(bool up); 

    int outputSound(); 

    void changeSource(std::string newSource);
};

void Amplifier::changeVolume(bool up)
{
    float volumeDelta = 0.1f;
    if (up)
    {
        volumeButtonValue += volumeDelta;
        if (volumeButtonValue > maxVolume)
        {
            volumeButtonValue = maxVolume;
        }
    }
    else
    {
        volumeButtonValue -= volumeDelta;
        if (volumeButtonValue < 0)
        {
            volumeButtonValue = 0;
        }
    }
}

int Amplifier::outputSound()
{
    return rand();
}

void Amplifier::changeSource(std::string newSource)
{
    sourceSelected = newSource;
}

struct Tuner
{
    std::string bandSelected = "FM";
    float tuningKnobAngleRadians = 1.234f;
    std::string presetButtonPressed = "none";
    float dialPositionMillimeters = 15.3f;
    double antennaSignalVoltageMillivolts = 0.132;
    float tuning;
    
    void selectBand(std::string newBand);

    void changeTuning(bool up); 

    void lightUp(); 
};

void Tuner::selectBand(std::string newBand)
{
    bandSelected = newBand;
}

void Tuner::changeTuning(bool up)
{   // TODO Tuning and tuning limits for various bands
    float tuningDelta = 1;
    if (up)
    {
        tuning += tuningDelta;
    }
    else
    {
        tuning -= tuningDelta;
    }
}

void Tuner::lightUp()
{
    std::cout << "Dial lit up!" << std::endl;
}

struct Speaker
{
    double bassDriverVoltageVolts = 31.43;
    float bassConeDisplacementMillimeters = 2.3f;
    double treebleDriverVoltageVolts = 30.56;
    float treebleConeDisplacementMillimeters = 0.4f;
    float ventExhaustOverPressurePa = 45.121f;
    float maxCurrent = 1.2f;

    float processSignal(float inputSignal); 
  
    float emitSound(float driverCurrent);
    
    bool blow(float driverCurrent);
};

float Speaker::processSignal(float inputSignal)
{
    float processingConstant = 0.182917f;
    
    return inputSignal * processingConstant;
}

float Speaker::emitSound(float driverCurrent)
{
    float conversionConstant = 0.12842f;
    
    return driverCurrent*conversionConstant;
}

bool Speaker::blow(float driverCurrent)
{
    return std::abs(driverCurrent) > maxCurrent;
}

struct Stereo
{
    Turntable turntable;
    CassetteDeck cassetteDeck;
    Amplifier amplifier;
    Tuner tuner;
    Speaker speaker1, speaker2;

    bool playMusic(std::string source);

    void changeRadioChannel(std::string newRadioChannel, bool up);

    bool recordTape(std::string inputSource); 
};

bool Stereo::playMusic(std::string source)
{
    return source == "Turntable" || source == "Cassette" || source == "Tuner";
}

void Stereo::changeRadioChannel(std::string newRadioChannel, bool up)
{
    std::cout << "Channel changed to: " << newRadioChannel << std::endl;
    tuner.changeTuning(up);
}

bool Stereo::recordTape(std::string inputSource)
{
    if (inputSource == "Turntable" || inputSource == "Tuner")
    {
        cassetteDeck.rotateReel();
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(438905280);
    std::cout << "good to go!" << std::endl;
}
