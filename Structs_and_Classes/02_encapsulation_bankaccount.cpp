#include <iostream>
#include <cassert>

class BankAccount  {

public: 
    BankAccount(int accountnumber, std::string owner, float availablefunds);
    int AccountNumber() const {return accountnumber_; }
    void AccountNumber(int number);
    std::string OwnerName() const {return owner_; }
    void OwnerName(std::string owner);
    float AvailableFunds() const {return availablefunds_; }
    void AvailableFunds(float founds); 

private: 
    int accountnumber_{0};
    std::string owner_{" "};
    float availablefunds_{0.0f};
};

BankAccount::BankAccount(int accountnumber, std::string owner, float availablefunds) {
    AccountNumber(accountnumber);
    OwnerName(owner);
    AvailableFunds(availablefunds);
}

void BankAccount::AccountNumber(int number) {
    accountnumber_ = number;
}

void BankAccount::OwnerName(std::string owner) {
    owner_ = owner;
}

void BankAccount::AvailableFunds(float funds) {
    availablefunds_ = funds; 
}

int main() {
    BankAccount account(123456, "Mr. G", 9999.99);
    std::cout << "Account #  : " << account.AccountNumber() << std::endl;
    std::cout << "Owner name : " << account.OwnerName() << std::endl;
    std::cout << "Funds USD$ : " << account.AvailableFunds() << std::endl;
};