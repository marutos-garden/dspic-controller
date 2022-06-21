/*
Devices:
RGB Light = GRB 1, 2, 3
Soil Sensor = AN5 (11)
LDR Sensor = AN4 (12)
*/

/*
Dispositivos
RGB Light Handler
Soil Sensor Handler
LDR Sensor Handler
Com Handler
*/
unsigned int pwm_period1;
unsigned int pwm_period2;
unsigned int pwm_period3;

void setup(){
     //PORT Config
     RCONbits.SWDTEN = 0;
     ANSELE = 0;
     ANSELG = 0;
     TRISF = 0;
     TRISE = 0;
     TRISG = 0;
     
     //PWM Config
     RPOR6bits.RP85R = 16; //OC1 en RE5
     RPOR6bits.RP87R = 17; //OC2 en RE7
     RPOR13bits.RP118R = 18; //OC3 en RG6
     
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