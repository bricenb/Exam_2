/* Copyright Bricen Bennett 2020 CSCE240 */

#include <inc/time_span.h>

TimeSpan::TimeSpan() {
  hours_ = 0;
  minutes_ = 0;
  seconds_ = 0;
}

TimeSpan::TimeSpan(int hours, int minutes, int seconds) {
  hours_ = hours;
  minutes_ = minutes;
  seconds_ = seconds;

  if (hours_ < 0)
    hours_ *= -1;
  if (minutes_ < 0)
    minutes_ *= -1;
  if (seconds_ < 0)
    seconds_ *= -1;
}




int TimeSpan::hours() const {
  return hours_;
}

int TimeSpan::minutes() const {
  return minutes_;
}

int TimeSpan::seconds() const {
  return seconds_;
}






const TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
  int this_hour = hours_;
  int this_minutes = minutes_;
  int this_seconds = seconds_;
  int hours = this_hour + rhs.hours_;
  int minutes = this_minutes + rhs.minutes_;
  int seconds = this_seconds + rhs.seconds_;

  if (seconds >= 60) {
    minutes++;
    seconds = seconds - 60;
    if (minutes >= 60) {
      hours++;
      minutes = minutes - 60;
    }
  }

  return TimeSpan(hours, minutes, seconds);
}





const TimeSpan operator+(int lhs, const TimeSpan& rhs) {
  int this_hours = rhs.hours_;
  int this_minutes = rhs.minutes_;
  int this_seconds = rhs.seconds_;

  this_seconds = this_seconds + lhs;

  while (this_seconds >= 60) {
  this_minutes++;
  this_seconds = this_seconds - 60;
}
  while (this_minutes >= 60) {
  this_hours++;
  this_minutes = this_minutes - 60;
}

  return TimeSpan(this_hours, this_minutes, this_seconds);
}




std::ostream& TimeSpan::Extract(std::ostream* out) const {
  int hours = hours_;
  int minutes = minutes_;
  int seconds = seconds_;

  *out << hours << " : " << minutes << " : " << seconds;
  return *out;
}

std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs) {
  return rhs.Extract(&lhs);
}

std::istream& TimeSpan::Insert(std::istream* in) {
  char col_holder;
  *in >> hours_ >> col_holder >> minutes_ >> col_holder >> seconds_;
  return *in;
}

std::istream& operator>>(std::istream& lhs, TimeSpan& rhs) {
  return rhs.Insert(&lhs);
}
