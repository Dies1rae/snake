/***************************************************************************
 *   Copyright (C) 2004 by Platov Anton                                    *
 *   anton@fmclub.spb.ru                                                   *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 *   Last modifed: 28.04.2004 12:04                                        *
 ***************************************************************************/
#ifndef _BUGMUD_RANDOM_H_
#define _BUGMUD_RANDOM_H_


class rnd_t{
 long rnd_hld;
int do_rnd(void);
 public:
long lrnd(long max);
int irnd(int max);
int dice_roll(int num, int max);
rnd_t();
~rnd_t();
};

#endif
