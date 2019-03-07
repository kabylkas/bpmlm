#include "Person.h"

Person::Person() {

}

Person::~Person() {

}

//sets
void Person::set_id(uint32_t id) {
  this->id = id;
}

void Person::set_advisror_leg(bool leg) {
  this->advisor_leg = leg;
}

void Person::set_activity(bool active) {
  this->active = active;
}

void Person::set_current_connections(uint16_t num) {
  this->current_connections = num;
}

void Person::set_connection_search_activity(double activity) {
  this->connection_search_activity = activity;
}

void Person::set_connection_growth(uint16_t growth) {
  this->connection_growth = growth;
}

void Person::set_pool_to_training_conv(double conv) {
  this->pool_to_training_conv = conv;
}

void Person::set_training_to_meeting_conv(double conv) {
  this->training_to_meeting_conv = conv;
}

void Person::set_meeting_to_meeting3_conv(double conv) {
  this->meeting_to_meeting3_conv = conv;
}

void Person::set_meeting3_to_school_conv(double conv) {
  this->meeting3_to_school_conv = conv;
}

void Person::set_learn_activity(double activity) {
  this->learn_activity = activity;
}

void Person::set_team_work_activity(double activity) {
  this->team_work_activity = activity;
}

