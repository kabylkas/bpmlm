#include "Person.h"

Person::Person() {

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
    } else {
      pool_meeting3 -= invitee_responce();
    }
  }
  return success;
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

uint16_t Person::invitee_responce() {
  // TODO: try differen algorithms
  return 1;
}
