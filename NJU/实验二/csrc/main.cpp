#include "verilated_vcd_c.h" 
#include "Vtop.h"
#include "stdio.h"
#include <stdlib.h>
#include "nvboard.h"
static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* dut);

vluint64_t main_time = 0;  
 
double sc_time_stamp()
{
    return main_time;
}
/*
void single_cycle() {
  dut.clk = 0; 
  dut.eval();
  dut.clk = 1;
  dut.eval();
}
void reset(int n) {
  dut.rst = 1;
  while (n -- > 0) single_cycle();
  dut.rst = 0;
}
*/
int main(int argc, char **argv)
{
           
    //Verilated::commandArgs(argc, argv); 
    //Verilated::traceEverOn(true); 
    //VerilatedVcdC* tfp = new VerilatedVcdC; 
    nvboard_bind_all_pins(&dut);  
    nvboard_init(); 
    
 
    Vtop *top = new Vtop("top"); 
    //eset(10);
    //top->trace(tfp, 0);   
    //tfp->open("wave.vcd"); 
    //sc_time_stamp() < 20 && !Verilated::gotFinish()
    int rst,clk;
    while (true) { 
    //int a = rand() & 1;
    //int b = rand() & 1;
    //int c = rand() & 15;
    //int AL = rand() & 1;
    //int LR = rand() & 1;
	//int se[2];
	//se[0] = rand() & 1;
	//se[1] = rand() & 1;
    //top->a= a;
    //top->b = b;
	//top->eval();
	//tfp->dump(main_time); 
        //main_time++; 
            //single_cycle();
        	dut.eval();
        	nvboard_update();    //更新NVBoard各组件状态
    }
    top->final();
    //tfp->close();
    delete top;
    nvboard_quit(); 
    return 0;
}
