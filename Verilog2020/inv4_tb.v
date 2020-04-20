//高成鑫 2020.04.20
//反相器的仿真激励：
//testbench		tb

module inv_tb(

);
				
reg[3:0]		B1;
wire[3:0]		Y4;

inv_4		inv_4(
				.A(B1),
				.Y(Y4)
)

				
initial begin
			A1 = 0;
	#3	A1 = 4'b1001;
	#5	A1 = 0;
	#2  A1 = 1;
	#4 	$STOP;

endmodule