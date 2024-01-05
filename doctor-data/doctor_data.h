#pragma once

#include <string>

namespace star_map {

enum class System {
    BetaHydri,
    Sol,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};

} // namespace star_map

namespace heaven {

using string = std::string;

struct Vessel {
    Vessel(string name, int generation, 
           star_map::System current_system = star_map::System::Sol);
    auto replicate(string name) const -> Vessel;
    auto make_booster() -> void;
    auto shoot_booster() -> bool;
}

} // namespace heaven