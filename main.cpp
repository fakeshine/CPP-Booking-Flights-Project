
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
#include <limits>
#include <vector>
#include <fstream>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;

// This is an abstract class

class Users
{
    public:

    void searchFlights(json& jsonArray , std::string stringToBeFound);
    void searchFlights(json& jsonArray , int uidToBeFound , json& bookedFlights);

    // Getters

    string getUserFirstName();
    string getUserLastName();
    string getUserType();
    string getUserNameLogin();
    string getUserPassword();
    int    getUserUID();
    
    // Setters

    void setUserFirstName(string userFirstNameInput);
    void setUserLastName(string userLastNameInput);
    void setUserType(string userTypeInput);
    void setUserNameLogin(string userNameLoginInput);
    void setUserPassword(string userPasswordInput);
    void setUserUID(int userUIDInput);

    // Constructor + Destructor

    Users()
    {
        std::cout << "A Users object has been created" << std::endl;
    }

    ~Users()
    {
        std::cout << "A Users object has been deleted" << std::endl;
    }
   
    protected:
    
    string userFirstName;
    string userLastName;
    string userType;
    string userNameLogin;
    string userPassword;
    string userMail;
    int userUID;
    

    virtual void login() = 0;   
};

void Users::searchFlights(json& jsonArray , std::string stringToBeFound)
{
    try
    {
        auto res = std::find_if(jsonArray.begin() , jsonArray.end() , [&](const json& i)
        {
            auto it = i.find("destinationTown");
            if(it == i["destinationTown"].end()) throw "There are no flights in the databse with the destination town you are looking for";
            return it != i.end() && it.value() == stringToBeFound;
            
        });

        std::cout << *res << std::endl;
    }
    catch(char const *msg)
    {
        std::cout << msg << std::endl;
    }
}

void Users::searchFlights(json& jsonArray , int uidToBeFound , json& bookedFlights)
{
    try
    {
        auto res = std::find_if(jsonArray.begin() , jsonArray.end() , [&](const json& i)
        {
            auto it = i.find("flightUID");
            if(it == i["flightUID"].end()) throw "There are no flights in the databse with the UID you are looking for";
            return it != i.end() && it.value() == uidToBeFound;
        });
        bookedFlights.push_back(json::object(*res));
        std::cout << *res << std::endl;
    }
    catch(char const *msg)
    {
         std::cout << msg << std::endl;
         this->searchFlights(jsonArray , uidToBeFound , bookedFlights);
    }
    
    
}

// Getters

string Users::getUserFirstName()
{
    return this->userFirstName;
}

string Users::getUserLastName()
{
    return this->userLastName;
}

string Users::getUserType()
{
    return this->userType;
}

string Users::getUserNameLogin()
{
    return this->userNameLogin;
}

string Users::getUserPassword()
{
    return this->userPassword;
}

int Users::getUserUID()
{
    return this->userUID;
}

// Setters

void Users::setUserFirstName(string userFirstNameInput)
{
    this->userFirstName = userFirstNameInput;
}

void Users::setUserLastName(string userLastNameInput)
{
    this->userLastName = userLastNameInput;
}

void Users::setUserType(string userTypeInput)
{
    this->userType = userTypeInput;
}

void Users::setUserNameLogin(string userNameLoginInput)
{
    this->userNameLogin = userNameLoginInput;
}

void Users::setUserPassword(string userPasswordInput)
{
    this->userPassword = userPasswordInput;
}

void Users::setUserUID(int userUIDInput)
{
    this->userUID = userUIDInput;
}

class Flights
{
    private :

    static int contorFlights;

    int    createdAtSec;
    int    createdAtMin;
    int    createdAtHour;
    int    createdAtMonthDay;
    int    createdAtMonth;
    int    createdAtYear;
    int    createdAtWeekDay;
    int    createdAtYearDay;
    int    createdAtHoursDaylightSavingsTime;
    float  flightPrice;

    string sourceTown;
    string destinationTown;
    int    totalSeats;
    int    availableSeats;   
    int    flightUID; 

    int    takeOffYear;
    int    takeOffMonth;
    int    takeOffDay;
    int    takeOffHour;
    int    takeOffSec;
    int    takeOffMin;

    int    landingYear;
    int    landingMonth;
    int    landingDay;
    int    landingHour;
    int    landingSec;
    int    landingMin;
    
    public:

    Flights()
    {
        // current date/time based on current system
        time_t now = time(0);
        tm *gmtm = gmtime(&now);
        char *dt = ctime(&now);

        std::cout << "A Flights object has been created at the local date and time \n: " << dt << std::endl;

        formatCreateObjectTime(gmtm);

        this->createdAtSec = gmtm->tm_sec;
        this->createdAtMin = gmtm->tm_min;
        this->createdAtMonthDay = gmtm->tm_mday;
        this->createdAtWeekDay = gmtm->tm_wday;
        this->createdAtYearDay = gmtm->tm_yday;
        this->createdAtHoursDaylightSavingsTime = gmtm->tm_isdst;
        this->flightUID = contorFlights;
        contorFlights++;        
    }

    void formatCreateObjectTime(tm *createObjStruct);

    void addFlight();

    // Getters

    // TO DO : getters and setters for createdAt  , takeOff , landing

    string getSourceTown();
    string getDestinationTown();
    int getTotalSeats();
    int getAvailableSeats();
    int getCreatedAtSec();
    int getCreatedAtMin();
    int getCreatedAtHour();
    int getCreatedAtMonthDay();
    int getCreatedAtMonth();
    int getCreatedAtYear();
    int getCreatedAtWeekDay();
    int getCreatedAtYearDay();
    int getCreatedAtHoursDaylightSavingsTime();
    float getFlightPrice();
    int getFlightUID();

    int getTakeOffYear();
    int getTakeOffMonth();
    int getTakeOffDay();
    int getTakeOffHour();
    int getTakeOffMin();
    int getTakeOffSec();

    int getLandingYear();
    int getLandingMonth();
    int getLandingDay();
    int getLandingHour();
    int getLandingMin();
    int getLandingSec();

    // Setters

    void setSourceTown(string sourceTownInput);
    void setDestinationTown(string destinationTownInput);
    void setTotalSeats(int totalSeatsInput);
    
    void setTakeOffYear(int takeOffYearInput);
    void setTakeOffMonth(int takeOffMonthInput);
    void setTakeOffDay(int takeOffDayInput);
    void setTakeOffHour(int takeOffHourInput);
    void setTakeOffMin(int takeOffMinInput);
    void setTakeOffSec(int takeOffSecInput);
    void setLandingYear(int landingYearInput);
    void setLandingMonth(int landingMonthInput);
    void setLandingDay(int landingDayInput);
    void setLandingHour(int landingHourInput);
    void setLandingMin(int landingMinInput);
    void setlandingSec(int landingSecInput);
    
    void setFlightPrice(float flightPriceInput);
};

int Flights::contorFlights = 0;

void Flights::formatCreateObjectTime(tm *createObjStruct)
{
    this->createdAtYear = 1900 + createObjStruct->tm_year;
    this->createdAtHour = 2 + createObjStruct->tm_hour;
    this->createdAtMonth = 1 + createObjStruct->tm_mon;
}

void Flights::addFlight()
{
    string sourceTownInput , destinationTownInput;
    bool isLeapYear = false;
    std::string forbiddenChars = "~`!@#$%^&*()_+=-<>/?.,;:\'\"[]{}|\\1234567890";

    std::cout << "Source Town: "; std::cin >> sourceTownInput;
    size_t specialSrc = sourceTownInput.find_first_of(forbiddenChars);
    if((specialSrc != string::npos)) throw "Name of towns can only take letters";

    std::cout << "Destination Town: "; std::cin >> destinationTownInput;
    size_t specialDest = destinationTownInput.find_first_of(forbiddenChars);
    if((specialDest != string::npos)) throw "Name of towns can only take letters";

    setSourceTown(sourceTownInput);
    setDestinationTown(destinationTownInput);
    std::cout << "Complete the details of the flight from " << sourceTownInput << " to " << destinationTownInput << " : " << std::endl;
    
    try
    {
        std::cout << "Takeoff Year : "; std::cin >> this->takeOffYear;
        if(this->takeOffYear < this->createdAtYear) throw "Date in the past (year)";
        if(this->takeOffYear > 9999) throw "Wrong input year";
        std::cout << "Takeoff Month : "; std::cin >> this->takeOffMonth;
        if(this->takeOffMonth < this->createdAtMonth) throw "Date in the past (month)";
        if((this->takeOffMonth > 12) || (this->takeOffMonth < 1)) throw "Months can only take integers from 1 to 12";
        std::cout << "Takeoff Day : "; std::cin >> this->takeOffDay;
        if(this->takeOffDay < this->createdAtMonthDay) throw "Date in the past (day)";
        if((this->takeOffDay > 31) || (this->takeOffDay < 1)) throw "Days can only take integers from 1 to 31";
        if((this->takeOffMonth == 2) && (this->takeOffDay > 29)) throw "February cannnot have more than 29 days";
        if(this->takeOffMonth == 2)
        {
            if(this->takeOffYear % 4 == 0)
                if(this->takeOffYear % 100 == 0)
                    if(this->takeOffYear % 400 == 0)
                    {
                        isLeapYear = true;
                    }
        }
        if((isLeapYear == false) && (this->takeOffDay > 28)) throw "This year is not a leap year. February cannot have more than 28 days";

        std::cout << "Takeoff Hour : "; std::cin >> this->takeOffHour;
        if((this->takeOffHour > 24) || (this->takeOffMonth < 0)) throw "Hours can only take integers from 0 to 24";
        std::cout << "Takeoff Minutes : "; std::cin >> this->takeOffMin;
        if((this->takeOffMin > 59) || (this->takeOffMin < 0)) throw "Minutes can only take integers from 0 to 59";
        std::cout << "Takeoff Seconds : "; std::cin >> this->takeOffSec;
        if((this->takeOffSec > 59) || (this->takeOffSec < 0)) throw "Seconds can only take integers from 0 to 59";

        std::cout << "Flight Price : "; std::cin >> this->flightPrice;
        std::cout << "Total Seats : "; std::cin >> this->totalSeats;
        availableSeats = totalSeats;

        std::cout << "Landing Year : "; std::cin >> this->landingYear;
        if(this->landingYear < this->createdAtYear) throw "Date in the past (year)";
        if(this->landingYear > 9999) throw "Wrong input year";
        std::cout << "Landing Month : "; std::cin >> this->landingMonth;
        if(this->landingMonth < this->createdAtMonth) throw "Date in the past (month)";
        if((this->landingMonth > 12) || (this->landingMonth < 1)) throw "Months can only take integers from 1 to 12";
        std::cout << "Landing Day : "; std::cin >> this->landingDay;
        if(this->landingDay < this->createdAtMonthDay) throw "Date in the past (day)";
        if((this->landingDay > 31) || (this->landingDay < 1)) throw "Days can only take integers from 1 to 31";
        if((this->landingMonth == 2) && (this->landingDay > 29)) throw "February cannnot have more than 29 days";
        if(isLeapYear == true) isLeapYear = false;
        if(this->landingMonth == 2)
        {
            if(this->landingYear % 4 == 0)
                if(this->landingYear % 100 == 0)
                    if(this->landingYear % 400 == 0)
                    {
                        isLeapYear = true;
                    }
        }
        if((isLeapYear == false) && (this->landingDay > 28)) throw "This year is not a leap year. February cannot have more than 28 days";

        std::cout << "Landing Hour : "; std::cin >> this->landingHour;
        if((this->landingHour > 24) || (this->landingMonth < 0)) throw "Hours can only take integers from 0 to 24";
        std::cout << "Landing Minutes : "; std::cin >> this->landingMin;
        if((this->landingMin > 59) || (this->landingMin < 0)) throw "Minutes can only take integers from 0 to 59";
        std::cout << "Landing Seconds : "; std::cin >> this->landingSec;
        if((this->landingSec > 59) || (this->landingSec < 0)) throw "Seconds can only take integers from 0 to 59";

    }
    catch(char const *msg)
    {
        std::cout << msg << std::endl;
        this->addFlight();
    }
    
}

// Getters

string Flights::getSourceTown()
{
    return this->sourceTown;
}

string Flights::getDestinationTown()
{
    return this->destinationTown;
}

int Flights::getTotalSeats()
{
    return this->totalSeats;
}

int Flights::getAvailableSeats()
{
    return this->availableSeats;
}

int Flights::getCreatedAtSec()
{
    return this->createdAtSec;
}

int Flights::getCreatedAtMin()
{
    return this->createdAtMin;
}

int Flights::getCreatedAtHour()
{
    return this->createdAtHour;
}

int Flights::getCreatedAtMonthDay()
{
    return this->createdAtMonthDay;
}

int Flights::getCreatedAtMonth()
{
    return this->createdAtMonth;
}

int Flights::getCreatedAtYear()
{
    return this->createdAtYear;
}

int Flights::getCreatedAtWeekDay()
{
    return this->createdAtWeekDay;
}

int Flights::getCreatedAtYearDay()
{
    return this->createdAtYearDay;
}

int Flights::getCreatedAtHoursDaylightSavingsTime()
{
    return this->createdAtHoursDaylightSavingsTime;
}

int Flights::getTakeOffYear()
{
    return this->takeOffYear;
}

int Flights::getTakeOffMonth()
{
    return this->takeOffMonth;
}

int Flights::getTakeOffDay()
{
    return this->takeOffDay;
}

int Flights::getTakeOffHour()
{
    return this->takeOffHour;
}

int Flights::getTakeOffMin()
{
    return this->takeOffMin;
}

int Flights::getTakeOffSec()
{
    return this->takeOffSec;
}

int Flights::getLandingYear()
{
    return this->landingYear;
}

int Flights::getLandingMonth()
{
    return this->landingMonth;
}

int Flights::getLandingDay()
{
    return this->landingDay;
}

int Flights::getLandingHour()
{
    return this->landingHour;
}

int Flights::getLandingMin()
{
    return this->landingMin;
}

int Flights::getLandingSec()
{
    return this->landingSec;
}

float Flights::getFlightPrice()
{
    return this->flightPrice;
}

int Flights::getFlightUID()
{
    return this->flightUID;
}

// Setters

void Flights::setSourceTown(string sourceTownInput)
{
    this->sourceTown = sourceTownInput;
}

void Flights::setDestinationTown(string destinationTownInput)
{
    this->destinationTown = destinationTownInput;
}

void Flights::setTotalSeats(int totalSeatsInput)
{
    this->totalSeats = totalSeatsInput;
}

void Flights::setTakeOffYear(int takeOffYearInput)
{
    this->takeOffYear = takeOffYearInput;
}

void Flights::setTakeOffMonth(int takeOffMonthInput)
{
    this->takeOffMonth = takeOffMonthInput;
}

void Flights::setTakeOffDay(int takeOffDayInput)
{
    this->takeOffDay = takeOffDayInput;
}

void Flights::setTakeOffHour(int takeOffHourInput)
{
    this->takeOffHour = takeOffHourInput;
}

void Flights::setTakeOffMin(int takeOffMinInput)
{
    this->takeOffMin = takeOffMinInput;
}

void Flights::setTakeOffSec(int takeOffSecInput)
{
    this->takeOffSec = takeOffSecInput;
}

void Flights::setLandingYear(int landingYearInput)
{
    this->landingYear = landingYearInput;
}

void Flights::setLandingMonth(int landingMonthInput)
{
    this->landingMonth = landingMonthInput;
}

void Flights::setLandingDay(int landingDayInput)
{
    this->landingDay = landingDayInput;
}

void Flights::setLandingHour(int landingHourInput)
{
    this->landingHour = landingHourInput;
}

void Flights::setLandingMin(int landingMinInput)
{
    this->landingMin = landingMinInput;
}

void Flights::setlandingSec(int landingSecInput)
{
    this->landingSec = landingSecInput;
}

void Flights::setFlightPrice(float flightPriceInput)
{
    this->flightPrice = flightPriceInput;
}

// Clients class is inherited from Users class

class Clients : public Users
{
    private: 

    static int contorClient;

    map<string, string> clientsMap = {};

    public:

    Clients()
    {
        std::cout << "A Clients object has been created";
        this->userType = "Client";
        this->userUID = 100 + contorClient;
        contorClient++;
    }

    void createAccount();
    void login();
    bool checkStrongPassword(std::string &stringInput);
    
};

int Clients::contorClient = 0;

bool Clients::checkStrongPassword(std::string &stringInput)
{
    
    bool status = false;

    bool hasLower = false , hasUpper = false , hasDigit = false , hasSpecialChar = false;
    std::string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int n = stringInput.length();

    if(n < 8) return false;
    else
    {
        for(int i = 0 ; i < n ;  i++)
    {
        if(islower(stringInput[i]) && hasLower == false) hasLower = true;
        if(isupper(stringInput[i]) && hasUpper == false) hasUpper = true;
        if(isdigit(stringInput[i]) && hasDigit == false) hasDigit = true;

        size_t special = stringInput.find_first_not_of(normalChars);
        if((special != string::npos) && (hasSpecialChar = false)) hasSpecialChar = true;

        if((hasLower == true) && (hasUpper == true) && (hasDigit == true) && (hasSpecialChar == true))
        {
            status = true;
            break;
        }
    }

        return status;
    }

}

void Clients::createAccount()
{
    try
    {
        std::string passwordInput1 , passwordInput2;
        std::cout << "Username (NO SPACES) : "; std::cin >> this->userNameLogin;
        std::cout << "Password : "; std::cin >> passwordInput1;
        if(this->checkStrongPassword(passwordInput1) == false) throw "Password must be at least 8 characters long and contain at least one number, one special character and one capital letter";
        std::cout << "Confirm Password : "; std::cin >> passwordInput2;
        if(passwordInput1 != passwordInput2) throw "Password confirmed incorrectly!";
        else setUserPassword(passwordInput1);

        RSA *rsa = new RSA();

        // Check if the username is already taken
        if(clientsMap.count(this->userNameLogin) == 0)
        {
            clientsMap.insert({this->userNameLogin , rsa->encryptPassword(userPassword)});
            std::cout << "Account has been created!" << std::endl;
        }
        else
        {
            throw "Username already taken";
        }

        delete rsa;
    }
    
    catch(char const *msg)
    {
        std::cout << msg << std::endl;
        this->createAccount();
    }
        
}

void Clients::login()
{
    std::cout << "Username (NO SPACES) :"; std::cin >> this->userNameLogin;
    std::cout << "Password :"; std::cin >> this->userPassword;

    RSA* rsa = new RSA();

    // Check if username exists in the map or not
    try 
    {
        if(clientsMap.count(this->userNameLogin) != 0)
        {
            // If it exists, compare the input password with the mapped password

            if(clientsMap[this->userNameLogin] == rsa->encryptPassword(this->userPassword)) throw "Logged In!";
            else throw "Wrong Password!";
        }
        else
        {
            throw "Sign up with this username firsly!";
        }

        delete rsa;
    }
    catch (char const *msg)
    {
        std::cout << msg << std::endl;
    }
}

// Admins class is inherited from Users class

class Admins : public Users
{    
    public :

    Admins();
    ~Admins();
    void login();
    void addFlightInJson(json flightObject , json flightsJson);
    void deleteFlightWithUID(json& jsonArray, int& value);
};

Admins::Admins()
{
    std::cout << "An Admins object has been created" << std::endl;
        this->userType = "Admin";
        this->userUID = 200;
        this->userNameLogin = "admin";
        this->userPassword = "admin";
        this->userFirstName = "Necunoscut";
        this->userLastName = "Necunoscut";
        this->userMail = "company_ name@company.com"; 
}

Admins::~Admins()
{
    std::cout << "An Admins object has been deleted" << std::endl;
}

void Admins::deleteFlightWithUID(json& jsonArray, int& value)
{
    for (auto &it : jsonArray.items())
    {
        int ctr = 1;
        if (it.value().at("flightUID").get<int>() == value)
            jsonArray.erase(jsonArray.begin() + ctr , jsonArray.begin() + ctr + 1);
        ctr++;
    }
}

void Admins::addFlightInJson(json flightObject , json flightsJson)
{
    Flights newFlight;
    newFlight.addFlight();
    addInJsonFlightObj(flightObject , newFlight);
    flightsJson.push_back(json::object(flightObject));
}

void Admins :: login()
{
    string auxUsername , auxPassword;
    std::cout << "Username (NO SPACES) :"; std::cin >> auxUsername;
    std::cout << "Password :"; std::cin >> auxPassword;

    if(this->userNameLogin == auxUsername)
    {
        if(this->userPassword == auxPassword)
        {
            std::cout << "Logged In!" << std::endl;
        }
        else 
        {
            std::cout << "Wrong Password!" << std::endl;
        }
    }
    else
    {
        std::cout << "This Admin user does not exist!" << std::endl;
    }

}

class RSA
{

    private:

    int p , q , n , totient , d , e;

    public:

    RSA();

    ~RSA()
    {
        std::cout << "An RSA object has been deleted" << std::endl;
    }

    int gcd(int number1 , int number2);
    int encrypt(int m);
    int decrypt(int c);


    /*
    We will encrypt and decrypt the passwords of the users char by char because RSA algorithm
    takes numbers as input a number, thus each char will be read as its ASCII code
    */
    std::string encryptPassword(std::string passwordInput);
    std::string decryptPassword(std::string passwordInput);
};

RSA::RSA()
{
    std::cout << "An RSA object has been created" << std::endl;

    this->e = 7;
    this->p = 2081;
    this->q = 3313;
    this->n = p*q;
    this->totient = (this->p - 1)*(this->q-1);
    for(this->e ; this->e < this->totient ; this->e++)
    {
        if(this->gcd(this->e , this->totient) == 1)
            break;
        else e++;
    }

    srand(time(NULL));
    double k = rand() % 1000 + 1;
    this->d = (1 + (k*this->totient)) / this->e;
}

int RSA::encrypt(int m)
{
    return customPow(m , this->e , this->n);
}

int RSA::decrypt(int c)
{
    return customPow(c , this->d , this->n);
}

int RSA::gcd(int number1 , int number2)
{
    if(number2 == 0) return number1;
    return gcd(number2 , number1 % number2);
}

int customPow(int x , int y , int n) // Computes x**y % n
{
    int res = 1;
    for(; y ; y--)
        res = (res * x) % n;
    return res;
}

std::string RSA::encryptPassword(std::string passwordInput)
{
    std::string encryptedPassword = "";
    for(char c : passwordInput)
    {
        char encryptedChar = this->encrypt(c);
        encryptedPassword += encryptedChar;
    }
    return encryptedPassword;
}

std::string RSA::decryptPassword(std::string passwordInput)
{
    std::string decryptedPassword = "";
    for(char c : passwordInput)
    {
        char decryptedChar = this->decrypt(c);
        decryptedPassword += decryptedChar;
    }
    return decryptedPassword;
}

int main()
{
    Clients client1;
    Admins admin;
    int choice;

    auto flightsJson = json::array();
    json flightObject;
    auto bookedFlightsJson = json::array();
    

    int inputFlightUID;
    string destinationTownInput;

    int k = 0;
    int contorBookedFlights = 0;
    // .json Output File

    std::ofstream flightsOutputFile("flights.json");
    std::ofstream bookedFlightsOutputFile("booked_flights.json");
    
    // Runs as long as the user does not quit by pressing 3.
    do
    {
        // Firstly, choose the type of user you want to authenticate with

        std::cout << "1.Client" << std::endl << "2.Admin" << std::endl << "ANYTIME PRESS 10 FOR CLOSING APP" << std::endl;
        std::cout << "CHOOSE FROM THE SELECTION MENU :" << std::endl;
        choice = validateChoice();

        switch (choice)
        {
        /**********/
        case 1:
            std::cout << "Hello, Client!" << std::endl;

            std::cout << "1. Login " << std::endl << "2. Sign Up " << std::endl << "3. Quit " << std::endl;
            std::cout << "CHOOSE FROM THE SELECTION MENU: " << std::endl;
            choice = validateChoice();
        /**********/

            switch (choice)
            {
            /**********/    
            case 1:
                client1.login();
                //TO DO - functionalitatiile clientului
                std::cout << client1.getUserNameLogin() << " has been logged in" << std::endl;
                std::cout << "1. Search Flight" << std::endl << "2. Book Flight" << std::endl << "3. Quit " << std::endl;
                choice = validateChoice();
            /**********/   
               
                switch (choice)
                {
                /**********/   
                case 1:
                    std::cout << "Type the name of the destination town you are interested in:" << std::endl; std::cin >> destinationTownInput;
                    client1.searchFlights(flightsJson , destinationTownInput);
                    break;
                /**********/
                case 2:
                    std::cout << "Type the name of the destination town you are interested in:" << std::endl; std::cin >> destinationTownInput;
                    client1.searchFlights(flightsJson , destinationTownInput);
                    cout << "Type the UID of the flight you want to book :" << std::endl; std::cin >> inputFlightUID;
                    client1.searchFlights(flightsJson , inputFlightUID , bookedFlightsJson);
                    /*if(contorBookedFlights == 0) 
                        {
                            change_key(bookedFlightsJson , "" , "BookedFlight");
                            contorBookedFlights++;
                        }*/
                        // TO DO : availableSeats -= 1 when a flight is booked
                    break;
                /**********/
                default:
                    break;
                }
                break;
            /**********/
            case 2:
                client1.createAccount();
                break;
            /**********/
            case 3:
                std::cout << "Goodbye!" << std::endl;
                break;
            /**********/
            default:
                break;
            /**********/
            }
            break;
            /**********/
        /**********/
        case 2:
            std::cout << "Hello, Admin!" << std::endl;

            std::cout << "1. Login " << std::endl << "2. Quit " << std::endl;
            std::cout << "CHOOSE FROM THE SELECTION MENU: " << std::endl;
            choice = validateChoice();
        /**********/
            switch (choice)
            {
            /**********/
            case 1:
                admin.login();
                std::cout << "Admin has been logged in" << std::endl;
                std::cout << "1. Add Flight" << std::endl << "2. Delete Flight" << std::endl << "3. Search Flight " << std::endl << "4. Quit " << std::endl;
                std::cout << "CHOOSE FROM THE SELECTION MENU: " << std::endl;
                choice = validateChoice();
            /**********/
                switch (choice)
                {
                /**********/
                case 1:
                    {
                        std::cout << "Adding Flight :" << std::endl;                        
                        admin.addFlightInJson(flightObject , flightsJson);
                        /*if(k == 0) 
                        {
                            change_key(flightsJson , "" , "Flights");
                            k++;
                        }*/
                    }
                    break;
                /**********/
                case 2:
                        std::cout << "Deleting Flight :" << std::endl;
                        std::cout << "Type the UID of the flight you want to delete:" << std::endl; std::cin >> inputFlightUID;
                        admin.deleteFlightWithUID(flightsJson , inputFlightUID);
                    break;
                /**********/
                case 3:
                    std::cout << "Type the name of the destination town you are interested in:" << std::endl; std::cin >> destinationTownInput;
                    admin.searchFlights(flightsJson , destinationTownInput);
                    break;
                /**********/
                case 4:
                    std::cout << "Goodbye!" << std::endl;
                    break;
                /**********/
                default:
                    break;
                /**********/
                }

                break;
            /**********/
            case 2:
                std::cout << "Goodbye!" << std::endl;
                break;
            /**********/
            default:
                break;
            /**********/
            }
            break;
        /**********/
        default:
            break;
        /**********/
        }
    }
    while(choice != 10);

    flightsOutputFile << flightsJson.dump(4);
    bookedFlightsOutputFile << bookedFlightsJson.dump(4);
    flightsOutputFile.close();
    bookedFlightsOutputFile.close();

    return 0;
}

void addInJsonFlightObj(json jsonObj , Flights flight)
{
    jsonObj = { {"createdAtSec" , flight.getCreatedAtSec()} ,
                {"createdAtMin" , flight.getCreatedAtMin()} , 
                {"createdAtHour" , flight.getCreatedAtHour()} ,
                {"createdAtMonthDay" , flight.getCreatedAtMonthDay()} ,
                {"createdAtMonth" , flight.getCreatedAtMonth()} ,
                {"createdAtYear" , flight.getCreatedAtYear()} ,
                {"createdAtWeekDay" , flight.getCreatedAtWeekDay()} ,
                {"createdAtYearDay" , flight.getCreatedAtYear()} ,
                {"createdAtHoursDaylightSavingsTime" , flight.getCreatedAtHoursDaylightSavingsTime()} ,
                {"flightPrice" , flight.getFlightPrice()} ,
                {"sourceTown" , flight.getSourceTown()} ,
                {"destinationTown" , flight.getDestinationTown()} ,
                {"totalSeats" , flight.getTotalSeats()} ,
                {"availableSeats" , flight.getAvailableSeats()} ,
                {"takeOffYear" , flight.getTakeOffYear()} , 
                {"takeOffMonth" , flight.getTakeOffMonth()} ,
                {"takeOffDay" , flight.getTakeOffDay()} ,
                {"takeOffHour" , flight.getTakeOffHour()} ,
                {"takeOffMin" , flight.getTakeOffMin()} ,
                {"takeOffSec" , flight.getTakeOffSec()} ,
                {"landingYear" , flight.getLandingYear()} ,
                {"landingMonth" , flight.getLandingMonth()} ,
                {"landingDay" , flight.getLandingDay()} ,
                {"landingHour" , flight.getLandingHour()} ,
                {"landingMin" , flight.getLandingMin()} ,
                {"landingSec" , flight.getLandingSec()} ,
                {"flightUID" , flight.getFlightUID()}
    };
}

/*void change_key(json &object, const std::string& old_key, const std::string& new_key)
{
    json::iterator it = object.find(old_key);
    // create null value for new key and swap value from old key
    std::swap(object[new_key], it.value());
    // delete value at old key (cheap, because the value is null after swap)
    object.erase(it);
}*/

int validateChoice()
{
    int retVal;

    //Input has to be a positive integer

    while(!(std::cin >> retVal))
    {
        std::cout << "Enter numeric values :";
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if(retVal < 1 || retVal > 3)
    {
        std::cout << "Enter numeric values :";
        retVal = validateChoice();
    }

    return retVal;
}
