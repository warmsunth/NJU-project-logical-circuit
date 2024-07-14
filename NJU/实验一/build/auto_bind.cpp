#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->y, 2, SW1, SW0);
	nvboard_bind_pin( &top->x0, 2, SW3, SW2);
	nvboard_bind_pin( &top->x1, 2, SW5, SW4);
	nvboard_bind_pin( &top->x2, 2, SW7, SW6);
	nvboard_bind_pin( &top->x3, 2, SW9, SW8);
	nvboard_bind_pin( &top->s, 2, LD1, LD0);
}
