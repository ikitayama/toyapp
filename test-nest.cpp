#include "config.h"

// C++ includes
#include <cassert>
#include <iostream>

// Includes from nestkernel:
//#include "nest_types.h"
//#include "target.h"
#include "nestkernel/spike_data.h"
#include "nestkernel/event.cpp"
//#include "event.h"

namespace nest
{



}

int main() {

  nest::SpikeData* p = new nest::SpikeData[1024];
  std::cout << "tid " << p[0].get_tid() << std::endl;  
  nest::SpikeEvent se;
//#pragma omp target parallel for map(to: p[:1024])
#pragma omp parallel for
  for (int i=0;i<1024;i++) {
     //std::cout << p[i].get_lag() << std::endl;
     p[i].get_offset();
  }

}
