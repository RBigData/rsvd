// Author: Drew Schmidt

#include "rsvd.h"


RSVD::RSVD(int q, int seed)
{
  q_ = q;
  seed_ = seed;
}



RSVD::RSVD(int q)
{
  q_ = q;
  seed_ = get_random_seed();
}



int RSVD::get_seed() const
{
  return seed_;
}



int RSVD::get_q() const
{
  return q_;
}



void RSVD::set_seed(const int seed)
{
  seed_ = seed;
}



void RSVD::set_q(const int q)
{
  q_ = q;
}
