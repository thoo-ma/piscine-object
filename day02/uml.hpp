#include <vector>

/// @todo SINGLETON

/// @note Doxyfile settings modified
/// EXTRACT_ALL            = YES
/// EXTRACT_PRIVATE        = YES
/// HAVE_DOT               = YES
/// UML_LOOK               = YES
/// CALL_GRAPH             = YES
/// CALLER_GRAPH           = YES
/// DOT_UML_DETAILS        = YES

class ExplosionChamber;

/// @note subject ask for virtual class but we made it abstract
class LinkablePart {
    virtual void execute(float p_pression) = 0;
};

class Injector : LinkablePart {
    private:
    ExplosionChamber * explosionChamber;
    public:
    void execute(float p_pressiobn) {};
};

class Wheel {
    public:
    void executeRotation(float p_force) {};
};

class Transmission {
    std::vector<Wheel *> wheels;
    void activate(float p_force) {};
};

class Crankshaft {
    Transmission * transmission;
    void receiveForce(float p_volume) {};
};

class ExplosionChamber {
    Crankshaft * crankshaft;
    void fill(float p_volume) {};
};

class Motor {
    Injector injector;
    ExplosionChamber explosionChamber;
    Crankshaft crankshaft;
    void connectToTransmission(Transmission * p_transmission) {};
};

class Pedal {
    LinkablePart * linkablePart;
    void setTarget(LinkablePart * p_part) {};
    void use(float p_pression) {};
};

class Direction {
    Wheel wheels[4]; /// four-wheel drive baby
    void turn(float p_angle) {};
};

class DAE {
    float force;
    Direction * direction;
    void use(float p_angle) {};
};

class SteerWheel {
    DAE * dae;
    void turn(float p_angle) {};
};

class Brake {
    Wheel * wheel;
    void execute(float p_force) {};
    void attackWheel(Wheel* p_wheel) {};
};

class BrakeController: LinkablePart {
    Brake brakes[2]; /// front and back wheels
    void execute(float p_pression) {};
};

class Electronics {
    DAE dae;
};

template <class T>
class Singleton {
    public:
    static T & getInstance() {
        static T instance;
        return instance;
    }
    private:
    Singleton() {}
    // ~Singleton() {}
    Singleton(const Singleton &) {};
    Singleton & operator=(const Singleton) {};
};

class Gear {
    int demultiplier;
};

class GearLever: Singleton<GearLever> {
    public:
    Gear gears[8]; /// just like F1 baby
    int level;
    void change() {};
    Gear * activeGear() { return &gears[level]; }
    private:
    GearLever();
};

/// @note subject ask for 'methods that manage these objects'
class Cockpit {
    public:
    Pedal pedal;
    SteerWheel steerWheel;
    GearLever gearLever;
};

class Car {
    public:
    Transmission transaction;
    Motor motor;
    Electronics electronics;
    Cockpit cockpit;
    Direction direction;
    BrakeController brakeController;
};
