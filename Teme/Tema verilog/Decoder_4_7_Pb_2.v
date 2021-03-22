module Decoder47 (A, B, C, D, E);

	input A, B, C, D;
	output [6:0] E;
	reg [6:0] E;

		always@ (A or B or C or D)
	begin
		if ( A == 0 && B == 0 && C == 0 && D == 0 )
			E <= 7'b1110111;
		else if ( A == 0 && B == 0 && C == 0 && D == 1 )
			E <= 7'b0100100;
		else if ( A == 0 && B == 0 && C == 1 && D == 0 )
			E <= 7'b1011101;
		else if ( A == 0 && B == 0 && C == 1 && D == 1 )
			E <= 7'b1101101;
		else if ( A == 0 && B == 1 && C == 0 && D == 0 )
			E <= 7'b0101110;
		else if ( A == 0 && B == 1 && C == 0 && D == 1 )
			E <= 7'b1101011;
		else if ( A == 0 && B == 1 && C == 1 && D == 0 )
			E <= 7'b1111011;
		else if ( A == 0 && B == 1 && C == 1 && D == 1 )
			E <= 7'b0100101;
		else if ( A == 1 && B == 0 && C == 0 && D == 0 )
			E <= 7'b1111111;
		else if ( A == 1 && B == 0 && C == 0 && D == 1 )
			E <= 7'b1101111;
		else if ( A == 1 && B == 0 && C == 1 && D == 0 )
			E <= 7'b0111111;
		else if ( A == 1 && B == 0 && C == 1 && D == 1 )
			E <= 7'b1111010;
		else if ( A == 1 && B == 1 && C == 0 && D == 0 )
			E <= 7'b1010011;
		else if ( A == 1 && B == 1 && C == 0 && D == 1 )
			E <= 7'b1111100;
		else if ( A == 1 && B == 1 && C == 1 && D == 0 )
			E <= 7'b1011011;
		else
			E <= 7'b0011011;
	end

endmodule

module Testbench;

	reg A_t, B_t, C_t, D_t;
	wire [6:0] E_t;
	
	Decoder47 Decoder47_1(A_t, B_t, C_t, D_t, E_t);

	initial
	begin
	
		//case 0
		A_t <= 0; B_t <= 0; C_t <= 0; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);

		//case 1
		A_t <= 0; B_t <= 0; C_t <= 0; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);

		//case 2
		A_t <= 0; B_t <= 0; C_t <= 1; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);

		//case 3
		A_t <= 0; B_t <= 0; C_t <= 1; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
	
		//case 4
		A_t <= 0; B_t <= 1; C_t <= 0; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 5
		A_t <= 0; B_t <= 1; C_t <= 0; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 6
		A_t <= 0; B_t <= 1; C_t <= 1; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 7
		A_t <= 0; B_t <= 1; C_t <= 1; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 8
		A_t <= 1; B_t <= 0; C_t <= 0; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 9
		A_t <= 1; B_t <= 0; C_t <= 0; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 10 -> A
		A_t <= 1; B_t <= 0; C_t <= 1; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 11 -> b
		A_t <= 1; B_t <= 0; C_t <= 1; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 12 -> C
		A_t <= 1; B_t <= 1; C_t <= 0; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 13 -> d
		A_t <= 1; B_t <= 1; C_t <= 0; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 14 -> E
		A_t <= 1; B_t <= 1; C_t <= 1; D_t <= 0;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);
		
		//case 15 -> F
		A_t <= 1; B_t <= 1; C_t <= 1; D_t <= 1;
		#1 $display("A_t = %b  B_t = %b  C_t = %b  D_t = %b	E_t = %b\n", A_t, B_t, C_t, D_t, E_t);

	end
endmodule
