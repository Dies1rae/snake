/***************************************************************************
 *   Copyright (C) 2004 by Platov Anton                                    *
 *   anton@fmclub.spb.ru                                                   *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 *   Last modifed: 28.04.2004 14:33                                        *
 ***************************************************************************/

#include "random.h"
#include <time.h>


rnd_t::rnd_t(void){
 rnd_hld = time(NULL); 
}

rnd_t::~rnd_t(void)
{
}

int rnd_t::dice_roll(int num, int max)
{
 int sum = 0;
 if (max <= 0 || num <= 0)
	 return (0);
 while (num-- > 0)
	 sum = sum + do_rnd()/(32768/max)+1;
 return(sum);
}

long rnd_t::lrnd(long max)
{
 float perc;
 perc = float(max+1)/32768;
 return((long)(do_rnd()*perc));
}

int rnd_t::irnd(int max)
{
 float perc;
 perc = float(max+1)/32768;
 return((int)(do_rnd()*perc));
}

int rnd_t::do_rnd(void)
{
	return(((rnd_hld = rnd_hld * 214013L + 2531011L) >> 16) & 0x7fff);
}
