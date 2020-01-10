#define RTE_B_DIO_HIGH_LINE_ENA					 RTE_uDioOutStatus.Bits.fa
#define RTE_B_PRI_VIN_LINE_LOW       RTE_Pri.u16PriStatus00.Bits.f3  /* 1 = low line */

#define RTE_Read_B_R_VIN_LINE_LOW       (RTE_B_PRI_VIN_LINE_LOW)
#define RTE_Read_B_R_VIN_LINE           (RTE_B_PRI_VIN_LINE_LOW)
#define RTE_Read_B_R_PRI_VIN_LINE       (RTE_B_PRI_VIN_LINE_LOW)

#define RTE_Write_B_P_VIN_LINE_LOW       (RTE_B_TO_SEC_STA_VIN_LINE_LOW)




CALI_RTE_W_sData.sVoutV1[u8CaliLine].s16Amp = MG_V_V1_AMP_DEFAULT;   
CALI_RTE_R_sData.sVoutV1[0]
RTE_CALI_sData
RTE_CALI_sData



SINLINE void MONCTRL_Rte_Read_R_u16VsbLinearExt(uint16 *var)
{
	Rte_Read_R_u16VsbLinearExt(&var);
}
#define Rte_Read_R_u16VsbLinearExt(var)       ((**var) = RTE_u16VoutExtVsbFast)

SINLINE uint16 MONCTRL_SCFG_u16GetVsbExtVolt10mVAvg(void)
{
	return BUFFER_u16GetMean1ms(BUFFER_CFG_E_ExtVsb);
}



PSUCTRL_SCFG_vVsbOvpDuty(u16TrimVsbOvpGainAct);
PSUCTRL_SCFG_vSetVsbOvpPwmOut(TRUE);

RTE_u16TrimVsbGainOvp.u16Val 
RTE_u16TrimVsbGainOvp.u16Val










{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_0, .Mode_Type=GPIO_Mode_AN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource0, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Inlet NTC */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_1, .Mode_Type=GPIO_Mode_AN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource1, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Outlet NTC */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_2, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource2, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* TX of UART2 */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_3, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource3, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* RX of UART2 */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_4, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource4, .u8GpioAF=GPIO_AF_4, .u8OutState=FALSE}, /* Adjust the VSB voltage */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_5, .Mode_Type=GPIO_Mode_AN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource5, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* voltage of VSB */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_6, .Mode_Type=GPIO_Mode_AN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource6, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* current of VSB */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_7, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource7, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* Reserve */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_8, .Mode_Type=GPIO_Mode_OUT, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource8, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* PSON/L signal to PSU */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_9, .Mode_Type=GPIO_Mode_OUT, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource9, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* LED Green */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_10,.Mode_Type=GPIO_Mode_OUT, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource10,.u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* LED Amber */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_11,.Mode_Type=GPIO_Mode_OUT,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource11,.u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Power OK signal to system */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_12,.Mode_Type=GPIO_Mode_OUT,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource12,.u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* SMBAlert signal */
{.u32Perip=RCC_AHBPeriph_GPIOA, .GPIOx=GPIOA, .u16Pin=GPIO_Pin_15,.Mode_Type=GPIO_Mode_OUT, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource15,.u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* EEPROM Write Protect */

/* Port B */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_0, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource0, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Fault flag of 56V */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_1, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource1, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Reserve */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_2, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_OD ,  .GPIO_PuPd=GPIO_PuPd_NOPULL, .u16PinSource=GPIO_PinSource2, .u8GpioAF=GPIO_AF_0, .u8OutState=TRUE},  /* Turn on or off VSB*/
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_3, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource3, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Vin line */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_4, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource4, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* I2c Address pin1 */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_5, .Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource5, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* I2c Address pin0 */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_6, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource6, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* TX of UART1*/
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_7, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource7, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* RX of UART1 */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_8, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_OD ,  .GPIO_PuPd=GPIO_PuPd_NOPULL, .u16PinSource=GPIO_PinSource8, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* SCL */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_9, .Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_OD ,  .GPIO_PuPd=GPIO_PuPd_NOPULL, .u16PinSource=GPIO_PinSource9, .u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* SDA */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_10,.Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_OD ,  .GPIO_PuPd=GPIO_PuPd_NOPULL, .u16PinSource=GPIO_PinSource10,.u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* SCL*/
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_11,.Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_OD ,  .GPIO_PuPd=GPIO_PuPd_NOPULL, .u16PinSource=GPIO_PinSource11,.u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* SDA */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_12,.Mode_Type=GPIO_Mode_OUT,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource12,.u8GpioAF=GPIO_AF_0, .u8OutState=TRUE},  /* Internal synchronize with second side */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_13,.Mode_Type=GPIO_Mode_IN, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource13,.u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* Output VIN OK signal to system */
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_14,.Mode_Type=GPIO_Mode_OUT,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource14,.u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* AC OK signal from PFC*/
{.u32Perip=RCC_AHBPeriph_GPIOB, .GPIOx=GPIOB, .u16Pin=GPIO_Pin_15,.Mode_Type=GPIO_Mode_AF, .GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP,     .u16PinSource=GPIO_PinSource15,.u8GpioAF=GPIO_AF_1, .u8OutState=FALSE}, /* PWM debug */
/* Port C */
{.u32Perip=RCC_AHBPeriph_GPIOC, .GPIOx=GPIOC, .u16Pin=GPIO_Pin_13,.Mode_Type=GPIO_Mode_IN,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource13, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* RESERVE */
{.u32Perip=RCC_AHBPeriph_GPIOC, .GPIOx=GPIOC, .u16Pin=GPIO_Pin_14,.Mode_Type=GPIO_Mode_IN,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource14, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* RESERVE */
{.u32Perip=RCC_AHBPeriph_GPIOC, .GPIOx=GPIOC, .u16Pin=GPIO_Pin_15,.Mode_Type=GPIO_Mode_IN,.GPIO_Speed=GPIO_Speed_50MHz, .GPIO_OType=GPIO_OType_PP ,  .GPIO_PuPd=GPIO_PuPd_UP, .u16PinSource=GPIO_PinSource15, .u8GpioAF=GPIO_AF_0, .u8OutState=FALSE}, /* RESERVE */

TEMPCTRL_SCFG_u16ReadOutletNtc();

