# lufa-atari-9pin-dualport
Arduino Leonardo with LUFA for 2 9pin Atari Ports

Pinout
				(n/a)
Pin	Mouse/Trackball		Lightpen	Joystick	Paddle		Dir	Comment
1	V-Pulse			n/c		/Up		Button 3	IN
2	H-Pulse			n/c		/Down		n/c		IN
3	VQ-Pulse		n/c		/Left		Button 1	IN
4	HQ-Pulse		n/c		/Right		Button 2	IN
5	Button 3 (M)		Penpress	n/c		PotX		BOTH
6	Button 1 (L)		/Beamtrigger	/Button 1	n/c		BOTH
7	+5V			+5V		+5V		+5V		OUT	50mA max
8	GND			GND		GND		GND		--
9	Button 2 (R)		Button 2	Button 2	PotY		BOTH

Pot: linear 470kOhm
Dir: relative to host

Host:		Device:
1 2 3 4 5	5 4 3 2 1
 6 7 8 9         9 8 7 6


Port 1	Leonardo	Port 2	Leonardo
1	15/PB1		1	2/PD1
2	16/PB2		2	RXI/PD2
3	14/PB3		3	TX0/PD3
4	8/PB4		4	4/PD4
5*	A3/PF4		5*	A1/PF6
6*	5/PC6		6*	7/PE6
7	VCC		7	VCC
8	GND		8	GND
9*	A2/PF5		9*	A0/PF7

Free:
3/PD0
6/PD7
9/PB5	START P1
10/PB6