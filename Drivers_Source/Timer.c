/******************************************************************************
 * Module:Timer
 *
 * File Name: Timer.c
 *
 * Description: Source file for Timer
 *
 * Authors: Ola Mohamed - Abdelrhman Atef - Abdelrhman Hesham -Diaa Eldin Hassan -Ahmed Gamal - Rammzi Muhammed
 ******************************************************************************/
 
#include "..\\./headers/tm4c123gh6pm.h" 
#include "..\\./headers/Timer.h"

/*******************************************************************************
 *                       Variables                             *
 *******************************************************************************/
 
//unsigned long TimerCountt;
//unsigned long Semaphoree;
volatile unsigned int countt=0,Semaphore;

void WaitForInterrupt(void);

/*******************************************************************************
 *                          Functions                             *
 *******************************************************************************/

/*
void Timer2_delay(unsigned long period){ 
	int i;
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  delay = SYSCTL_RCGCTIMER_R;
  TimerCountt = 0;
  Semaphoree = 0;
  TIMER2_CTL_R &=~0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R  = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = 1600000-1;    // 4) reload value
	
	TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
             // 9) enable IRQ 23 in NVIC
  TIMER2_CTL_R |= 0x00000001;    // 10) enable timer2A

	 for(i = 0; i < period; i++) { while ((TIMER2_RIS_R & 0x1) == 0) ;      //wait for TimerA timeout flag 
        TIMER2_ICR_R = 0x1;      // clear the TimerA timeout flag 
  }
}

*/

// You can use this timer only if you learn how it works
void Timer2_delay_ms(unsigned long period_ms) {
    volatile unsigned long delay;

    SYSCTL_RCGCTIMER_R |= 0x04;    // 0) Activate Timer2
    delay = SYSCTL_RCGCTIMER_R;    // Allow clock to stabilize

    TIMER2_CTL_R &= ~0x01;         // 1) Disable Timer2A during setup
    TIMER2_CFG_R = 0x00;           // 2) Configure for 32-bit timer mode
    TIMER2_TAMR_R = 0x02;          // 3) Configure for periodic mode

    TIMER2_TAILR_R = (80000 * period_ms) - 1; // 4) Set reload value for the given period in ms
    TIMER2_ICR_R = 0x01;           // 5) Clear timer timeout flag
    TIMER2_IMR_R = 0x01;           // 6) Arm timeout interrupt

    NVIC_PRI5_R = (NVIC_PRI5_R & 0x00FFFFFF) | 0x80000000; // 7) Priority 4
    NVIC_EN0_R = 1 << 23;          // 8) Enable IRQ 23 in NVIC
    TIMER2_CTL_R |= 0x01;          // 9) Enable Timer2A
    Semaphore = 0;
		while(Semaphore == 0){__wfi();}
}

void Timer2A_Handler(void) {
    TIMER2_ICR_R = 0x01; // Acknowledge Timer2A timeout
		countt++;
    Semaphore = 1;       // Signal timeout
}