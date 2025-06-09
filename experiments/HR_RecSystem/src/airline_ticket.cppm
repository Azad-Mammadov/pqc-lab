
export module airline_ticket;

import <iostream>;
import <string>;
import <optional>;

namespace AirLine
{
    export class AirlineTicket
    {
        public:
            double calculatePriceInDollars();
            std::string getPassengerName();
            void setPassengerName(const std::string& name);
            int getNumberOfMiles();
            void setNumberOfMiles(int miles);
            bool hasEliteSuperRewardsStatus();
            void setEliteSuperRewardsStatus(bool status);
            std::optional<std::string> getFrequentFlyerNumber() const;
            void setFrequentFlyerNumber(const std::string& number);

        private:
            std::string m_passengerName{"Unknown Passenger"};
            int m_numberOfMiles{0};
            bool m_hasEliteSuperRewardsStatus{false};
            std::optional<std::string> m_frequentFlyerNumber{"None"};
    };
} // namespace AirLine

double AirLine::AirlineTicket::calculatePriceInDollars()
{
    double price = 0.0;

    if (m_hasEliteSuperRewardsStatus)
    {
         return 0; // Free for elite members
    }

    return getNumberOfMiles() * 0.1; // $0.10 per mile
}

std::string AirLine::AirlineTicket::getPassengerName()
{
    return m_passengerName;
}

void AirLine::AirlineTicket::setPassengerName(const std::string& name)
{
    m_passengerName = name;
}

int AirLine::AirlineTicket::getNumberOfMiles()
{
    return m_numberOfMiles;
}

void AirLine::AirlineTicket::setNumberOfMiles(int miles)
{
    m_numberOfMiles = miles;
}

bool AirLine::AirlineTicket::hasEliteSuperRewardsStatus()
{
    return m_hasEliteSuperRewardsStatus;
}

void AirLine::AirlineTicket::setEliteSuperRewardsStatus(bool status)
{
    m_hasEliteSuperRewardsStatus = status;
}

std::string AirLine::AirlineTicket::getFrequentFlyerNumber() const
{
    return m_frequentFlyerNumber;
}

void AirLine::AirlineTicket::setFrequentFlyerNumber(const std::string& number)
{
    m_frequentFlyerNumber = number;
}