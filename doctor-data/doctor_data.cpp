#include "doctor_data.h"

heaven::Vessel::Vessel(
    std::string name, int generation, star_map::System current_system
    ) : name(name), generation(generation), current_system(current_system)
{};

heaven::Vessel heaven::Vessel::replicate(std::string new_name) const {
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

std::string heaven::get_older_bob(heaven::Vessel const &b1, heaven::Vessel const &b2) 
{
    return (b1.generation > b2.generation ? b2 : b1).name;
}

bool heaven::in_the_same_system(heaven::Vessel const &b1, heaven::Vessel const &b2)
{
    return b1.current_system == 
}