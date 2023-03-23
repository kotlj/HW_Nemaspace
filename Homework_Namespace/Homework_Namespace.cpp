
#include <iostream>

namespace engine
{
    class EngineInfo
    {
    private:
        char* model = nullptr;
        int displacement = 0;
        float power = 0.0;
        char* fuel_type = nullptr;
        char* manufacturer = nullptr;
    public:
        EngineInfo()
        {
            model = nullptr;
            displacement = 0;
            power = 0;
            fuel_type = nullptr;
            manufacturer = nullptr;
        }
        EngineInfo(const char* _model, int _displacement, float _power, const char* _fuel_type, const char* _manufacturer)
        {
            this->copyStr(model, _model);
            displacement = _displacement;
            power = _power;
            this->copyStr(fuel_type, _fuel_type);
            this->copyStr(manufacturer, _manufacturer);
        }

        void copyStr(char* &copyIn,const char* copyFrom)
        {
            if (copyIn != nullptr)
            {
                delete[] copyIn;
            }
            copyIn = new char[strlen(copyFrom)  + 1];
            copyIn[strlen(copyFrom)] = '\0';
            for (int i = 0; i < strlen(copyFrom); i++)
            {
                copyIn[i] = copyFrom[i];
            }
        }

        char* getModel()
        {
            return model;
        }
        int getDisplacement()
        {
            return displacement;
        }
        float getPower()
        {
            return power;
        }
        char* getFuelt_type()
        {
            return fuel_type;
        }
        char* getManufacturer()
        {
            return manufacturer;
        }

        virtual ~EngineInfo()
        {
            if (this->model != nullptr)
            {
                delete[] model;
            }
            if (this->fuel_type != nullptr)
            {
                delete[] fuel_type;
            }
            if (this->manufacturer != nullptr)
            {
                delete[] manufacturer;
            }
        }
    };

    void printEngineInfo(EngineInfo &obj)
    {
        std::cout << "Model: " << obj.getModel() << "\nDisplacement: " << obj.getDisplacement() << "cm^3\nPower: " << obj.getPower()
            << "H.p.\nFuel type: " << obj.getFuelt_type() << "\nManufacturer: " << obj.getManufacturer() << '\n';
    }
}


int main()
{
    engine::EngineInfo test1("Model_1", 10, 10, "Disel", "LG");
    engine::EngineInfo test2("Model_2", 20, 20, "NotDisel", "GL");
    engine::EngineInfo test3("Model_3", 30, 30, "Lesid", "LGGL");
    engine::printEngineInfo(test1);
    engine::printEngineInfo(test2);
    engine::printEngineInfo(test3);
}
