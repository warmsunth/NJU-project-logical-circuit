module bcd7seg(
  input  [3:0] b,
  output reg [6:0] h
);
    always @(*) begin
        case(b)
            4'b0000 : h = 7'b0000001;
            4'b0001 : h = 7'b1001111;
            4'b0010 : h = 7'b0010010;
            4'b0011 : h = 7'b0000110;
            4'b0100 : h = 7'b1001100;
            4'b0101 : h = 7'b0100100;
            4'b0110 : h = 7'b0100000;
            4'b0111 : h = 7'b0001111;
            4'b1000 : h = 7'b0000000;
            4'b1001 : h = 7'b0000100;
            default : h = 7'b0000000;
        endcase
    end
endmodule
module top(
    input [7:0]in,
    input en,
    output reg [2:0] out,
    output reg [6:0] h
);
    always @(*)begin
        if(en) begin
            casez(in)
                8'b1??????? : out = 3'b111;                                                                   
                8'b01?????? : out = 3'b110;
                8'b001????? : out = 3'b101;
                8'b0001???? : out = 3'b100;
                8'b00001??? : out = 3'b011;
		8'b000001?? : out = 3'b010;
           	8'b0000001? : out = 3'b001;                 
		8'b00000001 : out = 3'b000;                                
                default     : out = 3'b000;
        endcase
        end
    end
    bcd7seg seg0({1'b0,out},h);
endmodule
