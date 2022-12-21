floating numbers have three component 
	
	sign : 1 or 0 based on postive or negative number 
	
	biased exponent :
 		8 bits	- 0 to 256
 		Bias - range of negative exponent
 		normally we set this to  127 
 		0-127 are 2^(negative) i.e      00000110	= 2^(-6)
 		if bias is less than 127 range of positive numbers increase 

	normalised mantissa :
		

in IEE 754 
	TYPES			SIGN		BIASED-EXPONENT	NORMALISED-MANTISA	BIAS
Single precision	1(31st bit)	8(30-23)		23(22-0)			127


Coversion: 
	convert before . value to base 2 
	convert after . value to base x*2^-1 + y*2^-2 + z*2^-3

	concat both, move . value till its right to first set digit 
	count movement, movement = exponent
	number = sign * 2^(exp) * mantissa 


Example : 
	85.125
	85 = 1010101
	0.125 = 001
	85.125 = 1010101.001
       =1.010101001 x 2^6 
	sign = 0 
	biased exponent 127+6=133
	0/10000101/01010100100000000000000

	
