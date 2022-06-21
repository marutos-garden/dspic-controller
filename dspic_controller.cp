#line 1 "C:/Users/marwa/OneDrive/Desktop/marutos-garden/dspic-controller/dspic_controller.c"
#line 15 "C:/Users/marwa/OneDrive/Desktop/marutos-garden/dspic-controller/dspic_controller.c"
unsigned int pwm_period1;
unsigned int pwm_period2;
unsigned int pwm_period3;

void setup(){

 RCONbits.SWDTEN = 0;
 ANSELE = 0;
 ANSELG = 0;
 TRISF = 0;
 TRISE = 0;
 TRISG = 0;


 RPOR6bits.RP85R = 16;
 RPOR6bits.RP87R = 17;
 RPOR13bits.RP118R = 18;

 pwm_period1 = PWM_Init(1000, 1, 0, 2);
 PWM_Set_Duty(pwm_period1/4, 1);
 PWM_Start(1);

 pwm_period2 = PWM_Init(1000, 2, 0, 2);
 PWM_Set_Duty(pwm_period2/10, 2);
 PWM_Start(2);

 pwm_period3 = PWM_Init(1000, 3, 0, 2);
 PWM_Set_Duty(pwm_period3/10, 3);
 PWM_Start(3);

 delay_ms(10);
}

void main()
{
 setup();

 while (1)
 {
 PORTFbits.RF5 = 1;
 delay_ms(1000);
 PORTFbits.RF5 = 0;
 delay_ms(1000);
 }
}
