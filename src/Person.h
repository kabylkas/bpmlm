#pragma once

class Person {
  private:
    // General info
    uint32_t id;
    bool advisror_leg; // false = left

    // is the person active
    bool active;

    // Person connection
    uint16_t current_connections;
    double connection_search_activity;
    uint16_t connection_growth;

    // Person conversion variables
    double pool_to_training_conv;
    double training_to_meeting_conv;
    double meeting_to_meeting3_conv;
    double meeting3_to_school_conv;

    // Personal work
    double learn_activity;
    double team_work_activity;

    // My personally invited people
    uint16_t my_invitees;

  public:
    Person();
    ~Person();

    // simple actions
    void find_connections();
    void invite_to_training();
    void invite_to_meeting();
    void invite_to_3side_meeting();
    void invite_to_school();
    void work_with_team();
    void learn();
    
};
