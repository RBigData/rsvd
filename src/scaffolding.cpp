// Author: Drew Schmidt

#include "rsvd.h"

int RSVD::default_q()
{
  return 3;
}



RSVD::RSVD()
{
  seed_ = initial_seed();
  q_ = default_q();
}



RSVD::RSVD(int seed)
{
  seed_ = seed;
  q_ = default_q();
}



RSVD::RSVD(int seed, int q)
{
  seed_ = seed;
  q_ = q;
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
