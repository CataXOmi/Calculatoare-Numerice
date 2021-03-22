module Circuit (A, B, C, O);
	
	input A, B, C;
	output O;
	reg O;
		always@ (A or B or C)
	begin
		O = (((~A) | B) & C) ^ (((~B) ^ C) & A);
	end
	
endmodule

module Testbench;
	
	reg A_t, B_t, C_t;
	wire O_t; 

	Circuit Circuit_1(A_t, B_t, C_t, O_t);

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

