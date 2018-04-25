#include <iostream>


// Half Adder
void HA (int a, int b,   // Inputs
	 int& c, int& s) // Outputs
{

  c = a & b; // The output c is computed
             // as an AND of a and b.

  s = a ^ b; // The output s is computed
             // as an XOR of a and b.

}


// Full Adder
void FA (int a, int b, int carryin, // Inputs
         int& carryout, int& s)     // Outputs
{

   // Add the code for the hierachical construction of a Full Adder
   // using two Half Adders and an OR gate.
   int c1;
   int c2;
   int s1;
   
   HA(a, b, c1, s1);
   HA(s, carryin, c2, s);

   carryout = c1 | c2;

  // Hint: You will need to use three temporal int variables.

}


// 2-Bit-Carry-Ripple-Addierer
void CRA2 (int a1, int a0, int b1, int b0, int carryin, // Inputs
	   int& carryout, int& s1, int& s0)             // Outputs
{

     // Add the code for the hierachical construction of 
     // 2-Bit-Carry-Ripple-Adder

   int carrytemp;
   
   FA(a0, b0, carryin, carrytemp, s0);
   
   FA(a1, b1, carrytemp, carryout, s1);

}


// Multiplexer
void MUX(int sel, int a, int b, // Inputs
	 int& c)                 // Outputs
{

  // Add the code for the Multiplexer

   switch   (sel) {
      case 0: c = b; break;
      case 1: c = a; break;
   }
}


// 2-Bit-Multiplexer
void MUX2(int sel, int a1, int a0, int b1, int b0, // Inputs
	  int& c1, int& c0)                        // Outputs
{

  // Add the code for the hierachical construction of
  // a 2-Bit-Multiplexer
   MUX(sel, a0, b0, c0);
   MUX(sel, a1, b1, c1);

}


// 2-Bit-Conditonal-Sum-Adder
void CSA2 (int a1, int a0, int b1, int b0, int carryin, // Inputs
           int& carryout, int& s1, int& s0)             // Outputs
{

  // Add the code for the hierachical construction of
  // a 2-Bit-Conditional-Sum-Adder
   int sel;
   int a0_int, a1_int;
   int b0_int, b1_int;
   
   FA(a0, b0, carryin, sel, s0);
   FA(a1, b1, 0, b1_int, b0_int);
   FA(a1, b1, 1, a1_int, b1_int);

   MUX2(sel, a1_int, a0_int, b1_int, b0_int, carryout, s1);

}



// Main Routine
main() 
{

  // Assignments to the inputs of the circuit
  int a1       = 0xFFFF0000;
  int a0       = 0xFF00FF00;
  int b1       = 0xF0F0F0F0;
  int b0       = 0xCCCCCCCC;
  int carryin  = 0xAAAAAAAA;

  // Outputs, initialize to 0
  int carryout = 0x00000000;
  int s1       = 0x00000000;
  int s0       = 0x00000000;

  // Switch the output to hexadecimal
  std::cout << std::hex;

  // Displey the input assignments
  std::cout << std::endl << "Eingangsbelegungen:" << std::endl;
  std::cout << "      a1: " << a1 << std::endl;
  std::cout << "      a0: " << a0 << std::endl;
  std::cout << "      b1: " << b1 << std::endl;
  std::cout << "      b0: " << b0 << std::endl;
  std::cout << " carryin: " << carryin << std::endl;

  // Call the Carry-Ripple-Adder routine
  CRA2(a1,a0,b1,b0,carryin,carryout,s1,s0);

  // Display the output of the Carry-Ripple-Adder routine
  std::cout << std::endl << "Carry-Ripple-Addierer:" << std::endl;
  std::cout << " carryout: " << carryout << std::endl;
  std::cout << "       s1: " << s1 << std::endl;
  std::cout << "       s0: " << s0 << std::endl;

  // Call the Conditional-Sum-Adder routine
  CSA2(a1,a0,b1,b0,carryin,carryout,s1,s0);

  // Display the output of the Conditional-Sum-Adder routine
  std::cout << std::endl << "Conditional-Sum-Addierer:" << std::endl;
  std::cout << " carryout: " << carryout << std::endl;
  std::cout << "       s1: " << s1 << std::endl;
  std::cout << "       s0: " << s0 << std::endl;

}
