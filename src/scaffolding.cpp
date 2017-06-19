// Author: Drew Schmidt

#include "rsvd.h"


Rsvd::Rsvd(int q, int seed)
{
  q_ = q;
  seed_ = seed;
}

Rsvd::Rsvd(int q)
{
  q_ = q;
  seed_ = get_random_seed();
}


int Rsvd::get_seed() const
{
  return seed_;
}

int Rsvd::get_q() const
{
  return q_;
}

void Rsvd::set_seed(const int seed)
{
  seed_ = seed;
}

void Rsvd::set_q(const int q)
{
  q_ = q;
}
