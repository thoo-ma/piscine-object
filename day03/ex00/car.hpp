class Brake {

    private:

    int const _brake_force_max = 42;
    int _current_brake_force = 0;

    public:

    void apply_force_on_brakes(int force) {
        _current_brake_force = force;
    }

    void apply_energency_brakes() {
        return apply_force_on_brakes(_brake_force_max);
    }
};

class Engine {

    public:

    void start() {
        // _current_gear = 1;
        // accelerate(10); // arbitrary value
    }

    void stop() {
        // _speed = 0;
        // _current_gear = 0;
    }

};

class Gearbox {

    private:

    int _current_gear = 0;
    int const _gear_min = 0;
    int const _gear_max = 6;

    public:

    void shift_gears_up() {
        if (_current_gear < _gear_max)
            _current_gear++;
    }

    void shift_gears_down() {
        if (_current_gear > _gear_min)
            _current_gear--;
    }

    void reverse() {
        _current_gear = -1;
    }

};

class Wheel {

    private:

    int _angle_range = 90; // degrees
    int _angle_min = _angle_range / 2 * -1;
    int _angle_max = _angle_range / 2;
    int _current_angle = 0;

    public:

    void turn_wheels(int angle) {
        int res = _current_angle += angle;
        if (res > _angle_max)
            _current_angle = _angle_max;
        else if (res < _angle_min)
            _current_angle = _angle_min;
        else
            _current_angle = res;
    }

    void straighten_wheels() {
        _current_angle = 0;
    }

};

class Car {

    private:

    Engine _engine;
    Brake _brake[4];
    Wheel _wheels[4];
    Gearbox _gearbox;

    int _speed = 0;

    public:

    void accelerate(int speed) {
        if (speed > _speed)
            _speed = speed;
    }

};