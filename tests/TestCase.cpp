//
// Created by NILANJAN GOSWAMI on 11/11/20.
//

#include "TestCase.hpp"

namespace NsTest {
Result testStatSampleAdd() {
  //! Seed with a real random value, if available
  std::random_device r;

  //! Choose a random mean between 1 and 6
  std::default_random_engine e1(r());
  std::uniform_int_distribution<uint32_t> uniformDist(0, 1);

  NsStatistix::Stat<uint64_t> aStat("DemoSampleAdd", "TypeA", 2);

  for (uint32_t iter = 0; iter < 10000; ++iter) {
    uint32_t randomNumber = uniformDist(e1);

    if (randomNumber == 0) {
      aStat.addSample(1);
    } else if (randomNumber == 1) {
      aStat.addSample(1, "TypeB");
    } else {
      assert(false);
    }
  }

  std::cout << aStat;

  return Result(10000, aStat.sampleCount());
}

} // namespace NsTest