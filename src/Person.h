#pragma once

class Person {
  private:
    // General info
    uint32_t id;
    bool advisror_leg; // false = left
    uint32_t left_points;
    uint32_t right_points;

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
    
    // sets
    void set_id(uint32_t id);
    void set_advisror_leg(bool leg);
    void set_activity(bool active);
    void set_current_connections(uint16_t num);
    void set_connection_search_activity(double activity);
    void set_connection_growth(uint16_t growth);
    void set_pool_to_training_conv(double conv);
    void set_training_to_meeting_conv(double conv);
    void set_meeting_to_meeting3_conv(double conv);
    void set_meeting3_to_school_conv(double conv);
    void set_learn_activity(double activity);
    void set_team_work_activity(double activity);
};
