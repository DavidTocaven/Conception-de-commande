/*
 
 Generation d'un echelon de tension sur l'unite Numerique-Analogique
 Acquisition Analogique-Numerique du C167
 NR - 2016
 
 Pour compiler: gcc166 -Wall -g -m7 -o test-echelon test-echelon.c -ltpc167
 */

#include <c167.h>
#include <gnutrap.h>
#include <bool.h>
#include <commc167.h>
/* variables globales */
float V_out0;
unsigned int V_can0,V_cna0;

// consigne de la commande de 3 Volts
 int consigne=1;	

// booleen pour savoir si la consigne est etat haut ou etat bas
int etat=0;

// variable contenant le temps ecoule relatif
int T=0;

// AJOUTS ETUDIANTS
/* Coefficients constants de la commande  */
/*
static float my0 =  1.421848;
static float my1 =  -2.529573;
static float my2 =  1.124884;
static float my4 = 0; // action Integrale

static float d1 =  1.000000;
static float d2 =  -1.667286;
static float d3 = 0; // action Integrale

static float mu0 =  -0.000045;
static float mu1 =  0.000000;
static float mu2 =  0.000045;
static float mu4 = 0; // action Integrale
*/
static float my0 =  1.510621;
static float my1 =  -2.140479;
static float my2 =  0.752529;

static float d1 =  -1.300908;
static float d2 =  0.434620;

static float mref0 =  0.000000;
static float mref1 =  -0.121555;
static float mref2 =  0.121555;
/* Variables d'etat */
float s0 ; // sortie k
float s1 ; // sortie k-1
float s2 ; // sortie k-2
//float s3 ; // sortie k-3			AJ integrateur

float ref0 ; // consigne k
float ref1 ; // consigne k-1
float ref2 ; // consigne k-2
//float ref3 ; // 	consigne k-3		AJ integrateur

float mes0 ; // Y mesure k
float mes1 ; // Y mesure k-1
float mes2 ; // Y mesure k-2
//float mes3 ; // Y mesure k-3			AJ integrateur


// ******************** //

/* fonction d'initialisation de la conversion analogique-numerique */
void adc_io_init() 
{
    ADCON=0x0; /* conversion unique sur le canal */
}

/* fonction d'initialisation de la conversion numerique-analogique */
void dac_io_init() 
{
  
	DP6 		= 0x001f;
	ADDRSEL2 	= 0x2008;
	BUSCON2 	= 0x8480;
	ADDRSEL3 	= 0x3008;
	BUSCON3 	= 0x8480;
}

/* fonction d'ecriture sur la voie 0 du DAC */
void dac0_output(unsigned w) 
{
	asm volatile("exts #0x0020,#1\n mov 0x0000,%0" : : "r" (w));
}

/* fonction d'ecriture sur la voie 1 du DAC */
void dac1_output(unsigned w) 
{
	asm volatile("exts #0x0030,#1\n mov 0x0000,%0" : : "r" (w));
}

/* fonction de generation d'un echelon sur la voie 0 du DAC */
/* sur interruption avec une periode T=2x3.36s */
TRAP(0x23,echelon_dac);
void echelon_dac() /* Lie a T3 */
{
	if (etat==0)
	{
		/* Consigne etat HAUT*/
		V_cna0 = 4095 ; /* valeur CNA 0 avec consigne pour etat haut */
		V_out0 = V_cna0/4095*5 -5 ; /* tension recalculee */
		etat=1;
		SET_SFRBIT(P3.3);

		//printf_entier_console("CAN = %d ", V_can0);
		//printf_entier_console("CNA = %d\n", V_cna0);
		consigne = 3;

		//init_commande();	
	}
	else
	{
		V_cna0 = 4095-2048 ; /* valeur CNA 0 a 0V pour etat bas */
		V_out0 = 0; /* tension recalculee */
		etat=0;
		CLR_SFRBIT(P3.3);
		//printf_entier_console("CAN = %d ", V_can0);
		//printf_entier_console("CNA = %d\n", V_cna0);
		consigne = 0;

		//init_commande();
	}

	/* ecriture sur le DAC  ---Commentaire etudiant */
	//dac0_output(V_cna0);
}

/* ******* Init de la commande ******/
void init_commande()
{
	// init consigne
	s0 = 0;
	s1 = 0;
	s2 = 0;
//	s3 = 0; //		AJ integrateur
	// init reference
	ref0 = 0;
	ref1 = 0;
	ref2 = 0;
//	ref3 = 0;//		AJ integrateur
	// init Y mesure
	mes0 = 0;
	mes1 = 0;
	mes2 = 0;
//	mes3 = 0;//		AJ integrateur
}

//float cTest=-5;  //  test can/cna


/* fonction de generation d'un echelon sur la voie 0 du DAC */
/* sur interruption avec une periode T=52ms */
TRAP(0x22,acquisition_adc);
void acquisition_adc() /* Lie a T2 */
{
	
	T=T+26; // periode de 52ms donc on ajoute 52ms au temps ecoule

	CLR_SFRBIT(ADCIR);          // reset du drapeau
	SET_SFRBIT(ADST);           // activation sequence conversion

	WAIT_UNTIL_BIT_SET(ADCIR);  // attente fin conversion Vg, 10us ecoulees
	V_can0 = ADDAT & 0x03FF;      // lecture conversion Vg

	// AJOUT ETUDIANTS

	// commande 
//	ref3 = ref2; //		AJ integrateur
	ref2 = ref1;
	ref1 = ref0;
	ref0 = consigne;

	
//	mes3 = mes2; //		AJ integrateur
	mes2 = mes1;
	mes1 = mes0;
	/* Adapatation mesure [0;5] vers [-5;5]*/
	mes0 = V_can0 *(10.0/1023.0) -5.0;

//	s3 = s2; //		AJ integrateur
	s2 = s1;
	s1 = s0;

	s0 =  -d1*s1 - d2*s2 /*- d3*s3*/ /* valeur des sorties precedentes */
	   + my0*mes0 + my1*mes1 + my2*mes2 /*+ my3*mes3*/ /* entree de y mesure  */
	   + mu0*ref0 + mu1*ref1 + mu2*ref2 /*+ mu3*ref3;*/ /* entree de consigne  */
	
	// test CNA/CAN
/*	cTest+=.01;
	if(cTest >5)
  	{
	  	cTest=-5;
	  	printf_entier_console("min%d\n",0);
  	}
	s0 = cTest;
*/	   

	/* Adaptation de la sortie [-5;5] vers CNA [2048;4095] */
	V_cna0 = (unsigned int)(2047.0/5.0*((s0 + 5.0)/2.0)+2048.0);
	/* envoie du temps et de la valeur du CAN sur la ligne serie */
	/* pour stockage et trace avec GnuPlot depuis le PC */
	// Debug
	printf_entier_console("T = %d ", T);
	printf_entier_console("Consigne = %d ", consigne);
	printf_entier_console("CAN = %u ", V_can0);
	printf_entier_console("CNA = %u\n", V_cna0);
	/*
	// Test CAN/CNA
	printf_entier_console("%d ", V_cna0);
	printf_entier_console("%d\n", V_can0);
	
	*/
	dac0_output(V_cna0);
}

/* initialisation Timer 3 pour generation echelon */
void timer_T3_init() 
{
	/* T3 en timer sans rechargement car periode pleine */
	T3CON=0x407; // timer - resolution 51.2 us, comptage, periode 3.36s
	T3=0; //valeur initiale du timer
	T3IC=0xC; // IT Niveau 3 groupe 0
	SET_SFRBIT(DP3.3);

}

/* initialisation Timer 3 pour generation echelon */
void timer_T2_init() 
{
	/* T2 en timer sans rechargement car periode pleine */
	T2CON=0x01;// timer - resolution 1.6 us, comptage, periode 104 ms
	T2=0; //valeur initiale du timer
	T2IC=0x8; // IT Niveau 2 groupe 0

}


void main()
{
	init_ASC0_384();

	adc_io_init();
	dac_io_init();
	init_commande();
	timer_T3_init();
	timer_T2_init();


	SET_SFRBIT(T3R); // activation timer
	SET_SFRBIT(T3IE); // autorisation IT timer

	SET_SFRBIT(T2R); // activation timer
	SET_SFRBIT(T2IE); // autorisation IT timer

	SET_SFRBIT(IEN); // autorisation IT generales

	do
	{
	}
	while(1);
}
