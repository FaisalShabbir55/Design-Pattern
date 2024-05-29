#include <iostream>
#include <string>

using namespace std;
class CurrencyConverter {
public:
	virtual void convertCurrency(double amount, string sourceCurrency, string targetCurrency) = 0;
	virtual ~CurrencyConverter() {}
};


class ThirdPartyCurrencyConversionService {
public:
	void convert(double amount, string sourceCurrency, string targetCurrency) {
		double conversionRate = getConversionRate(sourceCurrency, targetCurrency);
		double convertedAmount = amount * conversionRate;
		cout << amount << " " << sourceCurrency << " is equivalent to " << convertedAmount << " " << targetCurrency << endl;
	}

private:
	double getConversionRate(string sourceCurrency, string targetCurrency) {
		if (sourceCurrency == "PKR" && targetCurrency == "EURO") {
			return 310.0;
		}
		else if (sourceCurrency == "PKR" && targetCurrency == "Dollar") {
			return 280.0;
		}
		else {
			cout << "Unsupported currency pair!" << endl;
			return 0.0;
		}
	}
};

class CurrencyConverterAdapter : public CurrencyConverter {
private:
	ThirdPartyCurrencyConversionService* adaptee;

public:
	CurrencyConverterAdapter(ThirdPartyCurrencyConversionService* service) : adaptee(service) {}

	void convertCurrency(double amount, string sourceCurrency, string targetCurrency) override {

		adaptee->convert(amount, sourceCurrency, targetCurrency);
	}
};

int main() {
	ThirdPartyCurrencyConversionService thirdPartyService;
	CurrencyConverter* converter = new CurrencyConverterAdapter(&thirdPartyService);

	double amount;
	string sourceCurrency, targetCurrency;

	cout << "Enter amount: ";
	cin >> amount;
	cout << "Enter source currency: ";
	cin >> sourceCurrency;
	cout << "Enter target currency: ";
	cin >> targetCurrency;

	converter->convertCurrency(amount, sourceCurrency, targetCurrency);

	return 0;
}
