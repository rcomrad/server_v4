#include "time_handler.hpp"

#include <boost/date_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <algorithm>

#include "domain/metaprogramming.hpp"

//--------------------------------------------------------------------------------

dom::DateTime
dom::TimeHandler::getCurentTime() noexcept
{
    auto time = boost::posix_time::second_clock::local_time().time_of_day();
    //    auto date = boost::gregorian::day_clock().universal_day();
    DateTime result;

    result.dateTime.date.day   = time.day();
    result.dateTime.date.month = time.month();
    result.dateTime.date.year  = time.year();

    result.dateTime.time.seconds = time.seconds();
    result.dateTime.time.minutes = time.minutes();
    result.dateTime.time.hours   = time.hours();

    return result;
}

//--------------------------------------------------------------------------------

bool
dom::TimeHandler::dateTimeHasPassed(const DateTime& aTimeMoment) noexcept
{
    static DateTime nullMoment;
    return durationHasPassed(aTimeMoment, nullMoment);
}

bool
dom::TimeHandler::durationHasPassed(const DateTime& aTimeFrom,
                                    const DateTime& aDuration) noexcept
{
    auto currentTime = getCurentTime();
    return (currentTime - aTimeFrom) < aDuration;
}

//--------------------------------------------------------------------------------

// boost::posix_time::ptime
// dom::DateAndTime::getRawCurentTime() noexcept
// {
//     return boost::posix_time::second_clock::local_time();
// }

// std::string
// dom::DateAndTime::getCurentTime() noexcept
// {
//     boost::posix_time::ptime timeLocal =
//         boost::posix_time::second_clock::local_time();

//     std::string dateTime;

//     if (timeLocal.time_of_day().hours() < 10) dateTime += "0";
//     dateTime += std::to_string(timeLocal.time_of_day().hours()) + ":";
//     if (timeLocal.time_of_day().minutes() < 10) dateTime += "0";
//     dateTime += std::to_string(timeLocal.time_of_day().minutes()) + ":";
//     if (timeLocal.time_of_day().seconds() < 10) dateTime += "0";
//     dateTime += std::to_string(timeLocal.time_of_day().seconds());

//     return dateTime;
// }

// std::string
// dom::DateAndTime::getCurentTimeSafe() noexcept
// {

// }

// boost::gregorian::date
// dom::DateAndTime::getDate(const std::string& aDate) noexcept
// {
//     uint16_t year  = uint16_t(std::stoi(aDate.substr(0, 4)));
//     uint16_t month = uint8_t(std::stoi(aDate.substr(5, 2)));
//     uint16_t day   = uint8_t(std::stoi(aDate.substr(8, 2)));
//     boost::gregorian::date date{year, month, day};

//     return date;
// }

// boost::posix_time::ptime
// dom::DateAndTime::getTime(const std::string& aTime) noexcept
// {
//     // 2023-04-03 12:00:00

//     uint16_t year  = uint16_t(std::stoi(aTime.substr(0, 4)));
//     uint16_t month = uint8_t(std::stoi(aTime.substr(5, 2)));
//     uint16_t day   = uint8_t(std::stoi(aTime.substr(8, 2)));
//     boost::gregorian::date date{year, month, day};

//     uint16_t hour    = uint16_t(std::stoi(aTime.substr(11, 2)));
//     uint16_t minutes = uint8_t(std::stoi(aTime.substr(14, 2)));
//     uint16_t seconds = uint8_t(std::stoi(aTime.substr(17, 2)));
//     boost::posix_time::time_duration time{hour, minutes, seconds};

//     boost::posix_time::ptime result{date, time};
//     return result;
// }

// std::string
// dom::DateAndTime::getDateStr(const boost::gregorian::date& aDate) noexcept
// {
//     uint16_t year  = aDate.year();
//     uint16_t month = aDate.month().as_number();
//     uint16_t day   = aDate.day().as_number();

//     return std::to_string(year) + "-"s + (month < 10 ? "0"s : ""s) +
//            std::to_string(month) + "-"s + (day < 10 ? "0"s : ""s) +
//            std::to_string(day);
// }

// std::string
// dom::DateAndTime::toStr(const boost::posix_time::ptime& aTime) noexcept
// {

//     if (aTime.time_of_day().hours() < 10) dateTime += "0";
//     dateTime += std::to_string(aTime.time_of_day().hours()) + ":";
//     if (aTime.time_of_day().minutes() < 10) dateTime += "0";
//     dateTime += std::to_string(aTime.time_of_day().minutes()) + ":";
//     if (aTime.time_of_day().seconds() < 10) dateTime += "0";
//     dateTime += std::to_string(aTime.time_of_day().seconds());
//     return dateTime;
// }

// bool
// dom::DateAndTime::curentTimeAssert(
//     const std::string& aTime,
//     const boost::posix_time::time_duration& aDuration) noexcept
// {
//     return curentTimeAssert(getTime(aTime), aDuration);
// }

// bool
// dom::DateAndTime::curentTimeAssert(
//     const boost::posix_time::ptime& aTime,
//     const boost::posix_time::time_duration& aDuration) noexcept
// {
//     boost::posix_time::ptime timeLocal =
//         boost::posix_time::second_clock::local_time();

//     return (aTime - timeLocal) < aDuration;
// }

// bool
// dom::DateAndTime::isPassed(const std::string& aTime) noexcept
// {
//     boost::posix_time::ptime timeLocal =
//         boost::posix_time::second_clock::local_time();

//     return getTime(aTime) < timeLocal;
// }
