#include <iostream>
#include <vector>

/// @todo unsiged int vs int for values
/// @todo casts
/// @todo split into files
/// @todo bonus ??
/// @todo error handling ?

class Bank;

class Account {

    friend Bank;

    private:

	int _id;
	int _value;

	Account(int id, int value = 0): _id(id), _value(value) { }

    void _deposit(int value) { _value += value; }

    public:

	friend std::ostream& operator << (std::ostream & o, const Account & account) {
        o << "ID " << account._id << ": " << account._value << " USD" << std::endl;
		return o;
	}

};

class Bank {

    private:

	int _liquidity;
    int _tax_on_deposit;
    int _total_number_of_acounts_created;
	std::vector<Account> _clientAccounts;

    public:

	Bank(): _liquidity(0), _total_number_of_acounts_created(0), _tax_on_deposit(0.05) { }

    void addAccount(int value) {
        int to_bank = value * _tax_on_deposit;
        int to_client = value - to_bank;
        _clientAccounts.push_back(Account(_total_number_of_acounts_created, to_client));
        std::cout << "Created acount n." << _total_number_of_acounts_created << " (with value " << value << ")" << std::endl;
        _total_number_of_acounts_created++;
        _liquidity += to_bank;
    }

    void deleteAccountById(int id) {
        for (std::vector<Account>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++) {
            if (it->_id == id) {
                _clientAccounts.erase(it);
                std::cout << "Deleted acount n." << id << std::endl;
                return;
            }
        }
    }

    void deposit(int id, int value) {
        int to_bank = value * _tax_on_deposit;
        int to_client = value - to_bank;
        for (std::vector<Account>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++) {
            if (it->_id == id) {
                it->_deposit(to_client);
                _liquidity += to_bank;
                std::cout << "Deposit of " << value << " into acount n." << id << std::endl;
            }
        }
    }

	friend std::ostream& operator << (std::ostream & o, Bank & bank) {
		o << "== Bank informations ==" << std::endl;
		o << "Liquidity: " << bank._liquidity << std::endl;
        o << "Accounts: " << bank._clientAccounts.size() << std::endl;
        for (std::vector<Account>::iterator it = bank._clientAccounts.begin(); it != bank._clientAccounts.end(); it++)
            o << *it;
		o << "=======================" << std::endl;
		return o;
	}
};

int main()
{
	Bank bank = Bank();
    std::cout << bank;
    bank.addAccount(0);
    bank.addAccount(0);
    bank.deleteAccountById(1);
    bank.deleteAccountById(42);
    bank.addAccount(420000);
    std::cout << bank;
	return (0);
}
