
module airline_ticket;


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

std::optional<std::string> AirLine::AirlineTicket::getFrequentFlyerNumber() const
{
    return m_frequentFlyerNumber;
}

void AirLine::AirlineTicket::setFrequentFlyerNumber(const std::string& number)
{
    m_frequentFlyerNumber = number;
}