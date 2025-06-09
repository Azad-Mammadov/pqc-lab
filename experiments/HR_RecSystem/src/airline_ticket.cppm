
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
