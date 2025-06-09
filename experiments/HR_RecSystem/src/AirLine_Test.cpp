
#include <iostream>
#include <string>
import airline_ticket;


int main()
{
    AirLine::AirlineTicket myTicket;
    myTicket.setPassengerName("John Doe");
    myTicket.setNumberOfMiles(700);
    myTicket.setFrequentFlyerNumber("FF3456ZX9");

    const double cost {myTicket.calculatePriceInDollars()};
    std::cout << "This ticket will cost $" << cost <<"\n";
    std::cout << "Frequent Flyer Number: " << myTicket.getFrequentFlyerNumber() << "\n";

    return 0;
}