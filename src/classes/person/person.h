#include <string>

class Person { 
    public:
			Person(std::string name, std::string ID, std::string phone);
			std::string getName();
			std::string getPhone();
			std::string getID();
			bool isActive();
    private:
			std::string m_name;
			std::string m_phone;
			std::string m_ID;
			bool m_active;

};
