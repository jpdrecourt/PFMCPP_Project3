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
#include <iomanip>
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
            ++bar.num;                    //2a), 5)
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





struct Cat
{
    Cat();
    int numLimbs;
    int numTails;
    float ageYears;
    std::string colour;
    float weightKg;
    int cutenessLevel;
    int maxCroquettes;

    void meow(int loudnessDB);

    bool catchAnimal(std::string animalSpecies); 

    float throwUpFurBall(); 

    int eatCroquettes(int croquettesNum, float croquetteWeight);
};

Cat::Cat() :
numLimbs(3),
numTails(1),
ageYears(3.6f),
colour("orange"),
weightKg(4.1f),
cutenessLevel(50),
maxCroquettes(7)
{
    std::cout << "Cat being constructed" << std::endl;
}

void Cat::meow(int loudnessDB)
{
    std::cout << "Meow!!!" << std::endl;
    std::cout << "My current cuteness level is " << cutenessLevel << std::endl;
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
    return weightKg * 11;
}

int Cat::eatCroquettes(int croquettesNum, float croquetteWeightG)
{
    int i = 0;
    while (i < croquettesNum)
    {
        ++i;
        weightKg += croquetteWeightG * 0.001f;
        std::cout << "Eating a croquette... yum!\n";
        if (i >= maxCroquettes) 
        {
            std::cout << "I had enough.\n";
            return croquettesNum - i;
        }
    }
    return 0;
}

struct VendingMachine
{
    VendingMachine();
    bool isOn = true;
    float interiorTemperatureCelsius = 10.2f;
    float targetTemperatureCelsius = 8.5f;
    float cashCollectedEuros = 123.54f;
    int itemSelected = 13;

    struct ItemDispenser
    {
        ItemDispenser();
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

    ItemDispenser kitkatDispenser;

    float chargeCustomerEuros(ItemDispenser item, int numberOfItems); 

    bool dispenseKitkat(int numberOfItems); 

    void refrigerate();
};

VendingMachine::VendingMachine()
{
    std::cout << "VendingMachine being constructed" << std::endl;
}

VendingMachine::ItemDispenser::ItemDispenser() :
name("KitKat"),
flavour("Original"),
inventory(5),
priceEuros(2.5f),
itemNumber(13),
isDisabled(false)
{
    std::cout << "VendingMachine::ItemDispenser being constructed" << std::endl;
}

bool VendingMachine::ItemDispenser::distributeItems(int numberOfItems)
{
    for (int i = 0; i < numberOfItems; ++i)
    {
        std::cout << "Distributing item\n";
        --inventory;
        if (inventory == 0) 
        {
            disable("Empty");
            return (++i == numberOfItems);
        }
    }
    return true;
}

void VendingMachine::ItemDispenser::stockUp(int itemsAdded)
{
    inventory += itemsAdded;
    isDisabled = false;
}

void VendingMachine::ItemDispenser::disable(std::string cause)
{
    if (cause == "Empty") 
    {
        std::cout << "Please restock " << name << " - " << flavour << std::endl;
    }
    isDisabled = true;
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

bool VendingMachine::dispenseKitkat(int numberOfItems)
{
    std::cout << "Attempt at dispensing " << numberOfItems << " items\n";
    return kitkatDispenser.distributeItems(numberOfItems);
}

void VendingMachine::refrigerate()
{
    std::cout << (interiorTemperatureCelsius > targetTemperatureCelsius ? "Refrigeration in progress..." : "No refrigeration needed") << std::endl;
}

struct Computer
{
    Computer();
    int numCPUCores = 6;
    float CPUFrequencyGHz = 3.4f;
    int memoryMB = 32;
    int powerNeededW = 430;
    std::string operatingSystem = "Solaris";

    struct Drive 
    {
        Drive();
        std::string brand = "Seagate";
        float capacityGB = 2000.0f;
        int standardRpm = 7200;
        float readSpeedMBs = 101.1f;
        float writeSpeedMs = 74.2f;

        int readData(int address); 
        
        bool writeData(int address, int data); 

        void parkHeads(); 
    };

    Drive cDrive;

    bool bootUp(Drive systemDrive); 

    bool runProgram(Drive programDrive, std::string path); 

    bool crash();    
};

Computer::Computer()
{
    std::cout << "Computer being constructed" << std::endl;
}

Computer::Drive::Drive()
{
    std::cout << "Computer::Drive being constructed" << std::endl;
}

int Computer::Drive::readData(int address)
{
    return address * rand();
}

bool Computer::Drive::writeData(int address, int data)
{
    return ((rand() * address * data) % 1000000) != 0; // Very bad harddrive!
}

void Computer::Drive::parkHeads()
{
    std::cout << ((rand() % 1000000) != 0 ? "Heads parked" : "Failed to park heads!") << std::endl;
}

bool Computer::bootUp(Drive systemDrive)
{
    return systemDrive.readData(rand()) != 0;
}

bool Computer::runProgram(Drive programDrive, std::string path)
{
    std::cout << "Running " << path << " on " << programDrive.brand << std::endl;
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
    Motorcycle();
    std::string brand = "Harley Davidson";
    std::string model = "2022 Heritage Classic";
    std::string colour = "Pink";
    int enginePowerHp = 101;
    int numCylinders = 2;
    float speedKph; 

    void accelerate(float acceleration); 

    void decelerate(float deceleration);

    bool makeWheelie(); 
};

Motorcycle::Motorcycle() :
speedKph(10)
{
    std::cout << "Motorcycle being constructed" << std::endl;
}

void Motorcycle::accelerate(float acceleration)
{
    std::cout << "Original speed is: " << speedKph << "km/h\n";
    speedKph += acceleration;
    std::cout << "New speed is: " << speedKph << "km/h\n";
}

void Motorcycle::decelerate(float deceleration) 
{
    std::cout << "Original speed is: " << speedKph << "km/h\n";
    speedKph -= deceleration;
    if (speedKph < 0)
    {
        speedKph = 0;
    }
    std::cout << "New speed is: " << speedKph << "km/h\n";
}

bool Motorcycle::makeWheelie() 
{
    return speedKph > 20;
}

struct Turntable
{
    Turntable();
    float platterRpm = 32.9f;
    float tonearmCounterweightGrams = 160.0f;
    double motorVoltageVolts = 9.2345;
    float stylusMovementMicrometers = 2.5f;
    float speedSelection = 33.0f;

    void changeSpeedSelection(bool isIncreased); 

    void regulateSpeed(); 

    int grooveAmplitude();
};

Turntable::Turntable()
{
    std::cout << "Turntable being constructed" << std::endl;
}

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
    std::cout << "New Speed selection: " << speedSelection << "rpm\n";
    regulateSpeed();
}

void Turntable::regulateSpeed()
{
    while (true)
    {
        float speedDifference = speedSelection - platterRpm;
        if (std::abs(speedDifference) < 0.05f) return;
        platterRpm += 0.5f * speedDifference;
        std::cout << "New platter speed: " << platterRpm << "rpm" << std::endl;        
    }
}

int Turntable::grooveAmplitude()
{
    return rand(); 
}


struct CassetteDeck
{
    CassetteDeck();
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

CassetteDeck::CassetteDeck()
{
    std::cout << "CassetteDeck being constructed" << std::endl;
}

int CassetteDeck::readMagneticInformation()
{
    return rand();
}

void CassetteDeck::rotateReel()
{
    float directionCoefficient = (isForward ? 1.0f : -1.0f);
    
    reelSpeed = tapeSpeedCmPerSecond * speedCoefficient * directionCoefficient;
}

void CassetteDeck::reverseDirection()
{
    isForward = !isForward;
}

struct Amplifier
{
    Amplifier();
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

Amplifier::Amplifier()
{
    std::cout << "Amplifier being constructed" << std::endl;
}

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
    std::cout << "New source: " << sourceSelected << std::endl;
}

struct Tuner
{
    Tuner();
    std::string bandSelected = "FM";
    float tuningKnobAngleRadians = 1.234f;
    std::string presetButtonPressed = "none";
    float dialPositionMillimeters = 15.3f;
    double antennaSignalVoltageMillivolts = 0.132;
    float tuning = 92.5f;
    float tuningDelta = 0.1f;
    
    void selectBand(std::string newBand);

    void changeTuning(bool up); 

    void lightUp();

};

Tuner::Tuner()
{
    std::cout << "Tuner being constructed" << std::endl;
}

void Tuner::selectBand(std::string newBand)
{
    bandSelected = newBand;
}

void Tuner::changeTuning(bool up)
{   
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
    Speaker();
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

Speaker::Speaker()
{
    std::cout << "Speaker being constructed" << std::endl;
}

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
    Stereo();
    Turntable turntable;
    CassetteDeck cassetteDeck;
    Amplifier amplifier;
    Tuner tuner;
    Speaker speaker1, speaker2;
    std::string sourcePlaying;

    bool playMusic(std::string source);

    void changeRadioChannel(std::string newRadioChannel, bool up);

    bool recordTape(); 
};

Stereo::Stereo()
{
    std::cout << "Stereo being constructed" << std::endl;
}

bool Stereo::playMusic(std::string source)
{
    if (source == "Turntable" || source == "Cassette" || source == "Tuner")
    {
        sourcePlaying = source;    
        return true;
    }
    return false;
}

void Stereo::changeRadioChannel(std::string newRadioChannel, bool up)
{
    std::cout << "Channel changed to: " << newRadioChannel << std::endl;
    tuner.changeTuning(up);
}

bool Stereo::recordTape()
{
    if (sourcePlaying == "Turntable" || sourcePlaying == "Tuner")
    {
        cassetteDeck.rotateReel();
        return true;
    }
    return false;
}

int main()
{
    Example::main();
    // "---" in output indicates call to a member function
    std::cout << std::endl;
    
    srand(438905280);

    Cat cat;
    std::cout << std::fixed << std::setprecision(1)
        << "The cat has " << cat.numLimbs << " limb(s) and " << cat.numTails << " tail(s). It is " << cat.ageYears << " year(s) old. Its colour is " << cat.colour << ". And its cuteness level is " << cat.cutenessLevel << ".\n"
        << "Cat weight: " << cat.weightKg << "kg\n"
        << "Max croquettes eaten in one sitting: " << cat.maxCroquettes << "\n"
        << "--- ";
    cat.meow(42);
    std::cout
        << "--- "
        << "Did the cat catch a fly? " << (cat.catchAnimal("Fly") ? "Yes!" : "No :(") << "\n"
        << "--- "
        << "Size of the furball: " << cat.throwUpFurBall() << "mm\n"
        << "--- Attempting to eat 11 croquettes in bowl\n"
        << cat.eatCroquettes(11, 1) << " croquette(s) left in bowl\n"
        << std::setprecision(3)
        << "Cat new weight: " << cat.weightKg << "\n"
        << std::endl;
    
    VendingMachine vendingMachine;
    std::cout 
        << std::setprecision(1)
        << "Vending machine on: " << (vendingMachine.isOn ? "Yes" : "No") << "\n"
        << "Interior temperature: " << vendingMachine.interiorTemperatureCelsius << "°C" << "\n"
        << "Target temperature: " << vendingMachine.targetTemperatureCelsius << "°C" << "\n"
        << "--- ";
    vendingMachine.refrigerate();
    std::cout << std::setprecision(2) 
        << "Cash collected: " << vendingMachine.cashCollectedEuros << "€\n" 
        << "Item selected: " << vendingMachine.itemSelected << "\n"
        << "--- "
        << "Charging customer for 5 items: " << vendingMachine.chargeCustomerEuros(vendingMachine.kitkatDispenser, 5) << "€\n"
        << "*** Dispenser number: " << vendingMachine.kitkatDispenser.itemNumber << "\n"
        << "*** "
        << (vendingMachine.kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "*** Product: " << vendingMachine.kitkatDispenser.name << "\n"
        << "*** Flavour: " << vendingMachine.kitkatDispenser.flavour << "\n"
        << "*** Inventory: " << vendingMachine.kitkatDispenser.inventory << "\n"
        << "*** Price: " << vendingMachine.kitkatDispenser.priceEuros << "€\n"
        << "--- "
        << (vendingMachine.dispenseKitkat(6) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser state: " << (vendingMachine.kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n";
    
    vendingMachine.kitkatDispenser.stockUp(3);
    std::cout 
        << "--- "
        << "New item dispenser inventory: " << vendingMachine.kitkatDispenser.inventory << "\n"
        << "New item dispenser state: " << (vendingMachine.kitkatDispenser.isDisabled ? "Disabled" : "Activated") << "\n"
        << "--- "
        << (vendingMachine.dispenseKitkat(2) ? "Successfully" : "Unsuccessfully") << " dispensed\n"
        << "--- "
        << "New item dispenser inventory: " << vendingMachine.kitkatDispenser.inventory << "\n";
    std::cout << std::endl;
    
    Computer computer;
    std::cout 
        << "--- "
        << "Computer booted: " << (computer.bootUp(computer.cDrive) ? "Yes" : "No") << "\n"
        << "Number of cores: " << computer.numCPUCores << "\n"
        << "CPU Frequency: " << computer.CPUFrequencyGHz << "GHz\n"
        << "RAM: " << computer.memoryMB << "MB\n"
        << "Power needed: " << computer.powerNeededW << "W\n"
        << "Operating system: " << computer.operatingSystem << "\n"
        << "*** Drive brand: " << computer.cDrive.brand << "\n"
        << "*** Drive capacity: " << computer.cDrive.capacityGB << "GB\n"
        << "*** Drive RPM: " << computer.cDrive.standardRpm << "\n"
        << "*** Drive read speed: " << computer.cDrive.readSpeedMBs << "MB/s\n"
        << "--- "
        << "*** Data read at address 123: " << computer.cDrive.readData(123) << "\n"
        << "--- "
        << "*** Writing data 456 at address 678 successful?: " << (computer.cDrive.writeData(678, 456) ? "Yes" : "No") << "\n"
        << "--- ";
    computer.runProgram(computer.cDrive, "/usr/local/games/pacman/pacman");
    std::cout 
        << "--- "
        << "Computer crashed: " << (computer.crash() ? "Yes :(" : "No") << "\n"
        << "--- ";
    computer.cDrive.parkHeads();
    std::cout << std::endl;
    
    Motorcycle motorcycle;
    std::cout 
        << "Brand: " << motorcycle.brand << "\n"
        << "Model: " << motorcycle.model << "\n"
        << "Colour: " << motorcycle.colour << "\n"
        << "Engine power: " << motorcycle.enginePowerHp << "Hp\n"
        << "Cylinders: " << motorcycle.numCylinders << "\n"
        << "Speed: " << motorcycle.speedKph << "km/h\n"
        << "--- ";
    motorcycle.accelerate(30); 
    std::cout 
        << "--- "
        << (motorcycle.makeWheelie() ? "Wheelieeeee!" : "Try again ;)") << "\n"
        << "--- ";
    motorcycle.decelerate(20);
    std::cout 
        << std::endl;  
    
    Stereo stereo;
    std::cout
        << "*** Turntable:\n"
        << "PlatterRPM: " << stereo.turntable.platterRpm << "\n"
        << "Tonearm counterweight: " << stereo.turntable.tonearmCounterweightGrams << "g\n"
        << "Motor voltage: " << stereo.turntable.motorVoltageVolts << "V\n"
        << "Stylus movement: " << stereo.turntable.stylusMovementMicrometers << "μm\n"
        << std::setprecision(0)
        << "Speed selection: " << stereo.turntable.speedSelection << "rpm\n"
        << std::setprecision(2)
        << "--- ";
    stereo.turntable.changeSpeedSelection(true);
    stereo.turntable.regulateSpeed();
    std::cout << "--- ";
    stereo.turntable.changeSpeedSelection(false);
    stereo.turntable.regulateSpeed();
    std::cout
        << "--- "
        << "Groove amplitude: " << stereo.turntable.grooveAmplitude() << "\n"
        << "*** Cassette deck:\n"
        << (stereo.cassetteDeck.isCompartmentOpen ? "Open" : "Closed") << "\n"
        << std::setprecision(2)
        << "Tape speed: " << stereo.cassetteDeck.tapeSpeedCmPerSecond << "cm/s\n"
        << "--- Rotating reel\n";
    stereo.cassetteDeck.rotateReel();
    std::cout
        << std::setprecision(3)
        << "Speed coefficient: " << stereo.cassetteDeck.speedCoefficient << "\n"
        << "Reel speed: " <<  stereo.cassetteDeck.reelSpeed << "rpm\n"
        << "Play head current: " << stereo.cassetteDeck.playHeadCurrentMilliAmps << "mA\n"
        << "Button pressed: " << stereo.cassetteDeck.controlButtonPressed << "\n"
        << "Counter: " << stereo.cassetteDeck.counter << "\n"
        << (stereo.cassetteDeck.isForward ? "Forward" : "Reverse") << "\n"
        << "--- ";
    stereo.cassetteDeck.reverseDirection();
    std::cout
        << (stereo.cassetteDeck.isForward ? "Forward" : "Reverse") << "\n"
        << "--- "
        << "Magnetic info: " << stereo.cassetteDeck.readMagneticInformation() << "\n"
        << "*** Amplifier:\n"
        << std::setprecision(1)
        << "Volume button: " << stereo.amplifier.volumeButtonValue << "\n"
        << "Max volume: " << stereo.amplifier.maxVolume << "\n"
        << "Input signal: " << stereo.amplifier.inputSignalVoltageVolts << "\n"
        << "Output to speakers: " << stereo.amplifier.speakerOutputVoltageVolts << "\n"
        << "Source: " << stereo.amplifier.sourceSelected << "\n"
        << "Equalizer: " << stereo.amplifier.equalizerPreset << "\n"
        << "--- "
        << "Sound output: " << stereo.amplifier.outputSound() << "\n"
        << "--- ";
    stereo.amplifier.changeSource("Cassette Deck");
    stereo.amplifier.changeVolume(true);
    std::cout 
        << "--- "
        << "New volume: " << stereo.amplifier.volumeButtonValue << "\n"
        << "*** Tuner:\n"
        << "Band: " << stereo.tuner.bandSelected << "\n"
        << "Turning knob rotation: " << stereo.tuner.tuningKnobAngleRadians << "rad\n"
        << "Preset: " << stereo.tuner.presetButtonPressed << "\n"
        << "Dial position: " << stereo.tuner.dialPositionMillimeters << "mm\n"
        << std::setprecision(3)
        << "Antenna signal: " << stereo.tuner.antennaSignalVoltageMillivolts << "mV\n"
        << std::setprecision(1)
        << "Tuning: " << stereo.tuner.tuning << "\n"
        << "--- ";
    stereo.tuner.lightUp();
    stereo.tuner.selectBand("AM");
    stereo.tuner.changeTuning(false);
    std::cout
        << "--- "
        << "New band: " << stereo.tuner.bandSelected << "\n"
        << "--- "
        << "New tuning: " << stereo.tuner.tuning << "\n"
        << "*** Speaker 1:\n"
        << std::setprecision(2)
        << "Bass driver: " << stereo.speaker1.bassDriverVoltageVolts << "V\n"
        << "Treeble driver: " << stereo.speaker1.treebleDriverVoltageVolts << "V\n"
        << "Bass cone displacement: " << stereo.speaker1.bassConeDisplacementMillimeters << "mm\n"
         << "Treeble cone displacement: " << stereo.speaker1.treebleConeDisplacementMillimeters << "mm\n"
        << "Vent exhaust: " << stereo.speaker1.ventExhaustOverPressurePa << "Pa\n"
        << "Max current: " << stereo.speaker1.maxCurrent << "A\n"
        << std::setprecision(6)
        << "--- "
        << "Processed signal: " << stereo.speaker1.processSignal(0.2345f) << "\n"
        << "--- "
        << "Sound emitted: " << stereo.speaker1.emitSound(0.21456f) << "\n"
        << "--- "
        << "Speaker blown: " << (stereo.speaker1.blow(1.4392f) ? "Yes :(" : "No") << "\n"
        << "*** Stereo:\n"
        << "--- "
        << "Playing music on tuner: " << (stereo.playMusic("Tuner") ? "Yes" : "No") << "\n"
        << "--- ";
    stereo.changeRadioChannel("WNYC", true);
    std::cout 
        << "--- "
        << "Recording tape: " << (stereo.recordTape() ? "Yes" : "No") << "\n";

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}
