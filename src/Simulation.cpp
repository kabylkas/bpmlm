#include "Simulation.h"

Simulation::Simulation() {
  this->days = 0;
  this->people.clear();
}

Simulation::~Simulation() {
  for (uint32_t i = 0; i < people.size(); i++) {
    delete people[i];
  }
  this->people.clear();
}

void Simulation::setup_me() {
  Person* me = new Person();
  me->set_id(1);
  me->set_advisor_leg(false);
  me->set_activity(true);
  me->set_pool_connections(200);
  me->set_connection_search_activity(0.07);
  me->set_connection_growth(1);
  me->set_pool_to_training_conv(0.25);
  me->set_training_to_meeting_conv(1);
  me->set_meeting_to_meeting3_conv(0.25);
  me->set_meeting3_to_school_conv(0.1);
  me->set_learn_activity(0.3);
  me->set_team_work_activity(0.3);
  me->set_left_points(0);
  me->set_right_points(0);
  this->people.push_back(me);
}

void Simulation::run_detailed() {
  std::vector<Person*> people_buffer;
  for (uint32_t day = 0; day < this->days; day++) {
    people_buffer.clear();
    for (uint32_t i = 0; i < this->people.size(); i++) {
      Person* p = this->people[i];
      if (p->is_active()) {
        p->find_connections();
        p->learn();
        p->invite_to_training();
        p->invite_to_meeting();
        p->invite_to_meeting3();

        bool success = p->invite_to_school();
        if (success) {
          Person* invitee = this->add_person(p);
          people_buffer.push_back(invitee);
        }
      }
    }
  }
}

Person* add_person(Person* inviter) {
  Person* me = this->people[0];
  Person* invitee = new Person();

  // determine which leg the invitee will belong to
  if (inviter != me) {
    // invitee was not invited by me
    // so assign, the leg of the person
    // who invited him
    invitee->set(p.get_advisor_leg());
  } else {
    if (me->is_qualified()) {
      // if I am qualified,
      // just place the invitee randomly
      invitee->set(random);
    } else {
      // if I am not qulified
      if (me->get_invitees() == 0) {
        // first, place invitee to left
        invitee->set(false);
      } else {
        // then to right
        invitee->set(true);
      }
    }
  }

  return invitee;
}

void Simulation::set_days(uint32_t days) {
  this->days = days;
}
