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
    cutenessLevel -= 10;
    return false;
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
    if (inventory == 0)
    {
        disable("Empty");        
    }
    return false;
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
    return (rand() % 1000000) == 0;
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
    return false;
}

int main()
{
    Example::main();
    
    
    srand(438905280);
    std::cout << "good to go!" << std::endl;
}
