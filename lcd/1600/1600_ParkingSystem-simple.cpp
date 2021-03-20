//
// Created by nanji on 3/19/21.
//

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->_big = big;
        this->_medium = medium;
        this->_small = small;
    }

    bool addCar(int carType) {
        if (carType ==1 && this->_big > 0) {
            this->_big--;
            return true;
        } else if (carType == 2 && this->_medium > 0) {
            this->_medium--;
            return true;
        } else if (carType == 3 && this->_small > 0) {
            this->_small--;
            return true;
        }
        return false;
    }

private:
    int _big, _medium, _small;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */