
#include <iostream>
#include <string>
import airline_ticket;


int main()
{
    AirLine::AirlineTicket myTicket;
    myTicket.setPassengerName("John Doe");
    myTicket.setNumberOfMiles(700);

    const double cost {myTicket.calculatePriceInDollars()};
    std::cout << "This ticket will cost $" << cost <<"\n";

    return 0;
}