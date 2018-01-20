/*
 
 Génération d'un échelon de tension sur l'unité Numérique-Analogique
 Acquisition Analogique-Numérique du C167
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
unsigned int consigne=3;

// booleen pour savoir si la consigne est etat haut ou etat bas
int etat=0;

// variable contenant le temps écoulé relatif
int T=0;

// AJOUTS ETUDIANTS
/* Coefficients constants de la commande  */
/*
static float ny1 =  1.506;
static float ny2 =  -3.0001;
static float ny3 =  1.4933;

static float nu1 =  -2.06078e-06;
static float nu2 =  -1,60155e-21;
static float nu3 =  2,0607832e-06;

static float d1  =  -1.9860;
static float d2  =  0.9860;
*/
static float ny1 =  1.474124;
static float ny2 =  -2.818532;
static float ny3 =  1.347227;

static float d1 =  1.000000;
static float d2 =  -1.864621

static float nu1 =  -0.000019;
static float nu2 =  0.000000;
static float nu3 =  0.000019;



/* Variables d'état */
float s0 ; // sortie k
float s1 ; // sortie k-1
float s2 ; // sortie k-2

float ref0 ; // consigne k
float ref1 ; // consigne k-1
float ref2 ; // consigne k-2

float mes0 ; // Y mesure k
float mes1 ; // Y mesure k-1
float mes2 ; // Y mesure k-2


// ******************** //

/* fonction d'initialisation de la conversion analogique-numerique */
void adc_io_init() {
  
  ADCON=0x0; /* conversion unique sur le canal 0 */
  
}

/* fonction d'initialisation de la conversion numerique-analogique */
void dac_io_init() {
  
  DP6 = 0x001f;
  ADDRSEL2 = 0x2008;
  BUSCON2 = 0x8480;
  ADDRSEL3 = 0x3008;
  BUSCON3 = 0x8480;
}

/* fonction d'écriture sur la voie 0 du DAC */
void dac0_output(unsigned w) {
  asm volatile("exts #0x0020,#1\n mov 0x0000,%0" : : "r" (w));
}

/* fonction d'écriture sur la voie 1 du DAC */
void dac1_output(unsigned w) {
  asm volatile("exts #0x0030,#1\n mov 0x0000,%0" : : "r" (w));
}

/* fonction de generation d'un echelon sur la voie 0 du DAC */
/* sur interruption avec une periode T=2x3.36s */
TRAP(0x23,echelon_dac);
void echelon_dac() {
  if (etat==0)
  {
    V_cna0 = 4095 ; /* valeur CNA 0 avec consigne pour état haut */
    V_out0 = V_cna0/4095*5 -5 ; /* tension recalculee */
    etat=1;
    SET_SFRBIT(P3.3);
  }
  else
  {
    V_cna0 = 4095-2048 ; /* valeur CNA 0 à 0V pour état bas */
    V_out0 = ?????; /* tension recalculee */
    etat=0;
    CLR_SFRBIT(P3.3);
  }
  
  /* ecriture sur le DAC */
  dac0_output(V_cna0);
}

/* ******* Init de la commande ******/
void init_commande()
{
// init consigne
s0 = 0;
s1 = 0;
s2 = 0;
// init reference
ref0 = 0;
ref1 = 0;
ref2 = 0;
// init Y mesure
mes0 = 0;
mes1 = 0;
mes2 = 0;

}




/* fonction de generation d'un echelon sur la voie 0 du DAC */
/* sur interruption avec une periode T=52ms */
TRAP(0x22,acquisition_adc);
void acquisition_adc() {
  T=T+52; // periode de 52ms donc on ajoute 52ms au temps écoulé
  
  CLR_SFRBIT(ADCIR);          // reset du drapeau
  SET_SFRBIT(ADST);           // activation sequence conversion
  
  WAIT_UNTIL_BIT_SET(ADCIR);  // attente fin conversion Vg, 10us ecoulees
  V_can0 = ADDAT & 0x03FF;      // lecture conversion Vg
  
  // AJOUT ETUDIANTS
  
  // commande 
  
  ref0 = ;
  mes0 = ;
  s0 = - d1*s1 - d2*s2 /* valeur des sorties précédentes */
       + my0*mes0 + my1*mes1 + my2*mes2 /* entrée de y mesure  */
       + mu0*ref0 + mu1*ref1 + mu2*ref2 ; /* entrée de comsigne  */
  
  // actualisation temporelle 
  s2 = s1;
  s1 = s0;  
  
  mes2 = mes1;
  mes1 = mes0;
  
  ref2 = ref1;
  ref1 = ref0;
  
  /* envoie du temps et de la valeur du CAN sur la ligne série */
  /* pour stockage et tracé avec GnuPlot depuis le PC */
  printf_entier_console("%d ", T);
  printf_entier_console("%d\n", V_can0);
}

/* initialisation Timer 3 pour génération échelon */
void timer_T3_init() {
  /* T3 en timer sans rechargement car periode pleine */
  T3CON=0x407; // timer - resolution 51.2 us, comptage, periode 3.36s
  T3=0; //valeur initiale du timer
  T3IC=0xC; // IT Niveau 3 groupe 0
  SET_SFRBIT(DP3.3);

}

/* initialisation Timer 3 pour génération échelon */
void timer_T2_init() {
  /* T2 en timer sans rechargement car periode pleine */
  T2CON=0x1; // timer - resolution 1.6 us, comptage, periode 104ms
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
