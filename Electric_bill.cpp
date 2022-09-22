#include <iostream>
#include <string>
using namespace std;

class BILL
{
    string cust_name, cust_type; // cust = customer
    int unit_consumed;
    int fix_amt, unit_charge, exceeds_limit, surcharge_percange, finalAmount;

public:
    BILL(){     //constructor
        // setting default value so even if we forget to call input function 
        cust_name = "unknown";
        cust_type = "unknown";
        unit_consumed = 0;
        // so whenever you these as output, know that you haven't called input function
    }

    void input()
    {
        string name, type;
        int units;
        cout << "Enter customer name: " << name;
        getline(cin, name);
        cust_name = name;

        cout << "Enter customer type: " << type;
        getline(cin, type);
        cust_type = type;
        typecheck();

        cout << "Enter units consumed by user : ";
        cin >> units;
        unit_consumed = units;
    }

    void typecheck()
    {
        if (cust_type == "domestic")
        {
            fix_amt = 250;
            unit_charge = 8;
            exceeds_limit = 5000;
            surcharge_percange = 10;
        }
        else if (cust_type == "commercial")
        {
            fix_amt = 1000;
            unit_charge = 15;
            exceeds_limit = 50000;
            surcharge_percange = 20;
        }
        else
        {

            cout << "THIS TYPE OF USER IS UNKNOWN" << endl;
            exit(0);
        }
    }

    void calculateBill()
    {
        int temp_amount;
        temp_amount = fix_amt + (unit_consumed * unit_charge);
        int exceeding_amt, surcharge_amt;

        if (cust_type == "domestic" && temp_amount > exceeds_limit)
        {
            exceeding_amt = temp_amount - exceeds_limit;
            surcharge_amt = ((exceeding_amt * 10) / 100); // applying 10%
            finalAmount = temp_amount - surcharge_amt;      // taking off 10% surcharge
        }
        else if (cust_type == "commercial" && temp_amount > exceeds_limit)
        {
            exceeding_amt = temp_amount - exceeds_limit;
            surcharge_amt = ((exceeding_amt * 20) / 100);  // applying 20%
            finalAmount = temp_amount - surcharge_amt;    // taking off 20% surcharge
        }
        else
            finalAmount = temp_amount;
    }

    void output()
    {
        cout << "\n=========== WANO-KUNI ELECTRICITY CORPORATION ===================" << endl;
        cout << "\nName of customer is : " << cust_name << endl;
        cout << "\nType of customer is : " << cust_type << endl;
        cout << "\nUnits consumed by customer : " << unit_consumed << endl;
        cout << "\nTotal amount due is : " << finalAmount;
        cout << "\n============= Thank You ================" << endl;
    }
};

int main()
{

    BILL b;
    b.input();
    b.calculateBill();
    b.output();
    return 0;
}