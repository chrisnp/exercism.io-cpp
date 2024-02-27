#pragma once

namespace chicken_coop {

[[gnu::pure]]
inline auto positions_to_quantity(int displayed) noexcept -> unsigned int {
    if (displayed <= 0) return 0;
    return displayed % 2 + positions_to_quantity(displayed / 2);
}
    
}  // namespace chicken_coop


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif