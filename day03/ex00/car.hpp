
// volant : tourner les roues
// boite de vitesses : passer les vitesses
// moteur : accelerer
class Car {

    private:

    int _speed = 0;
    int _current_gear = 0;
    int const _gear_min = 0;
    int const _gear_max = 6;
    int const _brake_force_max = 42;

    public:

    void start() {
        _current_gear = 1;
        accelerate(10); // arbitrary value
    }

    void stop() {
        _speed = 0;
        _current_gear = 0;
    }

    void accelerate(int speed) {
        if (speed > _speed)
            _speed = speed;
    }

    void shift_gears_up() {
        if (_current_gear < _gear_max)
            _current_gear++;
    }

    void shift_gears_down() {
        if (_current_gear > _gear_min)
            _current_gear--;
    }

    void reverse();

    void turn_wheels(int angle);

    void straighten_wheels();

    void apply_force_on_brakes(int force);

    void apply_energency_brakes() {
        return apply_force_on_brakes(_brake_force_max);
    }
};