module top(
	input [1:0] x0,x1,x2,x3,y,
	output reg [1:0] s
);
	always @(*) begin
		case(y) 
			2'b00: s = x0;
			2'b01: s = x1;
			2'b10: s = x2;
			2'b11: s = x3;
			default: s = 2'b00;
		endcase
	end
endmodule
