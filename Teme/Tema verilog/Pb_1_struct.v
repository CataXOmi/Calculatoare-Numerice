module NOT (A, O);

	input A;
	output wire O;
	assign O = !A;

endmodule

module XOR (A, B, O);
	
	input A, B;
	output reg O;
	
		always@ (A or B)
	
	begin 
		O = A^B;
	end
endmodule

module AND (A, B, O);

	input A, B;
	output reg O;
	
		always@ (A or B)
	
	begin
		O = A & B;	
	end
endmodule

module OR(A, B, O);

	input A, B;
	output reg O;
	
		always@ (A or B)

	begin
		O = A | B;
	end
endmodule

module Circuit (A, B, C, O);
	
	input A, B, C;
	output O;
	wire O;
	wire w1, w2, w3, w4, w5, w6;

	NOT not1(A,w1);
	NOT not2(B,w2);
	OR or1(w1,B,w3);
	AND and1(w3,C,w5);
	XOR xor1(w2,C,w4);	
	AND and2(w4,A,w6);
	XOR xor2(w5,w6,O);

endmodule

module Testbench;

	reg A_t, B_t, C_t;
	wire O_t;
	
	Circuit Circuit_1 (A_t, B_t, C_t, O_t);
	
	initial 
	begin
		A_t = 0; B_t = 0; C_t = 0;
		#1 A_t = 0; B_t = 0; C_t = 1;
		#1 A_t = 0; B_t = 1; C_t = 0;
		#1 A_t = 0; B_t = 1; C_t = 1;
		#1 A_t = 1; B_t = 0; C_t = 0;
		#1 A_t = 1; B_t = 0; C_t = 1;
		#1 A_t = 1; B_t = 1; C_t = 0;
		#1 A_t = 1; B_t = 1; C_t = 1;
	end

	initial begin
		$monitor("A_t = %b  B_t = %b  C_t = %b 	O_t = %b", A_t, B_t, C_t, O_t); 
	end

endmodule
