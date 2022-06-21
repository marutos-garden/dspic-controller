/*
Devices:
RGB Light = GRB 1, 2, 3
Soil Sensor = AN5 (11)
LDR Sensor = AN4 (12)
SPI COMM =
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
unsigned adc_res1;
unsigned adc_res2;

void setup(){
     //PORT Config
     RCONbits.SWDTEN = 0;
     ANSELE = 0;
     ANSELG = 0;

     TRISF = 0;
     TRISE = 0;
     TRISG = 0;

     //PWM RGB LIGHT Config
     RPOR6bits.RP85R = 16;      //OC1 en RE5
     RPOR6bits.RP87R = 17;      //OC2 en RE7
     RPOR13bits.RP118R = 18;    //OC3 en RG6
     
     pwm_period1 = PWM_Init(1000, 1, 0, 2);
     PWM_Set_Duty(pwm_period1/4, 1);
     PWM_Start(1);
     
     pwm_period2 = PWM_Init(1000, 2, 0, 2);
     PWM_Set_Duty(pwm_period2/10, 2);
     PWM_Start(2);
     
     pwm_period3 = PWM_Init(1000, 3, 0, 2);
     PWM_Set_Duty(pwm_period3/10, 3);
     PWM_Start(3);
     
     //LDR SENSOR Config
     ANSELBbits.ANSB4 = 1;
     TRISBbits.TRISB4 = 1;
     
     //SOIL SENSOR Config
     ANSELBbits.ANSB5 = 1;
     TRISBbits.TRISB5 = 1;
     
     //COM SENSOR Config
     // Set SPI1 to the Master Mode, data length is 16-bit, clock = Fcy (no clock scaling), data sampled in the middle of interval, clock IDLE state high and data transmitted at low to high clock edge:
     SPI1_Init_Advanced(_SPI_SLAVE, _SPI_16_BIT, _SPI_PRESCALE_SEC_1, _SPI_PRESCALE_PRI_1, _SPI_SS_DISABLE, _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_HIGH, _SPI_ACTIVE_2_IDLE);
     
     ADC1_Init_Advanced(_ADC_10bit, _ADC_INTERNAL_REF);
     
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