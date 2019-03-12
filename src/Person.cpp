#include "Person.h"

Person::Person() {
  this->id                         = 0;
  this->advisor_leg                = false;
  this->left_points                = 0;
  this->right_points               = 0;
  this->active                     = false;
  this->pool_connections           = 0;
  this->pool_training              = 0;
  this->pool_meeting               = 0;
  this->pool_meeting3              = 0;
  this->connection_search_activity = 0.0;
  this->connection_growth          = 0;
  this->pool_to_training_conv      = 0;
  this->training_to_meeting_conv   = 0;
  this->meeting_to_meeting3_conv   = 0;
  this->meeting3_to_school_conv    = 0;
  this->learn_activity             = 0;
  this->team_work_activity         = 0;
  this->num_invitees               = 0;
}

Person::~Person() {

}

void Person::learn() {

}

void Person::find_connections() {
  bool success = this->chance.success(connection_search_activity);
  if (success) {
    this->pool_connections += this->connection_growth;
  }
}

void Person::invite_to_training() {
  if (pool_connections > 0) {
    bool success = this->chance.success(this->pool_to_training_conv);
    if (success) {
      pool_connections--;
      pool_training++;
    } else {
      pool_connections -= this->invitee_responce();
    }
  }
}

void Person::invite_to_meeting() {
  if (pool_training > 0) {
    bool success = this->chance.success(this->training_to_meeting_conv);
    if (success) {
      pool_training--;
      pool_meeting++;
    } else {
      pool_training -= this->invitee_responce();
    }
  }
}

void Person::invite_to_meeting3() {
  if (pool_meeting > 0) {
    bool success = this->chance.success(this->meeting_to_meeting3_conv);
    if (success) {
      pool_meeting--;
      pool_meeting3++;
    } else {
      pool_meeting3 -= this->invitee_responce();
    }
  }
}

bool Person::invite_to_school() {
  bool success;
  if (pool_meeting3 > 0) {
    success = this->chance.success(this->meeting3_to_school_conv);
    if (success) {
      pool_meeting3--;
      num_invitees++;
    } else {
      pool_meeting3 -= invitee_responce();
    }
  }
  return success;
}

//sets
void Person::set(bool advisor_leg, double activity_rate) {
  this->advisor_leg                = advisor_leg;
  this->active                     = this->chance.success(activity_rate);
  if (this->active) {
    this->pool_connections           = chance.get_init_pool();
    this->connection_search_activity = 0.0;
    this->connection_growth          = 1;
    this->pool_to_training_conv      = chance.get_conv();
    this->training_to_meeting_conv   = chance.get_conv();
    this->meeting_to_meeting3_conv   = chance.get_conv();
    this->meeting3_to_school_conv    = chance.get_conv();
    this->learn_activity             = chance.get_conv();
    this->team_work_activity         = chance.get_conv();
  }
}

void Person::set_id(uint32_t id) {
  this->id = id;
}

void Person::set_advisor_leg(bool leg) {
  this->advisor_leg = leg;
}

void Person::set_activity(bool active) {
  this->active = active;
}

void Person::set_pool_connections(uint16_t num) {
  this->pool_connections = num;
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

void Person::set_left_points(uint32_t points) {
  this->left_points = points;
}

void Person::set_right_points(uint32_t points) {
  this->right_points = points;
}

// gets
bool Person::is_active() {
  return this->active;
}

bool Person::is_qualified() {
  return (this->num_invitees >= 2);
}

uint16_t Person::get_pool_connections() {
  return this->pool_connections;
}

uint16_t Person::get_pool_training() {
  return this->pool_training;
}

uint16_t Person::get_pool_meeting() {
  return this->pool_meeting;
}

uint16_t Person::get_pool_meeting3() {
  return this->pool_meeting3;
}

uint32_t Person::get_right_points() {
  return this->right_points;
}

uint32_t Person::get_left_points() {
  return this->left_points;
}

uint16_t Person::get_num_invitees() {
  return this->num_invitees;
}

bool Person::get_advisor_leg() {
  return this->advisor_leg;
}
// aux
uint16_t Person::invitee_responce() {
  // TODO: try differen algorithms
  return 1;
}

void Person::add_points(bool advisor_leg, uint32_t points) {
  if (advisor_leg) {
    this->right_points += points;
  } else {
    this->left_points += points;
  }
}

std::string Person::to_string() {
  std::stringstream out;
  out << "active: " << this->active << ", ";
  out << "advisor leg: " << this->advisor_leg << ", ";
  return out.str();
}
