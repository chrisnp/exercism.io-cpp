#include "doctor_data.h"
using string = std::string;

heaven::Vessel::Vessel(
    string name, int generation, star_map::System current_system
    ) : name(name), generation(generation), current_system(current_system)
{}

heaven::Vessel heaven::Vessel::replicate(string new_name) const {
    Vessel replica { new_name, generation + 1, current_system };
    return replica;
}

void heaven::Vessel::make_booster() {
    ++busters;
}

bool heaven::Vessel::shoot_booster() {
    if (busters) {
        --busters;
        return true;
    }
    return false;
}

string heaven::get_older_bob(Vessel const &v1, Vessel const &v2) 
{
    return (v1.generation > v2.generation ? v2 : v1).name;
}

bool heaven::in_the_same_system(Vessel const &v1, Vessel const &v2)
{
    return v1.current_system == v2.current_system
}