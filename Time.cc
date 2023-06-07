#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  setTime(h, m);
}

void Time::setTime(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

void Time::add(int h, int m){

	int totalMins = convertToMins() + m;
	setTime(totalMins/60, totalMins % 60);

}

bool Time::operator==(Time& t)
{
//  return ( this->convertToMins() == t.convertToMins() );
  return ( convertToMins() == t.convertToMins() );
}

bool Time::operator!=(Time& t)
{
  return ( !(*this == t) );
}

bool Time::operator<(Time& t)
{
  return ( convertToMins() < t.convertToMins() );
}

bool Time::operator<=(Time& t)
{
  return ( (*this < t) || (*this == t) );
}

bool Time::operator>(Time& t)
{
  return ( !(*this <= t) );
}

bool Time::operator>=(Time& t)
{
  return ( !(*this < t) );
}

ostream& operator<<(ostream& output, Time& t)
{
  output << setfill('0') << setw(2) << t.hours   << ":"
         << setfill('0') << setw(2) << t.minutes;

  return output;
}

int Time::convertToMins() const
{
  return (hours*60 + minutes);

}
