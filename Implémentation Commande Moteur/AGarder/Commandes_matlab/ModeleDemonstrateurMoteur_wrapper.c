

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#define sign(a) ((a)/fabs((a)))
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void ModeleDemonstrateurMoteur_Outputs_wrapper(const real_T *Vm,
			real_T *Vs,
			real_T *Vg,
			const real_T *xC,
			const real_T  *R, const int_T  p_width0,
			const real_T  *L, const int_T  p_width1,
			const real_T  *Ke, const int_T  p_width2,
			const real_T  *Kc, const int_T  p_width3,
			const real_T  *mu, const int_T  p_width4,
			const real_T  *J, const int_T  p_width5,
			const real_T  *Cn, const int_T  p_width6,
			const real_T  *rCn, const int_T  p_width7,
			const real_T  *Delta1, const int_T  p_width8,
			const real_T  *Ks, const int_T  p_width9,
			const real_T  *Kr, const int_T  p_width10,
			const real_T  *Kg, const int_T  p_width11,
			const real_T  *Znmrt, const int_T  p_width12,
			const real_T  *Rchn, const int_T  p_width13,
			const real_T  *rRch, const int_T  p_width14,
			const real_T  *Delta2, const int_T  p_width15)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
Vs[0] = Kr[0]*Ks[0]*xC[3]-10*floor((Kr[0]*Ks[0]*xC[3]+5)/10);
Vg[0] = Kg[0]*xC[2];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  *  Derivatives function
  *
  */
void ModeleDemonstrateurMoteur_Derivatives_wrapper(const real_T *Vm,
			const real_T *Vs,
			const real_T *Vg,
			real_T *dx,
			real_T *xC,
			const real_T  *R,  const int_T  p_width0,
			const real_T  *L,  const int_T  p_width1,
			const real_T  *Ke,  const int_T  p_width2,
			const real_T  *Kc,  const int_T  p_width3,
			const real_T  *mu,  const int_T  p_width4,
			const real_T  *J,  const int_T  p_width5,
			const real_T  *Cn,  const int_T  p_width6,
			const real_T  *rCn,  const int_T  p_width7,
			const real_T  *Delta1,  const int_T  p_width8,
			const real_T  *Ks,  const int_T  p_width9,
			const real_T  *Kr,  const int_T  p_width10,
			const real_T  *Kg,  const int_T  p_width11,
			const real_T  *Znmrt,  const int_T  p_width12,
			const real_T  *Rchn,  const int_T  p_width13,
			const real_T  *rRch,  const int_T  p_width14,
			const real_T  *Delta2,  const int_T  p_width15)
{
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_BEGIN --- EDIT HERE TO _END */
dx[0] = -R[0]/L[0]*xC[0] - Ke[0]/L[0]*xC[2] + 1/L[0]*Vm[0];
dx[1] = -(R[0]+(Rchn[0]+rRch[0]*Delta2[0]))/L[0]*xC[1] - Ke[0]/L[0]*xC[2];

if(abs(xC[2])>Znmrt[0])
{
    dx[2] = Kc[0]/J[0]*xC[0] + Kc[0]/J[0]*xC[1] - mu[0]/J[0]*xC[2] - sign(xC[2])/J[0]*Cn[0]*(1+rCn[0]*Delta1[0]);
}
else
{
    if(abs(Kc[0]*xC[0] + Kc[0]*xC[1] - mu[0]*xC[2]) >= Cn[0]*(1+rCn[0]*Delta1[0]))
    {
        dx[2] = Kc[0]/J[0]*xC[0] + Kc[0]/J[0]*xC[1] - mu[0]/J[0]*xC[2] - sign(Kc[0]*xC[0] + Kc[0]*xC[1] - mu[0]*xC[2])/J[0]*Cn[0]*(1+rCn[0]*Delta1[0]);
    }
    else
    {
        xC[2]=0;
        dx[2]=0;
    }
}

dx[3] = xC[2];
/* %%%-SFUNWIZ_wrapper_Derivatives_Changes_END --- EDIT HERE TO _BEGIN */
}
