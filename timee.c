#include <avr/io.h>
#include <avr/interrupt.h>

unsigned long sys_time = 0;

ISR(TIMER0_COMPA_vect)
{
	sys_time++;
}

void initTime()
{
	TCCR0A = 0X02;

#if F_CPU > 20000000
#error "Frekvencija takta mora biti manja od 20MHz"
#endif

	unsigned long n = F_CPU/1000;  // perioda tajmera
	unsigned char clk_sel = 1;   // podrazumevano nema preskaliranja

	while(n > 255)
	{
		n/=8;   // ako je preskalirano 8 puta,to znaci da se F_cpu smanjuje 8 puta,a samim tim i n
		clk_sel ++;
	}


	TCCR0B = clk_sel;
	OCR0A = (unsigned char)(n & 0xff) - 1;

	TIMSK0 = 0x02;    // dozvola prekida

	unsigned long millis()
	{
		unsigned long tmp;
		cli();
		tmp = sys_time;
		sei();
		return tmp;

	}

	void delay(unsigned long d)
	{
		unsigned long t0 = millis();
		while(millis() - t0 < d);

	}


}

