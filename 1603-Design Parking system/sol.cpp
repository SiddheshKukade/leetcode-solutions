class ParkingSystem {
public:
    int big;
    int medium ;
     int small;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;

    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(this-> big== 0)
                return false;
            this->big = this->big -1;
        }else    if(carType == 2){
            if(this->medium == 0)
                return false;
            this->medium = this->medium -1;
        }else if(carType ==3 ){
            if(this->small == 0)
                return false;
            this->small = this->small -1;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
