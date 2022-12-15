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


struct Cat
{
    // number of limbs
    int numLimbs = 3;
    // number of tails    
    int numTails = 1;
    // age
    float ageYears = 3.6f;
    // colour
    std::string colour = "orange";
    // weight
    float weightKg = 4.1f;

    // 3 things it can do:
    // meow
    void meow(float loudnessDB);

    // catch small animals
    bool catchAnimal(std::string animalSpecies); // returns true if the animal is caught

    // throw up fur balls
    float throwUpFurBall(); // returns the size of the fur ball in mm
};


struct VendingMachine
{
    // inventory
    int inventory = 42;
    // interior temperature
    float interiorTemperatureCelsius = 10.2f;
    // target temperature
    float targetTemperatureCelsius = 8.5f;
    // cash collected
    float cashCollectedEuros = 123.54f;
    // item selected
    int itemSelected = 13;

    struct ItemDispenser
    {
        std::string name = "KitKat";
        std::string flavour = "Original";
        int inventory = 5;
        float priceEuros = 2.5f;
        int itemNumber = 13;

        bool distributeItems(int numberOfItems); // returns true if item successfully distributed

        int updateInventory(int itemAdded); // returns the new inventory

        bool disable(std::string cause); // return true if the dispenser is disabled
    };

    // 3 things it can do:
    // charge customer for an item
    float chargeCustomerEuros(int item); // returns the price for the item

    // dispense item
    bool dispenseItem(ItemDispenser itemDispenser, int numberOfItems); // returns true if the items are sucessfully dispensed

    // refrigerate at a given temperature
    void refrigerate(float temperature);
};

struct Computer
{
    // number of CPU cores
    int numCPUCores = 6;
    // CPU frequency in GHz
    float CPUFrequencyGHz = 3.4f;
    // memory size
    int memoryMB = 32;
    // power needed to run the computer
    int powerNeededW = 430;
    // operating system
    std::string operatingSystem = "Solaris";

    struct Drive 
    {
        std::string brand = "Seagate";
        float capacityGB = 2000.0f;
        int standardRpm = 7200;
        float readSpeedMBs = 101.1f;
        float writeSpeedMs = 74.2f;

        int readData(int address); // returns the value at that address
        
        bool writeData(int address, int data); // return true if the write succeeded

        bool parkHeads(); // return true if the heads are parked
    };

    // 3 things it can do:
    // boot up
    bool bootUp(Drive systemDrive); // returns true if the boot is successful

    // run an program on given path
    bool runProgram(Drive programDrive, std::string path); // returns true if the program is started successfully

    // crash
    void crash();    
};

struct Motorcycle
{
    // brand
    std::string brand = "Harley Davidson";
    // model
    std::string model = "2022 Heritage Classic";
    // colour
    std::string colour = "Pink";
    // engine power in hp
    int enginePowerHp = 101;
    // number of cylinders
    int numCylinders = 2;

    // 3 things it can do:
    // accelerate
    float accelerate(float acceleration); // returns new speed

    // break (decelerate)
    float decelerate(float deceleration); // returns new speed

    // make a wheelie
    bool makeWheelie(); // returns true if the front wheel takes off the ground
};

struct Turntable
{
    // platter rotation speed
    float platterRpm = 32.9f;
    // tonearm counterweight
    float tonearmCounterweightGrams = 160.0f;
    // motor voltage
    double motorVoltageVolts = 9.2345;
    // stylus movement amplitude
    float stylusMovementMicrometers = 2.5f;
    // speed selection
    int speedSelection = 33;

    // 3 things it can do:
    // change rotating speed
    float changeRotatingSpeed(bool isIncreased); // returns the new rotating speed

    // rotate vinyl disk
    float rotateDisk(float targetSpeed); // returns the rotating speed

    // output groove amplitude
    float grooveAmplitude(); // returns the current groove amplitude
};

struct CassetteDeck
{
    // cassette compartment open
    bool isCompartmentOpen = false;
    // tape speed
    float tapeSpeedCmPerSecond = 4.76f;
    // current at the play head
    double playHeadCurrentMilliAmps = 0.83;
    // control button pressed
    std::string controlButtonPressed = "Play";
    // counter value
    int counter = 354;

    // 3 things it can do:
    // read magnetic information 
    double readMagneticInformation(); // returns a current value in mA

    // rotate reel
    bool rotateReel(bool isForward); // returns true if the reel rotates

    // reverse direction
    bool reverseDirection(); // returns true if the direction can be reversed
};

struct Amplifier
{
    // volume button value
    float volumeButtonValue = 11.1f;
    // input signal voltage
    double inputSignalVoltageVolts = 0.0;
    // speaker output voltage
    double speakerOutputVoltageVolts = 0.0;
    // source selected
    std::string sourceSelected = "turntable";
    // equalizer preset
    std::string equalizerPreset = "jazz";

    // 3 things it can do:
    // change volume
    float changeVolume(bool up); // returns new volume
    // output sound
    float outputSound(float volume); // returns a signal voltage
    // change source
    bool changeSource(std::string newSource); // returns true if the change is successful
};

struct Tuner
{
    // band selected
    std::string bandSelected = "FM";
    // tuning know angle
    float tuningKnobAngleRadians = 1.234f;
    // preset button pressed
    std::string presetButtonPressed = "none";
    // dial position
    float dialPositionMillimeters = 15.3f;
    // antenna signal voltage
    double antennaSignalVoltageMillivolts = 0.132;
    
    // 3 things it can do:
    // select band
    bool selectBand(std::string newBand); // returns true if the selection is successful

    // change tuning
    float changeTuning(bool up); // returns the new tuning knob rotation angle

    // light up
    bool lightUp(); // returns true if the light is on
};

struct Speaker
{
    // bass driver voltage
    double bassDriverVoltageVolts = 31.43;
    // bass cone displacement
    float bassConeDisplacementMillimeters = 2.3f;
    // treeble driver voltage
    double treebleDriverVoltageVolts = 30.56;
    // treeble cone displacement
    float treebleConeDisplacementMillimeters = 0.4f;
    // vent exhaust pressure
    float ventExhaustOverPressurePa = 45.121f;

    // 3 things it can do:
    // process signal
    float processSignal(float inputSignal); // returns a driver current 
  
    // emit sound
    void emitSound(float driverCurrent);
    
    // blow
    void blow(float driverCurrent);
};

struct Stereo
{
    // turntable
    Turntable turntable;
    // cassette deck
    CassetteDeck cassetteDeck;
    // amplifier
    Amplifier amplifier;
    // tuner
    Tuner tuner;
    // speakers
    Speaker speaker1, speaker2;

    // 3 things it can do:
    // play music
    bool playMusic(std::string source); // returns true if music can be played from source

    // change radio channel
    bool changeRadioChannel(std::string newRadioChannel); // returns true if change is successful

    // record tape
    bool recordTape(std::string inputSource); // returns true if the source can be recorded
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
