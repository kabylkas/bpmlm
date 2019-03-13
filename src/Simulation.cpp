#include "Simulation.h"

Simulation::Simulation() {
  this->days                 = 0;
  this->people_activity_rate = 0.0;
  this->people.clear();
}

Simulation::~Simulation() {
  for (uint32_t i = 0; i < people.size(); i++) {
    delete people[i];
  }
  this->people.clear();
}

void Simulation::reset() {
  for (uint32_t i = 0; i < people.size(); i++) {
    delete people[i];
  }
  this->people.clear();
}

void Simulation::set_people_activity_rate(double rate) {
  this->people_activity_rate = rate;
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
  Person* me = this->get_me();
  uint32_t limit = 1000000;
  for (uint32_t day = 0; day < this->days; day++) {
    people_buffer.clear();
    #ifdef TRACE
    std::cout << "Starting day " << day << ". People in team = " << this->people.size() << std::endl;
    #endif
    for (uint32_t i = 0; i < this->people.size(); i++) {
      Person* p = this->people[i];
      #ifdef TRACE
      std::cout << "Person " << i << " is working now." << std::endl;
      std::cout << "Person " << i << "'s stats: " << p->to_string() << std::endl;
      #endif

      bool skip = false;
      if (!p->is_active()) {
        skip = true;
      } else if (me->get_left_points() > limit && p->get_advisor_leg() == false) {
        skip = true;
      } else if (me->get_right_points() > limit && p->get_advisor_leg() == true) {
        skip = true;
      }

      if (!skip) {
        p->find_connections();
        p->learn();
        p->invite_to_training();
        p->invite_to_meeting();
        p->invite_to_meeting3();

        bool success = p->invite_to_school();
        if (success) {
          #ifdef TRACE
          std::cout << "Adding new person to the company" << std::endl;
          #endif
          Person* invitee = this->create_person(p);
          people_buffer.push_back(invitee);
        }
      }
    }

    for (uint32_t i = 0; i < people_buffer.size(); i++) {
      this->people.push_back(people_buffer[i]);
    }
  }
}

Person* Simulation::create_person(Person* inviter) {
  Person* me = this->people[0];
  Person* invitee = new Person();
  bool advisor_leg = false;
  // determine which leg the invitee will belong to
  if (inviter != me) {
    // invitee was not invited by me
    // so assign, the leg of the person
    // who invited him
    advisor_leg = inviter->get_advisor_leg();
  } else {
    if (me->is_qualified()) {
      // if I am qualified,
      // see which leg has less points
      // and put the invitee there
      if (me->get_left_points() > me->get_right_points()) {
        advisor_leg = true;
      }
    } else {
      // if I am not qulified
      if (me->get_num_invitees() == 0) {
        // first, place invitee to left
        advisor_leg = false;
      } else {
        // then to right
        advisor_leg = true;
      }
    }
  }

  invitee->set(advisor_leg, this->people_activity_rate);
  me->add_points(advisor_leg, this->products.draw_product());
  return invitee;
}

void Simulation::set_days(uint32_t days) {
  this->days = days;
}

Person* Simulation::get_me() {
  return this->people[0];
}
