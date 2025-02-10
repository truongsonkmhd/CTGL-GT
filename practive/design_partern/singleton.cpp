#include <string>
#include <iostream>
#include <mutex>
 
using namespace std;
  
Database* Database::mInstancePtr = nullptr;
mutex Database::mLocker;

class Database
{
private:
    static Database* mInstancePtr;
    int mRecord;
    string mName;
    static mutex mLocker;
 
    Database(string name)
    {
        mName = name;
        mRecord = 0;
    }
 
public:
    void editRecord(string operation)
    {
        cout << "Performing a " << operation <<
                "operation on record " << mRecord <<
                " in database " << mName << endl;
    }
 
    string getName()
    {
        return mName;
    }
 
    static Database* getInstance(string name)
    {
        mLocker.lock();// xử lý đa luồng 
        if (nullptr == mInstancePtr) {
            mInstancePtr = new Database(name);
        }
        mLocker.unlock();// xử lý đa luồng 
        return mInstancePtr;
    }
};

int main()
{
    Database *database;
    database = Database::getInstance("products");
    cout << "This is the " << database->getName() << " database." << endl;
    database = Database::getInstance("employees");
    cout << "This is the " << database->getName() << " database." << endl;
    return 0;
}