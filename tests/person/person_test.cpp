#include "Person.h"
#include <iostream>
#include <stdint.h>

int main() {
  Person p;

  p.set_id(1);
  p.set_advisor_leg(false);
  p.set_activity(true);
  p.set_pool_connections(200);
  p.set_connection_search_activity(0.07);
  p.set_connection_growth(1);
  p.set_pool_to_training_conv(0.25);
  p.set_training_to_meeting_conv(1);
  p.set_meeting_to_meeting3_conv(0.25);
  p.set_meeting3_to_school_conv(0.1);
  p.set_learn_activity(0.3);
  p.set_team_work_activity(0.3);
  p.set_left_points(0);
  p.set_right_points(0);

  for (uint32_t i = 0; i < 300; i++) {
    if (p.is_active()) {
      p.find_connections();
      p.invite_to_training();
      std::cout << "Current connections: " << p.get_pool_connections() << "; ";
      std::cout << "Invited to training: " << p.get_pool_training() << std::endl;
    }
  }

  return 0;
}
